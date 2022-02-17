#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include "thread.h"

static int timesChecked = 0;




StudentThread::StudentThread(int studentNo, int checks): studentNo(studentNo), checks(checks){}

void StudentThread::ThreadFunc(){
    Thread::ThreadFunc();
    std::cout << "     Student " << studentNo << " starts" << std::endl;
    while(1){
        if (timesChecked >= checks ){break;}
        Delay();
        goToParty();
        Delay();
    }
    int n;
    char buffer[100];
    n = sprintf(buffer, "     Student %d terminates\n", studentNo);
    write(1, &buffer, n);
    Exit();
}






LandlordThread::LandlordThread(int checks, int maxStudents):checks(checks), maxStudents(maxStudents){}

void LandlordThread::ThreadFunc(){
    Thread::ThreadFunc();
    for (timesChecked ; timesChecked < checks; timesChecked++){
        Delay();
        checkRoom(maxStudents, checks);
        Delay();
    }
    int n;
    char buffer[100];
    n = sprintf(buffer, "After checking the room %d times, the landlord retires and is on vacation!\n", timesChecked + 1);
    write(1, &buffer, n);
    Exit();
}
