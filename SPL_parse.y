%{
	#define YYERROR_VERBOSE 1

	#include <stdio.h>
	#include <string.h>
	#include <time.h>
	#include "errormsg.h"
	#include "symbol.h"
	#include "type.h"
	#include "absyn.h"
	A_pro root = NULL;
%}

%union{
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
}

%start s

%locations

%token<sval> T_STRING
%token<sval> T_NAME
%token<ival> T_INTEGER T_BOOLEAN
%token<fval> T_REAL
%token<cval> T_CHAR

%token<conval> T_SYS_CON
%token<functval> T_SYS_FUNCT
%token<procval> T_SYS_PROC
%token<typeval> T_SYS_TYPE

%token T_READ
%token T_AND T_ARRAY T_BEGIN T_CASE T_CONST T_DIV T_DO T_DOWNTO T_ELSE T_END T_FOR T_FUNCTION T_GOTO T_IF
%token T_IN T_MOD T_NOT T_OF T_OR T_PACKED T_PROCEDURE T_PROGRAM T_RECORD T_REPEAT T_SET T_THEN
%token T_TO T_TYPE T_UNTIL T_VAR T_WHILE T_WITH
%token T_LP T_RP T_LB T_RB T_DOT T_COMMA T_COLON T_MUL T_UNEQUAL T_PLUS T_MINUS T_GE T_GT T_LE T_LT
%token T_EQUAL T_ASSIGN T_DOTDOT T_SEMI

%type<s_symbol> T_ID
%type<a_prog> program
%type<s_symbol> program_head
%type<a_routine> routine sub_routine
%type<a_routineHead> routine_head
%type<a_stmtList> stmt_list routine_body
%type<a_decList> const_part type_part var_part routine_part
%type<a_decList> const_expr_list type_decl_list var_decl_list
%type<a_dec> const_dec type_definition
%type<a_constval> const_value
%type<a_type> type_decl
%type<a_simple> simple_type_decl
%type<a_array> array_type_decl
%type<a_fieldList> record_type_decl field_decl_list
%type<a_nameList> name_list var_para_list val_para_list
%type<a_range> array_type_range_decl
%type<a_field> field_decl
%type<a_varDecList> var_decl
%type<a_dec> function_decl procedure_decl
%type<a_routinePartHead> function_head procedure_head
%type<a_paraList> parameters para_decl_list
%type<a_paraField> para_type_list
%type<a_stmt> stmt non_label_stmt assign_stmt proc_stmt compound_stmt if_stmt repeat_stmt while_stmt for_stmt case_stmt goto_stmt	else_clause
%type<a_exp> expression expr term factor
%type<ival> direction
%type<a_caseList> case_expr_list
%type<a_case> case_expr
%type<a_expList> expression_list
%% 
s:
	program						{root = $1;}

program 
	: program_head routine T_DOT	{$$ = A_Program(@$, $1, $2);}

program_head
	: T_PROGRAM T_ID T_SEMI		{$$ = $2;}
routine
	: routine_head routine_body	{$$ = A_Routine(@$, $1, $2);}
sub_routine
	: routine_head routine_body	{$$ = A_Routine(@$, $1, $2);}

routine_head
	: label_part const_part type_part var_part routine_part	
		{$$ = A_RoutineHead(@$, $2, $3, $4, $5);}
label_part: {}
const_part 
	: T_CONST const_expr_list		{$$ = $2;}
	|								{$$ = NULL;}
const_expr_list
	: const_expr_list const_dec	{$$ = A_DecList($2, $1);}
	| const_dec					{$$ = A_DecList($1, NULL);}
const_dec
	: T_NAME T_EQUAL const_value T_SEMI		{$$ = A_ConstDec(@$, S_Symbol($1), $3);}
