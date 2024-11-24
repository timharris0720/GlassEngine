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
<<<<<<< HEAD
=======
		void Application::PushGameObject(Object::GameObject GO){
			gameObjects.push_back(GO);
			logger.InfoLog("Added Gameobject: %s to stack", GO.name.c_str());
		}
>>>>>>> parent of e981af5 (smt fucky uppy)
		bool Application::isRunning(){
			return GetRenderer().GetBackend().apiInstance->shouldWindowClose();
		}
		void Application::run(){
			while (GetRenderer().GetBackend().apiInstance->shouldWindowClose())
			{
				pluginLoader.pluginUpdate();
<<<<<<< HEAD
				for(Core::Entity::GameObject go : gameObjects){
					for(auto& comp : go.GetComponenets()){
						comp.GetScript()->Update();
=======
				for(Core::Object::GameObject go : gameObjects){
					for(std::shared_ptr<Core::Scripting::Component> comp : go.GetComponenets()){
						comp->GetScript()->Update();
>>>>>>> parent of e981af5 (smt fucky uppy)
					}
				}
			}
		}
	}
	namespace Scripting {
<<<<<<< HEAD
		void Script::PushGameObject(Core::Entity::GameObject GO){
			Core::App::Application::GetInstance().PushGameObject(GO);
		}
		

		
	}
	namespace Entity{
		ErrorCode Component::validateComponent() {
			if(m_script == nullptr){
=======
		Component::Component(std::string _name) {
			name = _name;
			logger = Logger(_name, "Log.txt");
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
>>>>>>> parent of e981af5 (smt fucky uppy)
				return COMP_NO_SCRIPT;

			}
			else if (name == ""){
				return COMP_NO_NAME;
			}
			else return COMP_VALID;
		}

		GameObject::GameObject(std::string name_){
			name = name_;
			logger = Logger(name, "log.txt");
<<<<<<< HEAD
			App::Application::GetInstance().PushGameObject(*this);
=======
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
			
>>>>>>> parent of e981af5 (smt fucky uppy)
		}
		void GameObject::CreateShader(std::string fragmentShaderPath, std::string vertexShaderPath){
			App::Application::GetRenderer().CreateShader(fragmentShaderPath, vertexShaderPath);
		}
	}
}