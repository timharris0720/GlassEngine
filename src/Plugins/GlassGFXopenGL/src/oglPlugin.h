#include "GlassEngine/plugin.h"
#ifdef _WIN32
#ifdef OPENGL_PLUGIN
#define OPENGL_PLUGIN_API __declspec(dllexport)
#else
#define OPENGL_PLUGIN_API __declspec(dllimport)
#endif
#else
#define OPENGL_PLUGIN_API
#endif

#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include "GlassEngine/GlassEngine.h"

class OpenGLShader : public Shader {
public:
    OPENGL_PLUGIN_API Shader* Create(std::string fragmentShaderPath, std::string vertexShaderPath) override;
};


class OpenGLRenderAPI : public GlassPlugin_GFX {
private:
    GLFWwindow* window;
    Logger logger = Logger("GlassGFX.OpenGL.Plugin", "Log.txt");
public:

    OPENGL_PLUGIN_API bool onLoad() override;
    OPENGL_PLUGIN_API void createRenderContext(WindowProperties winProps) override;
    OPENGL_PLUGIN_API void* GetNativeWindow() const {return window;}
    
    OPENGL_PLUGIN_API void Update() override;
    OPENGL_PLUGIN_API bool shouldWindowClose() override{
        return glfwWindowShouldClose(window);
    }
    OPENGL_PLUGIN_API void VsyncCallback() override {
        glfwSwapInterval(winData.vsync);
    }
    OPENGL_PLUGIN_API void Clear();
    OPENGL_PLUGIN_API void BeginScene(std::shared_ptr<Cameras::Camera> camera);
    OPENGL_PLUGIN_API void DrawVertexArray();
    OPENGL_PLUGIN_API Shader* CreateShader(std::string fragmentShaderPath, std::string vertexShaderPath);
};