/*
 * absyn.h - Abstract Syntax Header
 *
 */

/* Type Definitions */
#ifndef _ABSYN_H
#define _ABSYN_H

struct YYLTYPE;
typedef struct YYLTYPE A_pos;

typedef struct A_pro_st *A_pro;
typedef struct A_routine_st *A_routine;
typedef struct A_routineHead_st *A_routineHead;
typedef struct A_dec_st *A_dec;
typedef struct A_const_st *A_const;
typedef struct A_type_st *A_type;
typedef struct A_simple_st *A_simple;
typedef struct A_array_st *A_array;
typedef struct A_range_st *A_range;
typedef struct A_name_st *A_name;
typedef struct A_field_st *A_field;
typedef struct A_varDecList_st *A_varDecList;
typedef struct A_routinePart_st *A_routinePart;
typedef struct A_routinePartHead_st *A_routinePartHead;
typedef struct A_paraList_st *A_paraList;
typedef struct A_paraField_st *A_paraField;
typedef struct A_stmt_st *A_stmt;
typedef struct A_case_st *A_case;
typedef struct A_proc_st *A_proc;
typedef struct A_exp_st *A_exp;
typedef struct A_var_st *A_var;
typedef struct A_decList_st *A_decList;
typedef struct A_nameList_st *A_nameList;
typedef struct A_fieldList_st *A_fieldList;
typedef struct A_stmtList_st *A_stmtList;
typedef struct A_caseList_st *A_caseList;
typedef struct A_expList_st *A_expList;


#include "symbol.h"
#include "type.h"
#include "SPL_parse.h"

struct A_pro_st{
	A_pos pos;
	S_symbol name;
	A_routine routine;
};


struct A_routine_st{
	A_pos pos;
	A_routineHead head;
	A_stmtList compoundStmt;
};


struct A_routineHead_st{
	A_pos pos;
	A_decList constPart;
	A_decList typePart;
	A_decList varPart; 
	A_decList routinePart;
};

enum A_dec_st_kind {
	A_constDec,
	A_typeDec,
	A_varDec,
	A_routineDec,
} ;
struct A_dec_st{
	A_dec_st_kind kind;
	A_pos pos;
	S_symbol name;
	union {
		A_const value;
		A_type type;
		A_varDecList var;
		A_routinePart routine;
	} u;
};

// typedef enum A_sysType_en {
// 	A_boolean, A_char, A_integer, A_real, A_string
// } A_sysType;

typedef SysType A_sysType;

struct A_const_st {
	A_pos pos;
	A_sysType kind;
	union {
		int integer;
		double real;
		char ch;
		char *str;
		int boolean;
	} u;
};


enum A_range_st_kind { A_constRange, A_nameRange };
struct A_range_st{
	A_range_st_kind kind;
	A_pos pos;
	union {
		A_const lconst;
		S_symbol lname;
	} lower_u;
	union {
		A_const uconst;
		S_symbol uname;
	} upper_u;
};

enum A_simple_st_kind{
	A_simpleSysType,
	A_simpleNameType,
	A_simpleNameListType,
	A_simpleRangeType
};
struct A_simple_st{
	A_simple_st_kind kind;
	A_pos pos;
	union {
		A_sysType sysType;
		S_symbol name;
		A_nameList nameList;
		A_range range;
	} u;
};



struct A_array_st{
	A_pos pos;
	A_range range;
	A_type type;
};

enum A_type_st_kind{
	A_simpleType,
	A_arrayType,
	A_recordType
};
struct A_type_st {
	A_type_st_kind kind;
	A_pos pos;
	union {
		A_simple simple;
		A_array array;
		A_fieldList fieldList;
	} u;			
};

struct A_name_st {
	A_pos pos;
	S_symbol name;
};

struct A_field_st {
	A_pos pos;
	A_nameList nameList;
	A_type type;
};

struct A_varDecList_st {
	A_pos pos;
	A_nameList nameList;
	A_type type;
};

enum routineKind {A_function, A_procedure};

struct A_routinePart_st {
	A_routinePartHead head;
	A_routine subRoutine;
};

struct A_routinePartHead_st {
	routineKind kind;
	A_pos pos;
	S_symbol name;
	A_paraList parameters;
	A_simple simpleType;
};

enum paraKind {Var, Value};
struct A_paraList_st {
	A_paraField field;
	A_paraList next;
};

