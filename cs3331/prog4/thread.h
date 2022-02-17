/*****************************************************************************/
/* Name: Andrew Fila                                  User ID: amfila        */
/* Due Date: 3-31-2021                                                       */
/* Program assignment #4                                                     */
/* Filename: thread.h                                                        */
/* Program Purpose:                                                          */
/*                                                                           */
/*****************************************************************************/

#ifndef THREAD_H
#define THREAD_H
#include "ThreadClass.h"

class StudentThread : public Thread {
    public:
        StudentThread(int studentNo, int checks);
        void goToParty();
    private:
        void ThreadFunc();
        int checks;
        int studentNo;
};
class LandlordThread : public Thread {
    public:
        LandlordThread(int checks, int maxStudents);
        void checkRoom(int checks, int maxStudents);
    private:
        void ThreadFunc();
        int checks;
        int maxStudents;
};




#endif /*THREAD_H*/
