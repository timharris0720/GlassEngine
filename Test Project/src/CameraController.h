#include "GlassEngine/GlassEngine.h"
#include "GlassEngine/InputSystem.h"

class CameraController : public GameComponent {
public:
    CameraController() : GameComponent("CameraController"){}

    void Start() override {
        
    }
    void Update() override {
        if(Input::GetKeyDown(KeyCode::Escape)){
            logger.InfoLog("asd");
        }
    }
};