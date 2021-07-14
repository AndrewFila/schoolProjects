/* ----------------------------------------------------------- */
/* NAME : Andrew Fila                        User ID: 27817835 */
/* DUE DATE : 02/10/2021                                       */
/* PROGRAM ASSIGNMENT # 1                                      */
/* FILE NAME : prog1.c                                         */
/* PROGRAM PURPOSE :                                           */
/*    This is a program to create 4 coccurent procceses        */
/*    which calculate the fibonacci number, buffon's           */
/*    needle, the area of an elipse, and a pinball game.       */
/* ----------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <errno.h>
#include <math.h>
/** #1 -- Fibonacci
 *  Calculates Fibonacci number of given n recursivly
 **/

long fib(int n){
    if (n == 0){
        return 0;
    }
    if ( n == 1){
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}



/** #2 Buffon's Needle
 *
 **/
float buffon(int r){
    //declorations
    int L, G;
    L = 1; G = 1;
    float pi = acos(-1.0);
    int t = 0;
    srand(time(NULL));
    for (int i = 0; i < r; i++){
        //random numbers
        float d = (float) rand()/RAND_MAX;
        float a = (float) rand()/RAND_MAX * 2 * pi;

        float ans = d + L * sin(a);
        if (ans < 0 || ans > G){
            t++;
        }
    }
    return (float) t/ (float) r;
}

/** #3 Area of an Elipse
 *  calculates the area of an elipse given the semi-major and semi-minor axixes.
 **/
float ellipse(float major, float minor, int s){
    float x, y;
    srand(time(NULL));
    int t = 0;
    for (int i = 0; i < s; i++){
        x = (float) rand()/RAND_MAX;
        y = (float) rand()/RAND_MAX;
        x = x * major;
        y = y * minor;
        float u = (pow(x, 2) / pow(major, 2) + pow(y, 2) / pow(minor, 2));
        if (u <= 1.0){
            t++;
        }
    }
    printf("         Total Hits %d\n", t);
    float area = (((float) t/ (float) s) * major * minor) * 4.0;
    return area;
}

/** #4 Pinball
 *  plays a pinball game and outputs the percentage of hits, number of hits for each bin
 **/
void pinball(int bins, int balls){
    long * hits = malloc(sizeof(long) * bins);
    float * hitPercent = malloc(sizeof(float) * bins);
    srand(time(NULL));
    float random;
    for (int j = 0; j < balls; j++){ //for each ball
        int count = 0;
        for (int i = 0; i < bins - 1; i++){ //for each level in the game = bins - 1
            random = (float) rand()/RAND_MAX;
            if (random >= .5){
                count++;
            }
        }
        hits[count]++;
    }
    for (int i = 0; i < bins; i++){ // caclulates hit percentage
        hitPercent[i] = (float) hits[i]/balls;
    }
    for (int i = 0; i < bins; i++){ //printing section
        int max = 50;
        printf("%3d-(%7ld)-(%5.2f)|", i+1, hits[i], hitPercent[i]);
        max = max * hitPercent[i];
        for (int j = 0; j < max; j++){
            printf("*");
        }
        printf("\n");
    }
}




int main(int argc, char** argv){
    float pi = acos(-1.0);
    int wstatus[4];
    //safety check
    if (argc != 8){
        perror("ERROR: Correct format -> ./prog1 <n> <r> <a> <b> <s> <x> <y>");
        exit(EXIT_FAILURE);
    }
    //declarations==========
    int n, r, a, b, s, x, y;
    int pid0, pid1, pid2, pid3;
    n = atoi(argv[1]);
    r = atoi(argv[2]);
    a = atoi(argv[3]); b = atoi(argv[4]); s = atoi(argv[5]);
    x = atoi(argv[6]); y = atoi(argv[7]);
    //======================
    printf("Main Process Started\nFubonacci Input                 = %d\nBuffon's Needle Iterations      = %d\nTotal random Nubmer Pairs       = %d\nSemi-Major Axis Lenght          = %d\nSemi-Minor Axis Length          = %d\nNumber of bins                  = %d\nNumber of Ball Droppings        = %d\n\n", n, r, s, a, b, x, y);

    pid0 = fork();                          //make first child
    if (pid0 == -1){
        perror("fork");
        exit(EXIT_FAILURE);
    }
    printf("   Fibonacci Process Created\n");
    if (pid0 == 0){                         //pid0 = 0 => child process 0 -- Fibonacci
        printf("   Fibonacci Process Started\n");
        dprintf(1,"   Input Number %d \n", n);
        long ans = fib(n);
        dprintf(1,"   Fibonacci Number f(%d) is %ld \n\n", n, ans);
        exit(EXIT_SUCCESS);

    }else{
        pid1 = fork();
        if (pid1 == -1){
            perror("fork");
            exit(EXIT_FAILURE);
        }
        printf("       Buffon's Needle Process Created\n");
        if (pid1 == 0){                    //pid1 = 0 => child process 1 -- Buffon's Needle
            printf("       Buffon's Needle Process Started\n");
            printf("       Input Number %d\n", r);
            float buf = buffon(r);
            printf("       Estimated Probability: %5f\n\n", buf);
            exit(EXIT_SUCCESS);


        }else{
            pid2 = fork();
            if (pid2 == -1 ){
                perror("fork");
                exit(EXIT_FAILURE);
            }
            printf("         Ellipse Area Process Created\n");
            if (pid2 == 0){                 //pid2 = 0 => child process 2 -- Ellipse
                printf("         Ellipse Area Process Started\n");
                printf("         Total random Number Paris %d\n",s);
                printf("         Semi-Major Axis Length %d\n", a);
                printf("         Semi-Minor Axis Length %d\n", b);
                float est, act;
                est = ellipse(a,b,s);
                act = (a * b) * pi;
                printf("         Estimated Area is %5f\n         Actual Area is %5f\n\n", est, act);
                exit(EXIT_SUCCESS);
            }else{
                pid3 = fork();
                if (pid3 == -1){
                    perror("fork()");
                    exit(EXIT_FAILURE);
                }
                if (pid3 == 0){             //pid3 = 0 => child process 3 -- Pinball
                    printf("Simple Pinball Process Started\n");
                    printf("number of bins %d\n", x);
                    printf("number of Ball Droppings %d\n", y);
                    pinball(x,y);
                    exit(EXIT_SUCCESS);
                }else{                      //parent process
                    int status = waitpid(pid0, &wstatus[0], 0);
                    if (status == -1){
                        perror("wait");
                        exit(EXIT_FAILURE);
                    }
                    printf("Fibonacci Process Exits\n");

                    status = waitpid(pid1, &wstatus[1], 0);
                    if (status == -1){
                        perror("wait");
                        exit(EXIT_FAILURE);
                    }
                    printf("Buffon's Needle Process Exits\n");

                    status = waitpid(pid2, &wstatus[2], 0);
                    if (status == -1){
                        perror("wait");
                        exit(EXIT_FAILURE);
                    }
                    printf("Ellipse Area Process Exits\n");

                    status = waitpid(pid3, &wstatus[3], 0);
                    if (status == -1){
                        perror("wait");
                        exit(EXIT_FAILURE);
                    }
                    printf("Simple Pinball Process Exits\n");


                    printf("Main Process Exits\n");
                    exit(EXIT_SUCCESS);
                }
            }
        }
    }


    return 0;
}
