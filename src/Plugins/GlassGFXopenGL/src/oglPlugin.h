#pragma once
#ifdef _WIN32
#ifdef GLASS_PLUGIN_EXPORTS
#define GLASS_PLUGIN_API __declspec(dllexport)
#else
#define GLASS_PLUGIN_API __declspec(dllimport)
#endif
#else
#define GLASS_PLUGIN_API
//#define OPENGL_PLUGIN_API __declspec(dllimport)
#endif
#include "GlassEngine/plugin.h"
#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include "GlassEngine/GlassEngine.h"
#include "texture.h"
#include "version_opengl.h"
class OpenGLShader : public Shader {
private:
    Logger logger = Logger("GlassGFX.OpenGL.Plugin.OpenGLShader", "Log.txt");
public:
    GLASS_PLUGIN_API void Compile(std::string fragmentShaderPath, std::string vertexShaderPath) override;
    GLASS_PLUGIN_API void Bind() override;
    GLASS_PLUGIN_API void Unbind() override;
    GLASS_PLUGIN_API void setBool(const std::string& name, bool value) override ;
    GLASS_PLUGIN_API void setInt(const std::string& name, int value) override;
    GLASS_PLUGIN_API void setFloat(const std::string& name, float value) override;
    GLASS_PLUGIN_API void setVec2(const std::string& name, const glm::vec2& value) override;
    GLASS_PLUGIN_API void setVec2(const std::string& name, float x, float y) override;
    GLASS_PLUGIN_API void setVec3(const std::string& name, const glm::vec3& value) override;
    GLASS_PLUGIN_API void setVec3(const std::string& name, float x, float y, float z) override;
    GLASS_PLUGIN_API void setVec4(const std::string& name, const glm::vec4& value) override;
    GLASS_PLUGIN_API void setVec4(const std::string& name, float x, float y, float z, float w) override;
    GLASS_PLUGIN_API void setMat2(const std::string& name, const glm::mat2& mat) override;
    GLASS_PLUGIN_API void setMat3(const std::string& name, const glm::mat3& mat) override;
    GLASS_PLUGIN_API void setMat4(const std::string& name, const glm::mat4& mat) override;
    void checkCompileErrors(GLuint shader, std::string type);
};
class OpenGLRenderAPI : public GlassPlugin_GFX {
private:
    GLFWwindow* window;
    Logger logger = Logger("GlassGFX.OpenGL.Plugin", "Log.txt");
    Components::Camera* sceneCameraComponent;
    Components::Transform* scenecamtrans;
    
public:
    
    GLASS_PLUGIN_API bool onLoad() override;
    GLASS_PLUGIN_API void createRenderContext(WindowProperties* winProps) override;
    GLASS_PLUGIN_API void* GetNativeWindow() const {return window;}
    void GlfwErrorCB(int error, const char* description);
    GLASS_PLUGIN_API void Update() override;
    GLASS_PLUGIN_API void BeginScene(GoCS::GameObject* mCamera) override;
    GLASS_PLUGIN_API void EndScene() override;
    GLASS_PLUGIN_API double GetTime() override;
    GLASS_PLUGIN_API bool shouldWindowClose() override;
    GLASS_PLUGIN_API void Shutdown() override;
    GLASS_PLUGIN_API void Render() override;
    GLASS_PLUGIN_API void VsyncCallback() override {
        glfwSwapInterval(winData.vsync);
    }
    GLASS_PLUGIN_API Shader* CreateShader();
    GLASS_PLUGIN_API VertexArray* CreateVAO();
    GLASS_PLUGIN_API texture::Texture* CreateTexture(std::string path,texture::ImageWrapping wrapType);
    GLASS_PLUGIN_API void DrawVertexArray(RenderCommand* renderCMD) override;
    GLASS_PLUGIN_API void AddToRenderQueue(VertexArray* vertArray, Shader* objShader,texture::Texture* m_texture = nullptr, Components::Transform* objectTransform = nullptr, RenderType type = RenderType::INDEXED) override;
};
//void DrawVertexArray(Renderer::VertexArray* vert) {}
class OGLVertexArray : public VertexArray {

    private:

    Logger logger = Logger("GlassGFX.OpenGL.Plugin.OGLVertexArray", "Log.txt");
    public:
    GLASS_PLUGIN_API void Create(std::vector<Vertex>* vertices,std::vector<unsigned int>* indices) override;
    GLASS_PLUGIN_API void Bind();
    GLASS_PLUGIN_API void Unbind();
};
class OpenGLTexture : public texture::Texture {
    private:
    Logger logger = Logger("GlassGFX.OpenGL.Plugin.OpenGLTexture", "Log.txt");
    public:
    unsigned int textureID;
    GLASS_PLUGIN_API OpenGLTexture(std::string name,texture::ImageWrapping wrapType);
    GLASS_PLUGIN_API void Bind();
};

