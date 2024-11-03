#include "GlassEngine/core.h"
int main() {
    Core::App::AppSpec appSpec;
    appSpec.name = "Application";
    appSpec.width = 600;
    appSpec.height = 480;
    Core::App::Application app(appSpec, Core::App::OPENGL);
    
    std::cout << "HIII" << std::endl;
    
    

    
    while(true){

    }
    return 0;
}