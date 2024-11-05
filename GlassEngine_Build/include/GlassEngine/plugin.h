#include <iostream>
#include <string>
#include <any>

struct WindowProperties {
    std::string name;
    int width;
    int height;
    bool vsync;
    WindowProperties(std::string name = "Window",int width = 600, int height = 480, bool vsync = false) : name(name), width(width), height(height), vsync(vsync) {}
};




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
    WindowProperties winData;
    virtual void createRenderContext(WindowProperties winProps) = 0;
    virtual bool shouldWindowClose() { return true;}
    virtual int GetWidth() {return winData.width;};
    virtual int GetHeight() {return winData.height;};
    virtual void* GetNativeWindow() const = 0;
    virtual bool isVsyncEnabled() {return winData.vsync;};
    virtual void VsyncCallback() = 0;
    void toggleVsync() {winData.vsync = !winData.vsync; VsyncCallback();}
    void toggleVsync(bool choice){winData.vsync = choice; VsyncCallback();};
};
