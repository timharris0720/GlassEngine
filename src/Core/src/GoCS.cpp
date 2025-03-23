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
        transform = new Components::Transform();
        logger.setLoggerName(name);
        Core::App::Application::GetInstance().PushGameObject(this);
    }
    double GameObject::getDeltaTime(){
        return 1.0;
    }

    GameObject::GameObject(std::string name, GameObject* pParent){
        this->name = name;
        this->parent = pParent;
        this->root =  Core::App::Application::GetInstance().GetRoot();
        transform = new Components::Transform();
        logger.setLoggerName(name);
        parent->children.push_back(this);
		logger.DebugLog("Added Gameobject: %s to %s as a child", name.c_str(), pParent->name.c_str());

    }
    void GameObject::Update(){
        for(GameObject* child : children){
            child->Update();
        }
        
        for(int i = 0; i < components.size(); i++){
            components[i]->Update();
        }
        if(vertexArray && objectShader){
            Core::App::Application::GetRenderer().DrawIndexed(vertexArray, objectShader, objectTexture, transform);
        }
        
        

    }
}
namespace Components {
    Sprite::Sprite(std::string imagePath, texture::ImageWrapping wrapType) : GameComponent("sprite2D") {
        path = imagePath;
        wrapType= wrapType;
    } 
    void Sprite::Start() {
        texture::Texture* texu =  Core::App::Application::GetRenderer().CreateTexture(path,wrapType);
        Shader* shader = Core::App::Application::GetRenderer().CreateShader("Assets/Shaders/2D/defaultShaderFrag.glsl","Assets/Shaders/2D/defaultShaderVert.glsl");
        VertexArray* v = Defaults::SquareSprite();
        parentObject->objectShader = std::move(shader);
        parentObject->vertexArray = std::move(v);
        parentObject->objectTexture = std::move(texu);
    }

    Camera::Camera(float fov, float aspectRatio, float nearPlane, float farPlane) : GameComponent("Camera") {
        this->fov = fov;
        this->aspectRatio = aspectRatio;
        this->nearPlane = nearPlane;
        this->farPlane = farPlane;
        this->sceneType = 3;
    }
    Camera::Camera(float left, float right, float bottom, float top, float nearPlane, float farPlane) : GameComponent("Camera"){
        this->left  = left;
        this->right = right;
        this->bottom = bottom;
        this->top = top;
        this->nearPlane = nearPlane;
        this->farPlane = farPlane;
        this->sceneType = 2;
    }
}