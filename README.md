# Minishell

A small [command-line interpreter](https://en.wikipedia.org/wiki/Unix_shell) coded in C

*This is a school project*

#### Description
During this project, the goal was to recode a Unix shell with some restrictions on the functions we could use, here is the list of most of the alowed ones:
- malloc, free, opendir, readdir, closedir, getcwd, chdir
- fork, stat, lstat, open, close, getline
- read, write, execve, access, wait, waitpid
- signal, kill, getpid, strerror, perror, strsignal

#### How to test it

First, compile all the source files usig `make`

Now, execute the binary:
`./mysh`

The shell is now running, try it out!