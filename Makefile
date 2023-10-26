CC = gcc

CFLAGS = -g -Wall `sdl-config --cflags`
LFLAGS = `sdl-config --libs` -lSDL_image -lSDL_ttf

BIN = tictactoe

all: $(BIN)

$(BIN): utils.o drawing.o tictactoe.c main.o
	$(CC) $^ -o $(BIN) $(LFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<
