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
			
			GetRenderer().GetBackend().apiInstance->createRenderContext(&winProp);
		}
		void Application::PushGameObject(Core::Entity::GameObject* GO){
			gameObjects.push_back(GO);
			logger.InfoLog("Added Gameobject: %s to stack", GO->name.c_str());
		}
		bool Application::isRunning(){
			return GetRenderer().GetBackend().apiInstance->shouldWindowClose();
		}
		void Application::run(){
			while (GetRenderer().GetBackend().apiInstance->shouldWindowClose())
			{
				pluginLoader.pluginUpdate();
				for(Core::Entity::GameObject* go : gameObjects){
					for(const auto& comp : go->componenets){
						comp->GetScript();
					}
				}
			}
		}
	}
	namespace Scripting {
		void Script::PushGameObject(Core::Entity::GameObject* GO){
			Core::App::Application::GetInstance().PushGameObject(GO);
		}
		
		
	}
	namespace Entity{
		GameObject::GameObject(std::string name_){
			name = name_;
			logger = Logger(name, "log.txt");
			App::Application::GetInstance().PushGameObject(this);
		}
		void GameObject::AddComponent(const std::shared_ptr<Component>& component){
			ErrorCode COMP_CODE = component->validateComponent();
			switch (COMP_CODE)
			{
				case ErrorCode::COMP_VALID:
					component->GetScript()->gameObject = this;
					component->GetScript()->Start();
					this->componenets.emplace_back(component);
					break;
				case ErrorCode::COMP_NO_NAME:
					logger.ErrorLog("NO NAME ADDED TO COMPONENT THATS PART OF GAMEOBJECT %s", name.c_str());
					break;
				case ErrorCode::COMP_NO_SCRIPT:
					logger.ErrorLog("NO SCRIPT ADDED TO COMPONENT: %s", component->name.c_str());
					break;
			}
			
		}
		void GameObject::CreateShader(std::string fragmentShaderPath, std::string vertexShaderPath){
			App::Application::GetRenderer().CreateShader(fragmentShaderPath, vertexShaderPath);
		}



	}
}