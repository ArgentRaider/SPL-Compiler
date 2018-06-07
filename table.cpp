#include <vector>
#include <unordered_map>
#include "table.h"
#include "errormsg.h"

#define TAB_DEBUG
#ifdef TAB_DEBUG
#include <cstdio>
#endif

typedef std::unordered_map<S_symbol, A_const> ConstMap;
typedef std::unordered_map<S_symbol, A_type> TypeMap;
typedef std::unordered_map<S_symbol, Variable*> VarMap;
typedef std::unordered_map<S_symbol, A_routinePartHead> RoutineMap;
typedef std::unordered_map<S_symbol, Variable*> RefMap;
typedef std::unordered_map<int, A_stmt> LabelHash;


struct Environment{
	ConstMap constMap;
	TypeMap typeMap;
	VarMap varMap;
	RoutineMap routineMap;		// records those Var type defined in the head of a routine
	RefMap refMap;
	LabelHash labelMap;
};

std::vector<Environment> envVec;

void BeginScope(){
	Environment newEnv;
	envVec.push_back(std::move(newEnv));
}

void EndScope(){
	Environment& env = envVec.back();
	for(auto viter: env.varMap){
		delete viter.second;
	}
	for(auto riter: env.refMap){
		delete riter.second;
	}
	envVec.pop_back();
}

bool DeclareLabel(int label, A_stmt stmt){
	bool res = false;
	Environment& env = envVec.back();
	if(env.labelMap.find(label) == env.labelMap.end()){
		env.labelMap[label] = stmt;
		res = true;
	}
	return res;
}
A_stmt LocalLabel(int label){
	A_stmt res = nullptr;
	const Environment& env = envVec.back();
	if(env.labelMap.find(label) != env.labelMap.end()){
		res = env.labelMap.at(label);
	}
	return res;
}

NamedExp && FindName(S_symbol name){
	NamedExp res = NamedExp();
	for(int i = envVec.size() - 1; i >= 0; i--){
		const Environment& env = envVec[i];
		if(env.varMap.find(name) != env.varMap.end()){
			res.kind = N_Var;
			res.u.var = env.varMap.at(name);
			break;
		}else if(env.refMap.find(name) != env.refMap.end()){
			res.kind = N_Ref;
			res.u.ref = env.refMap.at(name);
			break;
		}else if(env.constMap.find(name) != env.constMap.end()){
			res.kind = N_Const;
			res.u.constVal = env.constMap.at(name);
			break;
		}else if(env.routineMap.find(name) != env.routineMap.end()){
			res.kind = N_Routine;
			res.u.routine = env.routineMap.at(name);
			break;
		}
	}
	return std::move(res);
}

Variable* FindVar(S_symbol name){
	Variable* res = nullptr;
	for(int i = envVec.size() - 1; i >= 0; i--){
		const Environment& env = envVec[i];
		if(env.varMap.find(name) != env.varMap.end()){
			res = env.varMap.at(name);
			break;
		}else if(env.refMap.find(name) != env.refMap.end()){
			res = env.refMap.at(name);
			break;
		}
	}
	return res;
}

