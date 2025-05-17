#include "GoCS.h"
#include "core.h"
#include "BinarySearching.h"

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
        int ind = Sorting::binary_search_recursive_gameobject_array( parent->children, this->transform->Position.z);
		
        parent->children.push_back(this);
		logger.DebugLog("Added Gameobject: %s to %s as a child", name.c_str(), pParent->name.c_str());

    }
    void GameObject::Update(){
        if(components.size() > 0){
            for(int i = 0; i < components.size(); i++){
                components[i]->Update();
            }
        }
        for(GameObject* child : children){
            child->Update();
        }
        
        
        if(vertexArray && objectShader){
            Core::App::Application::GetRenderer().DrawIndexed(vertexArray, objectShader, objectTexture, transform);
        }
    }
    
    GameObject* GameObject::getRootGameObject() {
        return root;
    }
    
    
    
}


namespace Components {
    Sprite::Sprite(std::string imagePath, texture::ImageWrapping wrapType) : GameComponent("Sprite2D") {
        path = imagePath;
        wrapType= wrapType;
    } 
    void Sprite::Start() {
        texture::Texture* texu =  Core::App::Application::GetRenderer().CreateTexture(path,wrapType);
        Shader* shader = Core::App::Application::GetRenderer().CreateShader("Assets/Shaders/2D/2D_Unlit_Fragment.glsl","Assets/Shaders/2D/2D_Unlit_Vertex.glsl");
        VertexArray* v = Defaults::SquareSprite();
        parent->objectShader = std::move(shader);
        parent->vertexArray = std::move(v);
        parent->objectTexture = std::move(texu);
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
            Assimp::Importer importer;
            const aiScene* scene = OpenModel(path, importer);
            if (!scene) {
                logger.ErrorLog("Failed to load model: %s", path.c_str());
                return;
            }
            //logger.InfoLog("Parse Start, scene meshes %u", scene->mNumMeshes);
            //logger.InfoLog("Scene Root node children %u", scene->mRootNode->mNumMeshes);
            
            
            ProcessNode(scene->mRootNode, scene, *parent);
            /*
                Create MeshObject
                Process Root mesh
                Process Children and create their gameobjects
            
            */

            //ProcessNode(scene->mRootNode,scene);
        }
        else{
            texture::Texture* texu =  Core::App::Application::GetRenderer().CreateTexture("Textures/Brick100/Bricks100_1K-JPG_Roughness.jpg",texture::REPEAT);

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

            //parent->objectTexture = std::move(texu);
        }
    }
    void Mesh::ProcessNode(aiNode* node, const aiScene* scene,GoCS::GameObject& GO){
        GoCS::GameObject temp(node->mName.C_Str());

        for (unsigned int i = 0; i < node->mNumMeshes; i++) {
            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
            ProcessMesh(mesh, temp);
        }

        GO.children.push_back(&temp);

        for (unsigned int i = 0; i < node->mNumChildren; i++) {
            ProcessNode(node->mChildren[i], scene, temp);
        }



    }

    void Mesh::ProcessMesh(aiMesh* mesh, GoCS::GameObject& GO){
        std::vector<Vertex> verts;
        std::vector<unsigned int> faceIndices;

        for(int i = 0 ; i < mesh->mNumVertices; i++){
            Vertex v;
            aiVector3D vert = mesh->mVertices[i];
            aiVector3D* uvs = mesh->mTextureCoords[0];
            aiVector3D normals = mesh->mNormals[i];
            
            v.vertices = glm::vec3(vert.x,vert.y,vert.z);

            //Vertex Color
            if(mesh->HasVertexColors(0)){
                v.color = glm::vec3(mesh->mColors[0][i].r, mesh->mColors[0][i].g, mesh->mColors[0][i].b);
            }
            // Vertex Normal
            if (mesh->HasNormals()) {
                v.normal = glm::vec3(mesh->mNormals[i].x,mesh->mNormals[i].y,mesh->mNormals[i].z);
            }
            // Texture Coords (UV)
            if(mesh->HasTextureCoords(0)){
                v.uv = glm::vec2(uvs[i].x,uvs[i].y);
            }
            verts.push_back(v);
        }
        //Process face indicies
        for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
            aiFace face = mesh->mFaces[i];
            for (unsigned int j = 0; j < face.mNumIndices; j++) {
                faceIndices.push_back(face.mIndices[j]);
            }

        }
        VertexArray* v  = Core::App::Application::GetRenderer().CreateVertexArray(&verts,&faceIndices);
        Shader* shader = Core::App::Application::GetRenderer().CreateShader("Assets/Shaders/3D/3D_Unlit_Fragment.glsl","Assets/Shaders/3D/3D_Unlit_Vertex.glsl");
        GO.vertexArray = std::move(v);
        GO.objectShader = std::move(shader);
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
