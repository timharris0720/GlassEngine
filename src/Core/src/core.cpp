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
		bool Application::isRunning(){
			return GetRenderer().GetBackend().apiInstance->shouldWindowClose();
		}
		void Application::run(){
			while (GetRenderer().GetBackend().apiInstance->shouldWindowClose())
			{
				pluginLoader.pluginUpdate();
				for(Core::Entity::GameObject go : gameObjects){
					for(auto& comp : go.GetComponenets()){
						comp.GetScript()->Update();
					}
				}
			}
		}
	}
	namespace Scripting {
		void Script::PushGameObject(Core::Entity::GameObject GO){
			Core::App::Application::GetInstance().PushGameObject(GO);
		}
		

		
	}
	namespace Entity{
		ErrorCode Component::validateComponent() {
			if(m_script == nullptr){
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
			App::Application::GetInstance().PushGameObject(*this);
		}
		void GameObject::CreateShader(std::string fragmentShaderPath, std::string vertexShaderPath){
			App::Application::GetRenderer().CreateShader(fragmentShaderPath, vertexShaderPath);
		}
	}
}