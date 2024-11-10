#include "GlassEngine/GlassEngine.h"
int main() {
    App::AppSpec appSpec;
    appSpec.name = "Application";
    appSpec.width = 600;
    appSpec.height = 480;
    App::Application app(appSpec, Core::App::OPENGL);
    
    std::cout << "HIII" << std::endl;
    
    

    
    while(true){

    }
    return 0;
}