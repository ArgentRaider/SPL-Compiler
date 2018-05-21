
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

	#include <stdio.h>
	#include <string.h>
	#include "errormsg.h"
	#define YYERROR_VERBOSE 1



/* Line 189 of yacc.c  */
#line 82 "SPL_parse.c"

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
     T_NAME = 258,
     T_STRING = 259,
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
#line 9 "SPL_parse.y"

	int ival;
	double fval;
	char cval;
	char* sval;
	enum SYS_CON{SYS_CON_FALSE, SYS_CON_TRUE, SYS_CON_MAXINT} conval;
	enum SYS_FUNCT{SYS_FUNCT_ABS, SYS_FUNCT_CHR, SYS_FUNCT_ODD, 
		SYS_FUNCT_ORD, SYS_FUNCT_PRED, SYS_FUNCT_SQR, SYS_FUNCT_SQRT, SYS_FUNCT_SUCC} functval;
	enum SYS_PROC{SYS_PROC_WRITE, SYS_PROC_WRITELN} procval;
	enum SYS_TYPE{SYS_TYPE_BOOLEAN, SYS_TYPE_CHAR, SYS_TYPE_INTEGER, SYS_TYPE_REAL} typeval;



/* Line 214 of yacc.c  */
#line 196 "SPL_parse.c"
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
#line 221 "SPL_parse.c"

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
#define YYLAST   403

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNRULES -- Number of states.  */
#define YYNSTATES  270

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
      29,    30,    36,    41,    43,    45,    47,    49,    51,    54,
      55,    58,    60,    65,    67,    69,    71,    73,    75,    79,
      86,    90,    95,   101,   105,   109,   112,   114,   119,   123,
     125,   128,   129,   132,   134,   139,   142,   145,   147,   149,
     150,   155,   161,   166,   170,   174,   175,   179,   181,   185,
     189,   192,   194,   196,   200,   204,   205,   209,   211,   213,
     215,   217,   219,   221,   223,   225,   227,   229,   233,   240,
     246,   248,   250,   255,   260,   265,   271,   274,   275,   280,
     285,   294,   296,   298,   304,   307,   309,   314,   319,   322,
     326,   328,   332,   336,   340,   344,   348,   352,   354,   358,
     362,   366,   368,   372,   376,   380,   384,   386,   388,   393,
     395,   400,   402,   406,   409,   412,   417,   421,   425,   427,
     429,   431,   433,   435
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      66,     0,    -1,    67,    -1,    68,    69,    50,    -1,    35,
     123,    64,    -1,    71,   100,    -1,    71,   100,    -1,    72,
      73,    76,    87,    90,    -1,    -1,    18,    74,    -1,    -1,
      74,     3,    61,    75,    64,    -1,     3,    61,    75,    64,
      -1,     5,    -1,     7,    -1,     8,    -1,     4,    -1,     9,
      -1,    41,    77,    -1,    -1,    77,    78,    -1,    78,    -1,
       3,    61,    79,    64,    -1,    80,    -1,    81,    -1,    83,
      -1,    12,    -1,     3,    -1,    46,    86,    47,    -1,    15,
      48,    82,    49,    31,    79,    -1,    75,    63,    75,    -1,
      56,    75,    63,    75,    -1,    56,    75,    63,    56,    75,
      -1,     3,    63,     3,    -1,    36,    84,    23,    -1,    84,
      85,    -1,    85,    -1,    86,    52,    79,    64,    -1,    86,
      51,   123,    -1,   123,    -1,    43,    88,    -1,    -1,    88,
      89,    -1,    89,    -1,    86,    52,    79,    64,    -1,    90,
      91,    -1,    90,    93,    -1,    91,    -1,    93,    -1,    -1,
      92,    64,    70,    64,    -1,    25,     3,    95,    52,    80,
      -1,    94,    64,    70,    64,    -1,    34,     3,    95,    -1,
      46,    96,    47,    -1,    -1,    96,    64,    97,    -1,    97,
      -1,    98,    52,    80,    -1,    99,    52,    80,    -1,    43,
      86,    -1,    86,    -1,   101,    -1,    16,   102,    23,    -1,
     102,   103,    64,    -1,    -1,     5,    52,   104,    -1,   104,
      -1,   105,    -1,   106,    -1,   101,    -1,   107,    -1,   109,
      -1,   110,    -1,   111,    -1,   113,    -1,   116,    -1,   123,
      62,   118,    -1,   123,    48,   118,    49,    62,   118,    -1,
     123,    50,   123,    62,   118,    -1,    11,    -1,   123,    -1,
     123,    46,   122,    47,    -1,    11,    46,   117,    47,    -1,
      13,    46,   121,    47,    -1,    27,   118,    39,   103,   108,
      -1,    22,   103,    -1,    -1,    37,   102,    42,   118,    -1,
      44,   118,    20,   103,    -1,    24,   123,    62,   118,   112,
     118,    20,   103,    -1,    40,    -1,    21,    -1,    17,   118,
      31,   114,    23,    -1,   114,   115,    -1,   115,    -1,    75,
      52,   103,    64,    -1,   123,    52,   103,    64,    -1,    26,
       5,    -1,   117,    51,   118,    -1,   118,    -1,   118,    57,
     119,    -1,   118,    58,   119,    -1,   118,    59,   119,    -1,
     118,    60,   119,    -1,   118,    61,   119,    -1,   118,    54,
     119,    -1,   119,    -1,   119,    55,   120,    -1,   119,    56,
     120,    -1,   119,    32,   120,    -1,   120,    -1,   120,    53,
     121,    -1,   120,    19,   121,    -1,   120,    29,   121,    -1,
     120,    14,   121,    -1,   121,    -1,     3,    -1,     3,    46,
     122,    47,    -1,    10,    -1,    10,    46,   122,    47,    -1,
      75,    -1,    46,   118,    47,    -1,    30,   121,    -1,    56,
     121,    -1,   123,    48,   118,    49,    -1,   123,    50,   123,
      -1,   122,    51,   118,    -1,   118,    -1,     3,    -1,     9,
      -1,    10,    -1,    11,    -1,    12,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    47,    47,    50,    53,    55,    57,    60,    61,    63,
      64,    66,    67,    69,    70,    71,    72,    73,    75,    76,
      78,    79,    81,    83,    84,    85,    87,    88,    89,    91,
      93,    94,    95,    96,    98,   100,   101,   103,   105,   106,
     108,   109,   111,   112,   114,   116,   117,   118,   119,   120,
     122,   124,   126,   128,   130,   131,   133,   134,   136,   137,
     139,   141,   143,   145,   147,   148,   150,   151,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   163,   164,   165,
     167,   168,   169,   170,   171,   173,   175,   176,   178,   180,
     182,   184,   185,   187,   189,   190,   192,   193,   195,   197,
     198,   200,   201,   202,   203,   204,   205,   206,   208,   209,
     210,   211,   213,   214,   215,   216,   217,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   230,   231,   235,
     236,   243,   255,   261
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_NAME", "T_STRING", "T_INTEGER",
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
  "label_part", "const_part", "const_expr_list", "const_value",
  "type_part", "type_decl_list", "type_definition", "type_decl",
  "simple_type_decl", "array_type_decl", "array_type_range_decl",
  "record_type_decl", "field_decl_list", "field_decl", "name_list",
  "var_part", "var_decl_list", "var_decl", "routine_part", "function_decl",
  "function_head", "procedure_decl", "procedure_head", "parameters",
  "para_decl_list", "para_type_list", "var_para_list", "val_para_list",
  "routine_body", "compound_stmt", "stmt_list", "stmt", "non_label_stmt",
  "assign_stmt", "proc_stmt", "if_stmt", "else_clause", "repeat_stmt",
  "while_stmt", "for_stmt", "direction", "case_stmt", "case_expr_list",
  "case_expr", "goto_stmt", "expression_list", "expression", "expr",
  "term", "factor", "args_list", "T_ID", 0
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
      73,    74,    74,    75,    75,    75,    75,    75,    76,    76,
      77,    77,    78,    79,    79,    79,    80,    80,    80,    81,
      82,    82,    82,    82,    83,    84,    84,    85,    86,    86,
      87,    87,    88,    88,    89,    90,    90,    90,    90,    90,
      91,    92,    93,    94,    95,    95,    96,    96,    97,    97,
      98,    99,   100,   101,   102,   102,   103,   103,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   105,   105,   105,
     106,   106,   106,   106,   106,   107,   108,   108,   109,   110,
     111,   112,   112,   113,   114,   114,   115,   115,   116,   117,
     117,   118,   118,   118,   118,   118,   118,   118,   119,   119,
     119,   119,   120,   120,   120,   120,   120,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   122,   122,   123,
     123,   123,   123,   123
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     3,     2,     2,     5,     0,     2,
       0,     5,     4,     1,     1,     1,     1,     1,     2,     0,
       2,     1,     4,     1,     1,     1,     1,     1,     3,     6,
       3,     4,     5,     3,     3,     2,     1,     4,     3,     1,
       2,     0,     2,     1,     4,     2,     2,     1,     1,     0,
       4,     5,     4,     3,     3,     0,     3,     1,     3,     3,
       2,     1,     1,     3,     3,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     6,     5,
       1,     1,     4,     4,     4,     5,     2,     0,     4,     4,
       8,     1,     1,     5,     2,     1,     4,     4,     2,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     1,     4,     1,
       4,     1,     3,     2,     2,     4,     3,     3,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     8,   129,   130,   131,   132,   133,
       0,     1,     0,     0,    10,     4,     3,    65,     5,    62,
       0,    19,     0,     0,     9,     0,    41,     0,   132,     0,
       0,    63,     0,     0,     0,    65,     0,    70,     0,    67,
      68,    69,    71,    72,    73,    74,    75,    76,    81,     0,
       0,     0,    18,    21,     0,    49,     0,     0,     0,   117,
      16,    13,    14,    15,    17,   119,     0,     0,     0,   121,
       0,   107,   111,   116,     0,     0,    98,     0,     0,     0,
      64,     0,     0,     0,     0,    17,     0,     0,     0,    20,
       0,    40,    43,    39,     0,     0,     7,    47,     0,    48,
       0,    66,     0,   100,     0,     0,     0,   123,     0,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,     0,     0,     0,    77,    12,     0,    27,    26,     0,
       0,     0,     0,    23,    24,    25,     0,     0,    42,    55,
      55,    45,    46,     8,     8,    83,     0,    84,     0,     0,
     122,     0,     0,    95,     0,   106,   101,   102,   103,   104,
     105,   110,   108,   109,   115,   113,   114,   112,     0,   126,
       0,    87,    88,    89,    82,     0,     0,     0,    11,     0,
       0,    36,     0,     0,    22,    38,     0,     0,     0,    53,
       0,     0,     0,    99,   118,   120,     0,    93,    94,     0,
     125,    92,    91,     0,     0,    85,   127,     0,    79,     0,
       0,     0,     0,    34,    35,     0,    28,    44,     0,    61,
       0,    57,     0,     0,     0,    50,     6,    52,     0,     0,
       0,    86,    78,     0,     0,     0,     0,     0,    60,    54,
       0,     0,     0,    51,    96,    97,     0,    33,     0,    30,
       0,    37,    56,    58,    59,    90,     0,    31,    29,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    12,   200,   201,    14,    21,    24,
      69,    26,    52,    53,   142,   143,   144,   222,   145,   190,
     191,    90,    55,    91,    92,    96,    97,    98,    99,   100,
     198,   230,   231,   232,   233,    18,    37,    22,    38,    39,
      40,    41,    42,   215,    43,    44,    45,   213,    46,   162,
     163,    47,   102,   130,    71,    72,    73,   131,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -223
