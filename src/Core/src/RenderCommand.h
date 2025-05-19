#pragma once
#include "VertexArray.h"
#include "Shader.h"
#include "texture.h"
#include "GoCS.h"

enum RenderType {
    INDEXED = 0,
    INSTANCED,
} ;

enum RenderMode {
    TRIANGLES = 0,
    TRIANGLES_STRIP,
    WIREFRAME,
    RENDER_POINTS
} ;
struct RenderCommand {
    VertexArray* va;
    Shader* shader;
    Components::Transform* transform;
    texture::Texture* renderTexture;
    RenderType type;
    RenderMode mode;
};