# 1. Aprendizado de Máquina
Aprender é o processo pelo qual um sistema melhora seu desempenho por meio da experiência. O Aprendizado de Máquina (Machine Learning) surge como uma solução para problemas onde é difícil antecipar todas as situações possíveis ou programar uma solução passo a passo. As abordagens para o aprendizado incluem:

- **Aprendizado como busca**: Consiste em enumerar um espaço de conceitos e eliminar aqueles que não condizem com os dados observados.
    
- **Aprendizado indutivo**: Foca em extrair informações gerais a partir da observação de um conjunto de casos particulares. Um exemplo histórico é como as observações de Tycho Brahe permitiram a Johannes Kepler formular suas leis da mecânica celeste.
    
### O Papel dos Dados

Os dados são a base para o treinamento de programas de aprendizado de máquina. O desenvolvimento de um sistema de ML segue etapas como a definição do problema, coleta e preparação dos dados, treinamento e avaliação do modelo.

Contudo, a coleta de dados apresenta desafios:

- **Desbalanceamento**: Fontes como a Wikipedia possuem uma distribuição de tópicos desigual, com maior concentração em áreas como Esportes, Música e Política.
    
- **Falta de Diversidade**: Os dados frequentemente sub-representam diversas culturas, geografias e grupos étnicos , privilegiando pontos de vista predominantes. O acesso à internet, por exemplo, é maior entre jovens e em países desenvolvidos.
    
- **Dados no Brasil**: Embora o acesso à internet atinja 80% dos domicílios, há uma disparidade social: 100% da classe A está conectada, contra 60% das classes D e E.
### Relação com Outras Áreas

O documento posiciona o Aprendizado de Máquina dentro de um contexto mais amplo:

- **Inteligência Artificial (IA)**: É a área mais ampla, focada na construção de sistemas inteligentes que se comportam como humanos.
    
- **Aprendizado de Máquina (ML)**: É uma subárea da IA que desenvolve algoritmos capazes de aprender.
    
- **Aprendizado Profundo (Deep Learning)**: Uma subárea do ML que utiliza modelos com múltiplas camadas de processamento para aprender representações de dados em vários níveis de abstração.
    
- **Ciência de Dados e Mineração de Dados**: A Ciência de Dados estuda a extração de conhecimento a partir de dados, utilizando técnicas de ML , enquanto a Mineração de Dados foca na aplicação de algoritmos para extrair padrões de conjuntos de dados.
# 2. Perceptron

Ele é o **modelo mais simples de rede neural** e foi o ponto de partida para o desenvolvimento do **aprendizado supervisionado**.

- Objetivo: **Classificar** dados em duas classes (ex: 0 ou 1, -1 ou +1).
    
- Tipo: **Aprendizado supervisionado (classificação binária)**.
    
- Baseia-se em **combinar entradas ponderadas por pesos** e aplicar uma **função de ativação**.

O Perceptron representa **um neurônio artificial** com

| Componente                     | Descrição                                            |
| ------------------------------ | ---------------------------------------------------- |
| **Entradas (x₁, x₂, ..., xₙ)** | Atributos ou variáveis de entrada.                   |
| **Pesos (w₁, w₂, ..., wₙ)**    | Parâmetros ajustáveis (importância de cada entrada). |
| **Viés (bias, b)**             | Constante que desloca o limiar da decisão.           |
| **Soma Ponderada (z)**         | $z = \sum_{i=1}^{n} (w_i \cdot x_i) + b$             |
| **Função de Ativação (f)**     | Converte ( z ) em saída binária (0 ou 1).            |
Saída:  
$$
	y =  
    \begin{cases}  
    1, & \text{se } (Σ_{i=1} w_i x_i + b) > 0 \\
    0, & \text{caso contrário}  
    \end{cases}  
$$

### 🧩 Pseudocódigo:

```
Entrada: dados de treino {(x₁, y₁), ..., (xₙ, yₙ)}
inicializar pesos w_i = 0 e bias b = 0
Definir taxa de aprendizado α (ex: 0.1)

para época em 1..N:
    para cada amostra (x, y_esperado):
        y_pred = ativacao(Σ(w_i * x_i) + b)
        erro = y_esperado - y_pred
        para cada peso w_i:
            w_i = w_i + α * erro * x_i
        b = b + α * erro
```

