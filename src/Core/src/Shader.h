#pragma once
#include <string>

class Shader {
public:
    unsigned int ShaderID;
    std::string VertShader;
    std::string FragShader;
    virtual void Compile(std::string fragmentShaderPath, std::string vertexShaderPath) {};
    virtual ~Shader() {};
    virtual void Bind() {};
    virtual void Unbind() {};

    Shader() = default;
};


