/*****************************************************************************/
/* Name: Andrew Fila                                User ID: amfila          */
/* Due Date: 4/14/2021                                                       */
/* Program Assignment #5                                                     */
/* File Name: thread.h                                                       */
/* Program Purpose:                                                          */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#ifndef THREAD_H
#define THREAD_H
#include "ThreadClass.h"

/*****************************************************************************/
/* CLASS:                                                                    */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/
class ElfThread : public Thread{
    public:
        ElfThread(int);
    private:
        void ThreadFunc();
        int id;
};
/*****************************************************************************/
/* CLASS:  ReindeerThread                                                    */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/
class ReindeerThread : public Thread{
    public:
        ReindeerThread(int, int);
    private:
        void ThreadFunc();
        int total;
        int id;
};
/*****************************************************************************/
/* CLASS: SantaThread                                                        */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/
class SantaThread : public Thread{
    public:
        SantaThread(int, int, int);
        void Sleep();
    private:
        void ThreadFunc();
        int e;
        int r;
        int t;
};


/*****************************************************************************/
/* CLASS:                                                                    */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

class GroupMonitor : public Monitor{
    public:
        GroupMonitor();
        //santa
        void Sleep();
        //elves
        void AskQuestion(int);
        //reindeer
        void ReindeerBack(int, int);
        void WaitOthers(int, int);
        void WaitSleigh(int);
        void FlyOff(int);
    private:
        //santa
        Condition retire;
        //reindeer
        Condition allBack;
        int rWaiting;
        int onSleigh;
        int rCount;
        //elves
        Condition question;
        int groupSize;
        int eCount;
};


#endif /*THREAD_H*/
