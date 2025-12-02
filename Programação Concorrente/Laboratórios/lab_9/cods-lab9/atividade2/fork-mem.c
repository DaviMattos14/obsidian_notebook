/* Disciplina: Programação Concorrente (ICP361) */
/* Prof.: Silvana Rossetto */
/* Tópico: Exemplo de definicao de um espaço de memoria compartilhada entre processo pai e filho */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h> 
#include <sys/types.h> 
#include <unistd.h>

int main(int argc,char *argv[]) { 
  int fd, value, *ptr, pid;

  /* abre uma area de memoria compartilhada ( se nao existir , cria ), retorna um descritor */
  fd = shm_open("/sharedmem", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
  if (fd == -1) {
   printf ("Error shm_open\n");
   exit(1);
  }

  /* ajusta o tamanho da area compartilhada para o dado que será lido e escrito */
  if (ftruncate(fd, sizeof(value)) == -1) {
     printf ("Error ftruncate\n");
     exit(1);
  }

  /* mapeia a area no espaco de enderecamento virtual deste processo */
  ptr = mmap(NULL, sizeof(value), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
  if (ptr == MAP_FAILED) {
    printf ("Error mmap");
    exit(1);
  }

  pid = fork();
  if (pid == -1) { perror("fork"); exit(EXIT_FAILURE); }

  if (pid == 0) {
    while (1) {
      /* escreve um valor aleatorio na area compartilhada */
      value = random () % 1000 ;
      (* ptr) = value ;
      printf ("Filho escreveu %i\n", value) ;
      sleep (1);
      /* le e imprime o conteudo da area compartilhada */
      value = (*ptr) ;
      printf ("Filho leu %i\n", value);
      sleep (1) ;
    }
  } else {
    while (1) {
      /* escreve um valor fixo na area compartilhada */
      value = 100 ;
      (* ptr) = value ;
      printf ("Pai escreveu %i\n", value) ;
      sleep (2);
      /* le e imprime o conteudo da area compartilhada */
      value = (*ptr) ;
      printf ("Pai leu %i\n", value);
      sleep (1) ;
    }
  }
}
