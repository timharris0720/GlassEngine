#include "RendererAPI.h"

namespace Renderer{
    //Plugin::PluginStruct_GFX* RendererAPI::pRenderingBackend = nullptr;
    Shader* RendererAPI::CreateShader(std::string fragmentShaderPath, std::string vertexShaderPath){
        Shader* shad = pRenderingBackend.apiInstance->CreateShader();
        shad->Compile(fragmentShaderPath,vertexShaderPath);
        return shad;
    }
    void RendererAPI::DrawIndexed(VertexArray* vertArray, Shader* objShader){
        pRenderingBackend.apiInstance->DrawVertexArray(vertArray, objShader);
    }
    VertexArray* RendererAPI::CreateVertexArray(std::vector<Vertex>* verts,std::vector<unsigned int>* inds){
        VertexArray* v = pRenderingBackend.apiInstance->CreateVAO();
        v->Create(verts,inds);
        return v;
    }
}