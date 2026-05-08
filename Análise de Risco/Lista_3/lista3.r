# Item 1

frota <- 20

carro_dia <- c(16, 12, 15, 16, 19, 14, 15, 17, 15, 18,
               19, 13, 17, 13, 15, 15, 17, 16, 15, 17,
               16, 13, 18, 14, 13, 14, 14, 18, 16 )

litro_carro <- c(59, 51, 46, 67, 69, 52, 57, 57, 42, 67,
                66, 67, 44, 59, 68, 61, 47, 51, 66, 48,
                60, 62, 63, 45, 59, 46, 55, 52, 53, 60,
                66, 46, 47, 63, 52, 64, 48, 47, 62, 49,
                53, 49, 51, 44, 55, 59, 60, 45, 64, 55)

if (!require('triangle', quietly = TRUE)) {
  options(repos = c(CRAN = "https://cloud.r-project.org"))
  install.packages('triangle', quiet = TRUE)
}
library(triangle)

set.seed(1)
n_simulacao <- 3000

n_sim <- 3000
n_carros <- 20

sample_ativos <- sample(carro_dia, n_sim, replace = TRUE)

matriz_ativos <- matrix(0, nrow = n_sim, ncol = n_carros)

for(i in 1:n_sim){
  k <- sample_ativos[i]  # quantos carros ativos naquele dia

  ativos_indices <- sample(1:n_carros, k, replace = FALSE)
  matriz_ativos[i, ativos_indices] <- 1
}

matriz_consumo <- matrix(
  sample(litro_carro, n_sim * n_carros, replace = TRUE),
  nrow = n_sim,
  ncol = n_carros
)

matriz_consumo <- matriz_consumo * matriz_ativos
matriz_preco <- matrix(
  rtriangle(n_simulacao, 6.10, 7),
  nrow=n_sim,
  ncol=n_carros
)

matriz_consumo <- matriz_consumo * matriz_ativos
gasto <- rowSums(matriz_consumo * matriz_preco)

summary(gasto)

#Resultados
resumo_gasto <- c(
    #media = mean(gasto), # valor esperado do gasto diario
    desvio_padrao = sd(gasto), # variacao em torno da media
    mediana = median(gasto), # valor central da distribuicao
    minimo = min(gasto), # menor gasto simulado
    maximo = max(gasto), # maior gasto simulado
    p05 = as.numeric(quantile(gasto, 0.05)), # limite inferior da faixa usual
    p25 = as.numeric(quantile(gasto, 0.25)), # primeiro quartil
    p75 = as.numeric(quantile(gasto, 0.75)), # terceiro quartil
    p90 = as.numeric(quantile(gasto, 0.90)), # limite superior da faixa usual
    p95 = as.numeric(quantile(gasto, 0.95)), # limite superior da faixa usual
    cv = sd(gasto) / mean(gasto) # dispersao relativa da simulacao
)

resumo_gasto_friendly <- data.frame(
    medida = names(resumo_gasto),
    valor = round(as.numeric(resumo_gasto), 2),
    row.names = NULL
)

print(resumo_gasto_friendly)

#Gráficos
hist(gasto)
plot(density(gasto))
plot(ecdf(gasto))

# Estatísticas principais
custo_base <- quantile(gasto, 0.50)
custo_p90  <- quantile(gasto, 0.90)

# Contingência
contingencia <- custo_p90 - custo_base
percentual_contingencia <- (contingencia / custo_base) * 100

# Exibir resultados
cat(sprintf("P50 (mediana):      R$ %.2f\n", custo_base))
cat(sprintf("P90 (cenário risco): R$ %.2f\n", custo_p90))
cat(sprintf("Contingência:       R$ %.2f\n", contingencia))
cat(sprintf("Contingência %%:     %.2f%%\n", percentual_contingencia))

#-------------------------------------------------
# Item 2
#-------------------------------------------------

set.seed(1)
n_simulacao <- 3000

