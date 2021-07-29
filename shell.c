#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

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

/**
 * Show the help page of implemented shell commands
 * @param input: string array of the command line input
 * @return 1 if it is successful
 */
int shell_help(char **input)
{
    printf("\n=========================================================\n");
    printf("Welcome to the c-shell help page!\n\n");
    printf("Here are the current available built in commands:\n");
    printf("cd [path] : Change directory to the specified path\n");
    printf("help : Help page for built in descriptions\n");
    printf("treedir : List all the folders and files in your current directory in a tree format\n");
    printf("exit : Exit the c-shell\n\n");

    printf("Fyi, other unix builtin commands will still be available (e.g. ls, pwd, cat, etc.)\n\n");

    return 1;
}

/**
 * Exits the shell
 */
int shell_exit(char **input)
{
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

/***
 **  Wrapper of fork(). Checks for fork errors, quits on error. 
 **/
pid_t Fork(void)
{
    pid_t pid;
    if ((pid = fork()) < 0)
    {
        fprintf(stderr, "%s: %s\n", "fork error", strerror(errno));
        exit(0);
    }
    return pid;
}

/***
 ** Wrapper of fgets. Checks and quits on Unix error. 
 ** Read n characters from FILE into pointer
 **/
char *Fgets(char *ptr, int n, FILE *stream)
{
    char *rptr;
    if (((rptr = fgets(ptr, n, stream)) == NULL) && ferror(stream))
    {
        fprintf(stderr, "%s\n", "fgets error");
        exit(0);
    }
    return rptr;
}

/**
 * Launches a child process to handle commands that are not in built-in commands
 * Used execvp to run Unix commands that are inside /bin/
 */
int shell_launch(char **argv)
{
    pid_t pid, wpid;
    int status;

    pid = Fork();
    if (pid == 0)
    {
        // Child process
        if (execvp(argv[0], argv) == -1)
        {
            fprintf(stderr, "Command '%s' is not found\n", argv[0]);
        }
        exit(EXIT_FAILURE);
    }
    else
    {
        // Parent process
        do
        {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

/**
 * Checks if the input command is in the built-in commands list
 * @param argv: input command from user
 * @return -1 if command is not in the built-in commands list
 */
int builtin_command(char **argv)
{
    int n = shell_command_count();
    for (int i = 0; i < n; i++)
    {
        int res = strcmp(command[i], argv[0]);
        if (res == 0)
        {
            return (*command_functions[i])(argv);
        }
    }
    return -1;
}