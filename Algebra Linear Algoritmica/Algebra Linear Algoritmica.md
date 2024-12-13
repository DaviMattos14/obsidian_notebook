## Operações Elementares
1. $L_i \rightarrow k \cdot L_i$ (Multiplicar uma linha por um escalar $K$, ex: $2, \frac{1}{2}$)
2. $L_i \leftrightarrow L_j$ (Inverter linhas)
3. $L_i \rightarrow L_i + k \cdot L_j$ (Somar duas linhas)

### Semântica $\rightarrow$ Sintática
$$
\text{Usuário}
\begin{cases}
3x_1+2x_2+5x_3=y_1 \\
4x_1+5x_2+10x_3=y_2 \\
4x_1+10x_2+10x_3=y_3 \\
\end{cases}
\rightarrow
\text{Programador}
\begin{bmatrix}
&X_1 & X_2 & X_3 & y_1 & y_2 & y_3\\  
(\text{Eq. }1)&3 & 2 & 5 & 1 & 0 & 0\\ 
(\text{Eq. }2)&4 & 5 & 10 & 0 & 1 & 0\\ 
(\text{Eq. }3)&4 & 10 & 10 & 0 & 0 & 1\\
\end{bmatrix}
$$
Resolvemos na **sintaxe** e verificamos no modo **semântico**
###### Matriz:
$$
\Huge\Downarrow
$$
$$
\begin{align}
A_{(1,1)}x_1 + A_{(1,2)}x_2 + A_{(1,3)}x_3 = y_1 \\
A_{(2,1)}x_1 + A_{(2,2)}x_2 + A_{(2,3)}x_3 = y_2 \\
A_{(3,1)}x_1 + A_{(3,2)}x_2 + A_{(3,3)}x_3 = y_3 \\
\end{align}
\rightarrow
\begin{bmatrix}
a_{(1,1)} & a_{(1,2)}& a_{(1,3)} \\
a_{(2,1)} & a_{(2,2)}& a_{(2,3)} \\
a_{(3,1)} & a_{(3,2)}& a_{(3,3)} \\
\end{bmatrix}
\cdot
\begin{bmatrix}
x_1\\x_2\\x_3
\end{bmatrix}
=
\begin{bmatrix}
y_1\\y_2\\y_3
\end{bmatrix}
$$
### Composição de Função
$$
\begin{gather}
f:R^2\rightarrow R^2 & g:R^2\rightarrow R^2\\
f\bigg(\begin{bmatrix}x_1\\x_2\end{bmatrix}\bigg) = \begin{bmatrix}3x_1+2x_2\\5x_1+4x_2\end{bmatrix} &
g\bigg(\begin{bmatrix}x_1\\x_2\end{bmatrix}\bigg) = \begin{bmatrix}10x_1+11x_2\\14x_1+5x_2\end{bmatrix}
\end{gather}
$$
Exemplo: $g(f(x))$
$$
f\bigg(\begin{bmatrix}3x_1+2x_2\\5x_1+4x_2\end{bmatrix}\bigg) = \begin{bmatrix}10(3x_1+2x_2)+11(5x_1+4x_2)\\14(3x_1+2x_2)+5(5x_1+4x_2)\end{bmatrix}=
\begin{bmatrix}85x_1+62x_2\\67x_1+48x_2\end{bmatrix}
$$
$$
\begin{gather}
f\bigg(\begin{bmatrix}x_1\\x_2\end{bmatrix}\bigg) = \begin{bmatrix}3&2\\5&4\end{bmatrix}\cdot \begin{bmatrix}x_1\\x_2\end{bmatrix}&
g\bigg(\begin{bmatrix}x_1\\x_2\end{bmatrix}\bigg) = \begin{bmatrix}10&11\\14&5\end{bmatrix} \cdot
\begin{bmatrix}x_1\\x_2\end{bmatrix}
\end{gather}
$$
$$
g \circ{f} \bigg(\begin{bmatrix}x_1\\x_2\end{bmatrix}\bigg) = 
\begin{bmatrix}10&11\\14&5\end{bmatrix}^A\cdot\begin{bmatrix}3&2\\5&4\end{bmatrix}^B \cdot\begin{bmatrix}x_1\\x_2\end{bmatrix} = 
\begin{bmatrix}85&62\\67&48\end{bmatrix}^C
\cdot \begin{bmatrix}x_1\\x_2\end{bmatrix}
$$
Onde $A\cdot B = C$, é o mesmo que $A_{(\text{Linha i})} \cdot B_{(\text{Coluna j})} = C_{(i,j)}$ 
Exemplo: $\begin{bmatrix}10&11\\14&5\end{bmatrix}^A\cdot\begin{bmatrix}3&2\\5&4\end{bmatrix}^B = \begin{bmatrix}((A_{(1,1)}\cdot B_{(1,1)})+(A_{(1,2)}\cdot B_{(2,1)}) )&((A_{(1,1)}\cdot B_{(2,1)})+(A_{(1,2)}\cdot B_{(2,2)}) )\\((A_{(2,1)}\cdot B_{(1,1)})+(A_{(2,2)}\cdot B_{(2,1)}) )&((A_{(2,1)}\cdot B_{(1,2)})+(A_{(2,2)}\cdot B_{(2,2)}) )\end{bmatrix}$
### Função Inversa
$f(x)=y \leftrightarrow x = g(y)$ 
$$
\begin{cases}
x_1+3x_2 = y_1\\
x_1+4x_2 = y_2
\end{cases}
\hspace{6px}
\underrightarrow{\text{Gauss-Jordan}\hspace{6px}}
\hspace{6px}
\begin{cases}
x_1=y_1-3(y_2-y_1)\\
x_2=y_2-y_1
\end{cases}
\rightarrow
\begin{cases}
x_1=4y_2-3y_2\\
x_2=y_2-y_1
\end{cases} \rightarrow x=g(y)
$$
$$
g\bigg(\begin{bmatrix}y_1\\y_2\end{bmatrix}\bigg) = \begin{bmatrix}4y_2-3y_2\\
y_2-y_1
\end{bmatrix}
$$
##### Teorema: $f(g(y)) = y \leftrightarrow g(f(x))=x$
##### Vetores Linearmente Independentes
$$
\begin{bmatrix}
&x_1&x_2&x_3&x_4&x_5\\
\text{(Eq 1)}& 1 & 0& 0& 0& 0\\
\text{(Eq 2)}& 0& 0 & 1& 0& 0\\
\text{(Eq 3)}& 0& 0& 0& 1& 0\\
\end{bmatrix}
$$
Onde, $x_2\text{ , } x_5$ são **variáveis dependentes** e $x_1\text{ , }x_3\text{ , }x_4$ são **variáveis independentes**, ou seja, $x_2 \text{ e } x_5$ podem ser escritos como combinação linear de $x_1\text{ , }x_3\text{ , }x_4$.
## Matriz Inversa
Se $b = Ax$ então $A^{-1}b=x$, ou seja
$$
A\cdot A^{-1}= A^{-1}\cdot A=1
$$
<font color="#ff0000">Obs</font>: A inversa existe se, e somente se, a eliminação produzir $n$ pivôs
Se $\text{Det}(A)=0$, então não tem inversa
##### Matriz quadrada $2\times 2$
$$A^{-1} \leftrightarrow 
\begin{bmatrix}
a & b \\
c & d
\end{bmatrix}^{-1}
=\frac{1}{Det(A)}
\begin{bmatrix}
a & -b \\
-c & d
\end{bmatrix}