**Função ativação:** retorna 1 se entrada > 0, senão 0.
- **α** → taxa de aprendizado (ex: 0.1)
- Atualiza pesos apenas quando há erro.
O Perceptron busca **coeficientes (pesos)** que satisfaçam:

$$
y_i (w \cdot x_i + b) > 0
$$
para todas as amostras corretamente classificadas.

Se o conjunto for **linearmente separável**, o Perceptron **converge** (ou seja, encontra pesos corretos).

Se **não for separável**, ele **não converge** (fica oscilando).

## Representação Geométrica

A fronteira de decisão é dada por:

$$
w_1x_1 + w_2x_2 + ... + w_nx_n + b = 0
$$
- Pontos acima → classe 1
- Pontos abaixo → classe 0

---

## Limitações

| Limitação                                                  | Explicação                                        |
| ---------------------------------------------------------- | ------------------------------------------------- |
| **Somente separável linearmente**                          | Não funciona para padrões não lineares (ex: XOR). |
| **Convergência garantida apenas se linearmente separável** | Caso contrário, entra em loop.                    |
| **Função de ativação simples**                             | Apenas degrau; não lida com probabilidades.       |

---

## Versão Vetorial (Forma Compacta)

$$
\begin{matrix}
\mathbf{w} \leftarrow \mathbf{w} + α (y - \hat{y}) \mathbf{x} \\  b \leftarrow b + α (y - \hat{y})
\end{matrix}
$$

- $\mathbf{w}$: vetor de pesos
- $\mathbf{x}$: vetor de entrada
- $y$: rótulo real
- $\hat{y}$​: previsão
## 💡 **Dica para Prova**

Lembre-se:
- O perceptron **não “entende” padrões curvos** — só retas/planos.
- **Erro = esperado - previsto**
- **Atualiza pesos somente se erra**
- **Bias desloca a fronteira de decisão** (não precisa passar pela origem).

#  3. Tipos de Aprendizado

### 🔹 Supervisionado:

- Dados **rotulados** (x → y conhecidos).
- O modelo **aprende mapeamento f(x) → y**.

- Exemplo:
    - Regressão linear (previsão de valores contínuos)
    - Classificação (atribuição de rótulos, ex: spam/não spam)

#### Como funciona

1. Fornecemos **dados de treino** com pares (entrada, saída):
$$
  D = \{(x_1, y_1), (x_2, y_2), ..., (x_n, y_n)\}  
$$
    
2. O modelo aprende **a relação entre x e y** ajustando seus parâmetros.
3. Depois é testado em **dados novos** (sem rótulo) para verificar se generalizou bem.
 #### Tipos principais
- **Regressão:** Usada para prever valores contínuos.
- **Classificação:** Utiliza um algoritmo para atribuir dados a categorias específicas.

⚠️ Cuidados
- Dividir dataset em **treino e teste**.
- Evitar **overfitting** (memorizar dados).
- Avaliar com métricas adequadas (MSE, acurácia, precisão, recall...).

---

### 🔹 Não Supervisionado:

Neste tipo, **os dados não têm rótulos** — o modelo tenta **descobrir padrões, grupos ou estruturas ocultas** nos dados. Não há “resposta correta” para comparar.

- Dados **não rotulados**.
- O algoritmo descobre **padrões ocultos** (grupos, associações).

 Objetivo
- Encontrar **relações internas** entre os dados.
- Reduzir dimensionalidade, agrupar exemplos similares ou identificar outliers.
- Exemplo: _Clustering (agrupamento K-Means)_.

⚠️ Limitações
- Difícil avaliar se o agrupamento está “correto”.
- Requer interpretação humana posterior.
---

### 🔹 Por Reforço:

- O agente aprende por **recompensa/punição** ao interagir com o ambiente.
- Exemplo: jogos, robótica, controle autônomo.
    
---

# 4. Modelos Paramétricos vs. Não Paramétricos

