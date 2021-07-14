/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "CminusParser.y"

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

#line 108 "CminusParser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "CminusParser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AND = 3,                        /* AND  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_EXIT = 5,                       /* EXIT  */
  YYSYMBOL_FOR = 6,                        /* FOR  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_INTEGER = 8,                    /* INTEGER  */
  YYSYMBOL_NOT = 9,                        /* NOT  */
  YYSYMBOL_OR = 10,                        /* OR  */
  YYSYMBOL_READ = 11,                      /* READ  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_WRITE = 13,                     /* WRITE  */
  YYSYMBOL_LBRACE = 14,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 15,                    /* RBRACE  */
  YYSYMBOL_LE = 16,                        /* LE  */
  YYSYMBOL_LT = 17,                        /* LT  */
  YYSYMBOL_GE = 18,                        /* GE  */
  YYSYMBOL_GT = 19,                        /* GT  */
  YYSYMBOL_EQ = 20,                        /* EQ  */
  YYSYMBOL_NE = 21,                        /* NE  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_COMMA = 23,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 24,                 /* SEMICOLON  */
  YYSYMBOL_LBRACKET = 25,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 26,                  /* RBRACKET  */
  YYSYMBOL_LPAREN = 27,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 28,                    /* RPAREN  */
  YYSYMBOL_PLUS = 29,                      /* PLUS  */
  YYSYMBOL_TIMES = 30,                     /* TIMES  */
  YYSYMBOL_IDENTIFIER = 31,                /* IDENTIFIER  */
  YYSYMBOL_DIVIDE = 32,                    /* DIVIDE  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_STRING = 34,                    /* STRING  */
  YYSYMBOL_INTCON = 35,                    /* INTCON  */
  YYSYMBOL_MINUS = 36,                     /* MINUS  */
  YYSYMBOL_INCLUDE = 37,                   /* INCLUDE  */
  YYSYMBOL_HEADERSTRING = 38,              /* HEADERSTRING  */
  YYSYMBOL_ADDR = 39,                      /* ADDR  */
  YYSYMBOL_DIVDE = 40,                     /* DIVDE  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_Program = 42,                   /* Program  */
  YYSYMBOL_Headers = 43,                   /* Headers  */
  YYSYMBOL_Header = 44,                    /* Header  */
  YYSYMBOL_Programbody = 45,               /* Programbody  */
  YYSYMBOL_Procedures = 46,                /* Procedures  */
  YYSYMBOL_ProcedureDecl = 47,             /* ProcedureDecl  */
  YYSYMBOL_ProcedureHead = 48,             /* ProcedureHead  */
  YYSYMBOL_FunctionDecl = 49,              /* FunctionDecl  */
  YYSYMBOL_ProcedureBody = 50,             /* ProcedureBody  */
  YYSYMBOL_DeclList = 51,                  /* DeclList  */
  YYSYMBOL_IdentifierList = 52,            /* IdentifierList  */
  YYSYMBOL_VarDecl = 53,                   /* VarDecl  */
  YYSYMBOL_Type = 54,                      /* Type  */
  YYSYMBOL_Statement = 55,                 /* Statement  */
  YYSYMBOL_Assignment = 56,                /* Assignment  */
  YYSYMBOL_IfStatement = 57,               /* IfStatement  */
  YYSYMBOL_TestAndThen = 58,               /* TestAndThen  */
  YYSYMBOL_Test = 59,                      /* Test  */
  YYSYMBOL_WhileStatement = 60,            /* WhileStatement  */
  YYSYMBOL_WhileExpr = 61,                 /* WhileExpr  */
  YYSYMBOL_WhileToken = 62,                /* WhileToken  */
  YYSYMBOL_IOStatement = 63,               /* IOStatement  */
  YYSYMBOL_ReturnStatement = 64,           /* ReturnStatement  */
  YYSYMBOL_ExitStatement = 65,             /* ExitStatement  */
  YYSYMBOL_CompoundStatement = 66,         /* CompoundStatement  */
  YYSYMBOL_StatementList = 67,             /* StatementList  */
  YYSYMBOL_Expr = 68,                      /* Expr  */
  YYSYMBOL_SimpleExpr = 69,                /* SimpleExpr  */
  YYSYMBOL_AddExpr = 70,                   /* AddExpr  */
  YYSYMBOL_MulExpr = 71,                   /* MulExpr  */
  YYSYMBOL_Factor = 72,                    /* Factor  */
  YYSYMBOL_Variable = 73,                  /* Variable  */
  YYSYMBOL_StringConstant = 74,            /* StringConstant  */
  YYSYMBOL_Constant = 75                   /* Constant  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   149

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   102,   102,   106,   112,   117,   123,   130,   134,   140,
     145,   151,   157,   161,   167,   173,   180,   185,   192,   197,
     203,   208,   214,   220,   224,   228,   232,   236,   240,   244,
     250,   262,   266,   273,   279,   286,   292,   298,   304,   317,
     334,   349,   355,   361,   367,   371,   377,   383,   388,   393,
     400,   406,   411,   416,   421,   426,   431,   438,   443,   449,
     457,   462,   467,   474,   479,   483,   487,   494,   499,   505,
     513
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "AND", "ELSE", "EXIT",
  "FOR", "IF", "INTEGER", "NOT", "OR", "READ", "WHILE", "WRITE", "LBRACE",
  "RBRACE", "LE", "LT", "GE", "GT", "EQ", "NE", "ASSIGN", "COMMA",
  "SEMICOLON", "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "PLUS", "TIMES",
  "IDENTIFIER", "DIVIDE", "RETURN", "STRING", "INTCON", "MINUS", "INCLUDE",
  "HEADERSTRING", "ADDR", "DIVDE", "$accept", "Program", "Headers",
  "Header", "Programbody", "Procedures", "ProcedureDecl", "ProcedureHead",
  "FunctionDecl", "ProcedureBody", "DeclList", "IdentifierList", "VarDecl",
  "Type", "Statement", "Assignment", "IfStatement", "TestAndThen", "Test",
  "WhileStatement", "WhileExpr", "WhileToken", "IOStatement",
  "ReturnStatement", "ExitStatement", "CompoundStatement", "StatementList",
  "Expr", "SimpleExpr", "AddExpr", "MulExpr", "Factor", "Variable",
  "StringConstant", "Constant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
#endif

#define YYPACT_NINF (-54)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -4,   -54,   -26,    26,    -4,   -54,   -54,   -54,    34,    59,
      34,    34,    54,   -54,   -54,   -54,   -54,   -54,    58,    33,
      67,    70,   -54,    89,    59,    75,    47,   -54,   -54,   -54,
     -54,   -54,    92,   -54,   -54,   -54,   -54,    36,   100,    34,
      94,   -54,    54,    27,    -6,   -54,    96,   -54,    47,   122,
     113,    95,    97,    48,    47,    64,    47,    61,   -54,    11,
      88,    -7,    66,   -54,   -54,   -54,    47,    59,   -54,   -54,
      47,    94,   103,     7,    98,   102,    94,   -54,    17,   113,
     -54,   109,   111,   107,   -54,    77,    88,    65,   108,    64,
      64,   -54,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    73,   -54,    22,   -54,   112,   123,   -54,   -54,
     -54,   101,    47,   115,   -54,   -54,   -54,    88,    88,    -7,
      -7,    -7,    -7,    -7,    -7,    66,    66,   -54,   -54,   -54,
     -54,   -54,   -54,   110,    74,   -54,   114,   119,   120,   -54,
     -54
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      10,    22,     0,     0,    10,     5,     3,     7,    10,     0,
      13,    10,     0,     6,     1,     4,     2,     9,     0,     0,
       0,     0,    37,     0,     0,    67,     0,    11,    44,    23,
      24,    25,     0,    26,    27,    28,    29,     0,     0,    12,
       0,     8,     0,    20,     0,    18,     0,    42,     0,    32,
       0,     0,     0,     0,     0,     0,     0,    67,    70,     0,
      46,    50,    57,    60,    63,    64,     0,     0,    15,    45,
       0,     0,    20,     0,     0,     0,     0,    16,     0,     0,
      33,     0,    69,     0,    43,     0,    49,     0,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     0,    17,     0,     0,    19,    34,
      31,     0,     0,     0,    68,    66,    65,    48,    47,    53,
      54,    55,    56,    51,    52,    58,    59,    61,    62,    36,
      30,    21,    14,     0,     0,    40,     0,     0,     0,    39,
      38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -54,   -54,   -54,   141,   142,     5,   -54,   -54,   -54,   -54,
     137,   -32,    72,    -5,   -29,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -39,   125,   -47,   -53,    18,
      19,    20,    -9,   -54,   -54
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    27,
      11,    44,    45,    12,    28,    29,    30,    49,    50,    31,
      67,    32,    33,    34,    35,    36,    37,    59,    60,    61,
      62,    63,    64,    83,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      38,    78,    86,    18,     1,    40,    42,    85,    69,    87,
      73,    80,    13,    17,    89,    38,    41,    76,    77,   102,
      89,    90,    98,   104,    69,    89,    14,    90,    38,    99,
      76,   105,    90,     2,    71,    91,   117,   118,   103,    73,
     110,    19,     1,    20,    38,   109,   130,    21,    22,    23,
      24,    68,    74,    19,    75,    20,    55,    47,    38,    21,
      22,    23,    24,    84,    19,   134,    20,    25,    89,    26,
      21,    22,    23,    24,    56,    90,    89,    89,    57,    25,
      89,    26,    58,    90,    90,    43,    54,    90,    88,    46,
      25,    56,    26,   115,    48,    57,   100,    51,   101,    58,
      54,   129,   137,   114,    92,    93,    94,    95,    96,    97,
     119,   120,   121,   122,   123,   124,    52,   125,   126,    66,
     127,   128,    70,    75,   136,    72,    79,    24,    74,    81,
     107,    82,   111,   106,   112,   113,   116,   132,   131,   135,
     133,    25,   138,   139,   140,    15,    16,    39,   108,    53
};

static const yytype_uint8 yycheck[] =
{
       9,    48,    55,     8,     8,    10,    11,    54,    37,    56,
      42,    50,    38,     8,     3,    24,    11,    23,    24,    66,
       3,    10,    29,    70,    53,     3,     0,    10,    37,    36,
      23,    24,    10,    37,    39,    24,    89,    90,    67,    71,
      79,     5,     8,     7,    53,    28,    24,    11,    12,    13,
      14,    15,    25,     5,    27,     7,     9,    24,    67,    11,
      12,    13,    14,    15,     5,   112,     7,    31,     3,    33,
      11,    12,    13,    14,    27,    10,     3,     3,    31,    31,
       3,    33,    35,    10,    10,    31,    25,    10,    27,    31,
      31,    27,    33,    28,    27,    31,    30,    27,    32,    35,
      25,    28,    28,    26,    16,    17,    18,    19,    20,    21,
      92,    93,    94,    95,    96,    97,    27,    98,    99,    27,
     100,   101,    22,    27,   133,    31,     4,    14,    25,    34,
      28,    34,    23,    35,    23,    28,    28,    14,    26,    24,
      39,    31,    28,    24,    24,     4,     4,    10,    76,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    37,    42,    43,    44,    45,    46,    47,    48,
      49,    51,    54,    38,     0,    44,    45,    46,    54,     5,
       7,    11,    12,    13,    14,    31,    33,    50,    55,    56,
      57,    60,    62,    63,    64,    65,    66,    67,    73,    51,
      54,    46,    54,    31,    52,    53,    31,    24,    27,    58,
      59,    27,    27,    67,    25,     9,    27,    31,    35,    68,
      69,    70,    71,    72,    73,    75,    27,    61,    15,    55,
      22,    54,    31,    52,    25,    27,    23,    24,    68,     4,
      66,    34,    34,    74,    15,    68,    69,    68,    27,     3,
      10,    24,    16,    17,    18,    19,    20,    21,    29,    36,
      30,    32,    68,    55,    68,    24,    35,    28,    53,    28,
      66,    23,    23,    28,    26,    28,    28,    69,    69,    70,
      70,    70,    70,    70,    70,    71,    71,    72,    72,    28,
      24,    26,    14,    39,    68,    24,    73,    28,    28,    24,
      24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    42,    43,    43,    44,    45,    45,    46,
      46,    47,    48,    48,    49,    50,    51,    51,    52,    52,
      53,    53,    54,    55,    55,    55,    55,    55,    55,    55,
      56,    57,    57,    58,    59,    60,    61,    62,    63,    63,
      63,    64,    65,    66,    67,    67,    68,    68,    68,    68,
      69,    69,    69,    69,    69,    69,    69,    70,    70,    70,
      71,    71,    71,    72,    72,    72,    72,    73,    73,    74,
      75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     2,     1,     2,     2,
       0,     2,     2,     1,     5,     2,     3,     4,     1,     3,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     2,     2,     3,     3,     3,     1,     8,     7,
       5,     3,     2,     3,     1,     2,     1,     3,     3,     2,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     1,     3,     3,     1,     4,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: Headers Programbody  */
