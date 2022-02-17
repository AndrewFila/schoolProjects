/********************************************************/
/* NAME: Andrew Fila                    User ID: amfila */
/* DUE DATE: 3-15-2021                                  */
/* PROGRAM ASSIGNMENT #3                                */
/* FILENAME: thread.h                                   */
/* PROGRAM PURPOSE:                                     */
/*  sorts a given input array by even-odd sort          */
/********************************************************/

#ifndef THREAD_H
#define THREAD_H
#include <stdbool.h>
#include "ThreadClass.h"

/********************************************************/
/*  Class SwapThread:                                   */
/*   defines the Swap thread class and associated       */
/*   variables                                          */
/********************************************************/

class SwapThread : public Thread
{
        public:
                SwapThread(int a1, int a2, int x[], bool *swapped);

        private:
            void ThreadFunc();
            int a1;
            int a2;
            int *x;
            bool *swapped;
};

#endif /*THREAD_H*/
