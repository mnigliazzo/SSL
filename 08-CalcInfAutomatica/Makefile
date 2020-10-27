SOURCE = Calc.c Scanner.c Parser.c
BIN = Calc.exe
OBJ = Calc.o Scanner.o Parser.o
CC = gcc
#CFLAGS = -std=c18
RM = rm -f
#flex -oScanner.c scanner.l

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

run: $(BIN)
	./$(BIN) <valida.txt> out.txt

$(OBJ): $(SOURCE)
	$(CC) -c $(SOURCE) -L "C:\Program Files (x86)\GnuWin32\lib" -lfl $(CFLAGS)


.PHONY: clean
clean:
	$(RM) $(OBJ) $(BIN)

all: clean $(BIN) run
	
