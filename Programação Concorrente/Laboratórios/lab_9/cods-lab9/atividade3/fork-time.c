/* Disciplina: Programação Concorrente (ICP361) */
/* Prof.: Silvana Rossetto */
/* Tópico:  Tempo de criação de processos com a chamada fork() */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "timer.h"

#define NFORKS 1000
#define NTIMES 10

int main() {
  double ini, fim;
  int pid, status;

  for (int i=0; i<NTIMES; i++) {
    /* Start time */
    GET_TIME(ini);

    for (int j=0; j<NFORKS; j++) {
      if ((pid = fork()) < 0 ) {
        printf ("-- ERROR: fork()\n"); exit(-1);
      }

      /*** processo filho ***/
      else if (pid == 0) {
        exit(0);
      }

      /*** processo pai ***/
      else {
        waitpid(pid, &status, 0);
      }
    }
   
    /* Stop time */
    GET_TIME(fim);

    printf("tempo(seg)=%g\n", (fim-ini) / (double) NFORKS);
  }

  return 0;
}
