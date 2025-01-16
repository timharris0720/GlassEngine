#include "GlassEngine/GlassEngine.h"

class testChildC : public GameComponent {
public:
    testChildC() :  GameComponent("testChild") {}
    void Start() override {
        logger.InfoLog("Hello World");
    }
};


class GameManager : public GameComponent {
public:
    GameManager() : GameComponent("Hello World"){}

    void Start() override {
        GameObject* testChild = new GameObject("testChild", parent);
        testChild->AddGameComponent<Components::Sprite>("testChild", "Assets/testImage.jpg");
        parent->CreateChild("ChildTest2");
        for(int i = 0; i < parent->children.size(); i++){
            logger.InfoLog("Child Index: %i   Child Name: %s", i, parent->children[i]->name.c_str());
        }
    }   
};
