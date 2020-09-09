#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <stdio.h>

void* checkerboard(int width, int height){
    unsigned int size = width * height * 3;                         //set size and create array
    unsigned char* image = malloc(width * height * 3);
    
    unsigned char row = 0;                                          //row is used for keeping track of the rows
    unsigned int check = 0;                                         //check is used for the columns
    


    for (int i = 0; i < size; i++){
        
        if (row%2 == 0 ){                                           //check if the rows are even 
            if (check%2 == 1){                                      //check if the columns are even
                if (i%3 == 2){ //i mod 3 = 2 -- blue                // the following apply the red or blue color to the square
                    image[i] = 255;
                }
                else {
                    image[i] = 0;
                }        
            }
            else {
                if (i%3 == 0){ //i mod 3 = 0 -- red
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
        if (i%(width * 3 * height / 8) == (width * 3 * height / 8) - 1 ){       // at the end of a row the variable row should update
            row++; 
        }
        if (i%(width * 3 / 8) == (width * 3 / 8) - 1){                          //at the end of a column we want to have a checkerboard pattern so we add 1 to make the first check even or odd (the opposite of what the row above it was)
            /* ex. 
               | 0 | 1 | 2 | 3| +1
               | 5 | 6 | 7 | 8| +1
               | 10|    ...   |
               */

            check++;
        }
    }



    stbi_write_png("checkerboard.png", width, height, 3, image, width*3);
    free(image);
}


void* gradient(int width, int height){
    unsigned int size = width * height * 3;
    unsigned char* image = malloc(width * height * 3);
    unsigned int row = 0;
    unsigned int column = 0;

    for (int i = 0; i < size; i++){
        if (i % 6 == 0 && i != 0) {                 //i mod 6 to get every other pixel
            column++;
        }
        if (i % (1536 * 2) == 0 && i != 0){         //rows are the (width * 3) * 2 for a height of 2
            row++;
            column = 0;
        }
        if (i%3 == 0){                  //red
            image[i] = column;                          //set as columns (columns are 2 wide)
        }
        else if (i%3 == 1){             //green
            image[i] = row;                             //set as rows (rows are two pixels tall in this method)
        }
        else {                          //blue
            image[i] = 128;

        }
    }
    
    stbi_write_png("gradient.png", width, height, 3, image, width*3);
    free(image);
}


int main(){
    checkerboard(512,512);
    gradient(512,512);
    return 0;
}
