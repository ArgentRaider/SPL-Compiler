#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

static int test_count = 0;
static int test_pass = 0;
static int main_ret = 0;

void test(void);

void test_symbol(void);
void test_table(void);

int main(){
	test();
	printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
	return main_ret;
}

#define EXPECT_EQ_BASE(equality, expect, actual, format) \
    do {\
        test_count++;\
        if (equality)\
            test_pass++;\
        else {\
            fprintf(stderr, "%s:%d: expect: " format " actual: " format "\n", __FILE__, __LINE__, expect, actual);\
            main_ret = 1;\
        }\
    } while(0)

void test(){
	test_symbol();
}

#define EXPECT_EQ_STRING(expect, actual) \
	EXPECT_EQ_BASE( strcmp(expect,actual) == 0, expect, actual, "%s")
#define TEST_SYMBOL(name) \
	do{ \
		S_symbol s = S_Symbol(name);\
		char* n = S_name(s); \
		EXPECT_EQ_STRING(name, n); \
		free(s); \
	}while(0)

void test_symbol(void){
	TEST_SYMBOL("haha");
	TEST_SYMBOL("_a");
	TEST_SYMBOL("23;a*)^");
}