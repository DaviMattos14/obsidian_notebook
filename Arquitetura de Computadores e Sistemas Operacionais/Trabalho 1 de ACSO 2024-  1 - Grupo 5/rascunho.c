#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_PROCESSOS 5
#define MAX 512
#define QUANTUM 4
#define A 7 
#define B 4
#define C 3


/*
    CRITANDO A ESTRUTURA I/O
*/
typedef struct entrada_saida
{
    int chegada;
    char tipo[2];
} ES;

/*
    CRITANDO A ESTRUTURA Processo
*/
typedef struct Processo
{
    char processo[3];
    int t_chegada;
    int t_servico;
    struct entrada_saida operacoes_io[MAX];
    int num_io;
} Processo;

/*IMPRIMINDO A TABELA NO ARQUIVO DE SAIDA*/
void imprimir_processos(const char *filename, Processo p[])
{
    FILE *arq = fopen("Saida.txt", "w+");
    fputs("\t TABELA\n", arq);
    fputs("\tNumero de Processos: 5\n", arq);
    for (int i = 0; i < 5; i++)
    {
        char saida[MAX] = "";
        sprintf(saida, "\tProcesso: %s \tTempo de Execucao: %d\tTempo de Chegada: %d\t Nº I/O:%d\t", p[i].processo, p[i].t_servico, p[i].t_chegada, p[i].num_io);
        if (p[i].num_io > 0)
        {
            char tempo[64] = "Tempo de Chamada I/O: ";
            char tipo[64] = "Tipo I/O: ";
            for (int j = 0; j < p[i].num_io; j++)
            {
                char converte[2];
                sprintf(converte, "%d", p[i].operacoes_io[j].chegada);
                strcat(tempo, converte);
                strcat(tipo, p[i].operacoes_io[j].tipo);
                if (j < p[i].num_io - 1)
                {
                    strcat(tempo, ", ");
                    strcat(tipo, ", ");
                }
            }
            strcat(tempo, "\t\t");
            strcat(tempo, tipo);
            strcat(saida, tempo);
        }
        strcat(saida, "\n");
        fputs(saida, arq);
    }
    fputs("\n\n", arq);
    fclose(arq);
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
            fputs(texto, saida);
        }
    }
    return aux;
}

int chamada_io(Processo p, int ut, int te){
    if (p.num_io == 0)
    {
        return 0; // 0 para caso o processo não tenha chamada de I/O
    }
    else
    {
        for (int i = 0; i < p.num_io; i++)
        {
            if ((ut - te) < p.operacoes_io[i].chegada && p.operacoes_io[i].chegada<= te)
            {
                return 1; // 1 PARA PROCESSOS QUE DEVEM SER INTERROMPRIDOS PARA EXECUTAR I/O
            }
        }
        return 2; // PARA PROCESSO QUE APÓS TERMINAREM SEU QUANTUM DEVEM SER BLOQUEADOS PARA EXECUTAR I/O
    }
    
}

