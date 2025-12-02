/* Disciplina: Programação Concorrente (ICP361) */
/* Prof.: Silvana Rossetto */
/* Tópico: Criação de processos com a chamada fork() - memoria nao compartilhada entre processo pai e filho */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main () {
   int x = 0;
   
   fork();

   for(int i=0; i<100000; i++)
      x++;

   printf ("Valor de x: %d\n", x);

   return 0;
}
