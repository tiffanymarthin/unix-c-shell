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

int shell_launch(char **argv);
int shell_command_count();
void welcomeMessage();
pid_t Fork(void);
char *Fgets(char *ptr, int n, FILE *stream);
int builtin_command(char **argv);
void split_buf(char *cmdline, char **argv);
int eval(char *cmdline);

#endif
