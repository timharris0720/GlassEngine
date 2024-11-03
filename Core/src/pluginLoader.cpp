

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

#include "PluginLoader.h"
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

namespace Plugin{
    bool PluginLoader::loadPlugin(const std::string& pluginName, PluginType type) {
        
        #ifdef _WIN32
            std::string pluginPath = pluginName + ".dll";
        #else
            std::string pluginPath = pluginName + ".so";
        #endif
        
        void* libraryHandle = LOAD_LIBRARY(pluginPath);
        if (!libraryHandle) {
        #ifdef _WIN32
                std::cerr  << pluginName <<": Cannot open library: " << GetLastError() << std::endl;
        #else
                std::cerr  << pluginName <<": Cannot open library: " << dlerror() << std::endl;
        #endif
                return false;
        }
        if(type != PluginType::GFX_PLUGIN){
            using GlassPluginCreate = GlassPlugin* (*)();

            // Retrieve the 'create' function from the library
            auto createGlassPlugin = reinterpret_cast<GlassPluginCreate>(GET_SYMBOL(libraryHandle, "create"));
            if (!createGlassPlugin) {
                #ifdef _WIN32
                    std::cerr << pluginName <<": Cannot load symbol 'create': " << GetLastError() << std::endl;
                #else
                    std::cerr <<  pluginName <<": Cannot load symbol 'create': " << dlerror() << std::endl;
                #endif
                CLOSE_LIBRARY(libraryHandle);
                return false;
            }

            std::unique_ptr<GlassPlugin> apiInstance(createGlassPlugin());
            if (!apiInstance) {
                std::cerr << "Failed to create GlassPlugin instance from " << pluginName << std::endl;
                CLOSE_LIBRARY(libraryHandle);
                return false;
            }

            // Attempt to call the onLoad function on the instance
            if (!apiInstance->onLoad()) {
                std::cerr << pluginName << ": onLoad failed." << std::endl;
                CLOSE_LIBRARY(libraryHandle);
                return false;
            }

            std::cout << "Loaded Plugin:  " << pluginName << std::endl;
            
            PluginStruct plugin;
            plugin.apiInstance = std::move(apiInstance);
            plugin.libraryHandle = libraryHandle;
            loadedPlugins.push_back(std::move(plugin));
        }
        else {
            using GlassPluginCreate = GlassPlugin_GFX* (*)();

            auto createGlassPlugin = reinterpret_cast<GlassPluginCreate>(GET_SYMBOL(libraryHandle, "create"));
            if (!createGlassPlugin) {
                #ifdef _WIN32
                    std::cerr << pluginName <<": Cannot load symbol 'create': " << GetLastError() << std::endl;
                #else
                    std::cerr <<  pluginName <<": Cannot load symbol 'create': " << dlerror() << std::endl;
                #endif
                CLOSE_LIBRARY(libraryHandle);
                return false;
            }

            std::unique_ptr<GlassPlugin_GFX> apiInstance(createGlassPlugin());
            if (!apiInstance) {
                std::cerr << "Failed to create GlassPlugin_GFX instance from " << pluginName << std::endl;
                CLOSE_LIBRARY(libraryHandle);
                return false;
            }

            // Attempt to call the onLoad function on the instance
            if (!apiInstance->onLoad()) {
                std::cerr << pluginName << ": onLoad failed." << std::endl;
                CLOSE_LIBRARY(libraryHandle);
                return false;
            }

            std::cout << "Loaded Graphics Plugin:  " << pluginName << std::endl;
            
            PluginStruct_GFX plugin;
            plugin.apiInstance = std::move(apiInstance);
            plugin.libraryHandle = libraryHandle;
            pRenderingBackend = std::move(plugin);
        }
        
        return true;
    }
    void PluginLoader::cleanup() {
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
        for (const auto& plugin : loadedPlugins) {
            if (plugin.apiInstance) {
                plugin.apiInstance->Update();
            }
        }
    }
}