#include "utils.h"

void* checked_malloc(unsigned size){
	void *p = malloc(size);
	if (!p) {
		fprintf(stderr,"Memory allocation failed!\n");
		exit(1);
	}
	return p;
}

double GetConstValue(A_const constVal){
	double res = 0;
	if(constVal->kind == Ty_integer) res = (double)constVal->u.integer;
	else if(constVal->kind == Ty_real) res = constVal->u.real;
	else if(constVal->kind == Ty_char) res = (double)constVal->u.ch;
	else if(constVal->kind == Ty_boolean) res = (double)constVal->u.boolean;
	return res;
}