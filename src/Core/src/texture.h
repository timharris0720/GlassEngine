#pragma once
#include <iostream>
namespace texture {
    enum ImageWrapping {
        REPEAT = 0,
        MIRRORED_REPEAT,
        CLAMP_TO_EDGE,
        CLAMP_TO_BORDER
    };
    class Texture {
        public:
        int width, height, channels;
        Texture() = default;
        Texture(std::string name, ImageWrapping WrapType);
        virtual void Bind(){};
    };
}