/*  VERIFICA SE O PROCESSO P TEM CHAMADA DE IO E O COLOCA NA FILA DE IO (BLOQUEIA ELE)*/
int verifica_io(FILE *filename, Processo p, Processo io[], int bloqueados, int ut){
    if (p.num_io == 0)
    {
        return bloqueados;
    }
    else
    {
        char texto[256];
        for (int i = 0; i < p.num_io; i++)
        {
            if(p.operacoes_io[i].chegada < ut){
                io[bloqueados] = p;
                io[bloqueados].t_chegada = ut;
                if (strcmp(p.operacoes_io[i].tipo, "A") ==0)
                {
                    io[bloqueados].t_servico = A;
                    sprintf(texto, "U.T: %d|\tO Processo %s está executando I/O e foi bloqueado (Tempo: %d)\n", ut, p.processo, A);
                    fputs(texto, filename);
                }
                else if (strcmp(p.operacoes_io[i].tipo, "B") ==0)
                {
                    io[bloqueados].t_servico = B;
                    sprintf(texto, "U.T: %d|\tO Processo %s está executando I/O e foi bloqueado (Tempo: %d)\n", ut, p.processo, B);
                    fputs(texto, filename);
                }else if (strcmp(p.operacoes_io[i].tipo, "C") ==0)
                {
                    io[bloqueados].t_servico = C;
                    sprintf(texto, "U.T: %d|\tO Processo %s está executando I/O e foi bloqueado (Tempo: %d)\n", ut, p.processo, C);
                    fputs(texto, filename);
                }
            }
        }
    }
    return bloqueados+1;
}
/*
    EXECUTA O ALGORITMO DE ROUND ROBIN E SALVA A SAÍDA EM UM .TXT
*/
void round_robin(const char *filename, Processo p[])
{
    int ut = 0;                    // Contador de Unidade de Tempo
    int tempo_execucao = 0;        // Contador de Tempo de Execução de Processo
    int processos_em_execucao = 0; // Contador de Processos em Execução
    int processos_bloqueados = 0; // Contador de Processos Bloqueados

    Processo fila_alta[NUM_PROCESSOS];  // Fila de Alta Prioridade
    Processo fila_baixa[NUM_PROCESSOS]; // Fila de Baixa Prioridade
    Processo fila_io[NUM_PROCESSOS];    // Fila de I/O

    FILE *saida = fopen(filename, "a+");
    fputs("\t\tINICIO DE EXECUÇÃO\n", saida);

    processos_em_execucao = chegada(saida, p, fila_alta, ut, processos_em_execucao, tempo_execucao); /*
        Verifica se algum processo chegou na unidade de tempo "ut", e o coloca na fila de alta prioridade
    */
    char linha[MAX];
    while (1) /* LOOP INIFINITO DE EXECUÇÃO*/
    {
        tempo_execucao++;
        ut++;
        fila_alta[0].t_servico--;
        int tem_io = chamada_io(fila_alta[0], ut, tempo_execucao);

        if (fila_alta[0].t_servico == 0) /*  VERIFICA SE O PROCESSO TERMINOU   */
        {
            sprintf(linha, "U.T= %d-%d|\t O Processo %s executou por %ds e Terminou\n", (ut - tempo_execucao), ut, fila_alta[0].processo, tempo_execucao);
            fputs(linha, saida);
            if (processos_em_execucao > 1) /* SE HOUVER PROCESSO EM EXECUÇÃO ... */
            {
                atualiza_fila(fila_alta, processos_em_execucao); /* CHAMA  O PROXIMO PROCESS0 */
            }
            tempo_execucao = 0;             /* REINICIA O TEMPO DE EXECUÇÃO DO PROCESSO */
            processos_em_execucao--;        /* ATUALIZA O CONTADOR */
            if (processos_em_execucao == 0) /* SE NÃO HOUVER PROCESSO EM EXECUÇÃO...*/
            {
                fclose(saida);
                break; /* TERMINA */
            }

            continue; /* SE AINDA HOUVER VÁ PARA O PROXIMO */
        }
        if (tempo_execucao == QUANTUM) /* SE O PROCESSO EXECUTOU A FATIA DE TEMPO DELE */
        {
            sprintf(linha, "U.T= %d-%d|\t O Processo %s sofreu preempção (Tempo restante: %d)\n", (ut - tempo_execucao), ut, fila_alta[0].processo, fila_alta[0].t_servico);
            fputs(linha, saida);
            processos_em_execucao = chegada(saida, p, fila_alta, ut, processos_em_execucao, tempo_execucao); /* VERIFICA SE CHEGOU ALGUM PROCESSO DURANTE A EXECUÇÃO */
            if (processos_em_execucao > 1)
            {
                atualiza_fila(fila_alta, processos_em_execucao); /* CHAMA O PRÓXIMO PROCESSO*/
            }

            tempo_execucao = 0; /* REINICIA O TEMPO */
        }
    }
}

int main()
{
    const char *arquivo_saida = "Saida.txt";
    const char *arquivo_leitura = "processos.txt";
    Processo p[] = {
        {"P1", 0, 13, {{4, "A"}}, 1},
        {"P2", 4, 11, {{2, "B"}, {6, "A"}}, 2},
        {"P3", 5, 7, {{-1, ""}}, 0},
        {"P4", 7, 8, {{-1, ""}}, 0},
        {"P5", 10, 16, {{2, "A"}, {7, "B"}}, 2}}; /* TABELA INICIALIZADA DIRETAMENTE POR QUE LER .CSV EM C É UM CU */
    imprimir_processos(arquivo_saida, p);         /* IMPRIME A TABELA NO ARQUIVO DE SAÍDA*/
    round_robin(arquivo_saida, p);                /* CHAMA O ALGORITMO DE RR */
    return 0;
}

/*
            if (fila1->tipo == Baixa)
            {
                printf("oi");
                sprintf(linha, "U.T= %d-%d|\t O Processo %s sofreu preempção (Tempo restante: %d)\n", (ut - tempo_execucao), ut, fila1->processo.processo, fila1->processo.t_servico);
                fputs(linha, arq);
                fila1 = retira_da_fila(fila1);
                fila1 = adiciona_na_fila(fila1, preemp, Baixa); // DEIXA O PROCESSO NA FILA DE BAIXA  
            }
            */