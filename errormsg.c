#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "errormsg.h"
#include "type.h"
#include "absyn.h"
#include "SPL_parse.h"

int debug = 0;
int errorNum = 0;

extern int yyleng;
extern FILE *yyin;

int rowNum = 1;
int startColNum = 0;
int endColNum = 0;

static char* fileName = "";

void AdjustPos(char* text){
	startColNum = endColNum + 1;
	endColNum = startColNum + yyleng - 1;

	yylloc.first_line = rowNum;
	yylloc.first_column = startColNum;
	yylloc.last_line = rowNum;
	yylloc.last_column = endColNum;

	if(debug){
		printf("Token '%s' at %d:%d-%d\n", text,
						yylloc.first_line,
                        yylloc.first_column,
                        yylloc.last_column);
	}
}

void NewLine(){
	rowNum++;
	endColNum = 0;
	startColNum = 0;
}

void EM_lex_error(char *message, ...){
	va_list ap;
	va_start(ap, message);
	EM_error(rowNum, rowNum, startColNum, endColNum, message, ap);
	va_end(ap);
}

void EM_error(int startRowNum, int endRowNum, int startColNum, int endColNum, char *message,...)
{	
	va_list ap; 

	errorNum++;

	if (fileName) fprintf(stderr,"%s:",fileName);
	fprintf(stderr,"%d.%d-%d.%d: ", startRowNum, endRowNum, startColNum, endColNum);
	va_start(ap,message);
	vfprintf(stderr, message, ap);
	va_end(ap);
	fprintf(stderr,"\n");
}

void EM_reset(char* fname)
{
	errorNum = 0;
	fileName=fname; 
	rowNum = 1;
	startColNum = 0;
	endColNum = 0;
	yyin = fopen(fname,"r");
	if (!yyin) {
		EM_error(0, 0, 0, 0,"cannot open"); 
		exit(1);
	}
}