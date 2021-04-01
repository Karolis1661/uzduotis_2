CC = gcc

TRGT = demo
SRC = demo.c
OBJ = demo.o
LIB = library_files/ll_lib.so
COLL = $(OBJ) $(LIB)

default = $(TRGT)

$(TRGT): $(COLL)
	$(CC) -o $@ $(COLL)

$(OBJ): $(SRC)
	$(CC) -c $(SRC)