#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main(){
  sigset_t signalSet;

  sigemptyset(&signalSet);
  sigaddset(&signalSet, SIGINT);
  sigaddset(&signalSet, SIGTSTP);
  sigprocmask(SIG_BLOCK, &signalSet, NULL);
  printf("Signals blocked\n");
  sigaction(SIGINT, &signalSet, NULL);
  sigaction(SIGTSTP, &signalSet, NULL);
  sleep(30);
  sigset_t signalStop;
  sigaddset(&signalStop, SIGTSTP);
  // Only unlock if SIGSTP is received
  if(sigpending(&signalStop) == 0){
    sigprocmask(SIG_UNBLOCK, &signalSet, NULL);
    printf("Signals unlocked\n");
  }

  return 0;
}
