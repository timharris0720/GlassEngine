#include "GlassEngine/GlassEngine.h"




class GameManager : public GoCS::GameComponent {
public:
    GameManager() : GoCS::GameComponent("Hello World"){
    
    }

    void Start() override {
        this->parent->logger.InfoLog("hello world");
    }
};
