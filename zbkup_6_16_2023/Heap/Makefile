# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: heap.cpp
	$(CC) $(CFLAGS) -o main heap.cpp
 
# The main.o target can be written more simply
 
#main.o: heap.cpp
#	$(CC) $(CFLAGS) -c main.cpp
 
#Point.o: Point.h
 
#Square.o: Square.h Point.h

clean:
	rm -rf main
