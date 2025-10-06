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

## Função de Massa de Probabilidade (PMF)
Aplica-se a **variáveis aleatórias discretas**.  
Ela fornece a probabilidade de a variável assumir um valor específico:
$$
P(X = x) = f(x)
$$
Deve satisfazer:
$$0 \le f(x) \le 1 \quad \text{e} \quad \sum_x f(x) = 1$$
## Função de Densidade de Probabilidade (PDF)
Aplica-se a **variáveis aleatórias contínuas**.  
Ela descreve a **densidade de probabilidade**, e não a probabilidade direta.  
A probabilidade de $X$ estar em um intervalo $[a,b]$ é:
$$
P(a \le X \le b) = \int_a^b f(x)\,dx
$$
Deve satisfazer:
$$
f(x) \ge 0 \quad \text{e} \quad \int_{-\infty}^{\infty} f(x)\,dx = 1
$$
## Linearidade da Esperança
A **linearidade da esperança** afirma que a **esperança (ou valor esperado)** de uma soma de variáveis aleatórias é igual à soma das esperanças individuais, **independentemente de haver dependência entre elas**:
$$
E[aX + bY] = aE[X] + bE[Y] \quad E[X,Y]= E[X]+E[Y]
$$
ou, mais geralmente,
$$
E\!\left[\sum_{i=1}^{n} X_i\right] = \sum_{i=1}^{n} E[X_i]
$$
# 2. Variáveis Aleatórias Discretas
## Modelo Bernoulli
> Sucesso ou Fracasso

$$
X \sim Ber(p) \hspace{1cm}(0 < p <1)
$$
$$
\mathbb{p}_X(x)=p^x(1-p)^{1-x} \hspace{20px}\text{para }x\in \{0,1\}
$$
- $E[X] = P$
- $Var(X) = P(1-P)$
$$
\begin{matrix}
\text{PMF:} && \text{CDF:} \\ 
P(X = x) = \begin{cases} p, & x = 1 \\ 1 - p, & x = 0 \end{cases} &&
F(x) = \begin{cases} 0, & x < 0 \\ 1 - p, & 0 \le x < 1 \\ 1, & x \ge 1 \end{cases}
\end{matrix}
$$
## Modelo Binomial
$X \sim Bin(n,p)$

> Chama-se de experimento binomial ao experimento que 
> - consiste em n ensaios de Bernoulli
> - cujo ensaios são independentes, e
> - para qual a probabilidade de sucessos em casa ensaio é sempre igual a p $(0<p<1)$

- PMF
$$
\begin{matrix} p_X=\mathbb{P}(X=x)= \dbinom{n}{x}\centerdot p^x\centerdot(1-p)^{n-x},\\ \dbinom{n}{x}= \frac {n!}{x!(n-x)!} & x \in \{0,1,2,...,n\}\end{matrix}
$$
- CDF
$$
F(k)=\sum\limits^k_{i=0} \dbinom{n}{i}\centerdot p^{i\centerdot(1-p)^{n-i}}= \sum\limits^k_{y \le k}p_x^{(y)}
$$
- $E[X] = n \centerdot p$
- $Var(X)=n\centerdot p \centerdot (1-p)$
## Modelo Geométrico
$X \sim Geom(p)$
> Número de repetições de um ensaio de Bernoulli com probabilidade de sucesso $(0<p<1)$até ocorrer o primeiro sucesso

- PMF:
$$
\mathbb{P}(X=x)=p\cdot(1 − p)^x \hspace{1cm},x \in \mathbb{N}
$$
- CDF:
$$
F(k)=1-(1-p)^k
$$
- $E[X]= \frac{1}{p}$
- $Var(X)= \frac{1-P}{p^2}$
## Modelo Poisson
$X \sim Poi(\lambda)$
> Nº de eventos que ocorrem em um intervalo de tempo ou espaço

- PMF:
$$
\begin{matrix} p(x) = e^{-\lambda} \centerdot \frac{\lambda^x}{x!}, & x=\{0,1,2,..\} \end{matrix}
$$
- CDF:
$$
F(k)=\sum\limits^k_{i=0}p(x)
$$

$E[X] = Var(x) = \lambda$

## Exponencial

- **Descrição:** Tempo até o primeiro evento (processo de Poisson).

- **PDF:**
$$
f(x) = \lambda e^{-\lambda x}, \quad x \ge 0
$$    
- **CDF:**
    $$
  F(x) = 1 - e^{-\lambda x}  
