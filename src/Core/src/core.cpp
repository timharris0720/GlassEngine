#include "core.h"
#include "pluginLoader.h"
#include "timestep.h"
#include <argparse/argparse.hpp>
#include "core_version.h"
#include "BinarySearching.h"
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
			//logger.InfoLog("Glass Engine Core Version: %s" GLASSENGINECORE_VERSION);
			Root = GoCS::GameObject();
			Root.transform = new Components::Transform();
			Root.name = "Root";
			Root.Tag = "RootTag";
			Root.root = &Root;
			MainCamera = new GoCS::GameObject("Main Camera");
			MainCamera->Tag = "Camera";
			if(backend == App::RenderBackend::OPENGL){
				bool ld = loadPlugin("GlassGFX.openGL", Plugin::GFX_PLUGIN);
				logger.DebugLog("GLASS PLUGIN LOADED %i",ld);
			}
			if(backend == App::RenderBackend::DX11){
				bool ld = loadPlugin("GlassGFX.DX11", Plugin::GFX_PLUGIN);
				logger.InfoLog("GLASS LOADED %i",ld);
			}
			if(backend == App::RenderBackend::DX12){
				bool ld = loadPlugin("GlassGFX.DX12", Plugin::GFX_PLUGIN);
				logger.InfoLog("GLASS LOADED %i",ld);
			}
			if(backend == App::RenderBackend::VULKAN){
				bool ld = loadPlugin("GlassGFX.VULKAN", Plugin::GFX_PLUGIN);
				logger.InfoLog("GLASS LOADED %i",ld);
			}
			if(backend == App::RenderBackend::CUSTOM) {
				bool ld = loadPlugin(customRendererPath, Plugin::GFX_PLUGIN);
				logger.InfoLog("GLASS LOADED %i",ld);
			}

			if(appSpec.sceneType == SceneType::DIM_2){
				logger.DebugLog("Ortho Camera");
				//MainCamera = Cameras::OrthoCamera(-10.0f, 10.0f, -10.0f, 10.0f, 0.1f, 100000.0f);
				MainCamera->AddComponent<Components::Camera>(winProp.width, winProp.height, 0.1f, 100.0f);
				//MainCamera.transform = Components::Transform();
			}
			else {
				logger.DebugLog("Perspective Camera");
				float ar = winProp.width / winProp.height;
				logger.InfoLog("Aspect ratio: %f, WIDTH %f HEIGHT %f", ar,  winProp.width ,winProp.height);
				MainCamera->AddComponent<Components::Camera>(90.0f, winProp.width , winProp.height, 0.1f, 100.0f);
				
				//MainCamera = Cameras::PerspectiveCamera(90.0f, winProp.width / winProp.height, 0.000001f, 100.0f);
				//MainCamera.transform = Components::Transform();
			}
			logger.InfoLog("Core Version: %s", CORE_VERSION_STRING);
			GetRenderer().GetBackend().apiInstance->createRenderContext(&winProp);
		}
		void Application::PushGameObject(GoCS::GameObject* GO){
			GO->root = &Root;
			GO->parent = &Root;
			int ind = Sorting::binary_search_recursive_gameobject_array(Root.children, GO->transform->Position.z);
			logger.InfoLog("Inseting Object name: %s at index %i of parent: %s", GO->name.c_str(), ind,Root.name.c_str());
			logger.InfoLog("BEFORE INSERTION GAMEOBJECT ARRAY");
        	for(int i = 0; i < Root.children.size(); i++)
            	logger.InfoLog("    Name: %s Position: %f %f %f", Root.children[i]->name.c_str(),Root.children[i]->transform->Position.x,Root.children[i]->transform->Position.y,Root.children[i]->transform->Position.z);
        
			if (ind != -1)
				Root.children.insert(Root.children.begin() + ind, GO);
			else
				Root.children.push_back(GO);
			
			logger.InfoLog("AFTER INSERTION GAMEOBJECT ARRAY");
			for(int i = 0; i < Root.children.size(); i++)
				logger.InfoLog("    Name: %s Position: %f %f %f", Root.children[i]->name.c_str(),Root.children[i]->transform->Position.x,Root.children[i]->transform->Position.y,Root.children[i]->transform->Position.z);
				
			logger.DebugLog("Added Gameobject: %s to Root as a child", GO->name.c_str());
		}
		bool Application::isRunning(){
			return GetRenderer().GetBackend().apiInstance->shouldWindowClose();
		}
		void Application::shutdown(){
			GetRenderer().GetBackend().apiInstance->Shutdown();
		}
		void Application::run(){

			
			while (GetRenderer().GetBackend().apiInstance->shouldWindowClose())
			{
				float time = GetRenderer().GetBackend().apiInstance->GetTime();
				GlassEngine::Timestep timestep = time - m_lastFrameTime;
				m_lastFrameTime = time;
				deltaTime = timestep;
				//timer.Update();
				GetRenderer().GetBackend().apiInstance->BeginScene(MainCamera);
				Root.Update();
				for(GoCS::GameObject* go : Root.children){
					go->Update();
				}
				GetRenderer().GetBackend().apiInstance->EndScene();
				pluginLoader.pluginUpdate();
			}
		}
		double Application::GetDeltaTime(){
			return deltaTime;
		}
	}
}

// TODO: finish the begin scene shit and cameras and textures