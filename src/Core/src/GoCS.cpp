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
namespace Components {
    Sprite::Sprite(std::string imagePath) : GameComponent("sprite2D") {
        sprite = ImageUtils::Image(imagePath);
        parent->objectShader = &Core::App::Application::GetInstance().GetRenderer().CreateShader("Assets/Shaders/2D/frag.glsl","Assets/Shaders/2D/vert.glsl");
        
    } 
}