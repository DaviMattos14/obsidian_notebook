#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_PROCESSOS 5
#define MAX 512
#define QUANTUM 4

/*
    CRITANDO A ESTRUTURA I/O
*/
typedef struct entrada_saida
{
    int chegada;
    char tipo[2];
    struct entrada_saida *prox;
} ES;

/*
    CRITANDO A ESTRUTURA DO PROCESSO
*/
typedef struct Processo
{
    char processo[3];
    int t_chegada;
    int t_servico;
    struct entrada_saida *operacoes_io;
    int num_io;
} Processo;

enum tipo_fila
{
    Alta,
    Baixa,
    IO
}; // 0 PARA ALTA - 1 PARA BAIXA - 2 PARA I/O
/*
    CRIANDO A ESTUTURA DA FILA
*/
typedef struct Fila
{
    Processo processo;
    int tipo;
    struct Fila *prox;
} Fila;

/* CRIANDO A CHAMADA DE I/O*/
ES *cria_io(const char *tipo, int t_chegada)
{
    ES *temp = (ES *)malloc(sizeof(ES));
    temp->chegada = t_chegada;
    strncpy(temp->tipo, tipo, 2);
    temp->prox = NULL;
    return temp;
}

/* INSERINDO A(S) CHAMADA(S) DE I/O(S) NA ESTRUTURA DO PROCESSO*/
ES *inserir_io(ES *head, int t_chegada, const char *tipo)
{
    if (head == NULL)
    {
        return cria_io(tipo, t_chegada);
        ;
    }
    else
    {
        ES *atual = head;
        while (atual->prox != NULL)
        {
            atual = atual->prox;
        }
        atual->prox = cria_io(tipo, t_chegada);
        ;
    }
    return head;
}

/* IMPRIMINDO A(S) CHAMADA(S) DE I/O(S) NO ARQUIVO DE SAIDA*/
void imprimir_io(FILE *arq, ES *head)
{
    ES *ptcab = head;

    char saida[MAX] = "";
    char tempo[64] = "Tempo de Chamada I/O: ";
    char tipo[64] = "Tipo I/O: ";

    while (ptcab != NULL)
    {
        char converte[2];
        sprintf(converte, "%d", ptcab->chegada);
        strcat(tempo, converte);
        strcat(tipo, ptcab->tipo);
        if (ptcab->prox != NULL)
        {
            strcat(tempo, ", ");
            strcat(tipo, ", ");
        }
        ptcab = ptcab->prox;
    }
    strcat(tempo, "\t");
    strcat(tempo, tipo);
    strcat(saida, tempo);
    strcat(saida, "\n");
    fputs(saida, arq);
}

/* IMPRIMINDO A "TABELA" DE PROCESSOS NO ARQUIVO DE SAIDA */
void imprimir_tabela_processos(const char *filename, Processo p[])
{
    FILE *arq = fopen(filename, "w+");
    fputs("\t TABELA\n", arq);
    fputs("\tNumero de Processos: 5\n", arq);
    for (int i = 0; i < 5; i++)
    {
        char saida[MAX] = "";
        sprintf(saida, "\tProcesso: %s \tTempo de Execucao: %d\tTempo de Chegada: %d\t ", p[i].processo, p[i].t_servico, p[i].t_chegada);
        fputs(saida, arq);
        if (p[i].num_io != 0)
        {
            imprimir_io(arq, p[i].operacoes_io);
        }
        if (p[i].num_io == 0)
        {
            fputs("Tempo de Chamada I/O: - \tTipo I/O: -\n", arq);
        }
    }
    fputs("\n\n", arq);
    fclose(arq);
}

/*
    CRIA O ELEMENTO DA FILA
*/
Fila *inicia_a_fila(Processo p, int tipo)
{
    Fila *novo_elemento = (Fila *)malloc(sizeof(Fila));
    novo_elemento->processo = p;
    novo_elemento->tipo = tipo;
    novo_elemento->prox = NULL;
    return novo_elemento;
}

/*
    ADICIONA O PROCESSO NA FILA
*/
Fila *adiciona_na_fila(Fila *inicio, Processo p, int tipo)
{
    if (inicio == NULL)
    {
        return inicia_a_fila(p, tipo);
    }
    else
    {
        Fila *atual = inicio;
        while (atual->prox != NULL)
        {
            atual = atual->prox;
        }
        atual->prox = inicia_a_fila(p, tipo);
    }
    return inicio;
}

Fila *retira_da_fila(Fila *inicio)
{
    if (inicio == NULL)
        return NULL;
    Fila *temp = inicio;
    inicio = inicio->prox;
    free(temp);
    return inicio;
}

