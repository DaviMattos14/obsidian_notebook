#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// funcao executada pelas threads
void* task(void* arg){
    long int id = (long int) arg;
    printf("Hello World! %ld\n", id);
    pthread_exit(NULL);
}


// Funcao principal
int main(int argc, char *argv[])
{
    short int nthreads; //qtde de threads que serao criadas (recebida na linha de comando)
    
    //verifica se o argumento 'qtde de threads' foi passado e armazena seu valor
    if(argc < 2 ){
        printf("Error! digite %s <n de threads>", argv[0]);
        return 1;
    }

    nthreads = atoi(argv[1]); // capturando o num de threads inserida pelo prompt
    
    //identificadores das threads no sistema
    pthread_t tids[nthreads];
    
     //cria as threads e atribui a tarefa de cada thread
    for( long int i=0; i<nthreads; i++){
        if(pthread_create(&tids[i], NULL, task, (void*) i)){
            printf("Erro pthread_create %ld\n",i);
            return 2;
        }
    }

    // ??????????
    for(short int i=0; i<nthreads;i++ ){
        if(pthread_join(tids[i],NULL)){
            printf("Error!");
            
        }
    }

    //log da funcao main
    printf("FIM!");
    return 0;
}