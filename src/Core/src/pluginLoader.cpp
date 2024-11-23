

#ifdef _WIN32
#include <windows.h>
#include <codecvt> // For string conversion

std::wstring stringToWString(const std::string& str) {
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &wstrTo[0], size_needed);
    return wstrTo;
}
#else
#include <dlfcn.h>
#endif

#include "pluginLoader.h"
#include "core.h"
#include <iostream>
#include <string>

#ifdef _WIN32
    #include <windows.h>
    #define LOAD_LIBRARY(path) LoadLibraryA(path.c_str())
    #define GET_SYMBOL(handle, symbol) GetProcAddress((HMODULE)(handle), symbol)
    #define CLOSE_LIBRARY(handle) FreeLibrary((HMODULE)(handle))
#else
    #include <dlfcn.h>
    #define LOAD_LIBRARY(path) dlopen(path.c_str(), RTLD_NOW)
    #define GET_SYMBOL(handle, symbol) dlsym(handle, symbol)
    #define CLOSE_LIBRARY(handle) dlclose(handle)
#endif
namespace Plugin {
    bool PluginLoader::loadPlugin(const std::string& pluginName, PluginType type) {
        
        #ifdef _WIN32
            std::string pluginPath = pluginName + ".dll";
        #else
            std::string pluginPath = pluginName + ".so";
        #endif
        
        void* libraryHandle = LOAD_LIBRARY(pluginPath);
        if (!libraryHandle) {
        #ifdef _WIN32
                logger.ErrorLog("Plugin: %s : Cant Open Error Code, %i", pluginName.c_str(), GetLastError());
                
        #else
                logger.ErrorLog("Plugin: %s : Cant Open Error Code, %i", pluginName.c_str(), dlerror());
        #endif
                return false;
        }
        if(type != PluginType::GFX_PLUGIN){
            using GlassPluginCreate = GlassPlugin* (*)();

            // Retrieve the 'create' function from the library
            auto createGlassPlugin = reinterpret_cast<GlassPluginCreate>(GET_SYMBOL(libraryHandle, "create"));
            if (!createGlassPlugin) {
                #ifdef _WIN32
                    
                    logger.ErrorLog("Plugin: %s : Cannot load symbol 'create' : Code, %i", pluginName.c_str(), GetLastError());
                    
                #else
                    logger.ErrorLog("Plugin: %s : Cannot load symbol 'create' : Code, %i", pluginName.c_str(), dlerror());

                #endif
                CLOSE_LIBRARY(libraryHandle);
                return false;
            }

            std::unique_ptr<GlassPlugin> api(createGlassPlugin());
            if (!api) {
                logger.ErrorLog("Plugin: %s : Failed to create GlassPlugin instance : Code, %i", pluginName.c_str(), PluginErrorCode::CANNOT_CREATE_INSTANCE);

                CLOSE_LIBRARY(libraryHandle);
                return false;
            }

            // Attempt to call the onLoad function on the instance
            if (!api->onLoad()) {
                logger.ErrorLog("Plugin: %s :  onLoad failed : Code, %i", pluginName.c_str(), PluginErrorCode::ONLOAD_FAILED);

                CLOSE_LIBRARY(libraryHandle);
                return false;
            }
            logger.InfoLog("Plugin: %s, Loaded", pluginName.c_str());
            
            PluginStruct plugin;
            plugin.apiInstance = std::move(api);
            plugin.libraryHandle = libraryHandle;
            loadedPlugins.push_back(std::move(plugin));
            /*
            
                PluginBackend = std::move(plugon);
                PluginBackend = std::move(plugon);
            */
        }
        else {
            using GlassPluginCreate = GlassPlugin_GFX* (*)();

            auto createGlassPlugin = reinterpret_cast<GlassPluginCreate>(GET_SYMBOL(libraryHandle, "create"));
            if (!createGlassPlugin) {
                 #ifdef _WIN32
                    
                    logger.ErrorLog("Plugin: %s : Cannot load symbol 'create' : Code, %i", pluginName.c_str(), GetLastError());
                    
                #else
                    logger.ErrorLog("Plugin: %s : Cannot load symbol 'create' : Code, %i", pluginName.c_str(), dlerror());

                #endif
                CLOSE_LIBRARY(libraryHandle);
                return false;
            }

            std::unique_ptr<GlassPlugin_GFX> api(createGlassPlugin());
            if (!api) {
                logger.ErrorLog("Plugin: %s : Failed to create GlassPlugin_GFX instance : Code, %i", pluginName.c_str(), PluginErrorCode::CANNOT_CREATE_INSTANCE);

                CLOSE_LIBRARY(libraryHandle);
                return false;
            }

            // Attempt to call the onLoad function on the instance
            if (!api->onLoad()) {
                std::cerr << pluginName << ": onLoad failed." << std::endl;
                logger.ErrorLog("Plugin: %s : onLoadFailed , GraphicsPlugin : Code, %i", pluginName.c_str(), PluginErrorCode::ONLOAD_FAILED);

                CLOSE_LIBRARY(libraryHandle);
                return false;
            }

            logger.InfoLog("Plugin: %s, Loaded", pluginName.c_str());

            
            PluginStruct_GFX plugin;
            plugin.apiInstance = std::move(api);
            plugin.libraryHandle = libraryHandle;
            Core::App::Application::GetRenderer().pRenderingBackend = std::move(plugin);
        }
        
        return true;
    }
    void PluginLoader::cleanup() {
        Core::App::Application::GetRenderer().GetBackend().apiInstance->cleanup();
        for (auto& plugin : loadedPlugins) {
            if (plugin.apiInstance) {
                plugin.apiInstance->cleanup();
            }

            // Close the library handle
            CLOSE_LIBRARY(plugin.libraryHandle);
        }
        loadedPlugins.clear();
    }
    void PluginLoader::pluginUpdate(){
        Core::App::Application::GetRenderer().GetBackend().apiInstance->Update();
        for (const auto& plugin : loadedPlugins) {
            if (plugin.apiInstance) {
                plugin.apiInstance->Update();
            }
        }
    }
}