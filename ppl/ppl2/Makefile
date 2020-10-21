
PROG = simple
CFLAGS = -O3 -I. -fpermissive
SCANNER = scanner
GRAMMAR = grammar
FLEX = flex
BISON = bison
SRCS = driver.c lex.yy.c $(PROG).c
BIN = $(PROG).exe
CC = g++

all: grammar scanner bin 

bin: $(SRCS)
	$(CC) $(CFLAGS) -o $(BIN) $(SRCS) 

grader: $(SRCS) grammar scanner
	$(CC) $(CFLAGS) -o $(BIN) $(SRCS) -DPL_GRADER

scanner: $(SCANNER).yy
	$(FLEX) $(SCANNER).yy

grammar: $(GRAMMAR).y
	$(BISON) $(GRAMMAR).y -o $(PROG).c

clean: 
	rm *.exe lex.yy.c $(PROG).? *.o
