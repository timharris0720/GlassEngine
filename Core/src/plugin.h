#include <iostream>
#include <string>


class GlassPlugin {
    public:
    virtual ~GlassPlugin() {}
    virtual void initialize() = 0;
    virtual void render() = 0;
    virtual void cleanup() = 0;
    
    virtual void setTexture(const std::string& texturePath) = 0;
    virtual void setShader(const std::string& shaderPath) = 0;

};
