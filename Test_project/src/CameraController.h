#include "GlassEngine/GlassEngine.h"
#include "GlassEngine/InputSystem.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h> 

class CameraController : public GameComponent {
private:

float moveSpeed;
float mouseSensitivity;

float yaw;
float pitch;

glm::vec3 movementInput;
public:
    CameraController() : GameComponent("CameraController"){}
    GameObject* testChild = nullptr;

    Components::Camera* camera;

    void Start();
    void Update();
    
    void ProcessKeyboardInput();
};