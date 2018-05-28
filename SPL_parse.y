%{
	#include <stdio.h>
	#include <string.h>
	#include <time.h>
	#include "errormsg.h"
	#define YYERROR_VERBOSE 1

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
	enum SYS_TYPE{SYS_TYPE_BOOLEAN, SYS_TYPE_CHAR, SYS_TYPE_INTEGER, SYS_TYPE_REAL} typeval;
}

%start s

%locations

%token<sval> T_NAME T_STRING
%type<sval>  T_ID
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

%% 
s:
	program						{}

program 
	: program_head routine T_DOT	{}

program_head
	: T_PROGRAM T_ID T_SEMI		{}
routine
	: routine_head routine_body	{}
sub_routine
	: routine_head routine_body	{}

routine_head
	: label_part const_part type_part var_part routine_part	{}
label_part: {}
const_part 
	: T_CONST const_expr_list		{}
	|								{}
const_expr_list
	: const_expr_list T_NAME T_EQUAL const_value T_SEMI	{}
	| T_NAME T_EQUAL const_value T_SEMI					{}
const_value
	: T_INTEGER					{}
	| T_REAL					{}
	| T_CHAR					{}
	| T_STRING					{}
	| T_SYS_CON					{}
type_part
	: T_TYPE type_decl_list		{}
	|							{}
type_decl_list
	: type_decl_list type_definition	{}
	| type_definition					{}
type_definition
	: T_NAME T_EQUAL type_decl T_SEMI	{}
type_decl
	: simple_type_decl			{}
	| array_type_decl			{}
	| record_type_decl			{}
simple_type_decl
	: T_SYS_TYPE				{}
	| T_NAME					{}
	| T_LP name_list T_RP		{}
array_type_decl
	: T_ARRAY T_LB array_type_range_decl T_RB T_OF type_decl	{}
array_type_range_decl
	: const_value T_DOTDOT const_value					{}
	| T_MINUS const_value T_DOTDOT const_value			{}
	| T_MINUS const_value T_DOTDOT T_MINUS const_value	{}
	| T_NAME T_DOTDOT T_NAME							{}
record_type_decl
	: T_RECORD field_decl_list T_END				{}
field_decl_list
	: field_decl_list field_decl					{}
	| field_decl									{}
field_decl
	: name_list T_COLON type_decl T_SEMI			{}
name_list
	: name_list T_COMMA T_ID						{}
	| T_ID											{}
var_part
	: T_VAR var_decl_list							{}
	|												{}
var_decl_list
	: var_decl_list var_decl						{}
	| var_decl										{}
var_decl
	: name_list T_COLON type_decl T_SEMI			{}
routine_part
	: routine_part function_decl					{}
	| routine_part procedure_decl					{}
	| function_decl									{}
	| procedure_decl								{}
	|												{}
function_decl
	: function_head T_SEMI sub_routine T_SEMI		{}
function_head
	: T_FUNCTION T_NAME parameters T_COLON simple_type_decl	{}
procedure_decl
	: procedure_head T_SEMI sub_routine T_SEMI		{}
procedure_head
	: T_PROCEDURE T_NAME parameters					{}
parameters
	: T_LP para_decl_list T_RP						{}
	|												{}
para_decl_list
	: para_decl_list T_SEMI para_type_list		{}
	| para_type_list							{}
para_type_list
	: var_para_list T_COLON simple_type_decl	{}
	| val_para_list T_COLON simple_type_decl	{}
var_para_list
	: T_VAR name_list							{}
val_para_list
	: name_list									{}
routine_body
	: compound_stmt								{}
compound_stmt
	: T_BEGIN stmt_list T_END					{}
stmt_list
	: stmt_list stmt T_SEMI						{}
	|											{}
stmt
	: T_INTEGER T_COLON non_label_stmt			{}
	| non_label_stmt							{}
non_label_stmt
	: assign_stmt								{}
	| proc_stmt									{}
	| compound_stmt								{}
	| if_stmt									{}
	| repeat_stmt								{}
	| while_stmt								{}
	| for_stmt									{}
	| case_stmt									{}
	| goto_stmt									{}
