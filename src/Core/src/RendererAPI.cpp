#include "RendererAPI.h"

namespace Renderer{
    //Plugin::PluginStruct_GFX* RendererAPI::pRenderingBackend = nullptr;
    Shader* RendererAPI::CreateShader(std::string fragmentShaderPath, std::string vertexShaderPath){
        Shader* shad = pRenderingBackend.apiInstance->CreateShader();
        shad->Compile(fragmentShaderPath,vertexShaderPath);
        return shad;
    }
    void RendererAPI::AddToRenderQueue(VertexArray* vertArray, Shader* objShader, texture::Texture* m_texture,Components::Transform* objectTransform, RenderType type){
        pRenderingBackend.apiInstance->AddToRenderQueue(vertArray, objShader,m_texture,objectTransform,type);
    }
    void RendererAPI::Draw(){
        pRenderingBackend.apiInstance->Render();
    }
    VertexArray* RendererAPI::CreateVertexArray(std::vector<Vertex>* verts,std::vector<unsigned int>* inds){
        VertexArray* v = pRenderingBackend.apiInstance->CreateVAO();
        v->Create(verts,inds);
        return v;
    }
    texture::Texture* RendererAPI::CreateTexture(std::string path, texture::ImageWrapping wrapType){
        texture::Texture* pTexture = pRenderingBackend.apiInstance->CreateTexture(path,wrapType);
        return pTexture;
    }

    void RendererAPI::LoadShaders(){
        std::vector<ShaderPair> shaders = FindShaderPairs("Assets/Shaders");
        logger.InfoLog("LOADING SHADERS");
        
        for (const auto& shader : shaders) {
            logger.InfoLog("Found Shader Pair: %s PATHS:   Vertex: %s Fragment %s", shader.name.c_str(), shader.vertexPath.c_str(), shader.fragmentPath.c_str());
            shaderCollection[shader.name] = std::move(CreateShader(shader.fragmentPath.c_str(),shader.vertexPath.c_str()));


        }
        logger.InfoLog("FINISHED LOADING SHADERS");

    }
    Shader* RendererAPI::GetShader(std::string name){

        auto it = shaderCollection.find(name);
        if (it != shaderCollection.end()) {
            logger.InfoLog("SHADER: %s, Exists In Shader Collection", name.c_str());
            return shaderCollection[name];

        } else {
           logger.ErrorLog("SHADER: %s Not Found in collection");
           return NULL;
        }
    }
}