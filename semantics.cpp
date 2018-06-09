#include <unordered_map>
#include <cstdlib>
#include <cassert>
#include <string>
#include "semantics.h"
#include "errormsg.h"
#include "table.h"
#include "utils.h"

#define SE_DEBUG

#ifdef SE_DEBUG
#include <cstdio>
#endif

void* Se_CheckSysFunc(S_symbol name, A_expList params, A_pos pos){
	static S_symbol writelnProc = S_Symbol("writeln");
	static S_symbol writeProc = S_Symbol("write");
	static S_symbol absFunc = S_Symbol("abs"); 

	// Below is an example to code a check.
	// In this project, HOWEVER, we ONLY need to consider "writeln"

	if(name == writelnProc || name == writeProc){
		EM_error(pos, "Expect an expression, but '%s' is a procedure.", S_name(name));
	}else if(name == absFunc){
		if(params == nullptr){
			EM_error(pos, "Need 1 parameter for '%s', but get none.", S_name(name));
		}else if(params->next != nullptr){
			EM_error(pos, "Need 1 parameter for '%s', but get more than 1.", S_name(name));
		}else {
			Se_AnalyseExp(params->head);

			A_type valueType = params->head->valueType;
			if(!isSysType(valueType, Ty_integer) || !isSysType(valueType, Ty_real)){
				EM_error(pos, "Expect a 'integer' or 'real' type parameter.");
			}else{
				// return a call-to-abs node
			}
		}
	}else{
		EM_error(pos, "Undefined symbol %s in this scope.", S_name(name));
	}
	if(!errorNum){

	}
	return nullptr;
}

void* Se_CheckSysProc(S_symbol name, A_expList params, A_pos pos){
	static S_symbol writelnProc = S_Symbol("writeln");
	static S_symbol writeProc = S_Symbol("write");
	static S_symbol absFunc = S_Symbol("abs"); 

	// Below is an example to code a check.
	// In this project, HOWEVER, we ONLY need to consider "writeln"

	if(name == writelnProc || name == writeProc){
		int actualArgNum = 0;
		for(A_expList ptr = params; ptr != nullptr; ptr = ptr->next){
			A_exp arg = ptr->head;
			actualArgNum++;
			// Construct IR nodes for parameters here
			Se_AnalyseExp(arg);
		}
		// check the paramList here and return a IR node

	}else if(name == absFunc){
		if(params == nullptr){
			EM_error(pos, "Need 1 parameter for '%s', but get none.", S_name(name));
		}else if(params->next != nullptr){
			EM_error(pos, "Need 1 parameter for '%s', but get more than 1.", S_name(name));
		}else {
			Se_AnalyseExp(params->head);

			A_type valueType = params->head->valueType;
			if(!isSysType(valueType, Ty_integer) || !isSysType(valueType, Ty_real)){
				EM_error(pos, "Expect a 'integer' or 'real' type parameter.");
			}else{
				EM_warning(pos, "Unused return value from function 'abs'.");
				// return a call-to-abs node
			}
		}
	}else{
		EM_error(pos, "Undefined symbol %s in this scope.", S_name(name));
	}
	if(!errorNum){

	}
	return nullptr;
}


void* Se_TypeConvert(SysType dstType, SysType srcType){
	assert(canConvert(dstType, srcType));
	// the same type, no need to convert
	if(dstType == srcType) return nullptr;

	// construct the convert IR node here
	return nullptr;
}

