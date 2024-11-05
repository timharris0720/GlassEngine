#include "core.h"
namespace Core {
	namespace App {
		bool Application::loadPlugin(std::string pluginPath, Plugin::PluginType type) {
			bool loaded = pluginLoader.loadPlugin(pluginPath, type);
			//pluginLoader.getLoadedPlugins().back().apiInstance->onLoad();
			return loaded;
		}
		Application::Application(AppSpec appSpec, RenderBackend backend){
			if(backend == RenderBackend::OPENGL){
				loadPlugin("GlassGFX.openGL", Plugin::GFX_PLUGIN);
			}
			WindowProperties winProp;
			winProp.name = appSpec.name;
			winProp.height = appSpec.height;
			winProp.width = appSpec.width;
			pluginLoader.pRenderingBackend.apiInstance->createRenderContext(winProp);
			

			while(pluginLoader.pRenderingBackend.apiInstance->shouldWindowClose() == false){
				pluginLoader.pluginUpdate();
			}

		}
	}

}