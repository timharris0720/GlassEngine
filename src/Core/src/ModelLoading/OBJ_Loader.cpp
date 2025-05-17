#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <regex>
#include <glm/glm.hpp>

#include "OBJ_Loader.h"
#include "../core.h"

namespace OBJ {
    ModelMesh OBJLoader::ReadOBJ_File(std::string path){
        
        
        
        VertexArray* v = Core::App::Application::GetRenderer().CreateVertexArray(&vertices,&indices);
    }
}