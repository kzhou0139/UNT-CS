// Group 10: Dhruv Chanana, Alicia Lin, Kelly Zhou, Mark White
// CSCE 3600.002, Spring 2023
// Major Assignment 2

#include "shell.h"
#include "parser.h"

#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// define all global (extern) variables
char aliases[1024], history[20][512];
int historyIndex = 0;

int main(int argc, char *argv[]) {
  bool batchMode = argc > 1;   // batch mode
  char *cwd = getcwd(NULL, 0); // current working directory

  struct Expr **tree;

  if (batchMode) {
    char line[512];                     // line in file
    int file = open(argv[1], O_RDONLY); // file descriptor for batch file
    if (file == -1) {
      perror("Error");
      exit(1);
    }

    dup2(file, 0); // set stdin to batch file descriptor
    close(file);

    // iterate through lines in file
    while (fgets(line, sizeof(line), stdin)) {
      line[strcspn(line, "\n")] = 0; // remove trailing newline

      // build abstract syntax tree and execute
      if (strlen(line) > 0) {
        tree = buildTree(line);
        execute(*tree);
      }
    }
  } else {
    // Capture interrupts
    signal(SIGINT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);

    char line[512]; // line in file

    printf("\x1B[32m[%s %s]\x1B[0m $ ", getlogin(), cwd); // print colored
                                                          // prompt with
                                                          // user and cwd

    // as long as input comes in, continue prompting user
    while (fgets(line, sizeof(line), stdin)) {
      line[strcspn(line, "\n")] = 0; // remove trailing newline

      // add command to history
      if (historyIndex == 20)
        historyIndex -= 20;
      strcpy(history[historyIndex++], line);

      // build abstract syntax tree and execute
      if (strlen(line) > 0) { // ensure line is not empty
        tree = buildTree(line);
        execute(*tree);
      }

      cwd = getcwd(NULL, 0);                                // get new cwd
      printf("\x1B[32m[%s %s]\x1B[0m $ ", getlogin(), cwd); // print prompt
                                                            // again
    }
    printf("\n");
  }
}
