#include <iostream>
#include <string>
#include <any>
class GlassPlugin {
    public:
    virtual ~GlassPlugin() {};
    virtual bool onLoad() = 0;
    virtual void onInit() {};
    virtual void Update() {};
    virtual void cleanup() {};
    virtual std::any getVariable(std::string varName) {return {};};
    virtual std::any execute(const std::string& command, const std::any& data = {}) {
        return {}; // Default empty return for unsupported commands
    }
    virtual void setTexture(const std::string& texturePath) {};
    virtual void setShader(const std::string& shaderPath) {};
};

class GlassPlugin_GFX : public GlassPlugin {
    public:
    virtual void createApplication(std::string name, int width,int height) {};
};

