#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 100000

long int soma = 0; 
pthread_mutex_t mutex;
pthread_cond_t cond;
short int estado = 0;

void *ExecutaTarefa(void *arg) {
    long int id = (long int) arg;
    printf("Thread : %ld esta executando...\n", id);

    for (int i = 0; i < N; i++) {
        pthread_mutex_lock(&mutex);

        while (estado == 1)
          pthread_cond_wait(&cond, &mutex);

        soma++;
        
        // Se atingiu múltiplo de 1000, notifica a thread extra e aguarda
        if (soma % 1000 == 0) {
            if (estado == 0) { // Garante que só uma thread sinaliza
                estado = 1;
                pthread_cond_signal(&cond);
            }

        while (estado == 1)
          pthread_cond_wait(&cond, &mutex);
        }

        pthread_mutex_unlock(&mutex);
    }

    printf("Thread : %ld terminou!\n", id);
    pthread_exit(NULL);
}

void *extra(void *args) {
    long int nthreads = (long int) args;
    long int tot = N * nthreads;
    printf("Extra : executando...\n");

    pthread_mutex_lock(&mutex);

    while (1) {
        while (estado == 0 && soma < tot)
            pthread_cond_wait(&cond, &mutex);

        if (estado == 1)
        {
          printf("soma=%ld\n", soma);
          estado = 0;
          pthread_cond_broadcast(&cond);
        }

        if (soma >= tot) {
          pthread_cond_broadcast(&cond); // garantia extra para evitar deadlocks
          pthread_mutex_unlock(&mutex);
          break;
        }
    }

    printf("Extra : terminou!\n");
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_t *tid;
    int nthreads;

    if (argc < 2) {
        printf("Digite: %s <numero de threads>\n", argv[0]);
        return 1;
    }

    nthreads = atoi(argv[1]);

    tid = (pthread_t *) malloc(sizeof(pthread_t) * (nthreads + 1));
    if (tid == NULL) {
        puts("ERRO--malloc");
        return 2;
    }

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    for (long int t = 0; t < nthreads; t++) {
        if (pthread_create(&tid[t], NULL, ExecutaTarefa, (void *)t)) {
            printf("--ERRO: pthread_create()\n");
            exit(-1);
        }
    }

    if (pthread_create(&tid[nthreads], NULL, extra, (void *)nthreads)) {
        printf("--ERRO: pthread_create()\n");
        exit(-1);
    }

    for (int t = 0; t < nthreads + 1; t++) {
        if (pthread_join(tid[t], NULL)) {
            printf("--ERRO: pthread_join()\n");
            exit(-1);
        }
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    printf("Valor final de soma = %ld\n", soma);
    return 0;
}