const_value
	: T_INTEGER					{$$ = A_Integer(@1, $1);}
	| T_REAL					{$$ = A_Real(@1, $1);}
	| T_CHAR					{$$ = A_Char(@1, $1);}
	| T_STRING					{$$ = A_String(@1, $1);}
	| T_SYS_CON					{
		switch($1){
			case SYS_CON_FALSE: $$ = A_Bool(@1, 0); break;
			case SYS_CON_TRUE: $$ = A_Bool(@1, 1); break;
			case SYS_CON_MAXINT: $$ = A_Integer(@1, 32767);break;
		}
	}
type_part
	: T_TYPE type_decl_list		{$$ = $2; }
	|							{$$ = NULL;}
type_decl_list
	: type_decl_list type_definition	{$$ = A_DecList($2, $1);}
	| type_definition					{$$ = A_DecList($1, NULL);}
type_definition
	: T_NAME T_EQUAL type_decl T_SEMI	{$$ = A_TypeDec(@$, S_Symbol($1), $3);}
type_decl
	: simple_type_decl			{$$ = A_SimpleType(@$, $1);}
	| array_type_decl			{$$ = A_ArrayType(@$, $1);}
	| record_type_decl			{$$ = A_RecordType(@$, $1);}
simple_type_decl
	: T_SYS_TYPE				{$$ = A_SimpleSysType(@$, $1);}
	| T_NAME					{$$ = A_SimpleNameType(@$, S_Symbol($1));}
	| T_LP name_list T_RP		{$$ = A_SimpleNameListType(@$, $2);}
array_type_decl
	: T_ARRAY T_LB array_type_range_decl T_RB T_OF type_decl	
	{$$ = A_Array(@$, $3, $6);}
array_type_range_decl
	: const_value T_DOTDOT const_value					{
		$$ = A_ConstRange(@$, $1, $3);
	}
	| T_MINUS const_value T_DOTDOT const_value			{
		// In semantic analysis the type of const_value should be checked
		$2->u.integer *= -1;
		$$ = A_ConstRange(@$, $2, $4);
	}
	| T_MINUS const_value T_DOTDOT T_MINUS const_value	{
		$2->u.integer *= -1;
		$5->u.integer *= -1;
		$$ = A_ConstRange(@$, $2, $5);
	}
	| T_NAME T_DOTDOT T_NAME							{
		$$ = A_NameRange(@$, S_Symbol($1), S_Symbol($3));
	}
record_type_decl
	: T_RECORD field_decl_list T_END				{$$ = $2;}
field_decl_list
	: field_decl_list field_decl					{$$ = A_FieldList($2, $1);}
	| field_decl									{$$ = A_FieldList($1, NULL);}
field_decl
	: name_list T_COLON type_decl T_SEMI			{$$ = A_Field(@$, $1, $3);}
name_list
	: name_list T_COMMA T_ID						{$$ = A_NameList(A_Name(@3, $3), $1);}
	| T_ID											{$$ = A_NameList(A_Name(@1, $1), NULL);}
var_part
	: T_VAR var_decl_list							{$$ = $2;}
	|												{$$ = NULL;}
var_decl_list
	: var_decl_list var_decl						{$$ = A_DecList(A_VarDec(@2, $2), $1);}
	| var_decl										{$$ = A_DecList(A_VarDec(@1, $1), NULL);}
var_decl
	: name_list T_COLON type_decl T_SEMI			{$$ = A_VarDecList(@$, $1, $3);}
routine_part
	: routine_part function_decl					{$$ = A_DecList($2, $1);}
	| routine_part procedure_decl					{$$ = A_DecList($2, $1);}
	| function_decl									{$$ = A_DecList($1, NULL);}
	| procedure_decl								{$$ = A_DecList($1, NULL);}
	|												{$$ = NULL;}
function_decl
	: function_head T_SEMI sub_routine T_SEMI		{$$ = A_RoutinePartDec(@$, A_RoutinePart($1, $3));}
function_head
	: T_FUNCTION T_NAME parameters T_COLON simple_type_decl	{$$ = A_FuncHead(@$, S_Symbol($2), $3, $5);}
