# Capítulo 1: Calculo de Probabilidade
**Espaço Amostral** ($Ω$) : Enumeração (finita ou infinita) de todos os resultados possíveis.

$\Omega = {A1, A2, A3, ...}$

**Evento (A):** Resultados ou conjunto de resultados possíveis. Chamamos ‘evento’ qualquer subconjunto do espaço amostral.

**Evento Impossível (∅)**: Conjunto Vazio, pois ele nunca acontecerá.

**Probabilidade ( P(A) ):** Probabilidade de um evento **A** ocorrer.

$$
P(A) = \frac {A}Ω
$$

## União - (A ∪ B)

> Pelo menos um ocorre

$P(A ∪ B) = P(A) + P(B) - P(A ∩ B)$

$P(A ∪ B) = P(A) + P(B)$, Para eventos mutuamente exclusivos.

## Interseção - (A ∩ B)

> A **e** B ocorrem

$P(A ∩ B) = P(A) \cdot P(B)$ - Eventos Independentes

$P(A ∩ B) = P(A) \cdot P(B|A)$ - Eventos Dependentes

$A ∩ (B ∪ C) = (A ∩ B) ∪ (A ∩ C)$ 

## Evento Complementar $(A^c)$

![Untitled](evento_complementar.png)

$P(A^c)=1-P(A)$

$(A ∩ B)^c = A^c ∪ B^c$

$(A ∪ B)^c = A^c ∩ B^c$

## Permutação e Combinação
Uma _permutação de k elementos_ é quando a ordem de sorteio importa, e a quantidade de possíveis permutações é dado por
$$
P_{n,k}=n(n-1)...(n-k+1)=\frac{n!}{(n-k)!}
$$

Uma _combinação de k elementos_ é quando a ordem não importa, e a quantidade de possíveis combinações é dada por
$$
\binom{n}{k} = \frac{P_{n,k}}{k!}=\frac{n!}{k!(n-k)!}
$$
## Axiomas de Probabilidade
Seja $\Omega$ um espaço amostral. Uma _probabilidade_ é uma função $\mathbb{P}$ que atribui a eventos $A \subseteq \Omega$ um número real $\mathbb{P}(A)$ e satisfaz os seguintes axiomas:
- $0 \le \mathbb{P}(A) \le 1$ ou $\mathbb{P}(A) \in [0,1]$
- $\mathbb{P}(\Omega) = 1$
- Para $A_1,A_2,...,A_n$ disjuntos e tomados 2 a 2:
$$
\mathbb{P}(\cup^\infty_{i=1} A_i)=\sum^\infty_{n=1}\mathbb{P}(A_n)
$$
## Propriedades de Probabilidade
1. $\mathbb{P}(A^c) = 1-\mathbb{P}(A)$
2. $A\subset B \rightarrow \mathbb{P}(A)\le \mathbb{P}(B)$
3. $\mathbb{P}(A\cup B) = \mathbb{P}(A) + \mathbb{P}(B) - \mathbb{P}(A\cap B)$
4.  Princípio da inclusão-exclusão
$$
\mathbb{P}(A\cup B \cup C) = \mathbb{P}(A)+\mathbb{P}(B) +\mathbb{P}(C)- \mathbb{P}(A\cap B)-\mathbb{P}(A\cap C)-\mathbb{P}(B\cap C) 
+\mathbb{P}(A\cap B \cap C)
$$
5. Leis de Morgan
$$
\mathbb{P}(\cup^n_{i=1} A_i)=1-\mathbb{P}(\cap^n_{i=1} A^c_i)
$$
# Capítulo 2: Dependência e condicionamento
## Probabilidade Condicional
Para eventos A e B, a probabilidade condicional de _A dado B_ é definida como
$$
\mathbb{P}(A|B)=\frac{\mathbb{P}(A\cap B)}{\mathbb{P}(B)}
$$
- $P(A|B) = 1-P(A^c|B)$
- $P(A_1 ∪ A_2|B) = P(A_1|B) + P(A_2|B) − P(A_1 ∩ A_2|B)$
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
$P(A|B)+P(A|B^c)=1$
# Capítulo 3: Variáveis aleatórias discretas
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
>Associa a cada valor possível da variável aleatória discreta suas respectiva probabilidade

