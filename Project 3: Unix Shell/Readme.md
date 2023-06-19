# Wish Shell
The source this is based on [is here](https://github.com/remzi-arpacidusseau/ostep-projects/tree/master/processes-shell)

The Wish Shell is a simple command line interpreter developed in C. It supports executing arbitrary commands with up to 10 arguments, changing the current working directory, and modifying the execution path.

## Features
- Interactive shell prompt
- Execution of external commands found in the PATH
- cd command to change current working directory
- path command to modify the execution path
- Ability to handle up to 10 arguments per command
- exit command to terminate the shell

## Usage
To start the shell, use ``./myshell`` from your terminal after compiling it.

In the shell, you can type any command found in your PATH. For example:

``wish> ls`` 

You can use other commands, like ``cd``, ``path`` and ``exit``.
![](https://github.com/Hpro1/KayttisSysteemiHT/blob/main/Project%203%3A%20Unix%20Shell/images/1.png)

## Compilation
Compile the shell with ``gcc -o myshell myshell.c``
