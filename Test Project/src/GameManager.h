#include "GlassEngine/GlassEngine.h"


class GameManager : public GameComponent {
public:
    GameManager() : GameComponent("GameManager"){}
    GameObject* testChild;
    GameObject* testChild2;
    int frameNumber;
    void Start() override {
        testChild = new GameObject("testChild", parent);
        testChild2 = new GameObject("testChild2", parent);
        testChild->AddGameComponent<Components::Sprite>("Assets/Textures/Brick100/Bricks100_1K-JPG_Color.jpg", texture::REPEAT);
        testChild2->AddGameComponent<Components::Sprite>("Assets/Textures/Brick100/Bricks100_1K-JPG_NormalGL.jpg", texture::REPEAT);
        //testChild2->transform->Scale = glm::vec3(0.1,0.1,0);

        testChild2->transform->Position = glm::vec3(2,1,0);
    }  
    void Update() override {
        frameNumber++;
        testChild->transform->Rotation.x = 10 * sin((frameNumber/10)/123);
        testChild->transform->Rotation.z = 10 * sin((frameNumber/10)/123);
        testChild->transform->Rotation.y = 10 * sin((frameNumber/10)/123);
        
    }
};
