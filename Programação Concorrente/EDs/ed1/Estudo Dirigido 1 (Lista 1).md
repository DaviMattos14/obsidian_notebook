# Questão 1
## a)
```C
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double pi(int n){
    long double term;
    term = (4.0 / ((8.0 * n) + 1.0)) -
           (2.0 / ((8.0 * n) + 4.0)) -
           (1.0 / ((8.0 * n) + 5.0)) -
           (1.0 / ((8.0 * n) + 6.0));

    return term * (1.0 / pow(16.0, n));
}
int main(int argc, char*argv[]){
    if (argc < 2)
    {
        printf("Error! digite %s <n de iteracoes>", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    
    long double valor_pi = 0.0;
    for(int i=0; i<n; i++){
        valor_pi += pi(i);
    }
    printf("pi = %Lf\n", valor_pi);
    return 0;
}
```

## b)
```C
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
```
# Questão 2
```C
void* task(void* args){
    //tret* ret = (tret*) malloc(sizeof(tret));
    targ *arg = (targ*) args;

    int fatia = arg->tam / arg->nthreds;
    int inicio = arg->id * fatia;
    int fim = (arg->id == (arg->nthreds-1))? arg->tam : inicio + fatia;

    pthread_mutex_lock(&mutex);
    for(int i = inicio; i < fim; i++){
        //printf("thread %ld -> %d\n", arg->id, vetor[i]);
        if(vetor[i] < min) min = vetor[i];
        if(vetor[i] > max) max = vetor[i];
    }
    pthread_mutex_unlock(&mutex);
}
```
# Questão 3
## a)
Seção crítica é uma área do código onde é compartilhada entre as threads, mas que devem ser executadas de forma atômica.
## b)
Corrida de dados é quando um mais de um fluxo de execução se entrelaça na hora da escrita, ou seja, mais de uma thread acessam a mesma posição da memória ao mesmo tempo.
## c)
Violação de atomicidade é quando uma função que deveria ser executada uma por thread é executada por mais de uma ao mesmo tempo causando interrupção de uma das threadas
## d)
## e)
## f)
## g)
## h)