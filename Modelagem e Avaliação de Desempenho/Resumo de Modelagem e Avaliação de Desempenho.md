# 1. Definições

**Processo estocástico**: é um conjunto de variáveis aleatórias $X(t),t \in T$ que descreve a evolução de um sistema ao longo do tempo sob influência do acaso
	Cada $X(t)$ representa o estado aleatório do sistema no instante $t$

**Espaço Amostral** $(\Omega)$: Conjunto de todas as saídas possíveis de um experimento aleatório.

**Evento**:  é um subconjunto qualquer de $\Omega$

**Probabilidade Simétrica**: é assumir que as saídas possíveis (Experimento ou $\Omega$) são equiprováveis (tem as mesma probabilidade)

**Probabilidade Frequencista**: a probabilidade $P(E)$ de um evento $E$ é dado pela razão entre o nº de resultados favoráveis e o nº total de resultados
$$
P(E) = \lim_{n\rightarrow \inf} \frac{\text{Nº de ocorrências E}}{n}
$$

**Probabilidade Condicional**: Para eventos A e B, a probabilidade condicional de _A dado B_ é definida como
$$
\mathbb{P}(A|B)=\frac{\mathbb{P}(A\cap B)}{\mathbb{P}(B)}
$$

**Probabilidade Conjunta** (Dependência):
$$
\mathbb{P}(A\cap B)=\mathbb{P}(A|B)\cdot \mathbb{P}(B)
$$
**Independência**: Dois eventos A e B são independentes se
$$
\mathbb{P}(A\cap B)=\mathbb{P}(A)\mathbb{P}(B)
$$
**Teorema Probabilidade Total**: afirma que, se um conjunto de eventos $( B_1, B_2, \dots, B_n )$ forma uma **partição** do espaço amostral (isto é, são mutuamente exclusivos e cobrem todo o espaço), então a probabilidade de um evento $( A )$ pode ser expressa como:
$$
P(A) = \sum_{i=1}^{n} P(A \mid B_i) \, P(B_i)
$$
**Regra de Bayes**: Se A e B são eventos com probabilidade positiva, então
$$P(A|B) = \frac{(P(A)⋅P(B|A))}{P(B)}$$
obs: $P(A∩B)=P(A)⋅(B|A)$
$P(A|B)+P(A|B^c)=1$

Eventos mutuamente exclusivos: $P(A ∪ B) = P(A) + P(B)$

Complemento:
- $P(A^c)=1-P(A)$
- $(A ∩ B)^c = A^c ∪ B^c$
- $(A ∪ B)^c = A^c ∩ B^c$

