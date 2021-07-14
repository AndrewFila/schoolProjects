/********************************************************************************/
/*      NAME: Andrew Fila                                 User ID: amfila       */
/*      DUE DATE: 2-19-21                                                       */
/*      PROGRAM ASSIGNMENT #2                                                   */
/*      FILE NAME: main.c                                                       */
/*      PROGRAM PURPOSE:                                                        */
/*          This program is designed to create two childeren and have them exec */
/*      quick sort and merge sort respectivly. The memory for this assignment   */
/*      is using shared memory for use between programs.                         */
/********************************************************************************/









#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

/* ----------------------------------------------------------- */
/* FUNCTION  1 : getNum()                                      */
/*     the purpose of this function is to return an int from   */
/* our input-file                                              */
/* PARAMETER USAGE :                                           */
/*                                                             */
/* FUNCTION CALLED :                                           */
/*     atoi(), read()                                          */
/* ----------------------------------------------------------- */

int getNum(){
    //decloration section
    char buffer;
    int cnt = read(0,&buffer,1);
    char num[10];
    int i = 0;
    //copies the 1 char buffer into a number buffer to become an int
    do {
        num[i] = buffer;
        i++;
        read(0, &buffer, 1);
    } while (buffer != '\n');
    num[i] = '\0';
    return atoi(num);
}


/* ----------------------------------------------------------- */
/* FUNCTION  2 : getArray()                                    */
/*     the purpose of this function is to return an int array  */
/* from our input-file                                         */
/* PARAMETER USAGE :                                           */
/*     size -- the size of the array to be returned            */
/* FUNCTION CALLED :                                           */
/*     atoi(), read()                                          */
/* ----------------------------------------------------------- */
int * getArray(int size){
    int * array = malloc(sizeof(int) * size);
    char buffer = '\0';
    char num[5];
    int i = 0;
    int j = 0;
    while (buffer != '\n'){
        if (read(0, &buffer, 1) == 0){
            printf("EOF\n");
        }

        if (buffer == ' ' || buffer == '\n'){
            num[i] = '\0';
            array[j] = atoi(num);
            j++;
            i = 0;
        }else if (buffer == '\0') {

        }else {
            num[i] = buffer;
            i++;
        }
    }
    return array;
}


/* ----------------------------------------------------------- */
/* FUNCTION  main                                              */
/*    main function creates arrays for the inputs then stores  */
/* in the newly created shared memory then forks 2 children    */
/* and execs qsort and merge                                   */
/* PARAMETER USAGE :                                           */
/*                                                             */
/* FUNCTION CALLED :                                           */
/*     getNum, getArray, shmget, malloc/free, fork, wait,      */
/*  perror, exit                                               */
/* ----------------------------------------------------------- */


int main(int argc, char** argv){

    printf("Quicksort and Binary Merge with Multiple Processes:\n\n");
    //getting inputs
    int aCnt = getNum();
    printf("Input array for qsort has %d elements:\n\t", aCnt);
    int * a = (int *) malloc(sizeof(int) * aCnt);
    a = getArray(aCnt);
    for (int i = 0; i < aCnt; i++){
        printf("%d ", a[i]);
    }

    int xCnt = getNum();
    printf("\nInput array for x[] for merge has %d elements:\n\t", xCnt);
    int * x = (int *) malloc(sizeof(int) * xCnt);
    x = getArray(xCnt);
    for (int i = 0; i < xCnt; i++){
        printf("%d ", x[i]);
    }

    int yCnt = getNum();
    printf("\nInput array for y[] for merge has %d elements:\n\t", yCnt);
    int * y = (int *) malloc(sizeof(int) * yCnt);
    y = getArray(yCnt);
    for (int i = 0; i < yCnt; i++){
        printf("%d ", y[i]);
    }
    printf("\n\n");
    //shared memory section
    int shm_id[2];
    int *data[2];
    shm_id[0] = shmget(IPC_PRIVATE, aCnt*sizeof(int), IPC_CREAT | 0666);//mem created
    if (shm_id[0] >= 0){
        printf("*** MAIN: qsort shared memory key = %d\n", shm_id[0]);
        printf("*** MAIN: qsort shared memory created\n");
    } else {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    data[0] = shmat(shm_id[0], NULL, 0); //memory attached
    if (data[0] == (int *)(-1)){
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    printf("*** MAIN: qsort shared memory attached and is ready to use\n\n");
    //write to shared memory for qsort
    for (int i = 0; i < aCnt; i++){
        data[0][i] = a[i];
    }

    shm_id[1] = shmget(IPC_PRIVATE, (xCnt + yCnt)*sizeof(int), IPC_CREAT | 0666);
    if (shm_id[1] >= 0){
        printf("*** MAIN: merge shared memory key = %d\n", shm_id[1]);
        printf("*** MAIN: merge shared memory created\n");
    }
    data[1] = shmat(shm_id[1], NULL, 0);
    if (data[1] == (int *)(-1)){
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    printf("*** MAIN: merge shared memory attached and is ready to use\n\n");
    int i = 0;
    //write to shared memory for merge
    while ( i < xCnt){
        data[1][i] = x[i];
        i++;
    }
    while( i < xCnt + yCnt){
        data[1][i] = y[i];
        i++;
    }




    int pid[2];
    int wstatus[2];
    if ((pid[0] = fork()) == 0){ //child 1 -- qsort

        char * qsortArgs[2] = {"./qsort", NULL};
        if (execvp(qsortArgs[0], qsortArgs) == -1){
            perror("exec");
            exit(EXIT_FAILURE);
        }

    } else {
        if ((pid[1] = fork()) == 0){ //child 2 -- merge

            char buff[10];
            sprintf(buff, "%d", shm_id[1]);
            char * merge = "./merge";
            char * mergeArgs[2];
            mergeArgs[0] = merge;
            mergeArgs[1] = buff;

            if (execvp(mergeArgs[0], mergeArgs) == -1){
                perror("exec");
                exit(EXIT_FAILURE);
            }







        } else { //parent
            int status = waitpid(pid[0], &wstatus[0], 0);
            if (status == -1){
                perror("wait");
                exit(EXIT_FAILURE);

            }
            if (shmdt(data[0]) == -1){
                perror("shmdt");
                exit(EXIT_FAILURE);
            }
            printf("*** MAIN: qsort shared memory successfully detached\n");
            if (shmctl(shm_id[0], IPC_RMID, NULL) == -1){
                perror("shmctl");
                exit(EXIT_FAILURE);
            }
            printf("*** MAIN: qsort shared memory successfully removed\n\n");





            status = waitpid(pid[1], &wstatus[1], 0);
            if (status == -1){
                perror("wait");
                exit(EXIT_FAILURE);
            }
            if (shmdt(data[1]) == -1){
                perror("shmdt");
                exit(EXIT_FAILURE);
            }
            printf("*** MAIN: merge shared memory successfully detached\n");
            if (shmctl(shm_id[1], IPC_RMID, NULL) == -1){
                perror("shmctl");
                exit(EXIT_FAILURE);
            }
            printf("*** MAIN: merge shared memory successfully removed\n");
        }
    }

    return 1;
}
