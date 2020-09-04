#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <stdio.h>

void* checkerboard(int width, int height){
    unsigned int size = width * height * 3;
    unsigned char* image = malloc(width * height * 3);

    unsigned char row = 0;
    unsigned int check = 0;
    for (int i = 0; i < size; i++){
        
        if (row%2 == 0 ){
            if (check%2 == 1){
                if (i%3 == 2){
                    image[i] = 255;
                }
                else {
                    image[i] = 0;
                }        
            }
            else {
                if (i%3 == 0){
                    image[i] = 255;
                }
                else {
                    image[i] = 0;
                }        
            }
        }
        else {
            if (check%2 == 0){
                if (i%3 == 2){
                    image[i] = 255;
                }
                else {
                    image[i] = 0;
                }        
            }
            else {
                if (i%3 == 0){
                    image[i] = 255;
                }
                else {
                    image[i] = 0;
                }        
            }
        }
        if (i%(width * 3 * height / 8) == (width * 3 * height / 8) - 1 ){
            row++; 
        }
        if (i%(width * 3 / 8) == (width * 3 / 8) - 1){
            check++;
        }
    }



    stbi_write_png("checkerboard.png", width, height, 3, image, width*3);
    free(image);
}


void* gradient(int width, int height){
    unsigned char size = width * height * 3;
    unsigned char* image = malloc(width * height * 3);
    for (int i = 0; i < size; i++){

    }

    stbi_write_png("gradient.png", width, height, 3, image, width*3);
    free(image);
}


int main(){
    checkerboard(512, 512);
    return 0;
}
