CC = g++
CFLAGS = -Wall -g

objects = main.o node.o stack.o nosuchobject.o

hw2q5 : $(objects)
        cc -o hw2q5 $(objects)
main.o : main.cpp main.h
        cc -c main.cpp
clean :
        rm edit $(objects)