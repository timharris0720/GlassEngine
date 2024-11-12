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
#include "GlassEngine/Logger.h"

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
};