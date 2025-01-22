#include "core.h"
#include "pluginLoader.h"
#include "camera.h"
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
			if(appSpec.sceneType == SceneType::DIM_2){
				MainCamera = Cameras::OrthoCamera(-10.0f, 10.0f, -10.0f, 10.0f, 0.1f, 100.0f);
			}
			else {
				MainCamera = Cameras::PerspectiveCamera(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);
			}
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
				GetRenderer().GetBackend().apiInstance->BeginScene(&MainCamera);
				for(GoCS::GameObject* go : Root.children){
					go->Update();
				}
				pluginLoader.pluginUpdate();
			}
		}
	}
}

// TODO: finish the begin scene shit and cameras and textures