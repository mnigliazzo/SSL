SOURCE = Calc.c Scanner.c Parser.c Evaluar.c TablaSimbolos.c
BIN = Calc.exe
OBJ = Calc.o Scanner.o Parser.o Evaluar.o TablaSimbolos.o
FLEXL = scanner.l
FLEXC =Scanner.c
CC = gcc
CFLAGS = -std=c18 -g

RM = rm -f
#flex -oScanner.c scanner.l
$(BIN): $(OBJ) $(FLEXC)
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

run: $(BIN)
	./$(BIN) <Calc_in.txt> Calc_out.txt

$(OBJ): $(SOURCE)
	$(CC) -c $(SOURCE) $(CFLAGS)

.PHONY: clean
clean:
	$(RM) $(OBJ) $(BIN)
	$(RM) $(FLEXC)

all: clean $(BIN) run

$(FLEXC): $(FLEXL)
	flex -o$(FLEXC) $(FLEXL)
	
