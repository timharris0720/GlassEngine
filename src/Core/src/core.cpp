#include "core.h"
#include "pluginLoader.h"
namespace Core {
	namespace App {
		Application* Application::s_instance = nullptr;
		Renderer::RendererAPI* Application::renderAPI = nullptr;
		bool Application::loadPlugin(std::string pluginPath, Plugin::PluginType type) {
			bool loaded = pluginLoader.loadPlugin(pluginPath, type);
			//pluginLoader.getLoadedPlugins().back().apiInstance->onLoad();
			return loaded;
		}
		Application::Application(App::AppSpec appSpec, RenderBackend backend){
			s_instance = this;
			renderAPI = new Renderer::RendererAPI();
			WindowProperties winProp;
			winProp.name = appSpec.name;
			winProp.height = appSpec.height;
			winProp.width = appSpec.width;
			if(backend == App::RenderBackend::OPENGL){
				bool ld = loadPlugin("GlassGFX.openGL", Plugin::GFX_PLUGIN);
				logger.InfoLog("GLASS LOADED %i",ld);
			}
			Root = GoCS::GameObject();
			GetRenderer().GetBackend().apiInstance->createRenderContext(&winProp);
		}
		void Application::PushGameObject(GoCS::GameObject* GO){
			GO->root = &Root;
			
			Root.children.push_back(GO);
			logger.InfoLog("Added Gameobject: %s to stack", GO->name.c_str());
		}
		bool Application::isRunning(){
			return GetRenderer().GetBackend().apiInstance->shouldWindowClose();
		}
		void Application::run(){
			while (GetRenderer().GetBackend().apiInstance->shouldWindowClose())
			{
				
				for(GoCS::GameObject* go : Root.children){
					for(const auto& comp : go->components){
						comp->Update();
					}
				}
				pluginLoader.pluginUpdate();
			}
		}
	}
}