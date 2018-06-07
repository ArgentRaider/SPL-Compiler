#ifndef _TABLE_H
#define _TABLE_H

#include "symbol.h"
#include "absyn.h"

void BeginScope();
void EndScope();

struct Variable{
    S_symbol name;
    A_type type;
    bool isRef;
    Variable(S_symbol name, A_type type, bool isRef): name(name), type(type), isRef(isRef){}
};

enum NameKind{N_Var, N_Ref, N_Const, N_Routine, N_Undefined};
struct NamedExp{
    NameKind kind;
    union {
        Variable* var;
        Variable* ref;
        A_const constVal;
        A_routinePartHead routine;
    } u;

    NamedExp(): kind(N_Undefined) {};
};

NamedExp&& FindName(S_symbol name);
Variable* FindVar(S_symbol name);

A_const GlobalConst(S_symbol name);
A_const LocalConst(S_symbol name);
A_type GlobalType(S_symbol name);
A_type LocalType(S_symbol name);
Variable* GlobalVar(S_symbol name);
Variable* LocalVar(S_symbol name);
Variable* GlobalRef(S_symbol name);
Variable* LocalRef(S_symbol name);
A_routinePartHead GlobalRoutine(S_symbol name);
A_routinePartHead LocalRoutine(S_symbol name);

// Return true if it is a successful declaration
bool DefineConst(S_symbol name, A_const constVal, A_pos pos);
bool DefineType(S_symbol name, A_type type, A_pos pos);
bool DefineVar(S_symbol name, A_type varType, A_pos pos);
bool DefineRef(S_symbol name, A_type refType, A_pos pos);
bool DefineRoutine(S_symbol name, A_routinePartHead routinePartHead, A_pos pos);
bool DefineParameters(A_paraList paraList);

bool DeclareLabel(int label, A_stmt stmt);
A_stmt LocalLabel(int label);


// Return NULL if name is not a built-in type and is not declared before
A_type RealType(A_type type);

struct Environment;

#endif