assign_stmt
	: T_ID T_ASSIGN expression						{}
	| T_ID T_LB expression T_RB T_ASSIGN expression	{/*array element*/}
	| T_ID T_DOT T_ID T_ASSIGN expression			{/*record element*/}
proc_stmt
	: T_SYS_PROC								{}
	| T_ID										{}
	| T_ID T_LP args_list T_RP					{}
	| T_SYS_PROC T_LP expression_list T_RP		{}
	| T_READ T_LP factor T_RP					{}
if_stmt
	: T_IF expression T_THEN stmt else_clause		{}
else_clause
	: T_ELSE stmt									{}
	|												{}
repeat_stmt
	: T_REPEAT stmt_list T_UNTIL expression		{}
while_stmt
	: T_WHILE expression T_DO stmt				{}
for_stmt
	: T_FOR T_ID T_ASSIGN expression direction expression T_DO stmt		{}
direction
	: T_TO										{}
	| T_DOWNTO									{}
case_stmt
	: T_CASE expression T_OF case_expr_list T_END	{}
case_expr_list
	: case_expr_list case_expr					{}
	| case_expr									{}
case_expr:
	const_value T_COLON stmt T_SEMI				{}
	| T_ID T_COLON stmt T_SEMI					{}
goto_stmt:
	T_GOTO T_INTEGER							{}
expression_list
	: expression_list T_COMMA expression		{}
	| expression								{}
expression
	: expression T_GE expr						{}
	| expression T_GT expr						{}
	| expression T_LE expr						{}
	| expression T_LT expr						{}
	| expression T_EQUAL expr					{}
	| expression T_UNEQUAL expr					{}
	| expr										{}
expr
	: expr T_PLUS term							{}
	| expr T_MINUS term							{}
	| expr T_OR term							{}
	| term										{}
term
	: term T_MUL factor							{}
	| term T_DIV factor							{}
	| term T_MOD factor							{}
	| term T_AND factor							{}
	| factor									{}
factor
	: T_NAME									{}
	| T_NAME T_LP args_list T_RP				{/*self-defined function with parameters*/}
	| T_SYS_FUNCT								{}
	| T_SYS_FUNCT T_LP args_list T_RP			{}
	| const_value								{}
	| T_LP expression T_RP						{}
	| T_NOT factor								{}
	| T_MINUS factor							{}
	| T_ID T_LB expression T_RB					{}
	| T_ID T_DOT T_ID							{}
args_list
	: args_list T_COMMA expression				{}
	| expression								{}


T_ID
	: T_NAME {$$ = $1;}
	| T_SYS_CON {
		switch($1){
			case SYS_CON_FALSE:  $$ = "false"; break;
			case SYS_CON_TRUE:   $$ = "true"; break;
			case SYS_CON_MAXINT: $$ = "maxint"; break;
		}
	}
	| T_SYS_FUNCT {
		switch($1){
			case SYS_FUNCT_ABS: $$ = "abs"; break;
			case SYS_FUNCT_CHR: $$ = "chr"; break;
			case SYS_FUNCT_ODD: $$ = "odd"; break;
			case SYS_FUNCT_ORD: $$ = "ord"; break;
			case SYS_FUNCT_PRED:$$ = "pred"; break;
			case SYS_FUNCT_SQR: $$ = "sqr"; break;
			case SYS_FUNCT_SQRT:$$ = "sqrt"; break;
			case SYS_FUNCT_SUCC:$$ = "succ"; break;
		}
	}
	| T_SYS_PROC {
		switch($1){
			case SYS_PROC_WRITE:   $$ = "write"; break;
			case SYS_PROC_WRITELN: $$ = "writeln"; break;
		}
	}
	| T_SYS_TYPE {
		switch($1){
			case SYS_TYPE_BOOLEAN: $$ = "boolean"; break;
			case SYS_TYPE_CHAR:    $$ = "char"; break;
			case SYS_TYPE_INTEGER: $$ = "integer"; break;
			case SYS_TYPE_REAL:    $$ = "real"; break;
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