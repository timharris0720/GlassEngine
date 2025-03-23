#include "oglPlugin.h"
#include "glassSTL.h"
#define __STDC_LINMIT_MACROS
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
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    return true;
}
bool OpenGLRenderAPI::shouldWindowClose(){
    return !glfwWindowShouldClose(window);
}
void OpenGLRenderAPI::createRenderContext(WindowProperties* winProps){    winData = *winProps;
    window = glfwCreateWindow(winData.width,winData.height, winData.name.c_str(), NULL,NULL);
    logger.DebugLog("GLEW      version: %s", glewGetString(GLEW_VERSION));
    logger.DebugLog("GL Shader version: %s", glGetString(GL_SHADING_LANGUAGE_VERSION));
    logger.DebugLog("GL        version: %s", glGetString(GL_VERSION));
    glfwMakeContextCurrent(window);

    GLenum glI = glewInit();
    if( glI != GLEW_OK){
        logger.ErrorLog("GLEW Failed To INIT, %u code", glI);
        exit(EXIT_FAILURE);
    }
    glfwSwapInterval(winData.vsync);

}
void OpenGLRenderAPI::BeginScene(GoCS::GameObject* mCamera){
    sceneMainCamera = mCamera;
    sceneCameraComponent = mCamera->GetComponent<Components::Camera>();

    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glClearColor(0,0,0,1);
}
void OpenGLRenderAPI::Update(){}
void OpenGLRenderAPI::EndScene() {
   int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    
    sceneCameraComponent->setProjection(display_w,display_h);
    glViewport(0, 0, display_w, display_h);
    glfwSwapBuffers(window);
    glfwPollEvents();
    
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
void OpenGLRenderAPI::DrawVertexArray(VertexArray* vertArray, Shader* objShader,texture::Texture* m_texture, Components::Transform* objectTransform){
    
    /*
    //glm::mat4 model = glm::mat4(1.0f); // Start with an identity matrix
    //logger.InfoLog("Position: %f %f %f", objectTransform->Position.x, objectTransform->Position.y, objectTransform->Position.z);
    //logger.InfoLog("Rotation: %f %f %f", objectTransform->Rotation.x, objectTransform->Rotation.y, objectTransform->Rotation.z);
    //logger.InfoLog("Scale   : %f %f %f", objectTransform->Scale.x, objectTransform->Scale.y, objectTransform->Scale.z);
    //model = glm::translate(model, objectTransform->Position);
    //// Apply rotation (convert degrees to radians)
    //model = glm::rotate(model, glm::radians(objectTransform->Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)); // Rotate around X-axis
    //model = glm::rotate(model, glm::radians(objectTransform->Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotate around Y-axis
    //model = glm::rotate(model, glm::radians(objectTransform->Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f)); // Rotate around Z-axis

    // Apply scaling
    //model = glm::scale(model, objectTransform->Scale);
    */
    //glm::mat4 model = glm::mat4(1.0f); // Identity matrix
    ////model = glm::translate(model, objectTransform->Position);  // <-- Apply translation first
    //model = glm::rotate(model, glm::radians(objectTransform->Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    //model = glm::rotate(model, glm::radians(objectTransform->Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    //model = glm::rotate(model, glm::radians(objectTransform->Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    //model = glm::scale(model, objectTransform->Scale);  // Scaling last

    


    if(m_texture != nullptr)
        m_texture->Bind();
    objShader->Bind();
    vertArray->Bind();
    
    //glm::mat4 mvp =  sceneMainCamera->getProjectionMatrix() * sceneMainCamera->getViewMatrix() * model;
    //objShader->setMat4("mvp", mvp);
    //objShader->setMat4("projection", sceneMainCamera->getProjectionMatrix());
    //objShader->setMat4("view", sceneMainCamera->getViewMatrix());
    //objShader->setMat4("model", objectTransform->applyTransform());
    //objShader->setMat4("model", model);
    
    if(sceneCameraComponent){
    
        //glm::mat4 mvp = sceneCameraComponent->getProjectionMatrix() * sceneCameraComponent->getViewMatrix() * model;
        glm::mat4 mvp =  sceneCameraComponent->getProjectionMatrix() * sceneCameraComponent->getViewMatrix() * objectTransform->applyTransform();
        objShader->setMat4("mvp", mvp);

    }
    objShader->setMat4("model", objectTransform->applyTransform());
    glDrawElements(GL_TRIANGLES, vertArray->IndiciesCount, GL_UNSIGNED_INT, 0);
    objShader->Unbind();

    
    
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
    logger.DebugLog("Fragment shader path: %s ", fragmentShaderPath.c_str());
    logger.DebugLog("Vertex shader path: %s ", vertexShaderPath.c_str());
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
void OpenGLShader::setBool(const std::string& name, bool value) {
    glUniform1i(glGetUniformLocation(ShaderID, name.c_str()), (int)value);
}
void OpenGLShader::setInt(const std::string& name, int value) {
    glUniform1i(glGetUniformLocation(ShaderID, name.c_str()), value);
}
void OpenGLShader::setFloat(const std::string& name, float value) {
    glUniform1f(glGetUniformLocation(ShaderID, name.c_str()), value);
}
void OpenGLShader::setVec2(const std::string& name, const glm::vec2& value) {
    glUniform2fv(glGetUniformLocation(ShaderID, name.c_str()), 1, &value[0]);
}
void OpenGLShader::setVec2(const std::string& name, float x, float y) {
    glUniform2f(glGetUniformLocation(ShaderID, name.c_str()), x, y);
}
void OpenGLShader::setVec3(const std::string& name, const glm::vec3& value) {
    glUniform3fv(glGetUniformLocation(ShaderID, name.c_str()), 1, &value[0]);
}
void OpenGLShader::setVec3(const std::string& name, float x, float y, float z) {
    glUniform3f(glGetUniformLocation(ShaderID, name.c_str()), x, y, z);
}
void OpenGLShader::setVec4(const std::string& name, const glm::vec4& value) {
    glUniform4fv(glGetUniformLocation(ShaderID, name.c_str()), 1, &value[0]);
}
void OpenGLShader::setVec4(const std::string& name, float x, float y, float z, float w) {
    glUniform4f(glGetUniformLocation(ShaderID, name.c_str()), x, y, z, w);
}
void OpenGLShader::setMat2(const std::string& name, const glm::mat2& mat) {
    glUniformMatrix2fv(glGetUniformLocation(ShaderID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
void OpenGLShader::setMat3(const std::string& name, const glm::mat3& mat) {
    glUniformMatrix3fv(glGetUniformLocation(ShaderID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
void OpenGLShader::setMat4(const std::string& name, const glm::mat4& mat) {
    glUniformMatrix4fv(glGetUniformLocation(ShaderID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
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
    logger.DebugLog("Name: %s :    Channels: %i",name.c_str(), channels);
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    // set the texture wrapping/filtering options (on the currently bound texture object)
    GLint wrapMode;
    switch (WrapType) {
        case texture::ImageWrapping::REPEAT: wrapMode = GL_REPEAT; break;
        case texture::ImageWrapping::MIRRORED_REPEAT: wrapMode = GL_MIRRORED_REPEAT; break;
        case texture::ImageWrapping::CLAMP_TO_EDGE: wrapMode = GL_CLAMP_TO_EDGE; break;
        case texture::ImageWrapping::CLAMP_TO_BORDER: wrapMode = GL_CLAMP_TO_BORDER; break;
        default: wrapMode = GL_REPEAT; break;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the texture
    if (imageData)
    {
        GLenum format = (channels == 1) ? GL_RED : (channels == 3) ? GL_RGB :  (channels == 4) ? GL_RGBA : GL_RGB;
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, imageData);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        logger.ErrorLog("Failed to load texture");
        logger.ErrorLog("Reasion: STB Image Error: %s", stbi_failure_reason()); 

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