void* Se_PassArguments(A_expList actualArgs, A_paraList declareArgs, A_pos errorPos){
	bool compatible = true;
	A_expList srcPtr = actualArgs;
	A_paraList dstPtr = declareArgs;	// non-null
	A_nameList dstHead = dstPtr != nullptr ? dstPtr->field->nameList : nullptr;
	int decArgNum;
	int actualArgNum = 0;

	for(A_expList ptr = actualArgs; ptr != nullptr; ptr = ptr->next){
		A_exp arg = ptr->head;
		actualArgNum++;
		// Construct IR nodes for parameters here
		Se_AnalyseExp(arg);
	}
	for(decArgNum = 1; decArgNum <= actualArgNum; decArgNum++){
		if(!dstPtr){
			compatible = false;
			EM_error(errorPos, "Expect %d arguments. Get %d.", decArgNum - 1, actualArgNum);
			break;
		}
		Se_PassArgument(dstPtr->field, srcPtr->head, decArgNum, compatible);
		srcPtr = srcPtr->next;
		dstHead = dstHead->next;
		if(!dstHead){
			dstPtr = dstPtr->next;
			if(dstPtr)dstHead = dstPtr->field->nameList;
		}
	}
	if(decArgNum > actualArgNum && dstPtr != nullptr){
		EM_error(errorPos, "Expect more than %d arguments.", actualArgNum);
	}
	return nullptr;
}

void* Se_PassArgument(A_paraField dstField, A_exp src, int index, bool& compatible){
	void* res = nullptr;
	bool legal = true;
	if(dstField->kind == Var){
		if(src->kind != A_varExp){
			legal = false;
			compatible = false;
			EM_error(src->pos, "Expect an lvalue for argument %d. Get an rvalue.", index);
		}
	}
	if(legal){
		A_type dstType = dstField->type, srcType = src->valueType;
		if(dstType->kind == A_simpleType && dstType->u.simple->kind == A_simpleSysType \
		&& srcType->kind == A_simpleType && srcType->u.simple->kind == A_simpleSysType \
		&& canConvert(dstType->u.simple->u.sysType, srcType->u.simple->u.sysType) ){
			if(dstField->kind == Var){
				if(dstType->u.simple->u.sysType != srcType->u.simple->u.sysType){
					compatible = false;
					EM_error(src->pos, "Cannot convert type for argument %d implicitly as a 'var' type", index);
				}else{
					// Pass a pointer to the call or something
				}
			}else{
				// get the convert node
				res = Se_TypeConvert(dstType->u.simple->u.sysType, srcType->u.simple->u.sysType);
			}
		}else if(dstType == srcType){
			// return the original node?
		}else{
			compatible = false;
			EM_error(src->pos, "Incompatible type for argument %d.", index);
		}
	}
	if(!errorNum){
		
	}
	return res;
}

int Se_Analyse(A_pro root){
	if(root != nullptr){
		BeginScope();
		bool tmp;
		Se_AnalyseRoutine(root->routine, nullptr, tmp); 
		EndScope();
	}else{
		EM_error(0, 0, 0, 0, "Semantic Error: The Program is Empty!");
		return 0;
	}
}

// begin scope from extern part
void* Se_AnalyseRoutine(A_routine node, S_symbol retName, bool& retAssigned){
	if(node == nullptr) return nullptr;

	Se_AnalyseRoutineHead(node->head);
	Se_AnalyseStmtList(node->compoundStmt, retName, retAssigned);
	
	if(!errorNum){	// No Error yet. Construct the IR tree here if necessary

	}
	return nullptr;
}

void* Se_AnalyseRoutineHead(A_routineHead node){
	A_decList decPtr;
	for( decPtr = node->constPart; decPtr != nullptr; decPtr = decPtr->next ){
		A_dec dec = decPtr->head;
		DefineConst(dec->name, dec->u.value, dec->pos);
	}
	for( decPtr = node->typePart; decPtr != nullptr; decPtr = decPtr->next ){
		A_dec dec = decPtr->head;
		// Fetch the real type
		DefineType(dec->name, dec->u.type, dec->pos);
	}
	for( decPtr = node->varPart; decPtr != nullptr; decPtr = decPtr->next ){
		A_dec dec = decPtr->head;
		A_varDecList varList = dec->u.var;
		A_type realType = RealType(varList->type);
		if(!realType){// Error already handled by RealType()
		}else {
			for(A_nameList varPtr = varList->nameList; varPtr != nullptr; varPtr = varPtr->next){
				DefineVar(varPtr->head->name, realType, varPtr->head->pos);
			}
		}
	}
	for( decPtr = node->routinePart; decPtr != nullptr; decPtr = decPtr->next ){
		A_dec dec = decPtr->head;
		A_routinePartHead routinePartHead = dec->u.routine->head;
		A_routine routine = dec->u.routine->subRoutine;	
		bool res = DefineRoutine(routinePartHead->name, routinePartHead, routinePartHead->pos);
		if(res){
			BeginScope();
			DefineParameters(routinePartHead->parameters);
			S_symbol retName = nullptr;
			bool retAssigned = false;
			if(routinePartHead->kind == A_function){
				retName = routinePartHead->name;
				// Define the name of this function as a Var
				// so that it could be assigned inside the funciton
				// This define shouldn't report any error since everything is checked before.
				DefineVar(retName, routinePartHead->retType, routinePartHead->pos);
			}
			Se_AnalyseRoutine(routine, retName, retAssigned);
			// A function without assigning its return value
			if(retName && !retAssigned){
				EM_error(routinePartHead->pos, "Function %s doesn't have a return value.", S_name(routinePartHead->name));
			}
			EndScope();
		}
	}
	if(!errorNum){
		
	}
	return nullptr;
}

