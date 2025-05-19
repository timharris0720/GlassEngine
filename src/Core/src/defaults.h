#pragma once
#include <iostream>
#include <vector>
#include "VertexArray.h"
namespace Defaults {
    VertexArray* SquareSprite(glm::vec2 scalingWidth = glm::vec2(1));
    VertexArray* Circle(float radius = 0.5f, int segments = 64,glm::vec2 scalingWidth = glm::vec2(1));
    VertexArray* Cube();

    enum PrimativeType{
        CUBE = 0,
        SPHERE,
        CAPSULE
    };
}