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

### Organização do hardware de um sistema
![[org_hardware.png]]

##### Barramentos:
- Condutores elétricos que carregam bytes de informação entre os demais componentes 
- São projetados para transferir bytes agrupados em palavras (ex., 4bytes, 8bytes) 
##### Dispositivos de E/S 
- Conexão do sistema com o mundo externo
##### Memória Principal
  - Dispositivo de armazenamento temporário que armazena programas e os dados usados por eles enquanto o processador está executando o programa 
  - Logicamente a memória é organizada como um vetor de bytes, cada byte com seu próprio endereço Espaço máximo de endereçamento: 
	  - 4G (232) bytes, sem extensão, arquitetura de 32 bits 
	  - 16EXA (264) bytes, teórico na arquitetura de 64 bits, embora 256 TERA (248) bytes usado nos processadores x86-64 atuais
##### Processador
A CPU (Unidade Central de Processamento) é a máquina que interpreta e executa as instruções armazenadas na memória principal 
O PC (Ponteiro ou Contador de Programa) contém o endereço da próxima instrução a ser executada em linguagem de máquina 
Operações básicas executadas pela CPU: 
- carga/armazenamento de dados da memória/ registrador 
- operações lógicas/ aritméticas nos registradores 
- desvio para outros pontos do programa

#### Uso de Cache
Cache é uma memória bem mas rápida (e cara) que a memória principal e de tamanho bem menor
Idéia básica: duplicar em cache uma área da memória para permitir o acesso mais rápido à informação (que teria que ser buscada na memória mais lenta se a cache não existisse)
Cache só é eficiente se houver localidade (tendência dos programas de acessar instruções e dados em regiões localizadas proximamente)
Acesso e atualizações da cache são feitos pelo hardware de forma transparente
![[Computadores e Programação/imagens/hierarquia_memoria.png]]
#### Funcionalidades de Sistema Operacional
O Sistema Operacional (SO) tem duas funções básicas: 
1. O Proteger o hardware do uso inapropriado pelas aplicações 
2. Prover mecanismos elementares para interação das aplicações com os dispositivos de hardware, simplificando a tarefa dos desenvolvedores de aplicações
![[so.png]]
![[abstracao_so.png]]

#### Processos
Caracteriza um **programa em execução** 
Vários processos podem executar **concorrentemente**, i.e., a execução das instruções de um processo pode alternar com a execução das instruções de outro processo num mesmo computador 
O SO usa o mecanismo de **troca de contexto** para alternar entre a execução de um processo e outro 
Para isso, **informações de contexto** são armazenadas para cada processo (estado das variáveis, ponteiro de programa, pilha de execução, conteúdo da memória, etc.)

#### Threads
Threads é o nome dado às diferentes **unidades de execução** de um processo 
As threads compartilham o código e variáveis globais do processo 
**Multithreading** é um modelo de programação com importância crescente, devido à demanda por aplicações com melhor desempenho e uso apropriado das arquiteturas multicore

#### Memória Virtual
Abstração que dá a cada processo a ilusão de que ele possui uso exclusivo da memória principal 
Todo processo tem a mesma visão da memória principal, chamada espaço de endereçamento virtual 
O espaço de endereçamento virtual é dividido em áreas de propósito específico: 
1. Código e dados: carregados diretamente a partir do conteúdo do arquivo objeto executável
2. Heap: espaço de dados criado dinamicamente (ex., malloc free)
3. Bibliotecas compartilhadas: código e dados para bibliotecas compartilhadas
4. Pilha: uso especial para implementar chamadas de funções (cresce e diminui dinamicamente)
5. Memória virtual do kernel: o kernel é a parte do SO que fica sempre residente na memória em área que as aplicações não podem ler escrever executar diretamente
##### Funcionamento
Para que a abstração de memória virtual funcione, é preciso um esquema sofisticado de interação entre o hardware e o SO 
Páginas da memória virtual são mapeadas em páginas da memória física
	Requer tradução pelo hardware de todo endereço de memória gerado pelo processador 
A idéia básica consiste em armazenar o conteúdo da memória virtual no disco e usar a memória principal como cache para o disco
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
O paralelismo pode ser explorado em diferentes níveis de abstracão:
- Threads
Vários fluxos de controle dentro do mesmo processo 
Os sistemas de computador podem ser: uniprocessador (um único processador sob o controle do SO) ou multiprocessador (vários processadores sob o controle do mesmo SO) 
Os sistemas multiprocessador têm se tornado mais comuns com o advento das tecnologias multicore e hyperthreading
Hyperthreading (ou multithreading simultâneo)
	Técnica que permite uma única CPU executar vários fluxos de controle de um mesmo processo 
	Requer várias cópias de um mesmo hardware (como PC e registradores), enquanto outras partes são compartilhadas (ex., unidade de aritmética de ponto flutuante)
	Requer bem menos ciclos de relógio (clock) para chavear entre threads
	
- Instrucão 
No passado, vários ciclos de relógio por instrução
Hoje, em processadores superescalares, várias instruções por ciclo de clock, com uso de pipelining
Pipelining 
	As ações requeridas para executar uma instrução são divididas em diferentes passos e o hardware do processador é organizado como uma série de estágios, cada um executando um desses passos 
	Hardware pode executar mais de uma instrução simultaneamente, mas com comportamento equivalente ao sequencial
