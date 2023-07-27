// Group 10: Alicia Lin
// CSCE 3600.002, Spring 2023
// Major Assignment 2
// April 21, 2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// built-in path command
void path_cmd(char **path) {
  // if no argument passed, display path name
  if (path[1] == NULL && path[2] == NULL) {
    // check if path is null
    if (getenv("PATH") == NULL) printf("PATH null!\n");
    else printf("%s\n", getenv("PATH"));
  }
  // if arguments passed, append or remove from pathname
  else {
    char argument[1024] = "";   // variable for new pathname
    // add to pathname
    if (strcmp(path[1], "+") == 0) {
      // check if current path is null
      if (getenv("PATH") == NULL) {
        printf("PATH null!\n");
        return;
      }
      // add current path to variable
      else strcat(argument, getenv("PATH"));
      // add user argument to variable
      char *pathAddition = path[2];
      // remove . at beginning of input
      if (pathAddition[0] == '.')
        memmove(pathAddition, pathAddition + 1, strlen(pathAddition));
      strcat(argument, pathAddition);
      // set PATH environment variable
      setenv("PATH", argument, 1);
      // check how path has changed
      if (getenv("PATH") == NULL) printf("PATH null!\n");
      else printf("%s\n", getenv("PATH"));
    }
    // remove from pathname
    else if (strcmp(path[1], "-") == 0) {
      char *currentPath;
      // check if current path is null
      if (getenv("PATH") == NULL) {
        printf("PATH null!\n");
        return;
      }
      // get current path
      else currentPath = getenv("PATH");
      // get user argument
      char *pathRemoval = path[2];
      // remove . at beginning of input
      if (pathRemoval[0] == '.')
        memmove(pathRemoval, pathRemoval + 1, strlen(pathRemoval));
      // remove user argument from end of variable
      int removalLength = strlen(pathRemoval);
      int pathSize = strlen(currentPath);
      currentPath[pathSize - removalLength] = '\0';
      // set PATH environment variable
      strcat(argument, currentPath);
      setenv("PATH", argument, 1);
      // check how path has changed
      if (getenv("PATH") == NULL) printf("PATH null!\n");
      else printf("%s\n", getenv("PATH"));
    } else
      printf("Unable to execute path command \n");
  }
}
