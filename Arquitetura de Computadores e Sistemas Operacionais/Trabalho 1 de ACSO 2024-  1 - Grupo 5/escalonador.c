#include <stdio.h>

int main(){

    FILE *fp = fopen("Tabela_Processos.csv", "r");
    if (!fp) {
        printf("Não é possível abrir o arquivo\n");
        return 1;
    }

    char buf[1024];
    while (fgets(buf, 1024, fp)) {
        char *campo = strtok(buf, ",");
        while(campo) {
            printf("%s\n", campo);
            campo = strtok(NULL, ",");
        }
    }


// Create a file
    FILE *fptr = fopen("saida.txt", "w");

// Write some text to the file
    fprintf(fptr, buf); 

// Close the file
    fclose(fp);
    fclose(fptr);
    return 0;
}