Tal que,

$$
p(x) =\left \{ \begin{matrix}P(X=x_i),&i={1,2,3,...} \\ 0,& \text{ caso contrário} \end{matrix}\right.
$$

Satisfazendo, $p(x) \ge 0$ e $\sum_{x\in Rx} p(x) = 1$
## Modelos de Variáveis Aleatórias Discretas
### Modelo Bernoulli
> Sucesso ou Fracasso

$$
X \sim Ber(p) \hspace{1cm}(0 < p <1)
$$
$$
\mathbb{p}_X(x)=p^x(1-p)^{1-x} \hspace{20px}\text{para }x\in \{0,1\}
$$
- $E[X] = P$
- $Var(X) = P(1-P)$
### Modelo Binomial
$X \sim Bin(n,p)$

> Chama-se de experimento binomial ao experimento que 
> - consiste em n ensaios de Bernoulli
> - cujo ensaios são independentes, e
> - para qual a probabilidade de sucessos em casa ensaio é sempre igual a p $(0<p<1)$

$$
\begin{matrix} p_X=\mathbb{P}(X=x)= \dbinom{n}{x}\centerdot p^x\centerdot(1-p)^{n-x},\\ \dbinom{n}{x}= \frac {n!}{x!(n-x)!} & x \in \{0,1,2,...,n\}\end{matrix}
$$

- $E[X] = n \centerdot p$
- $Var(X)=n\centerdot p \centerdot (1-p)$
### Modelo Hipergeométrico
$X \sim Hip(m,n,k)$

>m $\rightarrow$ Sucessos
>n $\rightarrow$ Fracassos (N-m)
>k $\rightarrow$ Tamanho da amostra
>m+n $\rightarrow$ N ($\Omega$)

$$
p_X=\mathbb{P}(X=x)=\frac{\binom{m}{x}\centerdot \binom{n}{k-x}}{\binom{m+n}{k}}
$$
- $E[X] = \frac{k\cdot m}{m+n} =k\cdot \frac{m}{N}=kp$
- $Var(X)= \frac{k\cdot m}{m+n}\bigg[\frac{(k-1)(m-1)}{m+n-1}+1\bigg]=np(1-p)\frac{N-k}{N-1}$
### Modelo Geométrico
$X \sim Geom(p)$
> Número de repetições de um ensaio de Bernoulli com probabilidade de sucesso $(0<p<1)$até ocorrer o primeiro sucesso

$$
\mathbb{P}(X=x)=p\cdot(1 − p)^x \hspace{1cm},x \in \mathbb{N}
$$
- $E[X]= \frac{1}{p}$
- $Var(X)= \frac{1-P}{p^2}$
### Modelo Binomial Negativo
>Tentativas independentes com mesma probabilidade de sucesso $p ∈ [0, 1]$, sejam realizadas até que se acumule um total de $r$ sucessos.

$$
\mathbb{P}(X=x)=\binom{x-1}{r-1}p^r\cdot(1 − p)^{x-r},\hspace{1cm}
x \in \{r,r+1,...\}
$$
- $E[X]=\frac{r}{p}$
- $Var(X)=\frac{r(1-p)}{p^2}$

### Modelo Poisson
$X \sim Poi(\lambda)$
> Eventos Raros

$$
\begin{matrix} p(x) = e^{-\lambda} \centerdot \frac{\lambda^x}{x!}, & x=\{0,1,2,..\} \end{matrix}
$$

$E[X] = Var(x) = \lambda$

# Capítulo 4: Esperança e variância
### Valor Esperado (Esperança, média)

$$
\mathbb{E}(X) = \sum_{x \in \Omega_X}x\cdot\mathbb{P}(X=x)=\sum_{x \in \Omega_X}x\cdot p_X(x)
$$

Onde, $x$ é o valor de X, e $p(x)$ é a probabilidade de X.
O valor esperado é uma **constante**
O valor esperado é uma <font color="#ff0000">medida de centralidade</font>. Esse valor depende somente da distribuição da v.a. X, isto é, da f.m.p. $p_X$.
#### Linearidade da Esperança
Se X é v.a., então para todos os números reais $a$ e $b$
$$
\begin{matrix}
\mathbb{E}(\alpha X+b)=\alpha\mathbb{E}(X)+b \\
\mathbb{E}(\alpha X+\beta Y)=\alpha\mathbb{E}(X)+\beta \mathbb{Y}
\end{matrix}
$$
#### Esperança de Função de v.a.
$$
\mathbb{E}(g(x)) = \sum_{x \in \Omega_X}g(X)\cdot\mathbb{P}(X=x)
$$
### Variância e Desvio Padrão
- Variância
$$
Var(X) = \mathbb{E}((X-\mathbb{E}(X))^2)=\mathbb{E}(X^2)-(\mathbb{E}(X))^2 
$$
- Desvio Padrão
$$
DP(X)=\sqrt{Var(X)}
$$
# Capítulo 5: Distribuições de probabilidades conjuntas
## Distribuição conjunta 
Sejam X e Y v.a.s definidas no mesmo espaço amostral. O par (X,Y) é chamado vetor aleatório bidimensional

O vetor aleatório bidimensional (X,Y) é chamado discreto se X e Y são v.a.s discretas
A <font color="#ff0000">função de massa de probabilidade conjunta</font> do v.a. (X,Y) discreto é a função $p_{X,Y}(x,y)$ definida por
$$
p_{X,Y}(x,y)=\mathbb{P}(X=x,Y=y)\text{ para todo }(x,y)\in \Omega_X \times \Omega_Y
$$
$$
\begin{cases}
p_{X,Y}(x,y)=\mathbb{P}(X=x,Y=y)\text{ para todo }(x,y)\in \Omega_X \times \Omega_Y\\
\sum_{x\in \Omega_X} \sum_{y\in \Omega_Y} p_{X,Y}=1
\end{cases}
$$

## Distribuição Marginal
$$
p_X(x)=\sum_{y \in \Omega_Y} \mathbb{P}(X=x,Y=y)\text{ para todo }x\in \Omega_X
$$
$$
p_Y(y)=\sum_{x \in \Omega_X} \mathbb{P}(X=x,Y=y)\text{ para todo }y\in \Omega_Y
$$
## Independência
$$
\mathbb{P}(X=x,Y=y)=\mathbb{P}(X=x)\mathbb{P}(Y=y)
$$
## Distribuição Condicional
$$
p_{X|Y}(x|y) = \frac{p_{X,Y}(x, y)}{p_Y(y)} \quad \text{para todo} \quad x \in \Omega_X
$$

Note que a f.m.p. condicional  $p_{X|Y}$ satisfaz
$$
\begin{cases}
p_{X|Y}(x|y) \geq 0 \quad \text{para todo} \quad (x, y) \in \Omega_X \times \Omega_Y \\
\sum\limits_{x \in \Omega_X} p_{X|Y}(x|y) = 1 \quad \text{para cada} \quad y \in \Omega_Y
\end{cases}
$$
## Covariância
$$
\begin{matrix}
\text{Cov}(X, Y) = \mathbb{E}[(X - \mathbb{E}(X))(Y - \mathbb{E}(Y))]\\
= \mathbb{E}[XY] - \mathbb{E}[X]\mathbb{E}[Y] \quad (\text{Linearidade da esperança})
\end{matrix}
$$
As seguintes propriedades são imediatas da definição:
1. $\text{Cov}(X, X) = \text{Var}(X)$\)
2. $\text{Cov}(X, Y) = \text{Cov}(Y, X)$
3. $\text{Cov}(X, Z) = 0$, se Z é uma variável aleatória constante com probabilidade 1
4. $\text{Cov}(aX, Y) = a \cdot \text{Cov}(X, Y), \quad \text{para } a \in \mathbb{R}$
5. Para quaisquer números reais $a$, $b$, $c$ e $d$,
$$
\text{Cov}(aX + bY, cX + dY) = ac \cdot \text{Var}(X) + bd \cdot \text{Var}(Y) + (ad + bc) \cdot \text{Cov}(X, Y)
$$
# Capítulo 6: Variáveis Aleatórias Contínuas

