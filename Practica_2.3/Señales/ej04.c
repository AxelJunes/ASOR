#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/**
* Signal handler
*/
void handler(int signal){
  if(signal == SIGINT)
  printf("SIGINT\n");
  else if(signal == SIGTSTP)
  printf("SIGTSTP\n");
}

int main(){
  sigset_t signalSet;
  struct sigaction sig;

  sig.sa_flags = SA_RESTART;
  sig.sa_handler = handler;
  sigemptyset(&signalSet);
  sigaddset(&signalSet, SIGINT);
  sigaddset(&signalSet, SIGTSTP);
  sigprocmask(SIG_BLOCK, &signalSet, NULL);
  printf("Signals blocked\n");
  sigaction(SIGINT, &signalSet, NULL);
  sigaction(SIGTSTP, &signalSet, NULL);
  sleep(30);
  sigprocmask(SIG_UNBLOCK, &signalSet, NULL);
  printf("Signals unlocked\n");

  return 0;
}
