#include "GoCS.h"
#include "core.h"
namespace GoCS {
    GameComponent::GameComponent(std::string name) {
        this->name = name;
        logger.setLoggerName(name + "_component");
        //logger.DebugLog("Adding Component %s to GameObject %s", name.c_str(), parent->name);
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
    } 
    void Sprite::Start() {
        Shader* shader = Core::App::Application::GetRenderer().CreateShader("Assets/Shaders/2D/frag.glsl","Assets/Shaders/2D/vert.glsl");
        
        parent->objectShader = std::move(shader);

    }
}