#
# makefile for SPL
#
BIN  = SPL.exe test_unit.exe
OBJS = SPL_parse.o SPL_lex.o utils.o symbol.o type.o absyn.o semantics.o errormsg.o table.o
RM   = rm.exe -f

# rules
# %.c: %.y
# 	bison -d -o $(@:%.o=%.d) $<

# %.c: %.l
# 	flex -o$(@:%.o=%.d) $<

# dependencies
all: $(BIN)

SPL.exe: $(OBJS)
	@echo g++ -std=c++11 -o $@ $(OBJS)
	@g++  -std=c++11 -o $@ $(OBJS)
	@echo ' '

test_unit.exe: test_unit.o symbol.o utils.o
	g++ -std=c++11 -o $@ $^

.PHONY: all clean

# source
SPL_lex.o: SPL_lex.cpp SPL_parse.h errormsg.h utils.h type.h
	g++ -c -o $@ $<

SPL_parse.o: SPL_parse.cpp SPL_parse.h errormsg.h utils.h symbol.h semantics.h absyn.h
	g++ -std=c++11 -c -o $@ $<

errormsg.o: errormsg.cpp errormsg.h SPL_parse.h absyn.h
	g++ -std=c++11 -c -o $@ $<

symbol.o: symbol.cpp symbol.h utils.h
	g++ -std=c++11 -c -o $@ $<

type.o: type.cpp type.h
	g++ -std=c++11 -c -o $@ $<

utils.o: utils.cpp utils.h absyn.h
	g++ -std=c++11 -c -o $@ $<

absyn.o: absyn.cpp absyn.h symbol.h type.h utils.h SPL_parse.h
	g++ -std=c++11 -c -o $@ $<

semantics.o: semantics.cpp semantics.h absyn.h errormsg.h table.h utils.h
	g++ -std=c++11 -c -o $@ $<

table.o: table.cpp table.h
	g++ -std=c++11 -c -o $@ $<

test_unit.o: test_unit.cpp symbol.h
	g++ -std=c++11 -c -o $@ $<

# SPL_parse.c: SPL_parse.y

# SPL_lex.c: SPL_lex.l utils.h


clean:
	${RM} *.bak *.o

