#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define NUM_MAX_PROCESSOS 4
#define MAX 512
#define QUANTUM 4

/* TIPOS DE I/O*/
#define DISCO 7 // A
#define FITA_MAGNETICA 4 // B
#define IMPRESSORA 2 // C

/*VARIAVEIS GLOBAL PRA CONTAR O TEMPO E PROCESSOS COMPLETOS*/
int ut = 0; // UT -> UNIDADE DE TEMPO
int processos_completos = 0;


/*
    CRITANDO A ESTRUTURA I/O
*/
typedef struct entrada_saida
{
    int chegada;
    char tipo[2];
    int saida;
    struct entrada_saida *prox;
} ES;

/*
    CRIANDO A ESTRUTURA DO PROCESSO
*/
typedef struct Processo
{
    char pid[3];
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
    temp->saida = 0;
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

/* REMOVENDO A CHAMADA DE I/O DO PROCESSO*/
ES* remover_Io(ES **inicio){
    if (*inicio == NULL)
        return NULL;

    ES *temp = *inicio;
    *inicio = (*inicio)->prox;
    
    return temp;
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
    fputs("\tTABELA\n", arq);
    fprintf(arq, "Numero de Processos: %d\n", NUM_MAX_PROCESSOS);
    for (int i = 0; i < NUM_MAX_PROCESSOS; i++)
    {
        char saida[MAX] = "";
        sprintf(saida, "Processo: %s \tTempo de Execucao: %d\tTempo de Chegada: %d\t ", p[i].pid, p[i].t_servico, p[i].t_chegada);
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
    ADICIONA O PROCESSO NO FIM FILA
*/
void adiciona_fim_fila(Fila **inicio, Processo p, int tipo)
{
    if (*inicio == NULL)
    {
        (*inicio) =  inicia_a_fila(p, tipo);
    }
    else
    {
        Fila *atual = *inicio;
        while (atual->prox != NULL)
        {
            atual = atual->prox;
        }
        atual->prox = inicia_a_fila(p, tipo);
    }
}

/* ADICIONA NO MEIO DA FILA COM BASE NO TEMPO DE CHEGADA/RETORNO E A UT ATUAL*/
void adiciona_meio_fila(Fila **inicio, Processo p, int tipo, int t)
{
    Fila* pos = *inicio;

    // Caso especial: inserir no início se a condição for atendida
    if (*inicio == NULL || (*inicio)->processo.t_chegada >= t)
    {
        Fila* temp = inicia_a_fila(p, tipo);
        temp->prox = *inicio;
        *inicio = temp;
        return;
    }

    // Percorre até encontrar a posição correta
    while (pos->prox != NULL && pos->prox->processo.t_chegada < t)
    {
        pos = pos->prox;
    }

    // Cria o novo nó e insere após 'pos'
    Fila* temp = inicia_a_fila(p, tipo);
    temp->prox = pos->prox;
    pos->prox = temp;
}


/*
    ADICIONA O PROCESSO NO INICIO FILA
*/
void adiciona_inicio_da_fila(Fila** inicio, Processo p, int tipo){
    Fila* atual = inicia_a_fila(p, tipo);
    atual->prox = *inicio;
    *inicio = atual;
}

/* REMOVE UM ELEMENTO DE UMA LISTA ENCADEDA*/
Fila* remove_da_fila(Fila **inicio)
{
    if (*inicio == NULL)
        return NULL;

    Fila *temp = *inicio;
    *inicio = (*inicio)->prox;
    
    return temp;
}

/* VERIFICA O TIPO DE I/O */
int tipo_io(ES** io){
    if (strcmp((*io)->tipo, "A") == 0)
        return DISCO;
    else if (strcmp((*io)->tipo, "B") == 0)
        return FITA_MAGNETICA;
    else if (strcmp((*io)->tipo, "C") == 0)
        return IMPRESSORA;
    return -1;    
}

int processos_em_io(Fila** ios){
    int i = 0;
    Fila* inicio = *ios;
    while (inicio != NULL)
    {
        i++;
        inicio = inicio->prox;
    }
    return i;
}

/* FAZ A VARREDURA DE CADA PROCESSO NO VETOR E COMPARA O TEMPO DE CHEGADA DO PROCESSO COM A ATUAL U.T.*/
void chegou_na_cpu(FILE *saida, Processo p[], Fila **alta, int tempo_execucao)
{
    for (int i = 0; i < NUM_MAX_PROCESSOS; i++)
    {
        if (ut == p[i].t_chegada || (ut > p[i].t_chegada && p[i].t_chegada > (ut - tempo_execucao)))
        {
            fprintf(saida, "O Processo %s chegou no processador no instante U.T.= %d (Fila de Alta)\n", p[i].pid, p[i].t_chegada);
            adiciona_fim_fila(alta, p[i], Alta);
        }
    }
}

void round_robin(const char *filename, Processo p[], Fila **alta, Fila **baixa, Fila **ios)
{
    FILE *arq = fopen(filename, "a+");
    int tempo_execucao = 0;
    int processos_completos = 0;
    int fila = Alta;
    fputs("--------- INICIO DE EXECUÇÂO ---------\n", arq);
    chegou_na_cpu(arq,p,alta,tempo_execucao);
    while (processos_completos < (NUM_MAX_PROCESSOS)) 
    {
        Processo* processo_em_execucao = &remove_da_fila(alta)->processo;

        if (processo_em_execucao == NULL){ // CASO A FILA DE ALTA ESTEJA VAZIA PEGA O PROCESSO NA FILA DE BAIXA
            fila = Baixa;
            processo_em_execucao = &remove_da_fila(baixa)->processo;
        }

        if (processo_em_execucao != NULL) // CASO UMA DAS DUAS FILAS NÃO ESTEJA VAZIA
        {
            fprintf(arq, "U.T= %d| \tExecutando o Processo %s ", ut, processo_em_execucao->pid);
            (fila == Alta)? fprintf(arq,"(Fila de Alta)\n") : fprintf(arq,"(Fila de Baixa)\n"); 
            if (processo_em_execucao->num_io == 0) // SE O PROCESSO NÃO TEM OPERAÇÃO DE I/O
            {
                tempo_execucao = (processo_em_execucao->t_servico < QUANTUM) ?
                                    processo_em_execucao->t_servico : QUANTUM;
                processo_em_execucao->t_servico -= tempo_execucao;
                ut += tempo_execucao;
                if (processo_em_execucao->t_servico > 0)
                {
                    fprintf(arq, "U.T= %d|\tO Processo %s terminou sua fatia de tempo e foi movido para Fila de Baixa (Tempo restante: %d)\n", ut, processo_em_execucao->pid, processo_em_execucao->t_servico);
                    processo_em_execucao->t_chegada = ut;
                    adiciona_fim_fila(baixa, (*processo_em_execucao), Baixa);
                }
                if (processo_em_execucao->t_servico == 0)
                {
                    fprintf(arq, "U.T= %d|\tO Processo %s terminou (Tempo Total de Execução: %d)\n", ut, processo_em_execucao->pid, ut);
                    processos_completos++;
                }
                
            }
            if (processo_em_execucao->num_io > 0) // SE O PROCESSO TEM OPERAÇÃO DE I/O
            {
                int chamada_io = processo_em_execucao->operacoes_io->chegada;
                tempo_execucao = (chamada_io <= QUANTUM) ? chamada_io : QUANTUM;
                processo_em_execucao->t_servico -= tempo_execucao;
                ut += tempo_execucao;

                ES* aux = processo_em_execucao->operacoes_io;
                while (aux != NULL)
                {
                    aux->chegada -= tempo_execucao;
                    aux = aux->prox;
                }

                if (chamada_io > QUANTUM) // SE A OPERAÇÃO I/O NÃO OCORRE DURANTE A FATIA DE TEMPO ATUAL
                {
                    fprintf(arq, "U.T= %d|\tO Processo %s terminou sua fatia de tempo e foi movido para Fila de Baixa (Tempo restante: %d)\n", ut, processo_em_execucao->pid, processo_em_execucao->t_servico);
                    processo_em_execucao->t_chegada = ut;
                    adiciona_fim_fila(baixa, (*processo_em_execucao), Baixa);
                }
                if (chamada_io <= QUANTUM) // SE A OPERAÇÃO I/O OCORRE DURANTE A FATIA DE TEMPO ATUAL
                {
                    fprintf(arq, "U.T= %d| \tO Processo %s foi bloqueado (Tempo restante: %d)\n", ut, processo_em_execucao->pid, processo_em_execucao->t_servico);
                    processo_em_execucao->operacoes_io->saida = (ut + tipo_io(&processo_em_execucao->operacoes_io));
                    adiciona_fim_fila(ios, (*processo_em_execucao), IO);
                }
            }
        }
        
        chegou_na_cpu(arq,p,alta,tempo_execucao); // VERIFICA SE ALGUM PROCESSO CHEGOU NA CPU
        
        if (*ios != NULL || processo_em_execucao != NULL) // VERIFICA SE HÁ PROCESSO EM OPERAÇÃO I/O
        {
            int aux = processos_em_io(ios);
            for (int i = 0; i < aux; i++)
            {
                Processo* io_processo = &remove_da_fila(ios)->processo;
                int saida_io = io_processo->operacoes_io->saida;
                int tipo = tipo_io(&io_processo->operacoes_io);
                
                if (saida_io <= ut && io_processo->t_servico != 0)
                {
                    io_processo->t_chegada = saida_io;

                    // Verifica para qual fila o processo deve retornar
                    if (tipo == DISCO)
                    {
                        fprintf(arq, "O Processo %s terminou a operação de I/O (Disco) no instante UT = %d e retornou para CPU (Fila de Baixa)\n", io_processo->pid, saida_io);
                        io_processo->num_io--;
                        ES* chamada = remover_Io(&io_processo->operacoes_io);
                        free(chamada);
                        adiciona_meio_fila(baixa, (*io_processo), Baixa, saida_io); // RETORNA PARA DE BAIXA
                    }
                    else if (tipo == FITA_MAGNETICA)
                    {
                        fprintf(arq, "O Processo %s terminou a operação de I/O (Fita Magnética) no instante UT= %d e retornou para CPU (Fila de Alta)\n", io_processo->pid, saida_io);
                        io_processo->num_io--;
                        ES* chamada = remover_Io(&io_processo->operacoes_io);
                        free(chamada);
                        adiciona_meio_fila(alta, (*io_processo), Alta, saida_io); // RETORNA PARA DE ALTA
                    }
                    else if (tipo == IMPRESSORA)
                    {
                        fprintf(arq, "O Processo %s terminou a operação de I/O (Impressora) no instante UT= %d e retornou para CPU (Fila de Alta)\n", io_processo->pid, saida_io);
                        io_processo->num_io--;
                        ES* chamada = remover_Io(&io_processo->operacoes_io);
                        free(chamada);
                        adiciona_meio_fila(alta, (*io_processo), Alta, saida_io);// RETORNA PARA DE ALTA
                    }
                }
                else
                {
                    adiciona_fim_fila(ios, (*io_processo), IO); // SE NENHUM PROCESSO RETORNOU DE I/O
                }
            }
            
        }
        if (processos_completos == NUM_MAX_PROCESSOS) // SE TODOS OS PROCESSO TERMINARAM
        {
            fputs("--------- FIM DE EXECUÇÂO ---------", arq);
            fputs("\nSimulacao Concluida", arq);
        }
        if (*ios != NULL && processo_em_execucao == NULL) // SE AINDA HÁ PROCESSO BLOQUEADO E A CPU NÃO ESTA EXECUTANDO NADA
        {
            fprintf(arq,"U.T= %d|\tCPU OCIOSA\n", ut);
            ut++;
        }
    
        //if (*baixa == NULL && ut > 100) break; /* IMPEDIR QUE O ESCALONADOR ENTRE EM LOOP */
    }
}

int main()
{
    const char *arquivo_saida = "saida.txt";

    /* TABELA INICIALIZADA DIRETAMENTE*/
    Processo p[] = {
        {"P1", 0, 13, NULL, 1},
        {"P2", 4, 11, NULL, 2},
        {"P3", 5, 7, NULL, 0},
        {"P4", 7, 8, NULL, 0}};
        //{"P5", 10, 16, NULL, 2}};

    /* CRIANDO OS CHAMADOS DE I/O*/
    p[0].operacoes_io = inserir_io(p[0].operacoes_io, 4, "A");
    p[1].operacoes_io = inserir_io(p[1].operacoes_io, 2, "B");
    p[1].operacoes_io = inserir_io(p[1].operacoes_io, 6, "A");
    //p[4].operacoes_io = inserir_io(p[4].operacoes_io, 2, "A");
    //p[4].operacoes_io = inserir_io(p[4].operacoes_io, 7, "B");

    /* IMPRIMINDO A TABELA NO ARQUIVO DE SAIDA*/
    imprimir_tabela_processos(arquivo_saida, p);

    /* CRIDANDO AS FILA */
    Fila *fila_alta = NULL;
    Fila *fila_baixa = NULL;
    Fila *fila_io = NULL;

    round_robin(arquivo_saida, p, &fila_alta, &fila_baixa, &fila_io);  

    return 0;
}