> Uma $f(x)$ definida sobre o espaço amostral $(\Omega)$ e assumindo valores num intervalo de número reais, é dita uma variável aleatória contínua. Uma v.a. é contínua se existir $F_x: ℝ \to ℝ$, denominada **função de densidade de probabilidade (f.d.p.)**, satisfazendo:


$$
\begin{alignat}{2}
   f(x)\ge 0, \forall x \in \mathbb{R} \\
   P(a\le x \le b) = \int_a^b f(x) dx
\end{alignat}
$$
OBS: Satisfazendo $\int_{-\infty}^{+\infty}f(x)dx=1$

> Variável Aleatória Discreta $\to$  **Contagem**
> Variável Aleatória Contínua $\to$ **Medição**

- Função de Distribuição Acumulada (f.d.a.)
$$
\begin{matrix}F(x)=P(X\le x)=\int_{-\infty}^x f(t)dt, &x \subset\mathbb{R } \hspace{0.25cm} \forall f(x)=F'(x)\end{matrix}
$$

$E[X] = \int_{-\infty}^{+\infty}x\centerdot f(x)dx$

$Var(X)=\int_\mathbb{R} (x-E[X])^2\centerdot f(x)dx = E[X^2]\centerdot E[X]^2$

## Modelos Probabilísticos

