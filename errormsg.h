#ifndef _ERRORMSG_H
#define _ERRORMSG_H

/* Headers */
#include <stdbool.h>
#include <stdarg.h>

/* Global Variables */
extern int debug;
extern int errorNum;

/* Pos Record */
extern void AdjustPos(char* text);
extern void NewLine();

extern void EM_lex_error(char *message, ...);
extern void EM_error(int rowNum, int startColNum, int endColNum, char *message,...);

#endif