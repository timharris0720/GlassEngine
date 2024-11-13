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
	namespace App {
		enum ErrorCode {
			GLFW_CANT_INIT = 32,
			GLEW_CANT_INIT = 33,
			COMP_NO_NAME = 34,
			COMP_NO_SCRIPT = 35,
		};
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
			Logger logger = Logger("Core","Log.txt");
			
		public:
			Application() = default;
			GLASS_ENGINE_API Application(AppSpec appSpec, RenderBackend backend);
			GLASS_ENGINE_API bool loadPlugin(std::string pluginPath, Plugin::PluginType type);
			RenderBackend GetAPI() {return api;}
			GLASS_ENGINE_API bool isRunning();
			GLASS_ENGINE_API void run();
			Plugin::PluginLoader pluginLoader;
		};
	}
	namespace Scripting {
		class Script {
			public:
			virtual ~Script() = default;
			virtual void Start() {}
			virtual void Update() {}
		};

		class Component {
			private:
				std::shared_ptr<Scripting::Script> script;
			public:
				std::string name;
				Component() = default;
				GLASS_ENGINE_API Component(std::string name);
				GLASS_ENGINE_API std::shared_ptr<Scripting::Script> GetScript();
				template<typename T>
				void SetScript(){
					static_assert(std::is_base_of<Script, T>::value, "Pushed type is not subclass of Layer!");
					script = std::make_shared<T>();	
				}
				GLASS_ENGINE_API void SetScript(const std::shared_ptr<Scripting::Script>& script);


				GLASS_ENGINE_API App::ErrorCode validateComponent();
		};
	}
	namespace Object {
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

		class GameObject : public Object {
			private:
				std::vector<std::shared_ptr<Scripting::Component>> componenets;
			public:
				GameObject() = default;
				GLASS_ENGINE_API GameObject(std::string name);
				std::string name;
				Transform transform;
				Mesh mesh;
				std::vector<GameObject> children;
				template<typename T>
				void AddComponent(){
					static_assert(std::is_base_of<Component, T>::value, "Pushed type is not subclass of Script!");
					componenets.emplace_back(std::make_shared<T>())->GetScript()->Start();	
				}
				GLASS_ENGINE_API void AddComponent(const std::shared_ptr<Scripting::Component>& component);
		};
	}
}