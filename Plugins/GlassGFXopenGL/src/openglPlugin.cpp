// OpenGLRenderAPI.h
#include "GlassEngine/plugin.h"
#ifdef _WIN32
#ifdef OPENGL_PLUGIN
#define OPENGL_PLUGIN_API __declspec(dllexport)
#else
#define OPENGL_PLUGIN_API __declspec(dllimport)
#endif
#else
#define OPENGL_PLUGIN_API
#endif

class OpenGLRenderAPI : public GlassPlugin {
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
extern "C" OPENGL_PLUGIN_API GlassPlugin* create() {
    return new OpenGLRenderAPI();
}