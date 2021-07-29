#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "shell.h"
#include "shell_commands.h"

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

/**
 * Show the help page of implemented shell commands
 * @param input: string array of the command line input
 * @return 1 if it is successful
 */
int shell_help(char **input)
{
    printf("\n=========================================================\n\n");
    printf("Welcome to the %s-shell help page!\n\n", SHELL_NAME);
    printf("Here are the current available built-in commands:\n");
    printf("cd [path] : Change directory to the specified path\n");
    printf("help : Help page for built in descriptions\n");
    printf("treedir : List all the folders and files in your current directory in a tree format\n");
    printf("exit : Exit the %s-shell\n\n", SHELL_NAME);

    printf("Note: Other Unix /bin/ commands will still be available (e.g. ls, pwd, cat, etc.)\n");
    printf("\n=========================================================\n\n");

    return 1;
}

/**
 * Exits the shell
 */
int shell_exit(char **input)
{
    printf("Thank you for trying it out!\n\n");
    return 0;
}

/**
 * Show the tree directory of the current directory
 * Program needs to be copied from another repo (directory-tree)
 */
int shell_treedir(char **input)
{
    system("treedir");
    return 1;
}
