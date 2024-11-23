#pragma once

#ifdef _WIN32
#ifdef GLASS_ENGINE_EXPORTS_CORE
#define GLASS_ENGINE_API __declspec(dllexport)
#else
#define GLASS_ENGINE_API __declspec(dllimport)
#endif
#else
#define GLASS_ENGINE_API
#endif

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "plugin.h"
#include "Logger.h"
namespace Plugin{
    enum PluginType {
        GFX_PLUGIN = 0,
        OTHER,
    };
    enum PluginErrorCode {
        CANNOT_CREATE_INSTANCE = 10,
        ONLOAD_FAILED = 11,
    };

    struct PluginStruct {
        std::shared_ptr<GlassPlugin> apiInstance = nullptr;
        void* libraryHandle;  // Library handle for the plugin
    };

    struct PluginStruct_GFX {
        std::shared_ptr<GlassPlugin_GFX> apiInstance;
        void* libraryHandle;  // Library handle for the plugin
    };
    class PluginLoader {
    public:

        
        std::vector<PluginStruct> loadedPlugins;

        bool loadPlugin(const std::string& pluginPath, PluginType type);
        void cleanup();
        GLASS_ENGINE_API void pluginUpdate();
    private:
        Logger logger = Logger("Core.PluginLoader", "Log.txt");
        void* libraryHandle = nullptr; 
    };
}