#include <iostream>
#include <string>


class GlassPlugin {
    public:
    virtual ~GlassPlugin() {};
    virtual bool onLoad() = 0;
    virtual void onInit() {};
    virtual void Update() {};
    virtual void cleanup() {};
    
    virtual void setTexture(const std::string& texturePath) {};
    virtual void setShader(const std::string& shaderPath) {};

};
