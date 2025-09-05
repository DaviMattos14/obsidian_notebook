/* Disciplina: Programação Concorrente */
/* Profa.: Silvana Rossetto */
/* Laboratório: 5 */
/* Codigo: Uso de variáveis de condição e suas operações básicas para sincronização por condição */
/* Condição lógica da aplicação: uma thread A deve imprimir HELLO antes da thread B imprimir BYEBYE */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NTHREADS  2

/* Variaveis globais */
short int hello = 0;
pthread_mutex_t mutex;
pthread_cond_t cond;

/* Thread A */
void *A (void *t) {
  printf("A: Comecei\n");
  
  //faz uma computação qualquer...
  
  //executa ''hello'' (OU vai para o estado 'hello')
  printf("HELLO\n");

  //regitra transicao de estado (para o caso da outra thread ainda não ter chegado ao ponto que deve verificar o estado) 
  pthread_mutex_lock(&mutex);
  hello=1; //registra a transição de estado
  //sinaliza outra thread (para o caso da outra thread já estar bloqueada)
  printf("A: vai sinalizar a condicao \n");
  pthread_cond_signal(&cond);
  pthread_mutex_unlock(&mutex);

  //faz outra computação qualquer...

  pthread_exit(NULL);
}

/* Thread B */
void *B (void *t) {
  printf("B: Comecei\n");

  //faz uma computação qualquer...
  
  //verifica se pode executar ''byebye''
  pthread_mutex_lock(&mutex);
  if (!hello) { // estado não transicionou ainda...
     printf("B: vai se bloquear para aguardar transicao de estado\n");
     pthread_cond_wait(&cond, &mutex); //bloqueia até estado valido
     printf("B: sinal recebido e mutex realocado \n");
  }
  pthread_mutex_unlock(&mutex); 
  
  //executa ''byebye''
  printf("BYEBYE\n");
  
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
  pthread_create(&threads[1], NULL, B, NULL);
  pthread_create(&threads[0], NULL, A, NULL);

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
