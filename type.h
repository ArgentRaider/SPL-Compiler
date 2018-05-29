/*
 * System-Defined types
 */
#ifndef _TYPE_H
#define _TYPE_H

typedef enum SysType_
{
	Ty_boolean = 1,		//     1
	Ty_char = 2,		//    10
	Ty_integer = 11,  	//  1011
	Ty_real = 27,		// 11011
	Ty_string = 6,		//   110
} SysType;

int canConvert(int dstType, int srcType);

typedef enum {
	A_plusOp, A_minusOp, A_mulOp, A_modOp, A_divOp,
	A_eqOp, A_neqOp, A_ltOp, A_leOp, A_gtOp, A_geOp, A_orOp,
	A_andOp, A_notOp, A_negOp,
} OperatorType;

#endif