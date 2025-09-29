# 1. Representação de Grafos

Um grafo $G=(V,E)$ é um objeto matemático composto por um conjunto de vértices ($V$), também chamados de nós, e por um conjunto de arestas ($E$), onde cada aresta em $E$ é um subconjunto de dois elementos de vértices $V$. 
Seja $u$ e $v$ vértices de G. Uma aresta é direcionada se seu par de subconjuntos for ordenado, por exemplo, $(u, v)$, e não direcionada se seu par de subconjuntos for não ordenado, por exemplo, $\{u, v\}$ ou, alternativamente, tanto $(u, v)$ quanto $(v, u)$

Com isso grafos podem ser **direcionados** e **não direcionados**
## Grafo Direcionado

Uma aresta direcionada $e=(u,v)$ estende-se do vértice $u$ para o vértice $v$ ($u \longrightarrow v$), com $e$ sendo uma aresta de *entrada* de v e uma aresta de *saída* de u.

$$
\begin{matrix}
G_{1}= (V_1,E_1) & V_1=\{0,1,2,3,4\} & E_1=\{(0,1),(1,2),(2,0),(3,4)\}
\end{matrix}
$$
![[Pasted image 20250929152057.png]]
Outros exemplos de representação:
![[grafo_direcionado.png]]
## Grafo Não Direcionado

Em um grafo não direcionado, toda aresta é de entrada e de saída.
$$
\begin{matrix}
G_{2}= (V_2,E_2) & V_2=\{0,1,2,3,4\} & E_2=\{\{0,1\}\{0,3\},\{0,4\},\{2,3\}\}
\end{matrix}
$$
![[Pasted image 20250929152234.png]]Outros exemplos:
![[Pasted image 20250929152322.png]]
Há outra representação de grafos:
- **Grafo Valorado**, onde cada aresta possui um **peso**
- **Grafo Completo**, onde todos vértices são vizinhos, todos $n$ vértices tem $n-1$ arestas
## Vizinhança
Um vértice $u$ é dito *vizinho* de $v$ se tiver uma aresta $E$ ligando os vértices.
($u \longrightarrow v$)

