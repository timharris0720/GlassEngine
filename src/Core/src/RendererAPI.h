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
#include <glm/glm.hpp>
#include "pluginLoader.h"
#include "VertexArray.h"
#include "texture.h"
namespace Renderer {
    
    /*
    
    plugin - returns shader* CreateShader(frag, vert)


    class Shader {
        bind
        unbind
        extern "C" Shader* create() {
            return new shaderOpenGL();
        }

    }
    
    */
    

    class RendererAPI {
        private:
            Logger logger = Logger("Core.RenderAPI", "Log.txt");

        public:

            RendererAPI() = default;
            Plugin::PluginStruct_GFX pRenderingBackend;
            void SetBackend(Plugin::PluginStruct_GFX backend) {pRenderingBackend = std::move(backend);}
            Plugin::PluginStruct_GFX& GetBackend() {return pRenderingBackend;}
            GLASS_ENGINE_API Shader* CreateShader(std::string fragmentShaderPath, std::string vertexShaderPath);
            GLASS_ENGINE_API VertexArray* CreateVertexArray(std::vector<Vertex>* verts,std::vector<unsigned int>* inds);
            GLASS_ENGINE_API texture::Texture* CreateTexture(std::string path);
            GLASS_ENGINE_API void DrawIndexed(VertexArray* vertArray, Shader* objShader, texture::Texture* m_texture = nullptr);
    };
};
