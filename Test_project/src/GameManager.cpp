#include "GameManager.h"


void GameManager::Start(){
    testChild = new GameObject("testChild"); 
    testChild2 = new GameObject("testChild2");
    //testChild3d = new GameObject("testChild2");
    testChild->AddComponent<Components::Sprite>("Assets/Textures/Brick100/Bricks100_1K-JPG_Color.jpg", texture::REPEAT);
    //testChild2->AddComponent<Components::Sprite>("Assets/Textures/Brick100/Bricks100_1K-JPG_NormalGL.jpg", texture::REPEAT);
    testChild2->transform->Scale = glm::vec3(0.1,0.1,0);
    testChild2->transform->Position = glm::vec3(1, 3, -5);
    testChild2->AddComponent<Components::Mesh>(Defaults::CUBE);
    //testChild2->objectShader->AddShaderCommand(glm::vec3(1,0,0.3), "vertexColorIN");
    Components::Camera* camera = parent->root->GetChild("Main Camera")->GetComponent<Components::Camera>();
    camera->FarClip = 1000000.0f;
    camera->NearClip = 0.0001f;
    
    //testChild->objectShader->AddShaderCommand(glm::vec3(1,0,0), "testColor");
}
void GameManager::Update() {
    
    //testChild->transform->Position.x += playerSpeed;
    testChild2->transform->Rotation.y += playerSpeed * getDeltaTime();
  
}