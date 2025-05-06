#include "CameraController.h"
#include <glm/gtx/quaternion.hpp>

void CameraController::Update() {
    ProcessKeyboardInput();

    if (glm::length(movementInput) > 0.0f) {
        glm::vec3 forward = glm::rotate(glm::quat(parentObject->transform->Rotation.x,parentObject->transform->Rotation.y,parentObject->transform->Rotation.z, 0), glm::vec3(0, 0, -1));
        glm::vec3 right   = glm::rotate(glm::quat(parentObject->transform->Rotation.x,parentObject->transform->Rotation.y,parentObject->transform->Rotation.z, 0), glm::vec3(1, 0,  0));
        glm::vec3 up      = glm::vec3(0, 1, 0);

        glm::vec3 movement = (movementInput.x * right +
                              movementInput.y * up +
                              movementInput.z * forward);

        parentObject->transform->Position += glm::normalize(movement) * moveSpeed *  (float)this->getDeltaTime();
    }

    if(Input::GetKeyDown(KeyCode::Enter)){
        double fps = 1.0 / this->getDeltaTime();

        logger.InfoLog("FPS: %f, Frame time: %f", fps, this->getDeltaTime());
    }
    if(Input::GetKeyDown(KeyCode::Escape)){
        
        logger.InfoLog("Shutting down");
        this->CloseApplication();
        
        
    }
    
}

void CameraController::Start() {
    testChild = parentObject->root->GetChild("testChild2");;
    camera = parentObject->GetComponent<Components::Camera>();
}