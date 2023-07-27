// Group 10: Dhruv Chanana, Alicia Lin, Kelly Zhou, Mark White
// CSCE 3600.002, Spring 2023
// Major Assignment 2

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "executor.h"
#include "parser.h"

// execute function, handles execution of each expression
void execute(struct Expr *expression) {
  // Execute the right function for each command type
  switch (expression->type) {
  case Command:
    executeCommand(expression);
    break;
  case Semicolon:
    executeSemicolon(expression);
    break;
  case Pipeline:
    executePipeline(expression);
    break;
  case RedirRight:
    executeRedirRight(expression);
    break;
  case RedirLeft:
    executeRedirLeft(expression);
    break;
  }
}

struct Expr **buildTree(char *line) {
  struct Expr *grandparent = malloc(sizeof(struct Expr)), // temporary variable
      **root = malloc(sizeof(struct Expr *));             // root of tree
  char *commandstr, delim, *copy = strdup(line), *end;
  bool rootSet = false;
  int offset = 0;

  // use strtok to iterate through each token and build a node for it
  while ((commandstr = strtok_r(line, ";|><", &line))) {
    offset += strlen(commandstr);

    // handle extra leading and trailing whitespace
    while (isspace(commandstr[0]))
      commandstr++;

    end = commandstr + strlen(commandstr) - 1;
    while (end > commandstr && isspace(end[0]))
      end--;
    end[1] = '\0';

    // allocate memory and define basic information about command
    struct Expr *command = malloc(sizeof(struct Expr)),
                *parent = malloc(sizeof(struct Expr));
    command->type = Command;
    command->args = commandstr;
    command->left = NULL;
    command->right = NULL;

    // Get delimiter or special character (redirection, semicolon, pipe)
    delim = copy[offset++];

    // Define AST node for special character if it exists, based on what it is
    switch (delim) {
    case ';':
      parent->type = Semicolon;
      parent->args = ";";
      parent->left = command;
      break;
    case '|':
      parent->type = Pipeline;
      parent->args = "|";
      parent->left = command;
      break;
    case '<':
      parent->type = RedirLeft;
      parent->args = "<";
      parent->left = command;
      break;
    case '>':
      parent->type = RedirRight;
      parent->args = ">";
      parent->left = command;
      break;
    default:
      parent->type = Command;
      parent->args = commandstr;
      parent->left = NULL;
      break;
    }
    parent->right = NULL;

    // Set root if not yet set, and add command and parent to AST
    if (!rootSet) {
      *root = parent;
      rootSet = true;
    } else {
      grandparent->right = parent;
    }
    grandparent = parent;
  }

  return root; // return root AST node
}
