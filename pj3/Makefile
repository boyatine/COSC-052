CC = g++
CFLAGS = -Wall -g

SRCS = ${wildcard *.cpp}
OBJS = ${SRCS:.cpp=.o}
INCLS = ${SRCS:.cpp=.h} stack.h node.h nosuchobject.h

a.out: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)

$(OBJS):
	$(CC) $(CFLAGS) -c $*.cpp

depend: Makefile.dep
	$(CC) -MM $(SRCS) > Makefile.dep

Makefile.dep:
	touch Makefile.dep

.PHONY: submit clean

submit:
	rm -f submit.zip
	zip submit.zip $(SRCS) $(INCLS) Makefile Makefile.dep

clean:
	rm -f *.o a.out core

include Makefile.dep

