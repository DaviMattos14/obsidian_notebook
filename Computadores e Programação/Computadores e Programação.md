## Visão Geral dos Sistemas (Aula 2 e 3)
### Sistema de Computador
Consistem de hardware e sistemas de software que funcionam juntos para executar aplicações do usuário. As implementações específicas podem variar com o tempo, mas os conceitos fundamentais não mudam.

### Bits + contexto
Um programa começa com um programa fonte escrito por um programador, em uma linguagem de alto
nível e armazenado em um arquivo (*hello.c*)

O programa fonte  é uma **sequência de bits** (0s e 1s), organizados em grupos de 8 bits chamados **bytes**.

Cada byte representa um **caractere** alfa numérico (de texto) A maioria dos sistemas modernos representa caracteres usando o padrão ASCII.

Arquivos como *hello.c*, constituídos exclusivamente de caracteres ASCII (i.e., sem formatação), são conhecidos como **arquivos texto**.

Todos os outros arquivos são conhecidos como **arquivos binários**

- Toda informação em um sistema (incluindo arquivos no disco, programas ou dados do usuário na memória, dados transferidos na rede) é representada como conjunto de bits.
- A  única coisa que diferencia é o contexto no qual a informação (conjunto de bits) é vista (ex., a mesma sequência de bits pode ser vista como um número inteiro, uma string, uma instrução de máquina, etc.)
### Tradução de programas
- Para executar o programa *hello* no sistema, as sentenças C devem ser traduzidas por outros programas em uma sequência de instruções de linguagem de máquina
- Essas instruções são então empacotadas no formato chamado programa (ou arquivo) objeto executável e armazenado como arquivo binário no disco 
- No UNIX, a tradução de arquivo fonte em arquivo executável pode ser feita pelo programa gcc:

### Sistema de Compilação
![[sistema_compilação.png]]

A tradução de programas é feita em quatro fases:
1. Pré-processamento (para gerar arquivo fonte com as inclusões especificadas) 
2. Compilação (para gerar código de montagem) 
3. Montagem (para gerar código binário relocável) 
4. Ligação (para gerar código binário executável)
Os programas que executam as quatro fases de tradução são chamados coletivamente de sistema de compilação

#### Pré-Processamento
O pré-processador (gcc -E) modifica o programa original C tratando as diretivas que começam com o caracter # 
Ex: a diretiva # include < stdio.h > diz para o preprocessador ler o conteúdo do arquivo stdio.h e inserir o conteúdo no programa fonte, gerando o arquivo hello.i

#### Compilador
O compilador (gcc -S) traduz o arquivo texto hello. i no arquivo texto hello.s, o qual contém o programa em linguagem de montagem 
Cada sentença no programa em linguagem de montagem descreve exatamente uma instrução de máquina em um formato de texto padrão 
<font color="#ff0000">A linguagem de montagem provê uma linguagem de saída comum para diferentes compiladores e linguagens de alto nível</font>

#### Montagem
O montador (gcc -c) traduz o arquivo hello. s em instruções de linguagem de máquina, empacotadas no formato conhecido como programa objeto relocável e armazena em um arquivo hello. o 
Trata-se de um arquivo binário, cujos bytes codificam instruções em linguagem de máquina (ao invés de caracteres)

#### Ligação
O programa hello chama a função printf que não é implementada em hello. c (faz parte da biblioteca C padrão) 
A função printf reside em um arquivo objeto precompilado chamado printf.o, o qual deve ser incorporado ao programa hello. o (ligação) 
O ligador (gcc) trata essa incorporação 
O resultado é o arquivo hello, um arquivo objeto executável que está pronto para ser carregado na memória e executado pelo sistema

### Leitura e interpretação de instruções
Nesse ponto, nosso programa fonte hello. c pode ser executado no shell Unix 
O shell é um interpretador de linha de comando que exibe um prompt e espera pela entrada de comandos

### Resumo de [[Resumo ArqCompSO]]
#### Abstrações de SO
##### Arquivo
Um arquivo é uma sequência de bytes com um determinado tamanho (em bytes) 
Todo dispositivo de E/S (disco, teclado, monitor, rede) é modelado como um arquivo 
Toda tarefa de E/S é executada lendo e escrevendo em arquivos através de chamadas de sistema do SO 
<font color="#00b050">Vantagem</font>: Usa-se primitivas de nível mais alto e não é preciso conhecer a tecnologia de cada dispositivo

