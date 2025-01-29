#pragma once
#include <string>
#include <glm/glm.hpp>
class Shader {
public:
    unsigned int ShaderID;
    std::string VertShader;
    std::string FragShader;
    virtual void Compile(std::string fragmentShaderPath, std::string vertexShaderPath) {};
    virtual ~Shader() {};
    virtual void Bind() {};
    virtual void Unbind() {};
    virtual void setBool(const std::string& name, bool value) {};
    virtual void setInt(const std::string& name, int value) {};
    virtual void setFloat(const std::string& name, float value) {};
    virtual void setVec2(const std::string& name, const glm::vec2& value) {};
    virtual void setVec2(const std::string& name, float x, float y) {};
    virtual void setVec3(const std::string& name, const glm::vec3& value) {};
    virtual void setVec3(const std::string& name, float x, float y, float z) {};
    virtual void setVec4(const std::string& name, const glm::vec4& value) {};
    virtual void setVec4(const std::string& name, float x, float y, float z, float w) {};
    virtual void setMat2(const std::string& name, const glm::mat2& mat) {};
    virtual void setMat3(const std::string& name, const glm::mat3& mat) {};
    virtual void setMat4(const std::string& name, const glm::mat4& mat) {};
    Shader() = default;
};


