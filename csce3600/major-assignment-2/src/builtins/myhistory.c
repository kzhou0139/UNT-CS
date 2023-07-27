// Group 10: Dhruv Chanana
// CSCE 3600.002, Spring 2023
// Major Assignment 2
// April 21, 2023

#include "executor.h"
#include "parser.h"
#include "shell.h"

#include <stdio.h>
#include <stdlib.h>

// myhistory builtin
void myhistory_cmd(char **args) {
  if (args[1] == NULL) {
    // Print out full history if no arguments provided
    for (int i = 0; strlen(history[i]) > 0; i++) {
      printf("%d: %s\n", i + 1, history[i]);
    }
  } else {
    for (int i = 1; args[i]; i++) {     // iterate through all arguments
      if (strcmp(args[i], "-c") == 0) { // clear history flag
        historyIndex = 0;
        for (int i = 0; strlen(history[i]) > 0; i++) {
          strcpy(history[i], "");
        }
      } else if (strcmp(args[i], "-e") == 0) { // execute history flag
        int num = 0;
        sscanf(args[++i], "%d", &num);

        if (1 <= num && num <= 21) {
          if (strlen(history[num]) > 0) { // execute history index
            struct Expr *newExpression = malloc(sizeof(struct Expr));
            newExpression->args = history[num - 1];
            executeCommand(newExpression);
          } else { // handle undefined history values
            printf("History value has no value\n");
          }
        } else { // handle invalid history index
          fprintf(stderr, "Error: invalid history index, enter a number "
                          "between 1 and 20\n");
        }
      } else { // handle invalid flags
        printf("myhistory: invalid option -- '%s'\n", args[i]);
      }
    }
  }
}
