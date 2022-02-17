/*****************************************************************************/
/* Name: Andrew Fila                                User ID: amfila          */
/* Due Date: 4/14/2021                                                       */
/* Program Assignment #5                                                     */
/* File Name: thread-main.cpp                                                */
/* Program Purpose:                                                          */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/
#include "thread.h"
#include <stdlib.h>


int main(int argc, char ** argv){
    //inital setup
    int elves = atoi(argv[1]);
    if (elves == 0){elves = 7;}
    int deers = atoi(argv[2]);
    if (deers == 0){deers = 9;}
    int toys  = atoi(argv[3]);
    if (toys  == 0){toys  = 5;}
    ElfThread *eThread[elves];

    for (int i = 0; i < elves; i++){
        eThread[i] = new ElfThread(i);
        eThread[i]->Begin();
    }
    ReindeerThread *rdThread[deers];
    for (int i = 0; i < deers; i++){
        rdThread[i] = new ReindeerThread(i, deers);
        rdThread[i]->Begin();
    }
    SantaThread *sThread = new SantaThread(elves, deers, toys);
    sThread->Begin();
    for (int i = 0; i < elves; i++){
        eThread[i]->Join();
    }
    for (int i = 0; i < deers; i++){
        rdThread[i]->Join();
    }
    sThread->Join();



}
