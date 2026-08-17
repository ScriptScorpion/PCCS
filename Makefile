CC := g++
CCF := -std=c++17 -O1 -Wall -Wextra -lncurses
SRC := main.cpp
OUT := pccs
main:
	$(CC) $(SRC) -o $(OUT) $(CCF)
