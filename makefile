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
	@echo gcc -std=c99 -o $@ $(OBJS)
	@gcc  -std=c99 -o $@ $(OBJS)
	@echo ' '

test_unit.exe: test_unit.o symbol.o
	@gcc -std=c99 -o $@ $^

.PHONY: all clean

# source
SPL_lex.o: SPL_lex.c SPL_parse.h errormsg.h

SPL_parse.o: SPL_parse.c SPL_parse.h errormsg.h

errormsg.o: errormsg.c errormsg.h

symbol.o: symbol.c symbol.h

type.o: type.c type.h

utils.o: utils.c utils.h

absyn.o: absyn.c absyn.h

test_unit.o: test_unit.c symbol.h
	gcc -c -o $@ $<

SPL_parse.c: SPL_parse.y

SPL_lex.c: SPL_lex.l utils.h


clean:
	${RM} *.bak *.o

