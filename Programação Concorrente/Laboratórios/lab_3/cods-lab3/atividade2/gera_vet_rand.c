/*
Programa auxiliar para gerar um vetor de floats 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000 //valor maximo de um elemento do vetor
//descomentar o define abaixo caso deseje imprimir uma versao do vetor gerado no formato texto
//#define LOG 

int main(int argc, char*argv[]) {
   float *vetor; //vetor que será gerada
   long int n; //qtde de elementos do vetor
   float elem; //valor gerado para incluir no vetor
   double soma=0; //soma total dos elementos gerados
   int fator=1; //fator multiplicador para gerar números negativos
   FILE * descritorArquivo; //descritor do arquivo de saida
   size_t ret; //retorno da funcao de escrita no arquivo de saida

   //recebe os argumentos de entrada
   if(argc < 3) {
      fprintf(stderr, "Digite: %s <dimensao> <nome arquivo saida>\n", argv[0]);
      return 1;
   }
   n = atoi(argv[1]);

   //aloca memoria para o vetor
   vetor = (float*) malloc(sizeof(float) * n);
   if(!vetor) {
      fprintf(stderr, "Erro de alocao da memoria do vetor\n");
      return 2;
   }

   //preenche o vetor com valores float aleatorios
   srand(time(NULL));
   for(long int i=0; i<n; i++) {
        elem = (rand() % MAX)/3.0 * fator;
        vetor[i] = elem;
        soma += elem; //acumula o elemento na soma total
        fator*=-1;
   }

   //imprimir na saida padrao o vetor gerado
   #ifdef LOG
   fprintf(stdout, "%ld\n", n);
   for(long int i=0; i<n; i++) {
      fprintf(stdout, "%f ",vetor[i]);
   }
   fprintf(stdout, "\n");
   fprintf(stdout, "%lf\n", soma);
   #endif

   //escreve o vetor no arquivo
   //abre o arquivo para escrita binaria
   descritorArquivo = fopen(argv[2], "wb");
   if(!descritorArquivo) {
      fprintf(stderr, "Erro de abertura do arquivo\n");
      return 3;
   }
   //escreve a dimensao
   ret = fwrite(&n, sizeof(long int), 1, descritorArquivo);
   //escreve os elementos do vetor
   ret = fwrite(vetor, sizeof(float), n, descritorArquivo);
   if(ret < n) {
      fprintf(stderr, "Erro de escrita no  arquivo\n");
      return 4;
   }
   //escreve o somatorio
   ret = fwrite(&soma, sizeof(double), 1, descritorArquivo);

   //finaliza o uso das variaveis
   fclose(descritorArquivo);
   free(vetor);
   return 0;
} 
