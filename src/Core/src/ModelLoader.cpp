#include "ModelLoader.h"
#include "core.h"
const aiScene* OpenModel(std::string path, Assimp::Importer& importer){
    VertexArray vt;
    const aiScene* scene = importer.ReadFile(path,  aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals);
    if (!scene || !scene->mRootNode || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE) {
        Core::App::Application::GetInstance().GetLogger()->ErrorLog("Assimp Error: %s", importer.GetErrorString());
    }
    Core::App::Application::GetInstance().GetLogger()->InfoLog("Model Loaded, mesh count: %u", scene->mNumMeshes);
    return scene;
}