procedure_decl
	: procedure_head T_SEMI sub_routine T_SEMI		{$$ = A_RoutinePartDec(@$, A_RoutinePart($1, $3));}
procedure_head
	: T_PROCEDURE T_NAME parameters					{$$ = A_ProcHead(@$, S_Symbol($2), $3);}
parameters
	: T_LP para_decl_list T_RP						{$$ = $2;}
	|												{$$ = NULL;}
para_decl_list
	: para_decl_list T_SEMI para_type_list		{$$ = A_ParaList($3, $1);}
	| para_type_list							{$$ = A_ParaList($1, NULL);}
para_type_list
	: var_para_list T_COLON simple_type_decl	{$$ = A_VarParaField(@$, $1, $3);}
	| val_para_list T_COLON simple_type_decl	{$$ = A_VarParaField(@$, $1, $3);}
var_para_list
	: T_VAR name_list							{$$ = $2;}
val_para_list
	: name_list									{$$ = $1;}
routine_body
	: compound_stmt								{$$ = $1->u.compoundStmt.substmtList;}
compound_stmt
	: T_BEGIN stmt_list T_END					{$$ = A_CompoundStmt(@$, $2);}
stmt_list
	: stmt T_SEMI stmt_list 					{$$ = A_StmtList($1, $3);}
	|											{$$ = NULL;}
stmt
	: T_INTEGER T_COLON non_label_stmt			{$$ = A_LabelStmt(@$, $1, $3);}
	| non_label_stmt							{$$ = $1;}
non_label_stmt
	: assign_stmt								{$$ = $1;}
	| proc_stmt									{$$ = $1;}
	| compound_stmt								{$$ = $1;}
	| if_stmt									{$$ = $1;}
	| repeat_stmt								{$$ = $1;}
	| while_stmt								{$$ = $1;}
	| for_stmt									{$$ = $1;}
	| case_stmt									{$$ = $1;}
	| goto_stmt									{$$ = $1;}
assign_stmt
	: T_ID T_ASSIGN expression						{$$ = A_AssignStmt(@$, A_Var(@1, $1), $3);}
	| T_ID T_LB expression T_RB T_ASSIGN expression	{/*array element*/ $$ = A_AssignStmt(@$, A_ArrayElement(@1, $1, $3), $6);}
	| T_ID T_DOT T_ID T_ASSIGN expression			{/*record element*/ $$ = A_AssignStmt(@$, A_RecordField(@1, $1, $3), $5);}
proc_stmt
	: T_SYS_PROC
	{switch($1){
		case SYS_PROC_WRITE: $$ = A_ProcStmt(@$, A_Proc(@$, S_Symbol("write"), NULL)); break;
		case SYS_PROC_WRITELN: $$ = A_ProcStmt(@$, A_Proc(@$, S_Symbol("writeln"), NULL)); break;
	}}
	| T_ID										{$$ = A_ProcStmt(@$, A_Proc(@$, $1, NULL));}
	| T_ID T_LP expression_list T_RP			{$$ = A_ProcStmt(@$, A_Proc(@$, $1, $3));}
	| T_SYS_PROC T_LP expression_list T_RP
	{switch($1){
		case SYS_PROC_WRITE: $$ = A_ProcStmt(@$, A_Proc(@$, S_Symbol("write"), $3)); break;
		case SYS_PROC_WRITELN: $$ = A_ProcStmt(@$, A_Proc(@$, S_Symbol("writeln"), $3)); break;
	}}
	| T_READ T_LP factor T_RP					{$$ = A_ProcStmt(@$, A_Proc(@$, S_Symbol("read"), A_ExpList($3, NULL)));}
if_stmt
	: T_IF expression T_THEN stmt else_clause		{$$ = A_IfStmt(@$, $2, $4, $5);}
else_clause
	: T_ELSE stmt									{$$ = $2;}
	|												{$$ = NULL;}
repeat_stmt
	: T_REPEAT stmt_list T_UNTIL expression		{$$ = A_RepeatStmt(@$, $4, $2);}
