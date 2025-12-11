### 1. Os Três Padrões Fundamentais (C e Java)

A prova vai exigir que você implemente, complete ou corrija um destes três padrões. Domine a lógica de cada um.

#### **A. Produtor / Consumidor**

Cenário: Buffer limitado. Produtor insere, Consumidor remove.

Regras: Produtor bloqueia se cheio. Consumidor bloqueia se vazio. Exclusão mútua no acesso ao buffer.

Implementação em C (Semáforos):

Baseado na Lista 2, Q1 1e Gabarito 2.

C

```c
sem_t mutex;      // Inicia com 1 (proteção do buffer)
sem_t slotVazio;  // Inicia com N (vagas disponíveis)
sem_t slotCheio;  // Inicia com 0 (itens disponíveis)

void Produtor(int item) {
    sem_wait(&slotVazio); // 1. Tem vaga? (Evita Deadlock: Recurso externo primeiro)
    sem_wait(&mutex);     // 2. Trava buffer
    // ... insere item ...
    sem_post(&mutex);     // 3. Destrava buffer
    sem_post(&slotCheio); // 4. Avisa consumidor
}

void Consumidor() {
    sem_wait(&slotCheio); // 1. Tem item?
    sem_wait(&mutex);     // 2. Trava buffer
    // ... retira item ...
    sem_post(&mutex);     // 3. Destrava buffer
    sem_post(&slotVazio); // 4. Avisa produtor
}
```

Implementação em Java (Monitores):

Baseado na Lista 3, Q1 3e Lab 11 4.

Java

```java
public synchronized void insere(int item) {
    // ERRO COMUM: Usar 'if' aqui. O correto é 'while'.
    while (count == N) { // Enquanto cheio, espera.
        try { wait(); } catch (InterruptedException e) {}
    }
    // ... insere item ...
    notifyAll(); // Acorda TODOS (Produtores e Consumidores)
}

public synchronized int retira() {
    while (count == 0) { // Enquanto vazio, espera.
        try { wait(); } catch (InterruptedException e) {}
    }
    // ... retira item ...
    notifyAll(); // Acorda TODOS
    return item;
}
```

---

#### **B. Leitores / Escritores**

Cenário: Banco de dados. Leitura paralela permitida. Escrita exclusiva.

Regra de Ouro: Se um escreve, ninguém lê nem escreve.

Implementação em C (Semáforos - Prioridade Leitura):

Baseado na Lista 2, Q3 5e Gabarito 6.

C

```c
sem_t mutex;   // Inicia com 1 (protege contador 'leitores')
sem_t escrita; // Inicia com 1 (bloqueia o escritor)
int leitores = 0;

void Leitor() {
    sem_wait(&mutex);
    leitores++;
    if (leitores == 1) sem_wait(&escrita); // 1º leitor trava o escritor
    sem_post(&mutex);
    
    // ... LEITURA ...
    
    sem_wait(&mutex);
    leitores--;
    if (leitores == 0) sem_post(&escrita); // Último leitor libera o escritor
    sem_post(&mutex);
}

void Escritor() {
    sem_wait(&escrita); // Trava tudo
    // ... ESCRITA ...
    sem_post(&escrita);
}
```

- **Ponto de Atenção:** Se a questão pedir **Prioridade para Escrita**, o leitor deve verificar se há escritores esperando antes de tentar ler 7.
    

---

#### **C. Barreira**

**Cenário:** N threads precisam chegar num ponto antes de qualquer uma continuar.

Implementação em C (Semáforos):

Baseado nos Slides Aula 7 8.

C

```c
sem_t mutex; // Inicia 1
sem_t cond;  // Inicia 0 (Fila de espera)
int chegaram = 0;

void Barreira(int N) {
    sem_wait(&mutex);
    chegaram++;
    if (chegaram < N) {
        sem_post(&mutex);
        sem_wait(&cond); // Bloqueia
    } else {
        // Última thread libera todas em cascata ou loop
        for(int i=0; i < N-1; i++) sem_post(&cond);
        chegaram = 0; // Reset para reuso
        sem_post(&mutex);
    }
}
```