#line 103 "CminusParser.y"
                {
                    //printf("<Program> -> <Headers> <Programbody>\n");
                }
#line 1269 "CminusParser.c"
    break;

  case 3: /* Program: Programbody  */
#line 107 "CminusParser.y"
                {
                    //printf("<Program> -> <Programbody>\n");
                }
#line 1277 "CminusParser.c"
    break;

  case 4: /* Headers: Headers Header  */
#line 113 "CminusParser.y"
                {
                    //printf("<Headers> -> <Headers> <Header>\n");
                }
#line 1285 "CminusParser.c"
    break;

  case 5: /* Headers: Header  */
#line 118 "CminusParser.y"
                {
                    //printf("<Headers> -> <Header>\n");
                }
#line 1293 "CminusParser.c"
    break;

  case 6: /* Header: INCLUDE HEADERSTRING  */
#line 124 "CminusParser.y"
                {
                    printf("\t.section\t.rodata\n");
                    //printf("<Header> -> <INCLUDE> <HEADERSTRING>\n");
                }
#line 1302 "CminusParser.c"
    break;

  case 7: /* Programbody: Procedures  */
#line 131 "CminusParser.y"
                {
                    //printf("<Program> -> <Procedures>\n");
                }
#line 1310 "CminusParser.c"
    break;

  case 8: /* Programbody: DeclList Procedures  */
