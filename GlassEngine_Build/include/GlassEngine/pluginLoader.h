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
namespace Plugin {
    enum PluginType {
        GFX_PLUGIN = 0,
        OTHER,
    };
    struct PluginStruct {
        std::unique_ptr<GlassPlugin> apiInstance;
        void* libraryHandle;  // Library handle for the plugin
    };

    struct PluginStruct_GFX {
        std::unique_ptr<GlassPlugin_GFX> apiInstance;
        void* libraryHandle;  // Library handle for the plugin
    };
    class PluginLoader {
    public:
        PluginStruct_GFX pRenderingBackend;
        std::vector<PluginStruct> loadedPlugins;

        bool loadPlugin(const std::string& pluginPath, PluginType type);
        void cleanup();
        void pluginUpdate();
    private:
        
        void* libraryHandle = nullptr; 
    };
}