# pipex

:books: [Introduction](#introduction)

:collision: [New concept](#new-concept)
 
:world_map: [Concept map](#concept-map)
 
:footprints: [Step by step](#step-by-step)

## Introduction
The aim of the Pipex proyect is to program the following shell command:
``
< infile cmd1 | cmd2 | cmd3 ... | cmdn > outfile
``
 (i.e. learn about inter-process communication) where 
- infile and outfile are file names 
- cmd1,cmd2,... cmdn are shell commands with their parameters
-  ``< filename `` [input redirection (fd = 0)] : the input will be read from the filename instead of STDIN_FILENO
-  ``filename > `` [output redirection (fd = 1)] : the output will be written in filename insead of STDOUT_FILENO
-   ``|`` takes output from one process, and sends it to another as input

Some helpful functions used in this proyect are:
| Function       | Description | Return |
| :------------: | :---------: | :-----:|
| ``int access(const char *pathname, int mode)`` | Checks whether the calling process can access the file pathname | Succes: 0 ; Failure: -1 |
| ``pid_t waitpid(pid_t pid, int *status, int options)`` | Wait for a child process to stop | Success: child's PID ; Failure: -1
| ``int pipe(int pipefd[2])`` | Creates a pipe, a unidirectional data channel that can be used for interprocess communication | Success: 0 ; Failure : -1 |
| ``int dup(int oldfd)`` | Allocates a new file descriptor that refers to the same open file description as the descriptor oldfd | Success: newfd ; Failure: -1 |
| ``int dup2(int oldfd, int newfd)`` | Performs the same task as dup(), but instead of using the lowest-numbered unused file descriptor, it uses the file descriptor number specified in newfd | Success: newfd ; Failure; -1 |
| ``int execve(const char *pathname, char *constargv[], char *constenvp[])`` | Executes the program referred to by pathname (binary executable) | Success: nothing ; Failure : -1 |
| ``pid_t fork(void)`` | Creates a child process by duplicating the calling process, the parent process | Succes: child's pid (parent process), 0 (child process); Failure: -1 (parent process), errno (child process) |

## New concept
*¿What is a process?* 
A process is a primitive unit for allocation of system resources that executes a program. There can be multiple processes executing the same program, but each process has its own copy of the program within its own address space and executes it independently of the other copies. We can tell which process is running by its process ID (PID), a value of type pid_t.

Besides, processes are organized hierarchically. Each process has a parent process that creates a new process called child process. A child inherits many of its attributes from the parent process.
These act of creating a new process is called *forking* due to the name of the function use to do it (``fork()``).


## Concept map
Here's a concept map to clarify how to communicate n processes using dup2, pipe and fork:
![Customer Journey Map (Timeline)](https://user-images.githubusercontent.com/71781441/135533181-be8aecc4-f330-4276-858e-be3e08fa3d6e.jpg)

## Step by step
### Step 1: Getting the arguments for execve
In order to execute a command we first need to get the pathname and the array of arguments and stored both of then as a node of a linked list.
- [x] Pathname referred to the command we want to execute
- [x] Command-line arguments

The pathname is stored in the last argument of the main function: the program's environment (*envp*). This variable keeps track of information that is shared by many programs and usually have environment variable names such as HOME, PATH, LOGNAME... The variable ``PATH`` holds a sequence of directory names (path) separated by colons used for searching for programs to be run. A typical value for this environment variable might be a string like:
```
PATH=/bin:/etc:/usr/bin:/usr/new/X11:/usr/new:/usr/local/bin
```
This means that if we try to execute a command name ``wc``, the system will look for file named ``/bin/wc``, ``/etc/wc`` and so on. The first of these file that exists (checked using  ``access`` with F_OK mode) is the one that is stored and eventually executed.

Check these things out to verify that your code works just fine:

:x: Use ``whereis`` (command used to locate the binary source and manual page files for a command) to confirm thar your pathname is actually correct

:x: Use ``unset PATH`` or/and ``import PATH=...`` with incorrect directory names to corroborate that your program stop when no correct path is found.

### Step 2: Opening infile and outfile
Infile must be open for reading only (O_RDONLY) so a command can be runned with its information.

Outfile must be open with the next flags
- [x] O_CREAT: the file is created, if applicable
- [X] O_WRONLY: open for writting only
- [X] O_TRUNC: if the file exists and is successfully opened, its length is truncated to 0.
- [x] 0666: file permissions (-rw-rw-rw-)

### Step 3: Execute several commands
In case, there're more than two commands we just have to repeat in a loop the idea for two commands as many times as the number of commands. So let's see the idea behind the basic case.
1. Allocate STDIN_FILENO to the fd that refers to the infile fd: ``dup2(fd_infile, STDIN_FILENO)``
2. Use ``pipe`` and ``fork`` (order matters) to create a child and a parent and given them a way to communicate
3. CHILD: redirects the writting end of the pipe (fd[WRITE_END]) to the STDOUT_FILENO and execute the first command
4. PARENT: waits until the child ends and redirects the reading end of the pipe (fd[READ_END]) to the STDIN_FILENO, except there's no left command to execute that the reading end is redirected to the outfile fd.
Caution should be taken with closing the file descriptors that are no longer used.

### Step 4: File descriptor leaks
Besides the memory leaks, this proyects introduce the concept of file descriptor leaks. They are the result of leaving an open file descriptor somewhere. 

:x: To check the out add an endless loop (``while(1);``) at the end of your program and write down ``lsof -c <name_executable>`` in a terminal. This command lists the open files that begin with the name of your executable. You can also use ``lsof -p <process_pid>`` to list them by the process Identificacion number.


