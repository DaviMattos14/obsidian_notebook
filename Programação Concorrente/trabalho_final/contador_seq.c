#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char *separadores = " \t\n\r.,;:!?\"'()[]{}*";

int main(int argc, char *argv[])
{

    FILE *arq;

    if (argc < 3)
    {
        printf("Error! digite %s <nome_do_arquivo.txt> <tam_buffer>\n", argv[0]);
        return 1;
    }

    arq = fopen(argv[1], "r");
    if (arq == NULL)
    {
        printf("--ERRO: fopen()\n");
        exit(-1);
    }

    int buffer = atoi(argv[2]);
    if (buffer <= 0)
    {
        printf("--ERRO: Tamanho de buffer inválido\n");
        exit(-1);
    }

    char *texto;
    texto = (char *)malloc(buffer * sizeof(char));
    if (texto == NULL)
    {
        printf("--ERRO: Falha ao alocar memoria.\n");
        fclose(arq);
        exit(1);
    }

    int contador = 0;
    while (fgets(texto, buffer, arq))
    {
        char *palavra = strtok(texto, separadores);
        while (palavra != NULL)
        {
            contador++;
            palavra = strtok(NULL, separadores);
        }
    }

    printf("Arquivo: %s\tNumero de palavras: %d\n", argv[1], contador);

    free(texto);
    fclose(arq);

    return 0;
}