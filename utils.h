#ifndef _UTILS_H
#define _UTILS_H

#include <cstdio>
#include <cstdlib>
#include "absyn.h"

#define check_malloc(p, size) \
	do{ \
		p = malloc(size); \
		if(!p){ \
			fprintf(stderr,"Memory allocation failed at %s:%d!\n", __FILE__, __LINE__); \
			exit(1); \
		} \
	} while (0)

void* checked_malloc(unsigned size);

double GetConstValue(A_const constVal);

inline bool isSysType(A_type type, SysType sysType){
	return type && type->kind == A_simpleType \
		&& type->u.simple->kind == A_simpleSysType \
		&& type->u.simple->u.sysType == sysType; 
}

#endif