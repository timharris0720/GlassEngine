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
    class PluginLoader {
    public:
        bool loadPlugin(const std::string& pluginPath, PluginType type);
        void cleanup();
        std::unique_ptr<GlassPlugin> getGFX_Plugin();

    private:
        std::unique_ptr<GlassPlugin> graphicsPlugin;
        std::vector<std::unique_ptr<GlassPlugin>> glassPluginsLoaded;
        void* libraryHandle = nullptr; 
    };
}