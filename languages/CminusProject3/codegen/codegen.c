#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <util/string_utils.h>
#include <util/symtab.h>
#include <util/dlink.h>
#include "reg.h"
#include "codegen.h"
#include "symfields.h"

extern int globalOffset;
static void printDataDeclaration(DNode decl);
static void printInstruction(DNode inst);
static char* makeDataDeclaration(DList dataList, SymTable symtab, char *str);
static int emitBinaryExpression(DList instList, int leftOperand, int rightOperand, char* opcode);
static int emitBinaryExpression(DList instList, int leftOperand, int rightOperand, char* opcode);
static int emitBinaryCompareExpression(DList instList, int leftOperand, int rightOperand, char *opcode);


int count = 0;

/**
 * Print a data declaration to stdout. This function is called by dlinkApply only.
 *
 * @param decl a DNode containing a data declaration
 */
static void printDataDeclaration(DNode decl) {
	printf("\t%s\n",(char*)dlinkNodeAtom(decl));

}

/**
 * Emit the assembly prologue for a procedure
 */
void emitProcedurePrologue(DList instList, char* name) {
	char* inst = nssave(2,"\t.globl ",name);
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = nssave(3,"\t.type ",name,",@function");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = nssave(2,name,":\tnop");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = ssave("\tpushq %rbp");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = ssave("\tmovq %rsp, %rbp");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
}

/**
 * Print the assembly prologue that includes the data section, declare the global area and string consts
 *
 * @param dataList a list of data declarations (strings)
 */
void emitDataPrologue(DList dataList) {

	printf("\t.section\t.rodata\n");
	if (globalOffset != 0)
		printf("\t.comm _gp, %d, 4\n",globalOffset);

	dlinkApply(dataList,(DLinkApplyFunc)printDataDeclaration);
	printf("\t.text\n");
}

/**
 * Print an assembly instruction to stdout. This function is only called by dlinkApply.
 *
 * @param inst a DNode containing an assembly instruction.
 */
static void printInstruction(DNode inst) {
	printf("%s\n",(char*)dlinkNodeAtom(inst));
}

/**
 * Print all of the assembly instructions for the main routine to stdout.
 *
 * @param instList a DList of assembly instructions.
 */
void emitInstructions(DList instList) {
	dlinkApply(instList,(DLinkApplyFunc)printInstruction);
}

/**
 * Print epilogue
 */
void emitExit(DList instList) {
  char *inst = ssave("\tleave");
  dlinkAppend(instList,dlinkNodeAlloc(inst));
  inst = ssave("\tret");
  dlinkAppend(instList,dlinkNodeAlloc(inst));
}
/**
 * Add an instruction that performs an assignment.
 *
 * @param instList a DList of assembly instructions
 * @param lhsRegIndex the register index of the register for the l-value address
 * @param rhsRegIndex the register index of the register for the r-value
 */
void emitAssignment(DList instList, int lhsRegIndex, int rhsRegIndex) {
	char *inst;

	inst = nssave(5,  "\tmovl ", getIntegerRegisterName(rhsRegIndex),
			", (", get64bitIntegerRegisterName(lhsRegIndex), ")");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister(lhsRegIndex);
	freeIntegerRegister(rhsRegIndex);
}

/**
 * Add the instructions needed to read a variable using the scanf system call.
 *
 * @param instList a DList of instructions
 * @param dataList a Dlist of data declarations
 * @param formatStr a format string
 * @param symtab a symbol table
 * @param addrIndex the register index of the register holding the address that is to be read into
 */
