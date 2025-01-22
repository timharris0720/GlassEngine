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
#include "Logger.h"
#include "ErrorCodes.h"
#include "defaults.h"
#include <string>
#include "texture.h"
#include "Shader.h"
#include "VertexArray.h"

namespace GoCS {
    class GameComponent;
    class GameObject;
}
namespace Components {
    class Transform;
    class Sprite;
}



namespace GoCS {
    class GameComponent {
        public:
        std::string name;
        Logger logger = Logger("TempName", "Log.txt");
        GoCS::GameObject* parent;
        GameComponent() = default;
        GLASS_ENGINE_API GameComponent(std::string name);
        virtual void Init() {};
        virtual void Start() {};
        virtual void Update() {};
        //virtual void Draw(Renderer::RendererAPI* renderer) {};
    };

    

    class GameObject {
        public: 
            Logger logger = Logger("TempName", "Log.txt");
            std::string name;
            std::vector<GameObject*> children;
            std::vector<GameComponent*> components;
            GameObject* parent;
            GameObject* root;
            Components::Transform* transform;
            Shader* objectShader = nullptr;
            VertexArray* vertexArray = nullptr;
            texture::Texture* objectTexture = nullptr;
            
            bool isActive;
            bool isAlive;

            void Start() {};
            GLASS_ENGINE_API void Update();
                
            GameObject* getRootGameObject() {
                return root;
            }
            template<class T, typename... Args>
            T* AddGameComponent(Args&&... args) {
                if (std::is_base_of<GameComponent, T>()) {
                    GameComponent* tmp = new T(std::forward<Args>(args)...);
                    tmp->parent = this;
                    //tmp->root = root;
                    //tmp->Init();
                    tmp->Start();
                    components.push_back(tmp);
                    logger.InfoLog("Added Component: %s_component to %s GameComponents", tmp->name.c_str(), this->name.c_str());
                    return static_cast<T*>(tmp);
                }
                return NULL;
            }
            GameObject* CreateChild(std::string name){
                GameObject* GO = new GameObject(name,  this);
                logger.InfoLog("Created Child Called %s, parent is %s", name.c_str(), this->name.c_str());
                return GO;
            }
            GameObject() = default;
            GLASS_ENGINE_API GameObject(std::string name);
            GLASS_ENGINE_API GameObject(std::string name, GameObject* pParent);
    };
}

namespace Components {
    class Transform : public GoCS::GameComponent {
        public:
            glm::vec3 Position;
            glm::vec3 Rotation;
            glm::vec3 Scale;
    };
    class Sprite : public GoCS::GameComponent{
        private:
        std::string path;
        texture::ImageWrapping wrapType;
        public:
            GLASS_ENGINE_API Sprite() = default;
            GLASS_ENGINE_API Sprite(std::string imagePath,texture::ImageWrapping wrapType);
            GLASS_ENGINE_API void Start() override;
    };

    
}

