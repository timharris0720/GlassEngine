#include "GoCS.h"
#include "core.h"
#include "BinarySearching.h"
#include "ModelLoading/OBJ_Loader.h"

namespace GoCS {
    GameComponent::GameComponent(std::string name) {
        this->name = name;
        logger.setLoggerName(name + "_component");
    }
    double GameComponent::getDeltaTime(){
        return parent->getDeltaTime();
    }
    void GameComponent::CloseApplication(){
        Core::App::Application::GetInstance().shutdown();
        exit(0);
    }
    Components::Transform* GameComponent::GetTransform(){
        return parent->transform;
    }


    GameObject::GameObject(std::string name){
        this->name = name;
        transform = new Components::Transform();
        logger.setLoggerName(name);
        Core::App::Application::GetInstance().PushGameObject(this);
    }
    double GameObject::getDeltaTime(){
        return Core::App::Application::GetInstance().GetDeltaTime();
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

    void GameObject::updateChildren(){
        for(auto c : children){
            c->Update();
        }
    }
    void GameObject::updateComponents(){
         for(int i =0; i < components.size(); i++){
            components[i]->Update();
        }
    }
    void GameObject::Draw(){
        if(vertexArray != nullptr && objectShader != nullptr){
            //logger.InfoLog("Added Object %s to render queue, indicies cout %u, PTRS: trans %p VA %p Shader %p TEXU %p ", this->name.c_str(), vertexArray->IndiciesCount,transform,vertexArray,objectShader,objectTexture);
            Core::App::Application::GetRenderer().AddToRenderQueue(vertexArray, objectShader, objectTexture, transform);
        }
    }


    void GameObject::Update(){
        Draw();
        if(components.size() > 0){
            updateComponents();
        }
        updateChildren();
        
        
        
    }
    
    GameObject* GameObject::getRootGameObject() {
        return root;
    }
    
    
    
}


namespace Components {
    Sprite::Sprite(std::string imagePath, texture::ImageWrapping wrapType, Primitives::PrimitiveType_2D type,glm::vec2 scalingWidth) : GameComponent("Sprite2D") {
        path = imagePath;
        wrapType= wrapType;
        CurrentSpriteType = type;
        textueScalingWidth = scalingWidth;
    } 
    Sprite::Sprite(std::string imagePath, texture::ImageWrapping wrapType, Primitives::PrimitiveType_2D type, int Segments, float Radius,glm::vec2 scalingWidth) : GameComponent("Sprite2D") {
        path = imagePath;
        wrapType= wrapType;
        CurrentSpriteType = type;
        textueScalingWidth = scalingWidth;
        radius = Radius;
        segments = Segments;
    } 
    void Sprite::Start() {
        texture::Texture* texu =  Core::App::Application::GetRenderer().CreateTexture(path,wrapType);
        Shader* shader = Core::App::Application::GetRenderer().CreateShader("Assets/Shaders/2D/2D_Unlit_Fragment.glsl","Assets/Shaders/2D/2D_Unlit_Vertex.glsl");
        VertexArray* v;
        if(CurrentSpriteType == Primitives::PrimitiveType_2D::SQUARE){
            v = Defaults::SquareSprite(textueScalingWidth);
        }
        else if(CurrentSpriteType == Primitives::PrimitiveType_2D::CIRCLE){
            v = Defaults::Circle(radius,segments,textueScalingWidth);
        }
        gameObject->objectShader = std::move(shader);
        gameObject->vertexArray = std::move(v);
        gameObject->objectTexture = std::move(texu);
    }

    #pragma region Mesh
    Mesh::Mesh(std::string path): GameComponent("MeshRenderer") { // add material aswell (at later date)
        this->path = path;
        PrimativeMesh = false;
    }
    Mesh::Mesh(Defaults::PrimativeType type){
        PrimativeMesh = true;
        PrimType = type;
    }
    void Mesh::Start(){
        if(PrimativeMesh == false){
            ModelMesh mesh = OBJ::OBJLoader::ReadOBJ_File(path);
        }
        else{
            texture::Texture* texu =  Core::App::Application::GetRenderer().CreateTexture("Assets/Textures/Brick100/Bricks100_1K-JPG_Roughness.jpg",texture::REPEAT);

            Shader* shader = Core::App::Application::GetRenderer().CreateShader("Assets/Shaders/3D/3D_Unlit_Fragment.glsl","Assets/Shaders/3D/3D_Unlit_Vertex.glsl");
            VertexArray* v;
            switch(PrimType) {
                case Defaults::CUBE:
                    v = Defaults::Cube();
                    logger.InfoLog("Cube Mesh");
                    break;
                case Defaults::SPHERE:
                    logger.InfoLog("Spehere Mesh");
                    break;
            }
            gameObject->objectShader = std::move(shader);
            gameObject->vertexArray = std::move(v);

            gameObject->objectTexture = std::move(texu);
        }
    }


    #pragma endregion
    #pragma region Camera
    Camera::Camera(float fov, int width, int height, float nearClippingPlane, float farClippingPlane) :  GameComponent("Camera"){
        Fov = fov;
        AspectRatio = width / height;
        if(nearClippingPlane <= 0.0f){
            logger.ErrorLog("Near Clip is less than 0 breaking");
        }
        NearClip = nearClippingPlane;
        FarClip = farClippingPlane;
        windowWidth = width;
        windowHeight =  height; 
        projection = ProjectionType::Perspective;
    }
    Camera::Camera(int width, int height, float nearClippingPlane, float farClippingPlane) :  GameComponent("Camera"){
        
        AspectRatio = width / height;
        if(nearClippingPlane <= 0.0f){
            logger.ErrorLog("Near Clip is less than 0 breaking");
        }
        NearClip = nearClippingPlane;
        FarClip = farClippingPlane;
        windowWidth = width;
        windowHeight =  height;
        projection = ProjectionType::Orthographic;
        
    }
    void Camera::Start(){
        RecaculateMatrices();
    }

    void Camera::Update(){
        RecaculateMatrices();
    }
    #pragma endregion
}
