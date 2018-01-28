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
  printf("Major number: %d\n", major(buffer.st_rdev));
  printf("Minor number: %d\n", minor(buffer.st_rdev));
  printf("i-node: %llu\n", buffer.st_ino);
  printf("File type: ");
  if(S_ISREG(buffer.st_mode)){
    printf("Ordinary file\n");
  }
  else if(S_ISDIR(buffer.st_mode)){
    printf("Directory\n");
  }
  else if(S_ISLNK(buffer.st_mode)){
    printf("Symbolic link\n");
  }
  printf("Last time the file was accesed: %s\n", ctime(&buffer.st_atime));

  return 0;
}
