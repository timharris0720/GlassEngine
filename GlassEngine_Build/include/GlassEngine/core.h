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
#include "pluginLoader.h"


namespace Core {
	namespace App {
		struct AppSpec {
			std::string name;
			
		};
		class Application {
		public:
			Application() = default;
			Application(AppSpec appSpec);
			GLASS_ENGINE_API bool loadPlugin(std::string pluginPath, Plugin::PluginType type);
			Plugin::PluginLoader pluginLoader;
		};
	}
}