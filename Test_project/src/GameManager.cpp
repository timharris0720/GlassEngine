#include "GameManager.h"


void GameManager::Start(){
    GRID = new GameObject("Grid",gameObject);
    testChild = new GameObject("testChild"); 
    testChild2 = new GameObject("testChild2");
    //testChild3d = new GameObject("testChild2");
    
    testChild->AddComponent<Components::Sprite>("Assets/Textures/Brick100/Bricks100_1K-JPG_Color.jpg", texture::REPEAT);
    testChild2->AddComponent<Components::Sprite>("Assets/Textures/Brick100/Bricks100_1K-JPG_NormalGL.jpg", texture::REPEAT);
    GRID->AddComponent<Components::Sprite>("Assets/Textures/Prototype/Orange/texture_08.png", texture::REPEAT);


    //testChild2->transform->Scale = glm::vec3(0.1,0.1,0);
    GRID->transform->Scale = glm::vec3(100,100,1);
    GRID->transform->Rotation = glm::vec3(90,0,0);


    testChild2->transform->Position = glm::vec3(1,5, -3);
    //testChild2->AddComponent<Components::Mesh>(Defaults::CUBE);
    //testChild2->objectShader->AddShaderCommand(glm::vec3(1,0,0.3), "vertexColorIN");
    Components::Camera* camera = parent->root->GetChild("Main Camera")->GetComponent<Components::Camera>();
    camera->FarClip = 1000000.0f;
    camera->NearClip = 0.0001f;
}
void GameManager::Update() {
    //testChild->transform->Position.x += playerSpeed;
    testChild2->transform->Rotation.y += 90 * getDeltaTime();
  
}