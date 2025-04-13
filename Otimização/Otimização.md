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
![[nao_negatividade.png]]![[restricao1.png]]![[restricao2.png]]