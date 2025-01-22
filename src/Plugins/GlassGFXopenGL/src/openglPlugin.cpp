#include "oglPlugin.h"
#include "glassSTL.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#pragma region RenderAPI
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
void OpenGLRenderAPI::BeginScene(Cameras::Camera* mCamera){
    sceneMainCamera = mCamera;
}
void OpenGLRenderAPI::Update() {
   
    
}
Shader* OpenGLRenderAPI::CreateShader() {
    return new OpenGLShader();
}
VertexArray* OpenGLRenderAPI::CreateVAO(){
    return new OGLVertexArray();
}
texture::Texture* OpenGLRenderAPI::CreateTexture(std::string path, texture::ImageWrapping wrapType) {
    return new OpenGLTexture(path, wrapType);
}
void OpenGLRenderAPI::DrawVertexArray(VertexArray* vertArray, Shader* objShader,texture::Texture* m_texture){
    
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    //glClearColor(0,0,0,1);
    objShader->Bind();
    if(m_texture != nullptr)
        m_texture->Bind();
    vertArray->Bind();
    
    glDrawElements(GL_TRIANGLES, vertArray->IndiciesCount, GL_UNSIGNED_INT, 0);
    objShader->Unbind();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glfwSwapBuffers(window);
    glfwPollEvents();
}
#pragma endregion
#pragma region OpenGLShader
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
    glUseProgram(ShaderID);
}
void OpenGLShader::Unbind(){
    glUseProgram(0);
}
#pragma endregion
#pragma region OpenGLVertexArray
void OGLVertexArray::Create(std::vector<Vertex>* vertices,std::vector<unsigned int>* indices){
    IndiciesCount = indices->size();
    // Generate VBO

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices->size() * sizeof(Vertex), vertices->data(), GL_STATIC_DRAW);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, IndiciesCount * sizeof(unsigned int), indices->data(), GL_STATIC_DRAW);

    glGenVertexArrays(1 , &VAO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, vertices));
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);
    //glGenVertexArrays(1, &VAO);
    //glGenBuffers(1, &VBO);
    //glGenBuffers(1, &EBO);

    //// Bind VAO
    //glBindVertexArray(VAO);

    //// Bind and upload data to VBO
    //glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //glBufferData(GL_ARRAY_BUFFER, vertices->size(), vertices->data(), GL_STATIC_DRAW);

    //// Bind and upload data to EBO
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices->size() * sizeof(unsigned int), indices->data(), GL_STATIC_DRAW);

    //// Specify the layout of the vertex data
    //// Position attribute
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,vertices));
    //glEnableVertexAttribArray(0);

    //// Color attribute
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    //glEnableVertexAttribArray(1);

    //// UV attribute
    //glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, UV));
    //glEnableVertexAttribArray(2);

    //// Unbind VAO (optional)
    //glBindVertexArray(0); // Unbind
    //logger.InfoLog("Created VBO EBO VAO");
}
void OGLVertexArray::Bind(){
    glBindVertexArray(VAO);

}
void OGLVertexArray::Unbind(){
    
}
#pragma endregion
#pragma region OpenGLTexture
OpenGLTexture::OpenGLTexture(std::string name, texture::ImageWrapping WrapType){
    stbi_set_flip_vertically_on_load(true);  
    unsigned char* imageData = stbi_load(name.c_str(), &width, &height, &channels, 0);
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    switch (WrapType)
    {
    case texture::ImageWrapping::REPEAT:
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        break;
    case texture::ImageWrapping::MIRRORED_REPEAT:
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);	
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        break;
    case texture::ImageWrapping::CLAMP_TO_EDGE:
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        break;
    case texture::ImageWrapping::CLAMP_TO_BORDER:
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);	
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
        break;
    
    default:
        break;
    } 
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the texture
    if (imageData)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        logger.InfoLog("Failed to load texture");
    }
    stbi_image_free(imageData);
}
void OpenGLTexture::Bind(){
    glBindTexture(GL_TEXTURE_2D, textureID);
}
#pragma endregion

// Plugin Registration
extern "C" GLASS_PLUGIN_API GlassPlugin* create() {
    return new OpenGLRenderAPI();
}