- **Modelos Paramétricos:** Resumem os dados com um conjunto de parâmetros de tamanho fixo, independentemente do número de exemplos. Exemplos incluem Regressão Linear e Perceptron.
    
    - **Vantagens:** São mais fáceis de interpretar, mais rápidos e não exigem muitos dados.
    - **Desvantagens:** São muito dependentes da função escolhida e mais adequados para problemas simples.
        
- **Modelos Não Paramétricos:** Não podem ser caracterizados por um conjunto limitado de parâmetros. Exemplos incluem árvores de decisão, redes neurais e SVM.
    
    - **Vantagens:** São mais flexíveis, não fazem suposições sobre a função subjacente e possuem alta performance.
    - **Desvantagens:** Requerem mais dados, são mais lentos para treinar e têm maior risco de _overfitting_.
---

# 5. Tipos de Dados

## Dados Estruturados 

São dados organizados, com informações representadas por atributos (features) e seus valores, geralmente armazenados em bancos de dados ou planilhas. Os tipos de atributos podem ser:

- **Categóricos/Nominais:** Valores que representam categorias (ex: cor do cabelo).
- **Booleano:** Apenas dois valores (verdadeiro/falso).
- **Ordinal:** Valores que representam uma escala (ex: nível de satisfação).
- **Numéricos:** Valores inteiros ou reais. 

## Dados Não Estruturados 
São compostos por diferentes tipos de dados combinados, como textos e imagens.

- **Preparação de Dados:** Textos podem ser convertidos em representações numéricas (vetores) para capturar relações semânticas, como no exemplo `(rei - homem) + mulher = rainha`.
- **Dados de Imagem:** Uma imagem pode ser vista como uma matriz de pixels. Cada pixel é representado por um valor numérico, seja em escala de cinza (um inteiro de 0 a 255) ou RGB (três inteiros, um para cada cor).

# 6. Métricas de Avaliação para Modelos

Treinar um modelo (regressão, classificação etc.) não é o suficiente.  
Precisamos **quantificar seu desempenho** — ou seja, **medir o erro ou acerto das previsões**.

- **Objetivo:** saber se o modelo **generaliza bem** para dados novos.
- **Problema comum:** _Overfitting_ (modelo “decorou” o treino) ou _Underfitting_ (modelo muito simples)

## Matriz de confusão
![[Pasted image 20251008193718.png]]
- **Verdadeiro Positivo (VP):** O modelo previu "positivo" e o valor real era "positivo".
- **Falso Positivo (FP):** O modelo previu "positivo", mas o valor real era "negativo".
- **Falso Negativo (FN):** O modelo previu "negativo", mas o valor real era "positivo".
- **Verdadeiro Negativo (VN):** O modelo previu "negativo" e o valor real era "negativo".

## Acurácia
Percentual de acertos totais do modelo. 
Boa quando as classes estão **equilibradas**
$$
\text{Acurácia }=\frac{VP+VN}{VP+VN+FP+FN}
$$
​
## Revocação (Recall)
De todos os casos que eram realmente "positivos", quantos o modelo conseguiu identificar?
Alta sensibilidade → poucos falsos negativos.
$$
\text{Recall}=\frac{VP}{VP+FN}​
$$
## Precisão
Das vezes que o modelo previu "positivo", quantas ele acertou?
Alta precisão → poucos falsos positivos.
$$
\text{Precision}=\frac{VP}{VP+FP}​
$$
## F1 - Score
Média harmônica entre precisão e revocação, útil para balancear o impacto de falsos positivos e falsos negativos
Boa quando há **classes desbalanceadas**.
$$
\text{F1}=2\times \frac{\text{Precisão}\times \text{Recall}}{\text{Precisão} + \text{Recall}}​
$$

# 7. Tipos de Dados e Pré-Processamento

### Tipos de atributos:

| Tipo         | Exemplo              | Observação                 |
| ------------ | -------------------- | -------------------------- |
| **Nominal**  | Cor (vermelho, azul) | Sem ordem.                 |
| **Binário**  | Fumante (0/1)        | Dois estados.              |
| **Ordinal**  | Tamanho (P, M, G)    | Ordem, sem distância fixa. |
| **Numérico** | Idade, peso          | Intervalo ou razão.        |