### Modelo Uniforme Contínuo

$X\sim Uniforme(a,b)$

> Dizemos que X é uma variável uniforme no intervalo $[a.b], (a,b)\in \mathbb{R}, a<b$, se a função de densidade de probabilidade da variável x é constante nesse intervalo e nula fora dele
> 
- Função de densidade de probabilidade
    
    $$
    f(x)=\begin{cases}
    \frac{1}{b-a}, &a\le x\le b\\
    0, & \text{caso contrário}
    \end{cases}
    $$
    
- Função de distribuição
    
    $$
    F(x)= \begin{cases}
    0, & x \le a\\
    \frac{x-a}{b-a}, & a\le x \le b\\
    1, &x \ge b
    \end{cases}
    $$
    
- Esperança
    
    $$
    E[X]=\frac{a+b}{2}
    $$
    
- Variância
    
    $$
    Var(x)=\frac{(a+b)^2}{12}
    $$
    

### Modelo Exponencial

$X\sim Exp(\lambda)$

> Dizemos que X é uma variável exponencial com parâmetro $\lambda$, $\lambda > 0$, se a função de densidade de X é dada por:
> 

$$
f(x)=\begin{cases} 
\lambda \centerdot e^{-\lambda x}, & x \ge 0\\
0, & x <0
\end{cases}
$$

- Função de distribuição
    
    $$
    F(x)=\begin{cases}
    0, & x<0 \\
    1-e^{-\lambda x}, & x \ge 0 
    \end{cases}
    $$
    
- Esperança
    
    $$
    E[X]=\frac{1}{\lambda}
    $$
    
- Variância
    
    $$
    Var(X)=\frac{1}{\lambda^2}
    $$
    

### Modelo Normal

$X\sim N(\mu, \sigma^2)$

$$
\begin{matrix}
f(x)=\frac{1}{\sigma \centerdot \sqrt{2\pi}} \centerdot e^{-\frac{1}{2}(\frac{x-\mu}{\sigma})}, &\forall x \in \mathbb{R}
\end{matrix}
$$

#### Propriedades
- Esperança:  $E[X]=\mu$
- Variância:  $Var(x)=\sigma^2$
- A f.d.p. de X é simétrica com respeito a $X=\mu$, logo,
	$f_x(\mu+x)=f_x(\mu -x)$
