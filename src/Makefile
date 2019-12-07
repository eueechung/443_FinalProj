# Usage:
# 	VERT_NO=X ANT_NO=Y make
# Replace X and Y with the number of vertices and ants you want the program to handle.

all: aco.hpp main.cpp
	g++ -g -Wall -DVERT_NO=$(VERT_NO) -DANT_NO=$(ANT_NO) main.cpp -o qap.exe
