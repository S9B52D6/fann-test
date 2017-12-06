LDIR=/usr/local/lib
LIBS=-lm -lfann

all: training test

training: training.c
	gcc -o training training.c $(LIBS)
test: test.c
	gcc -o test test.c $(LIBS)
