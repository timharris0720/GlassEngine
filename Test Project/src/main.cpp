#include "GlassEngine/core.h"
int main() {
    Core::App::Application app;
    if(app.loadPlugin("GlassGFX.openGL.dll", Plugin::GFX_PLUGIN) != true){
        std::cout << "Failed to load plugin" << std::endl;
    }
    else  {
        std::cout << "Plugin loaded succesfully" << std::endl;
    }
    std::cout << "Hello World";
    return 0;
}