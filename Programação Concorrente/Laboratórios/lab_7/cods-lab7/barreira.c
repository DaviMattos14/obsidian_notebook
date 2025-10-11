/* Disciplina: Computacao Concorrente */
/* Profa.: Silvana Rossetto */
/* Barreira usando semaforos */

/***** Condicao logica da aplicacao: a cada iteracao, as threads incrementam seu contador, imprimem o valor atual, e só podem
continuar depois que todas as threads completaram o passo. Apos N passos, as threads terminam  ****/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#define NTHREADS  5
#define PASSOS  4

/* Variaveis globais */
int bloqueadas = 0;
sem_t mutex, cond;

/* Barreira (solucao incorreta) */
void barreira0(int numThreads) {
    int i;
    sem_wait(&mutex);
    bloqueadas++;
    if (bloqueadas < numThreads) {
      sem_post(&mutex);
      sem_wait(&cond);
    } else {
      printf("\n");
      for(i=0; i<(numThreads-1); i++)
         { sem_post(&cond); }
      bloqueadas = 0;
      sem_post(&mutex);
    }
}

/* Barreira (solucao correta?) */
void barreira(int numThreads) {
    sem_wait(&mutex);
    bloqueadas++;
    if (bloqueadas < numThreads) {
      sem_post(&mutex);
      sem_wait(&cond);
      bloqueadas--;
      if (bloqueadas==0) sem_post(&mutex);
      else sem_post(&cond); 
    } else {
      printf("\n");
      bloqueadas--;
      sem_post(&cond);
    }
}

/* Barreira (solucao incorreta) */
void barreira1(int numThreads) {
    sem_wait(&mutex);
    bloqueadas++;
    if (bloqueadas < numThreads) {
      sem_post(&mutex);
      sem_wait(&cond);
      bloqueadas--;
      if (bloqueadas==0) sem_post(&mutex);
      else sem_post(&cond); 
    } else {
      printf("\n");
      sem_post(&cond);
      bloqueadas--;
    }
}

/* Funcao das threads */
void *A (void *t) {
  int my_id = *(int*)t, i;
  int boba = 0, boba1, boba2;

  for (i=0; i < PASSOS; i++) {
    boba++;
    printf("Thread %d: passo=%d\n", my_id, i);
    /* barreira */
    barreira(NTHREADS);
    /* faz alguma coisa... */
    boba1=100; boba2=-100; while (boba2 < boba1) boba2++;
  }
  //printf("Thread %d: terminou!\n", my_id);
  pthread_exit(NULL);
}

/* Funcao principal */
int main(int argc, char *argv[]) {
  int i; 
  pthread_t threads[NTHREADS];
  int id[NTHREADS];

  /* Inicializa os semaforos */
  sem_init(&mutex, 0, 1);
  sem_init(&cond, 0, 0);

  /* Cria as threads */
  for(i=0;i<NTHREADS;i++) {
     id[i]=i;
     pthread_create(&threads[i], NULL, A, (void *) &id[i]);
  }

  /* Espera todas as threads completarem */
  for (i = 0; i < NTHREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  sem_destroy(&mutex);
  sem_destroy(&cond);
  printf ("FIM.\n");
  pthread_exit (NULL);
}
