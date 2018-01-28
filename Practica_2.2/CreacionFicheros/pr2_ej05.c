#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char ** argv){
  int fd;

  fd = open(argv[1], O_CREAT | O_RDWR, 0645); //rw-r--r-x
  if (fd == -1) {
    printf("Error opening file, %i - %s\n", errno, strerror(errno));
    return -1;
  }

  return 0;
}
