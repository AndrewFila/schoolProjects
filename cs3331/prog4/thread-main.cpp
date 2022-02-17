/*****************************************************************************/
/* Name: Andrew Fila                                        User ID: amfila  */
/* Due Date: 3-31-2021                                                       */
/* Program Assignment #4                                                     */
/* Filename: thread-main.cpp                                                 */
/* Program Purpose:                                                          */
/*                                                                           */
/*****************************************************************************/
#include <iostream>
#include "thread.h"


int main(int argc, char **argv){
    //Setup//////////////////
    if (argc != 4){ //safety check
            std::cout << "input error: requires 3 integer values './prog4 <m> <n> <k>'" << std::endl;
        exit(-1);
    }
    int llChecks = atoi(argv[1]);
    if (llChecks == 0){ //default condition
        llChecks = 5;
    }
    int maxStu   = atoi(argv[2]);
    if (maxStu == 0){
        maxStu = 5;
    }
    int totalStu = atoi(argv[3]);
    if (totalStu == 0){
        totalStu = 10;
    }
    std::cout << "checks: " << llChecks << ", max students: " << maxStu << ", total students:  " << totalStu << std::endl;
    /////////////////////////


    LandlordThread ll(llChecks, maxStu);
    ll.Begin();

    StudentThread **stu;
    stu = (StudentThread **)malloc(sizeof(StudentThread) * totalStu);
    for (int i = 0; i < totalStu; i++){
        stu[i] = new StudentThread(i, llChecks);
        stu[i]->Begin();
    }
    ll.Join();
}