void* Se_AnalyseStmtList(A_stmtList node, S_symbol retName, bool& retAssigned){
	for(A_stmtList ptr = node; ptr != nullptr; ptr = ptr->next){
		A_stmt stmt = ptr->head;
		Se_AnalyseStmt(stmt, retName, retAssigned);
	}
	if(!errorNum){
		
	}
	return nullptr;
}

void* Se_AnalyseAssignStmt(A_assignS* assignStmt, A_pos pos);
void* Se_AnalyseProcStmt(A_proc procStmt, A_pos pos);
void* Se_AnalyseIfStmt(A_ifS* ifStmt, A_pos pos, S_symbol retName, bool& retAssigned);
void* Se_AnalyseRepeatStmt(A_repeatS* repeatStmt, A_pos pos);
void* Se_AnalyseWhileStmt(A_whileS* whileStmt, A_pos pos);
void* Se_AnalyseForStmt(A_forS* forStmt, A_pos pos);
void* Se_AnalyseCaseStmt(A_caseS* caseStmt, A_pos pos, S_symbol retName, bool& retAssigned);

void* Se_AnalyseStmt(A_stmt node, S_symbol retName, bool& retAssigned){
	if(node->label >= 0){
		if( !DeclareLabel(node->label, node) ){
			EM_warning(node->pos, "Redefined Label %d. Ignored.", node->label);
		}
	}

	switch(node->kind){
		case A_assignStmt:{
			Se_AnalyseAssignStmt(&(node->u.assignStmt), node->pos);
			if(retName && node->u.assignStmt.var->ID == retName) retAssigned = true;
			break;
		}
		case A_procStmt:{
			Se_AnalyseProcStmt(node->u.procStmt, node->pos);
			break;
		}
		case A_compundStmt:{
			Se_AnalyseStmtList(node->u.compoundStmt.substmtList, retName, retAssigned);
			break;
		}
		case A_ifStmt:{
			Se_AnalyseIfStmt(&(node->u.ifStmt), node->pos, retName, retAssigned);
			break;
		}
		case A_repeatStmt:{
			Se_AnalyseRepeatStmt(&(node->u.repeatStmt), node->pos);
			break;
		}
		case A_whileStmt:{
			Se_AnalyseWhileStmt(&(node->u.whileStmt), node->pos);
			break;
		}
		case A_forStmt:{
			Se_AnalyseForStmt(&(node->u.forStmt), node->pos);
			break;
		}
		case A_caseStmt:{
			Se_AnalyseCaseStmt(&(node->u.caseStmt), node->pos, retName, retAssigned);
			break;
		}
		case A_gotoStmt:{
			const A_stmt targetStmt = LocalLabel(node->u.gotoStmt.label);
			// You may use this targetStmt to build IR tree
			if( targetStmt == nullptr ){
				EM_error(node->pos, "Undefined label %d in this scope", node->u.gotoStmt.label);
			}
			break;
		}
	}
	if(!errorNum){
		
	}
	return nullptr;
}

