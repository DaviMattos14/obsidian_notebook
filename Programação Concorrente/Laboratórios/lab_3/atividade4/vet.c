#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr,"Uso: %s <dimensao_vetor> <arquivo_saida>\n", argv[0]);
        return 1;
    }

    long int dim = atol(argv[1]);
    // Alocando memoria
    float *vetorA = (float *)malloc(dim * sizeof(float));
    float *vetorB = (float *)malloc(dim * sizeof(float));
    if (!vetorA  || !vetorB) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        return 2;
    }

    srand(time(NULL));
    for (long int i = 0; i < dim; i++) {
        vetorA[i] = (float)rand() / (float)RAND_MAX; // Valor aleatório para A
        vetorB[i] = (float)rand() / (float)RAND_MAX; // Valor aleatório para B
    }

    float prod_interno = 0.0f;
    for (long int i = 0; i < dim; i++) {
        prod_interno += vetorA[i] * vetorB[i]; // C[i] = A[i] * B[i]
    }
    printf("Dimensao: %ld\n", dim);
    printf("Vetor A: [ ");
    for(int i = 0; i<dim;i++){
        if(i>0) printf(", ");
        printf("%f",vetorA[i]);
        if(i+1 == dim) printf(" ]\n");
    }
    printf("Vetor B: [ ");
    for(int i = 0; i<dim;i++){
        if(i>0) printf(", ");
        printf("%f",vetorB[i]);
        if(i+1 == dim) printf(" ]\n");
    }
    printf("Produto Interno: %f\n", prod_interno);

    FILE *arquivo = fopen(argv[2], "wb"); // Abrindo arquivo
    if (!arquivo) {
        fprintf(stderr,"Erro ao abrir o arquivo para escrita.\n");
        return 3;
    }

    
    fwrite(&dim, sizeof(long int), 1, arquivo); // Dimensão
    
    fwrite(vetorA, sizeof(float), dim, arquivo); // Vetor A
    
    fwrite(vetorB, sizeof(float), dim, arquivo); // Vetor B
    
    fwrite(&prod_interno, sizeof(float), 1, arquivo); // Produto Interno

    fclose(arquivo);
    free(vetorA);
    free(vetorB);

    printf("Sucesso\n");

    return 0;
}