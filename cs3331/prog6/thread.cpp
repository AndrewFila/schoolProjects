/*****************************************************************************/
/* Name: Andrew Fila                                User ID: amfila          */
/* Due Date: 4/25/2021                                                       */
/* Program Assignment #6                                                     */
/* File Name: thread.cpp                                                     */
/* Program Purpose:                                                          */
/*   This program finds prime numbers in range 2 to n where n is an          */
/*  inputed value.                                                           */
/*                                                                           */
/*****************************************************************************/
#include "thread.h"
#include "ThreadClass.h"
#include <string.h>
#include <stdio.h>
#define ever (;;)
int* primes = (int *) malloc(sizeof(int) * 1000);
extern PrimeThread *firstPrimeThread;
//-----------------------------
// Function printSpace
//  prints extra spaces
// parameter usage
//  num - number of spaces to print after multiplication (num * 2) + 2
//----------------------------
void printSpace(int num){
    for (int i = 0; i < (num * 2) + 2; i++){
        printf(" ");
    }
}

PrimeThread::PrimeThread(int index, int threadID, int primeID) {
    ThreadName.seekp(0, ios::beg);
    Index = index;
    ThreadID = threadID;
    ThreadName << "P" << primeID << ends;
    next = NULL;
    Number = -2;
    UserDefinedThreadID = threadID;

    strstream ChannelName;
    ChannelName << "Channel" << threadID - 1 << "-" << threadID << ends;
    channel = new SynOneToOneChannel(ChannelName.str(), threadID - 1, threadID);
}
//---------------------------------------------
// Fucntion ~PrimeThread()
//  PrimeThread Destructor
// Parameter Usage
//  none
// Function called
//  delete
//---------------------------------------------
PrimeThread::~PrimeThread(){
    delete channel;
}
//---------------------------------------------
// Fucntion PrimeThread()::ThreadFunc
//  receives numbers from its predecesor and checks to see if it is
//  divisible by the saved number, if it is it ignores it, otherwise it
//  sends the number to the next thread or creates a new next thread.
// Parameter Usage
//  index - the index in the primes array
//  threadID - the thread index
//  primeID - the integer part of the thread name P(2)
// Function called
//  printf(), Send(), Receive(), Begin(), Join()
//---------------------------------------------
void PrimeThread::ThreadFunc(){
    Thread::ThreadFunc();
    int nextPrime;
    int number;
    int tmpNum;

    for ever{
        channel->Receive(&number, sizeof(int));
        if (number == -1){                  //end of input
            printSpace(Index);
            printf("%s receives END\n", ThreadName.str());
            break;
        }
        if (Number == -2){                  //number not saved
            Number = number;                //save number in thread
            primes[Index] = number;         //save number in array
            primes[Index + 1] = -1;//terminate prime array with -1
            printSpace(Index);
            printf("%s starts and memorizes %d\n",ThreadName.str(), number);
        } else if (number%Number == 0){     //
            printSpace(Index);
            printf("%s ignores %d\n", ThreadName.str(), number);
        } else {
            if (next == NULL) {             //dosent have next node, create one
                printSpace(Index);
                printf("%s creates P%d\n", ThreadName.str(), number);
                nextPrime = number;
                next = new PrimeThread(Index + 1, ThreadID + 1, number);
                next->Begin();
            } else {                        //has next send the number
                printSpace(Index);
                printf("%s sends %d to P%d\n", ThreadName.str(), number, nextPrime);
            }
            next->channel->Send(&number, sizeof(int));//send number to next thread
        }
    }

    if (next != NULL){
        next->channel->Send(&number,  sizeof(int));
        next->Join();
    }
    Exit();
}

MasterThread::MasterThread(int max){
    UserDefinedThreadID = 0;
    Max = max;
    ThreadName.seekp(0, ios::beg);
    ThreadName << "Master" << ends;
}
//---------------------------------------------
// Fucntion MasterThread::ThreadFunc()
//  sends the numbers between 2 and max to P2
// Parameter Usage
//  max - max number to check for primality
// Function called
//  printf(), Send(), Join()
//---------------------------------------------
void MasterThread::ThreadFunc(){
    Thread::ThreadFunc();
    printf("Master starts\n");
    for (int i = 2; i <= Max; i++){                   //start pumping numbers
        printf("Master sends %d\n", i);
        firstPrimeThread->channel->Send(&i, sizeof(int));
    }

    //send end
    int END = -1;                                   //define end sig
    printf("Master sends END\n");
    firstPrimeThread->channel->Send(&END, sizeof(int)); //send END to P2
    firstPrimeThread->Join();                           //Wait until P2 is done
    //print primes array
    printf("Master prints the complete result:\n");
    int i = 0;
    while (primes[i] != -1){                    //print array
        printf(" %d",primes[i]);
        i++;
    }
    printf("\nMaster terminates\n");
    Exit();
}
//Mutex* PrimeLock;
//PrimeLock = new Mutex("Prime-Lock");
//PrimeLock->Lock();
  //critSection
//PrimeLock->Unlock();
