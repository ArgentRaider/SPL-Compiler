%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	#include "errormsg.h"
	#include "utils.h"
	#include "symbol.h"
	#include "type.h"
	#include "absyn.h"
	#include "SPL_parse.h"
%}

digit	[0-9]
digits	[0-9]+
integer	{digit}+
real	({digits}"."{digits})
newline \n

%s STRING_CHAR_MATCH STRING_MATCHED CHAR_MATCHED COMMENT_PARENTHESE COMMENT_BRACE

%%
<INITIAL>[[:blank:]]			{AdjustPos(yytext);}
<*>{newline}					{NewLine();}

 /*comment*/
<INITIAL>"(*"					{AdjustPos(yytext); BEGIN COMMENT_PARENTHESE;}
<INITIAL>"{"					{AdjustPos(yytext); BEGIN COMMENT_BRACE;}
<COMMENT_PARENTHESE>"*)"		{AdjustPos(yytext); BEGIN INITIAL;}
<COMMENT_BRACE>"}"				{AdjustPos(yytext); BEGIN INITIAL;}
<COMMENT_PARENTHESE>.			{AdjustPos(yytext);}
<COMMENT_BRACE>.				{AdjustPos(yytext);}

 /*operators*/
<INITIAL>"("		{AdjustPos(yytext);return T_LP;}
<INITIAL>")"		{AdjustPos(yytext);return T_RP;}
<INITIAL>"["		{AdjustPos(yytext);return T_LB;}
<INITIAL>"]"		{AdjustPos(yytext);return T_RB;}
<INITIAL>"."		{AdjustPos(yytext);return T_DOT;}
<INITIAL>","		{AdjustPos(yytext);return T_COMMA;}
<INITIAL>":"		{AdjustPos(yytext);return T_COLON ;}
<INITIAL>"*"		{AdjustPos(yytext);return T_MUL ;}
<INITIAL>"/"		{AdjustPos(yytext);return T_DIV ;}
<INITIAL>"<>"		{AdjustPos(yytext);return T_UNEQUAL ;}
<INITIAL>"NOT"		{AdjustPos(yytext);return T_NOT ;}
<INITIAL>"+"		{AdjustPos(yytext);return T_PLUS ;}
<INITIAL>"-"		{AdjustPos(yytext);return T_MINUS ;}
<INITIAL>">="		{AdjustPos(yytext);return T_GE ;}
<INITIAL>">"		{AdjustPos(yytext);return T_GT ;}
<INITIAL>"<="		{AdjustPos(yytext);return T_LE ;}
<INITIAL>"<"		{AdjustPos(yytext);return T_LT ;}
<INITIAL>"="		{AdjustPos(yytext);return T_EQUAL ;}
<INITIAL>":="		{AdjustPos(yytext);return T_ASSIGN ;}
<INITIAL>"%"		{AdjustPos(yytext);return T_MOD ;}
<INITIAL>".."		{AdjustPos(yytext);return T_DOTDOT;}
<INITIAL>";"		{AdjustPos(yytext);return T_SEMI ;}

 /*system words*/
<INITIAL>false	{AdjustPos(yytext);yylval.conval = SYS_CON_FALSE; return T_SYS_CON;}
<INITIAL>maxint	{AdjustPos(yytext);yylval.conval = SYS_CON_MAXINT; return T_SYS_CON;}
<INITIAL>true	{AdjustPos(yytext);yylval.conval = SYS_CON_TRUE; return T_SYS_CON;}
<INITIAL>abs		{AdjustPos(yytext);yylval.functval = SYS_FUNCT_ABS; return T_SYS_FUNCT;}
<INITIAL>chr		{AdjustPos(yytext);yylval.functval = SYS_FUNCT_CHR; return T_SYS_FUNCT;}
<INITIAL>odd		{AdjustPos(yytext);yylval.functval = SYS_FUNCT_ODD; return T_SYS_FUNCT;}
<INITIAL>ord		{AdjustPos(yytext);yylval.functval = SYS_FUNCT_ORD; return T_SYS_FUNCT;}
<INITIAL>pred		{AdjustPos(yytext);yylval.functval = SYS_FUNCT_PRED; return T_SYS_FUNCT;}
<INITIAL>sqr		{AdjustPos(yytext);yylval.functval = SYS_FUNCT_SQR; return T_SYS_FUNCT;}
<INITIAL>sqrt		{AdjustPos(yytext);yylval.functval = SYS_FUNCT_SQRT; return T_SYS_FUNCT;}
<INITIAL>succ		{AdjustPos(yytext);yylval.functval = SYS_FUNCT_SUCC; return T_SYS_FUNCT;}
<INITIAL>write		{AdjustPos(yytext);yylval.procval = SYS_PROC_WRITE; return T_SYS_PROC;}
<INITIAL>writeln	{AdjustPos(yytext);yylval.procval = SYS_PROC_WRITELN; return T_SYS_PROC;}
<INITIAL>boolean	{AdjustPos(yytext);yylval.typeval = Ty_boolean; return T_SYS_TYPE;}
<INITIAL>char		{AdjustPos(yytext);yylval.typeval = Ty_char; return T_SYS_TYPE;}
<INITIAL>integer	{AdjustPos(yytext);yylval.typeval = Ty_integer; return T_SYS_TYPE;}
<INITIAL>real		{AdjustPos(yytext);yylval.typeval = Ty_real; return T_SYS_TYPE;}
<INITIAL>string		{AdjustPos(yytext);yylval.typeval = Ty_string; return T_SYS_TYPE;}

