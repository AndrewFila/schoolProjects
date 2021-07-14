#ifndef UTIL_H
#define UTIL_H



//Reserved
#define REG_NUM 28
#define RSP  0
#define RBP  1

//Not Preserved
#define RAX  2
#define RBX  3
#define RCX  4
#define RDX  5
#define RDI  6
#define RSI  7
#define R8   8
#define R9   9
#define R10  10
#define R11  11
#define R12  12
#define R13  13
#define R14  14
#define R15  15

//32-bit portions

#define EBX  16
#define ECX  17
#define ESP  18
#define EBP  19

#define R8D  20
#define R9D  21
#define R10D 22
#define R11D 23
#define R12D 24
#define R13D 25
#define R14D 26
#define R15D 27


#define EAX  28
#define EDX  29
#define ESI  30
#define EDI  31

void    initReg();
bool    isRegAllocated(int reg);
int     allocateRegester();
int     alloacte32Regester();
char*   getIntegerRegesterName();
char*   getIntegerRegesterName();
void    freeIntegerRegester();
void    reserveIntegerRegester();
void    freeRegesters();



#endif /*UTIL_H*/
