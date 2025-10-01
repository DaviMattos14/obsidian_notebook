# Ordenação Topológica

## 1. Descrição
A **ordenação topológica** é uma listagem linear dos vértices de um DAG (grafo acíclico direcionado) tal que, para toda aresta (u, v), u aparece antes de v.

## 2. Grafo de exemplo
Vértices: {A, B, C, D, E}  
Arestas: A-B, A-C, B-D, C-D, D-E

## 3. Execução passo a passo (DFS)
- Executa DFS: termina ordem = E, D, B, C, A.  
- Ordenação topológica: A, C, B, D, E (ou outra equivalente).  

## 4. Pseudocódigo
```pseudocode
TOPOLOGICAL-SORT(G)
    para cada u ∈ V[G] faça
        cor[u] ← branco
        π[u] ← NIL
    tempo ← 0
    S ← lista vazia
    para cada u ∈ V[G] faça
        se cor[u] = branco então
            DFS-TOPO(G, u, S)
    retornar S

DFS-TOPO(G, u, S)
    cor[u] ← cinza
    tempo ← tempo + 1
    para cada v ∈ Adj[u] faça
        se cor[v] = branco então
            DFS-TOPO(G, v, S)
    cor[u] ← preto
    tempo ← tempo + 1
    inserir u no início de S
```