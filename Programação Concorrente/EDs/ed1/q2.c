#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

typedef struct{
    short int id;
    short int nthreds;
    long int tam;

} targ;

int *vetor;
int max = -1;
int min = 1000;
pthread_mutex_t mutex;

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



int main(int argv, char* argc[]){

    if (argv < 3)
    {
        printf("Error! digite <Tamanho do Vetor> <N de threads>");
        return -1;
    }
    
    int n = atoi(argc[1]);
    short int nthreads = atoi(argc[2]);
    vetor = (int*) malloc(sizeof(int) * n);
    if(nthreads > n) n = nthreads;
    
    pthread_t *tids = (pthread_t*) malloc(sizeof(pthread_t)*nthreads);
    //tret *ret = (tret*) malloc(sizeof(tret));

    if (vetor == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // inicializa a semente do gerador de números aleatórios
    srand((unsigned) time(NULL));

    // preenche com números aleatórios de 0 a 99
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 100; // se quiser pode trocar 100 pelo limite que quiser
    }
    pthread_mutex_init(&mutex,NULL);

    for (int i = 0; i < nthreads; i++){
        targ *args = (targ*) malloc(sizeof(targ));
        args->nthreds = nthreads;
        args->id = i;
        args->tam = n;
        if (pthread_create(&tids[i], NULL, task, (void*) args))
        {
            printf("Error"); exit(-1);
        }
        
    }

    for (int i = 0; i < nthreads; i++)
    {
        if (pthread_join(tids[i],NULL))
        {
            printf("Error"); exit(-1);
        }
        
    }
    pthread_mutex_destroy(&mutex);

    // imprime o vetor gerado
    printf("Vetor gerado:[");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
    printf("Min: %d \tMax:%d\n",min, max);
    free(vetor);
    return 0;
}