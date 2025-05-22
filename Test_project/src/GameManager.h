#include "GlassEngine/GlassEngine.h"
#include "CameraController.h"

class GameManager : public GameComponent {
public:
    GameManager() : GameComponent("GameManager"){}
    GameObject* square1;
    GameObject* square2;
    GameObject* cube;
    GameObject* Light;
    GameObject* GRID;
    float playerSpeed = 10;
    void Start();
    void Update();
};
