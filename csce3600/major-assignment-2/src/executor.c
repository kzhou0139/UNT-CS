// Group 10: Dhruv Chanana, Alicia Lin, Kelly Zhou, Mark White
// CSCE 3600.002, Spring 2023
// Major Assignment 2

#include "executor.h"
#include "builtins/alias.h"
#include "builtins/cd.h"
#include "builtins/exit.h"
#include "builtins/myhistory.h"
#include "builtins/path.h"

#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void executeCommand(struct Expr *expression) {
  // Execute command using expression args (full string of command)
  int n = 1, maxArgs = 5;
  char *line = strdup(expression->args),
       **args = malloc(sizeof(char *) * maxArgs);

  // Iterate through all args in command string with strtok
  args[0] = strtok_r(line, " \t", &line);
  while ((args[n] = strtok_r(NULL, " \t", &line))) {
    // Check if this argument contains single quotes, add to arg up until end of
    // single quotes if included
    char *tmp;
    if ((tmp = strchr(args[n], '\''))) {   // if arg contains '
      if (strchr(tmp + 1, '\'') == NULL) { // if arg does not contain a second
        // append until second quote to string
        sprintf(args[n] + strlen(args[n]), " %s'", strtok_r(NULL, "'", &line));
      }
    }

    // Check if this argument contains double quotes, add to arg up until end of
    // single quotes if included
    // Same logic as above
    if ((tmp = strchr(args[n], '"'))) {
      if (strchr(tmp + 1, '"') == NULL) {
        sprintf(args[n] + strlen(args[n]), " %s\"",
                strtok_r(NULL, "\"", &line));
      }
    }

    if (++n >= maxArgs) {
      args = realloc(args, sizeof(char *) * (maxArgs += 5)); // resize array if
                                                             // args exceed size
    }
  }

  char *aliasName = strdup(args[0]), *alias, command[512];
  strcat(aliasName, "=");
  // check if alias defined
  if (!expression->alias && (alias = strstr(aliases, aliasName))) {
    // get alias definition
    sscanf(alias, "%[^=]='%512[^']',", aliasName, command);

    // add all extra args to definition
    for (int i = 1; i < n; i++) {
      sprintf(command + strlen(command), " %s", args[i]);
    }

    // create new command for alias and execute
    struct Expr *newExpression = malloc(sizeof(struct Expr));
    newExpression->args = command;
    newExpression->alias = true;
    executeCommand(newExpression);
  } else if (strcmp(args[0], "alias") == 0) {
    // if command is alias, run alias
    alias_cmd(args);
  } else if (strcmp(args[0], "cd") == 0) {
    // if command is cd, run cd
    cd_cmd(args);
  } else if (strcmp(args[0], "exit") == 0) {
    // if command is exit, run exit
    exit_cmd(args);
  } else if (strcmp(args[0], "myhistory") == 0) {
    // if command is myhistory, run path
    myhistory_cmd(args);
  } else if (strcmp(args[0], "path") == 0) {
    // if command is path, run path
    path_cmd(args);
  } else {
    // if command is not alias or builtin, run from path
    // fork
    pid_t pid = fork();
    if (pid > 0) { // Parent
      // Capture SIGTTOU for signal capturing purposes
      signal(SIGTTOU, SIG_IGN);

      // Create process group if stdin and stdout are tty
      if (isatty(0) && isatty(1) && setpgid(pid, pid) == -1) {
        fprintf(stderr, "Error: Failed to create process group\n");
      }

      // Set pgrp of child as foreground if stdin and stdout are tty
      if (isatty(0) && isatty(1) && tcsetpgrp(0, pid) == -1) {
        fprintf(stderr, "Error: Failed to set process group as foreground\n");
      }

      // Wait for command to finish
      int status;
      waitpid(pid, &status, 0);

      // Change pgrp back to default
      if (isatty(0) && isatty(1) && tcsetpgrp(0, getpid()) == -1) {
        fprintf(stderr,
                "Error: Failed to restore original foreground process group\n");
      }
    } else if (pid == 0) {     // Child process
      signal(SIGINT, SIG_DFL); // stop ignoring interrupts
      signal(SIGTSTP, SIG_DFL);
      execvp(args[0], args); // Execute command
      if (errno == ENOENT) {
        fprintf(stderr, "Error: %s: command or file not found\n", args[0]);
      } else {
        perror("Error");
      }
      exit(0); // exit child once done
    } else {
      perror("fork error\n");
    }
  }
  free(expression);
}

// Alicia Lin
void executePipeline(struct Expr *expression) {
  // file descriptors for ends of pipe
  int fd[2];
  // create pipe
  pipe(fd);

  // fork pipe
  pid_t pid1 = fork();
  // in child
  if (pid1 == 0) {
    // copy pipe's write end to output
    dup2(fd[1], 1);
    // close pipe
    close(fd[0]);
    close(fd[1]);

    // execute first command
    execute(expression->left);
    // exit
    exit(0);
  }

  // in parent
  else {
    // fork again
    pid_t pid2 = fork();

    // in new child
    if (pid2 == 0) {
      // copy pipe's read end to input
      dup2(fd[0], 0);
      // close pipe
      close(fd[0]);
      close(fd[1]);

      // execute second command
      execute(expression->right);
      // exit
      exit(0);
    }

    // in parent
    else {
      // close pipe
      close(fd[0]);
      close(fd[1]);

      // wait
      int status;
      waitpid(pid1, &status, 0);
      waitpid(pid2, &status, 0);
    }
  }
  free(expression);
}

// Dhruv Chanana
void executeSemicolon(struct Expr *expression) {
  if (expression->left)
    execute(expression->left);
  if (expression->right)
    execute(expression->right);
  free(expression);
}

// Kelly Zhou
void executeRedirLeft(struct Expr *expression) {
  // cmd < in.txt
  pid_t pid = fork(); // initialize child process
  if (pid == 0) {
    char *inFile = expression->right->args; // get file name
    int inFd = open(inFile, O_RDONLY);      // open file
    dup2(inFd, 0);                          // duplicate file to stdin
    close(inFd);                            // close unused file descriptor
    execute(expression->left);              // execute redirection
    exit(0);
  } else {
    int status;
    waitpid(pid, &status, 0);
  }
  free(expression);
}

// Kelly Zhou
void executeRedirRight(struct Expr *expression) {
  // cmd > output_file
  pid_t pid = fork(); // initialize child process
  if (pid == 0) {
    char *outFile = expression->right->args; // get file name
    int outFd = open(outFile, O_WRONLY | O_TRUNC | O_CREAT,
                     S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR); // open file
    dup2(outFd, 1);            // duplicate file to stdout
    close(outFd);              // close unused file descriptor
    execute(expression->left); // execute redirection
    exit(0);
  } else {
    int status;
    waitpid(pid, &status, 0);
  }
  free(expression);
}
