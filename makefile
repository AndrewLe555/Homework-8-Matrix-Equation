CC = gcc
CXX = g++
CXXFLAGS = -Wall
CFLAGS = -std=c99 -Wall -O0

matrixCpp: matrix.cpp
	$(CXX) $(CXXFLAGS) matrix.cpp -o matrixCpp

matrixC: matrix.c
	$(CC) $(CFLAGS) matrix.c -o matrixC

runCpp: matrixCpp
	./matrixCpp

runC: matrixC
	./matrixC