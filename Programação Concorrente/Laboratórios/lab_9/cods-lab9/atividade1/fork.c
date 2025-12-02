/* Disciplina: Programação Concorrente (ICP361) */
/* Profa.: Silvana Rossetto */
/* Tópico: Criação de processos com a chamada fork() */

#include <unistd.h> //sleep
#include <sys/wait.h> //wait
#include <stdlib.h> //exit
#include <stdio.h> //printf

int main (void) {
   int pid;
   
   // cria um processo filho
   pid = fork (); //'pid' recebe o identificador do processo filho
   
   // verifica se houve erro
   if ( pid < 0 ) {
      printf ("Erro de criação de processo filho: %d\n", pid);
      exit(1);
   }
   //!!!!!!! apenas o processo pai executa !!!!!!!!
   else if ( pid > 0 ) {
      printf ("sou o processo pai, meu pid é %d, criei o processo filho de pid %d\n", getpid(), pid);
      wait(0); //suspende a execução até que um processo filho qualquer termine
   }
   //!!!!!!!

   //!!!!!!! apenas o processo filho executa !!!!!!!!!
   else {
      printf ("sou o processo filho, meu pid é %d\n", getpid());
      sleep(5); //se bloqueia por 5 seg 
   } 
   //!!!!!!!
   
   // os processos pai e filho executam
   printf ("Olá do processo %d!\n", getpid());

   return 0;
}
