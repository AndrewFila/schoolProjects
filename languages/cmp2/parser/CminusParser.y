/*******************************************************/
/*                     Cminus Parser                   */
/*                                                     */
/*******************************************************/

/*********************DEFINITIONS***********************/
%{
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <util/general.h>
#include <util/symtab.h>
#include <util/string_utils.h>
#include "emiter.h"
#include "ext_utils.h"

#define SYMTABLE_SIZE 100
#define SYMTAB_VALUE_FIELD     "value"

/*********************EXTERNAL DECLARATIONS***********************/

EXTERN(void,yyerror,(const char*));

EXTERN(int,yylex,(void));

char *fileName;

int strConst = 0;
int ids      = 0;
int offset   = 0;


SymTable symtab;

extern int yylineno;

extern FILE *yyin;

static int getValue(char *name);
static void setValue(char *name, int value);
%}

%defines

%start Program

%token AND
%token ELSE
%token EXIT
%token FOR
%token IF
%token INTEGER
%token NOT
%token OR
%token READ
%token WHILE
%token WRITE
%token LBRACE
%token RBRACE
%token LE
%token LT
%token GE
%token GT
%token EQ
%token NE
%token ASSIGN
%token COMMA
%token SEMICOLON
%token LBRACKET
%token RBRACKET
%token LPAREN
%token RPAREN
%token PLUS
%token TIMES
%token IDENTIFIER
%token DIVIDE
%token RETURN
%token STRING
%token INTCON
%token MINUS
%token INCLUDE
%token HEADERSTRING
%token ADDR

%left OR
%left AND
%left NOT
%left LT LE GT GE NE EQ
%left PLUS MINUS
%left TIMES DIVDE

%union {
    char*	name;
    int     val;
}
%type <val> Expr SimpleExpr AddExpr MulExpr Factor Constant INTCON
%type <name> Variable STRING StringConstant IDENTIFIER

/***********************PRODUCTIONS****************************/
%%
Program		: Headers Programbody
                {
                    //printf("<Program> -> <Headers> <Programbody>\n");
                }
                | Programbody
                {
                    //printf("<Program> -> <Programbody>\n");
                }
                ;

Headers         : Headers Header
                {
                    //printf("<Headers> -> <Headers> <Header>\n");
                }

                | Header
                {
                    //printf("<Headers> -> <Header>\n");
                }
                ;

Header          : INCLUDE HEADERSTRING
                {
                    printf("\t.section\t.rodata\n");
                    //printf("<Header> -> <INCLUDE> <HEADERSTRING>\n");
                }
                ;

Programbody		: Procedures
                {
                    //printf("<Program> -> <Procedures>\n");
                }
                | DeclList Procedures
                {
                    //printf("<Program> -> <DeclList> <Procedures>\n");
                }
                ;

Procedures 	    : ProcedureDecl Procedures
                {
                    //printf("<Procedures> -> <ProcedureDecl> <Procedures>\n");
                }
                |
                {
                    printf("\tleave\n\tret\n");
                    //printf("<Procedures> -> epsilon\n");
                }
                ;

ProcedureDecl   : ProcedureHead ProcedureBody
                {
                    //printf("<ProcedureDecl> -> <ProcedureHead> <ProcedureBody>\n");
                }
                ;

ProcedureHead   : FunctionDecl DeclList
                {
                    //printf("<ProcedureHead> -> <FunctionDecl> <DeclList>\n");
                }
                | FunctionDecl
                {
                    //printf("<ProcedureHead> -> <FunctionDecl>\n");
                }
                ;

FunctionDecl    :  Type IDENTIFIER LPAREN RPAREN LBRACE
                {
                    printf("\t.text\n\t.globl main\n\t.type main, @function\nmain:\tnop\n\tpushq %rbp\n\tmovq %rsp, %rbp\n");
                }
                ;

ProcedureBody   : StatementList RBRACE
                {
                    //printf("<ProcedureBody> -> <StatementList> <RBR>\n");
                }
                ;


