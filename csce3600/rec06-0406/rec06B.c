//Kelly Zhou

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  char* name;
  pid_t pid = fork();

  if (pid == 0) {
    printf("child: %d started\n", getpid());
    printf("child: parent = %d\n", getppid());
    printf("child...\n");
    sleep(20);
    printf("child just woke up\n");
  }
  else if (pid > 0) {
    printf("parent %d started\n", getpid());
    printf("parent: parent = %d\n", getppid());
  }
  else
    perror("fork error");

  pid == 0 ? name = (char*)"child" : name = (char*)"parent";
  printf("%s: terminating...\n", name);

  return 0;
}
