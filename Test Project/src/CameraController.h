#include "GlassEngine/GlassEngine.h"
#include "GlassEngine/InputSystem.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

class CameraController : public GameComponent {
public:
    CameraController() : GameComponent("CameraController"){}
    GameObject* testChild = nullptr;
    void Start() override {
        testChild = parentObject->root->GetChild("testChild");
    }
    void Update() override {
        if(Input::GetKeyDown(KeyCode::A)){
            testChild->transform->Rotation.x -= 0.01;
            logger.InfoLog("%f", testChild->transform->Rotation.x);
        }
        if(Input::GetKeyDown(KeyCode::D)){
            parentObject->transform->Rotation.x += 0.01;
            logger.InfoLog("%f", testChild->transform->Rotation.x);
        }
    }
};