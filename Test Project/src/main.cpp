#include "GlassEngine/GlassEngine.h"
Logger logger("MainApp","log.txt");
int main() {

    

    App::AppSpec appSpec;
    appSpec.name = "Application";
    appSpec.width = 600;
    appSpec.height = 480;
    App::Application app(appSpec, Core::App::OPENGL);   
    logger.InfoLog("Current Version: %s", Core::VERSION);
    logger.InfoLog("Current API: %i", app.GetAPI());
   
    while(app.isRunning()){
        app.pluginLoader.pluginUpdate();
    }
    return 0;
}