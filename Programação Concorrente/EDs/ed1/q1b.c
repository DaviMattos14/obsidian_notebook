#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

typedef struct{
    short int nthreads;
    int n;
    short int id;
} t_args;

long double calcula_pi(int n){
    long double term;
    term = (4.0 / ((8.0 * n) + 1.0)) -
           (2.0 / ((8.0 * n) + 4.0)) -
           (1.0 / ((8.0 * n) + 5.0)) -
           (1.0 / ((8.0 * n) + 6.0));

    return term * (1.0 / pow(16.0, n));
}

void* task(void* args){
    t_args* arg = (t_args*) args;

    long double *soma= (long double*) malloc (sizeof(long double));
    *soma = 0.0;
    for (int i = arg->id; i < arg->n; i+= arg->nthreads)
    {
        *soma += calcula_pi(i);
    }
    free(args);
    pthread_exit((void*) soma);
}


int main(int argc, char* argv[]){
    if (argc < 3){
        printf("Erro! Digite <Num Thredas> e <Num iteracoes>");
        return -1;
    }

    short int nthreads = atoi(argv[1]);
    int n = atoi(argv[2]);
    if (nthreads > n) nthreads = n;
    
    pthread_t tids[nthreads]; 

    for(int i = 0; i < nthreads; i++){
        t_args *arg = (t_args*) malloc (sizeof(t_args));

        arg->id = i;
        arg->n = n;
        arg->nthreads = nthreads;

        if (pthread_create(&tids[i], NULL, task, (void *) arg)){
            printf("--ERRO: pthread_create()\n"); exit(-1);
        }
    }

    long double *result_indv, resultado = 0.0;
    for (long int i = 0; i < nthreads; i++)
    {
        if (pthread_join(tids[i],(void *) &result_indv))
        {
            printf("--ERRO: pthread_join()\n"); exit(-1);
        }
        resultado += *result_indv;
        free(result_indv);
    }
    
    printf("\n\t pi = %Lf", resultado);
    return 0;
}