#line 135 "CminusParser.y"
                {
                    //printf("<Program> -> <DeclList> <Procedures>\n");
                }
#line 1318 "CminusParser.c"
    break;

  case 9: /* Procedures: ProcedureDecl Procedures  */
#line 141 "CminusParser.y"
                {
                    //printf("<Procedures> -> <ProcedureDecl> <Procedures>\n");
                }
#line 1326 "CminusParser.c"
    break;

  case 10: /* Procedures: %empty  */
#line 145 "CminusParser.y"
                {
                    printf("\tleave\n\tret\n");
                    //printf("<Procedures> -> epsilon\n");
                }
#line 1335 "CminusParser.c"
    break;

  case 11: /* ProcedureDecl: ProcedureHead ProcedureBody  */
#line 152 "CminusParser.y"
                {
                    //printf("<ProcedureDecl> -> <ProcedureHead> <ProcedureBody>\n");
                }
#line 1343 "CminusParser.c"
    break;

  case 12: /* ProcedureHead: FunctionDecl DeclList  */
#line 158 "CminusParser.y"
                {
                    //printf("<ProcedureHead> -> <FunctionDecl> <DeclList>\n");
                }
#line 1351 "CminusParser.c"
    break;

  case 13: /* ProcedureHead: FunctionDecl  */
