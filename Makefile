OBJS = HashTable.o main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

proj1: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o proj1

HashTable.o: HashTable.cpp HashTable.h HashEntry.h
	$(CC) $(CFLAGS) HashTable.cpp

main.o: main.cpp HashTable.h HashEntry.h Student.h
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm *.o  proj1

all: proj1
