# Modelagem Matemática
A modelagem, que trata de representação quantitativa de processos de problemas reais, é de grande importância nas diversas áreas do conhecimento. O objetivo de um modelo matemático é reproduzir o realidade da forma mais fiel possível, buscando entender o mundo real e obtendo as respostas que podem resultar a partir de ações.

## Formulação de um Modelo
1. Compreender o problema
2. Descrever o objetivo
3. Definir as variáveis de decisão
4. Descrever cada restrição
5. Escrever o objetivo em termos das variáveis de decisão
6.  Escrever as restrições em termos das variáveis de decisão

## Modelagem em Programação Linear (PPL)
==Hipóteses de Linearidade==
Nos modelos de programação linear são admitidas algumas hipóteses que as grandezas envolvidas precisam obedecer:
- Proporcionalidade
- Aditividade
- Não integralidade de solução (fracionamento ou divisibilidade)
- Determinística

### Exemplo
*Uma empresa pode fabricar dois produtos (1 e 2).*

*Na fabricação do produto 1 a empresa gasta nove horas-homem e três horas-máquina. Margem de lucro R$ 4000,00*
*Na fabricação do produto 2 a empresa gasta uma hora-homem e uma hora- máquina. Margem de lucro R$1000,00*
*A empresa dispõe de 18 horas-homem e 12 horas-máquina para um período de produção.*

*Quanto a empresa deve fabricar de cada produto para ter o maior lucro?*

#### Primeiro descrevemos o objetivo (Função Objetiva)
A função lucro (<font color="#ff0000">função objetivo</font>)
Tem-se a decidir quanto produzir do produto ==1== ($x_1$)e quanto produzir do produto ==2==($x_2$). Assim consideramos como ==variáveis== as quantidades a serem produzidas da cada produto respectivamente
O lucro $L$ depende da quantidade de cada produto
$$
z = 4x_1 + x_2
$$
#### Descrevendo as restrições
Não se pode utilizar o que não se tem!
A quantidade utilizada deve ser menor ou igual a quantidade disponível.
As quantidades de fabricação devem ser não negativas
$$
\begin{matrix}
\text{(Hora Homem)} && 9x_1+x_2 \le 18 \\
\text{(Hora Máquina)} && 3x_2 + x-2 \le 12 \\
x_1 \ge 0 && x_2 \ge0
\end{matrix}
$$
#### Problema de Programação Linear - PPL
![[ex_ppl.png]]

#### Resolução Geométrica
![[nao_negatividade.png]]![[restricao1.png]]![[restricao2.png]]![[conjunto_viavel1.png]]![[conjunto_viavel.png]]
#### Possíveis Melhores Soluções
![[sol_possiveis.png]]

Como queremos Maximizar $x_1$ **e** $x_2$, então podemos desconsiderar **P1, P2 e P4**
Logo, substituindo $P4$, na função objetiva, $z=4x_1+x-2$, temos:
$$
\begin{matrix}
(1,9) && 4\cdot1+9=13\\
\end{matrix}
$$
Então a solução ótima é $x_1=1$ e $x_2=9$, para o valor ótimo $=13$

# Problema de Programação Linear - PPL
==PPL Inteira==
$$\begin{matrix}
\text{min (ou max) } z = c^tx \\
\text{sujeito a}\\
\hspace{3cm} Ax=b\\
\hspace{3cm}x \in \mathbb{Z}^n


\end{matrix}
$$
PPL Inteira-Mista
$$\begin{matrix}
\text{min (ou max) } z = c^tx +d^ty\\
\text{sujeito a}\\
\hspace{3cm} Ax+By=b\\
\hspace{3cm}x \in \mathbb{R}^n, y\in\mathbb{Z}^p


\end{matrix}
$$
## A Terminologia para um PPL
**Função Objetivo**:
A função a ser maximizada ou minimizada é chamada <u>Função objetivo f</u>.

**Restrição**:
As condições impostas pelo modelo são denominadas <u>Restrições do PPL</u>.
As restrições $x_j ≥ 0$ são denominadas <u>Restrições de não negatividade</u>.
As outras <u>Restrições funcionais</u>.

**Solução Viáve**l:
Uma <u>Solução Viável</u> é uma solução para a qual todas as restrições são satisfeitas.

**Solução Inviável**:
Uma Solução Inviável é uma solução para a qual pelo menos uma restrição é violada.

**Região Viável**:
a região viável é o conjunto de todas as soluções viáveis.

**Solução Ótima**:
Uma solução ótima ié uma solução viável onde onde a função objetivo atinge valor máximo(
PPL maximização) ou mínimo (PPL minimização)

# Geometria do PPL
## Soluções de um PPL
### 1. Solução Única
![[solucao_unica.png]]
### 2. Solução Alternativa
![[solucao_alternativa.png]]
### 3. Solução Ilimitada
![[solucao_ilimitada.png]]
### 4. Problema Inviável
![[problema_inviavel.png]]
## Geometria de uma restrição( PPL forma canônica )
- Definição 1:
O conjunto ${x ∈ IR^n| a^T x ≤ b}$ é denominado semiespaço fechado
- Definição 2: 
Um conjunto S ⊂ $IR^n$ é dito limitado se existe uma constante K tal que o valor absoluto de cada componente de todo elemento de S e ́ menor ou igual a K .
- Definição 3: 
Um politopo é um conjunto que pode ser expresso como a interseção de um número finito de semiespaços fechados
- Definição 4:
Um poliedro é politopo limitado, não vazio.
- Definição 5: 
Seja a um vetor não-nulo em $IR^n$ e seja b um escalar. O conjunto ${x ∈ IR^n | a^T x = b}$ é  chamado de hiperplano.