static const yytype_int16 yypact[] =
{
     -28,   285,    46,  -223,  -223,  -223,  -223,  -223,  -223,  -223,
     -13,  -223,    16,    40,    62,  -223,  -223,  -223,  -223,  -223,
      55,    47,   154,    36,   102,   114,   110,   103,     3,   112,
     139,  -223,   285,   170,   139,  -223,   139,  -223,   115,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,   106,   212,
     121,   123,   114,  -223,   285,    20,   274,   139,   139,   -33,
    -223,  -223,  -223,  -223,    75,    52,   139,   139,   139,  -223,
      61,     8,    60,  -223,    82,   124,  -223,   263,   219,   180,
    -223,   139,   139,   285,   139,  -223,   119,   212,    32,  -223,
      86,   285,  -223,  -223,   173,   184,    20,  -223,   129,  -223,
     130,  -223,   -37,   336,   152,   139,   139,  -223,   292,  -223,
     377,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   285,   139,   255,   139,   255,
     336,     1,   305,   140,   336,  -223,   137,  -223,  -223,   155,
     285,   285,   142,  -223,  -223,  -223,   285,    32,  -223,   158,
     158,  -223,  -223,  -223,  -223,  -223,   139,  -223,    14,    57,
    -223,   157,   322,  -223,   159,     8,     8,     8,     8,     8,
       8,    60,    60,    60,  -223,  -223,  -223,  -223,   318,  -223,
     193,   185,   336,  -223,  -223,   139,   150,   139,  -223,    19,
     332,  -223,   122,    59,  -223,  -223,   151,    84,   171,  -223,
     161,    40,   162,   336,  -223,  -223,   255,  -223,  -223,   255,
    -223,  -223,  -223,   139,   255,  -223,   336,   139,   336,   179,
     212,   181,   199,  -223,  -223,    32,  -223,  -223,   285,   206,
      -4,  -223,   207,   210,    38,  -223,  -223,  -223,   209,   211,
     249,  -223,   336,   267,   213,   212,   243,   214,   206,  -223,
      84,    38,    38,  -223,  -223,  -223,   255,  -223,    29,  -223,
      32,  -223,  -223,  -223,  -223,  -223,   212,  -223,  -223,  -223
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -223,  -223,  -223,  -223,  -223,   126,   289,  -223,  -223,  -223,
     -48,  -223,  -223,   237,  -144,  -222,  -223,  -223,  -223,  -223,
     125,  -121,  -223,  -223,   221,  -223,   208,  -223,   217,  -223,
     164,  -223,    66,  -223,  -223,   104,   -11,   284,  -123,   272,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,
     174,  -223,  -223,   -25,   287,    17,   -50,     6,    -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -132
static const yytype_int16 yytable[] =
{
      10,    86,    19,   196,   181,    70,   183,     1,   104,    77,
     155,    79,   253,   105,   156,  -129,   107,  -129,   109,   192,
     193,    48,   219,    60,    61,   -80,    62,    63,    85,   263,
     264,    75,   103,    60,    61,   137,    62,    63,    85,   136,
     117,   137,   108,   249,   138,    94,    11,   139,   184,    57,
     138,    15,   185,    93,    95,    48,    17,   132,    23,   134,
     250,   204,   161,   118,   119,   185,    16,   -80,   140,   192,
     174,   175,   176,   177,   120,   220,   229,    48,   141,   121,
      20,   247,   133,   238,   141,   266,   239,     5,    25,   122,
      93,   241,   110,     6,     7,     8,     9,    49,   106,   178,
    -131,   180,  -131,   182,   205,    50,   226,   248,   185,   164,
     146,   158,   159,   123,   161,   111,   268,    51,   112,   113,
     114,   115,   116,  -130,   179,  -130,    48,   228,    48,   229,
     124,   203,   125,   265,   171,   172,   173,   146,   147,    93,
      93,   221,    59,    60,    61,   195,    62,    63,    64,    65,
       8,     9,    81,    54,    82,    56,    83,     5,    58,    27,
     216,   164,   218,     6,     7,    28,     9,    29,    84,    66,
      17,    30,   244,   146,   225,    76,   149,    31,    32,    80,
      33,    34,    87,   135,    88,    67,   126,   150,   240,    93,
      19,    35,   242,   153,   154,    68,    93,   259,    36,   157,
     129,   188,   187,   189,   197,    48,   194,   214,    48,   206,
     267,   209,   217,    48,   211,   227,    60,    61,   269,    62,
      63,    85,     5,   234,    27,   235,   237,    93,     6,     7,
      28,     9,    29,   212,   111,    17,    30,   112,   113,   114,
     115,   116,   243,    32,   245,    33,    34,   111,   246,    93,
     112,   113,   114,   115,   116,    48,    35,   146,     5,   251,
      27,   128,   252,    36,     6,     7,    28,     9,    29,   256,
     257,    17,    30,   254,   260,   255,   258,     5,   261,    32,
     202,    33,    34,     6,     7,    28,     9,    29,     5,    89,
      17,    30,    35,    13,     6,     7,     8,     9,    32,    36,
      33,    34,   127,   111,   151,   236,   112,   113,   114,   115,
     116,    35,   148,   152,   199,   224,   262,   111,    36,    78,
     112,   113,   114,   115,   116,     5,    60,    61,   101,    62,
      63,    64,     7,     8,     9,     5,   208,     0,     0,   160,
       0,     6,     7,     8,     9,   207,   111,     0,     0,   112,
     113,   114,   115,   116,   186,   223,     0,     0,     0,   111,
       0,     0,   112,   113,   114,   115,   116,   210,     0,     0,
       0,     0,   111,     0,     0,   112,   113,   114,   115,   116,
       5,    60,    61,     0,    62,    63,    64,     7,     8,     9,
     111,     0,     0,   112,   113,   114,   115,   116,   165,   166,
     167,   168,   169,   170
};

static const yytype_int16 yycheck[] =
{
       1,    49,    13,   147,   127,    30,   129,    35,    58,    34,
      47,    36,   234,    46,    51,    48,    66,    50,    68,   140,
     141,    22,     3,     4,     5,    22,     7,     8,     9,   251,
     252,    32,    57,     4,     5,     3,     7,     8,     9,    87,
      32,     3,    67,    47,    12,    25,     0,    15,    47,    46,
      12,    64,    51,    54,    34,    56,    16,    82,     3,    84,
      64,    47,   110,    55,    56,    51,    50,    64,    36,   190,
     120,   121,   122,   123,    14,    56,   197,    78,    46,    19,
      18,   225,    83,   206,    46,    56,   209,     3,    41,    29,
      91,   214,    31,     9,    10,    11,    12,    61,    46,   124,
      48,   126,    50,   128,    47,     3,    47,   228,    51,   110,
      51,   105,   106,    53,   162,    54,   260,     3,    57,    58,
      59,    60,    61,    48,   125,    50,   127,    43,   129,   250,
      48,   156,    50,   256,   117,   118,   119,    51,    52,   140,
     141,   189,     3,     4,     5,   146,     7,     8,     9,    10,
      11,    12,    46,    43,    48,    52,    50,     3,    46,     5,
     185,   162,   187,     9,    10,    11,    12,    13,    62,    30,
      16,    17,   220,    51,    52,     5,     3,    23,    24,    64,
      26,    27,    61,    64,    61,    46,    62,     3,   213,   190,
     201,    37,   217,    64,    64,    56,   197,   245,    44,    47,
      20,    64,    62,    48,    46,   206,    64,    22,   209,    52,
     258,    52,    62,   214,    21,    64,     4,     5,   266,     7,
       8,     9,     3,    52,     5,    64,    64,   228,     9,    10,
      11,    12,    13,    40,    54,    16,    17,    57,    58,    59,
      60,    61,    63,    24,    63,    26,    27,    54,    49,   250,
      57,    58,    59,    60,    61,   256,    37,    51,     3,    52,
       5,    42,    52,    44,     9,    10,    11,    12,    13,    20,
       3,    16,    17,    64,    31,    64,    63,     3,    64,    24,
     154,    26,    27,     9,    10,    11,    12,    13,     3,    52,
      16,    17,    37,     4,     9,    10,    11,    12,    24,    44,
      26,    27,    39,    54,    96,   201,    57,    58,    59,    60,
      61,    37,    91,    96,   150,   190,   250,    54,    44,    35,
      57,    58,    59,    60,    61,     3,     4,     5,    56,     7,
       8,     9,    10,    11,    12,     3,   162,    -1,    -1,    47,
      -1,     9,    10,    11,    12,    23,    54,    -1,    -1,    57,
      58,    59,    60,    61,    49,    23,    -1,    -1,    -1,    54,
      -1,    -1,    57,    58,    59,    60,    61,    49,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    57,    58,    59,    60,    61,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    12,
      54,    -1,    -1,    57,    58,    59,    60,    61,   111,   112,
     113,   114,   115,   116
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    35,    66,    67,    68,     3,     9,    10,    11,    12,
     123,     0,    69,    71,    72,    64,    50,    16,   100,   101,
      18,    73,   102,     3,    74,    41,    76,     5,    11,    13,
      17,    23,    24,    26,    27,    37,    44,   101,   103,   104,
     105,   106,   107,   109,   110,   111,   113,   116,   123,    61,
       3,     3,    77,    78,    43,    87,    52,    46,    46,     3,
       4,     5,     7,     8,     9,    10,    30,    46,    56,    75,
     118,   119,   120,   121,   123,   123,     5,   118,   102,   118,
      64,    46,    48,    50,    62,     9,    75,    61,    61,    78,
      86,    88,    89,   123,    25,    34,    90,    91,    92,    93,
      94,   104,   117,   118,   121,    46,    46,   121,   118,   121,
      31,    54,    57,    58,    59,    60,    61,    32,    55,    56,
      14,    19,    29,    53,    48,    50,    62,    39,    42,    20,
     118,   122,   118,   123,   118,    64,    75,     3,    12,    15,
      36,    46,    79,    80,    81,    83,    51,    52,    89,     3,
       3,    91,    93,    64,    64,    47,    51,    47,   122,   122,
      47,    75,   114,   115,   123,   119,   119,   119,   119,   119,
     119,   120,   120,   120,   121,   121,   121,   121,   118,   123,
     118,   103,   118,   103,    47,    51,    49,    62,    64,    48,
      84,    85,    86,    86,    64,   123,    79,    46,    95,    95,
      70,    71,    70,   118,    47,    47,    52,    23,   115,    52,
      49,    21,    40,   112,    22,   108,   118,    62,   118,     3,
      56,    75,    82,    23,    85,    52,    47,    64,    43,    86,
      96,    97,    98,    99,    52,    64,   100,    64,   103,   103,
     118,   103,   118,    63,    75,    63,    49,    79,    86,    47,
      64,    52,    52,    80,    64,    64,    20,     3,    63,    75,
      31,    64,    97,    80,    80,   103,    56,    75,    79,    75
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
#line 47 "SPL_parse.y"
    {;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 50 "SPL_parse.y"
    {;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 53 "SPL_parse.y"
    {;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 55 "SPL_parse.y"
    {;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 57 "SPL_parse.y"
    {;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 60 "SPL_parse.y"
    {;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 61 "SPL_parse.y"
    {;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 63 "SPL_parse.y"
    {;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 64 "SPL_parse.y"
    {;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 66 "SPL_parse.y"
    {;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 67 "SPL_parse.y"
    {;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 69 "SPL_parse.y"
    {;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 70 "SPL_parse.y"
    {;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 71 "SPL_parse.y"
    {;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 72 "SPL_parse.y"
    {;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 73 "SPL_parse.y"
    {;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 75 "SPL_parse.y"
    {;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 76 "SPL_parse.y"
    {;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 78 "SPL_parse.y"
    {;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 79 "SPL_parse.y"
    {;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 81 "SPL_parse.y"
    {;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 83 "SPL_parse.y"
    {;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 84 "SPL_parse.y"
    {;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 85 "SPL_parse.y"
    {;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 87 "SPL_parse.y"
    {;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 88 "SPL_parse.y"
    {;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 89 "SPL_parse.y"
    {;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 91 "SPL_parse.y"
    {;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 93 "SPL_parse.y"
    {;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 94 "SPL_parse.y"
    {;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 95 "SPL_parse.y"
    {;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 96 "SPL_parse.y"
    {;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 98 "SPL_parse.y"
    {;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 100 "SPL_parse.y"
    {;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 101 "SPL_parse.y"
    {;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 103 "SPL_parse.y"
    {;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 105 "SPL_parse.y"
    {;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 106 "SPL_parse.y"
    {;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 108 "SPL_parse.y"
    {;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 109 "SPL_parse.y"
    {;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 111 "SPL_parse.y"
    {;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 112 "SPL_parse.y"
    {;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 114 "SPL_parse.y"
    {;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 116 "SPL_parse.y"
    {;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 117 "SPL_parse.y"
    {;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 118 "SPL_parse.y"
    {;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 119 "SPL_parse.y"
    {;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 120 "SPL_parse.y"
    {;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 122 "SPL_parse.y"
    {;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 124 "SPL_parse.y"
    {;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 126 "SPL_parse.y"
    {;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 128 "SPL_parse.y"
    {;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 130 "SPL_parse.y"
    {;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 131 "SPL_parse.y"
    {;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 133 "SPL_parse.y"
    {;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 134 "SPL_parse.y"
    {;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 136 "SPL_parse.y"
    {;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 137 "SPL_parse.y"
    {;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 139 "SPL_parse.y"
    {;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 141 "SPL_parse.y"
    {;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 143 "SPL_parse.y"
    {;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 145 "SPL_parse.y"
    {;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 147 "SPL_parse.y"
    {;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 148 "SPL_parse.y"
    {;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 150 "SPL_parse.y"
    {;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 151 "SPL_parse.y"
    {;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 153 "SPL_parse.y"
    {;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 154 "SPL_parse.y"
    {;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 155 "SPL_parse.y"
    {;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 156 "SPL_parse.y"
    {;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 157 "SPL_parse.y"
    {;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 158 "SPL_parse.y"
    {;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 159 "SPL_parse.y"
    {;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 160 "SPL_parse.y"
    {;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 161 "SPL_parse.y"
    {;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 163 "SPL_parse.y"
    {;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 164 "SPL_parse.y"
    {/*array element*/;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 165 "SPL_parse.y"
    {/*record element*/;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 167 "SPL_parse.y"
    {;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 168 "SPL_parse.y"
    {;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 169 "SPL_parse.y"
    {;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 170 "SPL_parse.y"
    {;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 171 "SPL_parse.y"
    {;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 173 "SPL_parse.y"
    {;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 175 "SPL_parse.y"
    {;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 176 "SPL_parse.y"
    {;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 178 "SPL_parse.y"
    {;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 180 "SPL_parse.y"
    {;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 182 "SPL_parse.y"
    {;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 184 "SPL_parse.y"
    {;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 185 "SPL_parse.y"
    {;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 187 "SPL_parse.y"
    {;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 189 "SPL_parse.y"
    {;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 190 "SPL_parse.y"
    {;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 192 "SPL_parse.y"
    {;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 193 "SPL_parse.y"
    {;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 195 "SPL_parse.y"
    {;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 197 "SPL_parse.y"
    {;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 198 "SPL_parse.y"
    {;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 200 "SPL_parse.y"
    {;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 201 "SPL_parse.y"
    {;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 202 "SPL_parse.y"
    {;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 203 "SPL_parse.y"
    {;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 204 "SPL_parse.y"
    {;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 205 "SPL_parse.y"
    {;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 206 "SPL_parse.y"
    {;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 208 "SPL_parse.y"
    {;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 209 "SPL_parse.y"
    {;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 210 "SPL_parse.y"
    {;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 211 "SPL_parse.y"
    {;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 213 "SPL_parse.y"
    {;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 214 "SPL_parse.y"
    {;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 215 "SPL_parse.y"
    {;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 216 "SPL_parse.y"
    {;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 217 "SPL_parse.y"
    {;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 219 "SPL_parse.y"
    {;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 220 "SPL_parse.y"
    {/*self-defined function with parameters*/;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 221 "SPL_parse.y"
    {;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 222 "SPL_parse.y"
    {;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 223 "SPL_parse.y"
    {;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 224 "SPL_parse.y"
    {;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 225 "SPL_parse.y"
    {;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 226 "SPL_parse.y"
    {;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 227 "SPL_parse.y"
    {;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 228 "SPL_parse.y"
    {;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 230 "SPL_parse.y"
    {;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 231 "SPL_parse.y"
    {;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 235 "SPL_parse.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 236 "SPL_parse.y"
    {
		switch((yyvsp[(1) - (1)].conval)){
			case SYS_CON_FALSE:  (yyval.sval) = "false"; break;
			case SYS_CON_TRUE:   (yyval.sval) = "true"; break;
			case SYS_CON_MAXINT: (yyval.sval) = "maxint"; break;
		}
	;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 243 "SPL_parse.y"
    {
		switch((yyvsp[(1) - (1)].functval)){
			case SYS_FUNCT_ABS: (yyval.sval) = "abs"; break;
			case SYS_FUNCT_CHR: (yyval.sval) = "chr"; break;
			case SYS_FUNCT_ODD: (yyval.sval) = "odd"; break;
			case SYS_FUNCT_ORD: (yyval.sval) = "ord"; break;
			case SYS_FUNCT_PRED:(yyval.sval) = "pred"; break;
			case SYS_FUNCT_SQR: (yyval.sval) = "sqr"; break;
			case SYS_FUNCT_SQRT:(yyval.sval) = "sqrt"; break;
			case SYS_FUNCT_SUCC:(yyval.sval) = "succ"; break;
		}
	;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 255 "SPL_parse.y"
    {
		switch((yyvsp[(1) - (1)].procval)){
			case SYS_PROC_WRITE:   (yyval.sval) = "write"; break;
			case SYS_PROC_WRITELN: (yyval.sval) = "writeln"; break;
		}
	;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 261 "SPL_parse.y"
    {
		switch((yyvsp[(1) - (1)].typeval)){
			case SYS_TYPE_BOOLEAN: (yyval.sval) = "boolean"; break;
			case SYS_TYPE_CHAR:    (yyval.sval) = "char"; break;
			case SYS_TYPE_INTEGER: (yyval.sval) = "integer"; break;
			case SYS_TYPE_REAL:    (yyval.sval) = "real"; break;
		}
	;}
    break;



/* Line 1455 of yacc.c  */
#line 2684 "SPL_parse.c"
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
#line 270 "SPL_parse.y"

int main(){
	yyparse();
	return 0;
}

int yyerror(char *s) 
{ 
     fprintf(stderr, "%s\n", s); 
     return 0; 
}
