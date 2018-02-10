CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c -O3 $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all : demo-kalman

demo-kalman : demo-kalman.o
	$(CC) $(LFLAGS) demo-kalman.o -o demo-kalman

demo-kalman.o : demo-kalman.cpp kalman.hpp
	$(CC) $(CFLAGS) demo-kalman.cpp
