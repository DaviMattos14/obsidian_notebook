/* Disciplina: Programação Concorrente (ICP361) */
/* Prof.: Silvana Rossetto */
/* Tópico: Exemplo de definicao de um espaço de memoria compartilhada entre processo pai e filho com somatorio e exclusao mutua */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <semaphore.h>

typedef struct {
	int value;
	sem_t sem;
} shared_t; 	

int main(int argc,char *argv[]) { 
  int fd, pid;
  shared_t *ptr;

  /* abre uma area de memoria compartilhada ( se nao existir , cria ), retorna um descritor */
  fd = shm_open("/sharedmem1", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
  if (fd == -1) {
   printf ("Error shm_open\n");
   exit(1);
  }

  /* ajusta o tamanho da area compartilhada para o dado que será lido e escrito */
  if (ftruncate(fd, sizeof(shared_t)) == -1) {
     printf ("Error ftruncate\n");
     exit(1);
  }

  /* mapeia a area no espaco de enderecamento virtual deste processo */
  ptr = mmap(NULL, sizeof(shared_t), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
  if (ptr == MAP_FAILED) {
    printf ("Error mmap\n");
    exit(1);
  }
  ptr->value = 0;
  sem_init(&ptr->sem, 1, 1); //semaforo compartilhado entre processos e começando com 1 sinal

  //dispara um processo filho
  pid = fork();
  if (pid == -1) {printf("Error fork\n"); exit(1); }

  //os dois processos fazem o mesmo loop
  for(int i=0; i<100000; i++) {
      sem_wait(&ptr->sem);
      ptr->value = ptr->value + 1;
      sem_post(&ptr->sem);
  }    

  printf ("Valor de (ptr->value): %d\n", ptr->value);
  return 0;
}