Geometricamente buscamos o hiperplano que intercepta o conjunto das soluções viáveis para o qual k é máximo ( caso de problema de maximização) ou k é mínimo ( problema de minimização)
## Convexidade
![[convexidade.png]]
Portanto, um conjunto C é convexo ,se todo segmento de reta que une dois de seus elementos pontos está inteiramente contido em C.

Um ponto x de um conjunto convexo C é dito ser um ponto
extremo de C se ele não pode ser expresso como uma combinação convexa de
outros pontos distintos de C.

A região de contato ( interseção) entre o hiperplano ótimo da função objetivo
e o politopo da região viável é ou um ponto extremo ou uma face do politopo.

![[Pasted image 20250616195304.png]]
TEOREMA 5: Otimalidade do Ponto Extremo 
Se um problema de programação linear tem exatamente uma solução ótima, então esta solução deve ser um ponto extremo do conjunto viável
Lema
Se o PPL tem mais que uma solução ótima, ele tem infinitas soluções
ótimas. Além disso, o conjunto das soluções ótimas é convexo
# Dualidade
Passamos a ter dois problemas o Primal (P) e o Dual (D)
Exemplo
Primal
$$
\text{(P)}
\begin{matrix}
&&\text{max }z=4x_ {1} +  x_ {2} + 5x_ {3} + 3x_ {4} && \\
\text{sujeito a } &&x_1​−x_2​−x_3​+3x_4​⩽1 \\
 &&5x_1+x_2+3x_3+8x_4⩽55 \\
 &&−x_1+2x_2+3x_3−5x_4⩽3 \\ 
&&x_1,x_2,x_3,x_4 \ge 0 
\end{matrix}
$$
Dual

$$
\text{(D)}
\begin{matrix}
&&\text{min }w=1y_{1} +  55y_ {2} + 3y_{3}&& \\
\text{sujeito a } &&y_1​+5y_2​−y_3​​\ge4 \\
 &&-y_1+y_2+y2_3\ge1 \\
 &&−y_1+3y_2+3y_3\ge5 \\
 && 3y_1+8y_2-5y_3\ge 3 \\  
&&y_1,y_2,y_3 \ge 0 
\end{matrix}
$$
DEFINIÇÃO: O dual do problema (P) (_Problema PRIMAL_) é definido como
sendo o problema (D) (_Problema DUAL_)
$$
\begin{array}{rl}
\text{(P)} \quad & \text{maximize } z = \sum_{j=1}^n c_j x_j \\
\text{sujeito a} \quad & \sum_{j=1}^n a_{ij} x_j \leq b_i \quad (i = 1, \dots, m) \\
& x_j \geq 0 \quad (j = 1, \dots, n)
\end{array}
$$
$$
\begin{array}{rlrl}
\text{(D)} \quad & \text{minimize } w = \sum_{i=1}^m b_i y_i \\
\text{sujeito a }\quad &\sum_{i=1}^m a_{ij} y_i \geq c_j \quad (j=1,\dots,n) \\
 & y_i \geq 0 \quad (i=1,\dots,m)
\end{array}
$$
**Teorema de Dualidade Fraca**: 
Se x é uma solução viável de um problema primal e y é uma solução viável do problema dual correspondente, então
$$
\sum^{n}_{j=1}c_jx_j\le\sum\limits^{m}_{j=1}b_iy_i
$$
**Teorema da Dualidade Forte**:
Se um problema de programação linear tem uma solução ótima, seu dual também tem e os custos ótimos de ambos os problemas são iguais.
$$
\sum^{n}_{j=1}c_jx_j^{*}\le\sum\limits^{m}_{j=1}b_iy_i^{*}
$$
## Relação entre Primal e Dual
Dado o problema dual:
$$
\begin{array}{rlrl}
\text{(D)} \quad & \text{minimize } w = \sum_{i=1}^m b_i y_i \\
\text{sujeito a }\quad &\sum_{i=1}^m a_{ij} y_i \geq c_j \quad (j=1,\dots,n) \\
 & y_i \geq 0 \quad (i=1,\dots,m)
\end{array}
$$
Podemos escrever com:
$$
\begin{array}{rlrl}
\text{(D)} \quad & \text{maximize } -w = \sum_{i=1}^m (-b_i) y_i \\
\text{sujeito a }\quad &\sum_{i=1}^m (-a_{ij}) y_i \leq -c_j \quad (j=1,\dots,n) \\
 & y_i \geq 0 \quad (i=1,\dots,m)
\end{array}
$$
Analogamente...
$$
\begin{array}{rl}
\text{(P)} \quad & \text{maximize } z = \sum_{j=1}^n (-c_j) x_j \\
\text{sujeito a} \quad & \sum_{j=1}^n (-a_{ij}) x_j \geq -b_i \quad (i = 1, \dots, m) \\
& x_j \geq 0 \quad (j = 1, \dots, n)
\end{array}
$$
O dual deste problema, resulta no primal
$$
\begin{array}{rl}
\text{(P)} \quad & \text{maximize } z = \sum_{j=1}^n c_j x_j \\
\text{sujeito a} \quad & \sum_{j=1}^n a_{ij} x_j \leq b_i \quad (i = 1, \dots, m) \\
& x_j \geq 0 \quad (j = 1, \dots, n)
\end{array}
$$
