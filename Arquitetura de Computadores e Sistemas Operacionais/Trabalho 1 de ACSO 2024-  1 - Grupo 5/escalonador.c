#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_PROCESSOS 10
#define MAX 256
#define QUANTUM 5

typedef struct
{
    char processo[3];
    int t_chegada;
    int prioridade;
    int t_servico;
} Processo;

int lerCSV(Processo p[])
{
    FILE *arq = fopen("processos.csv", "r");
    if (arq == NULL)
    {
        printf("Não é possível abrir o arquivo\n");
        return 1;
    }

    char linha[MAX];
    int i = 0;

    fgets(linha, MAX, arq);

    while (!feof(arq))
    {
        fgets(linha, MAX, arq);
        char *leitura = strtok(linha, ";");
        strcpy(p[i].processo, leitura);

        leitura = strtok(NULL, ";");
        p[i].t_chegada = atoi(leitura);

        leitura = strtok(NULL, ";");
        p[i].prioridade = atoi(leitura);

        leitura = strtok(NULL, ";");
        p[i].t_servico = atoi(leitura);
        i++;
    }
    fclose(arq);
    return i;
}

int main()
{
    Processo processos[MAX];
    int n = lerCSV(processos);

    printf("Processo: %s \tTempo de Chegada: %d\tPrioridade: %d\tTempo de Execucao: %d",
           processos[2].processo, processos[2].t_chegada, processos[2].prioridade, processos[2].t_servico);
    /*
     */
    return 0;
}