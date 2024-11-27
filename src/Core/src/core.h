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
	namespace Entity {
		struct Mesh;
		struct Transform;
		class Object;
		class GameObject;
		class Component;
	}

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
	namespace Scripting
    {
        class Script {
            public:
            
                Core::Entity::GameObject* gameObject;
                Logger logger = Logger("TempName", "log.txt");
                virtual ~Script() = default;
                virtual void Start() {}
                virtual void Update() {}
                GLASS_ENGINE_API void PushGameObject(Core::Entity::GameObject* GO);
            };
    } // namespace Scripting

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


        class Object {
			public:

				void SetActive(bool active);
				bool isActive = true;
		};

        class Component {
			private:
				std::shared_ptr<Core::Scripting::Script> script;
				
			public:
				GameObject* parent;
				Logger logger;
				std::string name;
				Component() = default;
				GLASS_ENGINE_API Component(std::string _name);
				GLASS_ENGINE_API Core::Scripting::Script* GetScript();
				template<typename T>
				void SetScript(){
					static_assert(std::is_base_of<Scripting::Script, T>::value, "Pushed type is not subclass of Layer!");
					script = std::make_shared<T>();	
					script->logger.setLoggerName(name + "_script");
				}
				GLASS_ENGINE_API void SetScript(const std::shared_ptr<Core::Scripting::Script>& script);

				GLASS_ENGINE_API ErrorCode validateComponent();
		};


        class GameObject : public Object {
			private:
				
				Shader* shader;
			public:
				std::vector<std::shared_ptr<Component>> componenets;
				Logger logger;
				GameObject() = default;
				GLASS_ENGINE_API GameObject(std::string name);
				std::string name;
				Transform transform;
				Mesh mesh;
				std::vector<GameObject*> children;
				template <typename T, typename... Args>
				void addComponent(Args&&... args) {
					//componenets.emplace_back(std::make_shared<T>(std::forward<Args>(args)...));
					
				}
				
				GLASS_ENGINE_API void CreateShader(std::string fragmentShaderPath, std::string vertexShaderPath);
				GLASS_ENGINE_API void AddComponent(const std::shared_ptr<Component>& component);
				std::vector<std::shared_ptr<Component>>* GetComponenets() {
					return &componenets;
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
			std::vector<Core::Entity::GameObject*> gameObjects;
			static Application* s_instance;
			static Renderer::RendererAPI* renderAPI;
		public:
			
			Application() = default;
			GLASS_ENGINE_API Application(AppSpec appSpec, RenderBackend backend);
			GLASS_ENGINE_API bool loadPlugin(std::string pluginPath, Plugin::PluginType type);
			RenderBackend GetAPI() {return api;}
			GLASS_ENGINE_API void PushGameObject(Core::Entity::GameObject* GO);
			GLASS_ENGINE_API bool isRunning();
			GLASS_ENGINE_API void run();
			static Application& GetInstance() { return *s_instance; }
			static Renderer::RendererAPI& GetRenderer() { return *renderAPI; }
			Logger getLogger() { return logger;}
			
			Plugin::PluginLoader pluginLoader;
		};
	}
}