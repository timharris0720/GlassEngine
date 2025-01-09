#include "GoCS.h"

namespace GoCS {
    GameComponent::GameComponent(std::string name) {
        this->name = name;
    }
    GameObject::GameObject(std::string name){
        this->name = name;
        Core::App::Application::GetInstance().PushGameObject(this);
    }
}