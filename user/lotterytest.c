#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/param.h"
#include "kernel/pstat.h"
#include "user/user.h"

void
spin(void)
{
  volatile unsigned long x = 0;
  for(;;)
    x++;
}

int
main(int argc, char *argv[])
{
  int n = argc - 1;
  int pids[16];
  int i, j;

  if(n < 1 || n > 16){
    printf("uso: lotterytest t1 t2 t3 ...\n");
    exit(1);
  }

  for(i = 0; i < n; i++){
    int pid = fork();
    if(pid < 0){
      printf("fork fallo\n");
      exit(1);
    }
    if(pid == 0){
      if(settickets(atoi(argv[i+1])) < 0){
        printf("settickets fallo\n");
        exit(1);
      }
      spin();
      exit(0);
    }
    pids[i] = pid;
  }

  settickets(1000);   // el padre casi no consume CPU
  pause(300);

  struct pstat ps;
  if(getpinfo(&ps) < 0){
    printf("getpinfo fallo\n");
    exit(1);
  }

  int total = 0;
  for(i = 0; i < n; i++)
    for(j = 0; j < NPROC; j++)
      if(ps.inuse[j] && ps.pid[j] == pids[i])
        total += ps.ticks[j];

  printf("pid\tboletos\tticks\tporcentaje\n");
  for(i = 0; i < n; i++)
    for(j = 0; j < NPROC; j++)
      if(ps.inuse[j] && ps.pid[j] == pids[i])
        printf("%d\t%d\t%d\t%d%%\n", pids[i], ps.tickets[j],
               ps.ticks[j], total ? (ps.ticks[j] * 100) / total : 0);

  for(i = 0; i < n; i++)
    kill(pids[i]);
  for(i = 0; i < n; i++)
    wait(0);
  exit(0);
}