# Parâmetros para a distribuição triangular (número de executivos)
exec_min <- 16
exec_moda <- 18
exec_max <- 22

# Gastos por pessoa no último almoço
gasto_por_pessoa <- c(347, 410, 349, 454, 370, 465, 445, 383, 358, 418, 377, 407, 467, 441, 428, 354, 384, 400, 378, 367, 421, 392, 337, 387, 452, 411, 339, 380, 371, 464, 369, 484, 458, 471, 362)

# Número de almoços nos últimos 10 anos
almocos_ultimos10 <- c(38, 45, 42, 37, 38, 31, 42, 37, 42, 40)

# Vetor para armazenar o custo anual de cada simulação
custo_anual <- numeric(n_simulacao)

# Loop sobre cada simulação (cada ano)
for(sim in 1:n_simulacao){
  # Determinar número de almoços naquele ano
  num_almocos <- sample(almocos_ultimos10, 1)
  
  # Somar custo de todos os almoços naquele ano
  custo_almocos_ano <- 0
  
  # Loop sobre cada almoço naquele ano
  for(alm in 1:num_almocos){
    # Gerar número de executivos presentes neste almoço
    num_executivos <- round(rtriangle(1, a = exec_min, b = exec_max, c = exec_moda))
    
    # Selecionar quem está presente (índices)
    presentes <- sample(1:exec_max, num_executivos, replace = FALSE)
    
    # Gerar gasto de cada executivo presente
    gastos_individuais <- sample(gasto_por_pessoa, num_executivos, replace = TRUE)
    
    # Custo deste almoço
    custo_almoço <- sum(gastos_individuais)
    
    # Acumular ao total do ano
    custo_almocos_ano <- custo_almocos_ano + custo_almoço
  }
  
  # Guardar custo anual da simulação
  custo_anual[sim] <- custo_almocos_ano
}

# Resumo estatístico do custo anual
resumo_custo <- c(
    media = mean(custo_anual), # valor esperado do custo anual
    desvio_padrao = sd(custo_anual), # variação absoluta
    mediana = median(custo_anual), # valor central
    minimo = min(custo_anual),
    maximo = max(custo_anual),
    p05 = as.numeric(quantile(custo_anual, 0.05)),
    p25 = as.numeric(quantile(custo_anual, 0.25)),
    p75 = as.numeric(quantile(custo_anual, 0.75)),
    p80 = as.numeric(quantile(custo_anual, 0.80)),
    p90 = as.numeric(quantile(custo_anual, 0.90)),
    p95 = as.numeric(quantile(custo_anual, 0.95)),
    cv = sd(custo_anual) / mean(custo_anual)
)

resumo_custo_friendly <- data.frame(
    medida = names(resumo_custo),
    valor = round(as.numeric(resumo_custo), 2),
    row.names = NULL
)

cat('\n--- Item 2: Resumo do custo anual (simulação) ---\n')
print(resumo_custo_friendly)

summary(custo_anual)

# Estatísticas principais
custo_base <- quantile(custo_anual, 0.50)
custo_p90  <- quantile(custo_anual, 0.90)

# Contingência
contingencia <- custo_p90 - custo_base
percentual_contingencia <- (contingencia / custo_base) * 100

# Exibir resultados
cat(sprintf("P50 (mediana):      R$ %.2f\n", custo_base))
cat(sprintf("P90 (cenário risco): R$ %.2f\n", custo_p90))
cat(sprintf("Contingência:       R$ %.2f\n", contingencia))
cat(sprintf("Contingência %%:     %.2f%%\n", percentual_contingencia))

# Visualizações rápidas
hist(custo_anual, main = 'Histograma do custo anual (Item 2)', xlab = 'Custo anual (R$)')
plot(density(custo_anual), main = 'Densidade do custo anual (Item 2)')
plot(ecdf(custo_anual), main = 'ECDF do custo anual (Item 2)')