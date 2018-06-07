#include "absyn.h"


int Se_Analyse(A_pro root);

// retName != nullptr means this routine is a function and needs a return value
void* Se_AnalyseRoutine(A_routine node, S_symbol retName, bool& retAssigned);

void* Se_AnalyseRoutineHead(A_routineHead node);

void* Se_AnalyseStmtList(A_stmtList node, S_symbol retName, bool& retAssigned);

void* Se_AnalyseStmt(A_stmt node, S_symbol retName, bool& retAssigned);

// Fill the value type of A_exp
void* Se_AnalyseExp(A_exp node);

// Return a IR node representing a call to system function or procedure
// Depending on how many routines you want to realize
void* Se_CheckSysFunc(S_symbol name, A_expList params, A_pos pos);
void* Se_CheckSysProc(S_symbol name, A_expList params, A_pos pos);

// Return a type convert IR node 
void* Se_TypeConvert(SysType dstType, SysType srcType);

// Return a IR node representing a variable
void* Se_AnalyseVar(A_var node);

// Try to pass all arguments to a call
// Analyse the expressions before calling this function
void* Se_PassArguments(A_expList actualArgs, A_paraList declareArgs, A_pos errorPos);

// Pass one argument to calls
// You could add necessary arguments such as an IR node representing 'src'
// Called by Se_PassArguments
void* Se_PassArgument(A_paraField dst, A_exp src, int index, bool& compatible);

