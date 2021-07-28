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

/**
 * Implementing the builtin commands
 */

/**
 * Change directory command
 * If no path specified, it will go to home directory
 * @param input: string array of the command line input
 * @return 1 if it is successful, -1 otherwise
 */
int shell_cd(char **input)
{
    if (input[1] == NULL)
    {
        chdir(getenv("HOME"));
        return 1;
    }
    else
    {
        if (chdir(input[1]) == -1)
        {
            printf(" %s: Directory is not found\n", input[1]);
            return -1;
        }
    }
    return 1;
}