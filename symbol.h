/*
 * symbol.h - Symbols and symbol-tables
 *
 */

#ifndef _SYMBOL_H
#define _SYMBOL_H 

typedef struct S_symbol_ * S_symbol;
struct S_symbol_
{
	char* name;	
};


S_symbol S_Symbol(char * name);

char *S_name(S_symbol s);

#endif