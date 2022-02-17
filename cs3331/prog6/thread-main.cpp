/*****************************************************************************/
/* Name: Andrew Fila                                User ID: amfila          */
/* Due Date: 4/25/2021                                                       */
/* Program Assignment #6                                                     */
/* File Name: thread-main.cpp                                                */
/* Program Purpose:                                                          */
/*  Creates a sieve to find prime numbers                                    */
/*  -- main program reads arguments, starts the master and P2 threads        */
/*                                                                           */
/*****************************************************************************/
#include "thread.h"
#include <stdlib.h>
#include <stdio.h>

PrimeThread *firstPrimeThread;
int main(int argc, char ** argv){
    int n = 30;
    if (argc == 2){
        n = atoi(argv[1]);                      //read in args
    }

    MasterThread *master;

    master = new MasterThread(n);               //make master
    firstPrimeThread = new PrimeThread(0, 1, 2);//make prime thread

    master->Begin();                            //begin master
    firstPrimeThread->Begin();                  //begin prime thread

    master->Join();                             //master wait for other threads

    Exit();
}
