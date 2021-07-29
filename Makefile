all: run 

shell: shell.h shell.c main.c
	gcc -g -std=gnu99 shell.c main.c -o shell 

run: shell 
	shell

clean:
	rm shell 

check:
	valgrind --leak-check=full shell
