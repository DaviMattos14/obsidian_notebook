# Algoritmo de Kruskal

## 1. Descrição
O **algoritmo de Kruskal** encontra a Árvore Geradora Mínima (MST) adicionando arestas em ordem de peso crescente, sem formar ciclos.

## 2. Grafo de exemplo
Vértices: {A, B, C, D}  
Arestas com pesos:  
- A-B (1), B-C (2), C-D (3), A-D (4), B-D (5)

## 3. Execução passo a passo
- Ordenar arestas: (A-B=1), (B-C=2), (C-D=3), (A-D=4), (B-D=5).  
- Adiciona A-B, B-C, C-D → conecta todos os vértices.  
- MST formada com peso total = 6.

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