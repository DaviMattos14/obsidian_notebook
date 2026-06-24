
**Foco:** Sistemas de Equações Diferenciais Ordinárias (EDOs) em Epidemiologia

---

## PARTE I: Resumo das Metodologias Analíticas

### 1. Balanço de Massa (Construção do Modelo)
Traduz a biologia para o cálculo. A taxa de variação de um compartimento é a soma de tudo que entra menos tudo que sai.
* **Entradas ($+$):** Fluxos que apontam para o compartimento (ex: nascimentos, curas).
* **Saídas ($-$):** Fluxos que saem do compartimento (ex: mortes, infecções).
* **Atenção:** Taxas de transferência internas (como infecção de $S$ para $I$) devem aparecer rigorosamente em duas equações: negativa na origem, positiva no destino.

### 2. Análise Dimensional
Garante a coerência física provando que variáveis convertidas (como $s = S/N$) não possuem unidade de medida.
* **Método:** Aplique o operador de colchetes (ex: $[S] = \text{indivíduos}$). Isole a grandeza temporal e divida as unidades até provar que a dimensão final é estritamente $1$.

### 3. Desacoplamento de Sistemas Conservativos
Reduz EDOs acopladas para uma única equação resolvível.
* **Método:** Prove que a soma das derivadas é zero ($\frac{dN}{dt} = 0$). Use a identidade de conservação ($s + i = 1$) para isolar $s = 1 - i$ e substituir na EDO de $\frac{di}{d\tau}$, eliminando uma variável do sistema.

### 4. Fatoração e a Forma Canônica ($\rho_0$)
Padroniza a EDO para identificar os parâmetros de risco da epidemia.
* **Método:** Expanda os termos da EDO desacoplada e coloque a variável dependente em evidência global (ex: $\frac{di}{d\tau} = i[\text{Constante} - i]$). Substitua o bloco constante pelo Número Básico de Reprodução na forma $(1 - \rho_0^{-1})$.

### 5. Resolução Analítica (Integração Direta)
Obtém a função exata do tempo isolando as variáveis.
* **Método:** Isole $i$ de um lado e o tempo $\tau$ do outro. Use Decomposição em Frações Parciais para integrar funções racionais complexas. Aplique a propriedade de Euler ($e$) e as condições iniciais do Problema de Valor Inicial (PVI) para resolver a constante de integração.

