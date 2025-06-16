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

# Dualidade
