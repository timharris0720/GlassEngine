#include "GlassEngine/GlassEngine.h"
#include "GlassEngine/InputSystem.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h> 

class CameraController : public GameComponent {
private:

    float moveSpeed = 1;
    float rotSpeed = 90;
    float mouseSensitivity = 0.01;
    //
    float lastMouseX = 0.0f;
    float lastMouseY = 0.0f;
    bool firstMouse = true;
    glm::vec3 movementInput;
    glm::vec3 prevPosition;
    glm::vec3 prevRotation;
    bool isDirty = true;
public:
    CameraController() : GameComponent("CameraController"){}
    GameObject* testChild = nullptr;

    Components::Camera* camera;

    void Start();
    void Update();
};