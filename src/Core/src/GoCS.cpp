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
    GameObject::GameObject(std::string name, GameObject* pParent){
        this->name = name;
        this->parent = pParent;
        logger.setLoggerName(name);
        parent->children.push_back(this);
    }
    void GameObject::Update(){
        if(children.size() > 0){
            for(GameObject* child : children){
                child->Update();
            }
        }
        for(int i = 0; i < components.size(); i++){
            components[i]->Update();
        }
        if(vertexArray && objectShader){
            Core::App::Application::GetRenderer().DrawIndexed(vertexArray, objectShader);
        }
        
        
    
    }
}
namespace Components {
    Sprite::Sprite(std::string imagePath) : GameComponent("sprite2D") {
        path = imagePath;
    } 
    void Sprite::Start() {
        texture::Texture* texu =  Core::App::Application::GetRenderer().CreateTexture(path);
        Shader* shader = Core::App::Application::GetRenderer().CreateShader("Assets/Shaders/2D/defaultShaderFrag.glsl","Assets/Shaders/2D/defaultShaderVert.glsl");
        VertexArray* v = Defaults::SquareSprite();
        parent->objectShader = std::move(shader);
        parent->vertexArray = std::move(v);
        parent->texture = std::move(texu);
    }
}