- Em particular, $\phi(−z) = 1 − \phi(z)$, para todo $z \in R$
- $aX + b ∼ N(a\mu + b, a^2\sigma^2)$

#### Padronização
> Seja X uma v.a. tal que $E[X]=\mu$ e $Var(x)=\sigma^2$, para $N(\mu,\sigma^2)$
> Queremos $N(0,1)$,  Então: $E[Z]=0$ e $Var(Z)=1$
$$
X~N(\mu,\sigma^2)\rightarrow Z = \frac{X-\mu}{\sigma}~N(0,1)
$$
- $P(a\leq X \leq b) = P\Big(\frac{a-\mu}{\sigma}\leq Z \leq \frac{b-\mu}{\sigma}\Big)=\phi\Big(\frac{b-\mu}{\sigma}\Big)-\phi\Big(\frac{a-\mu}{\sigma}\Big)$
- $P(X\leq a)=P\Big(Z\leq\frac{a-\mu}{\sigma}\Big)=\phi\Big(\frac{a-\mu}{\sigma}\Big)$ 
- $P(X\geq a)=P\Big(Z\geq\frac{a-\mu}{\sigma}\Big)=1-\phi\Big(\frac{a-\mu}{\sigma}\Big)$ 
# Capítulo 7: Teorema Central do Limite e Lei dos Grandes Números
## Lei dos Grandes Números
>Sejam $X_1, X_2, . . .$ v.a. independentes e identicamente distribuídas (i.i.d.) com média $μ$ e variância $\sigma^2$ e $S_n := \sum^n_{i=1}X_i$ . Sabemos que
$$\begin{matrix}
E(S_n) = nμ && \text{Var}(S_n) = n\sigma^2
\end{matrix}
$$
 Se considerarmos a média $M_n:=\frac{S_n}{n}$, temos
$$
\begin{matrix}
E(M_n) = μ && \text{Var}(M_n) = \frac{\sigma^2}{n}
\end{matrix}
$$
#### Lei dos Grandes Números:
> Para todo $\epsilon > 0$, no limite $n\rightarrow\infty$
 $$
P(|M_n-\mu|\ge\epsilon)\rightarrow 0
$$
## Soma de variáveis aleatórias
> Dadas $n$ variáveis aleatórias $X_1,...X_n$, podemos definir uma nova variável aleatória como
$$
S_n\coloneqq \sum^n_{i=1}X_i
$$
### Distribuições da soma de variáveis aleatórias independentes
$$
\begin{align}
X_i\sim Ber(p) &&\rightarrow &&\sum^n_{i=1}X_i\sim Bin(n,p) \\
X_i\sim Bin(m_i,p) &&\rightarrow &&\sum^n_{i=1} X_i\sim  Bin\Big(\sum^n_{i=1}m_i,p\Big)\\
X_i\sim Poi(\lambda_i) && \rightarrow &&\sum^n_{i=1} X_i\sim  Poi\Big(\sum^n_{i=1}\lambda_i\Big)\\
X_i\sim N(\mu_i,\sigma^2_i) && \rightarrow &&\sum^n_{i=1} X_i\sim  N\Big(\sum^n_{i=1}\mu_i, \sum^n_{i=1}\sigma^2_i \Big)\\
\end{align}
$$
## Teorema Central do Limite
Sejam $X_1,X_2,...$ v.a. independentes e identicamente distribuídas (i.i.d) com média $\mu$ e variância $\sigma^2$ e $S_n\coloneqq \sum^n_{i=1}X_i$.
Consideramos uma nova variável aleatória
$$
Z_n = \frac{S_n-E(S_n)}{\sqrt{\text{Var}(S_n)}}=\frac{S_n-n\mu}{\sigma\sqrt{n}}
$$
Temos que $E(Z_n)=0$ e Var($Z_n$) $=1$. Isso significa que $Z_n$ tem uma distribuição que não se concentra ao redor do valor médio (a variância não vai para zero com $n$)
O TCL permite conhecer a distribuição limite de $Z_n$ (quando n $\rightarrow \infty$)
**Teorema Central do Limite**: A distribuição $Z_n$ se aproxima de uma normal padrão $Z\sim N(0,1)$, ou seja, para todos $x \in R$,
$$
P\bigg(\frac{\overline{X}-\mu}{\frac{\sigma}{\sqrt{n}}}\ge x\bigg) \rightarrow P(Z\geq x) = 1-\phi(x)
$$
$X_1, X_2, \dots$ i.i.d com média $\mu$ e variância $\sigma^2, S_n=\sum_{i=1}^n X_i$
$$
P(S_n \le c) = P\Bigg(\frac{S_n-\mu}{\sqrt{\frac{\sigma^2}{n}}}\le\frac{c-\mu}{\sqrt{\frac{\sigma^2}{n}}}\Bigg)\approx_{TCL} \phi\Bigg(\frac{c-\mu}{\sqrt{\frac{\sigma^2}{n}}}\Bigg)
$$
Onde $Z\sim N(0,1)$ e a aproximação melhora a medida que n cresce.
# Capítulo 8: Gráficos e Estatística Descritiva (Estatística)
>Estatística é um conjunto de conceitos e métodos para coletar, organizar, analisar e interpretar dados

