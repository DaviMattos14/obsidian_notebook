/* Disciplina: Programação Concorrente (ICP361) */
/* Prof.: Silvana Rossetto */
/* Tópico: Exemplo de definicao de um espaço de memoria compartilhada entre processo pai e filho com somatorio */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h> 
#include <sys/types.h> 
#include <unistd.h>

int main(int argc,char *argv[]) { 
  int fd, *ptr, value, pid;

  /* abre uma area de memoria compartilhada ( se nao existir , cria ), retorna um descritor */
  fd = shm_open("/sharedmem0", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
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
  *ptr=0;

  //dispara um processo filho
  pid = fork();
  if (pid == -1) {printf("Error fork\n"); exit(1); }

  //os dois processos fazem o loop
  for(int i=0; i<100000; i++)
      *ptr = *ptr + 1;

  printf ("Valor de (*ptr): %d\n", *ptr);
  
  return 0;
}
