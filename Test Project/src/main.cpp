#define GLASS_ENTRY_INCLUDE
#include "GlassEngine/GlassEngine.h"
#include "GameManager.h"

class TestProject : public Core::App::Application {
public:
    TestProject(Core::App::AppSpec specification, Core::App::RenderBackend RB, std::string customRenderbackend) : Core::App::Application(specification, RB, customRenderbackend) {
        getLogger().InfoLog("Application is running : %i", this->isRunning());
        //Core::Entity::GameObject* GO = new Core::Entity::GameObject("GameManager");
        //GO->AddComponent<GameManager_Componenet>();
        //PushGameObject(GO);

        GameObject* GO = new GameObject("GameManager");
        GO->AddGameComponent<GameManager>();
    }
};



Core::App::Application* CreateApplication(){
    Core::App::AppSpec appSpec;
    appSpec.name = "Application";
    appSpec.width = 600;
    appSpec.height = 480;
    appSpec.sceneType = App::SceneType::DIM_2;
    return new TestProject(appSpec, Core::App::RenderBackend::CUSTOM, "GlassGFX.openGL");
}

