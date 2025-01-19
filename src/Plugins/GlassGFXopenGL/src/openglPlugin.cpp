#include "oglPlugin.h"
#include "glassSTL.h"
void OpenGLRenderAPI::GlfwErrorCB(int error, const char* description){
    logger.ErrorLog("GLFW ERROR: %s", description);
}
bool OpenGLRenderAPI::onLoad() {
    
    if(!glfwInit()){
        logger.ErrorLog("GLFW Failed To INIT");
        return false;
    }
    // OpenGL initialization code
    //glfwSetErrorCallback(GlfwErrorCB);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    return true;
}
bool OpenGLRenderAPI::shouldWindowClose(){
    return !glfwWindowShouldClose(window);
}
void OpenGLRenderAPI::createRenderContext(WindowProperties* winProps){
    logger.InfoLog("WinProps");
    logger.InfoLog("---------------------------");
    logger.InfoLog("WinProps Height: %i", winProps->height);
    logger.InfoLog("WinProps Width : %i", winProps->width);
    logger.InfoLog("WinProps Name  : %s", winProps->name.c_str());
    logger.InfoLog("WinProps Vysnc : %i", winProps->vsync);
    
    winData = *winProps;
    window = glfwCreateWindow(winData.width,winData.height, winData.name.c_str(), NULL,NULL);
    logger.InfoLog("GLEW      version: %s", glewGetString(GLEW_VERSION));
    logger.InfoLog("GL Shader version: %s", glGetString(GL_SHADING_LANGUAGE_VERSION));
    logger.InfoLog("GL        version: %s", glGetString(GL_VERSION));
    glfwMakeContextCurrent(window);

    GLenum glI = glewInit();
    if( glI != GLEW_OK){
        logger.ErrorLog("GLEW Failed To INIT, %u code", glI);
        exit(EXIT_FAILURE);
    }

    
    glfwSwapInterval(winData.vsync);

}

void OpenGLRenderAPI::Update() {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,1);
    glfwSwapBuffers(window);
}

Shader* OpenGLRenderAPI::CreateShader() {
    return new OpenGLShader();
}
void OpenGLShader::checkCompileErrors(GLuint shader, std::string type) {
    GLint success;
    GLchar infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            logger.ErrorLog("Shader Compilation Failed: ShaderType: %s, reason: %s", type.c_str(), infoLog);
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            logger.ErrorLog("Shader PROGRAM_LINKING_ERROR Failed: reason: %s", type.c_str(), infoLog);
        }
    }
}
void OpenGLShader::Compile(std::string fragmentShaderPath, std::string vertexShaderPath){
    logger.InfoLog("Fragment shader path: %s ", fragmentShaderPath.c_str());
    logger.InfoLog("Vertex shader path: %s ", vertexShaderPath.c_str());
    VertShader = Utils::readFile(vertexShaderPath);
    FragShader = Utils::readFile(fragmentShaderPath);
    const char* vShaderCode = VertShader.c_str();
    const char* fShaderCode = FragShader.c_str();
    // 2. compile shaders
    unsigned int vertex, fragment;

    // vertex shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");

    // fragment Shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);

    checkCompileErrors(fragment, "FRAGMENT");
    // shader Program
    ShaderID = glCreateProgram();
    glAttachShader(ShaderID, vertex);
    glAttachShader(ShaderID, fragment);
    glLinkProgram(ShaderID);

    checkCompileErrors(ShaderID, "PROGRAM");
    // delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertex);
    glDeleteShader(fragment);
} 
    
    
void OpenGLShader::Bind(){
    
}
void OpenGLShader::Unbind(){
    
}

// Plugin Registration
extern "C" GLASS_PLUGIN_API GlassPlugin* create() {
    return new OpenGLRenderAPI();
}