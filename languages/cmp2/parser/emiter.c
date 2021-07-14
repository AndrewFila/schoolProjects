/************************************************/
/*                  emiter.c                    */
/* a list of emit functions to print assembly   */
/* code to stdout                               */
/*                                              */
/************************************************/





#include <stdio.h>
#include <stdbool.h>
#include "emiter.h"
#include "ext_utils.h"

int emitDeclaration(){
    printf("\t.section      .rodata");
    //emitStringConstants();
    printf("\t.text");
}



/* emitLoadim
 * input is an integer value to assign to a regester
 * returns the use regester
 */
int emitLoadIm(int val){
    int reg = allocateRegester();
    printf("\tmovl $%d, %s\n", val, getIntegerRegesterName(reg));
    return reg;
}
int emitLoadWFM(){
    return 0;
}
int emitStoreWTM(){
    return 0;
}

/* emitAddition
 * input is two regester values to add together
 * returns the value of the regester where the addition is stored
 */
int emitAddition(int rightOp, int leftOp){
    printf("\taddl %s, %s\n", getIntegerRegesterName(rightOp), getIntegerRegesterName(leftOp));
    return rightOp;
}

int emitMultiplication(int rightOp, int leftOp){
    printf("\timull %s, %s\n", getIntegerRegesterName(rightOp), getIntegerRegesterName(leftOp));
    return rightOp;
}

int emitSubtraction(int rightOp, int leftOp){
    printf("\tsubl %s, %s\n", getIntegerRegesterName(rightOp), getIntegerRegesterName(leftOp));
    return rightOp;
}

int emitDivision(int rightVal, int leftVal, int leftOp){
//    printf("\tmovl $%d, %s\n", rightVal, getIntegerRegesterName(leftOp));
//    printf("\tmovl $%d, %s\n", leftVal, getIntegerRegesterName(28));
//    printf("\tcdq\n");
//    printf("\tidivl %s\n", getIntegerRegesterName(18));
    return 29;
}
