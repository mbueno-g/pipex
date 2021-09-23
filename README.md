# pipex

:books: [Introduction](#introduction)
 
:world_map: [Concept map](#how-it-works)
 
:footprints: [Step by step](#step-by-step)

## :books: Introduction
The Pipex proyect aims to program the following shell command:
``
< infile cmd1 | cmd2 > outfile
``
where infile and outfile are file names and cmd1 and cmd2 are shell commands with their parameters.

Some new functions used in this proyect are:
| Function       | Description | Return |
| :------------: | :---------: | :-----:|
| ``int access(const char *pathname, int mode)`` | Checks whether the calling process can access the file pathname | Succes: 0 ; Failure: -1 |
| ``int unlink(const char *pathname)`` | Deletes a name from the filesystem | Success: 0 ; Failure: -1 |
| ``pid_t waitpid(pid_t pid, int *status, int options)`` | Wait for a child process to stop |
| ``pid_t wait(int *status)`` |  |
| ``int pipe(int pipefd[2])`` | Creates a pipe, a unidirectional data channel that can be used for interprocess communication | Success: 0 ; Failure : -1 |
| ``int dup(int oldfd)`` | Allocates a new file descriptor that refers to the same open file description as the descriptor oldfd | Success: newfd ; Failure: -1 |
| ``int dup2(int oldfd, int newfd)`` | Performs the same task as dup(), but instead of using the lowest-numbered unused file descriptor, it uses the file descriptor number specified in newfd | Success: newfd ; Failure; -1 |
| ``int execve(const char *pathname, char *constargv[],char *constenvp[])`` |  |
| ``pid_t fork(void)`` | Creates a child process by duplicating the calling process, the parent process | Succes: child's pid (parent process), 0 (child process); Failure: -1 (parent process), errno (child process) 
| ``perror`` |  |
| ``strerror`` |  |


