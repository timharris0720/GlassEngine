#include "GameManager.h"


void GameManager::Start(){
    GRID = new GameObject("Grid",gameObject);
    square1 = new GameObject("square1"); 
    square2 = new GameObject("square2");
    cube = new GameObject("cube");

    Light = new GameObject("Light1");
    Light->AddComponent<Components::Light>(LightType::SUNLIGHT, glm::vec3(1,0,0));
    //testChild3d = new GameObject("testChild2");
    
    square1->AddComponent<Components::Sprite>("Assets/Textures/Brick100/Bricks100_1K-JPG_Color.jpg", texture::REPEAT, Primitives::SQUARE);
    square2->AddComponent<Components::Sprite>("Assets/Textures/Brick100/Bricks100_1K-JPG_NormalGL.jpg", texture::REPEAT,Primitives::SQUARE);
    GRID->AddComponent<Components::Sprite>("Assets/Textures/Prototype/Orange/texture_08.png", texture::REPEAT,Primitives::CIRCLE, 64, 5.0f);

    cube->AddComponent<Components::Mesh>(Primitives::CUBE);
    

    //testChild2->transform->Scale = glm::vec3(0.1,0.1,0);
    GRID->transform->Scale = glm::vec3(1,1,1);
    GRID->transform->Rotation = glm::vec3(90,0,0);


    square2->transform->Position = glm::vec3(1,5, -3);
    //testChild2->AddComponent<Components::Mesh>(Defaults::CUBE);
    //testChild2->objectShader->AddShaderCommand(glm::vec3(1,0,0.3), "vertexColorIN");
    Components::Camera* camera = parent->root->GetChild("Main Camera")->GetComponent<Components::Camera>();
    camera->FarClip = 1000000.0f;
    camera->NearClip = 0.1f;
}
void GameManager::Update() {
    //testChild->transform->Position.x += playerSpeed;
  
}