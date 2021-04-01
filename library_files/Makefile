CC = gcc

CFLAGS = -fPIC -Wall -g
LDFLAGS = -shared

TRGT = ll_lib.so
SRC = programa.c
OBJ = programa.o

default: $(TRGT)

$(TRGT): $(OBJ)
	$(CC) $(CFLAGS) -shared -o $@ $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)