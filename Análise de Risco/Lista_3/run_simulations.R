#!/usr/bin/env Rscript
if(!require('triangle', quietly=TRUE)){
  install.packages('triangle', repos='https://cloud.r-project.org')
  library(triangle)
} else { library(triangle) }

set.seed(1)

# Dados Item 1
carro_dia <- c(16, 12, 15, 16, 19, 14, 15, 17, 15, 18,
               19, 13, 17, 13, 15, 15, 17, 16, 15, 17,
               16, 13, 18, 14, 13, 14, 14, 18, 16)

litro_carro <- c(59, 51, 46, 67, 69, 52, 57, 57, 42, 67,
                66, 67, 44, 59, 68, 61, 47, 51, 66, 48,
                60, 62, 63, 45, 59, 46, 55, 52, 53, 60,
                66, 46, 47, 63, 52, 64, 48, 47, 62, 49,
                53, 49, 51, 44, 55, 59, 60, 45, 64, 55)

n_sim <- 3000
n_carros <- 20

sample_ativos <- sample(carro_dia, n_sim, replace = TRUE)

matriz_ativos <- matrix(0, nrow = n_sim, ncol = n_carros)
for(i in 1:n_sim){
  k <- sample_ativos[i]
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
  rtriangle(n_sim * n_carros, a = 6.10, b = 7.00, c = 6.55),
  nrow = n_sim,
  ncol = n_carros
)

gasto <- rowSums(matriz_consumo * matriz_preco)

# Estatísticas Item 1
item1_stats <- list(
  minimo = min(gasto),
  p05 = as.numeric(quantile(gasto, 0.05)),
  p25 = as.numeric(quantile(gasto, 0.25)),
  mediana = as.numeric(quantile(gasto, 0.50)),
  p75 = as.numeric(quantile(gasto, 0.75)),
  p90 = as.numeric(quantile(gasto, 0.90)),
  p95 = as.numeric(quantile(gasto, 0.95)),
  maximo = max(gasto),
  sd = sd(gasto),
  cv = sd(gasto) / mean(gasto)
)

dir.create('c:\\Users\\Pichau\\Documents\\REPOSITÓRIOS\\obsidian_notebook\\Análise de Risco\\Lista_3\\figs', showWarnings = FALSE, recursive = TRUE)

png('c:\\Users\\Pichau\\Documents\\REPOSITÓRIOS\\obsidian_notebook\\Análise de Risco\\Lista_3\\grafico_item1_histograma.png', width=800, height=600)
hist(gasto, main='Histograma - Gasto Diário (Item 1)', xlab='Gasto (R$)', col='lightblue')
dev.off()

png('c:\\Users\\Pichau\\Documents\\REPOSITÓRIOS\\obsidian_notebook\\Análise de Risco\\Lista_3\\grafico_item1_densidade.png', width=800, height=600)
plot(density(gasto), main='Densidade - Gasto Diário (Item 1)', xlab='Gasto (R$)')
dev.off()

png('c:\\Users\\Pichau\\Documents\\REPOSITÓRIOS\\obsidian_notebook\\Análise de Risco\\Lista_3\\grafico_item1_ecdf.png', width=800, height=600)
plot(ecdf(gasto), main='ECDF - Gasto Diário (Item 1)', xlab='Gasto (R$)')
dev.off()

writeLines(sprintf('minimo=%.2f', item1_stats$minimo), 'c:\\Users\\Pichau\\Documents\\REPOSITÓRIOS\\obsidian_notebook\\Análise de Risco\\Lista_3\\item1_results.txt')
cat(sprintf('\np05=%.2f\np25=%.2f\nmediana=%.2f\np75=%.2f\np90=%.2f\np95=%.2f\nmaximo=%.2f\nsd=%.2f\ncv=%.4f\n',
      item1_stats$p05, item1_stats$p25, item1_stats$mediana,
      item1_stats$p75, item1_stats$p90, item1_stats$p95,
      item1_stats$maximo, item1_stats$sd, item1_stats$cv),
    file='c:\\Users\\Pichau\\Documents\\REPOSITÓRIOS\\obsidian_notebook\\Análise de Risco\\Lista_3\\item1_results.txt', append=TRUE)

