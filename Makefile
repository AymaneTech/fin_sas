all: compile 

clear:
	clear

compile: ubuntu.c
	gcc ubuntu.c -o a.out
	
	./a.out
