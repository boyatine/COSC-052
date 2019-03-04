#
# HW2 Makefile
#

CC = g++
CFLAGS = -Wall -g
SRCS = main.cpp hand.cpp deck.cpp card.cpp
OBJS = ${SRCS:.cpp=.o}
INCLS = ${SRCS:.cpp=.h}

a.out: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)

$(OBJS):
	$(CC) $(CFLAGS) -c $*.cpp

depend: Makefile.dep
	$(CC) -MM $(SRCS) > Makefile.dep

Makefile.dep:
	touch Makefile.dep

.PHONY: docs submit clean

docs:
	doxygen $(SRCS) $(INCLS)

submit:
	rm -f submit.zip
	zip submit.zip $(SRCS) $(INCLS) Makefile Makefile.dep HONOR

clean:
	rm -rf *.o a.out core latex html

include Makefile.dep

