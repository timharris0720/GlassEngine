#include "GoCS.h"
#include "core.h"
namespace GoCS {
    GameComponent::GameComponent(std::string name) {
        this->name = name;
        logger.setLoggerName(name + "_component");
        
        //logger.DebugLog("Adding Component %s to GameObject %s", name.c_str(), parent->name);
    }
    double GameComponent::getDeltaTime(){
        return parentObject->getDeltaTime();
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
    void GameObject::Update(){
        if(components.size() > 0){
            for(int i = 0; i < components.size(); i++){
                components[i]->Update();
            }
        }
        for(GameObject* child : children){
            logger.InfoLog("Child: %s", child->name);
            child->Update();
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
        //logger.InfoLog("Parse Start, scene meshes %u", scene->mNumMeshes);
        //logger.InfoLog("Scene Root node children %u", scene->mRootNode->mNumMeshes);
        
        
        ProcessNode(scene->mRootNode, scene, *parentObject);
        /*
            Create MeshObject
            Process Root mesh
            Process Children and create their gameobjects
        
        */

        //ProcessNode(scene->mRootNode,scene);
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
        Shader* shader = Core::App::Application::GetRenderer().CreateShader("Assets/Shaders/2D/defaultShaderFrag.glsl","Assets/Shaders/2D/defaultShaderVert.glsl");
        GO.vertexArray = std::move(v);
        GO.objectShader = std::move(shader);
    }



    #pragma endregion
    #pragma region Camera


    Camera::Camera(float fov, float aspect, float near, float far) : GameComponent("Camera") {
        this->fov = fov;
        this->aspectRatio = aspectRatio;
        this->nearPlane = nearPlane;
        this->farPlane = farPlane;
        this->projectionType = ProjectionType::Perspective;
        updateProjectionMatrix();
    }
    Camera::Camera(float left, float right, float bottom, float top, float near, float far) : GameComponent("Camera"){
        this->orthoLeft  = left;
        this->orthoRight = right;
        this->orthoBottom = bottom;
        this->orthoTop = top;
        this->nearPlane = nearPlane;
        this->farPlane = farPlane;
        this->projectionType = ProjectionType::Orthographic;
        updateProjectionMatrix();

    }
    void Camera::Start(){
        this->transform = parentObject->transform;
    }
    #pragma endregion
}