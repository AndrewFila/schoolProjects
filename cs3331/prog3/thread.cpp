/********************************************************/
/* NAME: Andrew Fila                    User ID: amfila */
/* DUE DATE: 3-15-2021                                  */
/* PROGRAM ASSIGNMENT #3                                */
/* FILENAME: thread.cpp                                 */
/* PROGRAM PURPOSE:                                     */
/*  sorts a given input array by even-odd sort          */
/********************************************************/

#include <stdlib.h>
#include <stdbool.h>
#include "thread.h"

/*****************************************/
/* FUNCTION SwapThread constuctor:       */
/*  assigns the values for indexes, input*/
/*  array and swapped flag               */
/* PARAMETER USAGE:                      */
/*  a1, a2 - indexes to be compared      */
/*  x[]    - input array                 */
/*  swapped- flag to signify if there has*/
/*           been a swap                 */
/* FUNCTION CALLED:                      */
/*  N/A                                  */
/*****************************************/



SwapThread::SwapThread(int a1, int a2, int x[], bool *swapped):a1(a1), a2(a2), x(x), swapped(swapped){}



/*****************************************************************************/
/* Function SwapThread implementation:                                       */
/*  Overall goal is to compare two values and swap them in the array if      */
/*  nessesary, also prints out information on even/odd pass, thread number   */
/*  and when it is created and exits.                                        */
/* Parameter Usage:                                                          */
/*  see above                                                                */
/* Function Called:                                                          */
/*  Exit(), cout                                                             */
/*****************************************************************************/


void SwapThread::ThreadFunc()
{
    Thread::ThreadFunc();
    if (a2 == 1){
        std::cout << "   even pass:" << std::endl;
    }
    if (a2 == 2){
        std::cout << "   odd pass:" << std::endl;
    }
    std::cout << "        thread " << a2 << " created" << std::endl;
    int temp;
    std::cout << "        thread " << a2 << " compares " << x[a1] << " and " << x[a2] << std::endl;
    if (x[a1] > x[a2]){         //if x[a1] is larger than x[a2], swap
        std::cout << "        thread " << a2 << " swaps " << x[a1] << " and " << x[a2] << std::endl;
        *swapped = true;        //flag as swapped
        temp  = x[a1];
        x[a1] = x[a2];
        x[a2] = temp;
    }
    std::cout << "        thread " << a2 << " exits" << std::endl;
    Exit();
}








/*****************************************/
/* FUNCTION  :                           */
/*                                       */
/* PARAMETER USAGE:                      */
/*                                       */
/* FUNCTION CALLED:                      */
/*                                       */
/*****************************************/
