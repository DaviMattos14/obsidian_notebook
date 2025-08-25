/* Disciplina: Programação Concorrente */
/* Profa.: Silvana Rossetto */
/* Lab3:  */
/* Codigo: Soma todos os elementos de um vetor de floats */

#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h> 
#include "timer.h"

//#define VERSOES

//variaveis globais
//vetor de elementos
float *vet;

//estrutura de dados para passar argumentos para a thread
typedef struct {
   //tamanho do vetor
   long int n;
   //numero de threads 
   short int nthreads;
   //identificador da thread
   short int id;
} t_args;  


//funcao executada pelas threads
//estrategia de divisao de tarefas: blocos de n/nthreads elementos
void *SomaVetor (void *args) {
  t_args *arg = (t_args*) args; //argumentos da thread
  int ini, fim, fatia; //auxiliares para divisao do vetor em blocos
  float soma_local=0, *ret; //somatorio local
  
  fatia = arg->n / arg->nthreads; //tamanho do bloco de dados de cada thread
  ini = arg->id * fatia; //posicao inicial do vetor
  fim = ini + fatia; //posicao final do vetor
  if (arg->id == (arg->nthreads-1)) fim = arg->n; //a ultima thread trata os elementos restantes no caso de divisao nao exata

  //soma os valores 
  for(int i=ini; i<fim; i++) {
     soma_local += vet[i];
  }

  //retorna o resultado da soma
  ret = (float*) malloc(sizeof(float));
  if (ret!=NULL) *ret = soma_local;
  else printf("--ERRO: malloc() thread\n");
  pthread_exit((void*) ret);
}

//funcao principal do programa
int main(int argc, char *argv[]) {
  long int n; //tamanho do vetor
  short int nthreads; //numero de threads 
  FILE *arq; //arquivo de entrada
  size_t ret; //retorno da funcao de leitura no arquivo de entrada
  double soma_ori; //soma registrada no arquivo
#ifdef VERSOES
  float soma_seq, soma_seq_blocos; //resultados das somas adicionais
  float soma1, soma2; //auxiliares para a soma sequencial alternada
#endif
  float soma_par_global; //resultado da soma concorrente
  float *soma_retorno_threads; //auxiliar para retorno das threads

  pthread_t *tid_sistema; //vetor de identificadores das threads no sistema

  //valida e recebe os valores de entrada
  if(argc < 3) { printf("Use: %s <arquivo de entrada> <numero de threads> \n", argv[0]); exit(-1); }

  //abre o arquivo de entrada com os valores para serem somados
  arq = fopen(argv[1], "rb");
  if(arq==NULL) { printf("--ERRO: fopen()\n"); exit(-1); }

  //le o tamanho do vetor (primeira linha do arquivo)
  ret = fread(&n, sizeof(long int), 1, arq);
  if(!ret) {
     fprintf(stderr, "Erro de leitura das dimensoes da matriz arquivo \n");
     return 3;
  }

  //aloca espaco de memoria e carrega o vetor de entrada
  vet = (float*) malloc (sizeof(float) * n);
  if(vet==NULL) { printf("--ERRO: malloc()\n"); exit(-1); }
  ret = fread(vet, sizeof(float), n, arq);
  if(ret < n) {
     fprintf(stderr, "Erro de leitura dos elementos do vetor\n");
     return 4;
  }

  //le o numero de threads da entrada do usuario 
  nthreads = atoi(argv[2]);
  //limita o numero de threads ao tamanho do vetor
  if(nthreads>n) nthreads = n;

  //aloca espaco para o vetor de identificadores das threads no sistema
  tid_sistema = (pthread_t *) malloc(sizeof(pthread_t) * nthreads);
  if(tid_sistema==NULL) { printf("--ERRO: malloc()\n"); exit(-1); }

  //cria as threads
  for(long int i=0; i<nthreads; i++) {
    t_args *args;
    args = (t_args*) malloc(sizeof(t_args));
    if(args==NULL) {    
       printf("--ERRO: malloc argumentos\n"); exit(-1);
    }
    args->n = n;
    args->nthreads = nthreads;
    args->id = i;
    if (pthread_create(&tid_sistema[i], NULL, SomaVetor, (void*) args)) {
       printf("--ERRO: pthread_create()\n"); exit(-1);
    }
  }

#ifdef VERSOES
  //soma sequencial de traz para frente
  soma_seq = 0;
  for(int t=n-1; t>=0; t--) {
     soma_seq += vet[t];
  }
  //soma sequencial bloco (== soma com 2 threads)
  soma1=0;
  for(int t=0; t<n/2; t++) {
     soma1 += vet[t];
  }
  soma2=0;
  for(int t=n/2; t<n; t++) {
     soma2 += vet[t];
  }
  soma_seq_blocos = soma1 + soma2;
#endif

  //espera todas as threads terminarem e calcula a soma total das threads
  soma_par_global=0;
  for(int i=0; i<nthreads; i++) {
     if (pthread_join(tid_sistema[i], (void *) &soma_retorno_threads)) {
        printf("--ERRO: pthread_join()\n"); exit(-1);
     }
     soma_par_global += *soma_retorno_threads;
     free(soma_retorno_threads);
  }

  //imprime os resultados
  printf("\n");
#ifdef VERSOES
  printf("soma_seq (invertida)         = %.26f\n\n", soma_seq);
  printf("soma_seq_blocos (2 blocos)   = %.26f\n\n", soma_seq_blocos);
#endif
  printf("soma_concorrente             = %.26f\n", soma_par_global);
  //le o somatorio registrado no arquivo
  ret = fread(&soma_ori, sizeof(double), 1, arq); 
  printf("\nSoma-ori                     = %.26lf\n", soma_ori);

  //desaloca os espacos de memoria
  free(vet);
  free(tid_sistema);
  //fecha o arquivo
  fclose(arq);

  return 0;
}
