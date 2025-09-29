# 1. Representação de Grafos

Um grafo $G=(V,E)$ é um objeto matemático composto por um conjunto de vértices ($V$), também chamados de nós, e por um conjunto de arestas ($E$), onde cada aresta em $E$ é um subconjunto de dois elementos de vértices $V$. 
Seja $u$ e $v$ vértices de G. Uma aresta é direcionada se seu par de subconjuntos for ordenado, por exemplo, $(u, v)$, e não direcionada se seu par de subconjuntos for não ordenado, por exemplo, $\{u, v\}$ ou, alternativamente, tanto $(u, v)$ quanto $(v, u)$

Com isso grafos podem ser **direcionados** e **não direcionados**
#### Grafo Direcionado
Uma aresta direcionada $e=(u,v)$ estende-se do vértice $u$ para o vértice $v$ ($u \longrightarrow v$), com $e$ sendo uma aresta de *entrada* de v e uma aresta de *saída* de u.
$$
\begin{matrix}
G_{1}= (V_1,E_1) & V_1=\{0,1,2,3,4\} & E_1=\{(0,1),(1,2),(2,0),(3,4)\}
\end{matrix}
$$![[Pasted image 20250929152057.png]]
Outros exemplos de representação:
![[grafo_direcionado.png]]
#### Grafo Não Direcionado
Em um grafo não direcionado, toda aresta é de entrada e de saída.
$$
\begin{matrix}
G_{2}= (V_2,E_2) & V_2=\{0,1,2,3,4\} & E_2=\{\{0,1\}\{0,3\},\{0,4\},\{2,3\}\}
\end{matrix}
$$
![[Pasted image 20250929152234.png]]Outros exemplos:
![[Pasted image 20250929152322.png]]
