GXX=clang
IN=ncurses.c
OUT=nc
FLAGS=-lncurses -Wall

all:
	$(GXX) $(IN) $(FLAGS) -o $(OUT)