void* Se_AnalyseVar(A_var node){
	void* res = nullptr;
	A_var var = node;
	A_pos pos = var->pos;
	Variable* defVar = FindVar(var->ID);

	if(!defVar){
		EM_error(pos, "Undefined variable %s.", S_name(var->ID));
	}else{
		// as a reference, you may want to do something to its pointer
		if(defVar->isRef){

		}

		if(var->kind == A_pureID){
			var->valueType = defVar->type;
		}else if(var->kind == A_arrayElement){
			if(defVar->type->kind == A_arrayType){
				A_exp subscript = var->u.subscript;
				Se_AnalyseExp(subscript);
				if( isSysType(subscript->valueType, Ty_integer) ){
					int lbound = defVar->type->u.array->range->lower_u.lconst->u.integer;
					int ubound = defVar->type->u.array->range->upper_u.uconst->u.integer;
					if(subscript->kind == A_constExp){			
						int subVal = subscript->u.constValue->u.integer;		
						if(subVal >= lbound && subVal <= ubound){
							int index = subVal - lbound;
							// Get the array offset from index
						}else{
							EM_error(subscript->pos, "Array subscript out of range from %d to %d.", lbound, ubound);
						}
					}else{
						A_exp realSubscript =   // subscript - lbound
							A_OpExp(subscript->pos, A_minusOp, subscript, A_ConstExp(subscript->pos, A_Integer(subscript->pos, lbound)));
						realSubscript->valueType = subscript->valueType;	// integer type
						// Construct the IR node to get the arrayElement
					}
				}else{
					EM_error(subscript->pos, "Subscript of array must be of integer type.");
				}
				var->valueType = defVar->type->u.array->type;
			}else{	//defVar->type->kind != A_arrayType
				EM_error(pos, "%s cannot be subscripted.", S_name(var->ID));
			}					
		}else{	// var->kind == A_recordField
			if(defVar->type->kind == A_recordType){
				A_fieldList fieldPtr = defVar->type->u.fieldList;	// non-null
				A_nameList namePtr = fieldPtr->head->nameList;
				int index = 0;	//from 0?
				
				while(fieldPtr != nullptr){
					if(var->u.fieldID == namePtr->head->name) break;

					index++;
					namePtr = namePtr->next;
					if(namePtr == nullptr){
						fieldPtr = fieldPtr->next;
						if(fieldPtr) namePtr = fieldPtr->head->nameList;
					}
				}
				if(fieldPtr != nullptr){
					// use index to get the member of record

					node->valueType = var->valueType = fieldPtr->head->type;
				}else{
					EM_error(pos, "%s doesn't have a member called %s.", S_name(var->ID), S_name(var->u.fieldID) );
				}
			}else{ // defVar->type->kind != A_recordType
				EM_error(pos, "%s doesn't have a member.", S_name(var->ID));
			}
		}
	}

	return res;
}

void* Se_AnalyseArithOp(A_exp node){
	void* res = nullptr;
	A_op opExp = node->u.op;
	A_oper oper = opExp->oper;
	SysType leftType = opExp->left->valueType->u.simple->u.sysType;
	SysType rightType = opExp->right->valueType->u.simple->u.sysType;

	bool legal = true;
	if(leftType != Ty_integer && leftType != Ty_real){
		legal = false;
		EM_error(opExp->left->pos, "Left operand of arithmetic operator should be integer or real.");
	}
	if(rightType != Ty_integer && rightType != Ty_real){
		legal = false;
		EM_error(opExp->right->pos, "Right operand of arithmetic operator should be integer or real.");
	}
	if(oper == A_modOp && (leftType != Ty_integer || rightType != Ty_integer)){
		legal = false;
		EM_error(node->pos, "The operands of MOD operator should be integers.");
	}
	if(legal){
		if(leftType == Ty_real) node->valueType = opExp->left->valueType;
		else node->valueType = opExp->right->valueType;

		// Both constants
		if(opExp->left->kind == A_constExp && opExp->right->kind == A_constExp){
			double l = GetConstValue(opExp->left->u.constValue),
					r = GetConstValue(opExp->right->u.constValue);
			double res = 0;

			switch(oper){
				case A_plusOp: res = l + r;	break;
				case A_minusOp: res = l - r; break;
				case A_mulOp: res = l * r; break;
				case A_divOp:{
					if(r == 0){
						legal = false;
						EM_error(opExp->right->pos, "Right operand of DIV should not be 0.");
						break;
					}
					res = l / r;
					break;
				}
				case A_modOp: res = int(l) % int(r); break;
				default: EM_error(node->pos, "ERROR, Unknown Arithmetic OP."); legal = false;
			}
			node->kind = A_constExp;
			if(legal){
				if(leftType == Ty_integer && rightType == Ty_integer)
					node->u.constValue = A_Integer(node->pos, int(res));
				else
					node->u.constValue = A_Real(node->pos, res);
			}
			
		}
		// At least one variable
		else{
			// you may construct your IR node here
			if(leftType == Ty_integer && rightType == Ty_real){

			}else if(leftType == Ty_real && rightType == Ty_integer){

			}else if(leftType == Ty_integer && rightType == Ty_integer){

			}else{ //leftType == Ty_real && rightType == Ty_real

			}
		}
	}

	return res;
}

