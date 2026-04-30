if (!requireNamespace('triangle', quietly = TRUE)) {
    install.packages('triangle', repos = 'https://cloud.r-project.org')
}

library(triangle)

# Dados do problema
frota <- 20

carro_dia <- c(16, 12, 15, 16, 19, 14, 15, 17, 15, 18,
               19, 13, 17, 13, 15, 15, 17, 16, 15, 17,
               16, 13, 18, 14, 13, 14, 14, 18, 16 )

litro_carro <- c(59, 51, 46, 67, 69, 52, 57, 57, 42, 67,
                66, 67, 44, 59, 68, 61, 47, 51, 66, 48,
                60, 62, 63, 45, 59, 46, 55, 52, 53, 60,
                66, 46, 47, 63, 52, 64, 48, 47, 62, 49,
                53, 49, 51, 44, 55, 59, 60, 45, 64, 55)

# Parâmetros da simulação de risco
set.seed(1)
n_simulacao <- 3000

sort_ativos <- sort(carro_dia)
sort_consumo <- sort(litro_carro)

sample_ativos <- sample(1:length(carro_dia), n_simulacao, replace = TRUE)
sample_consumo <- sample(1:length(litro_carro), n_simulacao, replace = TRUE)

amostra_ativos <- sort_ativos[sample_ativos]
amostra_consumo <- sort_consumo[sample_consumo]

amostra_gasolina <- rtriangle(n_simulacao, 6.10, 7)

# Modelo do gasto diário com combustível
gasto <- amostra_ativos * amostra_consumo * amostra_gasolina

# Medidas para interpretar a distribuição simulada
resumo_gasto <- c(
    media = mean(gasto), # valor esperado do gasto diario
    desvio_padrao = sd(gasto), # variacao em torno da media
    mediana = median(gasto), # valor central da distribuicao
    minimo = min(gasto), # menor gasto simulado
    maximo = max(gasto), # maior gasto simulado
    p05 = as.numeric(quantile(gasto, 0.05)), # limite inferior da faixa usual
    p25 = as.numeric(quantile(gasto, 0.25)), # primeiro quartil
    p75 = as.numeric(quantile(gasto, 0.75)), # terceiro quartil
    p95 = as.numeric(quantile(gasto, 0.95)), # limite superior da faixa usual
    cv = sd(gasto) / mean(gasto) # dispersao relativa da simulacao
)

resumo_gasto_friendly <- data.frame(
    medida = names(resumo_gasto),
    valor = round(as.numeric(resumo_gasto), 2),
    row.names = NULL
)

print(resumo_gasto_friendly)

# Visualizações da distribuição simulada
hist(gasto)
plot(density(gasto))
plot(ecdf(gasto))


# -----------------------------
# Item 2 - custo anual com almoços
# -----------------------------
# Dados do enunciado: número de executivos (min, mode, max), gastos por pessoa e
# número de almoços por ano (últimos 10 anos)
exec_min <- 16
exec_mode <- 18
exec_max <- 22

gasto_por_pessoa <- c(347,410,349,454,370,465,445,383,358,418,377,407,467,441,428,354,384,400,378,367,421,392,337,387,452,411,339,380,371,464,369,484,458,471,362)

almocos_ultimos10 <- c(38,45,42,37,38,31,42,37,42,40)

# Parâmetros de simulação (mantendo o mesmo n_simulacao)
set.seed(1)

# Simular número de executivos por almoço com distribuição triangular (discreta via arredondamento)
exec_sim <- round(rtriangle(n_simulacao, a = exec_min, b = exec_max, c = exec_mode))

# Simular gasto por pessoa e número de almoços por ano por amostragem empírica (bootstrap)
gasto_pessoa_sim <- sample(gasto_por_pessoa, n_simulacao, replace = TRUE)
almocos_ano_sim <- sample(almocos_ultimos10, n_simulacao, replace = TRUE)

# Custo anual = número de executivos * gasto por pessoa * número de almoços no ano
custo_anual <- exec_sim * gasto_pessoa_sim * almocos_ano_sim

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

# Visualizações rápidas
hist(custo_anual, main = 'Histograma do custo anual (Item 2)', xlab = 'Custo anual (R$)')
plot(density(custo_anual), main = 'Densidade do custo anual (Item 2)')
plot(ecdf(custo_anual), main = 'ECDF do custo anual (Item 2)')



