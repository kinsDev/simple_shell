# Hey guys, welcome to the kkshell (kaimenyi & kinyanjui).
- Below are some guides that ALX shared with us on what to know to create our shell.

# Everything you need to know to start coding your own shell

## PID & PPID
- A process is an instance of an executing program, that has a unique process ID. This process ID is used by many functions and system calls to interact with and manipulate processes. In order to retrieve the current process’ ID, you can use the system call getpid (man 2 getpid)

## Arguments
- The command line arguments are passed through the main function: int main(int ac, char **av);

  - av is a NULL terminated array of strings
  - ac is the number of items in av
- av[0] usually contains the name used to invoke the current program. av[1] is the first argument of the program, av[2] the second, and so on.

## Executing a program
- The system call execve allows a process to execute another program (man 2 execve). Note that this system call does load the new program into the current process’ memory in place of the “previous” program: on success execve does not return to continue the rest of the “previous” program.

## Creating processes
- The system call fork (man 2 fork) creates a new child process, almost identical to the parent (the process that calls fork). Once fork successfully returns, two processes continue to run the same program, but with different stacks, datas and heaps.

## Wait
- The wait system call (man 2 wait) suspends execution of the calling process until one of its children terminates.

## File information
- The stat (man 2 stat) system call gets the status of a file. On success, zero is returned. On error, -1 is returned.

## Environment
- We have seen earlier that the shell uses an environment list, where environment variables are “stored”. The list is an array of strings, with the following format: var=value, where var is the name of the variable and value its value. As a reminder, you can list the environment with the command printenv.
