#pragma once
#include "VertexArray.h"
#include "Shader.h"
#include "texture.h"
#include "GoCS.h"
struct RenderCommand {
    VertexArray* va;
    Shader* shader;
    Components::Transform* transform;
    texture::Texture* renderTexture;
};