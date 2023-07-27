// Group 10: Kelly Zhou
// CSCE 3600.002, Spring 2023
// Major Assignment 2
// April 21, 2023

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// built-in cd command
void cd_cmd(char **path) {
  // if no argument passed, change directory to home
  if (path[1] == NULL)
    chdir(getenv("HOME"));
  else {
    // change directory to path
    int cd_val = chdir(path[1]);
    // if unsuccessful, print out error message
    if (cd_val == -1)
      printf("Error: directory unchanged\n");
  }
}
