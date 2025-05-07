#include "CameraController.h"
#include <glm/gtx/quaternion.hpp>

void CameraController::Update() {
    ProcessKeyboardInput();

    
    if(Input::GetKeyDown(KeyCode::Enter)){
        double fps = 1.0 / this->getDeltaTime();

        logger.InfoLog("FPS: %f, Frame time: %f", fps, this->getDeltaTime());
    }
    if(Input::GetKeyDown(KeyCode::Escape)){
        
        logger.InfoLog("Shutting down");
        this->CloseApplication();
        
        
    }
    
}
void CameraController::ProcessKeyboardInput(){
    // Handles key inputs
	if (Input::GetKeyDown(KeyCode::W))
	{
		parentObject->transform->Position += moveSpeed * parentObject->transform->Rotation;
        logger.InfoLog("POS: X: %f Y: %f Z: %f     ROT: X: %f Y: %f Z: %f ", parentObject->transform->Position.x,parentObject->transform->Position.y,parentObject->transform->Position.z,parentObject->transform->Rotation.z,parentObject->transform->Rotation.y,parentObject->transform->Rotation.z);

	}
	if (Input::GetKeyDown(KeyCode::A))
	{
		parentObject->transform->Position += moveSpeed * -glm::normalize(glm::cross(parentObject->transform->Rotation, camera->Up));
        logger.InfoLog("POS: X: %f Y: %f Z: %f     ROT: X: %f Y: %f Z: %f ", parentObject->transform->Position.x,parentObject->transform->Position.y,parentObject->transform->Position.z,parentObject->transform->Rotation.z,parentObject->transform->Rotation.y,parentObject->transform->Rotation.z);

	}
	if (Input::GetKeyDown(KeyCode::S))
	{
		parentObject->transform->Position += moveSpeed * -parentObject->transform->Rotation;
        logger.InfoLog("POS: X: %f Y: %f Z: %f     ROT: X: %f Y: %f Z: %f ", parentObject->transform->Position.x,parentObject->transform->Position.y,parentObject->transform->Position.z,parentObject->transform->Rotation.z,parentObject->transform->Rotation.y,parentObject->transform->Rotation.z);

	}
	if (Input::GetKeyDown(KeyCode::D))
	{
		parentObject->transform->Position += moveSpeed * glm::normalize(glm::cross(parentObject->transform->Rotation, camera->Up));
        logger.InfoLog("POS: X: %f Y: %f Z: %f     ROT: X: %f Y: %f Z: %f ", parentObject->transform->Position.x,parentObject->transform->Position.y,parentObject->transform->Position.z,parentObject->transform->Rotation.z,parentObject->transform->Rotation.y,parentObject->transform->Rotation.z);

	}
	if (Input::GetKeyDown(KeyCode::Q))
	{
		parentObject->transform->Position += moveSpeed * camera->Up  ;
        logger.InfoLog("POS: X: %f Y: %f Z: %f     ROT: X: %f Y: %f Z: %f ", parentObject->transform->Position.x,parentObject->transform->Position.y,parentObject->transform->Position.z,parentObject->transform->Rotation.z,parentObject->transform->Rotation.y,parentObject->transform->Rotation.z);

	}
	if (Input::GetKeyDown(KeyCode::E))
	{
		parentObject->transform->Position += moveSpeed * -camera->Up ;
        logger.InfoLog("POS: X: %f Y: %f Z: %f     ROT: X: %f Y: %f Z: %f ", parentObject->transform->Position.x,parentObject->transform->Position.y,parentObject->transform->Position.z,parentObject->transform->Rotation.z,parentObject->transform->Rotation.y,parentObject->transform->Rotation.z);

	}
}
void CameraController::Start() {
    testChild = parentObject->root->GetChild("testChild2");;
    camera = parentObject->GetComponent<Components::Camera>();
}