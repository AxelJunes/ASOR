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
  struct timeval now;
  int n = 0;

  rc = gettimeofday(&now, NULL);
  while(n < 10000){
    n++;
  }
  int m = gettimeofday(&now, NULL);
  printf("Time: %d\n", m-rc);

  return 0;
}
