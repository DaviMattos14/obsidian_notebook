# Fundamentos de Hardware e Software

## Barramentos

- Meio de comunicação entre os diferentes elementos da máquina.
- São os caminhos por onde transitam: dados, endereços e sinais de controle.

- Barramento Síncrono
    - Existe um relógio temporizador que define a frequência de operação. São mais velozes e mais fáceis de serem construídos e a maioria dos barramentos é desse tipo.
    - Para memorizar: lembre de telefone.
- Barramento Assíncrono
    - Não existe temporizador e os ciclos duram o tempo requerido pela operação. Faz uso de sinalizações e são mais flexíveis, sendo bons para atender dispositivos diferentes (lentos e rápidos).
    - Para memorizar: lembre de e-mail.

## Registradores

- **Visíveis**: Registradores acessíveis pelo programador diretamente.
    - Dados:  contém dados (acumulador, RDM, etc).
    - Endereços: contém endereços de memória dos dados ou instruções (exemplo: REM, SP, SX, etc).
    - Condições: contém bits e flags de condição do resultado de uma operação (flag de sinal, flag de zero e flag de overflow).

## Instruções

**Definição**: Sequência de bits que são interpretados pela Unidade de Controle e que disparam operações lógicas ou aritméticas a serem executadas pelo hardware.

**Tipos:**

- Acesso à memória (transferência de dados entre processador e memória).
- Entrada e saída (transferência de dados entre processador e dispositivos).
- Tratamento de dados (operações aritméticas ou lógicas).
- Controle (desvios).

- **Invisíveis ou de Controle e Status**: Registradores não acessíveis pelo programador diretamente.
    - PC, RI, PSW (contém códigos de condição, bits de informação do status, bit de interrupção, bit de modo de operação, etc).

![Figura 1. Ciclo básico de instruções.](ciclo%20basico%20instrucoes.jpg)

Figura 1. Ciclo básico de instruções.