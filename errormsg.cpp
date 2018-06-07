#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "errormsg.h"
#include "SPL_parse.h"

#ifdef _MSC_VER
#define FOPEN(file, fname, mode) fopen_s(&file, fname, mode)
#else
#define FOPEN(file, fname, mode) file = fopen(fname, mode);
#endif

int debug = 0;
int errorNum = 0;
int warningNum = 0;

extern int yyleng;
extern FILE *yyin;

int rowNum = 1;
int startColNum = 0;
int endColNum = 0;

static char* fileName = nullptr;

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

void EM_lex_error(const char *message, ...){
	EM_error(rowNum, rowNum, startColNum, endColNum, message);
}

void EM_error(int startRowNum, int endRowNum, int startColNum, int endColNum, const char *message,...)
{	
	va_list ap; 

	errorNum++;

	if (fileName) fprintf(stderr,"%s:",fileName);
	fprintf(stderr,"Error(%d): %d.%d-%d.%d: ", errorNum, startRowNum, startColNum, endRowNum, endColNum);
	va_start(ap,message);
	vfprintf(stderr, message, ap);
	va_end(ap);
	fprintf(stderr,"\n");
}

void EM_error(A_pos pos, const char *message, ...)
{
	va_list ap; 

	errorNum++;

	if (fileName) fprintf(stderr,"%s:",fileName);
	fprintf(stderr,"Error(%d): %d.%d-%d.%d: ",errorNum, pos.first_line, pos.first_column, pos.last_line, pos.last_column);
	va_start(ap,message);
	vfprintf(stderr, message, ap);
	va_end(ap);
	fprintf(stderr,"\n");
}

void EM_warning(A_pos pos, const char *message, ...)
{
	va_list ap; 

	warningNum++;

	if (fileName) fprintf(stderr,"%s:",fileName);
	fprintf(stderr,"Warning(%d): %d.%d-%d.%d: ", warningNum, pos.first_line, pos.first_column, pos.last_line, pos.last_column);
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
	FOPEN(yyin, fname,"r");
	if (!yyin) {
		EM_error(0, 0, 0, 0,"cannot open"); 
		exit(1);
	}
}