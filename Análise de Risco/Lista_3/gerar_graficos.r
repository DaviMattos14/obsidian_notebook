# Script para gerar gráficos de saída
library(triangle)

# ===== Item 1 =====
frota <- 20

carro_dia <- c(16, 12, 15, 16, 19, 14, 15, 17, 15, 18,
               19, 13, 17, 13, 15, 15, 17, 16, 15, 17,
               16, 13, 18, 14, 13, 14, 14, 18, 16 )

litro_carro <- c(59, 51, 46, 67, 69, 52, 57, 57, 42, 67,
                66, 67, 44, 59, 68, 61, 47, 51, 66, 48,
                60, 62, 63, 45, 59, 46, 55, 52, 53, 60,
                66, 46, 47, 63, 52, 64, 48, 47, 62, 49,
                53, 49, 51, 44, 55, 59, 60, 45, 64, 55)

set.seed(1)
n_simulacao <- 3000
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
  rtriangle(n_simulacao, 6.10, 7),
  nrow=n_sim,
  ncol=n_carros
)

matriz_consumo <- matriz_consumo * matriz_ativos
gasto <- rowSums(matriz_consumo * matriz_preco)

# Gráficos Item 1
png('grafico_item1_histograma.png', width=600, height=400)
hist(gasto, main='Histograma do Gasto Diário com Combustível', 
     xlab='Gasto Diário (R$)', ylab='Frequência', col='steelblue', border='black')
dev.off()

png('grafico_item1_densidade.png', width=600, height=400)
plot(density(gasto), main='Densidade do Gasto Diário com Combustível',
     xlab='Gasto Diário (R$)', ylab='Densidade', col='darkblue', lwd=2)
polygon(density(gasto), col=rgb(0.1, 0.3, 0.7, 0.3))
dev.off()

png('grafico_item1_ecdf.png', width=600, height=400)
plot(ecdf(gasto), main='Distribuição Acumulada (ECDF) do Gasto Diário',
     xlab='Gasto Diário (R$)', ylab='Probabilidade Acumulada', 
     col='darkgreen', lwd=2)
grid(TRUE, col='gray70')
dev.off()

# ===== Item 2 =====
set.seed(1)

exec_min <- 16
exec_moda <- 18
exec_max <- 22

gasto_por_pessoa <- c(347, 410, 349, 454, 370, 465, 445, 383, 358, 418, 377, 407, 467, 441, 428, 354, 384, 400, 378, 367, 421, 392, 337, 387, 452, 411, 339, 380, 371, 464, 369, 484, 458, 471, 362)

almocos_ultimos10 <- c(38, 45, 42, 37, 38, 31, 42, 37, 42, 40)

sample_presenca <- sample(round(rtriangle(n_simulacao, a = exec_min, b = exec_max, c = exec_moda)), n_sim, replace = TRUE)

matriz_presenca <- matrix(0, nrow = n_sim, ncol = exec_max)

for(i in 1:n_sim){
  k <- sample_presenca[i]
  ativos_indices <- sample(1:exec_max, k, replace = FALSE)
  matriz_presenca[i, ativos_indices] <- 1
}

matriz_valor_por_pessoa <- matrix(
  sample(gasto_por_pessoa, n_simulacao, replace = TRUE),
  nrow = n_sim,
  ncol = exec_max
)

matriz_almocos_por_ano <- matrix(
  sample(almocos_ultimos10, n_simulacao, replace = TRUE),
  nrow = n_sim,
  ncol = 1
)

custo_por_pessoa <- matriz_valor_por_pessoa * matriz_presenca
custo_anual <- matriz_almocos_por_ano * rowSums(custo_por_pessoa)

# Gráficos Item 2
png('grafico_item2_histograma.png', width=600, height=400)
hist(custo_anual, main='Histograma do Custo Anual com Almoços', 
     xlab='Custo Anual (R$)', ylab='Frequência', col='indianred', border='black')
dev.off()

png('grafico_item2_densidade.png', width=600, height=400)
plot(density(custo_anual), main='Densidade do Custo Anual com Almoços',
     xlab='Custo Anual (R$)', ylab='Densidade', col='darkred', lwd=2)
polygon(density(custo_anual), col=rgb(0.8, 0.3, 0.3, 0.3))
dev.off()

png('grafico_item2_ecdf.png', width=600, height=400)
plot(ecdf(custo_anual), main='Distribuição Acumulada (ECDF) do Custo Anual',
     xlab='Custo Anual (R$)', ylab='Probabilidade Acumulada', 
     col='darkred', lwd=2)
grid(TRUE, col='gray70')
dev.off()

cat("Gráficos gerados com sucesso!\n")
