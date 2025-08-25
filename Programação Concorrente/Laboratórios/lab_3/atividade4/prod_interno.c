#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "timer.h"

float *vetA, *vetB;

typedef struct 
{
    long int dim;
    short int id;
    short int nthreads;
} targs;


void* task(void* args){
    targs *arg = (targs*) args;

    int inicio, fim, fatia;
    float prod_int_local = 0, *retorno;

    fatia = arg->dim / arg->nthreads;
    inicio = arg->id * fatia;
    fim = inicio + fatia;
    if (arg->id == (arg->nthreads-1)) fim = arg->dim;

    for (int i = inicio; i < fim; i++)
    {
        prod_int_local += vetA[i] * vetB[i];
    }
    
    retorno = (float*) malloc(sizeof(float));
    if (retorno != NULL) *retorno = prod_int_local;
    else printf("--ERRO: malloc() thread\n");
    pthread_exit((void*) retorno);
}

int main(int argc, char *argv[]){

    short int nthreads;
    long int dim;
    FILE* arq;
    size_t ret;
    pthread_t *tids;

    float prod_interno_global, *prod_interno_thread, prod_interno_seq, erro;

    double start, end, delta;

    if(argc < 3) { printf("Use: %s <arquivo de entrada> <numero de threads> \n", argv[0]); exit(-1); }

    arq = fopen(argv[1], "rb");
    if(arq==NULL) { printf("--ERRO: fopen()\n"); exit(-1); }

    ret = fread(&dim, sizeof(long int), 1, arq);
    if(!ret) {
        fprintf(stderr, "Erro de leitura das dimensoes da matriz arquivo \n");
        return 3;
    }

    vetA = (float *) malloc (sizeof(float) * dim);
    vetB = (float *) malloc (sizeof(float) * dim);
    if(vetA==NULL || vetB == NULL) { printf("--ERRO: malloc()\n"); exit(-1); }

    ret = fread(vetA,sizeof(float), dim, arq);
    ret = fread(vetB,sizeof(float), dim, arq);
    ret = fread(&prod_interno_seq, sizeof(float), 1, arq);

    nthreads = atoi(argv[2]);
    if(nthreads>dim) nthreads = dim;

    tids = (pthread_t *) malloc(sizeof(pthread_t) * nthreads);
    if(tids==NULL) { printf("--ERRO: malloc()\n"); exit(-1); }

    //printf("Dim: %ld\n Produto Interno: %lf\n Vetor A: %lf \t Vetor B: %lf ", dim, prod_interno_seq, vetA[0], vetB[0]);

    GET_TIME(start);
    for(long int i = 0; i < nthreads; i++){
        targs* args;
        args = (targs *) malloc(sizeof(targs));
        if (args == NULL){
            printf("--ERRO: malloc argumentos\n"); exit(-1);
        }
        
        args->dim = dim;
        args->id = i;
        args->nthreads = nthreads;

        if(pthread_create(&tids[i],NULL, task, (void *) args)){
            printf("--ERRO: pthread_create()\n"); exit(-1);
        }
    } 

    prod_interno_global = 0.0f;

    for (long int i = 0; i < nthreads; i++)
    {
        if (pthread_join(tids[i],(void *) &prod_interno_thread))
        {
            printf("--ERRO: pthread_join()\n"); exit(-1);
        }
        prod_interno_global += *prod_interno_thread;
        free(prod_interno_thread);
    }

    GET_TIME(end);
    delta = end-start;

    erro = (prod_interno_seq - prod_interno_global) / prod_interno_seq;
    printf("Dimensao: %ld\nValor Produto Interno (Seq)= %.16f\nValor Produto Interno (Conc)= %.16f\nErro = %.16f\n", dim, prod_interno_seq, prod_interno_global, erro);
    printf("\n \tTempo de Execucao = %lf\n",delta);

    free(vetA);
    free(vetB);
    free(tids);
    fclose(arq);
    return 0;
}