#pragma once
#include <string>

class Shader {
private:
    std::string VertShader;
    std::string FragShader;

public:
    virtual Shader* Create(std::string fragmentShaderPath, std::string vertexShaderPath);
    virtual ~Shader() {};
    virtual void Bind();
    virtual void Unbind();
    Shader() = default;
};


