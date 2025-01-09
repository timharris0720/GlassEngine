#pragma once
#include <iostream>
#include "glm/glm.hpp"
#include "Logger.h"
#include "ErrorCodes.h"
#include "core.h"
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
        GameObject* parent;
        GameComponent() = default;
        GLASS_ENGINE_API GameComponent(std::string name);
        virtual void Start();
        virtual void Update();
        virtual void Draw(Renderer::RendererAPI* renderer);
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

            void Start();
            void Update() {
                for(int i = 0; i < components.size(); i++){
                    components[i]->Update();
                }
            }
            GameObject* getRootGameObject();
            template<typename T>
            void AddGameComponent(std::string name) {
                
                static_assert(std::is_base_of<GameComponent, T>::value, "Pushed type is not subclass of Script!");
				std::shared_ptr<GameComponent> comp = std::make_shared<T>();
                comp->name = name;
                comp->parent = this;
                comp->Start();
                componenets.emplace_back(&comp);
            }

            GameObject() = default;
            GLASS_ENGINE_API GameObject(std::string name);
    };
}