$$
## Determinante
$$
\text{Det}\bigg(\begin{bmatrix}
a & b \\
c & d
\end{bmatrix}\bigg) = ad-bc
$$
#### Propriedades
- $\text{Det}(I)=1$
- $\text{Det}(A^{-1})=\frac{1}{\text{Det}(A)}$
- $\text{Det}(AB)=\text{Det}(A)\cdot \text{Det}(B)$
- $\text{Det}(A^T)=\text{Det}(A)$
## Transformações Lineares
Toda matriz simétrica A pode ser descrita como:
$$
A\bigg(
\begin{bmatrix}
x \\
y
\end{bmatrix}
\bigg) = 
R_{\theta}(T(R_\theta^{-1}))
$$
Ou seja, $R_\theta \begin{bmatrix}a & b \\c & d\end{bmatrix} R^{-1}_\theta=A$
#### Identidade
$$A=
\begin{bmatrix}
1 & 0 \\
0 & 1
\end{bmatrix}
\begin{bmatrix}
x_1 \\
y_1 
\end{bmatrix}
=
\begin{bmatrix}
x_2\\
y_2
\end{bmatrix}
$$
#### Cisalhamento
$$
A=
\begin{bmatrix}
1 & a \\
b & 1
\end{bmatrix}
$$
#### Rotação
$$
R_{\thetaº}=
\begin{bmatrix}
\cos{\theta} & -\sin{\theta} \\
\sin{\theta} & \cos{\theta}
\end{bmatrix}
$$
#### Reflexão
$$
A=
\begin{bmatrix}
0 & 1 \\
1 & 0
\end{bmatrix}
$$
#### Projeção (no eixo $x$)
$$
A=
\begin{bmatrix}
1 & 0 \\
0 & 0
\end{bmatrix}
$$

