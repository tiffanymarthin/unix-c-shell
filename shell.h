#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAXARGS 5
#define MAXLINE 80
// Change this to desired shell name
#define SHELL_NAME "tmarthin"

// Declare functions for builtin shell commands:
// Use int types to simplify debugging and while loop
int shell_cd(char **input);
int shell_help(char **input);
int shell_exit(char **input);
int shell_treedir(char **input);
int shell_launch(char **argv);
int shell_command_count();
void welcomeMessage();
pid_t Fork(void);
char *Fgets(char *ptr, int n, FILE *stream);
int shell_launch(char **argv);
int builtin_command(char **argv);
void split_buf(char *cmdline, char **argv);
int eval(char *cmdline);

#endif
