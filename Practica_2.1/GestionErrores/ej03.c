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
  int n = 0;

  while(n < 133){
    perror(strerror(n));
    n++;
  }

  return 0;
}
