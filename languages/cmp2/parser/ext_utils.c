#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "ext_utils.h"



static char* resRegNames[] = {"\%rsp", "\%rbp"};
static char* intRegNames[] = {"\%rdi","\%rsi","\%r8","\%r9","\%r10","\%r11","\%r12","\%r13","\%r14","\%r15"};
static char* intReg32Names[] = {"\%eax","\%ebx","\%ecx","\%edx","\%esi","\%edi","\%esp","\%ebp","\%r8d","\%r9d","\%r10d","\%r11d","\%r12d","\%r13d","\%r14d","\%r15d"};
bool * allocedReg;


/*********************************************/
/* initReg - initalizes our allocedReg array */
/* which keep track of if a regester is being*/
/* used -- default value = false (not in use)*/
/*********************************************/
void initReg(){
    allocedReg = (bool*) malloc(REG_NUM*sizeof(bool));
    for (int i = 0; i < REG_NUM; i++){
        allocedReg[i] = false;
    }
}

/*********************************************/
/* isRegAllocated simply checks if a regester*/
/* is allocated                              */
/*********************************************/
bool isRegAllocated(int reg){
    return allocedReg[reg];
}


/*********************************************/
/* allocateRegesters - returns the first free */
/* regester avalible for use (64 bit version)*/
/*********************************************/
int allocateRegester(){
    for (int i = 2; i < 16; i++){
        if (!allocedReg[i]){
            allocedReg[i] = true;
            return i;
        }
    }
    fprintf(stderr, "Regester Allocation Error\n");
    return -1; // no free regesters
}


/*********************************************/
/* allocateRegesters - returns the first free */
/* regester avalible for use (32 bit version)*/
/*********************************************/
int allocate32Regester(){
    for (int i = 16; i < REG_NUM; i++){
        if (!allocedReg[i]){
            return i;
        }
    }
    fprintf(stderr, "Regester Allocation Error\n");
    return -1; // no free regesters
}




/*********************************************/
/* getIntegerRegesterName - returns the name */
/* of the regester number given (64 bit)     */
/*********************************************/
char* getIntegerRegesterName(int reg){
    return intRegNames[reg];
}


/*********************************************/
/* getIntegerRegester32Name - reuturns the   */
/* name of the regester number given (32 bit)*/
/*********************************************/
char* getIntegerRegester32Name(int reg){
    return intReg32Names[reg];
}


/*********************************************/
/* freeIntegerRegester - marks the boolian   */
/* allocedReg array that the given regester  */
/* is now avalible                           */
/*********************************************/
void freeIntegerRegester(int reg){
    allocedReg[reg] = false;
}


/*********************************************/
/* reserveIntegerRegester - marks a given    */
/* regester as in use                        */
/*********************************************/
void reserveIntegerRegester(int reg){
    allocedReg[reg] = true;
}


/*********************************************/
/* freeRegisters - frees the allocedReg array*/
/*********************************************/
void freeRegisters(){
    free(allocedReg);
}