##### Regra de Linearidade
Para c e d escalares e A, V e W vetores:
$$
A(cV+dW)=c(AV)+d(AW)
$$
## Autovalores e Autovetores
$$
Av=\lambda v
$$
Manipulando a equação acima:
$$
\begin{align}
Av=\lambda v \\
Av-\lambda v= \overline{0} \\
Av-\lambda \text{I}v = \overline{0}\\
(A-\lambda\text{I})v=\overline{0}
\end{align}
$$
Como consequência, sabemos que: $det(A-\lambda\text{I})=\overline{0}$
# Espaços Vetoriais
Um espaço vetorial é um conjunto V, não vazio, munido de duas operações:
- Soma ($V\times V\rightarrow V$)
- Produto ($\mathbb{R} \times V \rightarrow V$)
Temos que,
1. $(\overrightarrow{u}+\overrightarrow{v})+\overrightarrow{w}=\overrightarrow{u}+(\overrightarrow{v}+\overrightarrow{w})$ - Comutatividade
2. $\overrightarrow{u}+\overrightarrow{v}=\overrightarrow{v}+\overrightarrow{u}$
3. $\exists\space \overline{0}\in V \space|\space \overrightarrow{u}+\overline{0}=u$ 
4. $\exists \space -\overrightarrow{u} \in V\space | \space \overrightarrow{u} + (-\overrightarrow{u})=\overline{0}$
5. $a(\overrightarrow{u}+\overrightarrow{v})=a\overrightarrow{u}+a\overrightarrow{v}$
6. $(a+b)\overrightarrow{v}=a\overrightarrow{v}+b\overrightarrow{b}$
7. $(ab)\overrightarrow{v}=a(b\overrightarrow{v})$
8. $1\times\overrightarrow{u}=\overrightarrow{u}$

## Subespaço vetorial
Seja V um espaço vetorial. $W\subset C$ é um subespaço vetorial se $\overline{0} \in W$ e:
- $\overrightarrow{u} + V \in W$
- $a\overrightarrow{u} \in W, \forall a \in \mathbb{R}$

### Espaço Coluna ($c(A)$)
Dado o SL $A_{m\times n}x_n=b_m$ 
	Se A é inversível, a solução do SL é única
	Se A não tem inversa, há infinitas soluções ou nenhuma

De um modo gera
$$
Ax+b=A_1x_1+A_2x_2+\dots+x_nA_n=b
$$
onde $A_n$ é a i-ésima vetor coluna de A.
Para que o SL tenha solução, é preciso que $b$ possa ser descrito como uma combinação linear de A.
$Ax=b$ tem solução $\leftrightarrow$ $b$ está no espaço coluna de A

### Espaço Nulo ou Núcleo ($n(A)$)
O espaço nulo, ou núcleo, do SL homogêneo, é o conjunto de vetores que satisfazem $A_{m\times n}x_n=\overline{0}$ .
OBS: A quantidade de variáveis livres (variáveis que são combinações lineares) nos diz a dimensão do vetor

### Espaço Linha e Posto de A ($c(A^T)/r(A)$)
O posto de uma matriz $A_{m\times n}$ é o número de pivôs, ou seja, o número de linhas não nulas da matriz escalonada.
Os vetor colunas que não tem pivôs são combinações lineares as colunas com pivôs.

1. $r(A)=m=n$
	- Matriz quadrada invertível
	- $Ax=b$ tem solução única
	- Posto linha completo, posto coluna completo
2. $r(A) = m <n$
	- $Ax=b$ tem infinitas sol.
	- Posto linha completo
3. $r(A) = n<m$
	- $Ax=b$ tem 1 ou 0 sol.
	- Posto coluna completo
4. $r(A)<n,r(A)<m$
	- $Ax=b$ tem 0 ou infinitas sol.

As colunas de A são linearmente independentes (LI) quando $r(A) = n$, ou seja, há $n$ pivôs e nenhum variável livre. $\rightarrow N(A)=\{0\}$

