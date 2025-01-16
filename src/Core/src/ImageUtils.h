#pragma once
#ifdef _WIN32
#ifdef GLASS_ENGINE_EXPORTS_CORE
#define GLASS_ENGINE_API __declspec(dllexport)
#else
#define GLASS_ENGINE_API __declspec(dllimport)
#endif
#else
#define GLASS_ENGINE_API
#endif

#include <iostream>
#include <vector>
#include <string>


namespace ImageUtils {
    class Image {
        public:
        std::string imageType;
        int width, height, channels;
        unsigned char* imageData;
        GLASS_ENGINE_API Image() = default;
        GLASS_ENGINE_API Image(std::string path);
        void freeTheImage();
    };
}