#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int estado = 0, aux = 0;
pthread_mutex_t mutex;
pthread_cond_t cond_t1, cond_t2;

void* t1(void *arg){
    pthread_mutex_lock(&mutex);
    
    printf("T1: ola, voce esta acessando a variavel 'aux' agora?\n");
    estado = 1;
    pthread_cond_signal(&cond_t2);
    
    while (estado < 2) pthread_cond_wait(&cond_t1, &mutex);
    printf("T1: certo, entao vou altera-la, ta?\n");
    estado = 3;
    pthread_cond_signal(&cond_t2);
    
    while (estado < 4) pthread_cond_wait(&cond_t1, &mutex);
    aux = 14;
    printf("T1: terminei a alteracao da variavel 'aux'\n");
    estado = 5;
    pthread_cond_signal(&cond_t2);


    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void* t2(void *arg){
    pthread_mutex_lock(&mutex);
    
    while(estado < 1) pthread_cond_wait(&cond_t2, &mutex);
    printf("T2: oi, nao, nao estou\n");
    estado=2;
    pthread_cond_signal(&cond_t1);
    while(estado < 3) pthread_cond_wait(&cond_t2, &mutex);
    printf("T2: tudo bem\n");
    estado=4;
    pthread_cond_signal(&cond_t1);
    while(estado < 5) pthread_cond_wait(&cond_t2, &mutex);
    printf("T2: perfeito, recebido!\n");



    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}


int main(void){
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_t1,NULL);
    pthread_cond_init(&cond_t2,NULL);

    pthread_t thread1, thread2;

    pthread_create(&thread1,NULL, t1, NULL);
    pthread_create(&thread2,NULL, t2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_t1);
    pthread_cond_destroy(&cond_t2);

    return 0;
}
