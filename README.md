# Unix Shell in C
A simplified version of a shell, implemented using C. This program will infinitely take user's inputs (commands) and give corresponding feedback if the commands are in the implemented built-in commands or in Unix `/bin/` commands. Note that it will fork a child process when it executes the Unix `/bin/` commands that are not in the built-in commands list.

## Dependencies
* Tested on Ubuntu - version 20.04.1 LTS
* gcc -std=gnu99 flag is needed to compile (included in Makefile)

## Implemented Built-In Commands
Description
* `cd`: Change directory to specified path/folder. When there is no path/folder specified, it will go to HOME directory
* `help`: Display the help page that describes each command
* `exit`: Exit the shell
* `treedir`: Show a tree directory of the current working directory

Important Note
* `treedir`: This program is from my other project (https://github.com/tiffanymarthin/directory-tree). In order for this command to work, copy the executable file 'treedir' to your `\bin\` folder so that it can be called from any folder.

## How to Use
* Make sure C compiler (gcc) is installed
* Git clone the repo
* Copy 'treedir' executable file from the repo to your `/bin/` folder (need admin access)
`sudo cp treedir /usr/local/bin`
* In "shell.h", change the shell-name to your preferred shell name on line 15:
    * `#define SHELL_NAME "tmarthin"`
* Type `make run` (see Makefile for more details)
* Once inside the personalized shell:
```
help
cd
cd [path/folder]
treedir
ls
pwd
...
exit
```
* Run `make clean` to remove the "shell" executable file

## Sample Output