<font color="#ff0000">Estatística descritiva</font>: se preocupa com a organização e apresentação dos dados observados (tabelas, gráficos, medidas descritivas como média e variância...)
<font color="#ff0000">Inferência estatística</font>: se preocupa de como dar informação sobre um universo (população) a partir de um conjunto de dados observados (amostra)

## Estatística Descritiva
População ($N$): conjuntos de todos os elementos sob investigação
Amostra ($n$): subconjuntos finitos da população
Parâmetro: característica numérica de uma população

Exemplo: Pesquisa eleitoral no estado do Rio de Janeiro
$$
\begin{matrix}
\text{população} &&→&& \text{todos os eleitores}\\
\text{amostra} &&→&& \text{1000 eleitores entrevistados}\\
\text{parâmetro} &&→ &&\text{idade média da população}\\
\end{matrix}
$$
### Tipologia de Variáveis
Dada uma população ou amostra, podemos estar interessados em várias características dos elementos constituintes; essas características são chamadas variáveis
- *Quantitativa*: assume um valor numérico
	- discreta: número finito ou enumerável 
	- contínua: número não enumerável
- *Qualitativa*: classificada em categorias
	- nominal: categorias não-ordenadas
	- ordinal: categorias ordenadas

### Distribuições de Frequências
*Distribuições de Frequências*: tabelas e gráficos
*Frequência absoluta*: número de vezes que cada valor é observado
*Frequência relativa*: número de vezes que cada valor é observado dividido pelo tamanho da amostra
*Frequência acumulada*: soma das frequências absolutas dos valores inferiores ou iguais ao valor dado

### Gráficos para variáveis qualitativas/quantitativas
- Gráfico de Barra (Barras, Histograma)
- Gráfico de Setores (de Pizza)
- Diagrama de Disperssão
- Boxplot

#### Construção de Boxplot
1. Encontre os 3 quartis
2. Classifica-se como outliers á direita, pontos que se encontram a mais de 1.5×(distância interquartílica) unidades à direita do 3º quartil
3. Classifica-se como outliers à esquerda, pontos que se encontram a mais de 1.5×(distância interquartílica) unidades á esquerda do 1º quartil
4. A linha se estende atá os valores mais extremos do conjunto de dados que não sejam outliers

### Medidas de Centralidade
Dada uma coleção de valores de uma variável quantitativa é útil definir formas de resumir esses dados. Uma maneira de fazer isso é através de *medidas de centralidade*.
- <font color="#ff0000">Média aritmética</font>: dados valores $x_1,...,x_n$, definimos
	$$
	\overline{x}\coloneqq \frac{\sum^n_{i=1}x_i}{n}
	$$
