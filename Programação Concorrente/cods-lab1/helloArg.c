/* Disciplina: Programacao Concorrente */
/* Profa.: Silvana Rossetto */
/* Laboratório: 1 */
/* Codigo: "Hello World" usando threads em C com passagem de um argumento */

#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>

//funcao executada pelas threads
void *PrintHello (void* arg) {
   //typecasting do argumento
   long int idThread = (long int) arg;
   //log da thread
   printf("Hello World da thread: %ld\n", idThread);

   pthread_exit(NULL);
}

//funcao principal do programa
int main(int argc, char * argv[]) {
   int nthreads; //qtde de threads que serao criadas (recebida na linha de comando)

   //verifica se o argumento 'qtde de threads' foi passado e armazena seu valor
   if(argc<2) {
       printf("--ERRO: informe a qtde de threads <%s> <nthreads>\n", argv[0]);
       return 1;
   }
   nthreads = atoi(argv[1]);

   //identificadores das threads no sistema
   pthread_t tid_sistema[nthreads];

   //cria as threads e atribui a tarefa de cada thread
   for(long int i=1; i<=nthreads; i++) {
      //printf("--Cria a thread %ld\n", i);
      if (pthread_create(&tid_sistema[i-1], NULL, PrintHello, (void*) i)) {
         printf("--ERRO: pthread_create()\n"); 
	 return 2;
      }
   }
   
   //log da função main
   printf("--Thread principal terminou\n");
   pthread_exit(NULL); //necessario para que o processo não seja encerrado antes das threads terminarem
   return 0;
}