#line 162 "CminusParser.y"
                {
                    //printf("<ProcedureHead> -> <FunctionDecl>\n");
                }
#line 1359 "CminusParser.c"
    break;

  case 14: /* FunctionDecl: Type IDENTIFIER LPAREN RPAREN LBRACE  */
#line 168 "CminusParser.y"
                {
                    printf("\t.text\n\t.globl main\n\t.type main, @function\nmain:\tnop\n\tpushq %rbp\n\tmovq %rsp, %rbp\n");
                }
#line 1367 "CminusParser.c"
    break;

  case 15: /* ProcedureBody: StatementList RBRACE  */
#line 174 "CminusParser.y"
                {
                    //printf("<ProcedureBody> -> <StatementList> <RBR>\n");
                }
#line 1375 "CminusParser.c"
    break;

  case 16: /* DeclList: Type IdentifierList SEMICOLON  */
#line 181 "CminusParser.y"
                {
                    printf("\t.comm _gp, %d, %d\n", ids*4, ids);
                    //printf("<DeclList> -> <Type> <IdentifierList> <SC>\n");
                }
#line 1384 "CminusParser.c"
    break;

  case 17: /* DeclList: DeclList Type IdentifierList SEMICOLON  */
#line 186 "CminusParser.y"
                {
                    printf("<DeclList> -> <DeclList> <Type> <IdentifierList> <SC>\n");
                }
