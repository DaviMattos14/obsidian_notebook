
# Guia Definitivo: Modelagem Compartimental e Estocástica

## 1. Resumo das Metodologias de Resolução

O estudo de dinâmica populacional e epidemiologia computacional segue um funil algorítmico rigoroso. Todo problema, do mais simples ao mais complexo, pode ser resolvido aplicando as seguintes técnicas em ordem:

### Pilar I: Construção e Redução (O Balanço de Massa)

- **A Matriz de Fluxo:** Para cada compartimento, a Equação Diferencial Ordinária (EDO) é montada somando todas as taxas que entram (sinal positivo) e subtraindo todas as taxas que saem (sinal negativo).
    
- **Análise Dimensional:** Prova-se que grandezas como $s = S/N$ são adimensionais substituindo as variáveis por suas unidades (ex: $[\text{indivíduos}]$). O tempo é anulado encontrando a dimensão da taxa de transmissão ($\beta$) e definindo $\tau = \beta t$.
    
- **Desacoplamento (O Truque da Conservação):** Se $\frac{dN}{dt} = 0$, a população é constante. Logo, $s + i = 1$. Isola-se $s = 1 - i$ e substitui-se na EDO de $i$, colapsando um sistema bidimensional interdependente em uma única EDO autônoma isolada.
    
- **Fatoração Canônica:** O polinômio resultante deve ter a variável $i$ colocada em evidência na forma $\frac{di}{d\tau} = i[\text{Constante} - i]$. A constante é então substituída pela notação clássica $(1 - \rho_0^{-1})$.
    

### Pilar II: Análise Matemática (O Sistema Contínuo)

- **Integração por Frações Parciais:** Para EDOs logísticas, a separação de variáveis gera a integral $\int \frac{1}{i(A-i)} di$. Decompõe-se isso na identidade algébrica $\frac{1}{A}(\frac{1}{i} + \frac{1}{A-i})$ para possibilitar a integração via logaritmos neperianos.
    
- **Problema de Valor Inicial (PVI):** Após aplicar a exponencial de Euler ($e$) para remover os logaritmos, a constante de integração genérica é descoberta substituindo $t=0$ e $i(0) = i_0$.
    
- **Linearização (Estabilidade):** Encontram-se as raízes $\overline{i}$ igualando a EDO a zero. Calcula-se a primeira derivada $f'(i)$. Substitui-se as raízes na derivada. Se o resultado numérico for estritamente $< 0$, o estado é **Assintoticamente Estável**; se $> 0$, é **Instável**.
    
- **Espaço de Fases:** Em sistemas conservativos ($N$ constante), a equação $S+I=N_0$ é plotada como um segmento de reta decrescente no primeiro quadrante ($I = -S + N_0$). A estabilidade das raízes dita a direção das setas de fluxo (tempo) sobre essa reta.
    

### Pilar III: Simulação Estocástica (O Sistema Discreto)

- **Vetor de Estado:** O sistema abandona frações contínuas e assume valores inteiros exatos $X = [S, I]$.
    
- **Tabela de Transições:** Cada seta do diagrama biológico vira um evento independente.
    
- **Propensão ($a_k$):** A taxa absoluta da EDO (ex: $\mu S$) vira o peso probabilístico do evento.
    
- **Avanço de Tempo:** O tempo até o próximo evento é amostrado via **Distribuição Exponencial**. O evento específico que ocorrerá é escolhido via **Distribuição Uniforme**, ponderado pela propensão de cada transição.
    

## 2. O Exercício Mestre: Modelo SIS com Demografia

**Por que este é o exercício mais completo?**

O Modelo SIS (Suscetível-Infectado-Suscetível) com renovação demográfica exige a aplicação de todas as técnicas determinísticas que estudamos: possui quatro fluxos cruzados, exige prova de conservação, desacoplamento por substituição, fatoração para encontrar o $\rho_0$ modificado, integração por frações parciais não-triviais, análise de estabilidade condicionada e projeção no espaço de fases.

### Passo 1: Construção das EDOs (Balanço de Massa)

Com taxas de natalidade/mortalidade $\mu$, transmissão $\beta$ e recuperação $\gamma$:

$$\frac{dS}{dt} = \mu N - \beta \frac{SI}{N} + \gamma I - \mu S$$

$$\frac{dI}{dt} = \beta \frac{SI}{N} - \gamma I - \mu I$$

**Conservação da População:**

