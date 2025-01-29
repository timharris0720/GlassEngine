#include "GlassEngine/GlassEngine.h"


class GameManager : public GameComponent {
public:
    GameManager() : GameComponent("GameManager"){}
    int frameNumber = 0;
    GameObject* testChild;
    GameObject* testChild2;
    void Start() override {
        testChild = new GameObject("testChild", parent);
        testChild2 = new GameObject("testChild3", parent);
        testChild->AddGameComponent<Components::Sprite>("Assets/Textures/Brick100/Bricks100_1K-JPG_Color.jpg", texture::ImageWrapping::REPEAT);
        testChild->transform->Position = glm::vec3(2,3,-10);
        testChild->transform->Scale = glm::vec3(2,2,0);
        testChild->transform->Rotation = glm::vec3(12,90,10);
       //`
        testChild2->AddGameComponent<Components::Sprite>("Assets/Textures/Brick100/Bricks100_1K-JPG_NormalDX.jpg", texture::ImageWrapping::REPEAT);
        //testChild2->transform->Scale = glm::vec3(0.1,0.1,0);
    }  
    void Update() override {
        testChild2->transform->Rotation.z = 10 * sin(frameNumber/123);
        frameNumber++;
    }
};
