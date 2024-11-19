#include "core.h"
#include "pluginLoader.h"
namespace Core {
	namespace App {
		bool Application::loadPlugin(std::string pluginPath, Plugin::PluginType type) {
			bool loaded = pluginLoader.loadPlugin(pluginPath, type);
			//pluginLoader.getLoadedPlugins().back().apiInstance->onLoad();
			return loaded;
		}
		Application::Application(App::AppSpec appSpec, RenderBackend backend){
			if(backend == App::RenderBackend::OPENGL){
				loadPlugin("GlassGFX.openGL", Plugin::GFX_PLUGIN);
			}
			WindowProperties winProp;
			winProp.name = appSpec.name;
			winProp.height = appSpec.height;
			winProp.width = appSpec.width;
			s_instance = this;
			renderAPI = new Renderer::RendererAPI();
			renderAPI->GetBackend()->apiInstance->createRenderContext(winProp);
		}
		void Application::PushGameObject(Object::GameObject GO){
			gameObjects.push_back(GO);
			logger.InfoLog("Added Gameobject: %s to stack", GO.name.c_str());
		}
		bool Application::isRunning(){
			return !renderAPI->GetBackend()->apiInstance->shouldWindowClose();
		}
		void Application::run(){
			while (isRunning() == true)
			{
				pluginLoader.pluginUpdate();
				for(Core::Object::GameObject go : gameObjects){
					for(std::shared_ptr<Core::Scripting::Component> comp : go.GetComponenets()){
						comp->GetScript()->Update();
					}
				}
			}
		}
	}
	namespace Scripting {
		Component::Component(std::string _name) {
			name = _name;
			logger = Logger(_name, "log.txt");
		}
		std::shared_ptr<Script> Component::GetScript(){
			return this->script;
		}

		void Component::SetScript(const std::shared_ptr<Scripting::Script>& _script){
			script = _script;
			script->logger.setLoggerName(name + "_script");
			
			script->Start();
			
		}
		ErrorCode Component::validateComponent() {
			if(script == nullptr){
				return COMP_NO_SCRIPT;

			}
			else if (name == ""){
				return COMP_NO_NAME;
			}
			else return COMP_VALID;
		}

		
	}
	namespace Object{
		GameObject::GameObject(std::string name_){
			name = name_;
			logger = Logger(name, "log.txt");
		}
		void GameObject::AddComponent(const std::shared_ptr<Scripting::Component>& component){
			ErrorCode COMP_CODE = component->validateComponent();
			switch (COMP_CODE)
			{
				case ErrorCode::COMP_VALID:
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