CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c -O3 $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all : demo-kalman demo-vector

demo-kalman : demo-kalman.o
	$(CC) $(LFLAGS) demo-kalman.o -o demo-kalman

demo-vector : demo-vector.o
	$(CC) $(LFLAGS) demo-vector.o -o demo-vector

demo-kalman.o : demo-kalman.cpp kalman.hpp
	$(CC) $(CFLAGS) demo-kalman.cpp

demo-vector.o : demo-vector.cpp vector.hpp
	$(CC) $(CFLAGS) demo-vector.cpp