DeclList 	    : Type IdentifierList  SEMICOLON
                {
                    printf("\t.comm _gp, %d, %d\n", ids*4, ids);
                    //printf("<DeclList> -> <Type> <IdentifierList> <SC>\n");
                }
                | DeclList Type IdentifierList SEMICOLON
                {
                    printf("<DeclList> -> <DeclList> <Type> <IdentifierList> <SC>\n");
                }
                ;


IdentifierList 	: VarDecl
                {
                    //printf("<IdentifierList> -> <VarDecl>\n");
                }

                | IdentifierList COMMA VarDecl
                {
                    //printf("<IdentifierList> -> <IdentifierList> <CM> <VarDecl>\n");
                }
                ;

VarDecl 	    : IDENTIFIER
                {
                    ids++;
                    //printf("<VarDecl> -> <IDENTIFIER>\n");
                }
                | IDENTIFIER LBRACKET INTCON RBRACKET
                {
                    //printf("<VarDecl> -> <IDENTIFIER> <LBK> <INTCON> <RBK>\n");
                }
                ;

Type     	    : INTEGER
                {
                    //printf("<Type> -> <INTEGER>\n");
                }
                ;

Statement 	    : Assignment
                {
                    //printf("<Statement> -> <Assignment>\n");
                }
                | IfStatement
                {
                    //printf("<Statement> -> <IfStatement>\n");
                }
                | WhileStatement
                {
                    //printf("<Statement> -> <WhileStatement>\n");
                }
                | IOStatement
                {
                    //printf("<Statement> -> <IOStatement>\n");
                }
                | ReturnStatement
                {
                    //printf("<Statement> -> <ReturnStatement>\n");
                }
                | ExitStatement
                {
                    //printf("<Statement> -> <ExitStatement>\n");
                }
                | CompoundStatement
                {
                    //printf("<Statement> -> <CompoundStatement>\n");
                }
                ;

Assignment      : Variable ASSIGN Expr SEMICOLON
                {
                  setValue($1, $3);
                  printf("\tleaq _gp(&rip), %rbx\n");
                  printf("\taddq %s, %rbx\n",offset);
                  //printf("\tmovl $1, %s\n", getIntegerRegesterName($1));
                  //printf("\tmovl %s, (%rbx)\n");
                  //offset++;
                  //printf("*<Assignment> -> <Variable> <ASSIGN> <Expr> <SC>\n");
                }
                ;

IfStatement	    : IF TestAndThen ELSE CompoundStatement
                {
                    //printf("<IfStatement> -> <IF> <TestAndThen> <ELSE> <CompoundStatement>\n");
                }
                | IF TestAndThen
                {
                    //printf("<IfStatement> -> <IF> <TestAndThen>\n");
                }
                ;


TestAndThen	    : Test CompoundStatement
                {
                    //printf("<TestAndThen> -> <Test> <CompoundStatement>\n");
                }
                ;

Test		    : LPAREN Expr RPAREN
                {
                    //printf("<Test> -> <LP> <Expr> <RP>\n");
                }
                ;


WhileStatement  : WhileToken WhileExpr Statement
                {
                    //printf("<WhileStatement> -> <WhileToken> <WhileExpr> <Statement>\n");
                }
                ;

WhileExpr	    : LPAREN Expr RPAREN
                {
                    //printf("<WhileExpr> -> <LP> <Expr> <RP>\n");
                }
                ;

WhileToken	    : WHILE
                {
                    //printf("<WhileToken> -> <WHILE>\n");
                }
                ;

