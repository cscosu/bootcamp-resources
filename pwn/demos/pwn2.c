#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char buf1[16];
  char buf2[16];

  // get a (arbitrary-length) string from the user
  gets(buf1);

  // print the strings back to the user
  printf("buf1: %s\n", buf1);
  printf("buf2: %s\n", buf2);

  // check for win condition
  if (strcmp(buf2, "win") == 0) {
    system("/bin/sh");
  }
  
}