void emitReadVariable(DList instList, DList dataList, char *formatStr, SymTable symtab, int addrIndex) {
        char *inst;

	char *fmtLabel = makeDataDeclaration(dataList, symtab, formatStr);
	inst = nssave(3,"\tleaq ", fmtLabel, "(%rip), %rdi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
        free(fmtLabel);

	inst = nssave(3,"\tmovq ", get64bitIntegerRegisterName(addrIndex), ", %rsi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = ssave("\tmovl $0, %eax");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = ssave("\tcall scanf@PLT");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister(addrIndex);
}

/**
 * Add the instructions needed to write a value using the printf system call.
 *
 * @param instList a Dlist of instructions
 * @param dataList a Dlist of data declarations
 * @param formatStr a format string
 * @param symtab a symbol table
 * @param regIndex the symbol table index of the register to be printed (must be addres if string)
 */
void emitWriteExpression(DList instList, DList dataList, char *formatStr, SymTable symtab, int regIndex) {
	char *inst;
	char *fmtLabel = makeDataDeclaration(dataList, symtab, formatStr);
	inst = nssave(3, "\tleaq ", fmtLabel, "(%rip), %rdi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
        free(fmtLabel);

	inst = nssave(3,"\tmovl ", getIntegerRegisterName(regIndex), ", %esi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = ssave("\tmovl $0, %eax");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	freeIntegerRegister(regIndex);

	inst = ssave("\tcall printf@PLT");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
}

/**
 * Add the instructions needed to write a string using the printf system call.
 *
 * @param instList a Dlist of instructions
 * @param dataList a Dlist of data declarations
 * @param symtab a symbol table
 * @param str the string to print
 */
void emitWriteString(DList instList,  DList dataList, SymTable symtab, char *str) {
    char *strLabel = makeDataDeclaration(dataList, symtab, str);

	char* inst = nssave(4,"\tleaq ", strLabel, "(%rip), ", "%rdi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	free(strLabel);

	inst = ssave("\tcall printf@PLT");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
}

/**
 * Add an instruction that performs a binary computation.
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @param opcode the opcode of the x86 assembly instruction
 * @return
 */
static int emitBinaryExpression(DList instList, int leftOperand, int rightOperand, char* opcode) {
	char* leftName = getIntegerRegisterName(leftOperand);
	char* rightName = getIntegerRegisterName(rightOperand);

	char* inst = nssave(6,"\t",opcode," ", rightName,", ",leftName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister(rightOperand);

	return leftOperand;
}

/**
 * Add instructions for logical or
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitOrExpression(DList instList, int leftOperand, int rightOperand) {
	emitBinaryExpression(instList,leftOperand,rightOperand,"orl");

	int tOp = allocateIntegerRegister();
	char *tmpName = getIntegerRegisterName(tOp);

	char *inst = nssave(2, "\tmovl $1, ", tmpName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));


	inst = nssave(4, "\tcmovne ", tmpName, ", ", getIntegerRegisterName(leftOperand));
	dlinkAppend(instList,dlinkNodeAlloc(inst));

 	freeIntegerRegister(tOp);
	return leftOperand;
}

/**
 * Add instructions for logical and
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitAndExpression(DList instList, int leftOperand, int rightOperand) {
        char* leftName = getIntegerRegisterName(leftOperand);
	char* rightName = getIntegerRegisterName(rightOperand);

	char* inst = nssave(4, "\ttestl ", leftName, ", ", leftName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

        inst = nssave(2, "\tmovl $1, ", leftName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	int tOp = allocateIntegerRegister();
	char *tmpName = getIntegerRegisterName(tOp);
	inst = nssave(2, "\tmovl $0, ", tmpName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));


	inst = nssave(4, "\tcmove ", tmpName, ", ", leftName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = nssave(4, "\ttestl ", rightName, ", ", rightName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

        inst = nssave(2, "\tmovl $1, ", rightName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = nssave(2, "\tmovl $0, ", tmpName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));


	inst = nssave(4, "\tcmove ", tmpName, ", ", rightName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

 	freeIntegerRegister(tOp);

        return emitBinaryExpression(instList,leftOperand,rightOperand,"andl");
}

/**
 * Add instructions for logical not
 *
 * @param instList a DList of instructions
 * @param operand the register index of the register holding the operand
 * @return the register index for the result register
 */
int emitNotExpression(DList instList, int operand) {
    char* opName = getIntegerRegisterName(operand);
	int tmpOp = allocateIntegerRegister();
	char *tmpName = getIntegerRegisterName(tmpOp);

	char* inst = nssave(2, "\tmovl $-1, ", tmpName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = nssave(4, "\ttestl ", tmpName, ", ", opName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

        inst = nssave(2, "\tmovl $0, ", opName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));


	inst = nssave(2, "\tmovl $1, ", tmpName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = nssave(4, "\tcmove ", tmpName, ", ", opName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister(tmpOp);

	return operand;
}

/**
 * Add instructions that performs a binary comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @param opcode the opcode of the x86 assembly instruction
 * @return the register index for the result register
 */
static int emitBinaryCompareExpression(DList instList, int leftOperand, int rightOperand, char *opcode) {
	leftOperand = emitBinaryExpression(instList,leftOperand,rightOperand,"cmpl");
	freeIntegerRegister(rightOperand);

	char *inst = nssave(2,"\tmovl $0, ", getIntegerRegisterName(leftOperand));
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	int tregIndex = allocateIntegerRegister();

	inst = nssave(2,"\tmovl $1, ", getIntegerRegisterName(tregIndex));
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	return emitBinaryExpression(instList,leftOperand,tregIndex,opcode);
}

/**
 * Add instructions that performs a == comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitEqualExpression(DList instList, int leftOperand, int rightOperand) {
    return emitBinaryCompareExpression(instList,leftOperand,rightOperand,"cmove");
}
/**
 * Add instructions that performs a != comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */

int emitNotEqualExpression(DList instList, int leftOperand, int rightOperand) {
  return emitBinaryCompareExpression(instList,leftOperand,rightOperand,"cmovne");
}

/**
 * Add instructions that performs a <= comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitLessEqualExpression(DList instList, int leftOperand, int rightOperand) {
  return emitBinaryCompareExpression(instList,leftOperand,rightOperand,"cmovle");
}

/**
 * Add instructions that performs a < comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitLessThanExpression(DList instList,int leftOperand, int rightOperand) {
  return emitBinaryCompareExpression(instList,leftOperand,rightOperand,"cmovl");
}

/**
 * Add instructions that performs a >= comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 */
int emitGreaterEqualExpression(DList instList, int leftOperand, int rightOperand) {
  return emitBinaryCompareExpression(instList,leftOperand,rightOperand,"cmovge");
}

/**
 * Add instructions that performs a > comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitGreaterThanExpression(DList instList, int leftOperand, int rightOperand) {
  return emitBinaryCompareExpression(instList,leftOperand,rightOperand,"cmovg");
}


/**
 * Add instructions that performs addtion
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitAddExpression(DList instList, int leftOperand, int rightOperand) {
	return emitBinaryExpression(instList,leftOperand,rightOperand,"addl");
}

/**
 * Add instructions that performs substruction
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitSubtractExpression(DList instList, int leftOperand, int rightOperand) {
	return emitBinaryExpression(instList,leftOperand,rightOperand,"subl");
}

/**
 * Add instructions that performs multiplication
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitMultiplyExpression(DList instList, int leftOperand, int rightOperand) {
	return emitBinaryExpression(instList,leftOperand,rightOperand,"imull");
}

/**
 * Add instructions that performs division
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitDivideExpression(DList instList, int leftOperand, int rightOperand) {
                char *inst;

	        inst = nssave(3,"\tmovl ", getIntegerRegisterName(leftOperand), ", %eax");
	        dlinkAppend(instList,dlinkNodeAlloc(inst));


		inst = ssave("\tcdq");
		dlinkAppend(instList,dlinkNodeAlloc(inst));

		inst = nssave(2,"\tidivl ", getIntegerRegisterName(rightOperand));
		dlinkAppend(instList,dlinkNodeAlloc(inst));

	        inst = nssave(2,"\tmovl %eax, ", getIntegerRegisterName(leftOperand));
		dlinkAppend(instList,dlinkNodeAlloc(inst));


	        freeIntegerRegister(rightOperand);

		return leftOperand;
}

/**
 * Add an instruction to compute the address of a variable.
 *
 * @param instList a Dlist of instructions
 * @param symtab a symbol table
 * @param varIndex the register index for a variable
 * @return the register index of the address register
 */
int emitComputeVariableAddress(DList instList, SymTable symtab, int varIndex) {

  int addrRegIndex = allocateIntegerRegister();
  char* addrRegName = (char*)get64bitIntegerRegisterName(addrRegIndex);

  int offset = (int)SymGetFieldByIndex(symtab,varIndex,SYMTAB_OFFSET_FIELD);
  char offsetStr[10];
  snprintf(offsetStr,9,"%d",offset);

  char *inst = nssave(2,"\tleaq _gp(%rip), ", addrRegName);
  dlinkAppend(instList,dlinkNodeAlloc(inst));
  inst = nssave(4,"\taddq $", offsetStr, ", ", addrRegName);
  dlinkAppend(instList,dlinkNodeAlloc(inst));

  return addrRegIndex;
}

/**
 * Add an instruction to load a variable from memory.
 *
 * @param instList a Dlist of instructions
 * @param regIndex the register index for the address of a variable
 * @return the register index of the result register
 */
int emitLoadVariable(DList instList, int regIndex) {
	int dstRegIndex = allocateIntegerRegister();
	char* dstRegName = (char*)getIntegerRegisterName(dstRegIndex);

	char* srcAddrRegName = (char*) get64bitIntegerRegisterName(regIndex);

	char *inst = nssave(4,"\tmovl (",srcAddrRegName,"), ", dstRegName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister(regIndex);

	return dstRegIndex;
}

/**
 * Add an instruction to load an integer constant
 *
 * @param instList a Dlist of instructions
 * @param intConst the const string of an integer constant
 * @return the register index of the result register holding the const
 */
int emitLoadIntegerConstant(DList instList, char * intConst) {
	int regIndex = allocateIntegerRegister();
	char* regName = (char*)getIntegerRegisterName(regIndex);

	char *inst = nssave(4,"\tmovl $", intConst, ", ", regName);

	dlinkAppend(instList,dlinkNodeAlloc(inst));

	return regIndex;
}

/**
 * Add a .asciiz declaration for a string constant if it hasn't been declared
 *
 * @param dataList a DList of data declarations
 * @param symtab a symbol table
 * @param str string constant to put into data section
 * @return the label of the string constant
 */
static char* makeDataDeclaration(DList dataList, SymTable symtab, char* str) {
	static int stringNum = 0;
	int symIndex = SymQueryIndex(symtab, str);
	int labelcount;
	char* strLabel = (char*)malloc(sizeof(char)*15);

	if (symIndex == SYM_INVALID_INDEX) {
	   symIndex = SymIndex(symtab, str);
	   labelcount = stringNum++;
           SymPutFieldByIndex(symtab,symIndex,SYMTAB_OFFSET_FIELD, (Generic)labelcount);

	   snprintf(strLabel, 17, ".string_const%d",labelcount);

	   char* decl = nssave(3, strLabel, ": .string ", str);
 	   dlinkAppend(dataList,dlinkNodeAlloc(decl));
	} else {
	  labelcount = (int)SymGetFieldByIndex(symtab,symIndex,SYMTAB_OFFSET_FIELD);
          snprintf(strLabel,15,".string_const%d",labelcount);

        }

	return strLabel;
}


/**
 * Add an identifier to the symbol table and store its offset
 * @param symtab a symbol table
 * @param id the symbol table index of an identifier
 */
void addIdToSymtab(SymTable symtab, char* id) {
	int symIndex = SymIndex(symtab, id);

        SymPutFieldByIndex(symtab, symIndex, SYMTAB_OFFSET_FIELD, (Generic)globalOffset);
        globalOffset += 4;
}
/*************************************************************/


/*
 *  Emit the if function for assembly
 *  @param
 */




//TODO -- Add a grammar rule to accept decloration of a 2D int arrays,
//TODO -- Add a grammar rule to acccept a reference to a 2D integer array element
//TODO -- Generate assembly to test the results of an expression controlling an if statemtn or while loop
/*
 * Sets the label number and emits assembly if statement.
 * @param(Dlist instList) --
 */

int emitIf(DList instList, int regIndex){
	char *regName = (char*)getIntegerRegisterName(regIndex);
    char *inst = ssave("\tmovl $-1, %eax");
    dlinkAppend(instList, dlinkNodeAlloc(inst));
    inst = nssave(2,"\ttestl %eax, ",regName);




    char label[20];
    snprintf(label,19,"%d",count);

    dlinkAppend(instList, dlinkNodeAlloc(inst));
    inst = nssave(2,"\tje .L",label);
    dlinkAppend(instList, dlinkNodeAlloc(inst));
    return count;
}
void emitEndIf(DList instList, int labelNum){
    char label[20];
    makeLabelName(label);
    char *inst = nssave(3,".L",label,":\tnop");
    dlinkAppend(instList, dlinkNodeAlloc(inst));
    count++;
}

//TODO -- Generate assembly to branch through an if-then-else statemetn as determined by the controlling expression
int emitThen(DList instList, int labelNum){
        char label[20];
        makeLabelName(label);
        char *inst = nssave(2,"\tjmp\t.L",label);
        dlinkAppend(instList, dlinkNodeAlloc(inst));
        count++;
        makeLabelName(label);
        inst = nssave(3, ".L",label,":\tnop");
        dlinkAppend(instList, dlinkNodeAlloc(inst));
    return labelNum;
}
//TODO -- Generate assembly to branch back to the begining of and out of a while-loop as determine by the controlling esxpression
//TODO -- Reserve space for an array of integers
//TODO -- Generate addresss arithemtic for an array reference.
//        For array declarations you only need to handle the following style:
//          int a[10][20], b[30]
