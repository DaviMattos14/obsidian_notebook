/* Disciplina: Programação Concorrente (ICP361) */
/* Prof.: Silvana Rossetto */
/* Tópico: Criação de processos com a chamada fork() e execve */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[], char *envp[]) {
   int pid;
   
   // cria um processo filho
   pid = fork ();
   
   // verifica se houve erro
   if ( pid < 0 ) {
      perror ("Erro: ");
      exit (1) ;
   }
   // apenas o processo pai executa
   else if ( pid > 0 ) {
      wait (0);
   }
   // apenas o processo filho executa
   else {
      execve ("/usr/bin/ls", argv, envp);

   }
   
   printf ("Tchau !\n");

   return 0;
}
