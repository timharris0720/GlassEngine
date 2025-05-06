#define GLASS_ENTRY_INCLUDE
#include "GlassEngine/GlassEngine.h"
#include "GameManager.h"

class TestProject : public Core::App::Application {
public:
    TestProject(Core::App::AppSpec specification, Core::App::RenderBackend RB, std::string customRenderbackend) : Core::App::Application(specification, RB, customRenderbackend) {
        GetLogger()->InfoLog("Application is running : %i", this->isRunning());
        //Core::Entity::GameObject* GO = new Core::Entity::GameObject("GameManager");
        //GO->AddComponent<GameManager_Componenet>();
        //PushGameObject(GO);

        GameObject* GO = new GameObject("GameManager");
        GO->AddComponent<GameManager>();

        GetRoot()->GetChild("Main Camera")->AddComponent<CameraController>();
    }
};



Core::App::Application* CreateApplication(int argc, char** argv){
    Core::App::AppSpec appSpec;
    appSpec.name = "Application";
    appSpec.width = 600;
    appSpec.height = 480;
    appSpec.sceneType = App::SceneType::DIM_3;
    appSpec.argc = argc;
    appSpec.argv = argv;
    return new TestProject(appSpec, Core::App::RenderBackend::OPENGL, "");
}