struct A_paraField_st
{
	// kind: Var->left value; Value->right value
	paraKind kind;
	A_pos pos;
	A_simple simpleType;
	A_nameList nameList;
};

typedef struct A_assignStmt_st {A_var var; A_exp exp;} A_assignS;
typedef struct A_compoundStmt_st {A_stmtList substmtList;} A_compoundS;
typedef struct A_ifStmt_st {A_exp test; A_stmt thenStmt; A_stmt elseStmt;} A_ifS;
typedef struct A_repeatStmt_st {A_exp test; A_stmtList body;} A_repeatS;
typedef struct A_whileStmt_st {A_exp test; A_stmt body;} A_whileS;
typedef struct A_forStmt_st {A_var var; A_exp initValue; int direction; A_exp finalValue; A_stmt body;} A_forS;
typedef struct A_caseStmt_st {A_exp test; A_caseList caselist;} A_caseS;
typedef struct A_gotoStmt_st {int label;} A_gotoS;

enum A_stmt_st_kind {
	A_assignStmt, A_procStmt, A_compundStmt,
	A_ifStmt, A_repeatStmt, A_whileStmt,
	A_forStmt, A_caseStmt, A_gotoStmt
} ;
struct A_stmt_st { 
	A_stmt_st_kind kind;
	A_pos pos;
	int label;
	union{
		A_assignS assignStmt;
		A_proc procStmt;
		A_ifS ifStmt;
		A_repeatS repeatStmt;
		A_whileS whileStmt;
		A_forS forStmt;
		A_caseS caseStmt;
		A_gotoS gotoStmt;
		A_compoundS compoundStmt;
	} u;
};

struct A_case_st {
	A_pos pos;
	A_const constValue;
	S_symbol name;
	A_stmt body;
};
// typedef enum {
// 	A_plusOp, A_minusOp, A_timesOp, A_modOp, A_divideOp,
// 	A_eqOp, A_neqOp, A_ltOp, A_leOp, A_gtOp, A_geOp
// } A_oper;
typedef OperatorType A_oper;

typedef struct A_op_st {A_oper oper; A_exp left; A_exp right;} *A_op;

enum A_exp_st_kind{ A_funcExp, A_nameExp, A_varExp, A_constExp, A_opExp };
struct A_exp_st {
	A_exp_st_kind kind;
	A_pos pos;
	A_type valueType;
	union{
		A_proc func;
		A_var var;
		A_const constValue;
		A_op op;
		S_symbol name;
	}u;
};

struct A_proc_st {
	enum routineKind kind;
	A_pos pos;
	S_symbol name;
	A_expList args;
};

enum A_var_st_kind { A_pureID, A_arrayElement, A_recordField };
struct A_var_st
{
	A_var_st_kind kind;
	S_symbol ID;
	A_type valueType;
	union{
		A_exp subscript;
		S_symbol fieldID;
	}u;
};

/*linked lists*/
struct A_decList_st {
	A_dec head;
	struct A_decList_st *next;
};

struct A_nameList_st {
	A_name head;
	struct A_nameList_st *next;
};

struct A_fieldList_st {
	A_field head;
	struct A_fieldList_st *next;
};
struct A_stmtList_st {
	A_stmt head;
	struct A_stmtList_st *next;
};

struct A_caseList_st {
	A_case head;
	struct A_caseList_st *next;
};

struct A_expList_st {
	A_exp head;
	struct A_expList_st *next;
};


/* Function Prototypes */
A_pro A_Program(A_pos pos, S_symbol name, A_routine routine);
A_routine A_Routine(A_pos pos, A_routineHead head, A_stmtList compoundStmt);

/*routine head*/
A_routineHead A_RoutineHead(A_pos pos, A_decList constPart, A_decList typePart, A_decList varPart, A_decList routinePart);
A_decList A_DecList(A_dec head, A_decList next);
/*const part*/
A_dec A_ConstDec(A_pos pos, S_symbol name, A_const value);
A_const A_Integer(A_pos pos, int i);//const_value
A_const A_Real(A_pos pos, double r);
A_const A_Char(A_pos pos, char c);
A_const A_String(A_pos pos, char *s);
A_const A_Bool(A_pos pos, int b);

/*type part*/
A_dec A_TypeDec(A_pos pos, S_symbol name, A_type type);//type_definition

