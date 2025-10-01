# Busca em Profundidade (DFS)

## 1. Descrição
A **Busca em Profundidade (DFS)** explora o grafo indo o mais fundo possível antes de retroceder. Útil para classificação de arestas, ordenação topológica e componentes fortemente conectados.

## 2. Grafo de exemplo
Grafo direcionado com vértices {A, B, C, D, E} e arestas:
- A-B, A-C, B-D, C-E

Lista de adjacência:
- A: {B, C}  
- B: {D}  
- C: {E}  
- D: {}  
- E: {}  

## 3. Execução passo a passo (ordem alfabética)
- Começa em A: d[A]=1. Descobre B, depois D. Finaliza D, volta a B, finaliza B.  
- Continua em A → descobre C, depois E. Finaliza E, depois C, por fim A.  

Ordem de finalização: D, B, E, C, A.

## 4. Pseudocódigo
```pseudocode
DFS(G)
    para cada u ∈ V[G] faça
        cor[u] ← branco
        π[u] ← NIL
    tempo ← 0
    para cada u ∈ V[G] faça
        se cor[u] = branco então
            DFS-VISITA(G, u)

DFS-VISITA(G, u)
    cor[u] ← cinza
    tempo ← tempo + 1
    d[u] ← tempo
    para cada v ∈ Adj[u] faça
        se cor[v] = branco então
            π[v] ← u
            DFS-VISITA(G, v)
    cor[u] ← preto
    tempo ← tempo + 1
    f[u] ← tempo
```