- SIMD (Single-Instruction, Multiple-Data)
No nível mais baixo, os processadores modernos possuem hardware especial que permite uma única instrução disparar várias operações para serem executadas em paralelo (ex., instruções Intel e AMD que permitem somar mais de um par de números fracionários em paralelo) 
Maior eficiência para aplicações envolvendo processamento vetorial e matrizes
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
O tamanho da palavra em um computador indica o tamanho nominal de um número inteiro ou de um ponteiro de dado 
Como um endereço virtual é codificado em uma palavra, então o tamanho máximo do espaço de endereçamento virtual para uma máquina com palavra de w bits é $2^w$ (endereços indo de 0 a $(2^w - 1)$) Ex: palavra = 32 bits, 232 bytes endereçáveis (4GBytes)
Os computadores e compiladores suportam vários formatos de dados, usando diferentes formas de codificação (ex., inteiros, ponto-flutuante) e diferentes tamanhos (ex., 2, 4, 8 bytes)

#### Endereçamento de um objeto
Na quase totalidade das máquinas, um objeto com vários bytes é armazenado em uma sequência contígua de bytes 
Dado pelo menor dos endereços dos bytes do objeto 
Seja x uma variável inteira, se &x = 0x100 (endereço de x), os quatro bytes de x são armazenados nos bytes: 0x100, 0x101, 0x102, 0x103

#### Ordenação dos Bytes na memória
![[ordenacao_byte_memoria.png]]![[big_little_endian.png]]
## # Representação e armazenamento no computador (Aula 5)
### Operações com bits
![[op_bits.png]]Um uso comum das operações com bits é na implementação de **máscaras** 
Uma **máscara** é um **padrão de bits** que indica um conjunto selecionado de bits dentro de uma palavra

- AND (`&`): "E" $0\&1 = 0$, $1\&1=1$
- OR (`|`): "OU" $0|1=1$, $1|1=1$
- NOT (`~`) "NEGAÇÂO" $\sim0=1$, $\sim1=0$
- XOR (`^`) "COMPARAÇÂO" $0\wedge1=1$, $1\wedge1=0$
### Operações Lógicas
- $|| \rightarrow$ OR lógico 
- $\&\& \rightarrow$ AND lógico
- $!\rightarrow$ Complemento Lógico
As operações lógicas tratam qualquer argumento diferente de ZERO como TRUE e o argumento ZERO como FALSE 
Elas retornam 0x00 ou 0x01 apenas, indicando resultado FALSE ou TRUE, respectivamente

### Operações de Deslocamento de bits em C
#### Deslocamento à direita
A expressão $x\gg K$ desloca K bits a direita
Em geral, as máquinas suportam duas formas de deslocamento à direita: **lógico** e **aritmético**
No deslocamento à direita **lógico**, zeros são inseridos ao se deslocar
	ex., $10101111 \gg 4 = 00001010$
No deslocamento à direita **aritmético**, o MSB (bit $X_n-1$) é copiado a cada deslocamento (<font color="#c00000">equivale a dividir por $2^K$, preservando o sinal do número</font>)
	ex., $10101111 \gg 4 = 11111010$ 
	$(-81/ 16 = -5 - 1/ 16 = -6)$ (arredondando)

### Representação de Inteiros em C
#### Inteiros Positivos
A linguagem C define vários tipos de números inteiros com tamanhos variados: **char, short int, int, long int, long long int** 
Além do tamanho, é possível indicar se o número é sempre positivo (unsigned) ou positivo/negativo (o default)
#### Inteiros Negativos
A representação mais comum para números negativos é complemento a 2 (C2)
	O bit mais significativo da palavra tem peso negativo 
		ex: $0001 = -0 * 2^3 + 0 * 2^2 + 0 * 2^1 + 1 * 2^0 = 1$
		$0110 = -0* 2^3 + 1* 2^2 + 1*2^1 + 0 * 2^0 = 6$ 
		$1010 = -1 * 2^3 + 0 * 2^2 + 1*2^1 + 0 * 2^0 = -6$
		$1111 = -1*2^3 + 1* 2^2 + 1 * 2^1 + 1 * 2^0 = -1$
	Observe que para qualquer valor inteiro x em C2 
		$\sim x$ (complementação bit a bit) é equivalente a -x - 1

### Ponto Flutuante
Representa números reais racionais na forma $V = x.2^Y$ 
Útil para representar números muito grandes (|V| $\gg$ 0), usando números normalizados, ou muito próximos de zero (|V| $\ll$ 1), usando números não normalizados 
Funciona como uma aproximação para a aritmética real

#### Número Binários Fracionários
![[frac_bin.png]]![[frac_bin2.png]]
#### Ponto Flutuando do IEEE
![[float_ieee.png]]
#### Precisão Simples IEEE
##### Normalizado
![[precisao_simples_ieee.png]]
##### Não normalizado, Infinito e Não é um Número (NaN)
![[precisao_simples_ieee_nan.png]]
#### Precisão Dupla IEEE
![[precisao_dupla_ieee.png]]
## Aula 6 - Representação de programas em linguagem de montagem
### Programas em linguagem de montagem 

### Perspectiva histórica das arquiteturas Intel 

### Codificação de programas 

### Características da arquitetura x86
