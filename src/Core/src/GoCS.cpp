#include "GoCS.h"
#include "core.h"
namespace GoCS {
    GameComponent::GameComponent(std::string name) {
        this->name = name;
        logger.setLoggerName(name + "_component");
    }
    GameObject::GameObject(std::string name){
        this->name = name;
        logger.setLoggerName(name);
        Core::App::Application::GetInstance().PushGameObject(this);
    }
    GameObject::GameObject(std::string name, GameObject* parent){
        this->name = name;
        logger.setLoggerName(name);
        parent->children.push_back(this);
    }

}