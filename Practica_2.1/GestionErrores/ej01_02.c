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
	const char *s = "Error";
	int errno;

	setuid(2);
	perror(s);
	printf("Error number: %d\n", strerror(errno));

	return 0;
}
