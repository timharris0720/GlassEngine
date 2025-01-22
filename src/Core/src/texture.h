#pragma once
#include <iostream>
namespace texture {
    class Texture {
        public:
        int width, height, channels;
        Texture() = default;
        Texture(std::string name);
        virtual void Bind(){};
    };
}