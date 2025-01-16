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

class OpenGLShader : public Shader {
private:
    Logger logger = Logger("GlassGFX.OpenGL.Plugin.OpenGLShader", "Log.txt");
public:
    GLASS_PLUGIN_API void Create(std::string fragmentShaderPath, std::string vertexShaderPath) override;
};


class OpenGLRenderAPI : public GlassPlugin_GFX {
private:
    GLFWwindow* window;
    Logger logger = Logger("GlassGFX.OpenGL.Plugin", "Log.txt");
public:

    GLASS_PLUGIN_API bool onLoad() override;
    GLASS_PLUGIN_API void createRenderContext(WindowProperties* winProps) override;
    GLASS_PLUGIN_API void* GetNativeWindow() const {return window;}
    
    GLASS_PLUGIN_API void Update() override;
    GLASS_PLUGIN_API bool shouldWindowClose() override;
    GLASS_PLUGIN_API void VsyncCallback() override {
        glfwSwapInterval(winData.vsync);
    }
    GLASS_PLUGIN_API void Clear();
    GLASS_PLUGIN_API void BeginScene(std::shared_ptr<Cameras::Camera> camera);
    GLASS_PLUGIN_API void DrawVertexArray();
    GLASS_PLUGIN_API Shader* CreateShader(std::string fragmentShaderPath, std::string vertexShaderPath);
};