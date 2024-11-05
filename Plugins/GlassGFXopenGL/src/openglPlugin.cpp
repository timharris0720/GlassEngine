// OpenGLRenderAPI.h
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

    bool onLoad() override {
        logger.ToggleFileLogging();
        if(!glfwInit()){
            logger.ErrorLog("GLFW Failed To INIT");
            return false;
        }
        
        logger.InfoLog("Beasdasdasd");
        // OpenGL initialization code
        if(!glewInit()){
            logger.ErrorLog("GLEW Failed To INIT");
            return false;
        }
        
        return true;
    }
    
    void createRenderContext(WindowProperties winProps) override{
        winData = winProps;
        window = glfwCreateWindow(winData.width,winData.height, winData.name.c_str(), NULL,NULL);
    }
    void* GetNativeWindow() const {return window;}
    
    void Update() override {
        glfwPollEvents();
        
    }
    bool shouldWindowClose() override{
        return glfwWindowShouldClose(window);
    }
    void VsyncCallback() override {
        glfwSwapInterval(winData.vsync);
    }
};

// Plugin Registration
extern "C" OPENGL_PLUGIN_API GlassPlugin* create() {
    return new OpenGLRenderAPI();
}