---
### Etapas de pré-processamento:

1. **Limpeza de dados**
    - Preencher valores ausentes (média, mediana, modelo preditivo).
    - Remover ruído (método de _binning_, regressão).
    - Detectar outliers.
        
2. **Integração de dados**
    - Unir dados de múltiplas fontes, resolvendo duplicatas e conflitos de nomes.
        
3. **Redução de dados**
    - Reduzir dimensionalidade (PCA, amostragem, seleção de atributos).
        
4. **Transformação de dados**
    - Normalizar (ex: [0,1]).
    - Discretizar (intervalos, faixas de idade etc.).
        
---

### 🧮 Estatística básica:

#### Medidas de Posição: 
medem a localização do meio ou centro de uma distribuição;

- **Média** (tendência central)
$$
    \frac{\sum\limits x_i}{n}
$$
sensível a valores extremos (outliers).

- **Mediana** (valor central)
$$
    \text{mediana }(x) =
 \begin{cases}
 \text{x}_{\frac{n+1}{2}} & \text{se n for ímpar} \\
\frac{(\text{x}_{\frac{n}{2}} + \text{x}_{\frac{n+1}{2}})}{2} & \text{se n for par}
 \end{cases}   
$$
para dados assimétricos, esta é a melhor medida.

- **Moda** (valor mais frequente)
#### Medidas de dispersão: 
são utilizadas para que possamos saber qual o grau de variação dos nossos dados

- **Quartis**:
	Dividem os dados ordenados em quatro partes iguais. O primeiro quartil (Q1) corresponde ao percentil 25, o segundo (Q2) é a mediana (percentil 50), e o terceiro (Q3) é o percentil 75
	
	**Intervalo Interquartílico (IQR):** É a diferença entre o terceiro e o primeiro quartil ($IQR=Q3−Q1$), representando a dispersão dos 50% centrais dos dados.

	Como calcular os quartis:
$$
\begin{matrix} 
i=(N-1)\cdot q+1
\\
P_{p}=x_{[i]}+(i-[i])\cdot(x_{[i]+1}-x_{[i]})
\end{matrix}
$$
onde:
- 
- 
	Como calcular os limites:
	-  $X_i > LS \text{ (Limite Superior)}$, para $LS=Q_3 + 1.5\times(Q_3-Q_1)$
	- $X_i < LI \text{ (Limite Inferior)}$, para $LI=Q_1 - 1.5\times(Q_3-Q_1)$

- **Variância** $\sigma$= média dos desvios² da média
    $$
    \frac{1}{2}\sum\limits(x_i-\overline{x}_i)^2
$$
- **Desvio padrão** = $\sqrt{\sigma}$
    Mede o quão distantes os valores estão da média
- **Z-score** = (valor - média) / desvio padrão → mede quão longe está da média.
    $$
    \frac{x-\overline{x}}{\sigma}
$$

---

## 🧮 **4. Regressão Linear**

### 📈 Modelo:

$$
y = β_0 + β_1x + ε  

$$
- ( $β_0$ ): intercepto (valor de y quando x = 0)
    
- ( $β_1$ ): inclinação (quanto y muda quando x varia 1 unidade)
    
- ( $ε$ ): erro (diferença entre previsto e real)
    

**Pseudocódigo (ajuste por mínimos quadrados):**

```
dados = {(x1, y1), ..., (xn, yn)}

β1 = Cov(x, y) / Var(x)
β0 = Média(y) - β1 * Média(x)

para cada novo x:
    prever y_pred = β0 + β1 * x
```

### 📊 Avaliação:

- **Erro Quadrático Médio (MSE)**  
$$
MSE = \frac{1}{n}\sum(y_i - \hat{y_i})^2  
$$
    
- Quanto **menor o MSE**, melhor o ajuste.

---

### 🔹 Regressão Linear Múltipla:
$$
y = β_0 + β_1x_1 + β_2x_2 + ... + β_nx_n  

$$
- Representação matricial:  
$$
    \mathbf{y} = Xβ + ε  
