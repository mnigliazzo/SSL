SOURCE = hello.c
BIN = hello.exe
OBJ = hello.o
CC = gcc
CFLAGS = -std=c18

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

run: $(BIN)
	$(BIN)

$(OBJ): $(SOURCE)
	$(CC) -c $(SOURCE) -o $(OBJ) $(CFLAGS)