# Item 2
exec_min <- 16
exec_moda <- 18
exec_max <- 22

gasto_por_pessoa <- c(347, 410, 349, 454, 370, 465, 445, 383, 358, 418, 377, 407, 467, 441, 428, 354, 384, 400, 378, 367, 421, 392, 337, 387, 452, 411, 339, 380, 371, 464, 369, 484, 458, 471, 362)
almocos_ultimos10 <- c(38, 45, 42, 37, 38, 31, 42, 37, 42, 40)

custo_anual <- numeric(n_sim)
for(sim in 1:n_sim){
  num_almocos <- sample(almocos_ultimos10, 1)
  custo_almocos_ano <- 0
  for(alm in 1:num_almocos){
    num_executivos <- round(rtriangle(1, a = exec_min, b = exec_max, c = exec_moda))
    gastos_individuais <- sample(gasto_por_pessoa, num_executivos, replace = TRUE)
    custo_almoço <- sum(gastos_individuais)
    custo_almocos_ano <- custo_almocos_ano + custo_almoço
  }
  custo_anual[sim] <- custo_almocos_ano
}

item2_stats <- list(
  minimo = min(custo_anual),
  p05 = as.numeric(quantile(custo_anual, 0.05)),
  p25 = as.numeric(quantile(custo_anual, 0.25)),
  mediana = as.numeric(quantile(custo_anual, 0.50)),
  p75 = as.numeric(quantile(custo_anual, 0.75)),
  p80 = as.numeric(quantile(custo_anual, 0.80)),
  p90 = as.numeric(quantile(custo_anual, 0.90)),
  p95 = as.numeric(quantile(custo_anual, 0.95)),
  maximo = max(custo_anual),
  media = mean(custo_anual),
  sd = sd(custo_anual),
  cv = sd(custo_anual) / mean(custo_anual)
)

png('c:\\Users\\Pichau\\Documents\\REPOSITÓRIOS\\obsidian_notebook\\Análise de Risco\\Lista_3\\grafico_item2_histograma.png', width=800, height=600)
hist(custo_anual, main='Histograma - Custo Anual (Item 2)', xlab='Custo anual (R$)', col='lightgreen')
dev.off()

png('c:\\Users\\Pichau\\Documents\\REPOSITÓRIOS\\obsidian_notebook\\Análise de Risco\\Lista_3\\grafico_item2_densidade.png', width=800, height=600)
plot(density(custo_anual), main='Densidade - Custo Anual (Item 2)', xlab='Custo anual (R$)')
dev.off()

png('c:\\Users\\Pichau\\Documents\\REPOSITÓRIOS\\obsidian_notebook\\Análise de Risco\\Lista_3\\grafico_item2_ecdf.png', width=800, height=600)
plot(ecdf(custo_anual), main='ECDF - Custo Anual (Item 2)', xlab='Custo anual (R$)')
dev.off()

cat(sprintf('minimo=%.2f\n', item2_stats$minimo), file='c:\\Users\\Pichau\\Documents\\REPOSITÓRIOS\\obsidian_notebook\\Análise de Risco\\Lista_3\\item2_results.txt')
cat(sprintf('\np05=%.2f\np25=%.2f\nmediana=%.2f\np75=%.2f\np80=%.2f\np90=%.2f\np95=%.2f\nmaximo=%.2f\nmedia=%.2f\nsd=%.2f\ncv=%.4f\n',
      item2_stats$p05, item2_stats$p25, item2_stats$mediana,
      item2_stats$p75, item2_stats$p80, item2_stats$p90, item2_stats$p95,
      item2_stats$maximo, item2_stats$media, item2_stats$sd, item2_stats$cv),
    file='c:\\Users\\Pichau\\Documents\\REPOSITÓRIOS\\obsidian_notebook\\Análise de Risco\\Lista_3\\item2_results.txt', append=TRUE)

cat('Simulações concluídas. Arquivos gerados em Lista_3/.\n')
