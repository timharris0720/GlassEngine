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
			

			

		}

		bool Application::isRunning(){
			return !pluginLoader.pRenderingBackend.apiInstance->shouldWindowClose();
		}
	}
	namespace Scripting {
		Component::Component(std::string m_name) {
			name = m_name;
		}
		std::shared_ptr<Script> Component::GetScript(){
			return this->script;
		}

		void Component::SetScript(const std::shared_ptr<Scripting::Script>& _script){
			script = _script;
		}


		
	}
	namespace Object{
		GameObject::GameObject(std::string name_){
			name = name_;
		}
		void GameObject::AddComponent(const std::shared_ptr<Scripting::Component>& component){
			this->componenets.emplace_back(component); component->GetScript()->Start();
		}
	}
}	