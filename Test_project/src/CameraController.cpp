#include "CameraController.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtc/constants.hpp>
#include "GlassEngine/Mathematics.h"
void CameraController::Update() {
    
    float speed = moveSpeed * getDeltaTime();
    float rotateSpeed = rotSpeed * getDeltaTime();

    float pitch = glm::radians(parentObject->transform->Rotation.x);
    float yaw   = glm::radians(parentObject->transform->Rotation.y);

    glm::vec3 front;
    front.x = cos(pitch) * cos(yaw);
    front.y = sin(pitch);
    front.z = cos(pitch) * sin(yaw);
    front = glm::normalize(front);

    glm::vec3 right = glm::normalize(glm::cross(front, glm::vec3(0,1, 0)));
    glm::vec3 up    = glm::normalize(glm::cross(right, front));

    if (Input::GetKeyDown(KeyCode::LeftArrow)) {
        parentObject->transform->Rotation.y -= rotateSpeed;
    }
    if (Input::GetKeyDown(KeyCode::RightArrow)) {
        parentObject->transform->Rotation.y += rotateSpeed;
    }
    if (Input::GetKeyDown(KeyCode::UpArrow)) {
        parentObject->transform->Rotation.x += rotateSpeed;
    }
    if (Input::GetKeyDown(KeyCode::DownArrow)) {
        parentObject->transform->Rotation.x -= rotateSpeed;
    }
    
    if (Input::GetKeyDown(KeyCode::W)) {
        parentObject->transform->Position += front * speed;
    }
    if (Input::GetKeyDown(KeyCode::S)) {
        parentObject->transform->Position -= front * speed;
    }
    if (Input::GetKeyDown(KeyCode::A)) {
        parentObject->transform->Position -= right * speed;
    }
    if (Input::GetKeyDown(KeyCode::D)) {
        parentObject->transform->Position += right * speed;
    }
    if (Input::GetKeyDown(KeyCode::Q)) {
        parentObject->transform->Position -= up * speed;
    }
    if (Input::GetKeyDown(KeyCode::E)) {
        parentObject->transform->Position += up * speed;
    }
    
    #pragma region Mouse_looking
    
    int mouseX, mouseY;
    Input::GetMousePosition(mouseX, mouseY);
    //Input::LockMouseToCenter(true);
    if (firstMouse) {
        lastMouseX = mouseX;
        lastMouseY = mouseY;
        firstMouse = false;
    }
    float xOffset = mouseX - lastMouseX;
    float yOffset = lastMouseY - mouseY; // reversed since y-coordinates go down
    //logger.InfoLog("mouse X: %i mouse Y: %i", xOffset,yOffset);

    lastMouseX = mouseX;
    lastMouseY = mouseY;
    
    xOffset *= mouseSensitivity;
    yOffset *= mouseSensitivity;

    parentObject->transform->Rotation.y += xOffset; // yaw
    parentObject->transform->Rotation.x += yOffset; // pitch
    #pragma endregion Mouse_looking
    parentObject->transform->Rotation.x = Maths::Clamp(parentObject->transform->Rotation.x, 89.0f, -89.0f);


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

    parentObject->transform->Position = glm::vec3(0,0,3);
    parentObject->transform->Rotation = glm::vec3(0,-90,0);
}