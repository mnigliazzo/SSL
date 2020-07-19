SOURCE1 = wl-1-enum-switch.c
BIN1 = wl-1-enum-switch.exe
OBJ1 = wl-1-enum-switch.o

SOURCE2 = wl-2-goto.c
BIN2 = wl-2-goto.exe
OBJ2 = wl-2-goto.o

SOURCE3 = wl-3-rec.c
BIN3 = wl-3-rec.exe
OBJ3 = wl-3-rec.o

SOURCE4 = wl-4.c
BIN4 = wl-4.exe
OBJ4 = wl-4.o

CC = gcc
#CFLAGS = -std=c18 
CFLAGS = 
RM = rm -f

all: $(BIN1) $(BIN2) $(BIN3) $(BIN4)

$(BIN1): $(OBJ1)
	$(CC) $(OBJ1) -o $(BIN1) $(CFLAGS)

$(BIN2): $(OBJ2)
	$(CC) $(OBJ2) -o $(BIN2) $(CFLAGS)

$(BIN3): $(OBJ3)
	$(CC) $(OBJ3) -o $(BIN3) $(CFLAGS)

$(BIN4): $(OBJ4)
	$(CC) $(OBJ4) -o $(BIN4) $(CFLAGS)

$(OBJ1): $(SOURCE1)
	$(CC) -c $(SOURCE1) -o $(OBJ1) $(CFLAGS)

$(OBJ2): $(SOURCE2)
	$(CC) -c $(SOURCE2) -o $(OBJ2) $(CFLAGS)

$(OBJ3): $(SOURCE3)
	$(CC) -c $(SOURCE3) -o $(OBJ3) $(CFLAGS)

$(OBJ4): $(SOURCE4)
	$(CC) -c $(SOURCE4) -o $(OBJ4) $(CFLAGS)

.PHONY: clean
clean:
	$(RM) $(OBJ1) $(BIN1)
	$(RM) $(OBJ2) $(BIN2)