void* Se_AnalyseCmpOp(A_exp node){
	void* res = nullptr;
	A_op opExp = node->u.op;
	A_oper oper = opExp->oper;
	SysType leftType = opExp->left->valueType->u.simple->u.sysType;
	SysType rightType = opExp->right->valueType->u.simple->u.sysType;

	bool legal = true;
	if(leftType != Ty_integer && leftType != Ty_real && leftType != Ty_char){
		legal = false;
		EM_error(opExp->left->pos, "Left operand of compare operator should be integer/real/char.");
	}
	if(rightType != Ty_integer && rightType != Ty_real && rightType != Ty_char){
		legal = false;
		EM_error(opExp->right->pos, "Right operand of compare operator should be integer/real/char.");
	}
	if(legal){
		node->valueType = A_SimpleType(node->pos, A_SimpleSysType(node->pos, Ty_boolean));
		if(opExp->left->kind == A_constExp && opExp->right->kind == A_constExp){
			double l = GetConstValue(opExp->left->u.constValue),
					r = GetConstValue(opExp->right->u.constValue);
			bool res = 0;

			switch(oper){
				case A_eqOp: res = l == r;	break;
				case A_neqOp: res = l != r; break;
				case A_ltOp: res = l < r; break;
				case A_leOp: res = l <= r; break;
				case A_gtOp: res = l > r; break;
				case A_geOp: res = l >= r; break;
				default: EM_error(node->pos, "ERROR, Unknown Compare OP."); legal = false;
			}
			node->kind = A_constExp;
			if(legal){
				node->u.constValue = A_Bool(node->pos, int(res));
			}	
		}
		else{
			// you may construct your IR node here
			if(leftType == rightType){

			}else{ //leftType != rightType, may need convert here

			}
		}
	}

	return res;
}

void* Se_AnalyseLogicOp(A_exp node){
	void* res = nullptr;
	A_op opExp = node->u.op;
	A_oper oper = opExp->oper;
	SysType leftType = opExp->left->valueType->u.simple->u.sysType;
	SysType rightType = opExp->right->valueType->u.simple->u.sysType;

	bool legal = true;
	if(leftType != Ty_boolean){
		legal = false;
		EM_error(opExp->left->pos, "Left operand of logic operator should be boolean.");
	}
	if(rightType != Ty_boolean){
		legal = false;
		EM_error(opExp->right->pos, "Right operand of logic operator should be boolean.");
	}
	if(legal){
		node->valueType = opExp->left->valueType;
		if(opExp->left->kind == A_constExp && opExp->right->kind == A_constExp){
			bool l = opExp->left->u.constValue->u.boolean == 1,
					r = opExp->right->u.constValue->u.boolean == 1;
			bool res = 0;

			switch(oper){
				case A_andOp: res = l && r;	break;
				case A_orOp: res = l || r; break;
				default: EM_error(node->pos, "ERROR, Unknown Logic OP."); legal = false;
			}
			node->kind = A_constExp;
			if(legal){
				node->u.constValue = A_Bool(node->pos, int(res));
			}	
		}
		else{
			// you may construct your IR node here
			//leftType = rightType = Ty_boolean

		}
	}

	return res;
}

