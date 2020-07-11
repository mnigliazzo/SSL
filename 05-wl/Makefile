SOURCE1 = wl-1-enum-switch.c
BIN1 = wl-1-enum-switch.exe
OBJ1 = wl-1-enum-switch.o

SOURCE2 = wl-2-goto.c
BIN2 = wl-2-goto.exe
OBJ2 = wl-2-goto.o

CC = gcc
#CFLAGS = -std=c18 
CFLAGS = 
RM = rm -f

all: $(BIN1) $(BIN2)

$(BIN1): $(OBJ1)
	$(CC) $(OBJ1) -o $(BIN1) $(CFLAGS)

$(BIN2): $(OBJ2)
	$(CC) $(OBJ2) -o $(BIN2) $(CFLAGS)

$(OBJ1): $(SOURCE1)
	$(CC) -c $(SOURCE1) -o $(OBJ1) $(CFLAGS)

$(OBJ2): $(SOURCE2)
	$(CC) -c $(SOURCE2) -o $(OBJ2) $(CFLAGS)

.PHONY: clean
clean:
	$(RM) $(OBJ1) $(BIN1)
	$(RM) $(OBJ2) $(BIN2)
