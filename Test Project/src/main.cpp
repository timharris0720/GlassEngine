#include "GlassEngine/GlassEngine.h"
Logger logger("MainApp","log.txt");
int main() {

    

    App::AppSpec appSpec;
    appSpec.name = "Application";
    appSpec.width = 600;
    appSpec.height = 480;
    App::Application app(appSpec, Core::App::OPENGL);
    
    std::cout << "HIII" << std::endl;
    
    logger.InfoLog("Current Version: %i . %i", CORE_VERSION_MAJOR,CORE_VERSION_MINOR);

    
    while(true){

    }
    return 0;
}