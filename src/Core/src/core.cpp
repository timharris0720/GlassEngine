#include "core.h"
#include "pluginLoader.h"

#include <argparse/argparse.hpp>

namespace Core {
	namespace App {
		Application* Application::s_instance = nullptr;
		Renderer::RendererAPI* Application::renderAPI = nullptr;
		bool Application::loadPlugin(std::string pluginPath, Plugin::PluginType type) {
			bool loaded = pluginLoader.loadPlugin(pluginPath, type);
			//pluginLoader.getLoadedPlugins().back().apiInstance->onLoad();
			return loaded;
		}
		
		Application::Application(App::AppSpec appSpec, RenderBackend backend, std::string customRendererPath){
			argparse::ArgumentParser program("test");

			program.add_argument("--debug")
			.help("Enable debug logging")
			.default_value(false)
			.implicit_value(true);
			
			s_instance = this;
			renderAPI = new Renderer::RendererAPI();
			WindowProperties winProp;
			winProp.name = appSpec.name;
			winProp.height = appSpec.height;
			winProp.width = appSpec.width;

			try {
				program.parse_args(appSpec.argc, appSpec.argv);
			}
			catch (const std::exception& err) {
				logger.ErrorLog("Error When Parsing Args: %s", err.what());
				std::cerr << program;
			}
			if (program["--debug"] == true) {
				logger.setDBGMode(true);
			}

			Root = GoCS::GameObject();
			Root.transform = new Components::Transform();
			MainCamera = new GoCS::GameObject("Main Camera");
			if(backend == App::RenderBackend::OPENGL){
				bool ld = loadPlugin("GlassGFX.openGL", Plugin::GFX_PLUGIN);
				logger.DebugLog("GLASS LOADED %i",ld);
			}
			if(backend == App::RenderBackend::DX11){
				bool ld = loadPlugin("GlassGFX.DX11", Plugin::GFX_PLUGIN);
				logger.InfoLog("GLASS LOADED %i",ld);
			}
			if(backend == App::RenderBackend::DX12){
				bool ld = loadPlugin("GlassGFX.DX12", Plugin::GFX_PLUGIN);
				logger.InfoLog("GLASS LOADED %i",ld);
			}
			if(backend == App::RenderBackend::CUSTOM) {
				bool ld = loadPlugin(customRendererPath, Plugin::GFX_PLUGIN);
				logger.InfoLog("GLASS LOADED %i",ld);
			}
			if(appSpec.sceneType == SceneType::DIM_2){
				logger.DebugLog("Ortho Camera");
				//MainCamera = Cameras::OrthoCamera(-10.0f, 10.0f, -10.0f, 10.0f, 0.1f, 100000.0f);
				MainCamera->AddComponent<Components::Camera>(-10.0f, 10.0f, -10.0f, 10.0f, 0.1f, 100000.0f);

				//MainCamera.transform = Components::Transform();
			}
			else {
				logger.DebugLog("Perspective Camera");
				MainCamera->AddComponent<Components::Camera>(90.0f, winProp.width / winProp.height, 0.000001f, 100.0f);
				//MainCamera = Cameras::PerspectiveCamera(90.0f, winProp.width / winProp.height, 0.000001f, 100.0f);
				//MainCamera.transform = Components::Transform();
			}
			GetRenderer().GetBackend().apiInstance->createRenderContext(&winProp);
		}
		double Application::GetTime() {
			//return timer.GetDeltaTime();
			return 1.0;
		}
		void Application::PushGameObject(GoCS::GameObject* GO){
			GO->root = &Root;
			GO->parent = &Root;
			Root.children.push_back(GO);
			logger.DebugLog("Added Gameobject: %s to Root as a child", GO->name.c_str());
		}
		bool Application::isRunning(){
			return GetRenderer().GetBackend().apiInstance->shouldWindowClose();
		}
		void Application::run(){
			while (GetRenderer().GetBackend().apiInstance->shouldWindowClose())
			{
				//timer.Update();
				GetRenderer().GetBackend().apiInstance->BeginScene(MainCamera);
				for(GoCS::GameObject* go : Root.children){
					go->Update();
				}
				GetRenderer().GetBackend().apiInstance->EndScene();
				pluginLoader.pluginUpdate();
			}
		}
	}
}

// TODO: finish the begin scene shit and cameras and textures