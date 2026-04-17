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
```