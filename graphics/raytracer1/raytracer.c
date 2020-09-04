#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <stdio.h>

void* raytracer(int width, int height){
    unsigned int size = width * height * 3;
    unsigned char* image = malloc(width * height * 3);
    for (int i = 0; i < size; i++){
        if (i < 3){
            image[i] = 255;
        }else{
            image[i] = 0;
        }
    }
    stbi_write_png("ray1", width, height, 3, image, width*3);
    free(image);
}


int main(){
    raytracer(512, 512);
    return 0;
}
