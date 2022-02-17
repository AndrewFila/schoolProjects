/*****************************************************************************/
/* Name: Andrew Fila                                User ID: amfila          */
/* Due Date: 4/25/2021                                                       */
/* Program Assignment #5                                                     */
/* File Name: thread.h                                                       */
/* Program Purpose:                                                          */
/*  creates a sieve to find the prime numbers under input n                  */
/*  -- header file defines the prime thread and master threads               */
/*                                                                           */
/*****************************************************************************/

#ifndef THREAD_H
#define THREAD_H
#include "ThreadClass.h"


class PrimeThread : public Thread{
    public:
        PrimeThread(int, int, int);
        ~PrimeThread();
        SynOneToOneChannel *channel;
    private:
       void ThreadFunc();
       int ThreadID;
       int Index;
       int Number;
       PrimeThread *next;
};

class MasterThread : public Thread{
    public:
        MasterThread(int);
    private:
        int Max;
        void ThreadFunc();
};


#endif /*THREAD_H*/
