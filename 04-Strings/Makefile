SOURCE = StringsTest.c
BIN = StringsTest.exe
OBJ = StringsTest.o
LIBC = String.c
LIBH = String.h
LIBO = String.o
CC = gcc
CFLAGS = -std=c18
RM = rm -f

$(BIN): $(OBJ) $(LIBO)
	$(CC) $(OBJ) $(LIBO) -o $(BIN) $(CFLAGS)

run: $(BIN)
	$(BIN)

$(OBJ): $(SOURCE) $(LIBH)
	$(CC) -c $(SOURCE) -o $(OBJ) $(CFLAGS)

$(LIBO): $(LIBH) $(LIBC)
	$(CC) -c $(LIBC) -o $(LIBO) $(CFLAGS)

.PHONY: clean
clean:
	$(RM) $(OBJ) $(BIN) $(LIBO)