- <font color="#ff0000">Mediana</font>: dados valores $x_1,...x_n$, sejam $x_{1},x_{2}, ..., x_{n}$ os mesmos valores ordenados. Definimos $Q2$ como
	$$
	Q2 \coloneqq \begin{cases}
	x_{(\frac{n+1}{n})} & \text{se n é ímpar (valor na posição central)} \\
	\frac{x_{(\frac{n}{2})}+x_{(\frac{n}{2}+1)}}{2} & \text{se n é par (média dos valores nas posições centrais)}
	\end{cases}
	$$
- <font color="#ff0000">Moda</font>: é aquele valor que ocorre com mais frequência 

### Medidas de Dispersão
Para ter uma caracterização melhor outras medidas, chamada *medidas de dispersão* são introduzidas. Essas são indicadores do grau de espalhamento dos valores em torno da média
Dados os valores $x_1,...,x_n$, definimos
- Variância Amostral
	$$
	S^2 \coloneqq \frac{\sum^n_{i=1}(x_i-\overline{x})^2}{n-1}= \frac{\sum^n_{i=1}x_i^2-n\overline{x}^2}{n-1}
	$$
	- $E(S^2)=\sigma^2$ 
- Desvio Padrão Amostral
	$$
	s \coloneqq \sqrt{\frac{\sum^n_{i=1}(x_i-\overline{x})^2}{n-1}}
	$$
- Coeficiente de variação amostral:
	$$
	cv\coloneqq \frac{s}{\overline{x}}
	$$
# Capítulo 9: Intervalos de Confiança
## Estimativa Pontual
1. Uso $\overline{x}$ para estimar $E(x)$
2. Uso $S^2=\frac{1}{n-1}\sum(x_i-\overline{x})^2$ para estimar $\text{Var}(x)=\sigma^2$
3. Uso $S=\sqrt{S^2}$ para estimar $DP=\sqrt{\text{Var}(x)}=\sigma$

## Caso $\sigma$ conhecido
Se $$X \sim N(\mu, \frac{\sigma^2}{n})\rightarrow Z = \frac{\overline{X}-\mu}{\frac{\sigma}{\sqrt{n}}} \sim N(0,1)$$
![[nivel_de_confianca.png]]
Dado $\alpha \in (0,1)$, o valor de $(1-\alpha = \gamma)$  é o que chamamos de nível de confiança do intervalo $IC_{\mu}(\gamma)$. Em geral, $\gamma$ será um valor próximo de 1, como por exemplo $0.95,0.98$ ou até $0.99$.

### Construindo o intervalo
Digamos que $\gamma = 0.95$ e $\frac{\alpha}{2}=q$:
$$
\begin{aligned}
\gamma = 0.95 
&= P(-q< Z < q)\\
&=P(-q< \frac{\overline{X}-\mu}{\frac{\sigma}{\sqrt{n}}} < q)\\
&= P(-q\frac{\sigma}{\sqrt{n}}< \overline{X}-\mu < q\frac{\sigma}{\sqrt{n}})\\
&= p(-\overline{X}-q\frac{\sigma}{\sqrt{n}}< \mu <-\overline{X}+q\frac{\sigma}{\sqrt{n}})\\
&= p(\overline{X}-q\frac{\sigma}{\sqrt{n}}< \mu <\overline{X}+q\frac{\sigma}{\sqrt{n}})
\end{aligned}
$$
Logo,
$$
IC_{\mu}(\gamma)=\Bigg[\overline{X}-q\frac{\sigma}{\sqrt{n}};\overline{X}+q\frac{\sigma}{\sqrt{n}}\Bigg]
$$
Com $\gamma = 0.95$ temos, $q$ = 1.96.
(Procurar na tabela normal $P(Z < q) = \frac{\gamma +1}{2}=0.975 \rightarrow q$)

