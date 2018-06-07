#ifndef _ERRORMSG_H
#define _ERRORMSG_H

/* Headers */
#include <cstdarg>
#include "absyn.h"

/* Global Variables */
extern int debug;
extern int errorNum;
extern int warningNum;

/* Pos Record */
extern void AdjustPos(char* text);
extern void NewLine();

extern void EM_lex_error(const char *message, ...);
extern void EM_error(int startRowNum, int endRowNum, int startColNum, int endColNum, const char *message,...);
extern void EM_error(A_pos pos, const char *message, ...);
extern void EM_warning(A_pos pos, const char *message, ...);

#endif