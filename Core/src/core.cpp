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
			if(backend == RenderBackend::VULKAN){
				loadPlugin("GlassGFX.vulkan", Plugin::GFX_PLUGIN);
			}
			if(backend == RenderBackend::DX11){
				loadPlugin("GlassGFX.dx11", Plugin::GFX_PLUGIN);
			}
			pluginLoader.pRenderingBackend.apiInstance->createApplication(appSpec.name,appSpec.width,appSpec.height);
		}
	}

}