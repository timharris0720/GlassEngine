#pragma once
#include "core.h"
#include "Shader.h"

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

    class Renderer {
        public:
            Renderer() = default;
            std::vector<RenderData> renderData;
            Shader* CreateShader(std::string fragmentShaderPath, std::string vertexShaderPath);
    };
};