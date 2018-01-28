#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv){
  // Execute nano
  system(argv[1]);
  printf("You exited %s\n", argv[1]);
  // Execute ls
  execl("/bin/ls", "­l", NULL);
  printf("You exited %s\n", argv[1]);
  return 0;
}
