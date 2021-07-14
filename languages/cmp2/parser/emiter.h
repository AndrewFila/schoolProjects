/************************************************/
/*                  emiter.h                    */
/* a list of emit functions to print assembly   */
/* code to stdout                               */
/*                                              */
/************************************************/

#ifndef EMITER_H
#define EMITER_H



int emitDeclaration();
int emitLoadIm(int val);
int emitAddition(int rightOp, int leftOp);
int emitMultiplication(int rightOp, int leftOp);
int emitSubtraction(int rightOp, int leftOp);
int emitDivision(int rightVal, int leftVal, int leftOp);
void emitWrite();
void emitRead();

#endif /*EMITER_H*/
