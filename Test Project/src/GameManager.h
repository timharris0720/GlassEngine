#include "GlassEngine/GlassEngine.h"


class GameManager : public GameComponent {
public:
    GameManager() : GameComponent("GameManager"){}
    GameObject* testChild;
    void Start() override {
        
        //testChild2->transform->Scale = glm::vec3(0.1,0.1,0);
    }  
    void Update() override {
        //testChild2->transform->Rotation.z = 10 * sin(frameNumber/123);
        
    }
};
