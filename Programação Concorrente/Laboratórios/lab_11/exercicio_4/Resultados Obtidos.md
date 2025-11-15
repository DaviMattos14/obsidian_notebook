# Atividade 1

## Casos de Testes

| Nº threads          | 10                                     | 4                                                | 2                                 | 1                                                   |
| ------------------- | -------------------------------------- | ------------------------------------------------ | --------------------------------- | --------------------------------------------------- |
| Tam Pool de threads | 5                                      | 10                                               | 2                                 | 11                                                  |
| Resultado Esperado  | Primos = {2,3}<br>Não-Primos{0,1,4}    | Primos = {2,3,5,7}<br>Não-Primos = {0,1,4,6,8,9} | Primos = {}<br>Não-Primos = {0,1} | Primos = {2,3,5,7}<br>Não-Primos = {0,1,4,6,8,9,10} |
| Resultado Obtido    | Primos = {2,3}<br>Não-Primos = {0,1,4} | Primos = {2,3,5,7}<br>Não-Primos = {0,1,4,6,8,9} | Primos = {}<br>Não-Primos = {0,1} | Primos = {2,3,5,7}<br>Não-Primos = {0,1,4,6,8,9,10} |

# Atividade 3


| Nº threads                                 | 2   | 4   | 8   | 10     | 1   | 10      |
| ------------------------------------------ | --- | --- | --- | ------ | --- | ------- |
| N                                          | 2   | 10  | 23  | 110001 | 11  | 1000001 |
| Resultado Esperado (Qtd de números primos) | 1   | 4   | 9   | 10453  | 5   | 78498   |
| Resultado Obtido (Qtd de números primos)   | 1   | 4   | 9   | 10453  | 5   | 78498   |