void* Se_AnalyseExp(A_exp node){
	switch(node->kind){
		case A_funcExp:{
			A_proc func = node->u.func;
			A_routinePartHead funcHead = GlobalRoutine(func->name);
			if(!funcHead){
				Se_CheckSysFunc(func->name, func->args, node->pos);
			}else if(funcHead->kind != A_function){
				EM_error(node->pos, "Expect an expression, but '%s' is a procedure.", S_name(funcHead->name));
			}else{
				Se_PassArguments(func->args, funcHead->parameters, node->pos);
				// set the valueType whether any error occured
				node->valueType = funcHead->retType;
			}
			break;
		}
		// const, var, ref, paramless function
		case A_nameExp:{
			NamedExp n = FindName(node->u.name);
			if(n.kind == N_Undefined){
				// nameExp will never be sys-function
				EM_error(node->pos, "Undefined symbol %s in this scope.", S_name(node->u.name));
			}else if(n.kind == N_Const){
				node->kind = A_constExp;
				node->u.constValue = n.u.constVal;
				node->valueType = A_SimpleType(node->pos, A_SimpleSysType(node->pos, node->u.constValue->kind));
			}else if(n.kind == N_Var){
				node->u.var = A_Var(node->pos, node->u.name);
				node->kind = A_varExp;
				node->valueType = n.u.var->type;

				// Get the variable
				// You may build a IR node from this variable v or use another way
				Variable* v = n.u.var;
			}else if(n.kind == N_Ref){
				node->u.var = A_Var(node->pos, node->u.name);
				node->kind = A_varExp;
				node->valueType = n.u.ref->type;

				// Get the Referenced variable
				// You may build a IR node from this variable r
				Variable* r = n.u.ref;

			}else{	// n.kind == N_Routine
				A_routinePartHead funcHead = n.u.routine;
				if(funcHead->kind == A_procedure){
					EM_error(node->pos, "Expect an expression, but '%s' is a procedure.", S_name(funcHead->name));
				}else if(funcHead->parameters != nullptr){
					EM_error(node->pos, "Function '%s' needs parameters.", S_name(funcHead->name));
				}else{
					// almost useless, just a mark
					node->u.func = A_Proc(node->pos, node->u.name, nullptr);
				}
				node->kind = A_funcExp;
				node->valueType = funcHead->retType;

				// you may use 'funcHead' to call the corresponding function
			}
			break;
		}
		case A_varExp:{
			A_var var = node->u.var;
			Se_AnalyseVar(var);
			node->valueType = var->valueType;
			break;
		}
		case A_constExp:{
			node->valueType = A_SimpleType(node->pos, A_SimpleSysType(node->pos, node->u.constValue->kind));
			break;
		}
		case A_opExp:{
			A_op opExp = node->u.op;
			A_oper oper = opExp->oper;
			bool isLegalType = true;
			if(oper != A_notOp && oper != A_negOp ){
				Se_AnalyseExp(opExp->left);
				if(opExp->left->valueType && opExp->left->valueType->kind == A_simpleType 
				 && opExp->left->valueType->u.simple->kind == A_simpleSysType 
				 && opExp->left->valueType->u.simple->u.sysType != Ty_string){
					 isLegalType &= true;
				 }else isLegalType = false;
			}
			Se_AnalyseExp(opExp->right);
			if(opExp->right->valueType && opExp->right->valueType->kind == A_simpleType 
				 && opExp->right->valueType->u.simple->kind == A_simpleSysType
				 && opExp->right->valueType->u.simple->u.sysType != Ty_string){
					 isLegalType &= true;
			}else 
				isLegalType = false;

			// if no error happened to both sides
			if(isLegalType){
				SysType leftType = opExp->left ? opExp->left->valueType->u.simple->u.sysType : Ty_null;
				SysType rightType = opExp->right->valueType->u.simple->u.sysType;
				switch(oper){
					case A_plusOp: 
					case A_minusOp:
					case A_mulOp:
					case A_modOp:
					case A_divOp:
						Se_AnalyseArithOp(node);
						break;
					case A_eqOp:
					case A_neqOp:
					case A_ltOp:
					case A_leOp:
					case A_gtOp:
					case A_geOp:
						Se_AnalyseCmpOp(node);
						break;
					case A_andOp:
					case A_orOp:
						Se_AnalyseLogicOp(node);
						break;
					case A_notOp:{
						if(rightType != Ty_boolean){
							EM_error(opExp->right->pos, "Expect a boolean value following NOT.");
						}else{
							node->valueType = opExp->right->valueType;	// SysType->boolean
							if(opExp->right->kind == A_constExp){
								node->kind = A_constExp;
								node->u.constValue = A_Bool(node->pos, 1 - opExp->right->u.constValue->u.boolean);
							}else{
								// you may construct a IR node here
							}
						}
						break;
					}
					case A_negOp:{
						if(rightType != Ty_integer && rightType != Ty_real){
							EM_error(opExp->right->pos, "Expect a int/real value following NEG.");
						}else{
							node->valueType = opExp->right->valueType;	// SysType->boolean
							if(opExp->right->kind == A_constExp){
								node->kind = A_constExp;
								if(rightType == Ty_integer)
									node->u.constValue = A_Integer(node->pos, - opExp->right->u.constValue->u.integer);
								else	// rightType == Ty_real
									node->u.constValue = A_Real(node->pos, - opExp->right->u.constValue->u.real);
							}else{
								// you may construct a IR node here
							}
						}
						break;
					}
				}
			}else{
				EM_error(node->pos, "The operand can only apply on non-string system type.");
			}
			break;
		}
	}
	return nullptr;
}

