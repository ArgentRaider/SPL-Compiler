
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "SPL_parse.y"

	#define YYERROR_VERBOSE 1

	#include <stdio.h>
	#include <string.h>
	#include <time.h>
	#include "errormsg.h"
	#include "symbol.h"
	#include "type.h"
	#include "absyn.h"
	A_pro root = NULL;


/* Line 189 of yacc.c  */
#line 87 "SPL_parse.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_STRING = 258,
     T_NAME = 259,
     T_INTEGER = 260,
     T_BOOLEAN = 261,
     T_REAL = 262,
     T_CHAR = 263,
     T_SYS_CON = 264,
     T_SYS_FUNCT = 265,
     T_SYS_PROC = 266,
     T_SYS_TYPE = 267,
     T_READ = 268,
     T_AND = 269,
     T_ARRAY = 270,
     T_BEGIN = 271,
     T_CASE = 272,
     T_CONST = 273,
     T_DIV = 274,
     T_DO = 275,
     T_DOWNTO = 276,
     T_ELSE = 277,
     T_END = 278,
     T_FOR = 279,
     T_FUNCTION = 280,
     T_GOTO = 281,
     T_IF = 282,
     T_IN = 283,
     T_MOD = 284,
     T_NOT = 285,
     T_OF = 286,
     T_OR = 287,
     T_PACKED = 288,
     T_PROCEDURE = 289,
     T_PROGRAM = 290,
     T_RECORD = 291,
     T_REPEAT = 292,
     T_SET = 293,
     T_THEN = 294,
     T_TO = 295,
     T_TYPE = 296,
     T_UNTIL = 297,
     T_VAR = 298,
     T_WHILE = 299,
     T_WITH = 300,
     T_LP = 301,
     T_RP = 302,
     T_LB = 303,
     T_RB = 304,
     T_DOT = 305,
     T_COMMA = 306,
     T_COLON = 307,
     T_MUL = 308,
     T_UNEQUAL = 309,
     T_PLUS = 310,
     T_MINUS = 311,
     T_GE = 312,
     T_GT = 313,
     T_LE = 314,
     T_LT = 315,
     T_EQUAL = 316,
     T_ASSIGN = 317,
     T_DOTDOT = 318,
     T_SEMI = 319
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 14 "SPL_parse.y"

	int ival;
	double fval;
	char cval;
	char* sval;
	enum SYS_CON{SYS_CON_FALSE, SYS_CON_TRUE, SYS_CON_MAXINT} conval;
	enum SYS_FUNCT{SYS_FUNCT_ABS, SYS_FUNCT_CHR, SYS_FUNCT_ODD, 
		SYS_FUNCT_ORD, SYS_FUNCT_PRED, SYS_FUNCT_SQR, SYS_FUNCT_SQRT, SYS_FUNCT_SUCC} functval;
	enum SYS_PROC{SYS_PROC_WRITE, SYS_PROC_WRITELN} procval;
	SysType typeval;
	
	A_pro a_prog;
	S_symbol s_symbol;
	A_routine a_routine;
	A_routineHead a_routineHead;
	A_stmtList a_stmtList;
	A_decList a_decList;
	A_dec a_dec;
	A_const a_constval;
	A_type a_type;
	A_simple a_simple;
	A_array a_array;
	A_fieldList a_fieldList;
	A_nameList a_nameList;
	A_range a_range;
	A_field a_field;
	A_varDecList a_varDecList;
	A_routinePartHead a_routinePartHead;
	A_paraList a_paraList;
	A_paraField a_paraField;
	A_stmt a_stmt;
	A_exp a_exp;
	A_caseList a_caseList;
	A_case a_case;
	A_expList a_expList;



