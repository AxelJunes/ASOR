#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/time.h>


int main(int argc, char **argv){
  struct utsname sys;

  if(uname(&sys) != 0){
    perror("uname");
    exit(EXIT_FAILURE);
  }

  printf("System name: %s\n", sys.sysname);
  printf("Node name: %s\n", sys.nodename);
  printf("Release: %s\n", sys.release);
  printf("Version: %s\n", sys.version);
  printf("Machine: %s\n", sys.machine);

  return 0;
}