## Caso $\sigma$ desconhecido
Estimamos $\sigma^2$ usando $S^2$ e padronizamos $\overline{X}$ por:
$$
T = \frac{\overline{X}-\mu}{\frac{S}{\sqrt{n}}}
$$
A variável aleatória T é diferente de Z, e sua distribuição deixa de ser normal e passa a ser t-Student:
$$
T\sim(n-1)
$$
Onde, $(n-1)$ são graus de liberdade, e $n$ é o tamanho da amostra.
Portanto,
$$
IC_{\mu}(\gamma)=\Bigg[\overline{X}-t\frac{S}{\sqrt{n}};\overline{X}+t\frac{S}{\sqrt{n}}\Bigg]
$$

## Intervalos de Confiança para Proporção
Dada uma amostra $X_1, \dots, X_n \sim Bern(p)$:
$$
\overline{X} = \frac{X_1+\dots+X_i}{n} = \hat{p} \approx N(E(\overline{X}),\text{Var}(\overline{X})) \therefore N\Big(p,\frac{p(1-p)}{n}\Big)
$$
- $E(\overline{X}) = E(X_i)=p$
- $\text{Var}(\overline{X}) = \frac{\text{Var}(X_i)}{n}=\frac{p(1-p)}{n}$
- Z = $\frac{\hat{p}-p}{\sqrt{\frac{p(1-p)}{n}}} \approx N(0,1)$
Temos que,
$$
IC^*_{p}(\gamma)=P\Bigg( \hat{p}-q\sqrt{\frac{p(1-p)}{n}} < p < \hat{p}+q\sqrt{\frac{p(1-p)}{n}}\Bigg)
$$
 Onde $q = \frac{1+\gamma}{2}$.
 **Abordagem não conservadora**: Substituímos $p$ na equação por $\hat{p}$
 **Abordagem conservadora**: Consideramos um $\gamma$ acima do nível de confiança fixado inicialmente
$$
IC_{\mu}(\gamma)=\Bigg[\hat{p}-q\frac{1}{\sqrt{4n}};\hat{p}+q\frac{1}{\sqrt{4n}}\Bigg]
$$
# Capítulo 10: Testes de Hipóteses
## Construção de Testes de Hipóteses
Considere $X_1, \dots, X_n$ uma amostra aleatória com $E(X_i)=\mu$ e $\text{Var}(X_i)=\sigma^2$
Formulamos duas hipóteses:
$$
\begin{cases}
H_0: \mu = x, & \text{Hipótese Nula}\\
H_1: \mu \neq x,&\text{Hipótese Alternativa}
\end{cases}
$$
Calcule a média amostral: $\overline{X}$

### Tipos de Erro
- <font color="#ff0000">Tipo 1</font>: Rejeitar $H_0$ dado que $H_0$ é verdade
- <font color="#ff0000">Tipo 2</font>: Não rejeitar $H_0$ dado que $H_0$ é falsa (i.e. dado $H_1$)

## Realização de Testes de Hipóteses
1. Defina um nível de significância $\alpha$ (1%, 5%, 10%)
2. Definir uma Regra de Decisão:
	$\alpha$ = P(Rejeitar $H_0$|$H_0$ verdade) = $P\Bigg(\Bigg|\frac{\overline{X}-\mu}{\frac{S}{\sqrt{n}}}\Bigg| \neq q | \mu = x\Bigg)$
3. Achar $q = t_{n-1}\text{(t-Student)}$  que vai determinar a regra de decisão de teste.

## Teste para Proporções
$X_1,\dots, X_n$: Amostra aleatória $X_i \sim Bern(p)$
![[teste_hipotese_proporcao.png]]
### Estatística de Teste:
$$
Z = \Bigg(\Bigg|\frac{\hat{p}-p}{\sqrt{\frac{p(1-p)}{n}}}\Bigg| \neq q | \mu = \overline{x}\Bigg)
$$
## P-Valor
P-valor é a probabilidade sob $H_0$ de observarmos um valor mais extremo (de acordo com $H_1$) para estatística de teste do que aquele observado na amostra.
**Regra de Teste**: Rejeitamos $H_0$ se P-valor $< \alpha$
Quanto <font color="#ff0000">menor</font> o p-valor mais evidência temos contrária a $H_0$
![[p_valor.png]]