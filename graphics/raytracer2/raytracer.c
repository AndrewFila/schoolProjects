#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

struct ray {
    float pos[3];
    float dir[3];
};
struct sphere {
    float position[3];
    float radius;
};


bool rayIntersect(struct ray *r, struct sphere *s){
    s->position[0] = 2;
    s->position[1] = 2;
    s->position[2] = -16;
    s->radius = 5.3547;
    float t = 0;
    float tp = 0;
    float tn = 0;

    float dc = 0;
    float dd = 0;
    float cc = 0;


    for (int i = 0; i < 3; i++){
        dc += r->dir[i] * s->position[i];
        dd += r->dir[i] * r->dir[i];
        cc += s->position[i] * s->position[i];

    }


    tp = (-dc + sqrt(pow(dc,2) - dd * cc - pow(s->radius,2))) / dd;
    tn = (-dc - sqrt(pow(dc,2) - dd * cc - pow(s->radius,2))) / dd;
    
    if (tp < tn){
        t = tp;
    }else{
        t = tn;
    }



    if (t >= 0){
        return true;
    }

    return false;
}

void calcDirection(struct ray *r, int i, int j){
    float px = .00390625;
    if (i <= 255){
        i = i - 256;
    }
    else {
        i =  -i + 256;
    }
    if (j <= 255){
        j = 256 + j;
    }
    else {
        j = -j + 256;
    }
    float dx = i * px + (px/2);
    float dy = j * px + (px/2);
    float dz = -2;
    float length = sqrt((dx * dx) + (dy * dy) + (dz * dz));
    r->dir[0] = dx/length;
    r->dir[1] = dy/length;
    r->dir[2] = dz/length;
    r->pos[0] = 0;
    r->pos[1] = 0;
    r->pos[2] = 0;
}



int main() {
    const int HEIGHT = 512;
    const int WIDTH = 512; 
    unsigned char* image = malloc(WIDTH * HEIGHT * 3);

    struct ray newRay;
    struct sphere newSphere;

    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            calcDirection(&newRay,i,j);
            if((i == 0 && j == 511) ||(i == 511 && j == 0) || (i == 255 && j == 256) ){;
                printf("pixel: %d x %d\n",i,j);
                printf("RayPosition %f %f %f\n", newRay.pos[0], newRay.pos[1], newRay.pos[2]);
                printf("RayDirection %f %f %f\n", newRay.dir[0], newRay.dir[1], newRay.dir[2]);
            }
            if (rayIntersect(&newRay, &newSphere)){
                image[(i * 1536) + (j * 3) ] = 255; 
                image[(i * 1536) + (j * 3) + 1 ] = 255; 
                image[(i * 1536) + (j * 3) + 2] = 255; 
            }
            else {
                image[(i * 1536) + (j * 3) ] = 128; 
                image[(i * 1536) + (j * 3) + 1 ] = 0; 
                image[(i * 1536) + (j * 3) + 2] = 0; 
            }
        }
    }

    stbi_write_png("sphere.png",WIDTH, HEIGHT, 3, image, WIDTH*3);
    free(image);
}

