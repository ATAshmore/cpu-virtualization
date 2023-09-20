cpu-virtualization

This repository contains two C programs, `problem1.c` and `problem2.c`, developed as part of the COP4600 Operating Systems course assignment.

## Problem 1

### Requirements
- Takes a command-line input, which can be a sequence of characters without separators (e.g., "date" or "ls") or a sequence with separators (e.g., "ls -l").
- Creates a new process using `fork()`.
- Executes the input command (`cmd`) in the new process with parameters (`params`), if provided.
- Waits for the new process to finish executing and prints "++++" on a new line.

### Usage
To compile and run `problem1.c`, use the following commands:

```shell
gcc problem1.c -o problem1
./problem1 <command> [parameters]
```

Replace `<command>` with the desired command (e.g., "ls") and `[parameters]` with any additional parameters (e.g., "-l").

## Problem 2

### Requirements
- Expects an input of the form: `cmd1 | cmd2`.
- Creates two processes (`child1` and `child2`).
- Executes `cmd1` in `child1` and `cmd2` in `child2`.
- Connects the output of `cmd1` to the input of `cmd2` using a pipe.
- Waits for both processes to finish executing and prints "++++" on a new line.

### Usage
To compile and run `problem2.c`, use the following commands:

```shell
gcc problem2.c -o problem2
./problem2 <cmd1> | <cmd2>
```

Replace `<cmd1>` and `<cmd2>` with the desired commands (e.g., "ls" and "wc").
r` file on Canvas or the specified platform.

