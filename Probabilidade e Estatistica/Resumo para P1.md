# Capítulo 1: Calculo de Probabilidade
**Espaço Amostral** ($Ω$) : Enumeração (finita ou infinita) de todos os resultados possíveis.

$\Omega = {A1, A2, A3, ...}$

**Evento (A):** Resultados ou conjunto de resultados possíveis. Chamamos ‘evento’ qualquer subconjunto do espaço amostral.

**Evento Impossível (∅)**: Conjunto Vazio, pois ele nunca acontecerá.

**Probabilidade ( P(A) ):** Probabilidade de um evento **A** ocorrer.

$$
P(A) = \frac {A}Ω
$$

### União - (A ∪ B)

> Pelo menos um ocorre

$P(A ∪ B) = P(A) + P(B) - P(A ∩ B)$

$P(A ∪ B) = P(A) + P(B)$, Para eventos mutuamente exclusivos.

### Interseção - (A ∩ B)

> A **e** B ocorrem

$P(A ∩ B) = P(A) \cdot P(B)$ - Eventos Independentes

$P(A ∩ B) = P(A) \cdot P(B|A)$ - Eventos Dependentes

$A ∩ (B ∪ C) = (A ∩ B) ∪ (A ∩ C)$ 

### Evento Complementar $(A^c)$

![Untitled](evento_complementar.png)

$P(A^c)=1-P(A)$

$(A ∩ B)^c = A^c ∪ B^c$

$(A ∪ B)^c = A^c ∩ B^c$

### Permutação e Combinação
Uma _permutação de k elementos_ é quando a ordem de sorteio importa, e a quantidade de possíveis permutações é dado por
$$
P_{n,k}=n(n-1)...(n-k+1)=\frac{n!}{(n-k)!}
$$

Uma _combinação de k elementos_ é quando a ordem não importa, e a quantidade de possíveis combinações é dada por
$$
\binom{n}{k} = \frac{P_{n,k}}{k!}=\frac{n!}{k!(n-k)!}
$$
### Axiomas de Probabilidade
Seja $\Omega$ um espaço amostral. Uma _probabilidade_ é uma função $\mathbb{P}$ que atribui a eventos $A \subseteq \Omega$ um número real $\mathbb{P}(A)$ e satisfaz os seguintes axiomas:
- $0 \le \mathbb{P}(A) \le 1$ ou $\mathbb{P}(A) \in [0,1]$
- $\mathbb{P}(\Omega) = 1$
- Para $A_1,A_2,...,A_n$ disjuntos e tomados 2 a 2:
$$
\mathbb{P}(\cup^\infty_{i=1} A_i)=\sum^\infty_{n=1}\mathbb{P}(A_n)
$$
### Propriedades de Probabilidade
1. $\mathbb{P}(A^c) = 1-\mathbb{P}(A)$
2. $A\subset B \rightarrow \mathbb{P}(A)\le \mathbb{P}(B)$
3. $\mathbb{P}(A\cup B) = \mathbb{P}(A) + \mathbb{P}(B) - \mathbb{P}(A\cap B)$
4.  Princípio da inclusão-exclusão
$$
\begin{alignat}{2}
\mathbb{P}(A\cup B \cup C) = \mathbb{P}(A)+\mathbb{P}(B) +\mathbb{P}(C)
\\ - \mathbb{P}(A\cap B)-\mathbb{P}(A\cap C)-\mathbb{P}(B\cap C) \\

+\mathbb{P}(A\cap B \cap C)
\end{alignat}
$$
5. Leis de Morgan
$$
\mathbb{P}(\cup^n_{i=1} A_i)=1-\mathbb{P}(\cap^n_{i=1} A^c_i)
$$
# Capítulo 2: Dependência e condicionamento
### Probabilidade Condicional
Para eventos A e B, a probabilidade condicional de _A dado B_ é definida como
$$
\mathbb{P}(A|B)=\frac{\mathbb{P}(A\cap B)}{\mathbb{P}(B)}
$$
### Independência
Dois eventos A e B são independentes se
$$
\mathbb{P}(A\cap B)=\mathbb{P}(A)\mathbb{P}(B)
$$
Independência é o <font color="#ff0000">oposto</font> de mutuamente exclusivos (disjuntos)!
Obs: $P(A|B) = P(A)$

### Teorema de Bayes
Se A e B são eventos com probabilidade positiva, então
$$P(A|B) = \frac{(P(A)⋅P(B|A))}{P(B)}$$
obs: $P(A∩B)=P(A)⋅(B|A)$
# # Capítulo 3: Variáveis aleatórias discretas
## Variável Aleatória
Seja $\Omega$ um espaço amostral. Uma <font color="#ff0000">variável aleatória</font> (v.a) é uma função
$$
X:w\in \Omega \rightarrow X(w)\in \mathbb{R}
$$
Varáveis aleatórias são _características numéricas_ de um experimento aleatório representado por $w$.

Também podemos usar a função $\mathbb{P}_x:A\rightarrow [0,1]$ definida por
$$
\mathbb{P}_x(A)=\mathbb{P}(X\in A)
$$
para calcula probabilidades
$\mathbb{P}_x$ é chama de distribuição de probabilidade da v.a. $X$.

## Variável Aleatória Discreta
Uma v.a. X é <font color="#ff0000">discreta</font> se o conjunto $Ω_X ⊂ R$  de _todos os valores possíveis de X_ (não confundir com Ω!) for enumerável.
A <font color="#ff0000">função massa de probabilidade</font> (f.m.p.) de uma v.a. X discreta é a função $p_X : Ω → [0, 1]$ dada por
$$p_X(x) = P(X = x).$$
> Exemplo:
$$
X =\left \{ \begin{matrix}0,&\text{se ocorrer } \{(C,C)\}\\ 1,&\text{se ocorrer }\{(C,K),(K,C)\}\\2, &\text{se ocorrer}\{(K,K)\} \end{matrix}\right.
$$
## Modelos de Variáveis Aleatórias Discretas
### Modelo Bernoulli
### Modelo Binomial
### Modelo Hipergeométrico
### Modelo Geométrico
### Modelo Binomial Negativo
### Modelo Poisson
