CC = gcc

build: main.c
	$(CC) -o main main.c

run: main
	./main

clean:
	del -f main.exe