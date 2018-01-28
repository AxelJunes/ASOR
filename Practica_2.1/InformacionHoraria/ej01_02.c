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
	int rc;

	rc = gettimeofday(&now, NULL);
	printf("System time: %u.%06u\n", now.tv_sec, now.tv_usec);

  return 0;
}
