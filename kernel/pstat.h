#ifndef _PSTAT_H_
#define _PSTAT_H_
#include "param.h"

struct pstat {
  int inuse[NPROC];    // 1 si la ranura esta en uso
  int tickets[NPROC];  // boletos del proceso
  int pid[NPROC];      // PID
  int ticks[NPROC];    // veces que fue planificado
};
#endif
