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
        GoCS::GameObject* parentObject;
        
        //Core::App::Application* applicationInstance;
        GameComponent() = default;
        GLASS_ENGINE_API GameComponent(std::string name);
        virtual void Init() {};
        virtual void Start() {};
        virtual void Update() {};
        GLASS_ENGINE_API double getDeltaTime();
        GLASS_ENGINE_API void CloseApplication();
        void SetParent(GoCS::GameObject* _parentObject) {
            parentObject = _parentObject;

        }
        GLASS_ENGINE_API Components::Transform* GetTransform(); 
            
        //virtual void Draw(Renderer::RendererAPI* renderer) {};
    };

    

    class GameObject {
        private:
            Logger logger = Logger("TempName", "Log.txt");

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

            void Start() {};
            GLASS_ENGINE_API void Update();
            GLASS_ENGINE_API double getDeltaTime();
            GameObject* getRootGameObject() {
                return root;
            }
            void SetParent(GameObject* parentObject) {
                parent = parentObject;
            }

            template <typename T, typename... Args>
            T* AddComponent(Args&&... args) {
                if (std::is_base_of<GameComponent, T>()) {
                    auto component = std::make_unique<T>(std::forward<Args>(args)...);
                    T* ptr = component.get();
                    ptr->SetParent(this);

                    //ptr->root = root;
                    //ptr->Init();
                    ptr->Start();

                    components.push_back(std::move(component));
                    
                    return ptr;
                }
                return NULL;
            }
            GameObject* GetChild(std::string name){
                for(GameObject* GO : children){
                    if(GO->name == name)
                    {
                        logger.InfoLog("Found %s Returning it", name.c_str()); 
                        return GO;
                    }
                    
                }
                return nullptr;
            }
            template <typename T>
            T* GetComponent() {
                static_assert(std::is_base_of<GameComponent, T>::value, "T must inherit from GameComponent");

                for (auto& component : components) {
                    if (T* casted = dynamic_cast<T*>(component.get()))  return casted;   
                }
                return nullptr;
            }
            GameObject* CreateChild(std::string name){
                GameObject* GO = new GameObject(name,  this);
                logger.DebugLog("Created Child Called %s, parent is %s", name.c_str(), this->name.c_str());
                return GO;
            }
            GameObject() = default;
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
        public:
            GLASS_ENGINE_API Sprite() = default;
            GLASS_ENGINE_API Sprite(std::string imagePath,texture::ImageWrapping wrapType);
            GLASS_ENGINE_API void Start();
            GLASS_ENGINE_API void Hello();

    };
    class Mesh : public GoCS::GameComponent {
        private:
            std::string path;
            bool PrimativeMesh;
            Defaults::PrimativeType PrimType;
            GLASS_ENGINE_API void ProcessMesh(aiMesh* mesh, GoCS::GameObject& GO);
            GLASS_ENGINE_API void ProcessNode(aiNode* node, const aiScene* scene, GoCS::GameObject& GO);

        public:
            GLASS_ENGINE_API Mesh() = default;
            GLASS_ENGINE_API Mesh(std::string path);
            GLASS_ENGINE_API Mesh(Defaults::PrimativeType type);
            GLASS_ENGINE_API void Start();
    };

    


    /*
    class Camera : public  GoCS::GameComponent {
    public:
        GLASS_ENGINE_API Camera() = default;
        GLASS_ENGINE_API Camera(std::string name);
        virtual ~Camera() = default;
        
        // Pure virtual methods for projection matrix
        virtual void setProjection(float width, float height){};
        virtual void updateProjectionMatrix(){};

        // Convenience methods for setting and getting position and rotation
        void setPosition(const glm::vec3& newPosition) { transform.Position = newPosition; }
        void setRotation(const glm::vec3& newRotation) { transform.Rotation = newRotation; }

        glm::vec3 getPosition() const { return transform.Position; }
        glm::vec3 getRotation() const { return transform.Rotation; }
        glm::mat4 getViewMatrix() const {
            glm::vec3 position = getPosition();
            glm::vec3 rotation = getRotation();

            // Calculate forward, right, and up vectors from the rotation
            glm::vec3 forward = glm::normalize(glm::vec3(
                cos(glm::radians(rotation.y)) * cos(glm::radians(rotation.x)),
                sin(glm::radians(rotation.x)),
                sin(glm::radians(rotation.y)) * cos(glm::radians(rotation.x))
            ));
            glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
            glm::vec3 right = glm::normalize(glm::cross(up, forward));
            up = glm::normalize(glm::cross(forward, right));

            return glm::lookAt(position, position + forward, up);
        }
        glm::mat4 getProjectionMatrix() const {return projectionMatrix;}
        glm::mat4 projectionMatrix{1.0f};
        Components::Transform transform;
    };
    class PerspectiveCamera : public Camera {
    public:
        float fov; // Field of View in degrees
        float aspectRatio;
        float nearPlane;
        float farPlane;
        PerspectiveCamera() = default;
        PerspectiveCamera(float fov, float aspectRatio, float nearPlane, float farPlane) : fov(fov), aspectRatio(aspectRatio), nearPlane(nearPlane), farPlane(farPlane), Camera("Camera") {
            updateProjectionMatrix();
        }

        void setProjection(float width, float height) override {
            aspectRatio = width / height;
            updateProjectionMatrix();
        }

        void updateProjectionMatrix() override {
            projectionMatrix = glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
        }

        void setFOV(float newFov) {
            fov = newFov;
            updateProjectionMatrix();
        }
        
    };
    class OrthoCamera : public Camera {
    public:
        OrthoCamera() = default;
        OrthoCamera(float left, float right, float bottom, float top, float nearPlane, float farPlane) : left(left), right(right), bottom(bottom), top(top), nearPlane(nearPlane), farPlane(farPlane), Camera("Camera") {
            updateProjectionMatrix();
        }

        void setProjection(float width, float height) override {
            left = -width / 2.0f;
            right = width / 2.0f;
            bottom = -height / 2.0f;
            top = height / 2.0f;
            updateProjectionMatrix();
        }

        void updateProjectionMatrix() override {
            projectionMatrix = glm::ortho(left, right, bottom, top, nearPlane, farPlane);
        }
        float left;
        float right;
        float bottom;   
        float top;
        float nearPlane;
        float farPlane;
    };

    */
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
            float pitch = glm::radians(parentObject->transform->Rotation.x);
            float yaw   = glm::radians(parentObject->transform->Rotation.y);

            glm::vec3 front;
            front.x = cos(pitch) * cos(yaw);
            front.y = sin(pitch);
            front.z = cos(pitch) * sin(yaw);
            front = glm::normalize(front);

            glm::vec3 right = glm::normalize(glm::cross(front, glm::vec3(0, 1, 0)));
            glm::vec3 up    = glm::normalize(glm::cross(right, front));
            m_ViewMatrix = glm::lookAt(parentObject->transform->Position, parentObject->transform->Position + front, up);;
            //calc view
        }


    };

    
}


