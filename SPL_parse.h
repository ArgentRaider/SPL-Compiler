
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 155 "SPL_parse.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

extern YYLTYPE yylloc;

