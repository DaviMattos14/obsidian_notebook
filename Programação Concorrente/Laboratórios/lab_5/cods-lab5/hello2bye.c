/* Disciplina: Programação Concorrente */
/* Profa.: Silvana Rossetto */
/* Laboratório: 5 */
/* Codigo: Uso de variáveis de condição e suas operações básicas para sincronização por condição */
/* Condição lógica da aplicação: a duas threads A devem imprimir HELLO antes da thread B imprimir BYEBYE */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NTHREADS  3

/* Variaveis globais */
short int estado = 0;
pthread_mutex_t mutex;
pthread_cond_t cond;

/* Thread A */
void *A (void *t) {
  printf("A: Comecei\n");
  
  //faz uma computação qualquer...
  
  //executa ''hello''
  printf("HELLO\n");

  pthread_mutex_lock(&mutex);
  estado++;
  if (estado==2) {
      printf("A:  estado = %d, vai sinalizar a condicao \n", estado);
      pthread_cond_signal(&cond);
  }
  pthread_mutex_unlock(&mutex);

  //faz outra computação qualquer...

  pthread_exit(NULL);
}

/* Thread B */
void *B (void *t) {
  printf("B: Comecei\n");

  //faz uma computação qualquer...
  
  //executa ''byebye''
  pthread_mutex_lock(&mutex);
  if (estado<2) { 
     printf("B: estado = %d, vai se bloquear...\n", estado);
     pthread_cond_wait(&cond, &mutex);
     printf("B: sinal recebido e mutex realocado, estado = %d\n", estado);
  }

  printf("BYEBYE\n");
  pthread_mutex_unlock(&mutex); 
  
  //faz outra computação qualquer...
  
  pthread_exit(NULL);
}


/* Funcao principal */
int main(int argc, char *argv[]) {
  pthread_t threads[NTHREADS];

  /* Inicializa o mutex (lock de exclusao mutua) e a variavel de condicao */
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init (&cond, NULL);

  /* Cria as threads */
  pthread_create(&threads[0], NULL, A, NULL);
  pthread_create(&threads[1], NULL, B, NULL);
  pthread_create(&threads[2], NULL, A, NULL);

  /* Espera todas as threads completarem */
  for (int i = 0; i < NTHREADS; i++) {
    pthread_join(threads[i], NULL);
  }
  printf ("\nFIM\n");

  /* Desaloca variaveis e termina */
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);
  return 0;
}
