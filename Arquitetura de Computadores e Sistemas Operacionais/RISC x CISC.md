# RISC x CISC

Basicamente, uma arquitetura de processador busca executar os programas da maneira mais rápida possível.

Cálculo do tempo de execução do programa
$$
T_p = N_i * T_c * N_c 
$$
$T_p$ = tempo de execução do programa 
$N_i$ = número de instruções
$T_c$ = tempo de cada ciclo de relógio 
$N_c$ = Número de ciclos

Assim, temos duas opções que minimizam o tempo nessa equação: 

- Diminuindo o número de instruções, mas aumentando o número de ciclos e tempo de cada ciclo de relógio (CISC).
- Aumentando o número de instruções, mas diminuindo o número de ciclos e tempo de cada ciclo de relógio (RISC).

| **CISC** | **RISC** |
| --- | --- |
| Arquitetura Memória-Memória | Arquitetura Registrador |
| Instruções complexas que demandam um número grande de ciclos de máquina para execução. E esses ciclos de máquina possuem tempo aumentado também por conta da complexidade do hardware necessário. | Instruções mais simples que demandam um número fixo de ciclos de máquina para sua execução. São poucos formatos diferentes de instruções e apenas as de “load” e “store” acessam a memória. |
| Uso de diversos modos de endereçamento de operandos. | Uso de poucos modos simples de endereçamento de operandos. |
| Enfraquecimento do pipeline. | Implementadas com o uso do pipeline. |
| Unidade de controle microprogramada. | Unidade de controle “hardwired”. |
| Programas menores. | Programas maiores. |