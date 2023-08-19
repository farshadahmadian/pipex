# pipex
The overall purpose of this project is to simulate the pipe operator ```|``` in C. When we use the pipe operator in the command line, we want to run a command and use its output as the input of the second command that is going to be executed. In order to do such a thing in C, we need to use the ```pipe()``` and ```fork()``` functions.

## Why fork()?
To run a command such as ```cat``` in a C program, we need to use one of the ```exec``` family functions. When these functions are executed, if the first argument (the command file which is ```/bin/cat``` here) is valid, the command process will replace the process in which it was called, and we will not have access to that (main) process anymore. So, after the command process is done (the ```cat``` command has been executed) the program will exit and the remaining code will not be executed. So, we need a child process to run the ```exec``` function in that so that after the child process is replaced by the command process, we can have access to the main process and continue executing the remaining of the program. The ```fork()``` function creates such a child process.

## Why pipe()?
Processes are separate programs that own a copy of the whole variables, and they execute the code separately. So, if we want to use the output of a program as the input of another one, which is the purpose of the pipe operator, we need to make a connection between processes. This is what the ```pipe()``` function does.

## Overall workflow
1. Create a pipe and two child processes.
2. One of the child processes (it will be called the first child process) will be responsible to read an input from a file, do something on the input, and then write the output to the writing end of the pipe (```fd[1]```).
3. The other child process (it will be called the second child process) is responsible to receive the output of the other process as its own input from the reading end of the pipe (```fd[0]```), do some task, and then write the output in a file.
4. The main process is responsible to create the pipe which is a link between the processes, create the child processes, close its own file descriptors, wait for the child processes termination, and receive the status code of the child (command) processes.

Do not confuse one thing. The first child process is responsible for writing to the pipe. Reading the input from a file is not related to the pipe. Similarly, the second child process is responsible to read from the pipe, and writing the result to a file is irrelevant to the pipe.

## Some points
1. Each process (main or child process) has its own reading and writing file descriptors of the pipe, which are respectively ```fd[0]``` and ```fd[1]```, and each process is responsible for closing its own file descriptors because a file descriptor remained open might cause the program to never terminate.
2. In the main process, first the file descriptors must be closed, and then the main process must wait for the children processes termination. Assume that ```fd[1]``` of the pipe inside the main process is not closed, and the main process is waiting for the termination of the child processes. It might cause the child process which is responsible for reading from the pipe to wait for more input forever.
3. ```exec``` family functions read the input from stdin, which by default is the keyboard, and write the output to stdout, which by default is the terminal console.
4. In the first child process, stdin must refer to the input file instead of the keyboard (because the command is going to get the input from an input file rather than the keyboard) and stdout must refer to ```fd[1]``` of the pipe instead of the terminal console (because the command is going to print the output to ```fd[1]``` rather than terminal console).
5. In the second child process, stdin must refer to ```fd[0]``` of the pipe instead of the keyboard (because the command is going to get the input from the pipe rather than the keyboard) and stdout must refer to the output file instead of the terminal console (because the command is going to print the output to the output file rather than the terminal console).

For more details, you can read the flowcharts below.

## Flowchart

### Main
<img src="https://github.com/farshadahmadian/pipex/assets/117720346/191b6bd8-3f16-4f4e-a2c8-d08a3c5fc3a5" alt="Main flowchart"/>

### Finding command file
<img src="https://github.com/farshadahmadian/pipex/assets/117720346/81323259-a0a0-4dbb-a941-ff0c5dc1f3d4" alt="Finding command file flowchart"/>
