#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <semaphore.h>

int *buffer;
sem_t vazio, cheio, mutex;
int posInsere = 0, posRetira = 0, consumido = 0;
int n, m;
short int nthreads;

typedef struct{
    short int id;
    int nthreads;
} targs;

typedef struct{
    short int id;
    int qtdPrimos;
} tresp;

int ehPrimo(long long int n){
    int i;
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (i = 3; i < sqrt(n) + 1; i += 2)
        if (n % i == 0) return 0;
    return 1;
}

void insere(int elemento){
    buffer[posInsere] = elemento;
    posInsere = (posInsere + 1) % m;
}

void* produtor(void* arg) {
    for (int i = 0; i < n;) {
        for (int j = 0; j < m; j++) {
            sem_wait(&vazio);
        }
        sem_wait(&mutex);
        int items_inseridos = 0;
        for (int j = 0; j < m && i < n; j++) {
            insere(i);
            i++;
            items_inseridos++;
        }
        sem_post(&mutex);
        for (int j = 0; j < items_inseridos; j++) {
            sem_post(&cheio);
        }
    }
    for (int i = 0; i < nthreads; i++) {
        sem_post(&cheio);
    }
    pthread_exit(NULL);
}


int retira(){
    int elemento = buffer[posRetira];
    posRetira = (posRetira + 1) % m;
    return elemento;
}

void* consumidor(void* arg){
    targs* args = (targs*) arg;
    int count_primo = 0;

    while (1) {
        sem_wait(&cheio);
        sem_wait(&mutex);

        if (consumido >= n) {
            sem_post(&mutex);
            sem_post(&cheio);
            break;
        }

        int num = retira();
        consumido++;

        sem_post(&mutex);
        sem_post(&vazio);

        if (ehPrimo(num)) {
            count_primo++;
        }
    }

    tresp *resultado = malloc(sizeof(tresp));
    if (resultado == NULL) {
        fprintf(stderr, "Erro de alocação de memória\n");
        exit(1);
    }
    resultado->id = args->id;
    resultado->qtdPrimos = count_primo;
    pthread_exit((void*) resultado);
}


int main(int argc, char *argv[]){
    if (argc < 4) {
        printf("Uso: %s <N> <M> <num_consumidores>\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);
    m = atoi(argv[2]);
    nthreads = atoi(argv[3]); 

    int vencedor = -1, qtdPrimoVencedor = 0, qtdTotalPrimos = 0;
    tresp *resp;

    buffer = malloc(m * sizeof(int));
    pthread_t prod;
    pthread_t consumidores[nthreads];
    targs args[nthreads];

    sem_init(&vazio, 0, m);
    sem_init(&cheio, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&prod, NULL, produtor, NULL);

    for (int i = 0; i < nthreads; i++) {
        args[i].id = i + 1;
        args[i].nthreads = nthreads;
        pthread_create(&consumidores[i], NULL, consumidor, &args[i]);
    }

    pthread_join(prod, NULL);

    for (int i = 0; i < nthreads; i++) {
        pthread_join(consumidores[i], (void**) &resp);
        qtdTotalPrimos += resp->qtdPrimos;
        if (resp->qtdPrimos > qtdPrimoVencedor) {
            qtdPrimoVencedor = resp->qtdPrimos;
            vencedor = resp->id;
        }
        free(resp);
    }

    printf("\nNum Total de Primos entre [%d, %d): %d\n\nVENCEDOR: Thread %d - Primos Encontrados: %d\n",
           (n-n), n, qtdTotalPrimos, vencedor, qtdPrimoVencedor);

    sem_destroy(&vazio);
    sem_destroy(&cheio);
    sem_destroy(&mutex);
    free(buffer);

    return 0;
}