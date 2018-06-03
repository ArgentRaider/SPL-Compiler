#include "type.h"

int canConvert(int dstType, int srcType){
	if( (srcType | dstType) == dstType )
		return 1;
	else return 0;
}