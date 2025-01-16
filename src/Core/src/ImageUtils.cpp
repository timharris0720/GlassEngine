#define STB_IMAGE_IMPLEMENTATION
#include "ImageUtils.h"
#include <iostream>
#include <vector>
#include <string>
#include "stb_image.h"
ImageUtils::Image::Image(std::string path){
    imageData = stbi_load(path.c_str(), &width,&height, &channels, 0);
    
}
void ImageUtils::Image::freeTheImage(){
    stbi_image_free(imageData);
}