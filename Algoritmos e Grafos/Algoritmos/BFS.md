# Busca em Largura (BFS)

## 1. Descrição
A **Busca em Largura (BFS)** explora o grafo em camadas, descobrindo todos os vértices a uma distância mínima da fonte antes de prosseguir.

## 2. Grafo de exemplo
Grafo não direcionado com vértices {A, B, C, D, E} e arestas:
- A-B, A-C, B-D, C-E

Lista de adjacência:
- A: {B, C}  
- B: {A, D}  
- C: {A, E}  
- D: {B}  
- E: {C}  

## 3. Execução passo a passo (fonte = A)
- Inicialização: d[A]=0, d[v]=∞ para demais vértices, fila = [A].  
- Retira A: descobre B e C, d[B]=1, d[C]=1, fila = [B, C].  
- Retira B: descobre D, d[D]=2, fila = [C, D].  
- Retira C: descobre E, d[E]=2, fila = [D, E].  
- Retira D e E: sem novos vértices.  
- Fila esvaziada → fim.  

Resultado:
- d[A]=0, d[B]=1, d[C]=1, d[D]=2, d[E]=2  

## 4. Pseudocódigo
```pseudocode
BFS(G, s)
    para cada v ∈ V[G] faça
        cor[v] ← branco
        d[v] ← ∞
        π[v] ← NIL
    cor[s] ← cinza
    d[s] ← 0
    π[s] ← NIL
    Q ← fila vazia
    ENQUEUE(Q, s)
    enquanto Q ≠ vazio faça
        u ← DEQUEUE(Q)
        para cada v ∈ Adj[u] faça
            se cor[v] = branco então
                cor[v] ← cinza
                d[v] ← d[u] + 1
                π[v] ← u
                ENQUEUE(Q, v)
        cor[u] ← preto
```