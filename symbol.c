#include "symbol.h"
#include "utils.h"

S_symbol S_Symbol(char * name){
	S_symbol s;
	check_malloc(s, sizeof(*s));
	s->name = name;
	return s;
}

char *S_name(S_symbol s){
	return s->name;
}