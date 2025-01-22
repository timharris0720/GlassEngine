#include "GlassEngine/GlassEngine.h"


class GameManager : public GameComponent {
public:
    GameManager() : GameComponent("GameManager"){}

    void Start() override {
        GameObject* testChild = new GameObject("testChild", parent);
        testChild->AddGameComponent<Components::Sprite>("Assets/testImage.jpg");
        Cameras
    }   
};