Um conjunto de vetores é uma base de um espaço vetorial se:
	Não são nulos
	São LI
	Eles geram o espaço
A Dimensão de um espaço vetorial é a quantidade de vetores na base, ou seja, é a quantidade mínima necessária para representarmos um vetor qualquer do espaço como combinação linear dos vetores.

# Teorema Fundamental da Algebra Linear
$c(A)$ tem dimensão $r(A)$ e $N(A^T)$ tem dimensão $m-r(A)$, ambos são subespaço $R^m$
$c(A^T)$ tem dimensão $r(A)$ e $N(A)$ tem dimensão $n-r(A)$, ambos são subespaços de $R^n$
$N(A)$ é o complemento ortogonal de $c(A^T)$
$N(A^T)$ é o complemento ortogonal de $c(A)$

Complemento ortogonal ($V^{\perp}$) é o conjunto de vetores que é ortogonal a um subespaço 
# Produto Interno
$$
<w,v>=w^Tv=[w_1\space w_2]\begin{bmatrix}v_1\\v_2\end{bmatrix}=w_1v_1+w_2v_2
$$
**Propriedades**
- $w^Tv=v^Tw$
- $||v||^2=v^tv=v_1^2+v_2^2$
- 
# Ortogonalidade
Dois vetores são ortogonais se $p^Tv=\overline{0}=<p,v>$.
Se p e v são ortogonais então:
$$
||p+v||^2=||p||^2+||v||^2
$$
Dois espaços vetoriais V e W são ortogonais se todos os vetores de V são ortogonais a todos vetores de W.

 # Projeção
![[projecao.png]]
Seja $e = v-p$, temos que $P=\alpha \overrightarrow{u}$
$$
\alpha=\frac{u^Tv}{u^Tu}
$$
Seja P um operador que leva qualquer vetor $\overrightarrow{v}$ ao vetor P, então
$$ Pv=p$$
$$p = \alpha u =u\frac{u^Tv}{u^Tu} =\frac{uu^T}{u^Tu}v$$
obs: $v^Tu=u^Tv$
Logo,
$$
P = \frac{uu^T}{u^Tu}
$$

**Tamanho**: $||v||$
obs: $||v||^2=v^Tv$
**Distância**: $d(v,w) = ||v-w||$
**Ângulo**: $cos(\theta)=\frac{P_vw}{w}$
**Projeção ortogonal de W em V**: $P_v(w)=(\frac{w^Tv}{||v||^2})\cdot v$
**Tamanho da projeção**: $w^T\cdot \tilde{v}$
**Normalização**: $\tilde{v}=\frac{v}{||v||}$

## Projeção sobre um subespaço
$$
\begin{matrix}
A^TA{}=A^Tv\rightarrow \overline{x}=(A^TA)^{-1}A^Tv \\
p = A(A^TA)^{-1}A^Tv \rightarrow\text{Projeção de v sobre o espaço}\\
P=A(A^TA)^{-1}A^T \rightarrow\text{Matriz de Projeção}
\end{matrix}
$$
# Bases Ortogonais e Gran-Schmitt
Os vetores são ortonormais se:
$$
<z_i,z_j>=z_i\cdot z_j=z_i^T\cdot z_j=\begin{cases}0&\text{se i}\neq j\\
1& \text{se i}=j\end{cases}
$$
Seja A uma matriz cujas as colunas são LI
Queremos transformar essas colunas em vetores ortonormais, ou seja, transformar A em Q.
tomar $e_1=q_1=\frac{u_1}{||u_1||}=\frac{v_1}{||v_1||}$
Para $$\text{proj}_{u}(v)=\frac{<v,u>}{<u,u>}u=\frac{v^Tu}{u^Tu}u$$
Então,
$$
\begin{matrix}
u_1=v_1, &&q_1=\frac{u_1}{||u_1||}\\
u_2=v_2-\text{proj}_{u_1}(v_2) &&q_2=\frac{u_2}{||u_2||}\\
u_3 =v_3 - \text{proj}_{u_1}(v_3)-\text{proj}_{q_2}(v_3) && q_1=\frac{u_3}{||u_3||}\\
u_4 =v_4 - \text{proj}_{u_1}(v_4)-\text{proj}_{q_2}(v_4)-\text{proj}_{q_3}(v_4) && q_1=\frac{u_4}{||u_4||}
\\\vdots &&\vdots \\
u_k=v_k\sum\text{proj}_{q_j}(v_k) && q_k=\frac{u_k}{||u_k||}
\end{matrix}
$$
![[Gram-Schmidt.png]]

