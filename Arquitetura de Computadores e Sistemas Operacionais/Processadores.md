# Processadores

Também é conhecido como CPU e é uma espécie de microchip especializado.

## Composição

- Unidade de Controle: Responsável por buscar as instruções na memória principal e por interpretar e determinar o tipo de cada instrução.
- Unidade Lógica Aritmética: Responsável por realizar cálculos matemáticos e lógicos que são necessários para executar cada instrução. Ela não lida diretamente com as instruções do programa, apenas “obedece” as operações decodificadas pela Unidade de Controle.
- Registradores: Memórias pequenas e de alta velocidade, que armazenam resultados temporários e certas informações de controle (evita acessos excessivos à memória principal).

![Note que não existe apenas barramento externo. ULA e registradores, por exemplo, também se comunicam por barramento interno. Podemos observar que o processador também lida diretamente com os dados transferidos de um elemento a outro da máquina (a placa mãe serve de ponte entre o processador e os outros componentes de hardware da máquina).](arq_processador.png)

Note que não existe apenas barramento externo. ULA e registradores, por exemplo, também se comunicam por barramento interno. Podemos observar que o processador também lida diretamente com os dados transferidos de um elemento a outro da máquina (a placa mãe serve de ponte entre o processador e os outros componentes de hardware da máquina).

## Registradores mais importantes

- **PC**: aponta para a próxima instrução a ser buscada na memória (isto é, armazena o endereço de memória da próxima instrução).
- **RI**: armazena a instrução que está sendo executada no momento.
- **REM**: armazena temporariamente um endereço de memória.
- **RDM**: armazena temporariamente dados que estão sendo transferidos da memória principal para a CPU e vice-versa.

## Funcionamento

![WhatsApp Image 2024-09-08 at 10.51.00_18b192e3.jpg](funcionamento_processador.jpg)

![image.png](diagrama_processador.png)

## Características gerais

- Cores: Core é o núcleo do processador (cada núcleo é composto pelas unidades básicas descritas anteriormente). Existem processadores core e multicore.
- Frequência: Capacidade do processador de processar informações ao mesmo tempo (depende do ciclo de relógio) e é medida em hertz.
- Cache: Memória auxiliar que ajuda a diminuir o tempo de transmissão das informações entre o processador e outros componentes.
- Potência: Quantia de enrgia consumida por segundo (medida em Watts - W).

PS: Os bytes são agrupados em palavras e a maioria das instruções operam sobre palavras. Assim, os registradores da CPU geralmente são do tamanho de uma palavra, então, se for de 32 bits, são 4 células que podem ser operadas a cada instrução. E, o tamanho da palavra, define normalmente a largura do processador.