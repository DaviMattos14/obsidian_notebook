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
    int min_local = min;
    int max_local = max;
    for(int i = inicio; i < fim; i++){
        //printf("thread %ld -> %d\n", arg->id, vetor[i]);
        if(vetor[i] < min_local) min_local = vetor[i];
        if(vetor[i] > max_local) max_local = vetor[i];
    }
    pthread_mutex_lock(&mutex);
    if(min_local < min) min = min_local;
    if(max_local > max) max = max_local; 
    pthread_mutex_unlock(&mutex);

}
```
# Questão 3
## a)
Seção crítica é uma área do código onde é compartilhada entre as threads, mas que devem ser executadas de forma atômica, ou seja, não pode ser executada por mais de uma thread simultaneamente para evitar inconsistências
## b)
Corrida de dados é quando um mais de um fluxo de execução se entrelaça na hora da escrita, ou seja, mais de uma thread acessam a mesma posição da memória ao mesmo tempo.
ocorre quando há dois ou mais acessos concorrentes a uma mesma posição de memória, e pelo menos um desses acessos é de escrita.
## c)
A violação de atomicidade ocorre quando uma sequência de operações que deveria ser executada como um bloco único e indivisível é interrompida por outra thread.
## d)
Violação de ordem se dá quando duas execuções distintas ocorrem de ordens invertidas, ou seja, quando a ordem de precedência não respeitada. 
## e)
Visa garantir que **os trechos de código em cada thread que acessam objetos compartilhados não sejam executados ao mesmo tempo**, ou que uma vez iniciados, são executados até o fim sem que outra thread inicie a execução do trecho equivalente.
## f)
Garante o bloqueios de uma ou mais threads até um sinal de liberação seja mandado .
Visa garantir que **uma thread seja retardada enquanto uma determinada condição lógica da aplicação não for satisfeita**
## g)
Para evitar os problema que surgem com a programação concorrente, tais como, corrida de dados e violação de atomicidade e ordem.
## h)
É criado variáveis em comum que é compartilhada entre as threads, tal trecho de código onde há esse compartilhamento é chamado de seção crítica. E visando evitar problemas como corrida de dados, queremos que a ações executadas na seção crítica sejam atômicas, ou seja, uma por vez, e isso é feito através do pthread_mutex.
# Questão 4
## a) 
a thread 1 é iniciada, S1 é executado, então a thread 1 é pausada, então a thread 2 é iniciada, S3 é executado, thread 2 termina, thread 1 é despausada S2 é executado e a thread 1 termina.
S1 -> S3 -> S2
## b) 
Adicionar pthread_mutex nas seções S1 e S2
## c)
Adiconamos uma variavel estado = 0 e junto com ela implementar pthread_cond. Enquanto a variavel estador for igual a 0, a thread 2 é bloqueada. Uma vez que a thread 1 terminar de inicializar mThread, mudamos a variavel estado para 1 e desbloqueamos a thread 2.

# Questão 5
-4 : 
-3 :
-2 : T3 -> T2 -> T1
-1 : 
0 : T1 -> T2 -> T3
1 : T1(1) -> T1(2)
2 : T2 -> T3 -> T2
3 : 
4 :