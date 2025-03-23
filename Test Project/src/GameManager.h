#include "GlassEngine/GlassEngine.h"


class GameManager : public GameComponent {
public:
    GameManager() : GameComponent("GameManager"){}
    GameObject* testChild;
    GameObject* testChild2;
    int frameNumber;
    void Start() override {
        testChild = new GameObject("testChild", parentObject);
        testChild2 = new GameObject("testChild2", parentObject);
        testChild->AddComponent<Components::Sprite>("Assets/Textures/Brick100/Bricks100_1K-JPG_Color.jpg", texture::REPEAT);
        testChild2->AddComponent<Components::Sprite>("Assets/Textures/Brick100/Bricks100_1K-JPG_NormalGL.jpg", texture::REPEAT);
        testChild2->transform->Scale = glm::vec3(0.1,0.1,0);

        testChild2->transform->Position = glm::vec3(2.0f, 2.0f, -5.0f);
    }  
    void Update() override {
        frameNumber++;
        testChild->transform->Rotation.x = 10 * sin((frameNumber/10)/123);
        testChild->transform->Rotation.z = 10 * sin((frameNumber/10)/123);
        testChild->transform->Rotation.y = 10 * sin((frameNumber/10)/123);
        
    }
};
