/*****************************************************************************/
/* Name: Andrew Fila                                User ID: amfila          */
/* Due Date: 4/14/2021                                                       */
/* Program Assignment #5                                                     */
/* File Name: thread.cpp                                                     */
/* Program Purpose:                                                          */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/
#include "thread.h"
#include "ThreadClass.h"
#include <string.h>
#include <stdio.h>

#define FALSE 0
#define TRUE  1


static GroupMonitor mon;

//******************************************************************************
//****************************************************************
//****************************************************************
ElfThread::ElfThread(int id) : id(id) {}
void ElfThread::ThreadFunc(){
    Thread::ThreadFunc();
    printf("         Elf %d starts.\n", id);
    while(1){
        Delay();            // Make toys
        mon.AskQuestion(id);      // Encounter a problem
        Delay();            // Problem solved, take a rest
    }
}



//****************************************************************
//****************************************************************
//****************************************************************
ReindeerThread::ReindeerThread(int id, int total): id(id), total(total) {}
void ReindeerThread::ThreadFunc(){
    Thread::ThreadFunc();
    printf("    Reindeer %d starts.\n", id);
    while(1){
        Delay();            // Vacation
        mon.ReindeerBack(total, id);     // Report back to santa
        mon.WaitOthers(total, id);       // Wait for other reindeer
                            // Note: last reindeer wakes up santa
        mon.WaitSleigh(total);       // Wait for attaching sleigh
        mon.FlyOff(total);           // Fly off to deliver toys
                            // Santa will let go all reindeer
        Delay();            // Prepare for vacation
    }
}


//****************************************************************
//****************************************************************
//****************************************************************
SantaThread::SantaThread(int e, int r, int t): e(e), r(r), t(t){}
void SantaThread::ThreadFunc(){
    Thread::ThreadFunc();
    printf("Santa thread starts.\n");
    while(1){}
    //    mon.Sleep();            // Take a nap
    //                        // Wakened up by elves or last reindeer
    //                        // What is the reason?
    //                        // Note that toy delivering is more important
    //    //if (){          // Reindeer are all back
    //        // gather all reindeers
    //        // put on a sleigh
    //        // fly off
    //        Delay();        //Satan delivers toys
    //        // Release all reindeer for vacation
    //    //}
    //    //if (){          // elves have a question
    //        // let elves in
    //        Delay();        //solve their problem
    //        // Solve the problem and release elves
    //    //}
    //}
}


GroupMonitor::GroupMonitor() :
        question("Q"), retire("Ret"), allBack("Back"), rCount(0), eCount(0), groupSize(3), rWaiting(0), onSleigh(0) {}
// -----------------------------------------------------------
// // FUNCTION AskQuestion
// //     allows the elves to ask questions.
// // PARAMETER USAGE :
// //    id - id of the elf
// // FUNCTION CALLED :
// //    Wait, Signal, Printf
// // -----------------------------------------------------------
//elves
void GroupMonitor::AskQuestion(int id){
    Monitor::MonitorBegin();
    eCount += 1;
    printf("         Elf %d has a problem\n", id);
    if (eCount == groupSize){
        eCount -=1;
        printf("         Elves %d ask a question\n",id);
        question.Signal();

    } else {
        question.Wait();
        eCount -= 1;
        question.Signal();
    }
    printf("          Elf %d returns to work\n", id);
    Monitor::MonitorEnd();
}
//deer
// -----------------------------------------------------------
// // FUNCTION ReindeerBack
// //     tracks the returning raindeer and adds them to count
// // PARAMETER USAGE :
// //    id - id of the Reindeer, total - total number of deer
// // FUNCTION CALLED :
// //    Printf
// // -----------------------------------------------------------
void GroupMonitor::ReindeerBack(int total, int id){
    Monitor::MonitorBegin();
    rCount += 1;
    printf("    reindeer %d returns\n", id);
    Monitor::MonitorEnd();
}
// -----------------------------------------------------------
// // FUNCTION WaitOthers
// //     makes the reindeer wait while all other raindeer are returing
// // PARAMETER USAGE :
// //    id - id of the Reindeer, total - total number of deer
// // FUNCTION CALLED :
// //    Printf, Signal, Wait
// // -----------------------------------------------------------
void GroupMonitor::WaitOthers(int total, int id){
    Monitor::MonitorBegin();
    if (rCount == total){
        printf("    The last reindeer %d wakes up santa", id);
        rCount -= 1;
        allBack.Signal();
    } else {
        allBack.Wait();
        rCount -= 1;
        allBack.Signal();
    }
    Monitor::MonitorEnd();
}
// -----------------------------------------------------------
// // FUNCTION WaitSleigh
// //     makes the reindeer wait while all other raindeer are being
//        attaced to the sleigh
// // PARAMETER USAGE :
// //    total - total number of deer
// // FUNCTION CALLED :
// //    Printf, Signal, Wait
// // -----------------------------------------------------------
void GroupMonitor::WaitSleigh(int total){
    Monitor::MonitorBegin();
    onSleigh+=1;
    if (onSleigh == total){
    } else {
    }
    Monitor::MonitorEnd();
}
// -----------------------------------------------------------
// // FUNCTION FlyOff
// //     Signals that santa and the reindeer are away delivering toys
// // PARAMETER USAGE :
// //    total - total number of deer
// // FUNCTION CALLED :
// //    Printf, Signal, Wait
// // -----------------------------------------------------------
void GroupMonitor::FlyOff(int total){
    Monitor::MonitorBegin();
    Monitor::MonitorEnd();

}
//santa
// -----------------------------------------------------------
// // FUNCTION Sleep
// //     Blocks santa while waiting for deer or elves
// // PARAMETER USAGE :
// //
// // FUNCTION CALLED :
// //    Printf, Wait
// // -----------------------------------------------------------
void GroupMonitor::Sleep(){
    Monitor::MonitorBegin();
    printf("sleep\n");
    Monitor::MonitorEnd();
}
