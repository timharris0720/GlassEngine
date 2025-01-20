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
    void GameObject::Update(){
        if(children.size() > 0){
            for(GameObject* child : children){
                child->Update();
            }
        }
        for(int i = 0; i < components.size(); i++){
            components[i]->Update();
        }
        if(objectShader)
            Core::App::Application::GetRenderer().DrawIndexed(vertexArray, objectShader);
    
    }
}
namespace Components {
    Sprite::Sprite(std::string imagePath) : GameComponent("sprite2D") {
        sprite = ImageUtils::Image(imagePath);

        
        
    } 
    void Sprite::Start() {
        Shader* shader = Core::App::Application::GetRenderer().CreateShader("Assets/Shaders/2D/frag.glsl","Assets/Shaders/2D/vert.glsl");
        Vertex Vertex1;
        Vertex1.vertices = glm::vec3(-0.5f, -0.5f,0.0f);
        Vertex1.color = glm::vec3(1,1,1);
        Vertex Vertex2;
        Vertex2.vertices = glm::vec3(0.5f, -0.5f,0.0f);
        Vertex2.color = glm::vec3(1,1,1);
        Vertex Vertex3;
        Vertex3.vertices = glm::vec3(0.5f,  0.5f,0.0f);
        Vertex3.color = glm::vec3(1,1,1);
        Vertex Vertex4;
        Vertex4.vertices = glm::vec3( -0.5f,  0.5f ,0.0f);
        Vertex4.color = glm::vec3(1,1,1);
        std::vector<Vertex> vertices = {
            Vertex1,Vertex2,Vertex3,Vertex4
        };
        std::vector<unsigned int> indices = {
            0, 1, 2, 
            2, 3, 0  
        };
        VertexArray* v = Core::App::Application::GetRenderer().CreateVertexArray(&vertices,&indices);
        parent->objectShader = std::move(shader);
        logger.InfoLog("Parent VA: %i", parent->vertexArray);
        logger.InfoLog("Parent   : %i", parent);
        
        this->parent->vertexArray = std::move(v);
    }
}