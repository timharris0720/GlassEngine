

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
namespace Plugin{
    bool PluginLoader::loadPlugin(const std::string& pluginPath) {
    #ifdef _WIN32
        // Load the shared library on Windows
        std::wstring widePluginPath = stringToWString(pluginPath);
        libraryHandle = LoadLibraryA(pluginPath.c_str());
        if (!libraryHandle) {
            std::cerr << "Cannot open library: " << GetLastError() << std::endl;
            return false;
        }

        // Load the create function
        typedef GlassGFXPlugin* (*CreateRenderAPI)();
        CreateRenderAPI createRenderAPI = (CreateRenderAPI)GetProcAddress((HMODULE)libraryHandle, "create");
        if (!createRenderAPI) {
            std::cerr << "Cannot load symbol 'create': " << GetLastError() << std::endl;
            FreeLibrary((HMODULE)libraryHandle);
            return false;
        }
    #else
        // Load the shared library on Linux
        libraryHandle = dlopen(pluginPath.c_str(), RTLD_NOW);
        if (!libraryHandle) {
            std::cerr << "Cannot open library: " << dlerror() << std::endl;
            return false;
        }

        // Load the create function
        typedef GlassGFXPlugin* (*CreateRenderAPI)();
        CreateRenderAPI createRenderAPI = (CreateRenderAPI)dlsym(libraryHandle, "create");
        const char* dlsym_error = dlerror();
        if (dlsym_error) {
            std::cerr << "Cannot load symbol 'create': " << dlsym_error << std::endl;
            dlclose(libraryHandle);
            return false;
        }
    #endif

        // Create the plugin instance and store it
        graphicsPlugin.reset(createRenderAPI()); // Use unique_ptr for automatic cleanup
        return true;
    }
    void PluginLoader::cleanup() {
    if (graphicsPlugin) {
        graphicsPlugin->cleanup();
    }

        // Free the library handle
    #ifdef _WIN32
        if (libraryHandle) {
            FreeLibrary((HMODULE)libraryHandle);
        }
    #else
        if (libraryHandle) {
            dlclose(libraryHandle);
        }
    #endif
    }
}