$$
## Uniforme Contínua

> **Descrição:** Todos os valores em $[a,b]$ igualmente prováveis.

- **PDF:**
$$
f(x) = \begin{cases} \frac{1}{b-a}, & a \le x \le b \\ 0, & \text{caso contrário} \end{cases}
$$    
- **CDF:**
    $$
  F(x) = \begin{cases} 0, & x < a \\ \frac{x - a}{b - a}, & a \le x < b \\ 1, & x \ge b \end{cases}  
$$
## Normal (Gaussiana)

 > **Descrição:** Distribuição simétrica em torno da média $\mu$.
    
- **PDF:**
    $$
  f(x) = \frac{1}{\sqrt{2\pi\sigma^2}} e^{-\frac{(x - \mu)^2}{2\sigma^2}}  
$$
- **CDF:**
    $$
  F(x) = \int_{-\infty}^{x} \frac{1}{\sqrt{2\pi\sigma^2}} e^{-\frac{(t - \mu)^2}{2\sigma^2}}\, dt  
$$(sem forma fechada; usa tabelas ou funções computacionais).
# 3. Relação Poisson $\times$ Exponencial (Processo de Poisson)

A **distribuição de Poisson** e a **distribuição Exponencial** estão intimamente ligadas — elas descrevem **dois lados do mesmo processo estocástico**, o **Processo de Poisson**.

## Processo de Poisson

Modela o número de ocorrências de um evento em um intervalo de tempo:  
$$
P(N(t) = k) = \frac{e^{-\lambda t} (\lambda t)^k}{k!}  
$$
onde \( $\lambda$ \) é a **taxa média de eventos por unidade de tempo**.

Assim, \( $N(t)$ \) segue **distribuição de Poisson**.
## Tempo entre eventos → Exponencial

O **tempo entre dois eventos consecutivos**, chamado de _tempo de interchegada_, segue uma **distribuição Exponencial**:  
$$
f_T(t) = \lambda e^{-\lambda t}, \quad t \ge 0  

$$
com média \( $E[T] = 1/\lambda$ \).

Portanto:
- Poisson → **quantos eventos ocorrem em um tempo fixo**.
- Exponencial → **quanto tempo até o próximo evento**.
## Relação formal

Se os tempos entre eventos \( $T_1, T_2, \dots$ \) são independentes e Exponenciais ($\lambda$ ),  
então o número total de eventos até o tempo \( t \):  
$$
N(t) = \max{ n : T_1 + T_2 + \cdots + T_n \le t }  

$$
segue uma **distribuição de Poisson( $\lambda t$ )**.

E reciprocamente, se ( $N(t)$ ) é um processo de Poisson, então os tempos entre eventos são **Exponenciais( $\lambda$ )**.

| Aspecto                         | Distribuição       | Interpretação               |
| ------------------------------- | ------------------ | --------------------------- |
| Número de eventos em tempo fixo | **Poisson(λt)**    | Contagem de ocorrências     |
| Tempo entre eventos             | **Exponencial(λ)** | Intervalo entre ocorrências |
# 4. Geração de Amostras Aleatórias

**Motivo**: Poder simular/observar fenômenos aleatórios

