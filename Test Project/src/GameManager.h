#include "GlassEngine/GlassEngine.h"

class testChildC : public GoCS::GameComponent {
public:
    testChildC() :  GoCS::GameComponent("testChild") {}
    void Start() override {
        logger.InfoLog("Hello World");
    }
};


class GameManager : public GoCS::GameComponent {
public:
    GameManager() : GoCS::GameComponent("Hello World"){}

    void Start() override {
        GoCS::GameObject* testChild = new GoCS::GameObject("testChild", parent);
        testChild->AddGameComponent<testChildC>("testChild");
        parent->CreateChild("ChildTest2");
        for(int i = 0; i < parent->children.size(); i++){
            logger.InfoLog("Child Index: %i   Child Name: %s", i, parent->children[i]->name.c_str());
        }
    }   
};