---

### 2. Pontos de Atenção Críticos (Onde você perde a questão)

#### **EM C (Pthreads e Semáforos)**

1. **Deadlock por Ordem Invertida:**
    
    - _Erro:_ `sem_wait(&mutex)` seguido de `sem_wait(&vaga)`.
        
    - _Por que:_ Você tranca o buffer e vai dormir esperando vaga. O consumidor precisa trancar o buffer para criar vaga, mas não consegue.
        
    - _Correção:_ Sempre pegue o **Recurso Condicional** (vaga/item) **ANTES** do **Mutex** 9.
        
2. **Inicialização:**
    
    - Mutex deve começar com **1**.
        
    - Semáforo de espera (condição) deve começar com **0**.
        
    - Semáforo de recursos (vagas) deve começar com **N**.
        
3. **Starvation em Leitores/Escritores:**
    
    - Na implementação padrão (acima), se leitores chegam sem parar, o escritor nunca escreve. Isso é _Starvation de Escritores_ 10.
        

#### **EM JAVA (Monitores e Pools)**

1. **O Pecado do `IF`:**
    
    - _Erro:_ `if (condicao) wait();`
        
    - _Por que:_ "Spurious Wakeup". A thread pode acordar sem o sinal, ou outra thread pode ter roubado a vaga antes dessa rodar.
        
    - _Correção:_ **SEMPRE** use `while (condicao) wait();`. Isso obriga a thread a retestar a condição ao acordar 11.
        
2. **O Pecado do `notify`:**
    
    - _Erro:_ Usar `notify()` quando há produtores e consumidores esperando no mesmo objeto.
        
    - _Por que:_ Você pode acordar a thread errada (ex: Produtor acorda outro Produtor quando está cheio), gerando Deadlock.
        
    - _Correção:_ Use `notifyAll()`. É menos eficiente, mas garante a corretude 12.
        
3. **Callable vs Runnable:**
    
    - `Runnable`: Método `run()`, retorno `void`, não lança exceção checada.
        
    - `Callable`: Método `call()`, retorna valor (Generics), lança exceção. Usado com `Future` 13.
        

---

### 3. Guia Definitivo: Como Resolver Qualquer Questão

Quando você ler o enunciado, siga este algoritmo mental:

**Passo 1: Identificar a Ferramenta**

- "Implemente usando Pthreads/Semáforos" -> Use **C** (sem_wait, sem_post).
    
- "Implemente usando Monitores/Java" -> Use **Java** (synchronized, wait, notifyAll).
    

**Passo 2: Identificar o Padrão**

- Tem limite de capacidade? -> **Produtor/Consumidor**.
    
- Tem distinção entre quem só olha e quem altera? -> **Leitores/Escritores**.
    
- Todo mundo tem que esperar todo mundo? -> **Barreira**.
    

**Passo 3: Aplicar o Template e Refinar**

- Escreva o esqueleto do padrão identificado acima.
    
- **Verifique as Variações (Pegadinhas):**
    
    - _O consumidor retira tudo de uma vez?_ -> Mude o `wait` do produtor para esperar `cheio == 0` e use um loop no consumidor 14.
        
    - _Prioridade para escritor?_ -> Adicione uma variável `escritoresEsperando` e bloqueie a entrada de leitores se ela for > 0 15.
        
    - _Pool de Threads?_ -> Verifique se o método de finalização (`shutdown`) acorda as threads trabalhadoras para elas morrerem (`notifyAll`) 16.
        

**Passo 4: Checklist Final (Caça-Erros)**

- [Java] Troquei todos os `if` por `while` nos waits?
    
- [Java] Usei `notifyAll`?
    
- \[C\] Coloquei `sem_wait` do recurso _antes_ do `sem_wait` do mutex?
    
- \[C\] Liberei o mutex em todos os caminhos de saída (incluindo `if/else`)?
    
