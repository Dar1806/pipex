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

### Execution

Run the pipex program with four arguments:

```bash
./pipex <file1> <cmd1> <cmd2> <file2>
```

#### Example usage

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

## How it works

1. Validate arguments and the environment.
2. Create a pipe with `pipe()`.
3. Fork a first child that redirects `stdin` to `file1`, `stdout` to the pipe's write end, and runs `cmd1` via `execve`.
4. Fork a second child that redirects `stdin` to the pipe's read end, `stdout` to `file2`, and runs `cmd2`.
5. The parent closes both pipe ends and waits for both children with `waitpid`, returning the exit status of the last command.

Command resolution handles three cases:

- Paths containing `/` (absolute or relative) are checked directly with `access`.
- Plain command names are searched through the `PATH` environment variable.
- If `PATH` is not set or the command is not found, `pipex` prints an error on `stderr` and exits with status 127.

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
```