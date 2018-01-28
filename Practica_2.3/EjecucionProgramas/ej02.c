#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv){
  int fdOut, fdErr, fdIn;

  pid_t pid = fork();

  if(pid == -1)
  perror("Fork error");
  else if(pid == 0){
    fdOut = open("/tmp/daemon.out", O_RDWR | O_CREAT);
    fdErr = open("/tmp/daemon.err",O_RDWR | O_CREAT);
    fdIn = open("/tmp/null",O_RDWR | O_CREAT);

    dup2(fdIn,STDIN_FILENO);
    dup2(fdOut,STDOUT_FILENO);
    dup2(fdErr,STDERR_FILENO);

    execv(argv[1], argv + 1);
    close(fdErr);
    close(fdOut);
    close(fdIn);
  }
  else{
    int status;
    wait(&status);
  }
  return 0;
}
