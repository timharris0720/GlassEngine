// OpenGLRenderAPI.h
#include "GlassEngine/plugin.h"

class OpenGLRenderAPI : public GlassGFXPlugin {
public:
    void initialize() override {
        // OpenGL initialization code
        std::cout << "Hello World" << std::endl;
    }

    void render() override {
        // OpenGL rendering code
    }

    void cleanup() override {
        // OpenGL cleanup code
    }

    void setTexture(const std::string& texturePath) override {
        // Load and bind OpenGL texture
    }

    void setShader(const std::string& shaderPath) override {
        // Load OpenGL shader
    }
};

// Plugin Registration
extern "C" GlassGFXPlugin* create() {
    return new OpenGLRenderAPI();
}