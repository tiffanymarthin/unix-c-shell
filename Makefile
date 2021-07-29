all: run 

shell: shell_commands.h shell_commands.c shell.h shell.c main.c
	gcc -g -std=gnu99 shell_commands.c shell.c main.c -o shell 

run: shell 
	shell

clean:
	rm shell 

check:
	valgrind --leak-check=full shell
