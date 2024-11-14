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
    struct entrada_saida* prox;
} ES;

/*
    CRITANDO A ESTRUTURA Processo
*/
typedef struct Processo
{
    char processo[3];
    int t_chegada;
    int t_servico;
    struct entrada_saida* operacoes_io;
    int num_io;
} Processo;

typedef struct Fila{
    Processo processo;
    struct Fila* prox;
}Fila;


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


void inserir_io(ES* io, int tempo, char tipo[]){
    ES* nova_chamada = (ES*) malloc(sizeof(ES));
    nova_chamada->chegada= tempo;
    strcpy(tipo,nova_chamada->tipo);
    nova_chamada->prox=NULL;
    if (io == NULL)
    {
        io = nova_chamada;
    }else if (io != NULL)
    {
        while (io->prox!=NULL)
        {
            io = io->prox;
        }
        io->prox = nova_chamada;
    }
    
    
}

void colocar_na_fila(Fila* fila, Processo p){
    Fila* novo_elemento = (Fila*) malloc(sizeof(Fila));
    novo_elemento->processo=p;
    while (fila->prox!=NULL)
    {
        fila = fila->prox;
    }
    fila->prox=novo_elemento;
    novo_elemento->prox=NULL;
}
Fila* remover_da_fila(Fila* fila){
    if(fila == NULL) return NULL;

    Fila* temp = fila;
    fila = fila->prox;
    free(temp);
    return fila;
}

void chegada(FILE *saida, Processo p[], Fila* fila, int ut, int tempo_execucao)
{
    char texto[256];
    for (int i = 0; i < NUM_PROCESSOS; i++)
    {
        if (ut == p[i].t_chegada || (ut > p[i].t_chegada && p[i].t_chegada > (ut - tempo_execucao)))
        {
            colocar_na_fila(fila, p[i]);
            sprintf(texto, "U.T: %d|\tO Processo %s chegou no processador\n", p[i].t_chegada, p[i].processo);
            fputs(texto,saida);
        }
    }
}

int bloqueado(Fila* io, Processo p){
    while (io != NULL)
    {
        if (strcmp(io->processo.processo,p.processo)==0)
        {
            return 1; // BLOQUEADO
        }
        io = io->prox;
    }
    return 0; // NÃO ESTÁ BLOQUEADO
}

int round_robin(const char *filename, Fila* fila1, Fila* fila2, Processo p[], int ut){
    int tempo_execucao = 0;
    char linha[MAX];
    FILE *arquivo = fopen(filename, "a+");

    fputs("\t\tINICIO DE EXECUÇÃO\n", arquivo);

    chegada(arquivo, p, fila1, ut, tempo_execucao); /* Verifica se algum processo chegou durante o tempo de execução*/

    while (1)
    {
        tempo_execucao++;
        ut++;
        fila1->processo.t_servico--;

        if (fila1->processo.t_servico == 0)
        {
            sprintf(linha, "U.T= %d-%d|\t O Processo %s executou por %ds e Terminou\n", (ut - tempo_execucao), ut, fila1->processo.processo, tempo_execucao);
            fputs(linha, arquivo);
            remover_da_fila(fila1);
            tempo_execucao = 0;             /* REINICIA O TEMPO DE EXECUÇÃO DO PROCESSO */
            if (fila1 == NULL) /* SE NÃO HOUVER PROCESSO EM EXECUÇÃO...*/
            {
                fclose(arquivo);
                break; /* TERMINA */
            }

            continue; /* SE AINDA HOUVER VÁ PARA O PROXIMO */
        }
        if (tempo_execucao == QUANTUM) /* SE O PROCESSO EXECUTOU A FATIA DE TEMPO DELE */
        {
            sprintf(linha, "U.T= %d-%d|\t O Processo %s sofreu preempção (Tempo restante: %d)\n", 
                (ut - tempo_execucao), ut, fila1->processo.processo, fila1->processo.t_servico);
            fputs(linha, arquivo);
            chegada(arquivo, p, fila1, ut, tempo_execucao);
            colocar_na_fila(fila2, fila1->processo); /* Diminui a prioridade */
            tempo_execucao = 0; /* REINICIA O TEMPO */
        }
    }
    return ut;
}

void Imprime_Lista_Encadeada(ES *pt) {
  while (pt != NULL) {
    printf("%d - %s\n", pt->chegada, pt->tipo);
    pt = pt->prox;
  }
}

int main()
{
    const char *arquivo_saida = "Saida.txt";
    // const char *arquivo_leitura = "processos.txt";
    Processo p[] = {
        {"P1", 0, 13, NULL, 1},
        {"P2", 4, 11, NULL, 2},
        {"P3", 5, 7, NULL, 0},
        {"P4", 7, 8, NULL, 0},
        {"P5", 10, 16, NULL, 2}}; /* TABELA INICIALIZADA DIRETAMENTE POR QUE LER .CSV EM C É UM CU */
        
    inserir_io(p[0].operacoes_io,4,"A");
    inserir_io(p[1].operacoes_io,2,"B");
    inserir_io(p[1].operacoes_io,6,"A");
    inserir_io(p[4].operacoes_io,2,"A");
    inserir_io(p[4].operacoes_io,7,"B");
    //imprimir_processos(arquivo_saida, p);         /* IMPRIME A TABELA NO ARQUIVO DE SAÍDA*/
    
    //Fila *fila_alta = (Fila*) malloc(sizeof(Fila));
    //Fila *fila_baixa = (Fila*) malloc(sizeof(Fila));
    //Fila *fila_io = (Fila*) malloc(sizeof(Fila));
    
    //int ut = 0;
    //ut = round_robin(arquivo_saida,fila_alta, fila_baixa, p, ut); /* CHAMA O ALGORITMO DE RR */
    return 0;
}