**OBS:**
$A=Q\cdot R \rightarrow R = Q^TA$

## Fatoração QR
- $A=QR$, mutiplique ambos os lador por $Q^T$:
- $Q^T A = Q^T Q R$
- Dado $Q^TQ=I$, teremos $R=Q^TA$
- Dados $A = \Bigg[ \mathop{\mathbf a_1}\limits_|^| \ \mathop{\mathbf a_2}\limits_|^| \ \cdots \ \mathop{\mathbf a_n}\limits_|^| \Bigg]$ e $Q = \Bigg[ \mathop{\mathbf q_1}\limits_|^| \ \mathop{\mathbf q_2}\limits_|^| \ \cdots \  \mathop{\mathbf q_n}\limits_|^| \Bigg]$
- Então: $<q,a>=q^ta=q_1a_1+q_2a_2+\dots$
$$
R = Q^T A = \begin{bmatrix} \mathbf q_1^T \mathbf a_1 & \mathbf q_1^T \mathbf a_2 & \cdots & \mathbf q_1^T \mathbf a_n \\\mathbf q_2^T \mathbf a_1 & \mathbf q_2^T \mathbf a_2 & \cdots & \mathbf q_2^T \mathbf a_n \\\vdots & \vdots & \ddots & \vdots \\\mathbf q_n^T \mathbf a_1 & \mathbf q_n^T \mathbf a_2 & \cdots & \mathbf q_n^T \mathbf a_n \\\end{bmatrix}=\begin{bmatrix} 
\mathbf q_1^T \mathbf a_1 & \mathbf q_1^T \mathbf a_2 & \cdots & \mathbf q_1^T \mathbf a_n \\
0 & \mathbf q_2^T \mathbf a_2 & \cdots & \mathbf q_2^T \mathbf a_n \\
\vdots & \vdots & \ddots & \vdots \\
0 & 0 & \cdots & \mathbf q_n^T \mathbf a_n \\
\end{bmatrix}
$$
# Determinante
Dada uma matriz $A_{m\times n}$, $A=[A_{ij}]$, então
$$
det(A)=|A|=det[A_{ij}]=\sum(-1)^ja_{1f1}\cdot a_{1f2}\times \dots \times a_{nfn}
$$
Onde $j = (j_1, j_2, ..., j_n)$ é o número de inversões para cada permutação de$\left\lbrace 1, 2, ..., n\right\rbrace = (f_1,f_2,f_3,\dots)$
Exemplo: $j = (0,1) \rightarrow f=\{(1,2),(2,1)\}$ e $A = A_{2\times2}$
$$
det(A)=(-1)^0 a_{11}\cdot a_{22}+(-1)^1a_{12}\cdot a_{21}=a_{11}\cdot a_{22}-a_{12}\cdot a_{21}
$$
Generalizando:
$$
det(A)=\sum(-1)^{i+j}a_{ij}|A_{ij}|
$$
onde $|A_{ij}|$ é uma matriz formada após se retirar de A a linha i e coluna j.
# Matriz Adjunta
Definimos o cofator $\Delta_{ij}$ do elemento $a_{ij}$ de uma matriz $A_{m\times n}$, por
$$
\Delta_{ij}=(-1)^{i+j}det(A_{ij})
$$
onde $A_{ij}$ é a submatriz de A obtida após retirar a linha i e a coluna j.
A matriz $\overline{A}$ de cofatores de A é definida por $A=[\Delta_{ij}]$ e a matriz adjunta é definida por $\text{adj}(A)=\overline{A}$.

Teorema: $A\cdot A^{-1}=A\cdot \text{adj}(A)=det(A)I$.

# Autovalores e Autovetores
$$
A = X D X^{-1}
$$
onde $D$ é uma matriz diagonalizável, $X$ é a matriz de autovetores invertível.
$$
Av=\lambda v
$$
Manipulando a equação acima:
$$
\begin{align}
Av=\lambda v \\
Av-\lambda v= \overline{0} \\
Av-\lambda \text{I}v = \overline{0}\\
(A-\lambda\text{I})v=\overline{0}
\end{align}
$$
Como consequência, sabemos que: $det(A-\lambda\text{I})=\overline{0}$
