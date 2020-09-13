SOURCE = Calc.c Scanner.c Parser.c
BIN = Calc.exe
OBJ = Calc.o Scanner.o Parser.o
CC = gcc
CFLAGS = -std=c18
RM = rm -f

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

run: $(BIN)
	$(BIN)

$(OBJ): $(SOURCE)
	$(CC) -c $(SOURCE) $(CFLAGS)

.PHONY: clean
clean:
	$(RM) $(OBJ) $(BIN)

