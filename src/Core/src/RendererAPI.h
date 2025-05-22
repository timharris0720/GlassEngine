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
#include "pluginLoader.h"
#include "VertexArray.h"
#include "texture.h"
#include <map>

#include <filesystem>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

#include <filesystem>
namespace fs = std::filesystem;

namespace Renderer {
    struct ShaderPair {
        std::string name;
        std::string vertexPath;
        std::string fragmentPath;
    };
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
            std::map<std::string, Shader*> shaderCollection;

            bool endsWith(const std::string& str, const std::string& suffix) {
                return str.size() >= suffix.size() &&
                       str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
            }
            
            std::vector<ShaderPair> FindShaderPairs(const std::string& rootPath) {
                std::unordered_map<std::string, ShaderPair> shaderMap;
            
                for (const auto& entry : fs::recursive_directory_iterator(rootPath)) {
                    if (!entry.is_regular_file()) continue;
            
                    fs::path path = entry.path();
                    if (path.extension() != ".glsl") continue;
            
                    std::string filename = path.stem().string();  // e.g., "basic_Vertex"
                    std::string fullpath = path.string();
            
                    if (endsWith(filename,"_Vertex")) {
                        std::string baseName = filename.substr(0, filename.size() - 7); // "_Vertex" is 7 chars
                        shaderMap[baseName].vertexPath = fullpath;
                        shaderMap[baseName].name = baseName;
                    } else if (endsWith(filename,"_Fragment")) {
                        std::string baseName = filename.substr(0, filename.size() - 9); // "_Fragment" is 9 chars
                        shaderMap[baseName].fragmentPath = fullpath;
                        shaderMap[baseName].name = baseName;
                    }
                }
            
                std::vector<ShaderPair> pairs;
                for (const auto& [baseName, pair] : shaderMap) {
                    if (!pair.vertexPath.empty() && !pair.fragmentPath.empty()) {
                        pairs.push_back(pair);
                    } else {
                        std::cerr << "⚠️ Incomplete shader pair: " << baseName << std::endl;
                    }
                }
            
                return pairs;
            }



        public:

            RendererAPI() = default;
            Plugin::PluginStruct_GFX pRenderingBackend;
            void SetBackend(Plugin::PluginStruct_GFX backend) {pRenderingBackend = std::move(backend);}
            Plugin::PluginStruct_GFX& GetBackend() {return pRenderingBackend;}

            GLASS_ENGINE_API void LoadShaders();
            GLASS_ENGINE_API Shader* GetShader(std::string name);


            GLASS_ENGINE_API Shader* CreateShader(std::string fragmentShaderPath, std::string vertexShaderPath);
            GLASS_ENGINE_API VertexArray* CreateVertexArray(std::vector<Vertex>* verts,std::vector<unsigned int>* inds);
            GLASS_ENGINE_API texture::Texture* CreateTexture(std::string path, texture::ImageWrapping wrapType);
            GLASS_ENGINE_API void AddToRenderQueue(VertexArray* vertArray, Shader* objShader, texture::Texture* m_texture = nullptr,Components::Transform* objectTransform = nullptr, RenderType type = RenderType::INDEXED);
            GLASS_ENGINE_API void Draw();
    };
};
