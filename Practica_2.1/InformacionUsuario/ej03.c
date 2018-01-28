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
  struct passwd *p;

  p = getpwuid(getuid());

  printf("Username: %s\n", p->pw_name);
  printf("Home directory: %s\n", p->pw_dir);
  printf("Password: %s\n", p->pw_passwd);

  return 0;
}
