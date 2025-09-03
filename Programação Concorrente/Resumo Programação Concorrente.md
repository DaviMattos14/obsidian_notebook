# Capítulo 1 - Introdução à computação concorrente

A programação concorrente está relacionada com a atividade de construir programas de computador que incluem linhas de controle distintas, as quais podem executar simultaneamente. Dessa forma, um programa dito concorrente se diferencia de um programa dito sequencial por conter mais de um fluxo de execução independente.

Para escrever um programa concorrente é necessário definir quais fluxos de execução criar e de que forma eles deverão interagir dentro da aplicação. As decisões devem levar em conta as especificidades da aplicação e o hardware disponível.

A biblioteca utilizada será a `pthread.h` na linguagem C

## Primeiro Programa Concorrente (Hello World!)

Antes de seguirmos vamos ver as primeira funções que usaremos:
### Criação de Threads
Retorna 0 em caso de sucesso
```C
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine)(void*), void *arg);
```
### Encerramento de Threads
A função encerra o thread de chamada e cria o valor *retval* disponível para qualquer junção bem-sucedida
```C
void pthread exit (void *retval);
```
### Espera pelo encerramento da thread
A função suspende a execução da thread chamada até que a execução das threads termine, em caso de sucesso ela retornará 0.
```C
int pthread join (pthread t thread, void **retval);
```
### Tarefa a ser executada pelas threads
A para definir o que as threads criadas terão que fazer, faremos uma função que será chamada em `pthread_join`
```C
void* tarefa(void* arg){
	/* Código a ser executado por cada thread*/
	pthread_exit(NULL);
}
```

### helloWorld.c
Normalmente em um programa sequencial em C temos a seguinte estrutura
```C
#include <stdio.h>

int main(){
	/* código */
return 0;
}
```

Para um programa concorrente, manteremos essa estrutura base, 