A_type A_SimpleType(A_pos pos, A_simple simple);
A_simple A_SimpleSysType(A_pos pos, A_sysType systype);
A_simple A_SimpleRangeType(A_pos pos, A_range range);
A_simple A_SimpleNameType(A_pos pos, S_symbol name);
A_simple A_SimpleNameListType(A_pos pos, A_nameList namelist);

A_range A_ConstRange(A_pos pos, A_const lo, A_const up);
A_range A_NameRange(A_pos pos, S_symbol lo, S_symbol up);
A_nameList A_NameList(A_name head, A_nameList next);
A_name A_Name(A_pos pos, S_symbol name);

A_array A_Array(A_pos pos, A_range range, A_type type);
A_type A_ArrayType(A_pos pos, A_array array);
A_type A_RecordType(A_pos pos, A_fieldList fieldList);
A_fieldList A_FieldList(A_field head, A_fieldList next);
A_field A_Field(A_pos pos, A_nameList nameList, A_type type);

/*var part*/
A_dec A_VarDec(A_pos pos, A_varDecList var);
A_varDecList A_VarDecList(A_pos pos, A_nameList nameList, A_type type);

/*routine part*/
A_dec A_RoutinePartDec(A_pos pos, A_routinePart routine);
A_routinePart A_RoutinePart(A_routinePartHead head, A_routine subRoutine);
A_routinePartHead A_FuncHead(A_pos pos, S_symbol name, A_paraList parameters, A_simple simpleType);
A_routinePartHead A_ProcHead(A_pos pos, S_symbol name, A_paraList parameters);
//procedure is treated as a special kind function

A_paraList A_ParaList(A_paraField field, A_paraList next);
A_paraField A_VarParaField(A_pos pos,A_nameList nameList, A_simple simpleType);
A_paraField A_ValParaField(A_pos pos, A_nameList nameList, A_simple simpleType);

/* A_var represents the left-values in the routine body, which means it will only be checked in AssignStmt or ForStmt*/
/* BTW, you may have noticed that A_var also appears in A_exp, which represents a right value. Actually the A_var node hanging under A_exp won't be checked as a tree node but a member of A_exp.*/
A_var A_Var(A_pos pos, S_symbol ID);
A_var A_ArrayElement(A_pos pos, S_symbol ID, A_exp subscript);
A_var A_RecordField(A_pos pos, S_symbol ID, S_symbol fieldID);

A_proc A_Proc(A_pos pos, S_symbol function, A_expList args);
/*stmt*/
A_stmtList A_StmtList(A_stmt head, A_stmtList next);
A_stmt A_LabelStmt(A_pos pos, int label, A_stmt stmt);
A_stmt A_AssignStmt(A_pos pos, A_var var, A_exp exp);
A_stmt A_ProcStmt(A_pos pos, A_proc proc);//call sys_proc or funtion
A_stmt A_CompoundStmt(A_pos pos, A_stmtList substmtList);
A_stmt A_IfStmt(A_pos pos, A_exp test, A_stmt thenStmt, A_stmt elseStmt);
A_stmt A_RepeatStmt(A_pos pos, A_exp test, A_stmtList body);
A_stmt A_WhileStmt(A_pos pos, A_exp test, A_stmt body);
/*direction = 1 or -1, representing the length of one step*/
A_stmt A_ForStmt(A_pos pos, A_var var, A_exp initValue, int direction, A_exp finalValue, A_stmt body);
A_stmt A_CaseStmt(A_pos pos, A_exp test, A_caseList caselist);
A_stmt A_GotoStmt(A_pos pos, int label);

A_caseList A_CaseList(A_case head, A_caseList next);
/*Either constValue or name would be NULL.*/
A_case A_Case(A_pos pos, A_const constValue, S_symbol name, A_stmt body);

/*expression*/
A_expList A_ExpList(A_exp head, A_expList next);
// a name unknown to be a Var, a const var or a Funct without parameter list yet. It might be replaced in Semantic Analysis.
A_exp A_NameExp(A_pos pos, S_symbol name);
// specifically created for array elements or record fields
A_exp A_VarExp(A_pos pos, A_var var);
A_exp A_FuncExp(A_pos pos, A_proc func);
A_exp A_ConstExp(A_pos pos, A_const constValue);
A_exp A_OpExp(A_pos pos, A_oper oper, A_exp left, A_exp right);


#endif

