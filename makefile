#
# makefile for SPL
#
OBJS = errormsg.o SPL_lex.o SPL_parse.o utils.o
RM   = rm.exe -f

# rules
%.c: %.y
	bison -d -o $(@:%.o=%.d) $<

%.c: %.l
	flex -o$(@:%.o=%.d) $<

# dependencies
SPL.exe: SPL_parse.c SPL_lex.c SPL_parse.h errormsg.h errormsg.c $(OBJS)
	@echo gcc -std=c99 -o $@ $(OBJS)
	@gcc  -std=c99 -o $@ $(OBJS)
	@echo ' '

.PHONY: clean

# source
SPL_lex.o: SPL_lex.c SPL_parse.h errormsg.h

SPL_parse.o: SPL_parse.c SPL_parse.h errormsg.h

errormsg.o: errormsg.c errormsg.h

utils.o: utils.c utils.h

SPL_parse.c: SPL_parse.y

SPL_lex.c: SPL_lex.l utils.h

clean:
	${RM} *.bak *.o