A_const GlobalConst(S_symbol name){
	for(int i = envVec.size()-1; i >= 0; i--){
		const Environment& env = envVec[i];
		if(env.constMap.find(name) != env.constMap.end()){
			return env.constMap.at(name);
		}
	}
	return nullptr;
}
A_const LocalConst(S_symbol name){
	const Environment& env = envVec.back();
	if(env.constMap.find(name) == env.constMap.end()){
		return nullptr;
	}else{
		return env.constMap.at(name);
	}
}
A_type GlobalType(S_symbol name){
	for(int i = envVec.size()-1; i >= 0; i--){
		const Environment& env = envVec[i];
		if(env.typeMap.find(name) != env.typeMap.end()){
			return env.typeMap.at(name);
		}
	}
	return nullptr;
}
A_type LocalType(S_symbol name){
	const Environment& env = envVec.back();
	if(env.typeMap.find(name) == env.typeMap.end()){
		return nullptr;
	}else{
		return env.typeMap.at(name);
	}
}
Variable* GlobalVar(S_symbol name){
	for(int i = envVec.size()-1; i >= 0; i--){
		const Environment& env = envVec[i];
		if(env.varMap.find(name) != env.varMap.end()){
			return env.varMap.at(name);
		}
	}
	return nullptr;
}
Variable* LocalVar(S_symbol name){
	const Environment& env = envVec.back();
	if(env.varMap.find(name) == env.varMap.end()){
		return nullptr;
	}else{
		return env.varMap.at(name);
	}
}
Variable* GlobalRef(S_symbol name){
	for(int i = envVec.size()-1; i >= 0; i--){
		const Environment& env = envVec[i];
		if(env.refMap.find(name) != env.refMap.end()){
			return env.refMap.at(name);
		}
	}
	return nullptr;
}
Variable* LocalRef(S_symbol name){
	const Environment& env = envVec.back();
	if(env.refMap.find(name) == env.refMap.end()){
		return nullptr;
	}else{
		return env.refMap.at(name);
	}
}
A_routinePartHead GlobalRoutine(S_symbol name){
	for(int i = envVec.size()-1; i >= 0; i--){
		const Environment& env = envVec[i];
		if(env.routineMap.find(name) != env.routineMap.end()){
			return env.routineMap.at(name);
		}
	}
	return nullptr;
}
A_routinePartHead LocalRoutine(S_symbol name){
	const Environment& env = envVec.back();
	if(env.routineMap.find(name) == env.routineMap.end()){
		return nullptr;
	}else{
		return env.routineMap.at(name);
	}
}

bool LocalDefined(S_symbol name){
	bool res = true;
	const Environment& env = envVec.back();
	if(env.constMap.find(name) == env.constMap.end() && \
		env.typeMap.find(name) == env.typeMap.end() && \
		env.varMap.find(name) == env.varMap.end() && \
		env.routineMap.find(name) == env.routineMap.end() && \
		env.refMap.find(name) == env.refMap.end())
		res = false;
	return res;
}

A_type RealType(A_type type){
	if(!type)return nullptr;
	A_type res = type;
	if(type->kind == A_simpleType){
		if(type->u.simple->kind == A_simpleNameType){
			S_symbol typeName = type->u.simple->u.name;
			res = GlobalType(typeName);
			// Not Found
			if(!res || (res->kind == A_simpleType && res->u.simple->kind == A_simpleNameType)){
				EM_error(type->pos, "Undefined type-name: %s.", S_name(type->u.simple->u.name));
				res = nullptr;
			}
		}
	}
	else if(type->kind == A_arrayType){
		A_range arrayRange = type->u.array->range;
		if(arrayRange->kind == A_nameRange){	// Fetch the real value of the names
			S_symbol lname = arrayRange->lower_u.lname, uname = arrayRange->upper_u.uname;
			A_const lval = GlobalConst(lname), uval = GlobalConst(uname);
			if(lval && uval){
				arrayRange->lower_u.lconst = lval;
				arrayRange->upper_u.uconst = uval;
				arrayRange->kind = A_constRange;
			}else{
				res = nullptr;
				if(!lval){EM_error(arrayRange->pos, "The lower bound %s of the array is not defined.", \
						S_name(lname));}
				if(!uval){EM_error(arrayRange->pos, "The upper bound %s of the array is not defined.", \
						S_name(uname));}
			}
		}
		// check if both bound is integer and lowerbound <= upperbound
		if(arrayRange->kind == A_constRange){
			A_const lconst = arrayRange->lower_u.lconst, uconst = arrayRange->upper_u.uconst;
			if(lconst->kind == Ty_integer && uconst->kind == Ty_integer){
				if(lconst->u.integer > uconst->u.integer){
					res = nullptr;
					EM_error(arrayRange->pos, "The lower bound %d should not be greater than upper bound %d." \
					, lconst->u.integer, uconst->u.integer);
				}
			}else{
				res = nullptr;
				if(lconst->kind != Ty_integer){EM_error(arrayRange->pos, \
				"The lower bound of the array should be of integer type.");}
				if(uconst->kind != Ty_integer){EM_error(arrayRange->pos, \
				"The upper bound of the array should be of integer type.");}
			}
		}
	}
	else if(type->kind == A_recordType){
		BeginScope();
		for(A_fieldList fieldPtr = type->u.fieldList; fieldPtr != nullptr; fieldPtr = fieldPtr->next){
			A_field head = fieldPtr->head;
			A_type realType = RealType(head->type);
			if(!realType){ res = nullptr;}
			else{
				for(A_nameList varPtr = head->nameList; varPtr != nullptr; varPtr = varPtr->next){
					if(!DefineVar(varPtr->head->name, realType, varPtr->head->pos)){
						res = nullptr;
					}
				}
			}
			if(res) // Fill the real type of the field
				head->type = realType;
		}
		EndScope();
	}
	// This line should never be executed.
	else EM_error(type->pos, "Unrecognized Type.");
	return res;
}

