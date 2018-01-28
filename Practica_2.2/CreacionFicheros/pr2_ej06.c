#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char ** argv){
  int fd;

  // Set mask so that new files don't have write permissions for group
  // and no other permissions for the rest of users
  umask(0727);
	fd = open(argv[1], O_CREAT, 0777);
	if (fd == -1) {
    printf("Error opening file, %i - %s\n", errno, strerror(errno));
    return -1;
  }

  return 0;
}
