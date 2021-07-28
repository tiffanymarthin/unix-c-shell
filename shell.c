#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#define MAXARGS 5
#define MAXLINE 80

// Declare functions for builtin shell commands:
// Use int types to simplify debugging and while loop
int shell_cd(char **input);
int shell_help(char **input);
int shell_exit(char **input);
int shell_treedir(char **input);

int shell_launch(char **argv);

// Command names
char *command[] = {"cd", "help", "exit", "treedir"};

// Command function pointers
int (*command_functions[])(char **) = {&shell_cd, &shell_help, &shell_exit, &shell_treedir};

// Count the number of builtin commands
int shell_command_count()
{
    return sizeof(command) / sizeof(*command);
}

/**
 * Welcome message of the ksea shell
 */
void welcomeMessage()
{
    printf("\n=========================================================\n");
    printf("\tSimple C Shell Implementation\n");
    printf("\tAvailable commands: cd, help, exit, treedir\n");
    printf("\tType 'help' to see command descriptions\n");
    printf("=========================================================\n");
    printf("\n\n");
}