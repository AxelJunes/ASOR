#include <sched.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(){
  int i = 0;
  int policy, nice;
  struct sched_param p;

  sched_getparam(i,&p);
  policy = sched_getscheduler(i);
  nice = getpriority(PRIO_PROCESS, i);
  if(policy == SCHED_FIFO)
    printf("Policy: SCHED_FIFO\n");
  else if(policy == SCHED_RR)
    printf("Policy: SCHED_RR\n");
  else if(policy == SCHED_OTHER)
    printf("Policy: SCHED_OTHER\n");
  printf("Process priority: %d\n", p.sched_priority);
  printf("Process nice: %d\n", nice);
  printf("Maximum priority number: %d\n", sched_get_priority_max(policy));
  printf("Minimum priority number: %d\n", sched_get_priority_min(policy));

  return 0;
}
