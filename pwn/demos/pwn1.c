#include <stdio.h>
#include <stdlib.h>

void get_log_file(char *name) {
  char cmd[50];
  sprintf(cmd, "cat log_file_%s", name);
  printf("Running: %s\n", cmd);
  system(cmd);
}

void create_log_file(char *name) {
  char cmd[50];
  sprintf(cmd, "echo \"memes\" > log_file_%s", name);
  system(cmd);
}

int main() {
  char log_name[100];
  create_log_file("alpha");
  
  printf("You could imagine this program running as part of a networked\n");
  printf("service on a server or an IoT device.\n");
  printf("\n\nPlease enter the name of the log file to access: ");
  
  // Get the name of the desired log file from the user
  fgets(log_name, 100, stdin);

  // Call get_log_file with user-controlled name
  get_log_file(log_name);
}


