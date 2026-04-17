<<<<<<< HEAD
This project has been created as part of the 42 curriculum by nmeunier.

## About

`pipex` is a C program that reproduces the behavior of a shell pipeline between two commands. It takes two files and two commands as arguments, and chains them as if you had typed in a shell:

```bash
< infile cmd1 | cmd2 > outfile
```

The goal of the project is to deepen the understanding of UNIX processes, file descriptors, pipes, and the `execve` family of system calls.

## Usage

```bash
./pipex infile "cmd1" "cmd2" outfile
```

- `infile` — input file (read by `cmd1`)
- `cmd1` — first command, with its arguments, as a single string
- `cmd2` — second command, with its arguments, as a single string
- `outfile` — output file (written by `cmd2`)

### Example

```bash
./pipex infile "grep hello" "wc -l" outfile
```

This is equivalent to:

```bash
< infile grep hello | wc -l > outfile
```

## Build

```bash
make        # builds the pipex binary
make clean  # removes object files
make fclean # removes object files and the binary
make re     # fclean + build
```

Compiled with `cc -Wall -Wextra -Werror`.

## Testing

A few useful tests to confirm behavior matches the shell:

```bash
# Basic
./pipex infile "cat" "wc -l" out
< infile cat | wc -l > out_bash
diff out out_bash

# Absolute paths
./pipex infile "/bin/grep hello" "/usr/bin/wc -l" out

# Empty environment (no PATH — requires absolute paths)
env -i ./pipex infile "/bin/cat" "/usr/bin/wc -l" out

# Memory leaks
valgrind --leak-check=full --trace-children=yes --track-fds=yes \
    ./pipex infile "ls -la" "wc -l" out
=======
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
>>>>>>> 363c4289cbc34f965fdfc4e5e213a1ed6958f53e
```