#pragma once
#include <iostream>
#include <vector>
#include "VertexArray.h"
namespace Defaults {
    VertexArray* SquareSprite();
    VertexArray* Cube();

    enum PrimativeType{
        CUBE = 0,
        SPHERE,
        CAPSULE
    };
}