#include "GlassEngine/entrypoint.h"
#include "GameManager.h"







class TestProject : public Core::App::Application {
public:
    TestProject(Core::App::AppSpec specification, Core::App::RenderBackend RB) : Core::App::Application(specification, RB) {
        getLogger().InfoLog("Application is running : %i", isRunning());
        Core::Object::GameObject GO =  Core::Object::GameObject("GameManager");
        GO.AddComponent<GameManager_Componenet>();
        PushGameObject(GO);
    }
};



Core::App::Application* CreateApplication(){
    Core::App::AppSpec appSpec;
    appSpec.name = "Application";
    appSpec.width = 600;
    appSpec.height = 480;
    return new TestProject(appSpec, Core::App::RenderBackend::OPENGL);
}

