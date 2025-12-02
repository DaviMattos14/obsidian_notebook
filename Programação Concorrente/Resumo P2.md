Este é o resumo do "Tudo ou Nada". Se você entender a lógica abaixo, você passa.

---

### 🚨 O Resumo de Sobrevivência (Cheat Sheet)

#### 1. A Ferramenta: Semáforos (C) vs Monitores (Java)

|**Conceito**|**C (Semáforos)**|**Java (Monitores)**|
|---|---|---|
|**Biblioteca**|`<semaphore.h>`|Nativo (`synchronized`)|
|**Exclusão Mútua**|`sem_t mutex;` (Inicia com **1**)|`synchronized (this) { ... }`|
|**Sincronização**|`sem_t cond;` (Inicia com **0**)|`wait()` / `notifyAll()`|
|**Bloquear**|`sem_wait(&cond)`|`wait()` (solta o lock automaticamente)|
|**Liberar**|`sem_post(&cond)`|`notifyAll()` (acorda todos)|
|**Perigo**|Esquecer de liberar o Mutex antes de dar `wait` em outro semáforo.|Usar `if` em vez de `while` no `wait()`.|

---

### 🧠 Os 3 Padrões que Vão Cair

Decore a lógica destes três. A prova vai pedir para você escrever um deles ou achar um erro em um deles.

#### **1. Produtor / Consumidor (O Clássico)**

- **Cenário:** Buffer limitado. Produtor enche, Consumidor esvazia.
    
- **Lógica do Produtor:**
    
    1. `wait(vaga_vazia)`: Tem espaço?
        
    2. `wait(mutex)`: Entra na seção crítica.
        
    3. **INSERE ITEM**
        
    4. `post(mutex)`: Sai da seção crítica.
        
    5. `post(item_cheio)`: Avisa que tem item.
        
- **Pegadinha de Prova (Java):** Se pedir para o produtor encher o buffer **todo** de uma vez:
    
    Java
    
    ```
    // Em Java
    public synchronized void Insere() {
        while (count != 0) wait(); // Espera esvaziar TUDO
        // ... enche o vetor ...
        notifyAll(); // Acorda consumidores
    }
    ```
    
    1
    

#### **2. Leitores / Escritores (O Perigoso)**

- **Cenário:** Vários leem ao mesmo tempo. Só um escreve (exclusivo).
    
- **Lógica (Prioridade Leitura):**
    
    - O **1º Leitor** trava o escritor (`wait(sem_escrita)`).
        
    - O **N-ésimo Leitor** (último a sair) destrava o escritor (`post(sem_escrita)`).
        
    - Escritores travam tudo.
        
- **Pegadinha de Prova:** "Implemente com prioridade para Escritor" ou "Evite Starvation".
    
    - **Solução:** Você precisa de uma variável `escritoresEsperando`.
        
    - No código do Leitor: `if (escritoresEsperando > 0) wait();`. Não deixe ler se tiver alguém na fila para escrever. 2
        

#### **3. Barreira (O Sincronizador)**

- **Cenário:** N threads precisam chegar num ponto antes de qualquer uma continuar.
    
- **Lógica:**
    
    - Use um contador `chegaram` protegido por mutex.
        
    - As primeiras N-1 threads incrementam e dormem (`wait`).
        
    - A última thread (`chegaram == N`) acorda todo mundo (`broadcast` ou loop de `post`) e zera o contador.
        
- **Erro Comum:** Esquecer de zerar o contador ou zerar cedo demais (antes de todos acordarem).
    

---

### 💣 Caça aos Erros (Onde você ganha pontos)

Nas questões de "Aponte o erro", procure imediatamente por estes três problemas:

1. O Erro do IF no Java (Erro Fatal)

Se você vir isso:

Java

```
if (bufferCheio) wait();
```

O ERRO É: Threads podem acordar por "acidente" (spurious wakeup) ou outra thread pode roubar a vaga.

A CORREÇÃO:

Java

```
while (bufferCheio) wait();
```

_Justificativa:_ "É necessário retestar a condição lógica após a thread acordar." 3

2. O Erro do notify() (Deadlock)

Se houver Produtores e Consumidores esperando no mesmo objeto e o código usar notify():

O ERRO É: O notify() pode acordar a thread errada (ex: Produtor acorda outro Produtor quando o buffer está cheio).

A CORREÇÃO: Use notifyAll().

_Justificativa:_ "Garante que a thread correta será acordada, evitando deadlock." 4

3. O Erro da Ordem dos Semáforos (Deadlock em C)

Se você vir isso:

C

```
sem_wait(&mutex); // Pegou a chave do cofre
sem_wait(&vaga);  // Vai dormir esperando vaga
```

O ERRO É: Deadlock. A thread travou o cofre e foi dormir. O consumidor precisa entrar no cofre para liberar a vaga, mas não consegue.

A CORREÇÃO: Inverta. Sempre pegue o recurso externo (vaga) antes do interno (mutex).

---

### 📝 Roteiro para Agora (Modo Urgência)

1. **Leitura Obrigatória (15 min):** Abra o arquivo `gab-lista3.pdf`. Leia a **Questão 5** (Erro do `notify` na impressora) e a **Questão 6** (Erro no `shutdown` do Pool de Threads). Isso cai muito. 5555
    
2. **Prática de Código (30 min):** Escreva à mão (no papel) o padrão **Leitores/Escritores em Java** usando `synchronized`. Garanta que você sabe onde colocar o `wait` e o `notifyAll`.
    
3. **Conceito Final (10 min):** Entenda a diferença de `Thread` vs `Processo`.
    
    - Processo = Memória separada (precisa de `mmap`/Pipe).
        
    - Thread = Memória compartilhada.
        

Boa sorte amanhã! Mantenha a calma, use `while` nos waits e `notifyAll` nas sinalizações que você garante a aprovação.