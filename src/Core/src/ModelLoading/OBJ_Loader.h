#pragma once
#include <string>
#include "../Logger.h"
#include "../GoCS.h"
#include "ModelMesh.h"
namespace OBJ {
    class OBJLoader {
        public:
        OBJLoader() = default;
        ModelMesh ReadOBJ_File(std::string path);

    };
}