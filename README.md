# Pipex

*This project has been created as part of the 42 curriculum by nmeunier.*

## Description

Pipex is a C implementation of the Unix pipe mechanism, recreating the behavior of the shell command:
```bash
< file1 cmd1 | cmd2 > file2
```

The project aims to:
- Understand how Unix pipes work at the system level
- Master process creation and management using `fork()`
- Learn inter-process communication (IPC) through pipes
- Implement command execution using `execve()`
- Handle file descriptors and redirections properly
- Practice memory management and error handling in C

The pipex program takes four mandatory arguments:
- `file1`: input file to read from
- `cmd1`: first command to execute
- `cmd2`: second command to execute
- `file2`: output file to write to

The program creates two child processes connected by a pipe, allowing the output of `cmd1` to become the input of `cmd2`, with the final result written to `file2`.

## Instructions

### Compilation

To compile the project, run:
```bash
make
```

This will generate the `pipex` executable.

To clean up object files:
```bash
make clean
```

To remove all compiled files including the executable:
```bash
make fclean
```

To rebuild the project from scratch:
```bash
make re
```

### Execution

Run the pipex program with four arguments:
```bash
./pipex <file1> <cmd1> <cmd2> <file2>
```

#### Example Usage

Create a test file:
```bash
echo "Hello World" > input.txt
```

Run pipex to pipe the output of `cat` through `wc -w`:
```bash
./pipex input.txt "cat" "wc -w" output.txt
```

The result (2) will be written to `output.txt`.

Another example with `grep` and `wc`:
```bash
./pipex input.txt "grep Hello" "wc -c" output.txt
```