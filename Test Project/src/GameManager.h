#include "GlassEngine/GlassEngine.h"
#include "CameraController.h"

class GameManager : public GameComponent {
public:
    GameManager() : GameComponent("GameManager"){}
    GameObject* testChild;
    GameObject* testChild2;
    float playerSpeed = 10;
    void Start();
    void Update();
};
