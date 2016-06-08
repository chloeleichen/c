all: main.c 
	gcc -g -Wall -o main main.c
clean: 
	rm -rf main
