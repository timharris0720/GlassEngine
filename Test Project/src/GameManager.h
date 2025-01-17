#include "GlassEngine/GlassEngine.h"


class GameManager : public GameComponent {
public:
    GameManager() : GameComponent("GameManager"){}

    void Start() override {
        GameObject* testChild = new GameObject("testChild", parent);
        testChild->AddGameComponent<Components::Sprite>("Assets/testImage.jpg");
        parent->CreateChild("ChildTest2");
        for(int i = 0; i < parent->children.size(); i++){
            logger.InfoLog("Child Index: %i   Child Name: %s", i, parent->children[i]->name.c_str());
        }
    }   
};
