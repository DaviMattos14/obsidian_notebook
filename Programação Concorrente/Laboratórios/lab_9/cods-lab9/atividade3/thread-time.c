/* Disciplina: Programação Concorrente (ICP361) */
/* Prof.: Silvana Rossetto */
/* Tópico:  Tempo de criação de threads com pthread_create */

#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>
#include "timer.h"

#define NTHREADS 1000
#define NTIMES 10

//--funcao executada pelas threads
void *Task (void* arg) {

   pthread_exit(NULL);
}

//--funcao principal do programa
int main(int argc, char * argv[]) {
   double ini, fim;
   pthread_t tid[NTHREADS];

   for (int i=0; i<NTIMES; i++) {
     /* Start time */
     GET_TIME(ini);

     //cria as threads
     for(int i=0; i<NTHREADS; i++) {
       if (pthread_create(&tid[i], NULL, Task, NULL)) {
          printf("--ERRO: pthread_create()\n"); 
       }
       pthread_join(tid[i], NULL);
     }

     /* Stop time */
     GET_TIME(fim);

     printf("tempo(seg)=%g\n", (fim-ini) / (double) NTHREADS);
   }
   
   return 0;
}







