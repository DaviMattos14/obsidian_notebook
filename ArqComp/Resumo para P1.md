# Aula 1 

## Modelo Von Neumann
![[Pasted image 20240924182156.png]]

## Modelo de Barramento
![[Pasted image 20240924182233.png]]

### Memória Principal e Secundária
- Memória Principal
	- Volátil (RAM)
	As informações armazenadas na memória volátil podem ser alteradas durante a execução de um programa. São também usadas para armazenar os resultados intermediários e finais das operações realizadas pelo processador.
	- Não Volátil (BIOS)
	A memória não volátil é usada para armazenar informações que não necessitam ser alteradas no decorrer do processamento. É utilizada para iniciar o funcionamento do computador, realizando os testes iniciais e cópia do sistema operacional para a memória.
	
- Memória Secundária
A memória secundária é onde os programas e dados, incluindo aqueles do sistema operacional, são armazenados de uma forma persistente no computador. Hoje em dia é constituída, principalmente, pelo conjunto de discos magnéticos (HDs) do computador e também, cada vez mais, pelos discos de estado sólido (SSDs).

A principal característica da memória secundária é o armazenamento da informação de uma forma permanente, mesmo quando o computador é desligado.

Uma das características da memória secundária é o alto volume de dados e o baixo custo de armazenamento por byte quando comparado com a memória principal.
### Entrada/Saída
A unidade de entrada e saída é necessária para prover a comunicação entre os dispositivos de ENTRADA e SAÍDA com as demais partes
do computador.
- Toda a informação é convertida de/para o formato binário pela unidade de entrada/saída.
Exemplos de dispositivos de entrada/saída: são o disco rígido, teclado,  terminal de vídeo, mouse, impressora, entre outros.

### Processador
A UPC (Unidade de Processamento Central - CPU) é o conjunto da unidade lógica e aritmética, registradores e da unidade de controle.

Sua função é executar os programas armazenados na memória principal, buscando suas instruções, examinando as, e então executando uma após a outra.
O processador é responsável pela realização de uma série de funções:
- Busca de instruções e dados na memória.
- Programa a transferência de dados entre a memória e os dispositivos de entrada/saída.
- Decodifica as instruções.
- Realiza as operações lógica e aritméticas.
- Responde a sinais enviados por dispositivos de entrada/saída como RESET ou interrupções.

## Arquitetura do Processador

### Unidade Aritmética e Lógica (UAL)

A largura da arquitetura de um processador (8, 16, 32 ou 64 bits) é definida pela largura em bits do maior operando inteiro que pode ser utilizado em uma única operação pela UAL.

Como consequência direta, a largura em bits do maior operando admitido pela UAL irá determinar, normalmente, a largura em bits do acumulador e dos registradores de uso geral do processador. Não há sentido para que sejam maiores ou menores do que isso.

### Registradores
O processador contém elementos de memória, de pequena capacidade mas de alta velocidade, usados para armazenar resultados temporários, chamados de **registradores**.
O conjunto desses registradores é denominado banco de **registradores**.
Existe um registrador invisível ao programador, chamado de registrador de instrução (**RI**), que armazena a instrução que está sendo executada.
Existe um registrador especial denominado apontador de instruções       (**PC**) , que contém o endereço da próxima instrução que vai ser executada.

### Unidade de Controle
A unidade de controle é responsável pela coordenação da atividade de todos os componentes do processador.
- Ela busca a instrução na memória e coloca no registrador de instruções (RI).
A unidade de controle faz a decodificação da instrução que está no RI:
- Determina qual o tipo de operação vai ser realizada pela UAL
- Determina quantos e quais são os operandos de leitura, e qual o registrador de destino, se houver.
- Lê os operandos necessários para a execução da instrução e os coloca na entrada da UAL.
A unidade de controle lê o resultado da saída da UAL e envia para o destino correto.
Há duas formas de se implementar a unidade de controle:
* Através de microprogramação
	Arquiteturas do tipo **CISC**
* Controle direto pelo hardware (PLA, ROM)
	Arquiteturas do tipo **RISC**.

### Tipos de Arquitetura

- Arquitetura de Acumulador
	- Um operando (em registrador ou memória), o acumulador é usado como operando implícito a maioria das vezes
	![[Pasted image 20240924205755.png]]
- Arquitetura de Pilha
	- Nenhum operando: todos operandos são implícitos no topo da pilha
	![[Pasted image 20240924205830.png]]
- Arquitetura de Registrador (load / store)
	- Três operandos, todos nos registradores
	- loads e stores são as únicas instruções que fazem acesso à memória
- Arquitetura Registrador-Memória
	- Dois operandos, um em memória
- Arquitetura Memória-Memória
	- Três operandos, podem todos estar na memória

### Sinal de Relógio (Clock)
