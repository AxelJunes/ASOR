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
  printf("Maximum number of links to the directory: %ld\n", pathconf("/", _PC_LINK_MAX));
  printf("Maximum length of the path: %ld\n", pathconf("/", _PC_PATH_MAX));
  printf("Maximum length of a file name: %ld\n", pathconf("/", _PC_NAME_MAX));

  return 0;
}
