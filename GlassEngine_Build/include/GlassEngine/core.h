#pragma once
#define CORE_VERSION_MAJOR 1
#define CORE_VERSION_MINOR 0

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
#include "glm/glm.hpp"
#include "Logger.h"
#include "ErrorCodes.h"
#include "RendererAPI.h"
#include <memory>
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



namespace Core {
<<<<<<< HEAD
	namespace Scripting {
		class Script;
	}
	namespace Entity{
		class Object;
		struct Transform;
		struct Mesh;
		class GameObject;
		
		class Component;
	}
	namespace App {
		struct AppSpec;
		class Application;
	}
}
namespace Core {
	namespace Scripting {
		class Script {
			public:
			Core::Entity::GameObject* parent;
=======
		namespace Scripting {
		class Script {
			public:
>>>>>>> parent of e981af5 (smt fucky uppy)
			Logger logger = Logger("TempName", "log.txt");
			virtual ~Script() = default;
			virtual void Start() {}
			virtual void Update() {}
<<<<<<< HEAD
			GLASS_ENGINE_API void PushGameObject(Core::Entity::GameObject GO);
		};

		

		
=======
		};

		class Component {
			private:
				std::shared_ptr<Scripting::Script> script;
				
			public:
				Logger logger;
				std::string name;
				Component() = default;
				GLASS_ENGINE_API Component(std::string _name);
				GLASS_ENGINE_API std::shared_ptr<Scripting::Script> GetScript();
				template<typename T>
				void SetScript(){
					static_assert(std::is_base_of<Script, T>::value, "Pushed type is not subclass of Layer!");
					script = std::make_shared<T>();	
					script->logger.setLoggerName(name + "_script");
					script->Start();
				}
				GLASS_ENGINE_API void SetScript(const std::shared_ptr<Scripting::Script>& script);


				GLASS_ENGINE_API ErrorCode validateComponent();
		};
>>>>>>> parent of e981af5 (smt fucky uppy)
	}
	namespace Entity {
		struct Transform {
			Vector3 position;
			Vector3 rotation;
			Vector3 scale;
			
		};

		struct Mesh {
			std::vector<Vector3> vertices;
			std::vector<Vector3> normals;
		};

		/*
		
		Remove shared ptr components and scripts
		make them new objects
		GetScript returns ptr to the script in the class
		*/

		class Component {
			private:
				std::unique_ptr<Scripting::Script> m_script;
				
			public:

				Logger logger;
				std::string name;
				Component() = default;
				GLASS_ENGINE_API Component(std::string _name, std::unique_ptr<Scripting::Script> script, GameObject* p) : m_script(std::move(script)) {
					name = _name;
					logger = Logger(_name, "Log.txt");
					script->logger.setLoggerName(name + "_script");
					script->parent = p;
				};
				void Update(){
					if(m_script)
						m_script->Update();
				}
				Scripting::Script* GetScript(){
					return m_script.get();
				};
				const Scripting::Script* GetScript() const{
					return m_script.get();
				};
				GLASS_ENGINE_API ErrorCode validateComponent();
		};

		class Object {
			public:

				void SetActive(bool active) {isActive = active;};
				bool isActive = true;
		};


		class GameObject : public Object {
			private:
<<<<<<< HEAD
				std::vector<Component> componenets;
				Shader* shader;
			public:
				
=======
				std::vector<std::shared_ptr<Scripting::Component>> componenets;
			public:
>>>>>>> parent of e981af5 (smt fucky uppy)
				Logger logger;
				
				std::string name;
				Transform transform;
				Mesh mesh;
				std::vector<GameObject> children;
<<<<<<< HEAD
			public:
				GameObject() = default;
				GameObject(std::string name) {};
				void addComponent(Component comp){
					componenets.push_back(std::move(comp));
				}
				GLASS_ENGINE_API void CreateShader(std::string fragmentShaderPath, std::string vertexShaderPath);
				const std::vector<Component>& GetComponenetsConst() const{
					return componenets;
				}
				std::vector<Component> GetComponenets() {
=======
				template<typename T>
				void AddComponent(){
					static_assert(std::is_base_of<Scripting::Component, T>::value, "Pushed type is not subclass of Script!");
					std::shared_ptr<Scripting::Component> comp = std::make_shared<T>();
					ErrorCode COMP_CODE = comp->validateComponent();
					
					
					switch (COMP_CODE)
					{
						case ErrorCode::COMP_VALID:
							componenets.emplace_back(comp);	
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
				std::vector<std::shared_ptr<Scripting::Component>> GetComponenets() {
>>>>>>> parent of e981af5 (smt fucky uppy)
					return componenets;
				}
		};
		
	}

	namespace App {
		
		enum RenderBackend {
			OPENGL = 0,
			VULKAN,
			DX11,
			DX12
		};
		struct AppSpec {
			std::string name;
			int height;
			int width;
		};


		class Application {
		private:
			RenderBackend api;
			Logger logger = Logger("Application","Log.txt");
<<<<<<< HEAD
			std::vector<Core::Entity::GameObject> gameObjects;
=======
			std::vector<Core::Object::GameObject> gameObjects;
>>>>>>> parent of e981af5 (smt fucky uppy)
			static Application* s_instance;
			static Renderer::RendererAPI* renderAPI;
		public:
			
			Application() = default;
			GLASS_ENGINE_API Application(AppSpec appSpec, RenderBackend backend);
			GLASS_ENGINE_API bool loadPlugin(std::string pluginPath, Plugin::PluginType type);
			RenderBackend GetAPI() {return api;}
<<<<<<< HEAD
			void PushGameObject(Core::Entity::GameObject GO) {gameObjects.push_back(std::move(GO));}
=======
			GLASS_ENGINE_API void PushGameObject(Object::GameObject GO);
>>>>>>> parent of e981af5 (smt fucky uppy)
			GLASS_ENGINE_API bool isRunning();
			GLASS_ENGINE_API void run();
			static Application& GetInstance() { return *s_instance; }
			static Renderer::RendererAPI& GetRenderer() { return *renderAPI; }
			Logger getLogger() { return logger;}
			
			Plugin::PluginLoader pluginLoader;
		};
	}
}