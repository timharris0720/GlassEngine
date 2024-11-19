#include "RendererAPI.h"

namespace Renderer{
    Shader* RendererAPI::CreateShader(std::string fragmentShaderPath, std::string vertexShaderPath){
        return pRenderingBackend->apiInstance->CreateShader(fragmentShaderPath,vertexShaderPath);
    }
}