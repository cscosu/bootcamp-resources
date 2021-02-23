#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char buf1[50];
  int x = 0x4567;
  short y = 3;
  int z = 420;

  // get a (arbitrary-length) string from the user
  gets(buf1);

  // print the variables back to the user
  // (you could also do this with gdb)
  printf("buf1: %s\n", buf1);
  printf("x: %d y: %hd z: %d\n", x, y, z);

  // check for win condition
  if (y == 456 && z == 0xABCDEF) {
    system("/bin/sh");
  }
  
}


