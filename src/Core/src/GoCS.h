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
//#define UseLoggerNonUt
#include <iostream>
#include "Logger.h"
#include "ErrorCodes.h"
#include "defaults.h"
#include <string>
#include "texture.h"
#include "Shader.h"
#include "VertexArray.h"
#include "ModelLoader.h"
#include "PrimitiveTypes.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>
#include <type_traits>
#include <memory>
#include <functional>


namespace GoCS {
    class GameComponent;
    class GameObject;
}
namespace Components {
    class Transform;
    class Sprite;
    class Mesh;
}
struct MeshObject {
    VertexArray rootMesh;
    std::vector<GoCS::GameObject> Children;

};



namespace GoCS {
    class GameComponent {
        public:
        std::string name;
        Logger logger = Logger("TempName", "Log.txt");
        GoCS::GameObject* parent;
        GoCS::GameObject* gameObject;
        
        //Core::App::Application* applicationInstance;
        GameComponent() = default;
        GLASS_ENGINE_API GameComponent(std::string name);
        virtual void Init() {};
        virtual void Start() {};
        virtual void Update() {};
        GLASS_ENGINE_API double getDeltaTime();
        GLASS_ENGINE_API void CloseApplication();
        void SetParent(GoCS::GameObject* _parentObject) {
            parent = _parentObject;
            //logger.InfoLog("Comp: Parent name: %s, %s", _parentObject->name.c_str(), parent->name.c_str());
        }
        void SetGameObject(GoCS::GameObject* _parentObject) {
            gameObject = _parentObject;
            //logger.InfoLog("Comp: Parent name: %s, %s", _parentObject->name.c_str(), parent->name.c_str());
        }
        GLASS_ENGINE_API Components::Transform* GetTransform(); 
            
        //virtual void Draw(Renderer::RendererAPI* renderer) {};
    };

    

    class GameObject {
        private:
            Logger logger = Logger("TempName", "Log.txt");
            GLASS_ENGINE_API void updateChildren();
            GLASS_ENGINE_API void updateComponents();
            GLASS_ENGINE_API void Draw();
        public: 
            std::vector<GameObject*> children;
            std::vector<std::unique_ptr<GameComponent>> components;

            std::string Tag;
            std::string name;
            GameObject* parent;
            GameObject* root;
            Components::Transform* transform;
            Shader* objectShader = nullptr;
            VertexArray* vertexArray = nullptr;
            texture::Texture* objectTexture = nullptr;
            
            bool isActive;
            bool isAlive;
            GameObject() = default;
            void Start() {};

            GLASS_ENGINE_API void Update();
            GameObject* GetChild(std::string m_name){
                logger.InfoLog("Size of Children of gameobject: %s %i",this->name.c_str(), children.size());
                
                for(GameObject* GO : children){
                    if(GO->name == m_name)
                    {
                        logger.InfoLog("Found %s Returning it", m_name.c_str()); 
                        return GO;
                    }
                    
                }
                return nullptr;
            }
            GLASS_ENGINE_API double getDeltaTime();
            GLASS_ENGINE_API GameObject* getRootGameObject();
            void SetParent(GameObject* parentObject) {
                parent = parentObject;
            }
            void setLN(std::string n){
                logger.setLoggerName(n);
            }
            template <typename T, typename... Args>
            T* AddComponent(Args&&... args) {
                if (std::is_base_of<GameComponent, T>()) {
                    auto component = std::make_unique<T>(std::forward<Args>(args)...);
                    T* ptr = component.get();
                    ptr->SetParent(parent);
                    ptr->SetGameObject(this);
                    logger.DebugLog("Adding Component %s to GameObject-Parent %s, Componenets GameObject Name: %s", component->name.c_str(), component->parent->name.c_str(),component->gameObject->name.c_str());
                    
                    //ptr->root = root;
                    //ptr->Init();
                    ptr->Start();
                    
                    components.push_back(std::move(component));
                    
                    return ptr;
                }
                return NULL;
            }
            template <typename T>
            T* GetComponent() {
                static_assert(std::is_base_of<GameComponent, T>::value, "T must inherit from GameComponent");

                for (auto& component : components) {
                    if (T* casted = dynamic_cast<T*>(component.get()))  return casted;   
                }
                return nullptr;
            }
            GLASS_ENGINE_API GameObject* CreateChild(std::string name);
            GLASS_ENGINE_API GameObject(std::string name);
            GLASS_ENGINE_API GameObject(std::string name, GameObject* pParent);
    };
}