#line 1392 "CminusParser.c"
    break;

  case 18: /* IdentifierList: VarDecl  */
#line 193 "CminusParser.y"
                {
                    //printf("<IdentifierList> -> <VarDecl>\n");
                }
#line 1400 "CminusParser.c"
    break;

  case 19: /* IdentifierList: IdentifierList COMMA VarDecl  */
#line 198 "CminusParser.y"
                {
                    //printf("<IdentifierList> -> <IdentifierList> <CM> <VarDecl>\n");
                }
#line 1408 "CminusParser.c"
    break;

  case 20: /* VarDecl: IDENTIFIER  */
#line 204 "CminusParser.y"
                {
                    ids++;
                    //printf("<VarDecl> -> <IDENTIFIER>\n");
                }
#line 1417 "CminusParser.c"
    break;

  case 21: /* VarDecl: IDENTIFIER LBRACKET INTCON RBRACKET  */
#line 209 "CminusParser.y"
                {
                    //printf("<VarDecl> -> <IDENTIFIER> <LBK> <INTCON> <RBK>\n");
                }
#line 1425 "CminusParser.c"
    break;

  case 22: /* Type: INTEGER  */
#line 215 "CminusParser.y"
                {
                    //printf("<Type> -> <INTEGER>\n");
                }
#line 1433 "CminusParser.c"
    break;

  case 23: /* Statement: Assignment  */
#line 221 "CminusParser.y"
                {
                    //printf("<Statement> -> <Assignment>\n");
                }
#line 1441 "CminusParser.c"
    break;

  case 24: /* Statement: IfStatement  */
#line 225 "CminusParser.y"
                {
                    //printf("<Statement> -> <IfStatement>\n");
                }
#line 1449 "CminusParser.c"
    break;

  case 25: /* Statement: WhileStatement  */
#line 229 "CminusParser.y"
                {
                    //printf("<Statement> -> <WhileStatement>\n");
                }
#line 1457 "CminusParser.c"
    break;

  case 26: /* Statement: IOStatement  */
#line 233 "CminusParser.y"
                {
                    //printf("<Statement> -> <IOStatement>\n");
                }
#line 1465 "CminusParser.c"
    break;

  case 27: /* Statement: ReturnStatement  */
#line 237 "CminusParser.y"
                {
                    //printf("<Statement> -> <ReturnStatement>\n");
                }
#line 1473 "CminusParser.c"
    break;

  case 28: /* Statement: ExitStatement  */
#line 241 "CminusParser.y"
                {
                    //printf("<Statement> -> <ExitStatement>\n");
                }
#line 1481 "CminusParser.c"
    break;

  case 29: /* Statement: CompoundStatement  */
#line 245 "CminusParser.y"
                {
                    //printf("<Statement> -> <CompoundStatement>\n");
                }
#line 1489 "CminusParser.c"
    break;

  case 30: /* Assignment: Variable ASSIGN Expr SEMICOLON  */
#line 251 "CminusParser.y"
                {
                  setValue((yyvsp[-3].name), (yyvsp[-1].val));
                  printf("\tleaq _gp(&rip), %rbx\n");
                  printf("\taddq %s, %rbx\n",offset);
                  //printf("\tmovl $1, %s\n", getIntegerRegesterName($1));
                  printf("\tmovl %s, (%rbx)\n");
                  //offset++;
                  //printf("*<Assignment> -> <Variable> <ASSIGN> <Expr> <SC>\n");
                }
#line 1503 "CminusParser.c"
    break;

  case 31: /* IfStatement: IF TestAndThen ELSE CompoundStatement  */
