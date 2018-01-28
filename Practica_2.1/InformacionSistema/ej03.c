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
	printf("Maximum argument longitude: %ld\n", sysconf(_SC_ARG_MAX));
	printf("Maximum number of child processes: %ld\n", sysconf(_SC_CHILD_MAX));
	printf("Maximum number of files: %ld\n", sysconf(_SC_OPEN_MAX));

  return 0;
}
