#include "RendererAPI.h"

namespace Renderer{
    //Plugin::PluginStruct_GFX* RendererAPI::pRenderingBackend = nullptr;
    Shader* RendererAPI::CreateShader(std::string fragmentShaderPath, std::string vertexShaderPath){
        return pRenderingBackend.apiInstance->CreateShader(fragmentShaderPath,vertexShaderPath);
    }
}