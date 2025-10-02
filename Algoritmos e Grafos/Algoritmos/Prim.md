# Algoritmo de Prim

## 1. Descrição
O **algoritmo de Prim** encontra a Árvore Geradora Mínima (MST) crescendo uma árvore a partir de um vértice inicial.

## 2. Grafo de exemplo
Vértices: {0, 1, 2, 3}  
Arestas com pesos:  
- 0-1 (3), 0-2 (4), 1-3 (4), 1-2 (2), 3-2 (2)
![[Pasted image 20251001215250.png]]
## 3. Execução passo a passo (raiz = A)
- Início: chave[0]=0, os outros = ∞.  
![[Pasted image 20251001215333.png]]
- Escolhe 1, adiciona aresta 0-1 (3).  
![[Pasted image 20251001215432.png]]
- Escolhe 2 via 1-2 (2).  
![[Pasted image 20251001215526.png]]
- Escolhe 3 via 3-2 (2).  
![[Pasted image 20251001215621.png]]
- MST final: arestas {0-1, 1-2, 2-3}, peso total = 7.
![[Pasted image 20251001215710.png]]
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