while_stmt
	: T_WHILE expression T_DO stmt				{$$ = A_WhileStmt(@$, $2, $4);}
for_stmt
	: T_FOR T_ID T_ASSIGN expression direction expression T_DO stmt		{$$ = A_ForStmt(@$, A_Var(@2, $2), $4, $5, $6, $8);}
direction
	: T_TO										{$$ = 1;}
	| T_DOWNTO									{$$ = -1;}
case_stmt
	: T_CASE expression T_OF case_expr_list T_END	{$$ = A_CaseStmt(@$, $2, $4);}
case_expr_list
	: case_expr_list case_expr					{$$ = A_CaseList($2, $1);}
	| case_expr									{$$ = A_CaseList($1, NULL);}
case_expr:
	const_value T_COLON stmt T_SEMI				{$$ = A_Case(@$, $1, NULL, $3);}
	| T_ID T_COLON stmt T_SEMI					{$$ = A_Case(@$, NULL, $1, $3);}
goto_stmt:
	T_GOTO T_INTEGER							{$$ = A_GotoStmt(@$, $2);}
expression_list
	: expression_list T_COMMA expression		{$$ = A_ExpList($3, $1);}
	| expression								{$$ = A_ExpList($1, NULL);}
expression
	: expression T_GE expr						{$$ = A_OpExp(@$, A_geOp, $1, $3);}
	| expression T_GT expr						{$$ = A_OpExp(@$, A_gtOp, $1, $3);}
	| expression T_LE expr						{$$ = A_OpExp(@$, A_leOp, $1, $3);}
	| expression T_LT expr						{$$ = A_OpExp(@$, A_ltOp, $1, $3);}
	| expression T_EQUAL expr					{$$ = A_OpExp(@$, A_eqOp, $1, $3);}
	| expression T_UNEQUAL expr					{$$ = A_OpExp(@$, A_neqOp, $1, $3);}
	| expr										{$$ = $1;}
expr
	: expr T_PLUS term							{$$ = A_OpExp(@$, A_plusOp, $1, $3);}
	| expr T_MINUS term							{$$ = A_OpExp(@$, A_minusOp, $1, $3);}
	| expr T_OR term							{$$ = A_OpExp(@$, A_orOp, $1, $3);}
	| term										{$$ = $1;}
term
	: term T_MUL factor							{$$ = A_OpExp(@$, A_mulOp, $1, $3);}
	| term T_DIV factor							{$$ = A_OpExp(@$, A_divOp, $1, $3);}
	| term T_MOD factor							{$$ = A_OpExp(@$, A_modOp, $1, $3);}
	| term T_AND factor							{$$ = A_OpExp(@$, A_andOp, $1, $3);}
	| factor									{$$ = $1;}
