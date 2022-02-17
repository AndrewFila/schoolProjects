/********************************************************/
/* NAME: Andrew Fila                    User ID: amfila */
/* DUE DATE: 3-15-2021                                  */
/* PROGRAM ASSIGNMENT #3                                */
/* FILENAME: thread-main.cpp                            */
/* PROGRAM PURPOSE:                                     */
/*  sorts a given input array by even-odd sort          */
/********************************************************/

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "thread.h"


#define EVEN 0
#define ODD  1

/*****************************************************************************/
/* Function eoSort:                                                          */
/*  handles the sorting fucntion by calling the swap threads and then joining*/
/*  them for each iteration.                                                 */
/* Parameter usage:                                                          */
/*  int pass - either 0 or 1 signaling even or odd pass respectivly          */
/*  int x[]  - the input array to be sorted                                  */
/*  int n    - size of the input array                                       */
/* Functions called:                                                         */
/*  malloc to create a thread array                                          */
/*****************************************************************************/




bool eoSort(int pass, int x[], int n){
        SwapThread **running;
        running = (SwapThread **)malloc(sizeof(SwapThread) * n);
        bool swapped = false;
        for (int i = 1 + pass; i < n; i += 2){
            running[i] = new SwapThread(i - 1, i, x, &swapped);
            running[i]->Begin();
            running[i]->Join();
        }
        return swapped;
}

/*****************************************************************************/
/* Function main:                                                            */
/* handles the running of the entire program reading in the input file then  */
/* calling the eoSort function to sort the array                             */
/* Parameter usage:                                                          */
/*   argc and argv unused                                                    */
/* Functions called:                                                         */
/*   cin and cout for reading and printing, eoSort to sort the array, malloc */
/*   and free for memory allocation                                          */
/*****************************************************************************/


int main(int argc, char **argv){
        std::cout << "Concurrent Even-Odd Sort\n\n";
        int size;
        std::cin >> size; //read in size
        std::cout << "Number of input data = " << size << std::endl;
        int *X;
        X = (int *)malloc(sizeof(int) * size);
        int in;
        for (int i = 0; i < size; i++){
                if (i%20 == 0 && i != 0){
                        std::cout << std::endl;
                }
                std::cin >> in; //read in numbers 1 by 1
                X[i] = in;
                std::cout << std::setw(4) << X[i];
        }
        std::cout << std::endl << std::endl;


        bool swapped = true;
        int pass = EVEN;
        int j = 0;

        while (swapped){
            std::cout << "Iteration " << j << ":" << std::endl;
            swapped = eoSort(EVEN, X, size);
            swapped = eoSort(ODD, X, size);
            std::cout<<"Result after iteration "<< j << ":" <<std::endl;
            for (int i = 0; i < size; i++){
                    if (i%20 == 0 && i != 0){
                            std::cout << std::endl;
                    }
                    std::cout << std::setw(4) << X[i];
            }
            std::cout << std::endl;
            j++;
        }
        std::cout<<"Final result after iteration "<< j-1 << ":" <<std::endl;
        for (int i = 0; i < size; i++){
                if (i%20 == 0 && i != 0){
                        std::cout << std::endl;
                }
                std::cout << std::setw(4) << X[i];
        }
        std::cout << std::endl;
        free(X);
        Exit();
        return -1;
}
