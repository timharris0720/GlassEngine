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
    bool onLoad() override {
        // OpenGL initialization code
        std::cout << "Hello World bwwawa" << std::endl;
        return true;
    }
};

// Plugin Registration
extern "C" OPENGL_PLUGIN_API GlassPlugin* create() {
    return new OpenGLRenderAPI();
}