bool DefineConst(S_symbol name, A_const constVal, A_pos pos){
	bool res = ! LocalDefined(name);
	if(res){
		Environment& env = envVec.back();
		env.constMap[name] = constVal;
	}else{
		EM_error(pos, "Redefined symbol %s in this scope.", S_name(name));
	}
	return res;
}

bool DefineType(S_symbol name, A_type type, A_pos pos){
	bool res = ! LocalDefined(name);
	A_type realType = RealType(type);
	if(res){
		if(realType){
			Environment& env = envVec.back();
			env.typeMap[name] = realType;
		}else res = false;
	}else{
		EM_error(pos, "Redefined symbol %s in this scope.", S_name(name));
	}
	return res;
}

bool DefineVar(S_symbol name, A_type varType, A_pos pos){
	bool res = ! LocalDefined(name);
	varType = RealType(varType);
	if(res){
		if(varType){
			Environment& env = envVec.back();
			Variable* var = new Variable(name, varType, false);
			env.varMap[name] = var;
		}else res = false;
	}else{
		EM_error(pos, "Redefined symbol %s in this scope.", S_name(name));
	}
	return res;
}

bool DefineRef(S_symbol name, A_type refType, A_pos pos){
	bool res = ! LocalDefined(name);
	refType = RealType(refType);
	if(res){
		if(refType){
			Environment& env = envVec.back();
			Variable* ref = new Variable(name, refType, true);
			env.refMap[name] = ref;
		}else res = false;
	}else{
		EM_error(pos, "Redefined symbol %s in this scope.", S_name(name));
	}
	return res;
}

bool DefineRoutine(S_symbol name, A_routinePartHead routinePartHead, A_pos pos){
	bool res = ! LocalDefined(name);
	if(routinePartHead->kind == A_function){
		routinePartHead->retType = RealType(routinePartHead->retType);
	}

	A_paraList paraList = routinePartHead->parameters;
	BeginScope();
	if(routinePartHead->kind == A_function){
		S_symbol retName = routinePartHead->name;
		// Define the name of this function as a Var
		// so that it won't be redefined inside the funciton
		DefineVar(retName, routinePartHead->retType, routinePartHead->pos);
	}
	bool paraDef = DefineParameters(paraList);
	EndScope();

	if(res){
		if( (routinePartHead->kind == A_function \
			&& !routinePartHead->retType) \
			|| !paraDef){
			res = false;
		}else{
			Environment& env = envVec.back();
			env.routineMap[name] = routinePartHead;
		}		
	}else{
		EM_error(pos, "Redefined symbol %s in this scope.", S_name(name));
	}
	return res;
}

bool DefineParameters(A_paraList paraList){
	bool res = true;
	for(A_paraList ptr = paraList; ptr != nullptr; ptr = ptr->next){
		A_paraField field = ptr->field;
		// check type
		field->type = RealType(field->type);
		if(!field->type){
			res = false;
			continue;
		} 
		// check name
		if(field->kind == Var){
			for(A_nameList refPtr = field->nameList; refPtr != nullptr; refPtr = refPtr->next){
				res &= DefineRef(refPtr->head->name, field->type, refPtr->head->pos);
			}
		}else{
			for(A_nameList varPtr = field->nameList; varPtr != nullptr; varPtr = varPtr->next){
				res &= DefineVar(varPtr->head->name, field->type, varPtr->head->pos);
			}
		}
	}
	return res;
}