### 6. Análise de Estabilidade Linear
Diagnostica o futuro da epidemia sem precisar resolver a EDO.
* **Método:** Encontre as raízes igualando a derivada a zero ($f(\overline{i}) = 0$). Calcule a derivada matemática da função de variação ($f'(i)$). Avalie o sinal substituindo a raiz na derivada:
    * $f'(\overline{i}) < 0 \implies$ **Assintoticamente Estável** (Atrator).
    * $f'(\overline{i}) > 0 \implies$ **Instável** (Repulsor).

### 7. Espaço de Fases
Geometria analítica do sistema, demonstrando como os compartimentos se relacionam ignorando a variável tempo.
* **Método:** Escreva a lei de conservação populacional (ex: $S + I = N_0$). Isole $I$ no eixo Y para formar a equação da reta ($I = -S + N_0$). Restrinja a reta estritamente ao primeiro quadrante ($S \ge 0, I \ge 0$) e plote os pontos de equilíbrio encontrados.

---
\newpage

## PARTE II: Resolução Completa - Modelo SIS com Evolução Demográfica

**O Problema:** Uma doença confere imunidade apenas temporária. Há fluxo de nascimentos ($\mu N$) em $S$, mortes naturais proporcionais ($\mu S$, $\mu I$), infecção ($\beta \frac{SI}{N}$) e recuperação ($\gamma I$). 

### Passo 1: Construção das EDOs (Balanço de Massa)
Montamos o sistema contabilizando as entradas e saídas de cada compartimento:
$$\frac{dS}{dt} = \mu N - \beta \frac{SI}{N} + \gamma I - \mu S$$
$$\frac{dI}{dt} = \beta \frac{SI}{N} - \gamma I - \mu I$$

### Passo 2: Prova de Conservação
Somamos o sistema para provar o equilíbrio demográfico:
$$\frac{dN}{dt} = \frac{dS}{dt} + \frac{dI}{dt}$$
$$\frac{dN}{dt} = \mu N - \mu S - \mu I = \mu(S+I) - \mu(S+I) = 0$$
Como a derivada é nula, a população total $N_0$ é rigorosamente constante.

### Passo 3: Adimensionalização e Conversão
Sabendo que $\tau = \beta t$, $s = S/N$ e $i = I/N$, convertemos o EDO da infecção multiplicando por $\frac{1}{\beta N}$:
$$\frac{di}{d\tau} = \frac{1}{\beta N} \left( \beta \frac{SI}{N} - \gamma I - \mu I \right)$$
Simplificando as frações e substituindo pelas variáveis adimensionais:
$$\frac{di}{d\tau} = si - \frac{\gamma}{\beta}i - \frac{\mu}{\beta}i$$

### Passo 4: Desacoplamento e Forma Canônica
Como a população é constante, $s + i = 1 \implies s = 1 - i$. Substituindo na EDO e aplicando a distributiva:
$$\frac{di}{d\tau} = (1 - i)i - \left(\frac{\gamma + \mu}{\beta}\right)i$$
$$\frac{di}{d\tau} = i - i^2 - \left(\frac{\gamma + \mu}{\beta}\right)i$$
Colocamos $i$ globalmente em evidência:
$$\frac{di}{d\tau} = i \left[ 1 - \left(\frac{\gamma + \mu}{\beta}\right) - i \right]$$
Definimos o número básico de reprodução como $\rho_0 = \frac{\beta}{\gamma + \mu}$. Substituindo, atingimos a forma canônica de Verhulst:
$$\frac{di}{d\tau} = i \left[ (1 - \rho_0^{-1}) - i \right]$$

### Passo 5: Pontos de Equilíbrio
Definimos $f(i) = \frac{di}{d\tau}$. Igualando a EDO a zero para encontrar onde o sistema estagna ($f(i) = 0$):
1. $\overline{i}_0 = 0$ (Estado livre de doença)
2. $\overline{i}_1 = 1 - \rho_0^{-1}$ (Estado endêmico, que só existe no mundo real se $\rho_0 > 1$)

### Passo 6: Análise de Estabilidade Linear
Derivamos a função canônica aplicando a regra do polinômio:
$$f'(i) = (1 - \rho_0^{-1}) - 2i$$

**Avaliando o Estado Livre de Doença ($\overline{i}_0 = 0$):**
$$f'(0) = 1 - \rho_0^{-1}$$
* Se $\rho_0 < 1$, o resultado é negativo ($<0$). O ponto zero é **Assintoticamente Estável**.
* Se $\rho_0 > 1$, o resultado é positivo ($>0$). O ponto zero é **Instável**.

**Avaliando o Estado Endêmico ($\overline{i}_1 = 1 - \rho_0^{-1}$):**
*(Assumindo $\rho_0 > 1$ para garantir existência biológica)*
$$f'(\overline{i}_1) = (1 - \rho_0^{-1}) - 2(1 - \rho_0^{-1}) = -(1 - \rho_0^{-1})$$
Como $\rho_0 > 1$, o termo em parênteses é positivo. Logo, a derivada inteira é negativa ($<0$). O estado endêmico é **Assintoticamente Estável**.

### Passo 7: Espaço de Fases
Como $S + I = N_0$, o sistema geométrico não depende da variável tempo.
Isolando $I$, obtemos a equação de uma reta restrita ao primeiro quadrante:
$$I = -S + N_0$$
* **Extremos (Limites Físicos):** A reta conecta o ponto $(N_0, 0)$ ao ponto $(0, N_0)$.
* **Dinâmica Geométrica:** Se $\rho_0 > 1$, qualquer ponto inicial inserido sobre essa reta deslizará continuamente até "estacionar" na coordenada exata do equilíbrio endêmico: $\left( N_0 \rho_0^{-1}, \, N_0(1 - \rho_0^{-1}) \right)$. Se $\rho_0 \le 1$, todo o sistema escorregará para a base geométrica $(N_0, 0)$.