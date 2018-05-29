#ifndef _UTILS_H
#define _UTILS_H

#include <stdio.h>
#include <stdlib.h>

#define check_malloc(p, size) \
	do{ \
		p = malloc(size); \
		if(!p){ \
			fprintf(stderr,"Memory allocation failed at %s:%d!\n", __FILE__, __LINE__); \
			exit(1); \
		} \
	} while (0)

void* checked_malloc(unsigned size);

#endif