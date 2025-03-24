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
    Sprite::Sprite(std::string imagePath, texture::ImageWrapping wrapType) : GameComponent("Sprite2D") {
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

    #pragma region Mesh
    Mesh::Mesh(std::string path): GameComponent("Mesh") {
        this->path = path;
    }
    void Mesh::Start(){
        Assimp::Importer importer;
        const aiScene* scene = OpenModel(path, importer);
        if (!scene) {
            logger.ErrorLog("Failed to load model: %s", path.c_str());
            return;
        }
        logger.InfoLog("Parse Start, scene meshes %u", scene->mNumMeshes);
        logger.InfoLog("Scene Root node children %u", scene->mRootNode->mNumMeshes);
        ProcessNode(scene->mRootNode,scene);
        logger.InfoLog("Parsed End");

    }
    void Mesh::ProcessNode(aiNode* node, const aiScene* scene) {
        for (unsigned int i = 0; i < node->mNumMeshes; i++) {
            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
            ProcessMesh(mesh, scene);
        }

        for (unsigned int i = 0; i < node->mNumChildren; i++) {
            ProcessNode(node->mChildren[i], scene);
        }
    }
    void Mesh::ProcessMesh(aiMesh* mesh, const aiScene* scene){
        logger.InfoLog("Processing mesh with %u vertices",  mesh->mNumVertices);
        for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
            // Extract vertex positions
            aiVector3D vertex = mesh->mVertices[i];
            logger.InfoLog("Vertex Position: %f %f %f ", vertex.x ,vertex.y ,vertex.z );
            // Extract normals (if available)
            if (mesh->HasNormals()) {
                aiVector3D normal = mesh->mNormals[i];
                //std::cout << "Normal: " << normal.x << ", " << normal.y << ", " << normal.z << std::endl;
            }

            // Extract texture coordinates (if available)
            if (mesh->mTextureCoords[0]) { // Only 1 set of UVs is considered here
                aiVector3D texCoord = mesh->mTextureCoords[0][i];
               // std::cout << "TexCoord: " << texCoord.x << ", " << texCoord.y << std::endl;
            }
        }

        // Extract indices
        for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
            aiFace face = mesh->mFaces[i];
            std::cout << "Face Indices: ";
            for (unsigned int j = 0; j < face.mNumIndices; j++) {
                std::cout << face.mIndices[j] << " ";
            }
            std::cout << std::endl;
        }
    }



    #pragma endregion
    #pragma region Camera


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
    #pragma endregion
}