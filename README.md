# Pipex

Pipex is a program that mimics the behavior of the shell pipe (`|`) operator. It allows you to execute a series of commands with input and output redirection.

## Features

- Execute multiple commands in sequence.
- Handle input and output redirection.
- Support for both mandatory and bonus parts of the project.

## Setup

1. **Clone the repository:**
   ```bash
   git clone https://github.com/jguigli/pipex.git
   cd pipex
   ```

2. **Compile the program:**
   - For the mandatory part:
     ```bash
     make
     ```
   - For the bonus part:
     ```bash
     make bonus
     ```

3. **Clean up object files:**
   ```bash
   make clean
   ```

4. **Remove all compiled files:**
   ```bash
   make fclean
   ```

5. **Recompile the program:**
   ```bash
   make re
   ```

## Usage

- **Mandatory Part:**
  ```bash
  ./pipex infile cmd1 cmd2 outfile
  ```
  - `infile`: The input file.
  - `cmd1`, `cmd2`: Commands to be executed.
  - `outfile`: The output file.

- **Bonus Part:**
  ```bash
  ./pipex_bonus infile cmd1 cmd2 ... cmdn outfile
  ```
  - `infile`: The input file.
  - `cmd1`, `cmd2`, ..., `cmdn`: Commands to be executed in sequence.
  - `outfile`: The output file.

## Error Handling

- The program provides detailed error messages for issues such as file access, command execution, and argument errors.
