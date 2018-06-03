#include "utils.h"

void* checked_malloc(unsigned size){
	void *p = malloc(size);
	if (!p) {
		fprintf(stderr,"Memory allocation failed!\n");
		exit(1);
	}
	return p;
}