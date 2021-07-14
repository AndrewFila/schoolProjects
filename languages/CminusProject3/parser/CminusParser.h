/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_CMINUSPARSER_H_INCLUDED
# define YY_YY_CMINUSPARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    AND = 258,                     /* AND  */
    ELSE = 259,                    /* ELSE  */
    EXIT = 260,                    /* EXIT  */
    FLOAT = 261,                   /* FLOAT  */
    FOR = 262,                     /* FOR  */
    IF = 263,                      /* IF  */
    INTEGER = 264,                 /* INTEGER  */
    NOT = 265,                     /* NOT  */
    OR = 266,                      /* OR  */
    READ = 267,                    /* READ  */
    WHILE = 268,                   /* WHILE  */
    WRITE = 269,                   /* WRITE  */
    LBRACE = 270,                  /* LBRACE  */
    RBRACE = 271,                  /* RBRACE  */
    LE = 272,                      /* LE  */
    LT = 273,                      /* LT  */
    GE = 274,                      /* GE  */
    GT = 275,                      /* GT  */
    EQ = 276,                      /* EQ  */
    NE = 277,                      /* NE  */
    ASSIGN = 278,                  /* ASSIGN  */
    COMMA = 279,                   /* COMMA  */
    SEMICOLON = 280,               /* SEMICOLON  */
    LBRACKET = 281,                /* LBRACKET  */
    RBRACKET = 282,                /* RBRACKET  */
    LPAREN = 283,                  /* LPAREN  */
    RPAREN = 284,                  /* RPAREN  */
    PLUS = 285,                    /* PLUS  */
    TIMES = 286,                   /* TIMES  */
    IDENTIFIER = 287,              /* IDENTIFIER  */
    DIVIDE = 288,                  /* DIVIDE  */
    RETURN = 289,                  /* RETURN  */
    STRING = 290,                  /* STRING  */
    INTCON = 291,                  /* INTCON  */
    MINUS = 292,                   /* MINUS  */
    INCLUDE = 293,                 /* INCLUDE  */
    HEADERSTRING = 294,            /* HEADERSTRING  */
    ADDR = 295,                    /* ADDR  */
    DIVDE = 296                    /* DIVDE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 96 "CminusParser.y"

    char*	name;
    int     regIndex;
    int     labelIndex;
    int 	offset;

#line 112 "CminusParser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CMINUSPARSER_H_INCLUDED  */
