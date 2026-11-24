#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/param.h"
#include "kernel/pstat.h"
#include "user/user.h"

int
mis_boletos(void)
{
  struct pstat ps;
  int me = getpid();
  if(getpinfo(&ps) < 0)
    return -1;
  for(int i = 0; i < NPROC; i++)
    if(ps.inuse[i] && ps.pid[i] == me)
      return ps.tickets[i];
  return -1;
}

int
main(void)
{
  int r;

  r = settickets(10);
  printf("Caso 1: settickets(10) = %d, boletos = %d\n", r, mis_boletos());

  r = settickets(0);
  printf("Caso 2a: settickets(0) = %d, boletos = %d\n", r, mis_boletos());

  r = settickets(-5);
  printf("Caso 2b: settickets(-5) = %d, boletos = %d\n", r, mis_boletos());

  settickets(20);
  int pid = fork();
  if(pid == 0){
    printf("Caso 5: el hijo tiene %d boletos\n", mis_boletos());
    exit(0);
  }
  wait(0);
  exit(0);
}
