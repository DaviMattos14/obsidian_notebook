
# 🧠 **Resumo para Prova – ICP363: Introdução ao Aprendizado de Máquina**

---

## 🏁 **1. Fundamentos**

### 📌 O que é Aprendizado de Máquina (ML)?

- Subárea da **Inteligência Artificial (IA)**.
    
- **Objetivo**: fazer sistemas melhorarem sua performance **com a experiência (dados)**.
    
- ML aprende **padrões** e **faz previsões** sem precisar de regras explícitas.
    

### ⚙️ Relação entre áreas:

|Área|Descrição|
|---|---|
|**IA**|Sistemas inteligentes que simulam comportamento humano.|
|**ML**|Algoritmos que aprendem com dados.|
|**DL (Deep Learning)**|Modelos com várias camadas (redes neurais profundas).|
|**Data Science**|Extração de conhecimento de dados (usa ML, estatística e mineração).|

### 🕰️ Breve histórico:

- **Bayes (1763)** – probabilidade condicional.
    
- **Markov (1913)** – processos estocásticos.
    
- **Perceptron (1957)** – primeira rede neural.
    
- **Backpropagation (1986)** – aprendizado em redes multicamadas.
    

---

## 📊 **2. Tipos de Aprendizado**

### 🔹 Supervisionado:

- Dados **rotulados** (x → y conhecidos).
    
- O modelo **aprende mapeamento f(x) → y**.
    
- Exemplo:
    
    - Regressão linear (previsão de valores contínuos)
        
    - Classificação (atribuição de rótulos, ex: spam/não spam)
        

**Pseudocódigo básico:**

```
Para cada amostra (x_i, y_i) no conjunto de treino:
    modelo ← ajustar parâmetros para minimizar erro entre previsão e y_i
```

---

### 🔹 Não Supervisionado:

- Dados **não rotulados**.
    
- O algoritmo descobre **padrões ocultos** (grupos, associações).
    
- Exemplo: _Clustering (agrupamento K-Means)_.
    

---

### 🔹 Por Reforço:

- O agente aprende por **recompensa/punição** ao interagir com o ambiente.
    
- Exemplo: jogos, robótica, controle autônomo.
    

---

## 🧩 **3. Tipos de Dados e Pré-Processamento**

### 🧮 Tipos de atributos:

|Tipo|Exemplo|Observação|
|---|---|---|
|**Nominal**|Cor (vermelho, azul)|Sem ordem.|
|**Binário**|Fumante (0/1)|Dois estados.|
|**Ordinal**|Tamanho (P, M, G)|Ordem, sem distância fixa.|
|**Numérico**|Idade, peso|Intervalo ou razão.|

---

### ⚙️ Etapas de pré-processamento:

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

- **Média** (tendência central)
    
- **Mediana** (valor central)
    
- **Moda** (valor mais frequente)
    
- **Variância** = média dos desvios² da média
    
- **Desvio padrão** = √variância
    
- **Z-score** = (valor - média) / desvio padrão → mede quão longe está da média.
    

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