namespace Components {
    class Transform : public GoCS::GameComponent {
        public:
            glm::vec3 Position = glm::vec3(0.0f, 0.0f, 0.0f);
            glm::vec3 Rotation = glm::vec3(0.0f, 0.0f, 0.0f);
            glm::vec3 LocalRotation = glm::vec3(0.0f, 0.0f, 0.0f);
            glm::vec3 Scale    = glm::vec3(1.0f, 1.0f, 1.0f);
            
            glm::mat4 applyTransform(){
                glm::mat4 model = glm::mat4(1.0f); // Start with an identity matrix
                model = glm::translate(model, Position);

                // Apply rotation (convert degrees to radians)
                model = glm::rotate(model, glm::radians(Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)); // Rotate around X-axis
                model = glm::rotate(model, glm::radians(Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotate around Y-axis
                model = glm::rotate(model, glm::radians(Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f)); // Rotate around Z-axis

                // Apply scaling
                model = glm::scale(model, Scale);
                
                return model;
            }
            
    };
    class Sprite : public GoCS::GameComponent{
        private:
        std::string path;
        texture::ImageWrapping wrapType;
        Primitives::PrimitiveType_2D CurrentSpriteType;
        glm::vec2 textueScalingWidth;
        float radius = 0.5f;
        float segments = 64;
        std::string shaderName = "2D_Unlit";
        public:
            GLASS_ENGINE_API Sprite() = default;
            GLASS_ENGINE_API Sprite(std::string imagePath,texture::ImageWrapping wrapType,Primitives::PrimitiveType_2D type, glm::vec2 scalingWidth = glm::vec2(1));
            GLASS_ENGINE_API Sprite(std::string imagePath, texture::ImageWrapping wrapType, Primitives::PrimitiveType_2D type, int Segments, float Radius,glm::vec2 scalingWidth = glm::vec2(1));
            GLASS_ENGINE_API void Start();
            GLASS_ENGINE_API void Hello();

    };
    class Mesh : public GoCS::GameComponent {
        private:
            std::string path;
            bool PrimativeMesh;
            Primitives::PrimitiveType_3D PrimType;
        public:
            GLASS_ENGINE_API Mesh() = default;
            GLASS_ENGINE_API Mesh(std::string path);
            GLASS_ENGINE_API Mesh(Primitives::PrimitiveType_3D type);
            GLASS_ENGINE_API void Start();
    };

    


   
    class Camera : public GoCS::GameComponent {
        private:
        
        glm::mat4 m_ViewMatrix = glm::mat4(1.0f);
        glm::mat4 m_ProjectionMatrix = glm::mat4(1.0f);
        enum ProjectionType {Perspective, Orthographic};
        ProjectionType projection;
        int windowWidth = 800, windowHeight = 600;
        public:
        float FarClip = 100;
        float NearClip = 0.1f;
        float Fov = 90.0f;
        float AspectRatio = 1.7f;

        glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
        GLASS_ENGINE_API Camera() = default; // Orthographic camera Constructor
        GLASS_ENGINE_API Camera(float fov, int width, int height, float nearClippingPlane, float farClippingPlane); // Perspective camera Constructor
        GLASS_ENGINE_API Camera(int width, int height, float nearClippingPlane, float farClippingPlane); // Perspective camera Constructor
        const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }

        // use https://github.com/VictorGordan/opengl-tutorials/blob/main/YoutubeOpenGL%208%20-%20Camera/Camera.h for camera code
        GLASS_ENGINE_API void Update();
        GLASS_ENGINE_API void Start();
        
        private:
        void RecaculateMatrices(){
            //calc Projection
            switch (projection)
            {
            case ProjectionType::Perspective:
                /* code */
                m_ProjectionMatrix = glm::perspective(glm::radians(Fov), AspectRatio, NearClip, FarClip);

                break;
            case ProjectionType::Orthographic:
                m_ProjectionMatrix = glm::ortho(0.0f,(float)windowWidth,0.0f,(float)windowHeight, NearClip, FarClip);
                break;
            default:
                logger.ErrorLog("ProjectionTypeFuckeddd");
                break;
            }
            float pitch = glm::radians(gameObject->transform->Rotation.x);
            float yaw   = glm::radians(gameObject->transform->Rotation.y);

            glm::vec3 front;
            front.x = cos(pitch) * cos(yaw);
            front.y = sin(pitch);
            front.z = cos(pitch) * sin(yaw);
            front = glm::normalize(front);

            glm::vec3 right = glm::normalize(glm::cross(front, glm::vec3(0, 1, 0)));
            glm::vec3 up    = glm::normalize(glm::cross(right, front));
            m_ViewMatrix = glm::lookAt(gameObject->transform->Position, gameObject->transform->Position + front, up);;
            //calc view
        }


    };

    
}


