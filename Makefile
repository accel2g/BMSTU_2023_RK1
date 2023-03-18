CC=g++
CFLAGS=-c -Wall

all: RK1

RK1: main.o tasks_rk1.o
	$(CC) main.o tasks_rk1.o -o RK1

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

tasks_rk1.o: tasks_rk1.cpp
	$(CC) $(CFLAGS) tasks_rk1.cpp

clean:
	rm -rf *.o RK1