/* Disciplina: Programação Concorrente (ICP361) */
/* Prof.: Silvana Rossetto */
/* Tópico:  Comunicacao entre processos via pipe */

//Programa extraido do "man pipe"

#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char *argv[]){
   int pfd[2];
   pid_t cpid;
   char buf, aux;

   if (pipe(pfd) == -1) { 
	perror("pipe"); 
        exit(EXIT_FAILURE); 
   }

   cpid = fork();
   if (cpid == -1) { 
        perror("fork"); 
        exit(EXIT_FAILURE); 
   }

   if (cpid == 0) {            /* Child reads from pipe */
        close(pfd[1]);          /* Close unused write end */
        while (read(pfd[0], &buf, 1) > 0)
	   printf("%c", buf);
        puts("");
	close(pfd[0]);

   } else {            /* Parent writes argv[1] to pipe */
        close(pfd[0]);          /* Close unused read end */
        while (read(STDIN_FILENO, &aux, 1) > 0)
            write(pfd[1], &aux, 1);
	close(pfd[1]);          /* Reader will see EOF */
        wait(0);             /* Wait for child */
   }

   return 0;
}
