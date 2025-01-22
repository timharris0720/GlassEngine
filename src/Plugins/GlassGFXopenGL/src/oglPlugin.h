#include "GlassEngine/plugin.h"
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

#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include "GlassEngine/GlassEngine.h"
#include "texture.h"
class OpenGLShader : public Shader {
private:
    Logger logger = Logger("GlassGFX.OpenGL.Plugin.OpenGLShader", "Log.txt");
public:
    GLASS_PLUGIN_API void Compile(std::string fragmentShaderPath, std::string vertexShaderPath) override;
    GLASS_PLUGIN_API void Bind() override;
    GLASS_PLUGIN_API void Unbind() override;
    void checkCompileErrors(GLuint shader, std::string type);
};
class OpenGLRenderAPI : public GlassPlugin_GFX {
private:
    GLFWwindow* window;
    Logger logger = Logger("GlassGFX.OpenGL.Plugin", "Log.txt");
public:
    
    GLASS_PLUGIN_API bool onLoad() override;
    GLASS_PLUGIN_API void createRenderContext(WindowProperties* winProps) override;
    GLASS_PLUGIN_API void* GetNativeWindow() const {return window;}
    void GlfwErrorCB(int error, const char* description);
    GLASS_PLUGIN_API void Update() override;
    GLASS_PLUGIN_API void BeginScene(Cameras::Camera* mCamera) override;
    GLASS_PLUGIN_API bool shouldWindowClose() override;
    GLASS_PLUGIN_API void VsyncCallback() override {
        glfwSwapInterval(winData.vsync);
    }
    GLASS_PLUGIN_API Shader* CreateShader();
    GLASS_PLUGIN_API VertexArray* CreateVAO();
    GLASS_PLUGIN_API texture::Texture* CreateTexture(std::string path);
    GLASS_PLUGIN_API void DrawVertexArray(VertexArray* vertArray, Shader* objShader, texture::Texture* m_texture = nullptr) override;
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
    GLASS_PLUGIN_API OpenGLTexture(std::string name);
    GLASS_PLUGIN_API void Bind();
};

