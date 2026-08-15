CC := g++
CCF := -std=c++17 -O1 -Wall -Wextra -lncurses
SRC := main.cpp
OUT := exe
main:
	$(CC) $(SRC) -o $(OUT) $(CCF)