#line 263 "CminusParser.y"
                {
                    //printf("<IfStatement> -> <IF> <TestAndThen> <ELSE> <CompoundStatement>\n");
                }
#line 1511 "CminusParser.c"
    break;

  case 32: /* IfStatement: IF TestAndThen  */
#line 267 "CminusParser.y"
                {
                    //printf("<IfStatement> -> <IF> <TestAndThen>\n");
                }
#line 1519 "CminusParser.c"
    break;

  case 33: /* TestAndThen: Test CompoundStatement  */
#line 274 "CminusParser.y"
                {
                    //printf("<TestAndThen> -> <Test> <CompoundStatement>\n");
                }
#line 1527 "CminusParser.c"
    break;

  case 34: /* Test: LPAREN Expr RPAREN  */
#line 280 "CminusParser.y"
                {
                    //printf("<Test> -> <LP> <Expr> <RP>\n");
                }
#line 1535 "CminusParser.c"
    break;

  case 35: /* WhileStatement: WhileToken WhileExpr Statement  */
#line 287 "CminusParser.y"
                {
                    //printf("<WhileStatement> -> <WhileToken> <WhileExpr> <Statement>\n");
                }
#line 1543 "CminusParser.c"
    break;

  case 36: /* WhileExpr: LPAREN Expr RPAREN  */
#line 293 "CminusParser.y"
                {
                    //printf("<WhileExpr> -> <LP> <Expr> <RP>\n");
                }
#line 1551 "CminusParser.c"
    break;

  case 37: /* WhileToken: WHILE  */
#line 299 "CminusParser.y"
                {
                    //printf("<WhileToken> -> <WHILE>\n");
                }
#line 1559 "CminusParser.c"
    break;

  case 38: /* IOStatement: READ LPAREN STRING COMMA ADDR Variable RPAREN SEMICOLON  */
#line 305 "CminusParser.y"
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
#line 1576 "CminusParser.c"
    break;

  case 39: /* IOStatement: WRITE LPAREN STRING COMMA Expr RPAREN SEMICOLON  */
#line 318 "CminusParser.y"
                {
                    printf("\tleaq .str_const%d(\%rip), \%rdi\n",strConst);
                    printf("\tmovl %s, %s\n", getIntegerRegesterName((yyvsp[-2].val)),"%esi");
                    printf("\tmovl $0, %s\n","%eax");
                    printf("\tcall printf@PLT\n");
                    strConst++;



                    //char *fmt = replaceNewline($3);
                    //printf(fmt, $5);
                    //free(fmt);
                    //free($3);
                    //printf("<IOStatement> -> <WRITE> <LP> <STRING> <COMMA> <Expr> <RP> <SC>\n");

                }
#line 1597 "CminusParser.c"
    break;

  case 40: /* IOStatement: WRITE LPAREN StringConstant RPAREN SEMICOLON  */
#line 335 "CminusParser.y"
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
#line 1614 "CminusParser.c"
    break;

  case 41: /* ReturnStatement: RETURN Expr SEMICOLON  */
#line 350 "CminusParser.y"
                {
                    //printf("<ReturnStatement> -> <RETURN> <Expr> <SC>\n");
                }
#line 1622 "CminusParser.c"
    break;

  case 42: /* ExitStatement: EXIT SEMICOLON  */
#line 356 "CminusParser.y"
                {
                    //printf("<ExitStatement> -> <EXIT> <SC>\n");
                }
#line 1630 "CminusParser.c"
    break;

  case 43: /* CompoundStatement: LBRACE StatementList RBRACE  */
#line 362 "CminusParser.y"
                  {
                    //printf("<CompoundStatement> -> <LBR> <StatementList> <RBR>\n");
                  }
#line 1638 "CminusParser.c"
    break;

  case 44: /* StatementList: Statement  */
#line 368 "CminusParser.y"
                {
                    //printf("<StatementList> -> <Statement>\n");
                }
#line 1646 "CminusParser.c"
    break;

  case 45: /* StatementList: StatementList Statement  */
#line 372 "CminusParser.y"
                {
                    //printf("<StatementList> -> <StatementList> <Statement>\n");
                }
