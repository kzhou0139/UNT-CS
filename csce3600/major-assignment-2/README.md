# CSCE 3600 Major Assignment 2
#### Spring 2023, Section 2, Group 10

## Group Members
* Dhruv Chanana
* Alicia Lin
* Kelly Zhou
* Mark White

## Project Organization
Each team member chose which built-in command and which secondary responsibility they wanted to complete. Below is which individual tasks each member completed:
* Dhruv Chanana: myhistory command, alias command
* Alicia Lin: path command, pipelining
* Kelly Zhou: cd command, redirection
* Mark White: exit command, signal handling

The main structure of the shell was programmed by Dhruv Chanana, and everyone assisted in defensive programming.

## Shell Usage
```bash
newshell [batchfile]
```

Arguments
* batchfile: optional argument used to input name of batch file that shell runs

## Building the Shell
```bash
make
```

## Design Overview

### Project Structure
```
major-assignment-2
├── include
│   ├── builtins
│   │   ├── alias.h
│   │   ├── cd.h
│   │   ├── exit.h
│   │   ├── myhistory.h
│   │   └── path.h
│   ├── executor.h
│   ├── parser.h
│   └── shell.h
├── makefile
├── README.md
└── src
    ├── builtins
    │   ├── alias.c
    │   ├── cd.c
    │   ├── exit.c
    │   ├── myhistory.c
    │   └── path.c
    ├── executor.c
    ├── parser.c
    └── shell.c
```

The overall structure of this shell includes 3 parts:

* Parser: Constructs an abstract syntax tree which represents a line in the shell
* Executor: Recurses through the abstract syntax tree and executes all nodes
* Shell: Handles input and batch files

Each of these parts has its own header and source file stored in the include and src folders respectively. Functions for builtins are defined in the builtins directories.

#### Parser

The parser is responsible for constructing an abstract syntax tree, or AST, which is a representation of a line in the shell that includes shell commands and special operators including pipes, redirection, and semicolons.

In order to represent this AST, a struct that defines one AST node is in include/parser.h. Each node includes 2 references to a left and a right child node, which together can represent a full AST. Since C does not have inheritance, each of these nodes also has an enum type, which is used in the execute command to decide which executor is used for the expression.

The buildTree function takes a string representing a line in the shell as a parameter and returns an AST representation.  

The execute function takes an expression as input and uses the expression type to decide which executor to use.

#### Executor

The executor is actually multiple functions that can handle all different types of expressions. There are 6 functions, each of which execute a different expression and their child nodes. Every executor except for the command executor (because all commands should be leaf nodes) will also execute children, so executors will essentially perform a post-order traversal on the AST

#### Shell

The shell is what actually handles input and is the entry point of the program. The shell handles running batch mode commands and the interactive mode of the shell.

If in batch mode, the shell opens the batch file and iterates through each line, building a tree and executing it until it encounters an EOF or exit command.

If in interactive mode, the shell will prompt the user to enter a command with username and current working directory. Until the user runs the exit builtin or presses Ctrl-D, the shell will continue running

### Built-in Commands

##### cd Command

The cd command is used to change directories.
```bash
cd
```
with no arguments passed, calling the cd command will change the path from the working directory to the user's HOME directory.
```bash
cd <path>
```
with an argument passed, the cd command will change the path from the working directory to the directory specified by the user.

##### exit Command

The exit command is used to exit the shell itself.
```bash
exit
```
Here are valid examples for quitting the shell
```bash
prompt> exit
```
```bash
prompt> cat yourFile; exit
```

##### path Command

The path command is used to print or modify the shell's current path, an environmental variable.
```bash
path
```
with no arguments will print the current path, while
```bash
path + <pathname>
```
will add pathname to the end of the current path, and
```bash
path - <pathname>
```
will remove pathname from the end of the current path.

##### myhistory Command
The myhistory builtin is a utility to track shell history and run past commands. With no input, myhistory will display the 20 saved commands. With the -e flag, the user can enter a number from this list to execute. With -c, the full history can be cleared

### Additional Functionalities

##### I/O Redirection
```bash
$ cmd1 < in.txt
```
will redirect the input for cmd1 to be from in.txt instead of the keyboard.

```bash
$ cmd2 > out.txt
```
will redirect the ouput of cmd2 into out.txt instead of the terminal.

##### Pipelining

The use of a vertical bar | between commands will connect these commands' input and output in a pipeline. In other words,
```bash
$ cmd1 | cmd2 | cmd3
```
will connect the output of cmd1 to the input of cmd2, and the output of cmd2 to the input of cmd3, with the final output being that of cmd3.

##### Signal Handling and Terminal Control

While commands are running, the Ctrl-C shortcut can be used to send the signal SIGINT to them, which stops execution. In interactive mode, Ctrl-C will have no effect

##### alias Command

The alias command can be used in order to create aliases that can be used as 'shortcuts' for other commands. Using the builtin with no input will display all defined aliases as a comma separated list, and the builtin can also be used to define an alias. For example, to define an alias called 'ls' that runs the command 'ls -al --color' the builtin can be used with the following arguments.
```bash
$ alias ls='ls -al --color'
```
This exact format must be used to define aliases, with the alias name, an equal sign, and then the definition within single quotes

## Complete Specification
* The path command *with* arguments will print out the new modified path, just as the path command *without* arguments does, even though this functionality is not specified.
* The prompt will include the current working directory as well as the user.
* While the shell is in interactive mode, interrupt signals caused by Ctrl-C or Ctrl-Z will be ignored. However, the user can exit with Ctrl-D or the exit builtin.
* The maximum command length is 512. This applies to commands entered through batch files, directly in the prompt, or aliases.
* History only includes commands run in the current session, and alias do not save across sessions
* myhistory will also be recorded within the history when run
* Batch files will continue executing after encountering errors

## Known Bugs or Problems
* Executing the path command (without arguments) will occasionally produce a segmentation fault.
* If exit is included before a semicolon, it will exit before the other command is run
* If redirection operators are used, other operators may not function properly in the same command
