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

### Project Structure

- **src/**: Source files
  - `main.c`: Entry point and argument validation
  - `process.c`: Child and parent process implementation
  - `path.c`: Command path resolution logic
  
- **libft/**: Custom C library functions
  - `ft_split.c`: String splitting utility
  - `ft_strjoin.c`: String concatenation
  - `ft_substr.c`: Substring extraction
  - `ft_strlen.c`: String length calculation
  - `ft_strncmp.c`: String comparison
  - `ft_putstr_fd.c`: String output to file descriptor
  - `ft_memcpy.c`: Memory copying
  
- **includes/**: Header files
  - `pipex.h`: Main project declarations
  - `libft.h`: Library function declarations

## Resources

### Documentation
- [pipe(2) - Linux Manual Page](https://man7.org/linux/man-pages/man2/pipe.2.html)
- [fork(2) - Linux Manual Page](https://man7.org/linux/man-pages/man2/fork.2.html)
- [execve(2) - Linux Manual Page](https://man7.org/linux/man-pages/man2/execve.2.html)
- [dup2(2) - Linux Manual Page](https://man7.org/linux/man-pages/man2/dup2.2.html)
- [waitpid(2) - Linux Manual Page](https://man7.org/linux/man-pages/man2/waitpid.2.html)

### Tutorials & References
- [Unix Pipes Explained](https://www.gnu.org/software/bash/manual/html_node/Pipelines.html)
- [Advanced Programming in the Unix Environment](https://www.oreilly.com/library/view/advanced-programming-in/0321637734/)
- [File Descriptors and Redirection](https://tldp.org/LDP/abs/html/io-redirection.html)

### AI Usage

AI was used to assist with the following aspects of this project:
- **Code structure and organization**: General guidance on how to organize the source files and implement the main logic flow
- **Error handling**: Help identifying common edge cases and implementing robust error checking
- **Memory management**: Suggestions on proper allocation and deallocation patterns
- **Process communication**: Clarification on pipe mechanics and file descriptor handling
- **Documentation**: Assistance in writing comprehensive comments and creating this README file

The core implementation logic, problem-solving approach, and debugging were completed independently to ensure deep understanding of Unix system programming concepts.