IOStatement     : READ LPAREN STRING COMMA ADDR Variable RPAREN SEMICOLON
                {
                    printf("\tleaq .string_const%d(%rip), %rdi\n",strConst);
                    printf("\tleaq _gp(%rip), %rbx\n");
                    printf("\taddq $4, %rbx\n");
                    printf("\tmovq %rbx, %rsi\n");
                    printf("\tmovl $0, %s\n", "\%eax");
                    printf("\tcall scanf@PLT");
                    //int t;
                    //scanf($3, &t);
                    //setValue($6, t);
                    //printf("<IOStatement> -> <READ> <LP> <STRING> <COMMA> <ADDR> <Variable> <RP> <SC>\n");
                }
                | WRITE LPAREN STRING COMMA Expr RPAREN SEMICOLON
                {
                    printf("\tleaq .str_const%d(\%rip), \%rdi\n",strConst);
                    printf("\tmovl %s, %s\n", getIntegerRegesterName($5),"%esi");
                    printf("\tmovl $0, %s\n","%eax");
                    printf("\tcall printf@PLT\n");
                    strConst++;



                    //char *fmt = replaceNewline($3);
                    //printf(fmt, $5);
                    //free(fmt);
                    //free($3);
                    //printf("<IOStatement> -> <WRITE> <LP> <STRING> <COMMA> <Expr> <RP> <SC>\n");

                }
                | WRITE LPAREN StringConstant RPAREN SEMICOLON
                {
                    printf("\tleaq .str_const%d(\%rip), \%rdi\n",strConst);
                    printf("\tmovl $0, %s\n", "%eax");
                    printf("\tcall printf@PLT\n");
                    strConst++;
                    //char * s = $3;
                    //char *fmt = replaceNewline(s);
                    //printf(fmt);
                    //free(fmt);
                    //free($3);
                    //printf("<IOStatement> -> <WRITE> <LP> <StringConstant> <RP> <SC>\n");
                }
                ;

ReturnStatement : RETURN Expr SEMICOLON
                {
                    //printf("<ReturnStatement> -> <RETURN> <Expr> <SC>\n");
                }
                ;

ExitStatement 	: EXIT SEMICOLON
                {
                    //printf("<ExitStatement> -> <EXIT> <SC>\n");
                }
                ;

CompoundStatement : LBRACE StatementList RBRACE
                  {
                    //printf("<CompoundStatement> -> <LBR> <StatementList> <RBR>\n");
                  }
                  ;

StatementList   : Statement
                {
                    //printf("<StatementList> -> <Statement>\n");
                }
                | StatementList Statement
                {
                    //printf("<StatementList> -> <StatementList> <Statement>\n");
                }
                ;

Expr            : SimpleExpr
                {
                    $$ = $1;
                    //$$ = emitLoadIm($1);
                    //printf("<Expr> -> <SimpleExpr>\n");
                }
                | Expr OR SimpleExpr
                {
                    //$$ = ($1 || $3);
                    //printf("<Expr> -> <Expr> <OR> <SimpleExpr> \n");
                }
                | Expr AND SimpleExpr
                {
                    $$ = ($1 && $3);
                    //printf("<Expr> -> <Expr> <AND> <SimpleExpr> \n");
                }
                | NOT SimpleExpr
                {
                    $$ = (!$2);
                    //printf("<Expr> -> <NOT> <SimpleExpr> \n");
                }
                ;

SimpleExpr	    : AddExpr
                {
                    $$ = $1;
                    //$$ = emitLoadIm($1);
                    //printf("<SimpleExpr> -> <AddExpr>\n");
                }
                | SimpleExpr EQ AddExpr
                {
                    $$ = ($1 == $3);
                    //printf("<SimpleExpr> -> <SimpleExpr> <EQ> <AddExpr> \n");
                }
                | SimpleExpr NE AddExpr
                {
                    $$ = ($1 != $3);
                    //printf("<SimpleExpr> -> <SimpleExpr> <NE> <AddExpr> \n");
                }
                | SimpleExpr LE AddExpr
                {
                    $$ = ($1 <= $3);
                    //printf("<SimpleExpr> -> <SimpleExpr> <LE> <AddExpr> \n");
                }
                | SimpleExpr LT AddExpr
                {
                    $$ = ($1 < $3);
                    //printf("<SimpleExpr> -> <SimpleExpr> <LT> <AddExpr> \n");
                }
                | SimpleExpr GE AddExpr
                {
                    $$ = ($1 >= $3);
                    //printf("<SimpleExpr> -> <SimpleExpr> <GE> <AddExpr> \n");
                }
                | SimpleExpr GT AddExpr
                {
                    //printf("<SimpleExpr> -> <SimpleExpr> <GT> <AddExpr> \n");
                    $$ = ($1 > $3);
                }
                ;

