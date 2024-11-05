#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_PROCESSOS 5
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
        p[i].t_servico = atoi(leitura);

        leitura = strtok(NULL, ";");
        p[i].t_chegada = atoi(leitura);

        leitura = strtok(NULL, ";");
        p[i].prioridade = atoi(leitura);
        i++;
    }
    fclose(arq);
    return i;
}
void atualiza_fila(Processo p[], int processo_em_execucao){
    Processo aux = p[0];
    for (int i = 0; i < processo_em_execucao-1; i++)
    {
        p[i] = p[i+1];
    }
    p[processo_em_execucao-1] = aux;
/*
    for (int i = 0; i < NUM_PROCESSOS; i++)
    {
        printf("Processo: %s \tTempo de Execucao: %d\tTempo de Chegada: %d\tPrioridade: %d\n",
               p[i].processo, p[i].t_servico, p[i].t_chegada, p[i].prioridade);
    }
*/
}

void round_robin(Processo p[]){
    int ut = 0;
    int tempo_execucao = 0;
    int processos_em_execucao = NUM_PROCESSOS;

    FILE *saida = fopen("Saida.txt","a+");
    char linha[MAX];
    while (1)
    {
        tempo_execucao++;
        ut++;
        p[0].t_servico--;
        if (p[0].t_servico == 0)
        {
            sprintf(linha, "*U.T: %d\t O Processo %s executou por %ds\n", ut, p[0].processo, tempo_execucao);
            fputs(linha, saida);
            atualiza_fila(p, processos_em_execucao);
            tempo_execucao = 0;
            processos_em_execucao--;
            if (processos_em_execucao == 0)
            {
                fclose(saida);
                break;
            }
            
            continue;
        }
        if (tempo_execucao == QUANTUM){
            sprintf(linha, "U.T: %d\t O Processo %s executou por %ds\n", ut, p[0].processo, tempo_execucao);
            fputs(linha, saida);
            atualiza_fila(p, processos_em_execucao);
            tempo_execucao = 0;
        }
        if (ut == 40)
        {
            break;
        }
        
    }
    
}

int main()
{
    Processo processos[NUM_PROCESSOS];
    int n = lerCSV(processos);
    FILE *saida = fopen("Saida.txt","w+");
    char linha[MAX];
    sprintf(linha, "\tNum Processsos:%d\n", n);
    fputs(linha, saida);
    for (int i = 0; i < n; i++)
    {
        sprintf(linha, "\tProcesso: %s \tTempo de Execucao: %d\tTempo de Chegada: %d\tPrioridade: %d\n",
               processos[i].processo, processos[i].t_servico, processos[i].t_chegada, processos[i].prioridade);
        fputs(linha, saida);
    }
    fclose(saida);
    round_robin(processos);

    return 0;
}