#include <iostream>
#include <vector>
#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
namespace ImageUtils {
    class Image {
        public:
        std::string imageType;
        int width, height, channels;
        unsigned char* imageData;
        Image() = default;
        Image(std::string path) {
            imageData = stbi_load(path.c_str(), &width,&height, &channels, 0);
        }
        void freeTheImage(){
            stbi_image_free(imageData);
        }
    };
}