AddExpr		    :  MulExpr
                {
                    $$ = $1;
                    //printf("<AddExpr> -> <MulExpr>\n");
                }
                |  AddExpr PLUS MulExpr
                {
                    //$$ = $1 + $3;
                    $$ = emitAddition($3, $1);
                    //printf("<AddExpr> -> <AddExpr> <PLUS> <MulExpr> \n");
                }
                |  AddExpr MINUS MulExpr
                {
                    //$$ = $1 - $3;
                    $$ = emitSubtraction($3,$1);
                    //printf("<AddExpr> -> <AddExpr> <MINUS> <MulExpr> \n");
                }
                ;

MulExpr		    :  Factor
                {
                    $$ = $1;
                    //printf("<MulExpr> -> <Factor>\n");
                }
                |  MulExpr TIMES Factor
                {
                    $$ = emitMultiplication($3,$1);
                    //printf("<MulExpr> -> <MulExpr> <TIMES> <Factor> \n");
                }
                |  MulExpr DIVIDE Factor
                {
                    $$ = emitDivision(getValue($3),getValue($1), $1);
                    //printf("<MulExpr> -> <MulExpr> <DIVIDE> <Factor> \n");
                }
                ;

Factor          : Variable
                {
                    $$ = getValue($1);
                    //printf("<Factor> -> <Variable>\n");
                }
                | Constant
                {
                    $$ = emitLoadIm($1);
                }
                | IDENTIFIER LPAREN RPAREN
                {
                    //printf("<Factor> -> <IDENTIFIER> <LP> <RP>\n");
                }
                | LPAREN Expr RPAREN
                {
                    $$ = $2;
                    //printf("<Factor> -> <LP> <Expr> <RP>\n");
                }
                ;

Variable        : IDENTIFIER
                {
                    $$ = $1;
                    //printf("<Variable> -> <IDENTIFIER>\n");
                }
                | IDENTIFIER LBRACKET Expr RBRACKET
                {
                    //printf("<Variable> -> <IDENTIFIER> <LBK> <Expr> <RBK>\n");
                }
                ;

StringConstant 	: STRING
                {
                    $$ = $1;
                    //printf("\t.string_const%d: .string %s", strConst, getValue($1));
                    //printf("<StringConstant> -> <STRING>\n");
                }
                ;

Constant        : INTCON
                {
                    $$ = $1;
                    //printf("<Constant> -> <INTCON>\n");
                }
                ;

%%


/********************C ROUTINES *********************************/

void yyerror(const char *s)
{
  fprintf(stderr,"%s: line %d: %s\n",fileName,yylineno,s);
}

int yywrap() {
    return 1;
}

static void initialize(char* inputFileName) {
    yyin = fopen(inputFileName,"r");
        if (yyin == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",inputFileName);
          exit(-1);
        }

    char* dotChar = rindex(inputFileName,'.');
    int endIndex = strlen(inputFileName) - strlen(dotChar);

char *outputFileName = nssave(2,substr(inputFileName,0,endIndex),".s");
    stdout = freopen(outputFileName,"w",stdout);
        if (stdout == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",outputFileName);
          exit(-1);
    }

symtab = SymInit(SYMTABLE_SIZE);
    SymInitField(symtab,SYMTAB_VALUE_FIELD,(Generic)-1,NULL);
}

static void finalize() {
    SymKillField(symtab,SYMTAB_VALUE_FIELD);
    SymKill(symtab);
    fclose(yyin);
    fclose(stdout);  //uncomment this line for Project 2
}

int main(int argc, char** argv)

{

    fileName = argv[1];
    initialize(fileName);
    initReg();

    yyparse();

    finalize();

    return 0;
}

/**
 *
 * retrieve the value of a key
 *
 * @param name a C character string which is a key
 * @return the value of the key
 */
static int getValue(char *name)
{
  return (int)SymGetField(symtab, name, SYMTAB_VALUE_FIELD);
}

/**
 *
 * retrieve the value of a key
 *
 * @param name a C character string which is a key
 * @param value the value of the key
 */
static void setValue(char *name, int value)
{
  SymPutField(symtab, name, SYMTAB_VALUE_FIELD, (Generic)value);
}
/******************END OF C ROUTINES**********************/
