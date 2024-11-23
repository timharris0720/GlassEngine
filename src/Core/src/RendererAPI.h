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
    struct Vertex {
        glm::vec2 textureCoord;
        glm::vec3 color = glm::vec3(1);
        glm::vec3 position;
    };
    struct RenObject {
      // Vertex - Color, textCoord, Pos / vector
      std::vector<Vertex> ObjectVertices;
      Shader ObjectsShader;
      // Shader


    };

    struct RenderData {
        // Vector Object 
        std::vector<RenObject> RenderObjects;
        
    };

    class RendererAPI {
        private:
        
        public:
            RendererAPI() = default;
            Plugin::PluginStruct_GFX pRenderingBackend;
            void SetBackend(Plugin::PluginStruct_GFX backend) {pRenderingBackend = std::move(backend);}
            Plugin::PluginStruct_GFX& GetBackend() {return pRenderingBackend;}
            
            GLASS_ENGINE_API Shader* CreateShader(std::string fragmentShaderPath, std::string vertexShaderPath);
        public:
            std::vector<RenderData> renderData;
    };
};