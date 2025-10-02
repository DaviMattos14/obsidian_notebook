# Algoritmo de Kruskal

## 1. Descrição
O **algoritmo de Kruskal** encontra a Árvore Geradora Mínima (MST) adicionando arestas em ordem de peso crescente, sem formar ciclos.

## 2. Grafo de exemplo
Vértices: {0, 1, 2, 3}  
Arestas com pesos:  
- 0-1 (3), 0-2 (4), 1-3 (4), 1-2 (2), 3-2 (2)
![[Pasted image 20251001215250.png]]
## 3. Execução passo a passo
- Ordenar arestas: (1-2=2), (2-3=2), (0-1=3), (0-2=4), (1-3=4).  
- Adiciona (1-2), (2-3), (0-1) → conecta todos os vértices.  
![[Pasted image 20251001220324.png]]
- MST formada com peso total = 7.

## 4. Pseudocódigo
```pseudocode
KRUSKAL-MST(G, w)
    A ← ∅
    para cada v ∈ V[G] faça
        MAKE-SET(v)
    ordenar as arestas E[G] em ordem crescente de peso
    para cada aresta (u, v) ∈ E[G], na ordem crescente faça
        se FIND-SET(u) ≠ FIND-SET(v) então
            A ← A ∪ {(u, v)}
            UNION(u, v)
    retornar A
```