/*VARIAVEL GLOBAL PRA CONTAR O TEMPO E VERIFICAR OS PROCESSOS EM EXECUÇÃO*/
int ut = 0;
int processos_em_execucao = 0;

int chegada(FILE *saida, Processo p[], Fila **fila, int tempo_execucao)
{
    char texto[256];
    int aux = processos_em_execucao;
    for (int i = 0; i < NUM_PROCESSOS; i++)
    {
        if (ut == p[i].t_chegada || (ut > p[i].t_chegada && p[i].t_chegada > (ut - tempo_execucao)))
        {
            *fila = adiciona_na_fila(*fila, p[i], Alta);
            aux++;
            sprintf(texto, "U.T: %d|\tO Processo %s chegou no processador\n", p[i].t_chegada, p[i].processo);
            fputs(texto, saida);
        }
    }
    return aux;
}

void round_robin(const char *filename, Processo p[], Fila *fila1, Fila *fila2, Fila *ios)
{
    FILE *arq = fopen(filename, "a+");

    int tempo_execucao = 0;
    char linha[MAX];

    processos_em_execucao = chegada(arq, p, &fila1, tempo_execucao);
    while (1)
    {
        tempo_execucao++;
        ut++;
        fila1->processo.t_servico--;

        Processo preemp = fila1->processo;
        
        if (preemp.num_io != 0)
        {
            if (preemp.operacoes_io->chegada == ut)
            {
                puts("tem chamada\n");
            }
        }
        

        if (fila1->processo.t_servico == 0)
        {
            sprintf(linha, "U.T= %d-%d|\t O Processo %s executou por %ds e Terminou\n", (ut - tempo_execucao), ut, fila1->processo.processo, tempo_execucao);
            fputs(linha, arq);
            if (fila1->prox == NULL)
            {
                fclose(arq);
                break;
            }
            fila1 = retira_da_fila(fila1);
            tempo_execucao = 0;
            processos_em_execucao--;
            continue;
        }

        
        if (tempo_execucao == QUANTUM)
        {
            
            if (fila1->tipo == Baixa)
            {
                sprintf(linha, "U.T= %d-%d|\t O Processo %s sofreu preempção (Tempo restante: %d)\n", (ut - tempo_execucao), ut, fila1->processo.processo, fila1->processo.t_servico);
                fputs(linha, arq);
                fila1 = retira_da_fila(fila1);
                fila1 = adiciona_na_fila(fila1, preemp, Baixa); // DEIXA O PROCESSO NA FILA DE BAIXA  
            }

            if (fila1->tipo == Alta)
            {
                sprintf(linha, "U.T= %d-%d|\t O Processo %s sofreu preempção e foi pra fila de Baixa (Tempo restante: %d)\n", (ut - tempo_execucao), ut, fila1->processo.processo, fila1->processo.t_servico);
                fputs(linha, arq);
                fila1 = retira_da_fila(fila1);                
                fila2 = adiciona_na_fila(fila2, preemp, Baixa); // COLOCA O PROCESSO NA FILA DE BAIXA
            }
            processos_em_execucao = chegada(arq, p, &fila1, tempo_execucao);
            tempo_execucao = 0;

        if (fila1 == NULL)
            break;
        }
    }
    fclose(arq);
}

int main()
{
    const char *arquivo_saida = "Saida.txt";

    /* TABELA INICIALIZADA DIRETAMENTE*/
    Processo p[] = {
        {"P1", 0, 13, NULL, 1},
        {"P2", 4, 11, NULL, 2},
        {"P3", 5, 7, NULL, 0},
        {"P4", 7, 8, NULL, 0},
        {"P5", 10, 16, NULL, 2}};

    /* CRIANDO OS CHAMADOS DE I/O*/
    p[0].operacoes_io = inserir_io(p[0].operacoes_io, 4, "A");
    p[1].operacoes_io = inserir_io(p[1].operacoes_io, 2, "B");
    p[1].operacoes_io = inserir_io(p[1].operacoes_io, 6, "A");
    p[4].operacoes_io = inserir_io(p[4].operacoes_io, 2, "A");
    p[4].operacoes_io = inserir_io(p[4].operacoes_io, 7, "B");

    /* IMPRIMINDO A TABELA NO ARQUIVO DE SAIDA*/
    imprimir_tabela_processos(arquivo_saida, p);

    /* CRIDANDO AS FILA */
    Fila *fila_alta = NULL;
    Fila *fila_baixa = NULL;
    Fila *fila_io = NULL;

    round_robin(arquivo_saida, p, fila_alta, fila_baixa, fila_io);

    
    return 0;
}