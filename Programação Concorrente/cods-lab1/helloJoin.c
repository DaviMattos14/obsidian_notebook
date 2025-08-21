/* Disciplina: Programacao Concorrente */
/* Profa.: Silvana Rossetto */
/* Laboratório: 1 */
/* Codigo: "Hello World" usando threads em C e a funcao que espera as threads terminarem */

#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>

//cria a estrutura de dados para armazenar os argumentos da thread
typedef struct {
   int idThread, nThreads;
} t_Args;

//funcao executada pelas threads
void *PrintHello (void *arg) {
  t_Args *args = (t_Args *) arg;

  printf("Sou a thread %d de %d threads\n", args->idThread, args->nThreads);
  free(arg); //libera a alocacao feita na main

  pthread_exit(NULL);
}

//funcao principal do programa
int main(int argc, char* argv[]) {
  t_Args *args; //receberá os argumentos para a thread

  int nthreads; //qtde de threads que serao criadas (recebida na linha de comando)

  //verifica se o argumento 'qtde de threads' foi passado e armazena seu valor
  if(argc<2) {
      printf("--ERRO: informe a qtde de threads <%s> <nthreads>\n", argv[0]);
      return 1;
  }
  nthreads = atoi(argv[1]);

  //identificadores das threads no sistema
  pthread_t tid_sistema[nthreads];

  //cria as threads
  for(int i=1; i<=nthreads; i++) {
    printf("--Aloca e preenche argumentos para thread %d\n", i);
    args = malloc(sizeof(t_Args));
    if (args == NULL) {
      printf("--ERRO: malloc()\n"); 
      return 1;
    }
    args->idThread = i; 
    args->nThreads = nthreads; 
    
    printf("--Cria a thread %d\n", i);
    if (pthread_create(&tid_sistema[i-1], NULL, PrintHello, (void*) args)) {
      printf("--ERRO: pthread_create()\n"); 
      return 2;
    }
  }

  //espera todas as threads terminarem
  for (int i=0; i<nthreads; i++) {
    if (pthread_join(tid_sistema[i], NULL)) {
         printf("--ERRO: pthread_join() da thread %d\n", i); 
    } 
  }

  //log da função principal
  printf("--Thread principal terminou\n");

  //pthread_exit(NULL); //nao é necessario nesse caso, por que?

  return 0;
}
