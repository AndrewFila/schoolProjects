#ifndef CODEGEN_H_
#define CODEGEN_H_

EXTERN(void, emitProcedurePrologue, (DList instList, char* name));
EXTERN(void, emitDataPrologue, (DList dataList));
EXTERN(void, emitInstructions,(DList list));
EXTERN(void, emitExit, (DList instList));
EXTERN(void, emitAssignment, (DList instList, int lhsRegIndex, int rhsRegIndex));
EXTERN(void, emitReadVariable, (DList instList, DList dataList, char *formatStr, SymTable symtab, int addrIndex));
EXTERN(void, emitWriteExpression, (DList instList, DList dataList, char *formatStr, SymTable symtab, int regIndex));
EXTERN(void, emitWriteString,(DList instList,  DList dataList, SymTable symtab, char *str));

EXTERN(int, emitOrExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitAndExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitNotExpression, (DList instList, int operand));
EXTERN(int, emitEqualExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitNotEqualExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitLessEqualExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitLessThanExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitGreaterEqualExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitGreaterThanExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitAddExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitSubtractExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitMultiplyExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitDivideExpression, (DList instList, int leftOperand, int rightOperand));

EXTERN(int, emitComputeVariableAddress,(DList instList,  SymTable symtab, int varIndex));
EXTERN(int, emitLoadVariable,(DList instList, int varIndex));
EXTERN(int, emitLoadIntegerConstant,(DList instList, char* intConst));

EXTERN(void, addIdToSymtab, (SymTable symtab, char* id));
EXTERN(int, emitIf, (DList instList, int regIndex));
EXTERN(int, emitThen, (DList instList, int labelNum));
EXTERN(void, emitEndIf, (DList instList, int labelNum));
#endif /*CODEGEN_H_*/

