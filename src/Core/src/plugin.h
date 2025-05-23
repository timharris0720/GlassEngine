#pragma once
#include <iostream>
#include <string>
#include <any>
#include <vector>
#include "Shader.h"
#include "VertexArray.h"
#include "texture.h"
#include "GoCS.h"
#include "RenderCommand.h"
//#include "camera.h"
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
    //virtual void setTexture(const std::string& texturePath) {};
    //virtual void setShader(const std::string& shaderPath) {};
};

class GlassPlugin_GFX : public GlassPlugin {
private:
    double previousFT;
public:
    WindowProperties winData;
    GoCS::GameObject* sceneMainCamera;
    std::vector<RenderCommand> RenderQueue;
    virtual void createRenderContext(WindowProperties* winProps) = 0;
    virtual bool shouldWindowClose() = 0;
    virtual void Shutdown() = 0;
    virtual void Cleanup() {};
    virtual int GetWidth() {return winData.width;};
    virtual int GetHeight() {return winData.height;};
    virtual void* GetNativeWindow() const = 0;
    virtual bool isVsyncEnabled() {return winData.vsync;};
    virtual void VsyncCallback() = 0;
    virtual void BeginScene(GoCS::GameObject* mCamera) = 0;
    virtual void EndScene() = 0;
    virtual double GetTime() = 0;
    virtual Shader* CreateShader() = 0;
    virtual VertexArray* CreateVAO() = 0;
    virtual texture::Texture* CreateTexture(std::string path,texture::ImageWrapping wrapType) = 0 ;
    virtual void AddToRenderQueue(VertexArray* vertArray, Shader* objShader,texture::Texture* m_texture, Components::Transform* objectTransform, RenderType type) = 0;
    virtual void DrawVertexArray(RenderCommand* renderCMD) = 0;
    virtual void Render() = 0;
    //virtual void DrawVertexArray(Renderer::VertexArray* vertArray, unsigned int indicesCount) = 0 ;
    //virtual void CreateShader(std::string fragmentShaderPath, std::string vertexShaderPath) {};
    void toggleVsync() {winData.vsync = !winData.vsync; VsyncCallback();}
    void toggleVsync(bool choice){winData.vsync = choice; VsyncCallback();};
};
 