$$    
- Adiciona uma **coluna de 1’s** para o intercepto.
    

---

## 🔗 **5. Correlação**

### 📏 Correlação de Pearson:

- Mede **relação linear** entre variáveis.  
$$
r = \frac{Cov(x, y)}{σ_x σ_y}      
$$
- Varia entre **-1 e 1**.
    
    - r = 1 → forte positiva
        
    - r = -1 → forte negativa
        
    - r ≈ 0 → sem correlação linear
        
- **Sensível a outliers.**
    

---

### 📈 Correlação de Spearman:

- Usa **ordem (ranks)** dos dados (não valores).
    
- Mede **relação monótona** (não necessariamente linear).
    
- **Mais robusta a outliers**.
    

---

## 🔁 **6. Validação e Conjuntos de Dados**

### 🧩 Divisão treino/teste:

- **Treino:** ajustar o modelo.
    
- **Teste:** medir desempenho em dados novos.
    
- Evita _overfitting_ (modelo “memoriza” o treino e erra no teste).
    

---

### 🔁 **Validação Cruzada (k-Fold Cross Validation):**

1. Divide o dataset em _k_ partes iguais (folds).
    
2. Treina com k−1 partes e testa com a parte restante.
    
3. Repete k vezes trocando o fold de teste.
    
4. Faz a **média dos resultados**.
    

**Pseudocódigo:**

```
dividir dados em k partes
para i de 1 até k:
    treino = dados - fold_i
    teste = fold_i
    modelo = treinar(treino)
    erro[i] = avaliar(modelo, teste)
mse_final = média(erro)
```

✅ **Vantagens:**

- Usa todos os dados para treino e teste.
    
- Reduz viés e variação na avaliação.
    

---

## ⚠️ **7. Overfitting e Underfitting**

|Conceito|Descrição|Sintoma|
|---|---|---|
|**Overfitting**|Modelo se ajusta demais ao treino|Erro baixo no treino, alto no teste|
|**Underfitting**|Modelo muito simples|Erro alto em ambos|

🎯 **Objetivo:** encontrar o equilíbrio — bom desempenho em dados **nunca vistos**.

---

## 🧮 **8. Perceptron (Algoritmo de Classificação)**

### 🔹 Estrutura:

- Entradas: ( $x_1, x_2, ..., x_n$ )
    
- Pesos: ( $w_1, w_2, ..., w_n$ )
    
- Viés (bias): ( $b$ )
    
- Saída:  
$$
	y =  
    \begin{cases}  
    1, & \text{se } (Σ w_i x_i + b) > 0 \\
    0, & \text{caso contrário}  
    \end{cases}  

$$

---

### 🧩 Pseudocódigo:

```
inicializar pesos w_i = 0 e bias b = 0
para época em 1..N:
    para cada amostra (x, y_esperado):
        y_pred = passo(Σ(w_i * x_i) + b)
        erro = y_esperado - y_pred
        para cada peso w_i:
            w_i = w_i + α * erro * x_i
        b = b + α * erro
```

- **α** → taxa de aprendizado (ex: 0.1)

- Atualiza pesos apenas quando há erro.
    

---

## 📚 **9. Conceitos-Chave para Revisar**

|Conceito|Definição curta|
|---|---|
|**MSE**|Mede erro médio das previsões|
|**Z-Score**|Quantos desvios padrão o valor está da média|
|**Bias (viés)**|Erro sistemático do modelo|
|**Variância**|Sensibilidade às variações do treino|
|**Trade-off Viés-Variância**|Ajustar complexidade para minimizar erro total|
|**Normalização**|Escalar dados (0–1) para evitar distorções|
|**Outlier**|Valor que foge do padrão da distribuição|

---

## 🧾 Dica Final de Estudo

Priorize entender **o raciocínio por trás dos algoritmos**:

- Por que normalizar?
    
- O que significa “erro baixo”?
    
- Como o modelo aprende com dados?
    

E pratique implementando:

- `LinearRegression()` e `KFold()` do **Scikit-Learn**
    
- `pearsonr()` e `spearmanr()` do **SciPy**
    
- Pequenos datasets como “Advertising.csv” para treinar e validar.