Somando as EDOs, os termos de infecção e recuperação se anulam: $\frac{dN}{dt} = \mu N - \mu(S+I) = 0$. População constante.

### Passo 2: Adimensionalização

Definindo $s = S/N$, $i = I/N$, $\tau = \beta t$, $\alpha = \mu/\beta$ e $\sigma = \gamma/\beta$. Multiplicamos a EDO dos infectados por $\frac{1}{\beta N}$:

$$\frac{di}{d\tau} = si - \sigma i - \alpha i$$

$$\frac{di}{d\tau} = si - i(\alpha + \sigma)$$

### Passo 3: Desacoplamento e Fatoração

Como $\frac{dN}{dt} = 0$, usamos a restrição $s = 1 - i$:

$$\frac{di}{d\tau} = (1 - i)i - i(\alpha + \sigma)$$

$$\frac{di}{d\tau} = i - i^2 - i(\alpha + \sigma)$$

$$\frac{di}{d\tau} = i \left[ 1 - (\alpha + \sigma) - i \right]$$

Definimos o Número Básico de Reprodução sabendo que $\rho_0^{-1} = \alpha + \sigma = \frac{\mu + \gamma}{\beta}$. Portanto, $\rho_0 = \frac{\beta}{\mu + \gamma}$. A forma canônica é:

$$\frac{di}{d\tau} = i \left[ (1 - \rho_0^{-1}) - i \right]$$

### Passo 4: Solução Analítica $i(\tau)$

Para simplificar a álgebra da integração, chamamos $A = (1 - \rho_0^{-1})$.

$$\frac{1}{i(A - i)} di = d\tau$$

Aplicando frações parciais $\frac{1}{A} \left( \frac{1}{i} + \frac{1}{A-i} \right)$:

$$\frac{1}{A} \left( \int \frac{1}{i} di + \int \frac{1}{A-i} di \right) = \int 1 d\tau$$

$$\ln|i| - \ln|A-i| = A\tau + C_1$$

$$\ln \left| \frac{i}{A-i} \right| = A\tau + C_1$$

Exponenciando ambos os lados e isolando $i$:

$$\frac{i}{A-i} = K e^{A\tau} \implies i = \frac{AK e^{A\tau}}{1 + K e^{A\tau}}$$

Aplicando a condição inicial $i(0) = i_0$, descobrimos que $K = \frac{i_0}{A-i_0}$. Substituindo $K$ e retornando o parâmetro epidemiológico $A$:

$$i(\tau) = \frac{i_0(1 - \rho_0^{-1}) e^{(1 - \rho_0^{-1})\tau}}{1 - \rho_0^{-1} + i_0 \left( e^{(1 - \rho_0^{-1})\tau} - 1 \right)}$$

### Passo 5: Pontos de Equilíbrio e Estabilidade Linear

Avaliamos a derivada da EDO autônoma $f(i) = i(A - i)$:

$$f'(i) = A - 2i$$

- **Ponto 1: Livre de Doença ($\overline{i}_0 = 0$)**
    
    $$f'(0) = A = 1 - \rho_0^{-1}$$
    
    Se $\rho_0 < 1$, o resultado é negativo $\implies$ **Assintoticamente Estável**.
    
    Se $\rho_0 > 1$, o resultado é positivo $\implies$ **Instável**.
    
- **Ponto 2: Estado Endêmico ($\overline{i}_1 = 1 - \rho_0^{-1}$)**
    
    _(Condição de existência física: $\rho_0 > 1$)_
    
    $$f'(\overline{i}_1) = (1 - \rho_0^{-1}) - 2(1 - \rho_0^{-1}) = -(1 - \rho_0^{-1})$$
    
    Como assumimos $\rho_0 > 1$, o termo interno é positivo, e o sinal externo garante que o resultado é estritamente negativo $\implies$ **Assintoticamente Estável**.
    

### Passo 6: Espaço de Fases

- **Geometria:** A conservação $S+I=N_0$ define a reta $I = -S + N_0$ no primeiro quadrante cartesiano.
    
- **Fluxo Se $\rho_0 \le 1$:** Toda trajetória descende a reta inexoravelmente em direção ao eixo das abscissas, ancorando no ponto $(N_0, 0)$.
    
- **Fluxo Se $\rho_0 > 1$:** Trajetórias de qualquer extremo convergem para o ponto atrator no interior da reta, cujas coordenadas exatas são $\left( N_0 \rho_0^{-1}, N_0(1 - \rho_0^{-1}) \right)$.
    

_(Fim do Documento Técnico)_