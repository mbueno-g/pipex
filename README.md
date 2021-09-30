# pipex

:books: [Introduction](#introduction)
 
:world_map: [Concept map](#how-it-works)
 
:footprints: [Step by step](#step-by-step)

## :books: Introduction
The Pipex proyect aims to program the following shell command:
``
< infile cmd1 | cmd2 | cmd3 ... | cmdn > outfile
``
where 
- infile and outfile are file names 
- cmd1,cmd2,... cmdn are shell commands with their parameters
- < redirection the standard input (fd = 0)
- \> redirection the standar output (fd = 1)

Some new functions used in this proyect are:
| Function       | Description | Return |
| :------------: | :---------: | :-----:|
| ``int access(const char *pathname, int mode)`` | Checks whether the calling process can access the file pathname | Succes: 0 ; Failure: -1 |
| ``pid_t waitpid(pid_t pid, int *status, int options)`` | Wait for a child process to stop | Success: child's PID ; Failure: -1
| ``int pipe(int pipefd[2])`` | Creates a pipe, a unidirectional data channel that can be used for interprocess communication | Success: 0 ; Failure : -1 |
| ``int dup(int oldfd)`` | Allocates a new file descriptor that refers to the same open file description as the descriptor oldfd | Success: newfd ; Failure: -1 |
| ``int dup2(int oldfd, int newfd)`` | Performs the same task as dup(), but instead of using the lowest-numbered unused file descriptor, it uses the file descriptor number specified in newfd | Success: newfd ; Failure; -1 |
| ``int execve(const char *pathname, char *constargv[],char *constenvp[])`` | Executes the program referred to by pathname (binary executable) | Success: nothing ; Failure : -1 |
| ``pid_t fork(void)`` | Creates a child process by duplicating the calling process, the parent process | Succes: child's pid (parent process), 0 (child process); Failure: -1 (parent process), errno (child process) |


## :world_map: Concept map
Here's a concept map to clarify how to communicate n processes using dup2, pipe and fork:
![Customer Journey Map (Timeline)](https://user-images.githubusercontent.com/71781441/135533181-be8aecc4-f330-4276-858e-be3e08fa3d6e.jpg)


