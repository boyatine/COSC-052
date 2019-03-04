a.out: main.o numbers.o
	g++ main.o numbers.o

main.o: main.cpp main.h numbers.h
	g++ -c main.cpp

numbers.o: numbers.cpp numbers.h
	g++ -c numbers.cpp

clean:
	rm -f a.out *.o