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

### ☕ Guia Avançado de Concorrência em Java

Em Java, a concorrência gira em torno de **Monitores** (para sincronização básica) e do pacote `java.util.concurrent` (para abstrações de alto nível como Pools e Futures).

#### 1. Os Padrões Clássicos com Monitores (`synchronized`)

Antes de entrar em Pools, é vital dominar como Java implementa os padrões clássicos usando a classe `Object`.

**Regras de Ouro:**

1. **Exclusão Mútua:** Use a palavra-chave `synchronized` em métodos ou blocos.
    
2. **Espera:** Use `wait()` para dormir. **Sempre** dentro de um `while`.
    
3. **Notificação:** Use `notifyAll()` para acordar threads. Evite `notify()` a menos que saiba exatamente o que está fazendo.
    

Exemplo: Produtor/Consumidor em Java

Baseado na Lista 3 e Lab 11 1111.

Java

```java
class Buffer {
    private int[] buffer;
    private int count = 0, in = 0, out = 0, N;

    public Buffer(int tamanho) {
        this.N = tamanho;
        this.buffer = new int[N];
    }

    public synchronized void insere(int item) {
        // PONTO DE ATENÇÃO: while e não if
        while (count == N) { 
            try { wait(); } catch (InterruptedException e) {}
        }
        buffer[in] = item;
        in = (in + 1) % N;
        count++;
        // PONTO DE ATENÇÃO: notifyAll e não notify
        notifyAll(); 
    }

    public synchronized int remove() {
        while (count == 0) {
            try { wait(); } catch (InterruptedException e) {}
        }
        int item = buffer[out];
        out = (out + 1) % N;
        count--;
        notifyAll();
        return item;
    }
}
```

---

#### 2. Pool de Threads

O conceito de **Pool de Threads** é criar um conjunto de threads trabalhadoras (_workers_) que ficam vivas durante toda a aplicação, consumindo tarefas de uma fila. Isso evita o custo de criar/destruir threads (`new Thread()`) repetidamente.

A. Implementação Manual (O que cai na prova)

Muitas vezes a prova pede para achar erros numa implementação manual de Pool (como na Questão 6 da Lista 3).

- **Estrutura:** Uma lista de threads (`Worker[]`) e uma fila de tarefas (`LinkedList<Runnable>`).
    
- **Lógica do Worker:** Um loop infinito que pega uma tarefa da fila e executa `r.run()`.
    
- **Ponto Crítico (Shutdown):** Como desligar o pool?
    
    - Você precisa de uma flag `shutdown`.
        
    - Ao chamar `shutdown()`, você seta a flag E chama `notifyAll()` na fila para acordar os workers que estão dormindo esperando tarefa. Se não acordá-los, eles nunca verão que a flag mudou e a aplicação não termina (Deadlock no encerramento).
        

Correção da Lista 3 (Questão 6) 2:

Java

```java
public void shutdown() {
    synchronized(queue) {
        this.shutdown = true;
        queue.notifyAll(); // Vital: Acorda workers ociosos para eles saírem
    }
    // ... join nas threads ...
}
```

B. Implementação com Biblioteca (ExecutorService)

Usada nos laboratórios e questões práticas de código moderno.

Java

```java
// Cria um pool com 10 threads fixas
ExecutorService pool = Executors.newFixedThreadPool(10);

// Submete uma tarefa que não retorna valor (Runnable)
pool.execute(new Runnable() {
    public void run() { System.out.println("Oi!"); }
});

// Encerra o pool (não aceita novas, espera as atuais terminarem)
pool.shutdown();
```

---

#### 3. Futuros (`Future`) e `Callable`

Quando queremos que uma tarefa concorrente **retorne um valor**, usamos `Callable` em vez de `Runnable` e recebemos um objeto `Future`.

Conceitos Chave 3333:

1. **`Callable<T>`:** Interface similar a `Runnable`, mas o método é `T call() throws Exception`. Pode retornar valor e lançar exceção checada.
    
2. **`Future<T>`:** É um "ticket" ou promessa. Você submete a tarefa e recebe esse ticket imediatamente.
    
3. **`future.get()`:** É o ponto de sincronização. Se a tarefa já acabou, retorna o valor. Se não, **bloqueia** a thread atual até a tarefa terminar.
    

Exemplo Prático (Soma Assíncrona):

Baseado no Lab 11 e Gabarito Prova 2 4.

Java

```java
import java.util.concurrent.*;

// 1. Definir a tarefa que retorna valor
class SomaParcial implements Callable<Long> {
    long inicio, fim;
    public SomaParcial(long i, long f) { this.inicio = i; this.fim = f; }
    
    public Long call() {
        long soma = 0;
        for (long i = inicio; i < fim; i++) soma += i;
        return soma;
    }
}

public class Main {
    public static void main(String[] args) throws Exception {
        ExecutorService pool = Executors.newFixedThreadPool(4);
        
        // 2. Submeter tarefas e guardar os Futures
        Future<Long> f1 = pool.submit(new SomaParcial(0, 100));
        Future<Long> f2 = pool.submit(new SomaParcial(100, 200));
        
        // O programa continua executando aqui enquanto as threads trabalham...
        
        // 3. Pegar os resultados (Sincronização)
        long total = f1.get() + f2.get(); // Bloqueia se necessário
        System.out.println("Total: " + total);
        
        pool.shutdown();
    }
}
```

---

### ⚠️ Pontos de Atenção Fatais (Checklist de Prova)

Nas questões teóricas ou de "Ache o Erro", verifique estes pontos imediatamente:

1. **Monitor Java:**
    
    - _Erro:_ `if (condicao) wait();`.
        
    - _Correção:_ `while (condicao) wait();` (Proteção contra Spurious Wakeup).
        
    - _Erro:_ `notify()` em cenários com múltiplos tipos de threads (Produtor acordando Produtor).
        
    - _Correção:_ `notifyAll()`.
        
2. **Thread Pool Manual:**
    
    - _Erro:_ O método `shutdown` apenas seta a flag `boolean` mas não notifica a fila.
        
    - _Consequência:_ Threads presas no `wait()` da fila nunca acordam para ver que `shutdown` é true. A JVM não termina.
        
3. **Future:**
    
    - _Conceito:_ `submit()` é assíncrono (não bloqueia). `get()` é síncrono (bloqueia).
        
    - _Erro:_ Chamar `get()` imediatamente após `submit()`.
        
    - _Consequência:_ Transforma o código paralelo em sequencial, matando o desempenho. Você deve submeter todas as tarefas primeiro, e só depois chamar `get()` em cada uma.
        

---

### 🧭 Guia: Como Resolver Qualquer Questão de Java

**Se for de Implementação:**

1. Decida: Precisa retornar valor?
    
    - **Sim:** Use `Callable`, `ExecutorService` e `Future`.
        
    - **Não:** Use `Runnable` (com `Thread` ou `ExecutorService`) ou Monitores (`synchronized`).
        
2. Se for Monitor (`synchronized`):
    
    - Proteja o estado mutável (variáveis).
        
    - Use `while` para esperar condições.
        
    - Use `notifyAll` ao mudar o estado.
        

**Se for de "Ache o Erro":**

1. Procure por `wait()` fora de `while`.
    
2. Procure por acesso a variáveis compartilhadas fora de blocos `synchronized`.
    
3. Procure por `notify()` onde deveria ser `notifyAll()`.
    
4. No encerramento de Pools, verifique se há notificação para acordar os trabalhadores ociosos.