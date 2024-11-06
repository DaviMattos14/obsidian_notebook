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

/*
    FAZ A LEITURA DO ARQUIVO .CSV E SALVA EM UM STRUCT
*/
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

/*
    ATUALIZA A FILA DE PROCESSOS APÓS O PROCESSO EM EXECUÇÃO TERMINAR (FIM DO TIME SLICE OU FIM DE PROCESSO)
*/
void atualiza_fila(Processo p[], int processo_em_execucao)
{
    Processo aux = p[0];
    for (int i = 0; i < processo_em_execucao - 1; i++)
    {
        p[i] = p[i + 1];
    }
    p[processo_em_execucao - 1] = aux;
}

/*
    IMPRIMIR TABELA DE PROCESSOS
*/
void imprimir(Processo p[], int processo_em_execucao)
{
    for (int i = 0; i < processo_em_execucao; i++)
    {
        printf("Processo: %s \tTempo de Execucao: %d\tTempo de Chegada: %d\tPrioridade: %d\n",
               p[i].processo, p[i].t_servico, p[i].t_chegada, p[i].prioridade);
    }
    printf("\n\n");
}

/*
    VERIFICA A CHEGADA DE UM NOVO PROCESSO E O COLOCA NA FILA
*/
int chegada(Processo p[], Processo fila[], int ut, int processos_em_execucao, int tempo_execucao)
{
    int aux = processos_em_execucao;
    for (int i = 0; i < NUM_PROCESSOS; i++)
    {
        if (ut == p[i].t_chegada || (ut > p[i].t_chegada && p[i].t_chegada > (ut - tempo_execucao)))
        {
            fila[aux] = p[i];
            aux++;
        }
    }
    return aux;
}

/*
    EXECUTA O ALGORITMO DE ROUND ROBIN COM QUANTUM = 5 E SALVA A SAÍDA EM UM .TXT
*/
void round_robin(Processo p[])
{
    int ut = 0;
    int tempo_execucao = 0;
    int processos_em_execucao = 0;

    Processo fila[NUM_PROCESSOS];

    processos_em_execucao = chegada(p, fila, ut, processos_em_execucao, tempo_execucao);
    FILE *saida = fopen("Saida.txt", "a+");
    char linha[MAX];
    while (1)
    {
        // imprimir(fila, processos_em_execucao);   -   IMPRIMIR A FILA NO PROMPT
        tempo_execucao++;
        ut++;
        fila[0].t_servico--;
        if (fila[0].t_servico == 0)
        {
            sprintf(linha, "U.T= %d~%d|\t O Processo %s executou por %ds e Terminou\n", (ut - tempo_execucao), ut, fila[0].processo, tempo_execucao);
            fputs(linha, saida);
            if (processos_em_execucao > 1)
            {
                atualiza_fila(fila, processos_em_execucao);
            }
            tempo_execucao = 0;
            processos_em_execucao--;
            if (processos_em_execucao == 0)
            {
                fclose(saida);
                break;
            }

            continue;
        }
        if (tempo_execucao == QUANTUM)
        {
            processos_em_execucao = chegada(p, fila, ut, processos_em_execucao, tempo_execucao);
            sprintf(linha, "U.T= %d~%d|\t O Processo %s executou por %ds e foi para Baixa prioridade\n", (ut - tempo_execucao), ut, fila[0].processo, tempo_execucao);
            fputs(linha, saida);
            if (processos_em_execucao > 1)
            {
                atualiza_fila(fila, processos_em_execucao);
            }

            tempo_execucao = 0;
        }
    }
}

/*
    FUNÇÃO PRINCIPAL, CRIA O ARQUIVO SAIDA.TXT, SALVA A TABELA E CHAMA O ALGORITMO
*/
int main()
{
    Processo processos[NUM_PROCESSOS];
    int n = lerCSV(processos);
    FILE *saida = fopen("Saida.txt", "w+");
    char linha[MAX];
    sprintf(linha, "\tNum Processsos:%d\t\tQuantum: %d\n", n, QUANTUM);
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