/* Line 214 of yacc.c  */
#line 226 "SPL_parse.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 251 "SPL_parse.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   361

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNRULES -- Number of states.  */
#define YYNSTATES  266

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    13,    16,    19,    25,    26,
      29,    30,    33,    35,    40,    42,    44,    46,    48,    50,
      53,    54,    57,    59,    64,    66,    68,    70,    72,    74,
      78,    85,    89,    94,   100,   104,   108,   111,   113,   118,
     122,   124,   127,   128,   131,   133,   138,   141,   144,   146,
     148,   149,   154,   160,   165,   169,   173,   174,   178,   180,
     184,   188,   191,   193,   195,   199,   203,   204,   208,   210,
     212,   214,   216,   218,   220,   222,   224,   226,   228,   232,
     239,   245,   247,   249,   254,   259,   264,   270,   273,   274,
     279,   284,   293,   295,   297,   303,   306,   308,   313,   318,
     321,   325,   327,   331,   335,   339,   343,   347,   351,   353,
     357,   361,   365,   367,   371,   375,   379,   383,   385,   387,
     392,   394,   399,   401,   405,   408,   411,   416,   420,   422,
     424,   426,   428
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      66,     0,    -1,    67,    -1,    68,    69,    50,    -1,    35,
     123,    64,    -1,    71,   101,    -1,    71,   101,    -1,    72,
      73,    77,    88,    91,    -1,    -1,    18,    74,    -1,    -1,
      74,    75,    -1,    75,    -1,     4,    61,    76,    64,    -1,
       5,    -1,     7,    -1,     8,    -1,     3,    -1,     9,    -1,
      41,    78,    -1,    -1,    78,    79,    -1,    79,    -1,     4,
      61,    80,    64,    -1,    81,    -1,    82,    -1,    84,    -1,
      12,    -1,     4,    -1,    46,    87,    47,    -1,    15,    48,
      83,    49,    31,    80,    -1,    76,    63,    76,    -1,    56,
      76,    63,    76,    -1,    56,    76,    63,    56,    76,    -1,
       4,    63,     4,    -1,    36,    85,    23,    -1,    85,    86,
      -1,    86,    -1,    87,    52,    80,    64,    -1,    87,    51,
     123,    -1,   123,    -1,    43,    89,    -1,    -1,    89,    90,
      -1,    90,    -1,    87,    52,    80,    64,    -1,    91,    92,
      -1,    91,    94,    -1,    92,    -1,    94,    -1,    -1,    93,
      64,    70,    64,    -1,    25,     4,    96,    52,    81,    -1,
      95,    64,    70,    64,    -1,    34,     4,    96,    -1,    46,
      97,    47,    -1,    -1,    97,    64,    98,    -1,    98,    -1,
      99,    52,    81,    -1,   100,    52,    81,    -1,    43,    87,
      -1,    87,    -1,   102,    -1,    16,   103,    23,    -1,   104,
      64,   103,    -1,    -1,     5,    52,   105,    -1,   105,    -1,
     106,    -1,   107,    -1,   102,    -1,   108,    -1,   110,    -1,
     111,    -1,   112,    -1,   114,    -1,   117,    -1,   123,    62,
     119,    -1,   123,    48,   119,    49,    62,   119,    -1,   123,
      50,   123,    62,   119,    -1,    11,    -1,   123,    -1,   123,
      46,   118,    47,    -1,    11,    46,   118,    47,    -1,    13,
      46,   122,    47,    -1,    27,   119,    39,   104,   109,    -1,
      22,   104,    -1,    -1,    37,   103,    42,   119,    -1,    44,
     119,    20,   104,    -1,    24,   123,    62,   119,   113,   119,
      20,   104,    -1,    40,    -1,    21,    -1,    17,   119,    31,
     115,    23,    -1,   115,   116,    -1,   116,    -1,    76,    52,
     104,    64,    -1,   123,    52,   104,    64,    -1,    26,     5,
      -1,   118,    51,   119,    -1,   119,    -1,   119,    57,   120,
      -1,   119,    58,   120,    -1,   119,    59,   120,    -1,   119,
      60,   120,    -1,   119,    61,   120,    -1,   119,    54,   120,
      -1,   120,    -1,   120,    55,   121,    -1,   120,    56,   121,
      -1,   120,    32,   121,    -1,   121,    -1,   121,    53,   122,
      -1,   121,    19,   122,    -1,   121,    29,   122,    -1,   121,
      14,   122,    -1,   122,    -1,     4,    -1,     4,    46,   118,
      47,    -1,    10,    -1,    10,    46,   118,    47,    -1,    76,
      -1,    46,   119,    47,    -1,    30,   122,    -1,    56,   122,
      -1,   123,    48,   119,    49,    -1,   123,    50,   123,    -1,
       4,    -1,     9,    -1,    10,    -1,    11,    -1,    12,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   103,   103,   106,   109,   111,   113,   116,   118,   120,
     121,   123,   124,   126,   128,   129,   130,   131,   132,   140,
     141,   143,   144,   146,   148,   149,   150,   152,   153,   154,
     156,   159,   162,   167,   172,   176,   178,   179,   181,   183,
     184,   186,   187,   189,   190,   192,   194,   195,   196,   197,
     198,   200,   202,   204,   206,   208,   209,   211,   212,   214,
     215,   217,   219,   221,   223,   225,   226,   228,   229,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   241,   242,
     243,   245,   250,   251,   252,   257,   259,   261,   262,   264,
     266,   268,   270,   271,   273,   275,   276,   278,   279,   281,
     283,   284,   286,   287,   288,   289,   290,   291,   292,   294,
     295,   296,   297,   299,   300,   301,   302,   303,   305,   306,
     307,   319,   331,   332,   333,   334,   335,   336,   340,   341,
     348,   360,   366
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_STRING", "T_NAME", "T_INTEGER",
  "T_BOOLEAN", "T_REAL", "T_CHAR", "T_SYS_CON", "T_SYS_FUNCT",
  "T_SYS_PROC", "T_SYS_TYPE", "T_READ", "T_AND", "T_ARRAY", "T_BEGIN",
  "T_CASE", "T_CONST", "T_DIV", "T_DO", "T_DOWNTO", "T_ELSE", "T_END",
  "T_FOR", "T_FUNCTION", "T_GOTO", "T_IF", "T_IN", "T_MOD", "T_NOT",
  "T_OF", "T_OR", "T_PACKED", "T_PROCEDURE", "T_PROGRAM", "T_RECORD",
  "T_REPEAT", "T_SET", "T_THEN", "T_TO", "T_TYPE", "T_UNTIL", "T_VAR",
  "T_WHILE", "T_WITH", "T_LP", "T_RP", "T_LB", "T_RB", "T_DOT", "T_COMMA",
  "T_COLON", "T_MUL", "T_UNEQUAL", "T_PLUS", "T_MINUS", "T_GE", "T_GT",
  "T_LE", "T_LT", "T_EQUAL", "T_ASSIGN", "T_DOTDOT", "T_SEMI", "$accept",
  "s", "program", "program_head", "routine", "sub_routine", "routine_head",
  "label_part", "const_part", "const_expr_list", "const_dec",
  "const_value", "type_part", "type_decl_list", "type_definition",
  "type_decl", "simple_type_decl", "array_type_decl",
  "array_type_range_decl", "record_type_decl", "field_decl_list",
  "field_decl", "name_list", "var_part", "var_decl_list", "var_decl",
  "routine_part", "function_decl", "function_head", "procedure_decl",
  "procedure_head", "parameters", "para_decl_list", "para_type_list",
  "var_para_list", "val_para_list", "routine_body", "compound_stmt",
  "stmt_list", "stmt", "non_label_stmt", "assign_stmt", "proc_stmt",
  "if_stmt", "else_clause", "repeat_stmt", "while_stmt", "for_stmt",
  "direction", "case_stmt", "case_expr_list", "case_expr", "goto_stmt",
  "expression_list", "expression", "expr", "term", "factor", "T_ID", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      73,    74,    74,    75,    76,    76,    76,    76,    76,    77,
      77,    78,    78,    79,    80,    80,    80,    81,    81,    81,
      82,    83,    83,    83,    83,    84,    85,    85,    86,    87,
      87,    88,    88,    89,    89,    90,    91,    91,    91,    91,
      91,    92,    93,    94,    95,    96,    96,    97,    97,    98,
      98,    99,   100,   101,   102,   103,   103,   104,   104,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   106,   106,
     106,   107,   107,   107,   107,   107,   108,   109,   109,   110,
     111,   112,   113,   113,   114,   115,   115,   116,   116,   117,
     118,   118,   119,   119,   119,   119,   119,   119,   119,   120,
     120,   120,   120,   121,   121,   121,   121,   121,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   123,   123,
     123,   123,   123
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     3,     2,     2,     5,     0,     2,
       0,     2,     1,     4,     1,     1,     1,     1,     1,     2,
       0,     2,     1,     4,     1,     1,     1,     1,     1,     3,
       6,     3,     4,     5,     3,     3,     2,     1,     4,     3,
       1,     2,     0,     2,     1,     4,     2,     2,     1,     1,
       0,     4,     5,     4,     3,     3,     0,     3,     1,     3,
       3,     2,     1,     1,     3,     3,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     6,
       5,     1,     1,     4,     4,     4,     5,     2,     0,     4,
       4,     8,     1,     1,     5,     2,     1,     4,     4,     2,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     3,     3,     1,     1,     4,
       1,     4,     1,     3,     2,     2,     4,     3,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     8,   128,   129,   130,   131,   132,
       0,     1,     0,     0,    10,     4,     3,    66,     5,    63,
       0,    20,     0,   131,     0,     0,     0,     0,     0,    66,
       0,    71,     0,     0,    68,    69,    70,    72,    73,    74,
      75,    76,    77,    82,     0,     9,    12,     0,    42,     0,
       0,     0,    17,   118,    14,    15,    16,    18,   120,     0,
       0,     0,   122,     0,   108,   112,   117,     0,     0,    99,
       0,     0,     0,    64,    66,     0,     0,     0,     0,     0,
      11,     0,    19,    22,     0,    50,    67,     0,   101,     0,
       0,     0,   124,     0,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    65,     0,     0,     0,    78,
      18,     0,     0,    21,     0,    41,    44,    40,     0,     0,
       7,    48,     0,    49,     0,    84,     0,    85,     0,     0,
     123,     0,     0,    96,     0,   107,   102,   103,   104,   105,
     106,   111,   109,   110,   116,   114,   115,   113,     0,   127,
       0,    88,    89,    90,    83,     0,     0,    13,    28,    27,
       0,     0,     0,     0,    24,    25,    26,     0,     0,    43,
      56,    56,    46,    47,     8,     8,   100,   119,   121,     0,
      94,    95,     0,   126,    93,    92,     0,     0,    86,     0,
      80,     0,     0,    37,     0,     0,    23,    39,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,    87,    79,
       0,     0,     0,     0,    35,    36,     0,    29,    45,     0,
      62,     0,    58,     0,     0,     0,    51,     6,    53,    97,
      98,     0,     0,     0,     0,     0,     0,    61,    55,     0,
       0,     0,    52,    91,    34,     0,    31,     0,    38,    57,
      59,    60,     0,    32,    30,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    12,   212,   213,    14,    21,    45,
      46,    62,    48,    82,    83,   173,   174,   175,   223,   176,
     202,   203,   124,    85,   125,   126,   130,   131,   132,   133,
     134,   210,   231,   232,   233,   234,    18,    31,    32,    33,
      34,    35,    36,    37,   198,    38,    39,    40,   196,    41,
     142,   143,    42,    87,    88,    64,    65,    66,    67
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -176
static const yytype_int16 yypact[] =
{
     -16,   183,    14,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
     -34,  -176,     8,    59,    73,  -176,  -176,   210,  -176,  -176,
      89,    56,    50,   -12,    76,   123,   183,   137,   123,   210,
     123,  -176,   116,    85,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,    98,    79,    89,  -176,   146,   109,   240,
     123,   123,  -176,    62,  -176,  -176,  -176,   -42,    68,   123,
     123,   123,  -176,   229,    -9,    67,  -176,   -10,   100,  -176,
     237,   125,    97,  -176,   210,   123,   123,   183,   123,   156,
    -176,   107,   146,  -176,   183,    40,  -176,     3,   294,   126,
     123,   123,  -176,   211,  -176,   335,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     183,   123,   210,   123,   210,  -176,    78,   263,   112,   294,
    -176,   119,    41,  -176,   -25,   183,  -176,  -176,   176,   185,
      40,  -176,   133,  -176,   139,  -176,   123,  -176,   134,   135,
    -176,   138,   296,  -176,   147,    -9,    -9,    -9,    -9,    -9,
      -9,    67,    67,    67,  -176,  -176,  -176,  -176,   276,  -176,
     221,   194,   294,  -176,  -176,   136,   123,  -176,  -176,  -176,
     157,   183,   183,   143,  -176,  -176,  -176,   183,    41,  -176,
     171,   171,  -176,  -176,  -176,  -176,   294,  -176,  -176,   210,
    -176,  -176,   210,  -176,  -176,  -176,   123,   210,  -176,   123,
     294,    28,   220,  -176,    -8,   153,  -176,  -176,   154,    95,
     173,  -176,   169,    59,   174,   175,   177,   152,  -176,   294,
     172,   156,   182,   197,  -176,  -176,    41,  -176,  -176,   183,
     204,   -23,  -176,   207,   222,    17,  -176,  -176,  -176,  -176,
    -176,   210,   258,   200,   156,   242,   228,   204,  -176,    95,
      17,    17,  -176,  -176,  -176,    63,  -176,    41,  -176,  -176,
    -176,  -176,   156,  -176,  -176,  -176
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -176,  -176,  -176,  -176,  -176,   108,   281,  -176,  -176,  -176,
     257,   -78,  -176,  -176,   227,  -175,  -150,  -176,  -176,  -176,
    -176,   111,  -160,  -176,  -176,   186,  -176,   180,  -176,   184,
    -176,   145,  -176,    66,  -176,  -176,   103,   -11,    -7,   -94,
     269,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,   187,  -176,    46,   -21,   260,   -24,   -46,    -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -131
static const yytype_int16 yytable[] =
{
      10,   121,    19,   208,    63,    89,  -129,    70,  -129,    72,
     -81,   204,   205,    92,    11,    94,    43,   141,   161,     1,
     163,   168,    71,   102,   248,    68,   177,   178,    43,   169,
      15,    52,   220,    54,    50,    55,    56,   120,   109,    93,
     110,   249,   204,   177,   226,   168,   103,   104,    43,   230,
     135,   246,   -81,   169,   136,   117,   170,   119,    16,   154,
     155,   156,   157,   172,   141,   128,    52,   115,    54,   247,
      55,    56,   120,    43,   129,    17,   118,   171,   151,   152,
     153,   105,   264,   127,   221,   252,   106,   172,   158,   230,
     160,    20,   162,    44,   144,   215,   107,    47,   216,     5,
     260,   261,    49,   218,     6,     7,     8,     9,    90,   159,
    -128,    43,  -128,    43,    91,   186,  -130,   114,  -130,   262,
     108,   116,    51,   222,   127,   164,    52,    53,    54,   136,
      55,    56,    57,    58,     8,     9,   138,   139,   229,    73,
      79,   144,    69,   243,    75,   200,    76,   253,    77,    74,
      81,    96,    84,    59,    97,    98,    99,   100,   101,    52,
      78,    54,   111,    55,    56,   120,   256,   113,   122,    60,
     127,   127,   241,   137,   166,   217,   207,   263,   219,    61,
     180,   187,   188,   167,   265,   136,   136,     5,    43,   181,
     189,    43,     6,     7,     8,     9,    43,   184,   199,   192,
     227,   127,    19,   185,   177,   201,    96,   206,   127,    97,
      98,    99,   100,   101,     5,    22,   197,   209,   228,     6,
       7,    23,     9,    24,     5,   235,    17,    25,   127,     6,
       7,     8,     9,   236,    26,   242,    27,    28,   238,   239,
      43,   240,   194,   224,     5,   244,   245,    29,   127,     6,
       7,    23,     9,    24,    30,   177,    17,    25,   140,   250,
      95,   195,   254,   255,    26,    96,    27,    28,    97,    98,
      99,   100,   101,   257,   251,    96,   112,    29,    97,    98,
      99,   100,   101,    96,    30,    13,    97,    98,    99,   100,
     101,    96,   258,   214,    97,    98,    99,   100,   101,    52,
       5,    54,    80,    55,    56,    57,     7,     8,     9,   123,
     182,   179,   165,   225,   183,   259,   237,    96,    86,   190,
      97,    98,    99,   100,   101,   193,   211,     0,     0,   191,
      96,     0,     0,    97,    98,    99,   100,   101,    52,     5,
      54,     0,    55,    56,    57,     7,     8,     9,    96,     0,
       0,    97,    98,    99,   100,   101,   145,   146,   147,   148,
     149,   150
};

static const yytype_int16 yycheck[] =
{
       1,    79,    13,   178,    25,    51,    48,    28,    50,    30,
      22,   171,   172,    59,     0,    61,    17,    95,   112,    35,
     114,     4,    29,    32,    47,    26,    51,    52,    29,    12,
      64,     3,     4,     5,    46,     7,     8,     9,    48,    60,
      50,    64,   202,    51,    52,     4,    55,    56,    49,   209,
      47,   226,    64,    12,    51,    76,    15,    78,    50,   105,
     106,   107,   108,    46,   142,    25,     3,    74,     5,   229,
       7,     8,     9,    74,    34,    16,    77,    36,   102,   103,
     104,    14,   257,    84,    56,   235,    19,    46,   109,   249,
     111,    18,   113,     4,    95,   189,    29,    41,   192,     4,
     250,   251,    52,   197,     9,    10,    11,    12,    46,   110,
      48,   112,    50,   114,    46,   136,    48,    20,    50,    56,
      53,    75,    46,   201,   125,    47,     3,     4,     5,    51,
       7,     8,     9,    10,    11,    12,    90,    91,    43,    23,
      61,   142,     5,   221,    46,   166,    48,   241,    50,    64,
       4,    54,    43,    30,    57,    58,    59,    60,    61,     3,
      62,     5,    62,     7,     8,     9,   244,    42,    61,    46,
     171,   172,    20,    47,    62,   196,   177,   255,   199,    56,
       4,    47,    47,    64,   262,    51,    51,     4,   189,     4,
      52,   192,     9,    10,    11,    12,   197,    64,    62,    52,
      47,   202,   213,    64,    51,    48,    54,    64,   209,    57,
      58,    59,    60,    61,     4,     5,    22,    46,    64,     9,
      10,    11,    12,    13,     4,    52,    16,    17,   229,     9,
      10,    11,    12,    64,    24,    63,    26,    27,    64,    64,
     241,    64,    21,    23,     4,    63,    49,    37,   249,     9,
      10,    11,    12,    13,    44,    51,    16,    17,    47,    52,
      31,    40,     4,    63,    24,    54,    26,    27,    57,    58,
      59,    60,    61,    31,    52,    54,    39,    37,    57,    58,
      59,    60,    61,    54,    44,     4,    57,    58,    59,    60,
      61,    54,    64,   185,    57,    58,    59,    60,    61,     3,
       4,     5,    45,     7,     8,     9,    10,    11,    12,    82,
     130,   125,    49,   202,   130,   249,   213,    54,    49,    23,
      57,    58,    59,    60,    61,    49,   181,    -1,    -1,   142,
      54,    -1,    -1,    57,    58,    59,    60,    61,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    54,    -1,
      -1,    57,    58,    59,    60,    61,    96,    97,    98,    99,
     100,   101
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    35,    66,    67,    68,     4,     9,    10,    11,    12,
     123,     0,    69,    71,    72,    64,    50,    16,   101,   102,
      18,    73,     5,    11,    13,    17,    24,    26,    27,    37,
      44,   102,   103,   104,   105,   106,   107,   108,   110,   111,
     112,   114,   117,   123,     4,    74,    75,    41,    77,    52,
      46,    46,     3,     4,     5,     7,     8,     9,    10,    30,
      46,    56,    76,   119,   120,   121,   122,   123,   123,     5,
     119,   103,   119,    23,    64,    46,    48,    50,    62,    61,
      75,     4,    78,    79,    43,    88,   105,   118,   119,   122,
      46,    46,   122,   119,   122,    31,    54,    57,    58,    59,
      60,    61,    32,    55,    56,    14,    19,    29,    53,    48,
      50,    62,    39,    42,    20,   103,   118,   119,   123,   119,
       9,    76,    61,    79,    87,    89,    90,   123,    25,    34,
      91,    92,    93,    94,    95,    47,    51,    47,   118,   118,
      47,    76,   115,   116,   123,   120,   120,   120,   120,   120,
     120,   121,   121,   121,   122,   122,   122,   122,   119,   123,
     119,   104,   119,   104,    47,    49,    62,    64,     4,    12,
      15,    36,    46,    80,    81,    82,    84,    51,    52,    90,
       4,     4,    92,    94,    64,    64,   119,    47,    47,    52,
      23,   116,    52,    49,    21,    40,   113,    22,   109,    62,
     119,    48,    85,    86,    87,    87,    64,   123,    80,    46,
      96,    96,    70,    71,    70,   104,   104,   119,   104,   119,
       4,    56,    76,    83,    23,    86,    52,    47,    64,    43,
      87,    97,    98,    99,   100,    52,    64,   101,    64,    64,
      64,    20,    63,    76,    63,    49,    80,    87,    47,    64,
      52,    52,    81,   104,     4,    63,    76,    31,    64,    98,
      81,    81,    56,    76,    80,    76
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 103 "SPL_parse.y"
    {root = (yyvsp[(1) - (1)].a_prog);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 106 "SPL_parse.y"
    {(yyval.a_prog) = A_Program((yyloc), (yyvsp[(1) - (3)].s_symbol), (yyvsp[(2) - (3)].a_routine));;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 109 "SPL_parse.y"
    {(yyval.s_symbol) = (yyvsp[(2) - (3)].s_symbol);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 111 "SPL_parse.y"
    {(yyval.a_routine) = A_Routine((yyloc), (yyvsp[(1) - (2)].a_routineHead), (yyvsp[(2) - (2)].a_stmtList));;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 113 "SPL_parse.y"
    {(yyval.a_routine) = A_Routine((yyloc), (yyvsp[(1) - (2)].a_routineHead), (yyvsp[(2) - (2)].a_stmtList));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 117 "SPL_parse.y"
    {(yyval.a_routineHead) = A_RoutineHead((yyloc), (yyvsp[(2) - (5)].a_decList), (yyvsp[(3) - (5)].a_decList), (yyvsp[(4) - (5)].a_decList), (yyvsp[(5) - (5)].a_decList));;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 118 "SPL_parse.y"
    {;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 120 "SPL_parse.y"
    {(yyval.a_decList) = (yyvsp[(2) - (2)].a_decList);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 121 "SPL_parse.y"
    {(yyval.a_decList) = NULL;;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 123 "SPL_parse.y"
    {(yyval.a_decList) = A_DecList((yyvsp[(2) - (2)].a_dec), (yyvsp[(1) - (2)].a_decList));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 124 "SPL_parse.y"
    {(yyval.a_decList) = A_DecList((yyvsp[(1) - (1)].a_dec), NULL);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 126 "SPL_parse.y"
    {(yyval.a_dec) = A_ConstDec((yyloc), S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].a_constval));;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 128 "SPL_parse.y"
    {(yyval.a_constval) = A_Integer((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].ival));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 129 "SPL_parse.y"
    {(yyval.a_constval) = A_Real((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].fval));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 130 "SPL_parse.y"
    {(yyval.a_constval) = A_Char((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].cval));;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 131 "SPL_parse.y"
    {(yyval.a_constval) = A_String((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].sval));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 132 "SPL_parse.y"
    {
		switch((yyvsp[(1) - (1)].conval)){
			case SYS_CON_FALSE: (yyval.a_constval) = A_Bool((yylsp[(1) - (1)]), 0); break;
			case SYS_CON_TRUE: (yyval.a_constval) = A_Bool((yylsp[(1) - (1)]), 1); break;
			case SYS_CON_MAXINT: (yyval.a_constval) = A_Integer((yylsp[(1) - (1)]), 32767);break;
		}
	;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 140 "SPL_parse.y"
    {(yyval.a_decList) = (yyvsp[(2) - (2)].a_decList); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 141 "SPL_parse.y"
    {(yyval.a_decList) = NULL;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 143 "SPL_parse.y"
    {(yyval.a_decList) = A_DecList((yyvsp[(2) - (2)].a_dec), (yyvsp[(1) - (2)].a_decList));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 144 "SPL_parse.y"
    {(yyval.a_decList) = A_DecList((yyvsp[(1) - (1)].a_dec), NULL);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 146 "SPL_parse.y"
    {(yyval.a_dec) = A_TypeDec((yyloc), S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].a_type));;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 148 "SPL_parse.y"
    {(yyval.a_type) = A_SimpleType((yyloc), (yyvsp[(1) - (1)].a_simple));;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 149 "SPL_parse.y"
    {(yyval.a_type) = A_ArrayType((yyloc), (yyvsp[(1) - (1)].a_array));;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 150 "SPL_parse.y"
    {(yyval.a_type) = A_RecordType((yyloc), (yyvsp[(1) - (1)].a_fieldList));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 152 "SPL_parse.y"
    {(yyval.a_simple) = A_SimpleSysType((yyloc), (yyvsp[(1) - (1)].typeval));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 153 "SPL_parse.y"
    {(yyval.a_simple) = A_SimpleNameType((yyloc), S_Symbol((yyvsp[(1) - (1)].sval)));;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 154 "SPL_parse.y"
    {(yyval.a_simple) = A_SimpleNameListType((yyloc), (yyvsp[(2) - (3)].a_nameList));;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 157 "SPL_parse.y"
    {(yyval.a_array) = A_Array((yyloc), (yyvsp[(3) - (6)].a_range), (yyvsp[(6) - (6)].a_type));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 159 "SPL_parse.y"
    {
		(yyval.a_range) = A_ConstRange((yyloc), (yyvsp[(1) - (3)].a_constval), (yyvsp[(3) - (3)].a_constval));
	;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 162 "SPL_parse.y"
    {
		// In semantic analysis the type of const_value should be checked
		(yyvsp[(2) - (4)].a_constval)->u.integer *= -1;
		(yyval.a_range) = A_ConstRange((yyloc), (yyvsp[(2) - (4)].a_constval), (yyvsp[(4) - (4)].a_constval));
	;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 167 "SPL_parse.y"
    {
		(yyvsp[(2) - (5)].a_constval)->u.integer *= -1;
		(yyvsp[(5) - (5)].a_constval)->u.integer *= -1;
		(yyval.a_range) = A_ConstRange((yyloc), (yyvsp[(2) - (5)].a_constval), (yyvsp[(5) - (5)].a_constval));
	;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 172 "SPL_parse.y"
    {
		(yyval.a_range) = A_NameRange((yyloc), S_Symbol((yyvsp[(1) - (3)].sval)), S_Symbol((yyvsp[(3) - (3)].sval)));
	;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 176 "SPL_parse.y"
    {(yyval.a_fieldList) = (yyvsp[(2) - (3)].a_fieldList);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 178 "SPL_parse.y"
    {(yyval.a_fieldList) = A_FieldList((yyvsp[(2) - (2)].a_field), (yyvsp[(1) - (2)].a_fieldList));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 179 "SPL_parse.y"
    {(yyval.a_fieldList) = A_FieldList((yyvsp[(1) - (1)].a_field), NULL);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 181 "SPL_parse.y"
    {(yyval.a_field) = A_Field((yyloc), (yyvsp[(1) - (4)].a_nameList), (yyvsp[(3) - (4)].a_type));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 183 "SPL_parse.y"
    {(yyval.a_nameList) = A_NameList(A_Name((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].s_symbol)), (yyvsp[(1) - (3)].a_nameList));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 184 "SPL_parse.y"
    {(yyval.a_nameList) = A_NameList(A_Name((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].s_symbol)), NULL);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 186 "SPL_parse.y"
    {(yyval.a_decList) = (yyvsp[(2) - (2)].a_decList);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 187 "SPL_parse.y"
    {(yyval.a_decList) = NULL;;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 189 "SPL_parse.y"
    {(yyval.a_decList) = A_DecList(A_VarDec((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].a_varDecList)), (yyvsp[(1) - (2)].a_decList));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 190 "SPL_parse.y"
    {(yyval.a_decList) = A_DecList(A_VarDec((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].a_varDecList)), NULL);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 192 "SPL_parse.y"
    {(yyval.a_varDecList) = A_VarDecList((yyloc), (yyvsp[(1) - (4)].a_nameList), (yyvsp[(3) - (4)].a_type));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 194 "SPL_parse.y"
    {(yyval.a_decList) = A_DecList((yyvsp[(2) - (2)].a_dec), (yyvsp[(1) - (2)].a_decList));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 195 "SPL_parse.y"
    {(yyval.a_decList) = A_DecList((yyvsp[(2) - (2)].a_dec), (yyvsp[(1) - (2)].a_decList));;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 196 "SPL_parse.y"
    {(yyval.a_decList) = A_DecList((yyvsp[(1) - (1)].a_dec), NULL);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 197 "SPL_parse.y"
    {(yyval.a_decList) = A_DecList((yyvsp[(1) - (1)].a_dec), NULL);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 198 "SPL_parse.y"
    {(yyval.a_decList) = NULL;;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 200 "SPL_parse.y"
    {(yyval.a_dec) = A_RoutinePartDec((yyloc), A_RoutinePart((yyvsp[(1) - (4)].a_routinePartHead), (yyvsp[(3) - (4)].a_routine)));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 202 "SPL_parse.y"
    {(yyval.a_routinePartHead) = A_FuncHead((yyloc), S_Symbol((yyvsp[(2) - (5)].sval)), (yyvsp[(3) - (5)].a_paraList), (yyvsp[(5) - (5)].a_simple));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 204 "SPL_parse.y"
    {(yyval.a_dec) = A_RoutinePartDec((yyloc), A_RoutinePart((yyvsp[(1) - (4)].a_routinePartHead), (yyvsp[(3) - (4)].a_routine)));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 206 "SPL_parse.y"
    {(yyval.a_routinePartHead) = A_ProcHead((yyloc), S_Symbol((yyvsp[(2) - (3)].sval)), (yyvsp[(3) - (3)].a_paraList));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 208 "SPL_parse.y"
    {(yyval.a_paraList) = (yyvsp[(2) - (3)].a_paraList);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 209 "SPL_parse.y"
    {(yyval.a_paraList) = NULL;;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 211 "SPL_parse.y"
    {(yyval.a_paraList) = A_ParaList((yyvsp[(3) - (3)].a_paraField), (yyvsp[(1) - (3)].a_paraList));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 212 "SPL_parse.y"
    {(yyval.a_paraList) = A_ParaList((yyvsp[(1) - (1)].a_paraField), NULL);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 214 "SPL_parse.y"
    {(yyval.a_paraField) = A_VarParaField((yyloc), (yyvsp[(1) - (3)].a_nameList), (yyvsp[(3) - (3)].a_simple));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 215 "SPL_parse.y"
    {(yyval.a_paraField) = A_VarParaField((yyloc), (yyvsp[(1) - (3)].a_nameList), (yyvsp[(3) - (3)].a_simple));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 217 "SPL_parse.y"
    {(yyval.a_nameList) = (yyvsp[(2) - (2)].a_nameList);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 219 "SPL_parse.y"
    {(yyval.a_nameList) = (yyvsp[(1) - (1)].a_nameList);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 221 "SPL_parse.y"
    {(yyval.a_stmtList) = (yyvsp[(1) - (1)].a_stmt)->u.compoundStmt.substmtList;;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 223 "SPL_parse.y"
    {(yyval.a_stmt) = A_CompoundStmt((yyloc), (yyvsp[(2) - (3)].a_stmtList));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 225 "SPL_parse.y"
    {(yyval.a_stmtList) = A_StmtList((yyvsp[(1) - (3)].a_stmt), (yyvsp[(3) - (3)].a_stmtList));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 226 "SPL_parse.y"
    {(yyval.a_stmtList) = NULL;;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 228 "SPL_parse.y"
    {(yyval.a_stmt) = A_LabelStmt((yyloc), (yyvsp[(1) - (3)].ival), (yyvsp[(3) - (3)].a_stmt));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 229 "SPL_parse.y"
    {(yyval.a_stmt) = (yyvsp[(1) - (1)].a_stmt);;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 231 "SPL_parse.y"
    {(yyval.a_stmt) = (yyvsp[(1) - (1)].a_stmt);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 232 "SPL_parse.y"
    {(yyval.a_stmt) = (yyvsp[(1) - (1)].a_stmt);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 233 "SPL_parse.y"
    {(yyval.a_stmt) = (yyvsp[(1) - (1)].a_stmt);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 234 "SPL_parse.y"
    {(yyval.a_stmt) = (yyvsp[(1) - (1)].a_stmt);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 235 "SPL_parse.y"
    {(yyval.a_stmt) = (yyvsp[(1) - (1)].a_stmt);;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 236 "SPL_parse.y"
    {(yyval.a_stmt) = (yyvsp[(1) - (1)].a_stmt);;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 237 "SPL_parse.y"
    {(yyval.a_stmt) = (yyvsp[(1) - (1)].a_stmt);;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 238 "SPL_parse.y"
    {(yyval.a_stmt) = (yyvsp[(1) - (1)].a_stmt);;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 239 "SPL_parse.y"
    {(yyval.a_stmt) = (yyvsp[(1) - (1)].a_stmt);;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 241 "SPL_parse.y"
    {(yyval.a_stmt) = A_AssignStmt((yyloc), A_Var((yylsp[(1) - (3)]), (yyvsp[(1) - (3)].s_symbol)), (yyvsp[(3) - (3)].a_exp));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 242 "SPL_parse.y"
    {/*array element*/ (yyval.a_stmt) = A_AssignStmt((yyloc), A_ArrayElement((yylsp[(1) - (6)]), (yyvsp[(1) - (6)].s_symbol), (yyvsp[(3) - (6)].a_exp)), (yyvsp[(6) - (6)].a_exp));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 243 "SPL_parse.y"
    {/*record element*/ (yyval.a_stmt) = A_AssignStmt((yyloc), A_RecordField((yylsp[(1) - (5)]), (yyvsp[(1) - (5)].s_symbol), (yyvsp[(3) - (5)].s_symbol)), (yyvsp[(5) - (5)].a_exp));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 246 "SPL_parse.y"
    {switch((yyvsp[(1) - (1)].procval)){
		case SYS_PROC_WRITE: (yyval.a_stmt) = A_ProcStmt((yyloc), A_Proc((yyloc), S_Symbol("write"), NULL)); break;
		case SYS_PROC_WRITELN: (yyval.a_stmt) = A_ProcStmt((yyloc), A_Proc((yyloc), S_Symbol("writeln"), NULL)); break;
	};}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 250 "SPL_parse.y"
    {(yyval.a_stmt) = A_ProcStmt((yyloc), A_Proc((yyloc), (yyvsp[(1) - (1)].s_symbol), NULL));;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 251 "SPL_parse.y"
    {(yyval.a_stmt) = A_ProcStmt((yyloc), A_Proc((yyloc), (yyvsp[(1) - (4)].s_symbol), (yyvsp[(3) - (4)].a_expList)));;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 253 "SPL_parse.y"
    {switch((yyvsp[(1) - (4)].procval)){
		case SYS_PROC_WRITE: (yyval.a_stmt) = A_ProcStmt((yyloc), A_Proc((yyloc), S_Symbol("write"), (yyvsp[(3) - (4)].a_expList))); break;
		case SYS_PROC_WRITELN: (yyval.a_stmt) = A_ProcStmt((yyloc), A_Proc((yyloc), S_Symbol("writeln"), (yyvsp[(3) - (4)].a_expList))); break;
	};}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 257 "SPL_parse.y"
    {(yyval.a_stmt) = A_ProcStmt((yyloc), A_Proc((yyloc), S_Symbol("read"), A_ExpList((yyvsp[(3) - (4)].a_exp), NULL)));;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 259 "SPL_parse.y"
    {(yyval.a_stmt) = A_IfStmt((yyloc), (yyvsp[(2) - (5)].a_exp), (yyvsp[(4) - (5)].a_stmt), (yyvsp[(5) - (5)].a_stmt));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 261 "SPL_parse.y"
    {(yyval.a_stmt) = (yyvsp[(2) - (2)].a_stmt);;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 262 "SPL_parse.y"
    {(yyval.a_stmt) = NULL;;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 264 "SPL_parse.y"
    {(yyval.a_stmt) = A_RepeatStmt((yyloc), (yyvsp[(4) - (4)].a_exp), (yyvsp[(2) - (4)].a_stmtList));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 266 "SPL_parse.y"
    {(yyval.a_stmt) = A_WhileStmt((yyloc), (yyvsp[(2) - (4)].a_exp), (yyvsp[(4) - (4)].a_stmt));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 268 "SPL_parse.y"
    {(yyval.a_stmt) = A_ForStmt((yyloc), A_Var((yylsp[(2) - (8)]), (yyvsp[(2) - (8)].s_symbol)), (yyvsp[(4) - (8)].a_exp), (yyvsp[(5) - (8)].ival), (yyvsp[(6) - (8)].a_exp), (yyvsp[(8) - (8)].a_stmt));;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 270 "SPL_parse.y"
    {(yyval.ival) = 1;;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 271 "SPL_parse.y"
    {(yyval.ival) = -1;;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 273 "SPL_parse.y"
    {(yyval.a_stmt) = A_CaseStmt((yyloc), (yyvsp[(2) - (5)].a_exp), (yyvsp[(4) - (5)].a_caseList));;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 275 "SPL_parse.y"
    {(yyval.a_caseList) = A_CaseList((yyvsp[(2) - (2)].a_case), (yyvsp[(1) - (2)].a_caseList));;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 276 "SPL_parse.y"
    {(yyval.a_caseList) = A_CaseList((yyvsp[(1) - (1)].a_case), NULL);;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 278 "SPL_parse.y"
    {(yyval.a_case) = A_Case((yyloc), (yyvsp[(1) - (4)].a_constval), NULL, (yyvsp[(3) - (4)].a_stmt));;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 279 "SPL_parse.y"
    {(yyval.a_case) = A_Case((yyloc), NULL, (yyvsp[(1) - (4)].s_symbol), (yyvsp[(3) - (4)].a_stmt));;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 281 "SPL_parse.y"
    {(yyval.a_stmt) = A_GotoStmt((yyloc), (yyvsp[(2) - (2)].ival));;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 283 "SPL_parse.y"
    {(yyval.a_expList) = A_ExpList((yyvsp[(3) - (3)].a_exp), (yyvsp[(1) - (3)].a_expList));;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 284 "SPL_parse.y"
    {(yyval.a_expList) = A_ExpList((yyvsp[(1) - (1)].a_exp), NULL);;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 286 "SPL_parse.y"
    {(yyval.a_exp) = A_OpExp((yyloc), A_geOp, (yyvsp[(1) - (3)].a_exp), (yyvsp[(3) - (3)].a_exp));;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 287 "SPL_parse.y"
    {(yyval.a_exp) = A_OpExp((yyloc), A_gtOp, (yyvsp[(1) - (3)].a_exp), (yyvsp[(3) - (3)].a_exp));;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 288 "SPL_parse.y"
    {(yyval.a_exp) = A_OpExp((yyloc), A_leOp, (yyvsp[(1) - (3)].a_exp), (yyvsp[(3) - (3)].a_exp));;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 289 "SPL_parse.y"
    {(yyval.a_exp) = A_OpExp((yyloc), A_ltOp, (yyvsp[(1) - (3)].a_exp), (yyvsp[(3) - (3)].a_exp));;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 290 "SPL_parse.y"
    {(yyval.a_exp) = A_OpExp((yyloc), A_eqOp, (yyvsp[(1) - (3)].a_exp), (yyvsp[(3) - (3)].a_exp));;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 291 "SPL_parse.y"
    {(yyval.a_exp) = A_OpExp((yyloc), A_neqOp, (yyvsp[(1) - (3)].a_exp), (yyvsp[(3) - (3)].a_exp));;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 292 "SPL_parse.y"
    {(yyval.a_exp) = (yyvsp[(1) - (1)].a_exp);;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 294 "SPL_parse.y"
    {(yyval.a_exp) = A_OpExp((yyloc), A_plusOp, (yyvsp[(1) - (3)].a_exp), (yyvsp[(3) - (3)].a_exp));;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 295 "SPL_parse.y"
    {(yyval.a_exp) = A_OpExp((yyloc), A_minusOp, (yyvsp[(1) - (3)].a_exp), (yyvsp[(3) - (3)].a_exp));;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 296 "SPL_parse.y"
    {(yyval.a_exp) = A_OpExp((yyloc), A_orOp, (yyvsp[(1) - (3)].a_exp), (yyvsp[(3) - (3)].a_exp));;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 297 "SPL_parse.y"
    {(yyval.a_exp) = (yyvsp[(1) - (1)].a_exp);;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 299 "SPL_parse.y"
    {(yyval.a_exp) = A_OpExp((yyloc), A_mulOp, (yyvsp[(1) - (3)].a_exp), (yyvsp[(3) - (3)].a_exp));;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 300 "SPL_parse.y"
    {(yyval.a_exp) = A_OpExp((yyloc), A_divOp, (yyvsp[(1) - (3)].a_exp), (yyvsp[(3) - (3)].a_exp));;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 301 "SPL_parse.y"
    {(yyval.a_exp) = A_OpExp((yyloc), A_modOp, (yyvsp[(1) - (3)].a_exp), (yyvsp[(3) - (3)].a_exp));;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 302 "SPL_parse.y"
    {(yyval.a_exp) = A_OpExp((yyloc), A_andOp, (yyvsp[(1) - (3)].a_exp), (yyvsp[(3) - (3)].a_exp));;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 303 "SPL_parse.y"
    {(yyval.a_exp) = (yyvsp[(1) - (1)].a_exp);;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 305 "SPL_parse.y"
    {(yyval.a_exp) = A_NameExp((yyloc), S_Symbol((yyvsp[(1) - (1)].sval)));;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 306 "SPL_parse.y"
    {(yyval.a_exp) = A_FuncExp((yyloc), A_Proc((yyloc), S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].a_expList)));;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 307 "SPL_parse.y"
    {
		switch((yyvsp[(1) - (1)].functval)){
			case SYS_FUNCT_ABS: (yyval.a_exp) = A_FuncExp((yyloc), A_Proc((yyloc), S_Symbol("abs"), NULL)); break;
			case SYS_FUNCT_CHR: (yyval.a_exp) = A_FuncExp((yyloc), A_Proc((yyloc), S_Symbol("chr"), NULL)); break;
			case SYS_FUNCT_ODD: (yyval.a_exp) = A_FuncExp((yyloc), A_Proc((yyloc), S_Symbol("odd"), NULL)); break;
			case SYS_FUNCT_ORD: (yyval.a_exp) = A_FuncExp((yyloc), A_Proc((yyloc), S_Symbol("ord"), NULL)); break;
			case SYS_FUNCT_PRED: (yyval.a_exp) = A_FuncExp((yyloc), A_Proc((yyloc), S_Symbol("pred"), NULL)); break;
			case SYS_FUNCT_SQR: (yyval.a_exp) = A_FuncExp((yyloc), A_Proc((yyloc), S_Symbol("sqr"), NULL)); break;
			case SYS_FUNCT_SQRT: (yyval.a_exp) = A_FuncExp((yyloc), A_Proc((yyloc), S_Symbol("sqrt"), NULL)); break;
			case SYS_FUNCT_SUCC: (yyval.a_exp) = A_FuncExp((yyloc), A_Proc((yyloc), S_Symbol("succ"), NULL)); break;
		}
	;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 319 "SPL_parse.y"
    {
		switch((yyvsp[(1) - (4)].functval)){
			case SYS_FUNCT_ABS: (yyval.a_exp) = A_FuncExp((yyloc), A_Proc((yyloc), S_Symbol("abs"), (yyvsp[(3) - (4)].a_expList))); break;
			case SYS_FUNCT_CHR: (yyval.a_exp) = A_FuncExp((yyloc), A_Proc((yyloc), S_Symbol("chr"), (yyvsp[(3) - (4)].a_expList))); break;
			case SYS_FUNCT_ODD: (yyval.a_exp) = A_FuncExp((yyloc), A_Proc((yyloc), S_Symbol("odd"), (yyvsp[(3) - (4)].a_expList))); break;
			case SYS_FUNCT_ORD: (yyval.a_exp) = A_FuncExp((yyloc), A_Proc((yyloc), S_Symbol("ord"), (yyvsp[(3) - (4)].a_expList))); break;
			case SYS_FUNCT_PRED: (yyval.a_exp) = A_FuncExp((yyloc), A_Proc((yyloc), S_Symbol("pred"), (yyvsp[(3) - (4)].a_expList))); break;
			case SYS_FUNCT_SQR: (yyval.a_exp) = A_FuncExp((yyloc), A_Proc((yyloc), S_Symbol("sqr"), (yyvsp[(3) - (4)].a_expList))); break;
			case SYS_FUNCT_SQRT: (yyval.a_exp) = A_FuncExp((yyloc), A_Proc((yyloc), S_Symbol("sqrt"), (yyvsp[(3) - (4)].a_expList))); break;
			case SYS_FUNCT_SUCC: (yyval.a_exp) = A_FuncExp((yyloc), A_Proc((yyloc), S_Symbol("succ"), (yyvsp[(3) - (4)].a_expList))); break;
		}
	;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 331 "SPL_parse.y"
    {(yyval.a_exp) = A_ConstExp((yyloc), (yyvsp[(1) - (1)].a_constval));;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 332 "SPL_parse.y"
    {(yyval.a_exp) = (yyvsp[(2) - (3)].a_exp);;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 333 "SPL_parse.y"
    {(yyval.a_exp) = A_OpExp((yyloc), A_notOp, NULL, (yyvsp[(2) - (2)].a_exp));;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 334 "SPL_parse.y"
    {(yyval.a_exp) = A_OpExp((yyloc), A_negOp, NULL, (yyvsp[(2) - (2)].a_exp));;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 335 "SPL_parse.y"
    {(yyval.a_exp) = A_VarExp((yyloc), A_ArrayElement((yyloc), (yyvsp[(1) - (4)].s_symbol), (yyvsp[(3) - (4)].a_exp)));;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 336 "SPL_parse.y"
    {(yyval.a_exp) = A_VarExp((yyloc), A_RecordField((yyloc), (yyvsp[(1) - (3)].s_symbol), (yyvsp[(3) - (3)].s_symbol)));;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 340 "SPL_parse.y"
    {(yyval.s_symbol) = S_Symbol((yyvsp[(1) - (1)].sval));;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 341 "SPL_parse.y"
    {
		switch((yyvsp[(1) - (1)].conval)){
			case SYS_CON_FALSE:  (yyval.s_symbol) = S_Symbol("false"); break;
			case SYS_CON_TRUE:   (yyval.s_symbol) = S_Symbol("true"); break;
			case SYS_CON_MAXINT: (yyval.s_symbol) = S_Symbol("maxint"); break;
		}
	;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 348 "SPL_parse.y"
    {
		switch((yyvsp[(1) - (1)].functval)){
			case SYS_FUNCT_ABS: (yyval.s_symbol) = S_Symbol("abs"); break;
			case SYS_FUNCT_CHR: (yyval.s_symbol) = S_Symbol("chr"); break;
			case SYS_FUNCT_ODD: (yyval.s_symbol) = S_Symbol("odd"); break;
			case SYS_FUNCT_ORD: (yyval.s_symbol) = S_Symbol("ord"); break;
			case SYS_FUNCT_PRED:(yyval.s_symbol) = S_Symbol("pred"); break;
			case SYS_FUNCT_SQR: (yyval.s_symbol) = S_Symbol("sqr"); break;
			case SYS_FUNCT_SQRT:(yyval.s_symbol) = S_Symbol("sqrt"); break;
			case SYS_FUNCT_SUCC:(yyval.s_symbol) = S_Symbol("succ"); break;
		}
	;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 360 "SPL_parse.y"
    {
		switch((yyvsp[(1) - (1)].procval)){
			case SYS_PROC_WRITE:   (yyval.s_symbol) = S_Symbol("write"); break;
			case SYS_PROC_WRITELN: (yyval.s_symbol) = S_Symbol("writeln"); break;
		}
	;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 366 "SPL_parse.y"
    {
		switch((yyvsp[(1) - (1)].typeval)){
			case Ty_boolean: (yyval.s_symbol) = S_Symbol("boolean"); break;
			case Ty_char:    (yyval.s_symbol) = S_Symbol("char"); break;
			case Ty_integer: (yyval.s_symbol) = S_Symbol("integer"); break;
			case Ty_real:    (yyval.s_symbol) = S_Symbol("real"); break;
			case Ty_string:  (yyval.s_symbol) = S_Symbol("string"); break;
		}
	;}
    break;



/* Line 1455 of yacc.c  */
#line 2745 "SPL_parse.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 376 "SPL_parse.y"

int main(){
	time_t startTime, endTime;
	startTime = time(NULL);
	yyparse();
	endTime = time(NULL);
	
	printf("Errors: %d\n", errorNum);
	printf("Parsing Time: %f seconds\n", difftime(endTime, startTime));
	
	return 0;
}

int yyerror(char *s) 
{ 
     fprintf(stderr, "%s\n", s); 
     return 0; 
}
