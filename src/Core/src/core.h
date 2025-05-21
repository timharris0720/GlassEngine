#pragma once

#ifdef _WIN32
#ifdef GLASS_ENGINE_EXPORTS_CORE
#define GLASS_ENGINE_API __declspec(dllexport)
#else
#define GLASS_ENGINE_API __declspec(dllimport)
#endif
#else
#define GLASS_ENGINE_API
#endif
#include <iostream>
#include "pluginLoader.h"
#include "Logger.h"
#include "ErrorCodes.h"
#include "RendererAPI.h"
#include "GoCS.h"
#include "ModelLoading/Material.h"
//#include "version.h"
//#include "SceneLoader.h"
//#include "Time.h"
typedef glm::vec3 Vector3;
typedef glm::vec2 Vector2;
typedef glm::vec4 Vector4;

typedef glm::mat4 Mat4;


/*
	TODO:
    -----
	- High Level Renderer
	- Gamobjects
	- Meshes
	- Input
	


*/

namespace Core{

	namespace Scripting {
		class Script;
	}
	namespace App
	{	
		enum RenderBackend;
		struct AppSpec;
		class Application;
	}
}


namespace Core {
	/*/
	namespace Scripting {

		class Component {
			private:
				std::shared_ptr<Scripting::Script> script;
				
			public:
				Logger logger;
				std::string name;
				Component() = default;
				GLASS_ENGINE_API Component(std::string _name);
				GLASS_ENGINE_API Scripting::Script* GetScript();
				template<typename T>
				void SetScript(){
					static_assert(std::is_base_of<Scripting::Script, T>::value, "Pushed type is not subclass of Layer!");
					script = std::make_shared<T>();	
					script->logger.setLoggerName(name + "_script");
				}
				GLASS_ENGINE_API void SetScript(const std::shared_ptr<Scripting::Script>& script);

				GLASS_ENGINE_API ErrorCode validateComponent();
		};
	}
	namespace Object {
		

		/*
		
		Remove shared ptr components and scripts
		make them new objects
		GetScript returns ptr to the script in the class
		

		class Object {
			public:

				void SetActive(bool active);
				bool isActive = true;
		};

		class GameObject : public Object {
			private:
				
				Shader* shader;
			public:
				std::vector<std::shared_ptr<Scripting::Component>> componenets;
				Logger logger;
				GameObject() = default;
				GLASS_ENGINE_API GameObject(std::string name);
				std::string name;
				Transform transform;
				Mesh mesh;
				std::vector<GameObject*> children;
				template<typename T>
				void AddComponent(){
					static_assert(std::is_base_of<Scripting::Component, T>::value, "Pushed type is not subclass of Script!");
					std::shared_ptr<Scripting::Component> comp = std::make_shared<T>();
					ErrorCode COMP_CODE = comp->validateComponent();
					
					
					switch (COMP_CODE)
					{
						case ErrorCode::COMP_VALID:
							componenets.emplace_back(&comp);
							comp->GetScript()->gameObject = this;
							comp->GetScript()->Start();
							break;
						case ErrorCode::COMP_NO_NAME:
							logger.ErrorLog("NO NAME ADDED TO COMPONENT THATS PART OF GAMEOBJECT %s", name.c_str());
							break;
						case ErrorCode::COMP_NO_SCRIPT:
							logger.ErrorLog("NO SCRIPT ADDED TO COMPONENT: %s", comp->name.c_str());
							break;
					}
				}
				GLASS_ENGINE_API void CreateShader(std::string fragmentShaderPath, std::string vertexShaderPath);
				GLASS_ENGINE_API void AddComponent(const std::shared_ptr<Scripting::Component>& component);
				std::vector<std::shared_ptr<Scripting::Component>>* GetComponenets() {
					return &componenets;
				}
		};
	}*/


	namespace App {
		
		enum RenderBackend {
			OPENGL = 0,
			VULKAN,
			DX11,
			DX12,
			CUSTOM
		};
		enum SceneType {
			DIM_2 = 0,
			DIM_3,
		};
		struct AppSpec {
			std::string name;
			int height;
			int width;
			App::SceneType sceneType;
			int argc;
			char** argv;
		};


		class Application {
		private:
			RenderBackend api;
			Logger logger = Logger("Core.Application","Log.txt");
			//std::vector<Core::Entity::GameObject*> gameObjects;
			GoCS::GameObject Root;
			GoCS::GameObject* MainCamera;
			float m_lastFrameTime;
			float deltaTime;
			static Renderer::RendererAPI* renderAPI;
			WindowProperties winProp;
			std::vector<Material> Materials;
			//Time timer;
		public:
			static Application* s_instance;
			Application() = default;
			GLASS_ENGINE_API Application(AppSpec appSpec, RenderBackend backend, std::string customRendererPath = "");
			GLASS_ENGINE_API bool loadPlugin(std::string pluginPath, Plugin::PluginType type);
			RenderBackend GetAPI() {return api;}
			GLASS_ENGINE_API double GetDeltaTime();
			GLASS_ENGINE_API void PushGameObject(GoCS::GameObject* gameObject);
			GLASS_ENGINE_API bool isRunning();
			GLASS_ENGINE_API void run();
			GLASS_ENGINE_API void shutdown();
			static Application& GetInstance() { return *s_instance; }
			static Renderer::RendererAPI& GetRenderer() { return *renderAPI; }
			GoCS::GameObject* GetRoot(){ return &Root; }
			Material* GetMaterialByID(int id){
				return &Materials[id];
			}
			Material* GetMaterialByName(std::string name){
				for(Material mat : Materials){
					if(mat.name == name){
						return &mat;
					}
				}
				return NULL;
			}
			int AddMaterial(Material mat){
				Materials.push_back(mat);
				return Materials.size();
			}
			Logger* GetLogger() { return &logger;}
			
			Plugin::PluginLoader pluginLoader;
			//SceneNS::SceneLoader sceneLoader;
		};
	}
}