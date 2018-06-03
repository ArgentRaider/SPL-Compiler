#
# makefile for SPL
#
BIN  = SPL.exe test_unit.exe
OBJS = SPL_parse.o SPL_lex.o utils.o symbol.o type.o absyn.o errormsg.o
RM   = rm.exe -f

# rules
%.c: %.y
	bison -d -o $(@:%.o=%.d) $<

%.c: %.l
	flex -o$(@:%.o=%.d) $<

# dependencies
all: $(BIN)

SPL.exe: $(OBJS)
	@echo g++ -std=c++11 -o $@ $(OBJS)
	@g++  -std=c++11 -o $@ $(OBJS)
	@echo ' '

test_unit.exe: test_unit.o symbol.o utils.o
	@g++ -std=c++11 -o $@ $^

.PHONY: all clean

# source
SPL_lex.o: SPL_lex.cpp SPL_parse.h errormsg.h

SPL_parse.o: SPL_parse.cpp SPL_parse.h errormsg.h

errormsg.o: errormsg.cpp errormsg.h

symbol.o: symbol.cpp symbol.h

type.o: type.cpp type.h

utils.o: utils.cpp utils.h

absyn.o: absyn.cpp absyn.h

test_unit.o: test_unit.cpp symbol.h
	g++ -c -o $@ $<

# SPL_parse.c: SPL_parse.y

# SPL_lex.c: SPL_lex.l utils.h


clean:
	${RM} *.bak *.o

