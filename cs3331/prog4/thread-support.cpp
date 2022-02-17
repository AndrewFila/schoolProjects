
/*****************************************************************************/
/* Name: Andrew Fila                                  User ID: amfila        */
/* Due Date: 3-31-2021                                                       */
/* Program assignment #4                                                     */
/* Filename: thread-support.cpp                                              */
/* Program Purpose:                                                          */
/*                                                                           */
/*****************************************************************************/

#include <iostream>
#include "thread.h"
#include <stdio.h>
#include <unistd.h>

static int inRoom = 0;
static int timesChecked     = 0;

//static Semaphore timesChecked("timesChecked", 0);
static Semaphore studentsInRoom("studentsInRoom",0);


static Semaphore Queue("WaitingQueue", 1);
static Semaphore EnterRoom("EnterRoom", 1);
static Semaphore ExitRoom("ExitRoom", 1);
static Semaphore RemoveStudents("RemoveStudents",1);


// -----------------------------------------------------------
// // FUNCTION  goToParty()
// //     allows students to enter and leave thre room
// // PARAMETER USAGE :
// //     N/A
// // FUNCTION CALLED :
// //    sprintf, write, Signal(), Wait(), Delay
// // -----------------------------------------------------------

void StudentThread::goToParty(){
        char buffer[100];
        int n;
        //entry protocol
        Queue.Wait(); //student waits to enter the queue
        n = sprintf(buffer, "     Student %d waits to enter the room\n", studentNo);
        write(1,&buffer,n);

        EnterRoom.Wait();//student waits to enter room
        Queue.Signal();  //let a new student wait to get in.

        ////critical section////
        inRoom++;
        studentsInRoom.Signal();
        n = sprintf(buffer, "     Student %d enters the room (%d students in room)\n", studentNo, inRoom);
        write(1,&buffer,n);
        ////////////////////////

        //s.wait();

        EnterRoom.Signal();
        //PARTY
        Delay();
        //Enough Partying

        //exit protocol
        ExitRoom.Wait();
        n = sprintf(buffer, "     Student %d waits to leave the room\n", studentNo);
        write(1,&buffer,n);
        inRoom--;
        studentsInRoom.Wait();
        ExitRoom.Signal();
        n = sprintf(buffer, "     Student %d leave the room\n", studentNo);
        write(1,&buffer,n);
}



//-----------------------------------------------------------
// FUNCTION  CheckRoom
//     allows the landlord to check the room and remove students if nessesary
// PARAMETER USAGE :
//    maxStudents: nuber of students allowd in a room
//    checks:   nuber of checks the landlord makesl
// FUNCTION CALLED :
//    write, sprintf, Signal(), Wait()
// -----------------------------------------------------------



void LandlordThread::checkRoom(int maxStudents, int checks){
        int n;
        char buffer[100];
        //entry protocol
        EnterRoom.Wait();
        ExitRoom.Wait();
        n = sprintf(buffer, "The landlord checks the room the %d-th time\n", timesChecked);
        write(1, &buffer, n);
        timesChecked++;


        //check room
        if (inRoom < maxStudents){
            n = sprintf(buffer, "The landlord finds there are %d students in the room (condition being good) and leaves.\n", inRoom);
            write(1, &buffer, n);
            EnterRoom.Signal();
            ExitRoom.Signal();
        }
        else {
            n = sprintf(buffer, "The landlord finishes checking and forces everyone to leave\n");
            write(1, &buffer, n);
            //while (studentsInRoom > 0);
            ExitRoom.Signal();
            //crit
            n = sprintf(buffer, "The landlord leaves the room and the room is empty\n");
            write(1, &buffer, n);
            EnterRoom.Signal();
        }

        if (timesChecked == checks){
            Queue.Wait();
            EnterRoom.Wait();
            ExitRoom.Wait();
        }
}
