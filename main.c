#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "shell_commands.h"

void pink()
{
    printf("\033[1;95m");
}

void purple()
{
    printf("\033[1;34m");
}

void reset()
{
    printf("\033[0m");
}

int main()
{
    char cmdline[MAXLINE];
    int status = 1;
    char cwd[1024]; // current working directory

    welcomeMessage();
    do
    {
        // Prints shell prompt
        getcwd(cwd, sizeof(cwd));
        pink();
        printf("%s-shell:", SHELL_NAME);
        purple();
        printf("~%s", cwd);
        reset();
        printf("> ");

        Fgets(cmdline, MAXLINE, stdin);
        if (feof(stdin))
        {
            exit(0);
        }
        status = eval(cmdline);
    } while (status);
}
