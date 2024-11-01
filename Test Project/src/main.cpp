#include "GlassEngine/core.h"
int main() {
    Core::App::Application app;
    std::cout << "HIII" << std::endl;
    
    app.loadPlugin("GlassGFX.openGL", Plugin::GFX_PLUGIN);
    
    
    while(true){

    }
    return 0;
}