**Premissa**: Temos um gerador de números uniformemente distribuídos entre 0 e 1: $]0,1[$

## Métodos principais
### Método da Transformada Inversa

- **Ideia:** usar a função de distribuição acumulada (CDF) \( F(x) \) da variável desejada.
    
- **Passos:**
    1. Gere \( $U \sim \text{Uniforme}(0,1)$ \);
    2. Calcule \( $X = F^{-1}(U)$ \).
- **Justificativa:** se \( $U$ \) é uniforme em $[0,1]$, então \( $X = F^{-1}(U)$ \) tem CDF \( $F(x)$ \).
- **Vantagens:** simples, exato.
- **Limitações:** exige que \( $F^{-1}$ \) tenha forma analítica fácil.
- **Exemplo:**  
    Exponencial( $\lambda$ ): ( $X = -\frac{1}{\lambda}\ln(1-U)$ ).
### Método da Aceitação–Rejeição

- **Ideia:** gerar amostras de uma distribuição difícil usando outra mais simples.
    
- **Passos:**
    1. Escolha uma distribuição fácil \( $g(x)$ \) e uma constante \( $c$ \) tal que \( $f(x) \le c,g(x)$ \) para todo \( $x$ \);
    2. Gere \( $X \sim g(x)$ \) e \( $U \sim U(0,1)$ \);
    3. Aceite \( $X$ \) se \( $U \le \frac{f(X)}{c,g(X)}$ \), senão rejeite e repita.

- **Vantagens:** útil quando \( $F^{-1}$ \) é complexa.
- **Limitações:** pode ser ineficiente se \( $c$ \) for grande (muitas rejeições).

### Método do Vetor (ou Método de Composição)

- **Ideia:** gerar amostras quando a distribuição é composta ou mistura de várias partes.
    
- **Passos:**
    1. Escolha qual componente gerar (segundo probabilidades associadas);
    2. Gere a amostra da distribuição correspondente.

- **Exemplo:**  
    Se \( X \) vem de uma mistura de duas exponenciais:  
$$
    f(x) = p f_1(x) + (1-p) f_2(x)
    $$
    então:
    - Gere \( $U \sim U(0,1)$ \);
    - Se \( $U < p$ \), gere \( $X \sim f_1$ \); caso contrário, \( $X \sim f_2$ \).

- **Aplicação:** simulação de **sistemas com múltiplos regimes** ou **processos compostos**.

| Método               | Quando usar              | Exemplo típico              |
| -------------------- | ------------------------ | --------------------------- |
| Transformada Inversa | CDF invertível           | Exponencial, Uniforme       |
| Aceitação–Rejeição   | CDF complexa             | Normal, Gamma               |
| Vetor (Composição)   | Mistura de distribuições | Modelos híbridos, workloads |

# 5. Modelo Híbrido de Amostragem

O **método híbrido de amostragem** combina **dois ou mais métodos de geração de amostras aleatórias** (como transformada inversa, aceitação–rejeição e composição) para aproveitar as vantagens de cada um e contornar suas limitações.

---
## Ideia principal

Nem todas as distribuições têm uma forma simples para \( $F^{-1}(x)$ \) (inversa da CDF) ou uma função de densidade \( $f(x)$ \) que facilite o uso de um único método.  
O método híbrido busca **dividir o domínio ou estrutura da distribuição** e **usar o melhor método em cada parte**.
## Como funciona

1. **Identificação das regiões ou componentes:**
    - Partes da distribuição onde \( $F^{-1}$ \) é simples → usa-se **Transformada Inversa**.
    - Partes mais complexas → aplica-se **Aceitação–Rejeição** ou **Composição**.
2. **Combinação dos resultados:**
    - As amostras geradas de cada parte são reunidas para formar um conjunto completo que segue a distribuição alvo.
## Vantagens

- Maior **eficiência** e **flexibilidade** que os métodos isolados.
- Permite tratar **distribuições complexas ou mistas** (contínuas e discretas, truncadas, ou multimodais).
- Reduz o número de rejeições e o custo computacional.
## Exemplo típico

Para gerar amostras **Normais**, o método híbrido pode:
- Usar **Transformada Inversa** para a parte central da distribuição (onde \( $F^{-1}$ \) é bem comportada);
- Usar **Aceitação–Rejeição** para as caudas (onde \( $F^{-1}$ \) diverge).
# 6. Filas
![[Pasted image 20251005012909.png]]
**Servidor**: Qualquer recurso onde filas de tarefas possam se formar

## Parâmetros do Sistemas
- Topologia da Rede
- Política (ordem de atendimento) da fila
- Average Arrival Rate: $\lambda$ 
	- Taxa média de chegada por u.t.
- Mean interarrivel time: $1/\lambda$
- Size ($s$): Tamanho do job
	- Tempo de serviço que o job demanda para ser concluído
- Mean Service Time: $E[S]=1/\mu$
- Average Size Rate ($\mu$): Taxa média nominal de serviço (em cada servidor) em jobs por u.t.

## Métricas de Desempenho

- Response Time (**T**) : Tempo de resposta (Tempo no sistema)
		$T = Tq + Ts$
- Waiting Time (**Tq**) : Tempo perdido em filas (Q: Queue)
- Número de jobs no sistema (**N(t)**) no instante $t$
- Número de jobs na Fila (**Nq(t)**) no instante $t$

O tempo de serviço S, assim como outras V.A.s e métricas, **depende do servidor**. Será maior ou menor conforme a taxa de serviço $\mu$ do servidor onde está. Para referir-se às métricas do i-ésimo servidor em uma rede de filas, anota-se $T_i$ , $Tq_i$ , $N(t)_i$ , etc.

Condição de Estabilidade: Sempre assumiremos que $\mu < \lambda$
