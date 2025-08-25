/* Incrementa um vetor de inteiros de forma concorrente */


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "timer.h"

int *vet; //vetor que será manipulado no programa
	 
typedef struct {
   short int nthreads;
   long int dim;
   short int id;
} t_args;

//função executada pelas threads
void * tarefa (void * args) {
   t_args *arg = (t_args*) args;
   long int fatia, ini, fim;

   fatia = arg->dim/arg->nthreads;
   ini = arg->id * fatia;
   fim = ini+fatia;
   if(arg->id == (arg->nthreads)-1) fim = arg->dim;

   //Outra forma de percorrer o vetor e dividir a tarefa (maior custo de acesso à memória. Por que??
   //short int nthreads = arg->nthreads;
   //fim = arg->dim;
   //for(long int i=arg->id; i<fim; i+=nthreads)
 
   for(long int i=ini; i<fim; i++)
      *(vet+i)+=1;

   free(args); 	
   pthread_exit(NULL);
}

//aloca espaço e inicializa o vetor de inteiros
short int inicia_vetor(long int dim, int **vet) {
//retorna 0 em sucesso
   (*vet) = (int*) malloc(sizeof(int)*dim);
   if((*vet)==NULL) return 1;
   for(long int i=0; i<dim; i++)
	   *(*vet+i) = (int) i;
   return 0;
}

//verifica a corretude do vetor de saida
long int verifica_vetor(long int dim, int *vet) {
//retorna 0 em sucesso e  caso contrario primeira posicao que encontrou erro
   for(long int i=0; i<dim; i++)
      if(*(vet+i) != (int) i + 1) return i;
   return 0;
}


//função principal
int main(int argc, char *argv[]) {
   short int nthreads;  //qtde de threads
   long int dim; //dimensao do vetor
   double start, end, delta;

   //recebe e valida os parametros de entrada
   if(argc < 3) {
      fprintf(stderr, "ERRO de entrada, digite: <%s> <dimensao vetor> <qtde de threads>\n", argv[0]);
      return 1;
   }
   dim = atoi(argv[1]);
   nthreads = atoi(argv[2]);
   if(nthreads>dim) nthreads=dim;

   //aloca espaço e inicializa o vetor de entrada
   if(inicia_vetor(dim, &vet)) {
      fprintf(stderr, "ERRO de inicializacao do vetor\n");
      return 1;
   }   
   //aloca espaco para o vetor de tid
   pthread_t tid[nthreads];

   GET_TIME(start);//começa a contagem de tempo
   //dispara as threads
   for(short int i=0; i<nthreads; i++) {
      t_args *args = (t_args*) malloc(sizeof(t_args));
      if(args==NULL){
         fprintf(stderr, "ERRO de alocacao de argumentos da thread %hd.\n", i);
         return 2;
      }   
      args->nthreads=nthreads;
      args->dim = dim;
      args->id=i;
      if(pthread_create(&tid[i], NULL, tarefa, (void*) args)) {
         fprintf(stderr, "ERRO de criacao da thread %hd.\n", i);
         return 3;
      }
   }

   //aguarda o termino das threads
   for(short int i=0; i<nthreads; i++) {
      if(pthread_join(tid[i], NULL)){
         fprintf(stderr, "ERRO de join da thread %hd.\n", i);
         return 4;
      }
   }
   GET_TIME(end); //termina a contagem de tempo
   delta = end-start; //calcula o intervalo de tempo para processamento do vetor

   //verifica a corretude da solucao concorrente	
   if(verifica_vetor(dim, vet)) 
        fprintf(stderr, "ERRO no vetor de saida\n");
   else puts(":-)");

   printf("Tempo: %lf\n", delta);

   free(vet);
   return 0;
}
