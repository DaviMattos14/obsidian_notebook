/* Disciplina: Programacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Laboratório: 5 */
/* Codigo: Uso de variáveis de condição e suas operações básicas para sincronização por condição */

/***** Condicao logica da aplicacao: a cada iteracao, as threads incrementam seu contador, imprimem o valor atual, e só podem continuar depois que todas as threads completaram o passo. Apos PASSOS passos, as threads terminam  ****/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NTHREADS  5
#define PASSOS  4

/* Variaveis globais */
pthread_mutex_t mutex;
pthread_cond_t cond;

//funcao barreira
void barreira(int nthreads) {
    static int bloqueadas = 0;
    pthread_mutex_lock(&mutex); //inicio secao critica
    if (bloqueadas == (nthreads-1)) { 
      //ultima thread a chegar na barreira
      pthread_cond_broadcast(&cond);
      bloqueadas=0;
    } else {
      bloqueadas++;
      pthread_cond_wait(&cond, &mutex);
    }
    pthread_mutex_unlock(&mutex); //fim secao critica
}

//funcao das threads
void *A (void *t) {
  int my_id = *(int*)t, i;
  int boba1, boba2;

  for (i=0; i < PASSOS; i++) {
    printf("Thread %d: passo=%d\n", my_id, i);

    //sincronizacao condicional
    barreira(NTHREADS);

    /* simula uma computacao qualquer para consumir tempo... */
    boba1=100; boba2=-100; while (boba2 < boba1) boba2++;
  }
  pthread_exit(NULL);
}

/* Funcao principal */
int main(int argc, char *argv[]) {
  pthread_t threads[NTHREADS];
  int id[NTHREADS];
  
  /* Inicilaiza o mutex (lock de exclusao mutua) e a variavel de condicao */
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init (&cond, NULL);

  /* Cria as threads */
  for(int i=0;i<NTHREADS;i++) {
     id[i]=i;
     pthread_create(&threads[i], NULL, A, (void *) &id[i]);
  }

  /* Espera todas as threads completarem */
	  for (int i = 0; i < NTHREADS; i++) {
    pthread_join(threads[i], NULL);
  }
  printf ("FIM.\n");

  /* Desaloca variaveis e termina */
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);
}
