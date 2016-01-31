OBJS = Hashtable.o Main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

proj1: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o proj1

Hashtable.o: Hashtable.cpp Hashtable.h
	$(CC) $(CFLAGS) Hashtable.cpp

Main.o: Main.cpp Hashtable.h Student.h
	$(CC) $(CFLAGS) Main.cpp

clean:
	\rm *.o  proj1

all: proj1
