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
#include "glm/glm.hpp"
#include "Logger.h"
#include "ErrorCodes.h"
#include "Logger.h"
#include "RendererAPI.h"
#include <string>

namespace GoCS {
    class GameComponent;
    class Transform;
    class GameObject;
}



namespace GoCS {
    class GameComponent {
        public:
        std::string name;
        Logger logger = Logger("TempName", "log.txt");
        GameObject* parent;
        GameComponent() = default;
        GLASS_ENGINE_API GameComponent(std::string name);
        virtual void Start() {};
        virtual void Update() {};
        virtual void Draw(Renderer::RendererAPI* renderer) {};
    };

    class Transform : GameComponent {
        public:
            glm::vec3 Position;
            glm::vec3 Rotation;
    };

    class GameObject {
        public: 
            Logger logger = Logger("TempName", "log.txt");
            std::string name;
            std::vector<GameObject*> children;
            std::vector<GameComponent*> components;
            GameObject* parent;
            GameObject* root;
            Transform* transform;
            bool isActive;
            bool isAlive;

            void Start() {};
            void Update() {
                if(children.size() > 0){
                    for(GameObject* child : children){
                        child->Update();
                    }
                }
                for(int i = 0; i < components.size(); i++){
                    components[i]->Update();
                }
            }
            GameObject* getRootGameObject();
            template<class T>
            T* AddGameComponent(std::string name) {
                if (std::is_base_of<GameComponent, T>()) {
                    GameComponent* tmp = new T();
                    tmp->parent = this;
                    tmp->name = name;
                    tmp->logger.setLoggerName(name + "_component");
                    tmp->Start();
                    components.push_back(tmp);
                    return static_cast<T*>(tmp);
                }
                return NULL;
            }

            GameObject() = default;
            GLASS_ENGINE_API GameObject(std::string name);
    };
}