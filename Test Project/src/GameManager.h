#include "GlassEngine/GlassEngine.h"




class GameManager : public GoCS::GameComponent {
public:
    GameManager() : GoCS::GameComponent("Hello World"){
    
    }

    void Start() override {
        logger.InfoLog("hello world");
    }
    void Update() override {
        logger.InfoLog("hewo");
    }
};
