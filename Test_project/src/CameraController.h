#include "GlassEngine/GlassEngine.h"
#include "GlassEngine/InputSystem.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

class CameraController : public GameComponent {
public:
    CameraController() : GameComponent("CameraController"){}
    GameObject* testChild = nullptr;
    int pmx, pmy;

    void Start();
    void Update();
    
};