## Caminho
Um caminho de tamanho $k$ do vértice $u$ ao vértice $v$ é uma sequência de vértices $(v_0,v_1,\dots,v_n)$ onde para cada par ordenado $(v_{i-1},v_{i})$ existe uma aresta, onde $k=$ número de arestas (ou $\#V -1$)
**Grafo fortemente conectado**: Para cada vértice há um caminho para cada outro vértice
## Ciclo
Em um grafo direcionado dado um caminho $(v_0,v_1,\dots,v_k)$, ele forma um ciclo se, somente se, $v_{0}= v_k$.
Em um grafo não direcionado, o caminho forma um ciclo, se $v_{0}= v_k$ , tem pelo menos uma aresta $(\#V > 0)$ que conecta um par ordenado, e todos os vértices e arestas no trajeto (exceto o inicial/final) são **distintos**.

## Representação computacional

Há duas formas padrão de se representar um grafo $G=(V,E)$
- listas de adjacências
- matriz de adjacências
Ambos funcionam para grafos direcionados e não direcionados.
- A **lista de adjacência** é mais compacta para grafos _esparsos_ (quando $|E| \ll |V|^2$). Por isso, é geralmente a representação escolhida, e a maioria dos algoritmos do livro assume esse formato.
- A **matriz de adjacência** é preferida para grafos _densos_ (quando $|E|$ é próximo de$|V|^2$) ou quando precisamos saber rapidamente se existe uma aresta entre dois vértices.
### Listas de Adjacências

**Estrutura**: um vetor **Adj** de tamanho $|V|$, onde cada posição corresponde a um vértice e contém uma lista de seus vizinhos.
- Se o grafo é direcionados: o tamanho total das listas é $|E|$.
- Se o grafo é não direcionados: o tamanho total é $2|E|$, porque cada aresta $(u, v)$ aparece em ambas as listas.
**Espaço necessário**: $\Theta(V + E)$.
- Pode ser adaptado para grafos **ponderados** (valorados), armazenando o peso junto ao vértice vizinho.
**Desvantagem:** para verificar se uma aresta $(u, v)$ existe, é preciso percorrer a lista de $u$.
### Matriz de Adjacências

**Estrutura**: uma matriz $|V| \times |V|$ onde $$a_{ij}=\begin{cases} 1 & \text{se } (i, j) \in E \\ 0 & \text{caso contrário} \end{cases}$$
- Ocupa sempre $\Theta(V^2)$ de memória, independentemente do número de arestas.
- A busca de uma aresta é imediata, $O(1)$.
- Para grafos não dirigidos, a matriz é simétrica.

Também pode representar grafos ponderados armazenando o peso em vez de apenas 0 ou 1.

Pode ser otimizada armazenando apenas metade da matriz (parte superior da diagonal

Para grafos pequenos, é mais simples que listas de adjacência e pode usar apenas 1 bit por posição em grafos não ponderados.
### Atributos de vértices e arestas

- Algoritmos costumam manter atributos (ex.: cor, distância, pai).
- Esses atributos podem ser armazenados em arrays auxiliares ou junto às estruturas.
- A forma de implementação varia conforme a linguagem de programação e necessidades do algoritmo.
# 2. Algoritmos básicos
## Busca
- Matriz de Adjacências
#Vértice Verifica se um vértice existe no grafo
```
busca_vertice(grafo G, int id)
    if 1 <= id <= G.n:
        return i    // índice do vértice (ou objeto associado)
    else:
        return NIL
```

#Aresta Verifica se existe uma aresta entre o vértice `u` e o vértice `v`
```
busca_aresta(grafo G, vertice u, vertice v)
    retornar (A[u][v] == 1)
```

- Lista de Adjacências
#Vértice
```
FUNÇÃO busca_vertices(Grafo G, Vértice u) 
	RETORNAR G.Adj[u]
```

#Aresta 
```
busca-aresta(Grafo G, vertice u, vertice v)
    para cada x em Adj[u]:
        se x == v:
            retornar VERDADEIRO
    retornar FALSO

```
## Inserir

- Matriz de Adjacências
#Vértice 
expandir a matriz para dimensão $(|V|+1) \times (|V|+1)$ e inicializar nova linha/coluna com 0
```
//Vertice
inserir_vertice(grafo G, vertice v)
    expandir matriz A
    para todo i:
        A[v][i] ← 0
        A[i][v] ← 0
```
#Aresta 
```
insere_aresta(grafo G, vertice u, vertice v, bool direcionado)
    A[u][v] ← 1
    if not direcionado:
        A[v][u] ← 1

```
- Lista de Adjacências
#Vértice 
criar nova lista vazia `Adj[v]`.
```
INSERE-VERTICE(grafo G, vertice v)
    Adj[v] ← lista vazia
```
#Aresta 
**Grafo dirigido:** adiciona $v$ na lista de $u$.
**Grafo não dirigido:** adiciona $v$ na lista de $u$ **e** $u$ na lista de $v$.
```
FUNÇÃO ADICIONAR_ARESTA(Grafo G, Vértice u, Vértice v, é_direcionado) 
	// Adiciona v à lista de adjacência de u 
	G.Adj[u].adicionar(v) 
	
	SE não é_direcionado ENTÃO 
			// Se o grafo não for direcionado, a aresta é recíproca
			G.Adj[v].adicionar(u) 
	FIM-SE 
FIM-FUNÇÃO
```

## Remover
- Matriz de Adjacências
remover linha e coluna correspondentes a `v`.
#Vértice 
```
REMOVE-VERTICE-MATRIZ(G, v)
    remover linha v e coluna v da matriz A

```

#Aresta 
```
REMOVE-ARESTA-MATRIZ(G, u, v, direcionado)
    A[u][v] ← 0
    if not direcionado:
        A[v][u] ← 0

```

- Lista de Adjacências
remover a lista `Adj[v]` e apagar todas as ocorrências de `v` em outras listas.
#Vértice 
```
REMOVE-VERTICE-LISTA(G, v)
    para cada u em V:
        remover v de Adj[u]
    remover lista Adj[v]

```

#Aresta 
```
REMOVE-ARESTA-LISTA(G, u, v, direcionado)
    remover v de Adj[u]
    if not direcionado:
        remover u de Adj[v]

```

# 3. Busca em Largura (BFS - Breadth-First Search)

- Explora vértices por **camadas**: primeiro os a distância $k$, depois $k+1$.
- Garante cálculo de **menores distâncias** em grafos não ponderados.
- Constrói conjuntos $L_i$​: vértices a distância $i$ da fonte.
- **Complexidade**: $O(V+E)$.
- **Propriedade**: BFS é correto porque cada aresta adiciona apenas vértices na camada seguinte.

Dado um grafo `G = (V, E)` e um vértice de origem `s`, a busca em largura explora sistematicamente as arestas de `G` para "descobrir" todos os vértices alcançáveis a partir de `s`.

**Como funciona**: O algoritmo avança em "ondas" a partir da origem `s`. Primeiro, visita todos os vizinhos de `s` (vértices a uma distância de 1 aresta). Em seguida, visita os vizinhos desses vizinhos (vértices a uma distância de 2 arestas), e assim por diante, até que todos os vértices alcançáveis tenham sido visitados.

**Caminho mais curto**: Uma propriedade crucial da busca em largura é que ela calcula a distância do caminho mais curto (em termos de número de arestas) de `s` para cada vértice alcançável.

**Árvore de busca em largura**: Durante a busca, o algoritmo constrói uma "árvore de busca em largura" com raiz em `s`, que contém todos os vértices alcançáveis. Para qualquer vértice `v` alcançável a partir de `s`, o caminho simples na árvore de `s` para `v` corresponde a um caminho mais curto no grafo original.

**Estrutura de dados**: Para gerenciar a fronteira de vértices descobertos, o algoritmo utiliza uma fila (queue) no estilo FIFO (primeiro a entrar, primeiro a sair).

**Coloração de Vértices**: Para acompanhar o progresso, cada vértice é colorido de branco, cinza ou preto.
- **Branco**: Vértice ainda não descoberto.
- **Cinza**: Vértice descoberto, mas seus vizinhos ainda não foram todos explorados. Os vértices cinzas formam a fronteira na fila.
- **Preto**: Vértice "finalizado", ou seja, todos os seus vizinhos já foram descobertos
## Algoritmo
```
BFS(G, s)   // G = (V, E), s = vértice de origem
    para cada v ∈ V[G] faça
        cor[v] ← branco         // não visitado
        d[v] ← ∞                // distância da origem
        p[v] ← NIL              // pai/predecessor
    cor[s] ← cinza
    d[s] ← 0
    p[s] ← NIL

    Q ← fila vazia
    ENQUEUE(Q, s)

    enquanto Q não estiver vazia faça
        u ← DEQUEUE(Q)
        para cada v ∈ Adj[u] faça
            se cor[v] = branco então
                cor[v] ← cinza
                d[v] ← d[u] + 1
                p[v] ← u
                ENQUEUE(Q, v)
        cor[u] ← preto

```
![[Pasted image 20250929192405.png]]
# 4. Subgrafos
## Árvores
- Grafo **não direcionado**, **conexo** (existe caminho entre quaisquer dois vértices) e **sem ciclos**.
- Propriedades principais:
    - Se tem $n$ vértices, possui exatamente $n-1$ arestas.
    - Há um **único caminho simples** entre quaisquer dois vértices.
## Floresta
- Conjunto de **árvores disjuntas** (um grafo acíclico, mas não necessariamente conexo).
- Cada componente conexo de uma floresta é uma árvore.
## Subgrafo
- Grafo formado a partir de outro grafo $G = (V, E)$, escolhendo um subconjunto de vértices $V' \subseteq V$ e um subconjunto de arestas $E' \subseteq E$ que conectam apenas vértices em $V'$.
- Pode ser:
    - **Induzido**: contém todas as arestas entre os vértices de $V'$.
    - **Não induzido**: contém apenas algumas dessas arestas.
## Subgrafo predecessor
- Subgrafo formado a partir das relações de **predecessores** em uma busca (DFS ou BFS).
- Quando executamos DFS ou BFS, cada vértice visitado guarda um **pai** (predecessor).
- Conectando cada vértice ao seu predecessor, obtemos um **subgrafo em forma de árvore ou floresta**, chamado **árvore de busca** ou **subgrafo predecessor**.

Durante a busca, para cada vértice `v` que é descoberto a partir de um vértice `u`, `u` se torna o predecessor de `v`. O subgrafo predecessor é o grafo G' = (V', E') formado por todos os vértices alcançados durante a busca e pelas arestas 
`(u, v)` onde `u` é o predecessor de `v`. 
Este subgrafo forma uma árvore (ou uma floresta de árvores) que representa os caminhos descobertos a partir do vértice de origem. 
Por exemplo, na busca por caminhos mais curtos, o subgrafo predecessor forma uma **árvore de caminhos mais curtos**
# 5. Busca em Profundidade (DFS - Depth-First Search)

Dado um vértice inicial, é desejável encontrar todos os vértices alcançáveis a partir dele. Existem muitos algoritmos para fazer isso, sendo o mais simples a busca em profundidade. Como o nome indica, o DFS enumera os caminhos mais profundos, apenas retrocedendo quando atinge um beco sem saída ou uma seção já explorada do grafo. O DFS por si só é bastante simples, então introduzimos algumas melhorias ao algoritmo básico.

- Para evitar loops, o DFS mantém um atributo de "cor" para cada vértice. Vértices não visitados são brancos por padrão. Vértices que foram visitados, mas para os quais ainda se pode retroceder, são coloridos de cinza. Vértices que estão completamente processados são coloridos de preto. O algoritmo pode então evitar loops pulando vértices que não são brancos.
- Em vez de apenas marcar vértices visitados, o algoritmo também mantém o controle da árvore gerada pela travessia em profundidade. Ele faz isso marcando o "pai" de cada vértice visitado, ou seja, o vértice que o DFS visitou imediatamente antes de visitar o filho.    
- O DFS aumentado também marca dois carimbos de tempo auto-incrementais, d e f, para indicar quando um nó foi descoberto pela primeira vez e quando foi finalizado.

**Estratégia**: A DFS explora o mais "profundamente" possível ao longo de cada ramo antes de retroceder (backtracking). Ela vai o mais longe que pode por um caminho, e só volta quando não há mais vértices brancos (não descobertos) para explorar a partir do vértice atual.

**Estrutura Recursiva**: A DFS é naturalmente recursiva. A busca a partir de um vértice `u` é suspensa quando um novo vértice `v` é descoberto, iniciando uma nova busca a partir de `v`. A busca a partir de `u` só recomeça depois que todos os vértices alcançáveis a partir de `v` forem explorados.

**Cores e Timestamps**: Assim como a BFS, a DFS usa cores para rastrear vértices. Além disso, ela atribui dois "timestamps" a cada vértice:
- **Timestamp de Descoberta (d)**: Registra quando um vértice se torna cinza.
- **Timestamp de Finalização (f)**: Registra quando um vértice se torna preto.

**Classificação de Arestas**: Com base nesses timestamps e cores, a DFS classifica as arestas em quatro tipos, o que revela informações importantes sobre a estrutura do grafo:
    - **Arestas de Árvore**: Arestas que levam a um vértice branco não descoberto. Elas formam a "floresta de busca em profundidade".
    - **Arestas de Retorno (Back edges)**: Arestas que conectam um vértice a um de seus ancestrais na árvore de busca (indicam a presença de ciclos).
    - **Arestas de Avanço (Forward edges)**: Arestas que conectam um vértice a um de seus descendentes (que não seja um filho direto).
    - **Arestas de Cruzamento (Cross edges)**: Todas as outras arestas.
        
**Complexidade de Tempo**: O tempo de execução é **Θ(V + E)**

## Algoritmo

**Procedimento principal:**

```
DFS(G)
1 for vertice u in G.V
2     u.cor = branco
3     u.π = NIL
4 tempo = 0
5 for vertice u in G.V
6     if u.cor == branco
7         DFS-VISIT(G, u)
```

**Procedimento auxiliar:**

```
DFS-VISIT(G, u)
1 tempo = tempo + 1 // white vertex u has just been discovered
2 u.d = tempo
3 u.cor = cinza
4 for vertice v in G.Adj[u]  // explore each edge (u, v)
5     if v.cor == branco
6         v.π = u
7         DFS-VISIT(G, v)
8 tempo = tempo + 1
9 u.f = tempo
10 u.color = preto                // blacken u; it is finished
```
![[Pasted image 20250929200106.png]]