#line 1654 "CminusParser.c"
    break;

  case 46: /* Expr: SimpleExpr  */
#line 378 "CminusParser.y"
                {
                    (yyval.val) = (yyvsp[0].val);
                    //$$ = emitLoadIm($1);
                    //printf("<Expr> -> <SimpleExpr>\n");
                }
#line 1664 "CminusParser.c"
    break;

  case 47: /* Expr: Expr OR SimpleExpr  */
#line 384 "CminusParser.y"
                {
                    //$$ = ($1 || $3);
                    //printf("<Expr> -> <Expr> <OR> <SimpleExpr> \n");
                }
#line 1673 "CminusParser.c"
    break;

  case 48: /* Expr: Expr AND SimpleExpr  */
#line 389 "CminusParser.y"
                {
                    (yyval.val) = ((yyvsp[-2].val) && (yyvsp[0].val));
                    //printf("<Expr> -> <Expr> <AND> <SimpleExpr> \n");
                }
#line 1682 "CminusParser.c"
    break;

  case 49: /* Expr: NOT SimpleExpr  */
#line 394 "CminusParser.y"
                {
                    (yyval.val) = (!(yyvsp[0].val));
                    //printf("<Expr> -> <NOT> <SimpleExpr> \n");
                }
#line 1691 "CminusParser.c"
    break;

  case 50: /* SimpleExpr: AddExpr  */
#line 401 "CminusParser.y"
                {
                    (yyval.val) = (yyvsp[0].val);
                    //$$ = emitLoadIm($1);
                    //printf("<SimpleExpr> -> <AddExpr>\n");
                }
#line 1701 "CminusParser.c"
    break;

  case 51: /* SimpleExpr: SimpleExpr EQ AddExpr  */
#line 407 "CminusParser.y"
                {
                    (yyval.val) = ((yyvsp[-2].val) == (yyvsp[0].val));
                    //printf("<SimpleExpr> -> <SimpleExpr> <EQ> <AddExpr> \n");
                }
#line 1710 "CminusParser.c"
    break;

  case 52: /* SimpleExpr: SimpleExpr NE AddExpr  */
#line 412 "CminusParser.y"
                {
                    (yyval.val) = ((yyvsp[-2].val) != (yyvsp[0].val));
                    //printf("<SimpleExpr> -> <SimpleExpr> <NE> <AddExpr> \n");
                }
#line 1719 "CminusParser.c"
    break;

  case 53: /* SimpleExpr: SimpleExpr LE AddExpr  */
#line 417 "CminusParser.y"
                {
                    (yyval.val) = ((yyvsp[-2].val) <= (yyvsp[0].val));
                    //printf("<SimpleExpr> -> <SimpleExpr> <LE> <AddExpr> \n");
                }
#line 1728 "CminusParser.c"
    break;

  case 54: /* SimpleExpr: SimpleExpr LT AddExpr  */
#line 422 "CminusParser.y"
                {
                    (yyval.val) = ((yyvsp[-2].val) < (yyvsp[0].val));
                    //printf("<SimpleExpr> -> <SimpleExpr> <LT> <AddExpr> \n");
                }
#line 1737 "CminusParser.c"
    break;

  case 55: /* SimpleExpr: SimpleExpr GE AddExpr  */
#line 427 "CminusParser.y"
                {
                    (yyval.val) = ((yyvsp[-2].val) >= (yyvsp[0].val));
                    //printf("<SimpleExpr> -> <SimpleExpr> <GE> <AddExpr> \n");
                }
#line 1746 "CminusParser.c"
    break;

  case 56: /* SimpleExpr: SimpleExpr GT AddExpr  */
#line 432 "CminusParser.y"
                {
                    //printf("<SimpleExpr> -> <SimpleExpr> <GT> <AddExpr> \n");
                    (yyval.val) = ((yyvsp[-2].val) > (yyvsp[0].val));
                }
#line 1755 "CminusParser.c"
    break;

  case 57: /* AddExpr: MulExpr  */
#line 439 "CminusParser.y"
                {
                    (yyval.val) = (yyvsp[0].val);
                    //printf("<AddExpr> -> <MulExpr>\n");
                }
#line 1764 "CminusParser.c"
    break;

  case 58: /* AddExpr: AddExpr PLUS MulExpr  */
