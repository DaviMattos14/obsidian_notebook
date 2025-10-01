# Algoritmo de Prim

## 1. Descrição
O **algoritmo de Prim** encontra a Árvore Geradora Mínima (MST) crescendo uma árvore a partir de um vértice inicial.

## 2. Grafo de exemplo
Vértices: {A, B, C, D}  
Arestas com pesos:  
- A-B (1), A-C (4), B-C (2), B-D (5), C-D (3)

## 3. Execução passo a passo (raiz = A)
- Início: chave[A]=0, os outros = ∞.  
- Escolhe A, adiciona aresta A-B (1).  
- Escolhe C via B-C (2).  
- Escolhe D via C-D (3).  
- MST final: arestas {A-B, B-C, C-D}, peso total = 6.

## 4. Pseudocódigo
```pseudocode
PRIM-MST(G, w, r)
    para cada u ∈ V[G] faça
        chave[u] ← ∞
        π[u] ← NIL
    chave[r] ← 0
    Q ← V[G]
    enquanto Q ≠ ∅ faça
        u ← EXTRACT-MIN(Q)
        para cada v ∈ Adj[u] faça
            se v ∈ Q e w(u, v) < chave[v] então
                π[v] ← u
                chave[v] ← w(u, v)
```