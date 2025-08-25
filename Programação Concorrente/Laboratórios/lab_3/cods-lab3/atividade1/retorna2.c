/* Disciplina: Programacao Concorrente */
/* Profa.: Silvana Rossetto */
/* Laboratório: 2 */
/* Codigo: usando threads em C com mais de um argumento e mais de um retorno */

#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>

//cria a estrutura de dados para armazenar os argumentos da thread
typedef struct {
   int idThread, nThreads;
} t_Args;

//cria a estrutura de dados de retorno da thread
typedef struct {
   int idThread;
   int aux;
} t_Ret;

//funcao executada pelas threads
void *PrintHello (void *arg) {
  t_Ret *ret; //estrutura de retorno

  //typecarting do argumento
  t_Args *args = (t_Args*) arg;

  //aloca memoria para a estrutura de retorno
  ret = malloc(sizeof(t_Ret));
  if (ret==NULL) {
     printf("--ERRO: malloc() thread\n");
     pthread_exit(NULL);
  }
  ret->idThread = args->idThread;
  ret->aux = args->idThread * 2;
  free(arg); //libera a memoria que foi alocada na main

  pthread_exit((void*) ret);
}

//--funcao principal do programa
int main(int argc, char* argv[]) {
  t_Args *args; //receberá os argumentos para a thread
  int nthreads; //qtde de threads que serao criadas (recebida na linha de comando)
  pthread_t *tid_sistema; //identificadores das threads no sistema

  t_Ret  *retorno; //receberá o retorno das threads (nao eh necessario alocar, virá alocada)

  //verifica se o argumento 'qtde de threads' foi passado e armazena seu valor
  if(argc<2) {
      printf("--ERRO: informe a qtde de threads <%s> <nthreads>\n", argv[0]);
      return 1;
  }
  nthreads = atoi(argv[1]);

  //identificadores das threads no sistema
   tid_sistema = (pthread_t*) malloc(sizeof(pthread_t)*nthreads);
   if(tid_sistema==NULL){
       printf("--ERRO: malloc\n");
       return 2;
   }

  //cria as threads
  for(int i=0; i<nthreads; i++) {
    args = malloc(sizeof(t_Args));
    if (args == NULL) {
      printf("--ERRO: malloc()\n"); 
      return 2;
    }
    args->idThread = i; 
    args->nThreads = nthreads; 
    
    printf("--Cria a thread %d\n", i);
    if (pthread_create(&tid_sistema[i], NULL, PrintHello, (void*) args)) {
      printf("--ERRO: pthread_create() da thread %d\n", i); 
    }
  }

  //espera todas as threads terminarem e recebe os valores retornados
   for (int i=0; i<nthreads; i++) {
     if (pthread_join(tid_sistema[i], (void**) &retorno)) {
         printf("--ERRO: pthread_join() da thread %d\n", i);
     }
     printf("Thread %d retornou %d \n", retorno->idThread, retorno->aux);
     free(retorno); //libera memoria alocada na thread
   }

  //log da função principal
  printf("--Thread principal terminou\n");
  return 0;
}
