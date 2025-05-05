#include "CameraController.h"
void CameraController::Update() {
    if(Input::GetKeyDown(KeyCode::LeftArrow)){
        parentObject->transform->Position.x -= 0.01;
        logger.InfoLog("%f %f %f", parentObject->transform->Position.x, parentObject->transform->Position.y, parentObject->transform->Position.z);
    }
    if(Input::GetKeyDown(KeyCode::RightArrow)){
        parentObject->transform->Position.x += 0.01;
        logger.InfoLog("%f %f %f", parentObject->transform->Position.x, parentObject->transform->Position.y, parentObject->transform->Position.z);
    }

    if(Input::GetKeyDown(KeyCode::UpArrow)){
        parentObject->transform->Position.z -= 0.01;
        logger.InfoLog("%f %f %f", parentObject->transform->Position.x, parentObject->transform->Position.y, parentObject->transform->Position.z);
    }
    if(Input::GetKeyDown(KeyCode::DownArrow)){
        parentObject->transform->Position.z += 0.01;
        logger.InfoLog("%f %f %f", parentObject->transform->Position.x, parentObject->transform->Position.y, parentObject->transform->Position.z);
    }
    if(Input::GetKeyDown(KeyCode::Enter)){
        double fps = 1.0 / this->getDeltaTime();

        logger.InfoLog("FPS: %f, Frame time: %f", fps, this->getDeltaTime());
    }
    
}

void CameraController::Start() {
    testChild = parentObject;
    parentObject->transform->Position.z = -3.0f;
    logger.InfoLog("%f", this->getDeltaTime());
}