#include "GlassEngine/GlassEngine.h"


class GameManager : public GameComponent {
public:
    GameManager() : GameComponent("GameManager"){}

    void Start() override {
        
        GameObject* testChild = new GameObject("testChild", parent);
        testChild->AddGameComponent<Components::Sprite>("Assets/Textures/Brick100/Bricks100_1K-JPG_Color.jpg", texture::ImageWrapping::REPEAT);

        GameObject* testChild3 = new GameObject("testChild3", parent);
        testChild3->AddGameComponent<Components::Sprite>("Assets/Textures/Brick100/Bricks100_1K-JPG_NormalDX.jpg", texture::ImageWrapping::REPEAT);
    }   
};