<INITIAL>read		{AdjustPos(yytext);return T_READ;}

 /*keyword list*/
<INITIAL>and		{AdjustPos(yytext);return T_AND;}
<INITIAL>array		{AdjustPos(yytext);return T_ARRAY;}
<INITIAL>begin		{AdjustPos(yytext);return T_BEGIN;}
<INITIAL>case		{AdjustPos(yytext);return T_CASE;}
<INITIAL>const		{AdjustPos(yytext);return T_CONST;}
<INITIAL>div		{AdjustPos(yytext);return T_DIV;}
<INITIAL>do			{AdjustPos(yytext);return T_DO;}
<INITIAL>downto		{AdjustPos(yytext);return T_DOWNTO;}
<INITIAL>else		{AdjustPos(yytext);return T_ELSE;}
<INITIAL>end		{AdjustPos(yytext);return T_END;}
<INITIAL>for		{AdjustPos(yytext);return T_FOR;}
<INITIAL>function	{AdjustPos(yytext);return T_FUNCTION;}
<INITIAL>goto		{AdjustPos(yytext);return T_GOTO;}
<INITIAL>if			{AdjustPos(yytext);return T_IF;}
<INITIAL>in			{AdjustPos(yytext);return T_IN;}
<INITIAL>mod		{AdjustPos(yytext);return T_MOD;}
<INITIAL>not		{AdjustPos(yytext);return T_NOT;}
<INITIAL>of			{AdjustPos(yytext);return T_OF;}
<INITIAL>or			{AdjustPos(yytext);return T_OR;}
<INITIAL>packed		{AdjustPos(yytext);return T_PACKED;}
<INITIAL>procedure	{AdjustPos(yytext);return T_PROCEDURE;}
<INITIAL>program	{AdjustPos(yytext);return T_PROGRAM;}
<INITIAL>record		{AdjustPos(yytext);return T_RECORD;}
<INITIAL>repeat		{AdjustPos(yytext);return T_REPEAT;}
<INITIAL>set		{AdjustPos(yytext);return T_SET;}
<INITIAL>then		{AdjustPos(yytext);return T_THEN;}
<INITIAL>to			{AdjustPos(yytext);return T_TO;}
<INITIAL>type		{AdjustPos(yytext);return T_TYPE;}
<INITIAL>until		{AdjustPos(yytext);return T_UNTIL;}
<INITIAL>var		{AdjustPos(yytext);return T_VAR;}
<INITIAL>while		{AdjustPos(yytext);return T_WHILE;}
<INITIAL>with		{AdjustPos(yytext);return T_WITH;}

 /*identifiers*/
<INITIAL>[a-zA-Z][_a-zA-Z0-9]*	{AdjustPos(yytext); check_malloc(yylval.sval, yyleng+1); strcpy(yylval.sval, yytext); return T_NAME;}

 /*value*/
<INITIAL>{real}	{AdjustPos(yytext); yylval.fval = atof(yytext); return T_REAL;}

<INITIAL>{integer}	{AdjustPos(yytext);yylval.ival = atoi(yytext); return T_INTEGER;}

<INITIAL>\'			{AdjustPos(yytext);BEGIN STRING_CHAR_MATCH;}
<STRING_CHAR_MATCH>[^']*	{
		AdjustPos(yytext);
		if( yyleng == 1){
			yylval.cval = *yytext;
			BEGIN CHAR_MATCHED;
		}else{
			check_malloc(yylval.sval, yyleng+1);
			strcpy(yylval.sval, yytext);
			BEGIN STRING_MATCHED;
		}
	}
<STRING_MATCHED>\'	{BEGIN INITIAL; return T_STRING;}
<CHAR_MATCHED>\'	{BEGIN INITIAL; return T_CHAR;}

.					{EM_lex_error("Illegal Token!");}

%%
int yywrap(){
	return 1;
}