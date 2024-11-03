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

class OpenGLRenderAPI : public GlassPlugin_GFX {
    private:
public:
    GLFWwindow* window;
    bool onLoad() override {
        // OpenGL initialization code
        if(!glewInit()){
            return false;
        }
        std::cout << "WOOO GLEW INITS" << std::endl;
        return true;
    }
    
    void createApplication(std::string name, int width,int height) override{
        window = glfwCreateWindow(width,height,name.c_str(),NULL,NULL);
    }

    std::any execute(const std::string& command, const std::any& data = {}) override {
        if (command == "getShaderInfo") {
            return "asdasd";
        }
        return {}; // Return empty for unsupported commands
    }
};

// Plugin Registration
extern "C" OPENGL_PLUGIN_API GlassPlugin* create() {
    return new OpenGLRenderAPI();
}