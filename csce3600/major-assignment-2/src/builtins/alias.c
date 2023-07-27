// Group 10: Dhruv Chanana
// CSCE 3600.002, Spring 2023
// Major Assignment 2
// April 21, 2023

#include "shell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alias_cmd(char **args) {
  if (args[1] == NULL) {
    if (strlen(aliases) > 0)
      printf("%s\n", aliases);
    else
      printf("No aliases defined\n");
    return;
  }

  char name[512], alias[512], *start;
  sscanf(args[1], "%512[^=]=", name);
  strcat(name, "=");

  if ((start = strstr(aliases, name)) == NULL) {
    sprintf(aliases + strlen(aliases), "%s,", args[1]);
  } else {
		sscanf(start, "%512[^,],", alias);
		char *end = start + strlen(alias) + 1;

		memmove(start, start + strlen(alias) + 1, strlen(end) + 1);
    sprintf(aliases + strlen(aliases), "%s,", args[1]);
  }
}
