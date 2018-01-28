#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <time.h>

int main(int argc, char ** argv){
  int file;
  struct stat buffer;

  file = open(argv[1], O_CREAT);
  fstat(file, &buffer);
  if(S_ISREG(buffer.st_mode)){
    //Create hard link to file
    link(argv[1],"./hardLink.hard");
    //Create symbolic link to file
    symlink(argv[1], "./symbolicLink.sym");
  }

  return 0;
}
