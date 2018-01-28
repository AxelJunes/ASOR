#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(){
  pid_t pid, ppid, pgid, sid;
  struct rlimit limit;
  char dir [100];

  pid  = getpid();
  ppid = getppid();
  pgid = getpgid(pid);
  sid  = getsid(pid);

  printf("Process id: %d\n",pid);
  printf("Process Parent id: %d\n",ppid);
  printf("Process Group id: %d\n",pgid);
  printf("Session id: %d\n",sid);
  printf("RLIMIT_FSIZE: %d\n", getrlimit(RLIMIT_FSIZE, &limit));
  printf("Path: %s\n", getcwd(dir, 100));
  return 0;
}