void* Se_AnalyseAssignStmt(A_assignS* assignStmt, A_pos pos){
	Se_AnalyseVar(assignStmt->var);
	Se_AnalyseExp(assignStmt->exp);
	A_var avar = assignStmt->var;
	A_exp aexp = assignStmt->exp;

	if(avar->valueType && aexp->valueType){	// no error happened during analysis
		if(avar->valueType->kind == A_simpleType && avar->valueType->u.simple->kind == A_simpleSysType \
			&& aexp->valueType->kind == A_simpleType && aexp->valueType->u.simple->kind == A_simpleSysType \
			&& canConvert(avar->valueType->u.simple->u.sysType, aexp->valueType->u.simple->u.sysType)){

		}else if(avar->valueType == aexp->valueType && avar->valueType->kind != A_arrayType){
			// this would be a record assign
			// deprecate this feature if you don't want it
		}else{
			EM_error(pos, "Incompatible type for an assign.");
		}
	}
	
	if(!errorNum){
		
	}
	return nullptr;
}
void* Se_AnalyseProcStmt(A_proc procStmt, A_pos pos){
	void* res = nullptr;
	NamedExp symbol = FindName(procStmt->name);

	if(symbol.kind == N_Undefined){
		Se_CheckSysProc(procStmt->name, procStmt->args, pos);
	}else if(symbol.kind != N_Routine){
		if(procStmt->args == nullptr){
			EM_warning(pos, "Unused value %s as a statement.", S_name(procStmt->name));
		}else{
			EM_error(pos, "Symbol %s cannot get arguments.", S_name(procStmt->name));
		}
	}else{
		// build IR node for the call to routine
		A_routinePartHead procHead = symbol.u.routine;
		Se_PassArguments(procStmt->args, procHead->parameters, pos);
		
		if(procHead->kind == A_function){
			EM_warning(pos, "Unused return value from function '%s'.", S_name(procStmt->name));
		}
	}

	return res;
}
void* Se_AnalyseIfStmt(A_ifS* ifStmt, A_pos pos, S_symbol retName, bool& retAssigned){
	Se_AnalyseExp(ifStmt->test);
	if( ! isSysType(ifStmt->test->valueType, Ty_boolean)){
		EM_error(ifStmt->test->pos, "Expect a boolean for if-clause test.");
	}
	bool thenAssigned = false, elseAssigned = false;
	Se_AnalyseStmt(ifStmt->thenStmt, retName, thenAssigned);
	if(ifStmt->elseStmt) Se_AnalyseStmt(ifStmt->elseStmt, retName, elseAssigned);
	retAssigned |= (thenAssigned && elseAssigned);
	return nullptr;
}
void* Se_AnalyseRepeatStmt(A_repeatS* repeatStmt, A_pos pos){
	bool tmp;
	Se_AnalyseStmtList(repeatStmt->body, nullptr, tmp);
	Se_AnalyseExp(repeatStmt->test);
	if( ! isSysType(repeatStmt->test->valueType, Ty_boolean)){
		EM_error(repeatStmt->test->pos, "Expect a boolean for if-clause test.");
	}
	return nullptr;
}
void* Se_AnalyseWhileStmt(A_whileS* whileStmt, A_pos pos){
	Se_AnalyseExp(whileStmt->test);
	if( ! isSysType(whileStmt->test->valueType, Ty_boolean)){
		EM_error(whileStmt->test->pos, "Expect a boolean for if-clause test.");
	}
	bool tmp;
	Se_AnalyseStmt(whileStmt->body, nullptr, tmp);
	return nullptr;
}
void* Se_AnalyseForStmt(A_forS* forStmt, A_pos pos){
	A_var var = forStmt->var;
	A_exp initValue = forStmt->initValue, finalValue = forStmt->finalValue;
	Se_AnalyseVar(var);
	Se_AnalyseExp(initValue);
	Se_AnalyseExp(finalValue);
	if(var->valueType && initValue->valueType && finalValue->valueType){
		bool legal = true;
		if(!isSysType(var->valueType, Ty_integer)){
			EM_error(var->pos, "Expect an integer-type variable as the loop counter.");
			legal = false;
		}
		if(!isSysType(initValue->valueType, Ty_integer)){
			EM_error(initValue->pos, "Expect an integer expression as the initial value.");
			legal = false;
		}
		if(!isSysType(finalValue->valueType, Ty_integer)){
			EM_error(finalValue->pos, "Expect an integer expression as the final value.");
			legal = false;
		}
		if(legal){
			if(initValue->kind == A_constExp && finalValue->kind == A_constExp){
				int i = initValue->u.constValue->u.integer,
					f = finalValue->u.constValue->u.integer;
				if( (f - i) * forStmt->direction < 0){
					EM_warning(pos, "The loop will never be executed.");
				}
			}
			bool tmp;
			Se_AnalyseStmt(forStmt->body, nullptr, tmp);
			// construct your IR node here.
		}
	}

	return nullptr;
}