##### Redes
Os sistemas de computador modernos estão normalmente ligados entre si através de infraestruturas de redes 
Do ponto de vista de um sistema isolado, a rede pode ser vista como mais um dispositivo de E/S 
O processador pode copiar dados entre a memória principal e o adaptador de rede (em geral via DMA), permitindo a comunicação entre diferentes máquinas

#### Concorrência e Paralelismo
**Concorrência** é o termo usado para referenciar a noção geral de um sistema com atividades simultâneas 
**Paralelismo** é o termo usado para referenciar o <font color="#ff0000">uso da concorrência para fazer um sistema executar mais rápido </font>
O paralelismo pode ser explorado em diferentes níveis de abstracão threads, instrucão e SIMD (Single-Instruction, Multiple-Data)

### Representação e Manipulação da Informação
Os computadores armazenam e processam informações representadas como valores binários 
Os circuitos eletrônicos para armazenar, processar e transmitir sinais binários são muito mais simples de construir e manter
Consideraremos as três principais formas de representação de numeros: 
- **Sem sinal**: notação binária tradicional, representando números maiores ou iguais a zero 
- **Complemento a 2**: forma mais comum para representar números negativos 
	Exemplo:
$$
\begin{matrix}
0101=-0\cdot2^3+1\cdot2^2+0\cdot2^1+1\cdot2^0=-0+5=5 \\
1011=-1\cdot2^3+0\cdot2^2+1\cdot2^1+1\cdot2^1=-8+3=-5
\end{matrix}
$$
- **Ponto-flutuante**: versão na base binária da notação científica para representar números reais (veremos detalhes mais a frente)
A representação de números no computador usa uma quantidade limitada de bits 
Em razão disso, algumas operações podem causar <font color="#c00000">estouro</font> (overflow) quando os resultados obtidos são maiores que o que é possível representar 
Acontece também o arredondamento de valores (aproximações, a serem estudadas com detalhes em cálculo numérico)

## Armazenamento de informações no Computador (Aula 4)
### Endereços de Memória
• Cada byte da memória é identificado por um número único, chamado endereço 
• O conjunto de todos os possíveis endereços é chamado espaço de endereçamento virtual (visto pelos programas como um vetor de bytes monolítico) 
Por ex., o valor de um ponteiro em C é o endereço virtual do primeiro byte de um bloco contínuo de armazenamento

### Sistema de Numeração
Permite quantificar coisas e é formado por: 
- Conjunto de algarismos 
- Conjunto de regras que estabelecem como representar quantidades numéricas com os algarismos
- Conjunto de operações que podem ser efetuadas com as quantidades numéricas

### Bases de Potenciação
Os números podem ser representados em qualquer base de pontenciação (ou simplesmente base) 
Uma base K requer K símbolos diferentes para representar os dígitos de 0 a (K-1) 
- O sistema binário possui 2 símbolos: **0 1** 
- O sistema octal possui 8 símbolos: **0 1 2 3 4 5 6 7** 
- O sistema decimal possui 10 símbolos: **0 1 2 3 4 5 6 7 8 9** 
- O sistema hexadecimal possui 16 símbolos: **0 1 2 3 4 5 6 7 8 9 A B C D E F**

### Notação Posicional
A forma geral de representação e interpretação de quantidades numéricas usa a idéia de **valor posicional** 
A posição dos algarismos determina o seu valor 
O valor do i-ésimo dígito D é $D * Base^i$ 
	**i** é a posição do algarismo no número, sendo i = 0 a posição menos significativa, à direita
O valor total é a soma dos valores relativos
![[notacao_posicional.png]]

### Conversão entre bases
#### Decimal $\rightarrow$ Binário

![[dec_bin.png]]
#### Decimal $\rightarrow$ Octal
![[dec_oct.png]]
#### Decimal $\rightarrow$ Hexadecimal
![[dec_hex.png]]
#### Binário $\rightarrow$ Decimal
![[bin_dec1.png]]
![[bin_dec2.png]]
#### Octal $\rightarrow$ Decimal
<img src="oct_dec_1.png" width="330"/> <img src="oct_dec_2.png" width="330"/>
#### Hexadecimal $\rightarrow$ Decimal
![[hex_dec1.png]]![[hex_dec2.png]]
#### Binário, Hexadecimal $\rightarrow$ Binário
![[oct_bin.png]]![[hex_bin.png]]
#### Binário $\rightarrow$ Octal, Hexadecimal
![[bin_hex_octa.png]]
### Tamanho de Palavra e formatos de dados
