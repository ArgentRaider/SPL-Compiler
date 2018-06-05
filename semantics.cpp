#include "semantics.h"
#include "errormsg.h"
#include <stdlib.h>

int Se_Analyse(A_pro root){
	if(root != NULL){
		return 1;
	}else{
		EM_error(0, 0, 0, 0, "Semantic Error: The Program is Empty!");
		return 0;
	}
}