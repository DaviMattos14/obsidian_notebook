#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_PROCESSOS 5
#define MAX 256
#define QUANTUM 4

/*
    CRITANDO A ESTRUTURA PROCESSO
*/
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
/*
    LENDO AS LINHAS DO ARQUIVO .CSV
*/
    while (!feof(arq))
    {
        fgets(linha, MAX, arq);
        char *leitura = strtok(linha, ";");/* DIVIDE STRING LINHA PELO DELIMITADOR ';' E PEGA A PRIMEIRA STRING*/
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
    ATUALIZA A FILA 
    COLOCA O PROCESSO NA POSIÇÃO [0] PARA O FIM DA FILA 
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
    VERIFICA A CHEGADA DE UM NOVO PROCESSO DURANTE O TIME SLICE E O COLOCA NA FILA
*/
int chegada(FILE *saida, Processo p[], Processo fila[], int ut, int processos_em_execucao, int tempo_execucao)
{
    char texto[256];
    int aux = processos_em_execucao;
    for (int i = 0; i < NUM_PROCESSOS; i++)
    {
        if (ut == p[i].t_chegada || (ut > p[i].t_chegada && p[i].t_chegada > (ut - tempo_execucao)))
        {
            fila[aux] = p[i];
            aux++;
            sprintf(texto, "U.T: %d|\tO Processo %s chegou no processador\n", p[i].t_chegada, p[i].processo);
            fputs(texto,saida);
        }
    }
    return aux;
}

/*
    EXECUTA O ALGORITMO DE ROUND ROBIN E SALVA A SAÍDA EM UM .TXT
*/
void round_robin(Processo p[])
{
    int ut = 0;
    int tempo_execucao = 0;
    int processos_em_execucao = 0;

    Processo fila[NUM_PROCESSOS];
    FILE *saida = fopen("Saida.txt", "a+");
    fputs("\t\tINICIO DE EXECUÇÃO\n",saida);

    processos_em_execucao = chegada(saida, p, fila, ut, processos_em_execucao, tempo_execucao);
    char linha[MAX];
    while (1)
    {
        // imprimir(fila, processos_em_execucao);   -   IMPRIMIR A FILA NO PROMPT
        tempo_execucao++;
        ut++;
        fila[0].t_servico--;
        if (fila[0].t_servico == 0)
        {
            sprintf(linha, "U.T= %d-%d|\t O Processo %s executou por %ds e Terminou\n", (ut - tempo_execucao), ut, fila[0].processo, tempo_execucao);
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
            sprintf(linha, "U.T= %d-%d|\t O Processo %s sofreu preempção (Tempo restante: %d)\n", (ut - tempo_execucao), ut, fila[0].processo,  fila[0].t_servico);
            fputs(linha, saida);
            processos_em_execucao = chegada(saida, p, fila, ut, processos_em_execucao, tempo_execucao);
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
    fputs("\t TABELA\n",saida);
    
    char linha[MAX];
    for (int i = 0; i < n; i++)
    {
        sprintf(linha, "\tProcesso: %s \t\tTempo de Execucao: %d\t\tTempo de Chegada: %d\t\tPrioridade: %d\n",
                processos[i].processo, processos[i].t_servico, processos[i].t_chegada, processos[i].prioridade);
        fputs(linha, saida);
    }
    sprintf(linha, "\tNum Processsos:%d\t\tQuantum: %d\n", n, QUANTUM);
    fputs(linha, saida);
    fputs("\n\n",saida);
    fclose(saida);
    
    round_robin(processos); /* CHAMA A EXECUÇÃO DO ROUND ROBIN*/

    return 0;
}