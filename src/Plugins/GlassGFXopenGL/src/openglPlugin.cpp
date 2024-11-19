#include "oglPlugin.h"

bool OpenGLRenderAPI::onLoad() {
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

void OpenGLRenderAPI::createRenderContext(WindowProperties winProps){
    winData = winProps;
    window = glfwCreateWindow(winData.width,winData.height, winData.name.c_str(), NULL,NULL);
    glfwSwapInterval(0);

}

void OpenGLRenderAPI::Update() {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,1);
    glfwSwapBuffers(window);
}

Shader* OpenGLRenderAPI::CreateShader(std::string fragmentShaderPath, std::string vertexShaderPath){
    logger.InfoLog("Fragment shader path: %s ", fragmentShaderPath.c_str());
    logger.InfoLog("Vertex shader path: %s ", vertexShaderPath.c_str());
    OpenGLShader shader;
    return &shader;
}



// Plugin Registration
extern "C" OPENGL_PLUGIN_API GlassPlugin* create() {
    return new OpenGLRenderAPI();
}