factor
	: T_NAME									{$$ = A_NameExp(@$, S_Symbol($1));}
	| T_NAME T_LP expression_list T_RP			{$$ = A_FuncExp(@$, A_Proc(@$, S_Symbol($1), $3));}
	| T_SYS_FUNCT								{
		switch($1){
			case SYS_FUNCT_ABS: $$ = A_FuncExp(@$, A_Proc(@$, S_Symbol("abs"), NULL)); break;
			case SYS_FUNCT_CHR: $$ = A_FuncExp(@$, A_Proc(@$, S_Symbol("chr"), NULL)); break;
			case SYS_FUNCT_ODD: $$ = A_FuncExp(@$, A_Proc(@$, S_Symbol("odd"), NULL)); break;
			case SYS_FUNCT_ORD: $$ = A_FuncExp(@$, A_Proc(@$, S_Symbol("ord"), NULL)); break;
			case SYS_FUNCT_PRED: $$ = A_FuncExp(@$, A_Proc(@$, S_Symbol("pred"), NULL)); break;
			case SYS_FUNCT_SQR: $$ = A_FuncExp(@$, A_Proc(@$, S_Symbol("sqr"), NULL)); break;
			case SYS_FUNCT_SQRT: $$ = A_FuncExp(@$, A_Proc(@$, S_Symbol("sqrt"), NULL)); break;
			case SYS_FUNCT_SUCC: $$ = A_FuncExp(@$, A_Proc(@$, S_Symbol("succ"), NULL)); break;
		}
	}
	| T_SYS_FUNCT T_LP expression_list T_RP		{
		switch($1){
			case SYS_FUNCT_ABS: $$ = A_FuncExp(@$, A_Proc(@$, S_Symbol("abs"), $3)); break;
			case SYS_FUNCT_CHR: $$ = A_FuncExp(@$, A_Proc(@$, S_Symbol("chr"), $3)); break;
			case SYS_FUNCT_ODD: $$ = A_FuncExp(@$, A_Proc(@$, S_Symbol("odd"), $3)); break;
			case SYS_FUNCT_ORD: $$ = A_FuncExp(@$, A_Proc(@$, S_Symbol("ord"), $3)); break;
			case SYS_FUNCT_PRED: $$ = A_FuncExp(@$, A_Proc(@$, S_Symbol("pred"), $3)); break;
			case SYS_FUNCT_SQR: $$ = A_FuncExp(@$, A_Proc(@$, S_Symbol("sqr"), $3)); break;
			case SYS_FUNCT_SQRT: $$ = A_FuncExp(@$, A_Proc(@$, S_Symbol("sqrt"), $3)); break;
			case SYS_FUNCT_SUCC: $$ = A_FuncExp(@$, A_Proc(@$, S_Symbol("succ"), $3)); break;
		}
	}
	| const_value								{$$ = A_ConstExp(@$, $1);}
	| T_LP expression T_RP						{$$ = $2;}
	| T_NOT factor								{$$ = A_OpExp(@$, A_notOp, NULL, $2);}
	| T_MINUS factor							{$$ = A_OpExp(@$, A_negOp, NULL, $2);}
	| T_ID T_LB expression T_RB					{$$ = A_VarExp(@$, A_ArrayElement(@$, $1, $3));}
	| T_ID T_DOT T_ID							{$$ = A_VarExp(@$, A_RecordField(@$, $1, $3));}


T_ID
	: T_NAME {$$ = S_Symbol($1);}
	| T_SYS_CON {
		switch($1){
			case SYS_CON_FALSE:  $$ = S_Symbol("false"); break;
			case SYS_CON_TRUE:   $$ = S_Symbol("true"); break;
			case SYS_CON_MAXINT: $$ = S_Symbol("maxint"); break;
		}
	}
	| T_SYS_FUNCT {
		switch($1){
			case SYS_FUNCT_ABS: $$ = S_Symbol("abs"); break;
			case SYS_FUNCT_CHR: $$ = S_Symbol("chr"); break;
			case SYS_FUNCT_ODD: $$ = S_Symbol("odd"); break;
			case SYS_FUNCT_ORD: $$ = S_Symbol("ord"); break;
			case SYS_FUNCT_PRED:$$ = S_Symbol("pred"); break;
			case SYS_FUNCT_SQR: $$ = S_Symbol("sqr"); break;
			case SYS_FUNCT_SQRT:$$ = S_Symbol("sqrt"); break;
			case SYS_FUNCT_SUCC:$$ = S_Symbol("succ"); break;
		}
	}
	| T_SYS_PROC {
		switch($1){
			case SYS_PROC_WRITE:   $$ = S_Symbol("write"); break;
			case SYS_PROC_WRITELN: $$ = S_Symbol("writeln"); break;
		}
	}
	| T_SYS_TYPE {
		switch($1){
			case Ty_boolean: $$ = S_Symbol("boolean"); break;
			case Ty_char:    $$ = S_Symbol("char"); break;
			case Ty_integer: $$ = S_Symbol("integer"); break;
			case Ty_real:    $$ = S_Symbol("real"); break;
			case Ty_string:  $$ = S_Symbol("string"); break;
		}
	}

%%
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