//Note: case condition should be integer consttant
// the name will be converted to the integer
void* Se_AnalyseCaseStmt(A_caseS* caseStmt, A_pos pos, S_symbol retName, bool& retAssigned){
	Se_AnalyseExp(caseStmt->test);
	A_caseList casePtr = caseStmt->caselist;
	bool allCaseAssigned = true;
	while(casePtr != nullptr){
		bool caseAssigned = false;
		A_case caseHead = casePtr->head;

		if(caseHead->name != nullptr){
			A_const nameVal = GlobalConst(caseHead->name);
			if(nameVal == nullptr){
				EM_error(caseHead->pos, "Undefined case label %s.", S_name(caseHead->name));
			}else if(nameVal->kind != Ty_integer){
				EM_error(caseHead->pos, "Case label %s is expected to be an integer.", S_name(caseHead->name));
			}else {
				// successful convert
				caseHead->constValue = nameVal;
			}
		}
		
		if(caseHead->constValue != nullptr){
			if(caseHead->constValue->kind != Ty_integer){
				EM_error(caseHead->pos, "Case label is expected to be an integer.");
			}else{
				int caseLabel = caseHead->constValue->u.integer;
				// deal everything you need with caseLabel
			}
		}

		Se_AnalyseStmt(caseHead->body, retName, caseAssigned);
		allCaseAssigned &= caseAssigned;
		casePtr = casePtr->next;
	}
	retAssigned |= allCaseAssigned;
	return nullptr;
}