#line 444 "CminusParser.y"
                {
                    //$$ = $1 + $3;
                    (yyval.val) = emitAddition((yyvsp[0].val), (yyvsp[-2].val));
                    //printf("<AddExpr> -> <AddExpr> <PLUS> <MulExpr> \n");
                }
#line 1774 "CminusParser.c"
    break;

  case 59: /* AddExpr: AddExpr MINUS MulExpr  */
#line 450 "CminusParser.y"
                {
                    //$$ = $1 - $3;
                    (yyval.val) = emitSubtraction((yyvsp[0].val),(yyvsp[-2].val));
                    //printf("<AddExpr> -> <AddExpr> <MINUS> <MulExpr> \n");
                }
#line 1784 "CminusParser.c"
    break;

  case 60: /* MulExpr: Factor  */
#line 458 "CminusParser.y"
                {
                    (yyval.val) = (yyvsp[0].val);
                    //printf("<MulExpr> -> <Factor>\n");
                }
#line 1793 "CminusParser.c"
    break;

  case 61: /* MulExpr: MulExpr TIMES Factor  */
#line 463 "CminusParser.y"
                {
                    (yyval.val) = emitMultiplication((yyvsp[0].val),(yyvsp[-2].val));
                    //printf("<MulExpr> -> <MulExpr> <TIMES> <Factor> \n");
                }
#line 1802 "CminusParser.c"
    break;

  case 62: /* MulExpr: MulExpr DIVIDE Factor  */
#line 468 "CminusParser.y"
                {
                    (yyval.val) = emitDivision(getValue((yyvsp[0].val)),getValue((yyvsp[-2].val)), (yyvsp[-2].val));
                    //printf("<MulExpr> -> <MulExpr> <DIVIDE> <Factor> \n");
                }
#line 1811 "CminusParser.c"
    break;

  case 63: /* Factor: Variable  */
#line 475 "CminusParser.y"
                {
                    (yyval.val) = getValue((yyvsp[0].name));
                    //printf("<Factor> -> <Variable>\n");
                }
#line 1820 "CminusParser.c"
    break;

  case 64: /* Factor: Constant  */
#line 480 "CminusParser.y"
                {
                    (yyval.val) = emitLoadIm((yyvsp[0].val));
                }
#line 1828 "CminusParser.c"
    break;

  case 65: /* Factor: IDENTIFIER LPAREN RPAREN  */
#line 484 "CminusParser.y"
                {
                    //printf("<Factor> -> <IDENTIFIER> <LP> <RP>\n");
                }
#line 1836 "CminusParser.c"
    break;

  case 66: /* Factor: LPAREN Expr RPAREN  */
#line 488 "CminusParser.y"
                {
                    (yyval.val) = (yyvsp[-1].val);
                    //printf("<Factor> -> <LP> <Expr> <RP>\n");
                }
#line 1845 "CminusParser.c"
    break;

  case 67: /* Variable: IDENTIFIER  */
#line 495 "CminusParser.y"
                {
                    (yyval.name) = (yyvsp[0].name);
                    //printf("<Variable> -> <IDENTIFIER>\n");
                }
#line 1854 "CminusParser.c"
    break;

  case 68: /* Variable: IDENTIFIER LBRACKET Expr RBRACKET  */
#line 500 "CminusParser.y"
                {
                    //printf("<Variable> -> <IDENTIFIER> <LBK> <Expr> <RBK>\n");
                }
#line 1862 "CminusParser.c"
    break;

  case 69: /* StringConstant: STRING  */
#line 506 "CminusParser.y"
                {
                    (yyval.name) = (yyvsp[0].name);
                    //printf("\t.string_const%d: .string %s", strConst, getValue($1));
                    //printf("<StringConstant> -> <STRING>\n");
                }
#line 1872 "CminusParser.c"
    break;

  case 70: /* Constant: INTCON  */
#line 514 "CminusParser.y"
                {
                    (yyval.val) = (yyvsp[0].val);
                    //printf("<Constant> -> <INTCON>\n");
                }
#line 1881 "CminusParser.c"
    break;


#line 1885 "CminusParser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 520 "CminusParser.y"



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
