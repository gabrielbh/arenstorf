
CC= g++
CFLAGS=   -Wvla -c -std=c++17 -Wextra -g -Wall
all: ex1
run: ex1
	ex1

#Executeable

ex1: Ex1.o Arenstorf.o ArenstorfPoint.o
	$(CC)  Ex1.o Arenstorf.o ArenstorfPoint.o -o ex1

#Obj File
Ex1.o: Ex1.cpp Arenstorf.o ArenstorfPoint.o
	$(CC) $(CFLAGS) Ex1.cpp -o Ex1.o

Arenstorf.o: Arenstorf.cpp Arenstorf.h ArenstorfPoint.h
	$(CC) $(CFLAGS) Arenstorf.cpp -o Arenstorf.o

ArenstorfPoint.o: ArenstorfPoint.cpp ArenstorfPoint.h
	$(CC) $(CFLAGS) ArenstorfPoint.cpp -o ArenstorfPoint.o

#Targets

clean:
	$(RM) -f *.o
	$(RM) ex1


.PHONY: clean


