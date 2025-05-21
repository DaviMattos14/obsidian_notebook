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
#### <span style="background:#fff88f">Decimal</span> $\rightarrow$ <span style="background:#fff88f">Binário</span>

![[dec_bin.png]]
####  <span style="background:#fff88f">Decimal</span> $\rightarrow$ <span style="background:#fff88f">Hexadecimal</span>
![[dec_hex.png]]
#### Binário $\rightarrow$ Decimal
![[bin_dec1.png]]
![[bin_dec2.png]]
#### Hexadecimal $\rightarrow$ Decimal
![[hex_dec1.png]]![[hex_dec2.png]]
#### <span style="background:#fff88f">Binário, Hexadecimal</span> $\rightarrow$ <span style="background:#fff88f">Binário</span>
![[oct_bin.png]]![[hex_bin.png]]
#### <span style="background:#fff88f">Binário</span> $\rightarrow$ <span style="background:#fff88f">Octal, Hexadecimal</span>
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
Ler código em linguagem de montagem gerado por um compilador envolve um **conjunto de habilidades distintas daquelas necessárias para escrever código** diretamente: 
	é preciso compreender as transformações usadas pelos compiladores para converter construções da linguagem de alto nível em código de máquina 
Técnicas de **otimização** usadas pelos compiladores podem rearranjar a ordem de execução do programa: 
	eliminando computações desnecessárias, substituindo operações lentas, ou mesmo convertendo computações recursivas por sequências iterativas
### Perspectiva histórica das arquiteturas Intel 

### Codificação de programas 
Dados dois programas, pl.c e p2.c, eles podem ser compilados fazendo: 
```c
gcc -m32 -01 -o p p1. C p2. C 
```
A opção `-O1` diz ao compilador para usar o **nível 1** de otimização

O sistema de compilação transforma programas expressos no modelo de execução da linguagem de alto nível em instruções elementares que o processador executa 

A habilidade de entender o código de montagem e sua relação com o código fonte é um passo essencial para compreender como os computadores executam os programas

- As instruções IA32 podem ter de 1 a 15 bytes de tamanho 
- As instruções são codificadas de tal forma que as operações mais comuns requerem um número menor de bytes comparado às demais 
- O formato das instruções é projetado de tal forma que a partir de uma posição inicial há uma única codificação dos bytes em instrução de máquina 

O disassembler determina o código em linguagem de montagem com base apenas na sequência de bytes do código de máquina e na arquitetura para a qual ele foi gerado (não depende da linguagem fonte do programa original)
#### ATT versus Intel 
- O código de montagem IA32 pode ser mostrado em diferentes formatos 
- O formato ATT é o formato padrão das ferramentas gcc e objdump (e será usado ao longo do curso) 
- O formato Intel é usado por outras ferramentas (ex., Microsoft), incluindo a própria documentação Intel 
- Há várias diferenças entre os dois formatos 
- Fazendo `gcc -01 -S -masm=intel ex11.c` forçamos o uso do formato Intel 
### Características da arquitetura x86
#### Nomeclatura
![[nomeclatura.png]]
#### Sufixos nas Instruções de Montagem Formato ATT

![[assembly_sufix.png]]
Tem que casar com o tamanho do operando destino
![[sufixo_montagem.png]]

Sufixos para instruções de ponto flutuante
![[sufixo_float.png]]

#### Registradores de propósito geral do 80386
![[registradores.png]]

Tinham finalidade específica nas arquiteturas anteriores de 16 bits (razão dos nomes), mas, com o endereçamento linear (flat addressing) de 4GB, o uso específico é enormemente reduzido e os **seis primeiros** podem ser considerados de uso geral, ainda que algumas instruções usem registradores fixos como fonte e destino 

- **EAX** - Acumulador, usado em operações aritméticas. 
- **ECX** - Contador, usado em loops. 
- **EDX** - Registrador de dados, usado em operações de entrada/saída e em multiplicações e divisões. É também uma extensão do Acumulador. 
- **EBX** - Base, usado para apontar para dados no segmento DS (8086). 
- **ESI** - Índice da fonte de dados a copiar (Source Index). Aponta para dados a serem copiados para DS:EDI (segmento DS, posição EDI). 
- **EDI** - Indice do destino de dados a copiar (Destination Index). Aponta para o destino dos dados a serem copiados de DS: ESI. 
- **ESP** - Apontador da Pilha (Stack Pointer). Aponta para o topo da pilha (endereço mais baixo dos elementos da pilha). 
- **EBP** - Apontador da base do frame (registro de ativação). Acesso a argumentos de procedimentos passados pela pilha.

#### Registrador de Flags
Armazena códigos de condições setadas por operacões lógicas e aritméticas, que podem ser testados por instruções específicas 
x86 não suporta acesso direto ao registrador das flags 
Para modificar ou ler o eflags 
	Necessário utilizar as instruções privilegiadas pushf (16 bits) ou pushaf (32 bits)

#### Registradores de Segmentos
- CS - Segmento do Código 
- DS - Segmento de Dados 
- ES - Segmento com dados extra 
- FS - Segmento com mais dados 
- GS - Segmento com ainda mais dados 
- SS - Segmento da Pilha (Stack)

#### Registradores para Operações de Ponto Flutuante 
Para operações de ponto flutuante existe uma pilha especial em hardware (FPU stack) com 8 registradores, referenciados de ST(0) a ST(7), sendo ST(0) o topo da pilha 
Os registradores possuem 80 bits, suportando operações de 
- precisão simples (32 bits, sufixo s) 
- precisão dupla (64 bits, sufixo l) 
- precisão dupla estendida (80 bits, sufixo t) 
As operações sobre a pilha FPU podem ser 
- unárias, sobre ST (0) 
- binárias, com ST (0) e ST0); ou ST(0) e operando em memória

## Aula 7 - Formatos de operandos e instruções de movimentação de dados IA32
### Operandos das Instruções IA32
#### Valores de Entrada
- constantes, 
- conteúdo de um registrador, ou o conteúdo armazenado na memória 
#### Localizações de destino 
- registradores ou 
- na memória
### Formatos de operandos
1. Imediato
	Constantes numéricas no formato ATT são escritas com $ seguido de um valor numérico (decimal ou hexadecimal) 
	- `movl $-20, %eax` :armazena -20 no registrador %eax 
	- `movl $0x2F, %ebx` :armazena 0x2F no registador %ebx
	Qualquer valor que possa ser representado em 32 bits pode ser usado como constante numérica
2. Registrador
	Registrador Denota o conteúdo de um dos registradores, ex.: 
	- `movb $10, %ah_`
	- `movw $10, %ax` 
	- `movl $10, %eax` 
	Veja que o sufixo das instruções e o tamanho do destino (1 byte, 2 bytes ou 4 bytes) têm que ser compatíveis
3. Memória
	Formato mais geral de referenciar memória: $I(E_b, E_i, s)$ 
		Endereço de memória $= I + R[E_b] + R[E_i] * s$ 
		- $I =$ deslocamento do tipo imediato (mas sem o $) 
		- $R[E_b]$ representa o valor armazenado no registrador base $E_b$ 
		- $R[E_i]$ representa o valor armazenado no registrador de índice $E_i$ 
		- $s$ é o fator de escala (1, 2, 4 ou 8), relacionado ao tamanho do tipo dos objetos da estrutura
	![[acesso_mem.png]]
	Todos os outros formatos são simplificações desse formato geral (com ausência de um ou mais elementos) 
	O formato completo é usual para referenciar elementos de vetores ou estruturas de dados

Exemplo:
$$
\begin{matrix}
260(\%\text{ecx},\%\text{edx})= && 0\text{x}104+0\text{x}1+0\text{x}3 = 0\text{x}108 = 0\text{x}13\\ 
260_{10}=104_{16} && 
\end{matrix}
$$

### Modos de endereçamento
- Absoluto: $\text{movl  } 17, \%\text{eax}$ 
	- $R[\%\text{eax}] = \text{Mem } [17]$ (endereço absoluto 17 referenciado) 
- Imediato: $\text{movl } \$17, \%\text{eax}$
	- $R\%\text{eax} = 17$ (valor inteiro constante)
- Indireto: $\text{movl } (\%\text{ecx}), \%\text{eax}$ 
	- $R[\%\text{eax}] = \text{Mem }[R[\%\text{ecx}]]$ (conteúdo de %ecx é o endereço de memória onde está o valor a ser armazenado em %eax) 
- Deslocamento: $\text{movl }8(\%\text{ebp}), \%\text{edx}$ 
	- Operando = $\text{Mem}[R[E_s] + I] = \text{Mem}[R[\%\text{еbp}]+8]$
- Indexado: $\text{movl }16(\%\text{ecx}, \%\text{eax},4), \%\text{edx}$
	- Operando = $\text{Mem}[R[E_b] + s * R[E_i] + I] = \text{Mem}[R[\%\text{еcx}]+R[\%\text{еax}]*4+16]$

### Instruções de Movimentação de Dados
![[mov_data.png]]
Instruções que copiam dados de uma localização para outra (ex., de um registrador para uma posição de memória)
A generalidade dos formatos de operandos permite que uma mesma instrução básica execute diferentes tipos de movimentações de dados
$$
\begin{matrix} 
\text{S = source (fonte)} && \text{D = destination (destino)}
\end{matrix}
$$
<font color="#c00000">Copiar um valor de um lugar para outro requer duas instruções, a primeira para carregar o valor na fonte no registrador, e a segunda para gravar esse valor do registrador no destino de mesmo tipo </font>
#### Movimentação básica
- **movb S,D**: S→D (move um byte) 
	- Qualquer registrador de bit único (`%ah - %bh` , `%al - %bl`))
- **movw S,D**: S→D (move uma palavra de 16 bits $\rightarrow$ 2 Bytes)
	- Qualquer registrador de 16bits (`%ax - %bp`)
- **movl S,D**: S→D (move uma palavra dupla de 32 bits $\rightarrow$ 5 Bytes) 
	- - Qualquer registrador de 32bits (`%eax - %ebp`)
- Destino D tem que ser compatível com o sufixo da instrução!
#### Movimentação com extensão do sinal 
- **movsbw S,D**: sinalEstendido(S)→D (de byte para palavra) 
- **movsbl S,D**: sinalEstendido(S)→D (de byte para palavra dupla)
- **movswl S,D**: sinalEstendido(S) →D (de palavra para palavra dupla) 
Bit de sinal repetido nos bits à esquerda, fazendo com que o valor da representação em C2 se mantenha
#### Movimentação com extensão de 0s 
- **movzbw S,D**: zeroEstendido(S)D (de byte para palavra) 
- **movzbl S,D**: zeroEstendido(S)→D (de byte para palavra dupla) 
- **movzwl S,D**: zeroEstendido(S)→D (de palavra para palavra dupla) 
Completa os bits à esquerda com 0
#### Operando das instruções
O operando fonte (S) designa um valor imediato (antecedido de $), ou armazenado em um registrador ou em memória 
O operando destino (D) designa uma localização que é um registrador ou uma posição de memória 

<font color="#c00000">Restrição com mov</font>: Uma posição de memória não pode ser copiada diretamente para outra posição de memória 
	Precisa-se copiar da memória para um registrador e depois do registrador para a memória
#### Pilha
##### Operações de 32bit
- **pushl S**: abre 4 posições na pilha, fazendo %esp$\leftarrow$%esp-4, e atualiza o novo topo com o valor S (4 bytes) (M$[\%\text{esp}]\leftarrow$S) 
- **popl D**: copia 4 bytes do topo para D (D$\leftarrow$M\[%esp\]) e decrementa topo, liberando 4 bytes (%esp$\leftarrow$%esp+4)

##### Equivalências
$$
\text{pushl \%ebp} \equiv \begin{cases}
\text{subl \$4, \%esp} \\
\text{movl \%ebp, (\%esp)}
\end{cases}
$$
$$
\text{popl \%ebp} \equiv \begin{cases}
\text{movl (\%esp), \%ebp} \\
\text{addl  \$4, \%esp}
\end{cases}
$$
Segue regra LIFO (Last-in, first-out) ou "último a entrar, primeiro a sair"

![[funcionamento_pilha.png]]

### Variáveis e Ponteiros
Ponteiros em C são endereços no código de montagem. 
Desreferenciar (dereferencing) um ponteiro (pegar o valor apontado por ele envolve carregá-lo num registrador e usar esse registrador para referenciar um endereço de memória. 
Variável local, como **x**, pode ser mantida em registrador (ao invés da memória), para acesso mais rápido.
## Aula 8 - Operações lógicas e aritméticas IA32
### Operações aritméticas com inteiros
![[aritmetica_logica_op.png]]
As operações lógicas e aritméticas são divididas em quatro grupos: 
- <u>Operações unárias</u>: um único operando é fonte e destino da operação 
	O operador D pode ser memória ou registrador: 
		• `inc D`: D+1→D (incremento de 1) 
		• `dec D`: D-1→D (decremento de 1) 
		• `neg D`: -D→D (negativo do número) 
		• `not D`: ~D→D (complemento do número bit a bit)
	Exemplo: `incl (%esp)` $\rightarrow$ incrementa o inteiro no topo da pilha
- <u>Operações binárias</u>: o segundo operando é usado como fonte e destino da operação 
	O operando S pode ser: imediato, registrador ou memória. 
	O operando D pode ser: registrador ou memória 
		• `add S, D`: D + S→D (adição) 
		• `sub S, D`: D - S→D (subtração) 
		• `imul S, D`: D * S→D (multiplicação, resultado em 32 bits) 
		• `xor S, D`: D^S→D ("ou-exclusivo" lógico bit a bit) 
		• `or S, D`: D | S→D ("ou" lógico bit a bit) 
		• `and S, D`: D & S→D ("e" lógico bit a bit) 
	Exemplo:  subl %eax, %edx [(%edx - %eax) → %edx] 
	![[op_aritimetica.png]]
	Não pode somar/subtrair memória com memória: addl (%eax), (%esp) - não é válido!
- <u>Operações de deslocamento</u>: à esquerda ou à direita, lógico ou aritmético 
	Nas operações de deslocamento de bits, a quantidade de bits deslocados é passada no primeiro argumento 
	-  `sal k, D`: D < k→D (deslocamento aritmético à esquerda) 
	-  `shi k, D`: D < k→D (deslocamento lógico à esquerda = sal) 
	-  `sar k, D`: D > k→D (deslocamento aritmético à direita) 
	-  `shr k, D`: D > k→D (deslocamento lógico à direita)
- <u>Operação de endereço efetivo de carga</u>: copia um endereço de memória para um registrador
	![[op_end.png]]• A instrução leal pode ser usada também para descrever operações aritméticas de forma compacta: ex., leal 7(%edx, %edx, 4), %eax (assumindo %edx = x, temos %eax = 5x + 7)
	
## Aula 9 - Controle do fluxo de execução e instruções condicionais
### Operações Aritméticas Especiais
![[op_aritmetica_espciais.png]]

| Instrução | Efeito                                      | Descrição                          |
| --------- | ------------------------------------------- | ---------------------------------- |
| `imull S` | %edx:%eax $\leftarrow$ S x %eax             | Mult. completa (64 bits) com sinal |
| `mull S`  | %edx:%eax $\leftarrow$ S x %eax             | Mult. completa (64 bits) sem sinal |
| `cltd`    | %edx:%eax $\leftarrow$ estende sinal(%eax)  | Estende 32 bits para 64 bits       |
| `idivl S` | %edx $\leftarrow$ %edx:%eax mod S (resto)   | Divisão com sinal                  |
|           | %eax $\leftarrow$ %edx:%eax ÷ S (quociente) |                                    |
| `divl S`  | %edx $\leftarrow$ %edx:%eax mod S (resto)   | Divisão sem sinal                  |
|           | %eax $\leftarrow$ %edx:%eax ÷ S (quociente) |                                    |
### Registradores de códigos de condição
A CPU mantém registradores de código de condição, setados bit-a-bit, que armazenam atributos das últimas operações lógicas e aritméticas executadas
Códigos de condição são setados como <font color="#c00000">efeito colateral de uma instrução</font> 
### Construções Condicionais
Construções condicionais (ex., while, for, if-else) requerem o teste de alguma condição relativa ao valor de variáveis do programa e podem causar um desvio na sequência de instruções 
- Desvios incondicionais 
São programados com a instrução jmp, desviando a execução para outra parte do programa 
- Desvios condicionais 
São baseados em códigos de condição (ou flags) setados nos registradores de códigos de condição
### Códigos de condição
Os códigos de condição mais comuns são: 
1. **CF** (Carry Flag): a última operação gerou um bit extra, usado para detectar overflow (estouro) em operações sem sinal 
2. **ZF** (Zero Flag): o resultado da última operação foi zero 
3. **SF** (Sign Flag): o resultado da última operação foi negativo 
4. **OF** (Overflow Flag): a última operação causou um overfow de operação com sinal
Obs:
A instrução leal não altera nenhum dos códigos de condição (já que seu uso é para cálculo de endereços de memória) 
Nas operações de deslocamento, CF é setado com o último bit deslocado para fora e OF é setado em zero
Nas operações lógicas, CF e OF são setados em zero 
<font color="#c00000">Atenção</font>: instruções add e dec setam OF e ZF, mas deixam CF inalterado.
### Overflow
Nunca pode acontecer overflow quando somamos dois números de sinais opostos 
Quando a soma de dois números do mesmo sinal dá um resultado de sinal oposto ocorre overflow 
Overflow também ocorre quando trocamos de sinal o menor negativo inteiro, pois a magnitude resultante não tem representação inteira positiva em complemento a dois
### Classe de instruções TEST e CMP
![[cod_condicao.png]]
![[test_cmp.png]]
### Instruções SET
![[instrucoes_set.png]]
![[set.png]]
### Instruções de Desvio (JUMP)
Uma instrução de desvio pode fazer a execução desviar para uma nova posição do programa (rompendo a ordem sequencial de instruções listadas) 
O endereço da instrução de destino (próxima instrução a ser executada) é normalmente indicado por um label 
Ao gerar o código objeto, o montador determina os endereços dos labels e decodifica os endereços alvos das instruções de desvio
![[jump.png]]
### Instrução jmp
![[instrucao_jmp.png]]
A instrução jmp desvia incondicionalmente 
Tipo de desvio 
- Direto (via label), codificado como parte da instrução (ex., jmp FIM) 
- Indireto (via registrador ou posição de memória), codificado com auxílio do operador "\*" 
	- jmp \* %eax - usa o conteúdo do registrador como endereço de desvio  
	- jmp \* (%eax) - usa o conteúdo da memória endereçada pelo registrador como endereço de desvio 
As demais instruções de desvio são condicionais e podem usar apenas destino direto (via label)
• je (ou jz): ZF (igual/zero) 
• jne (ou jnz): ~ZF (diferente/não-zero) 
• js: SF (negativo) 
• jns: ~SF (não negativo) 
• jg (ou jnle): ~(SF^OF) & ~ZF (maior com sinal)ª 
• jge (ou jnl): ~(SF^ OF) (maior ou igual com sinal) 
• jl (ou jnge): SF^OF (menor com sinal) 
• jle (ou jng): (SF^OF) | ZF (menor ou igual com sinal) 
	ª^ é a operação ou-exclusivo (XOR)
• ja (ou jnbe): ~CF & ~ZF (acima sem sinal ) 
• jae (ou jnb): ~CF (acima ou igual sem sinal) 
• jb (ou jnae): CF (abaixo sem sinal) 
• jbe (ou jna): CF | ZF (abaixo ou igual sem sinal ) 

Estas instruções operam sobre tipos UNSIGNED
### Codificação de Labels
**Relativo ao PC**: codifica a diferença entre o endereço da instrução alvo e o endereço da instrução imediatamente após o JUMP (requer 1, 2 ou 4 bytes) 
**Absoluto**: codifica o endereço alvo diretamente (requer 4 bytes)
![[cod_montagem.png]]
## Aula 10 - Tradução de expressões condicionais e repetições para linguagem de montagem
### IF-Else
![[if_else1.png]]
![[if_else.png]]
### Do-While
![[do_while1.png]]
![[do_while.png]]
### While
![[while1.png]]
![[while.png]]
### For
![[for1.png]]
![[for.png]]
### CMOV
Copia um valor para um registrador, dependendo de valores dos códigos de condição
![[cmov.png]]
### Switch Case
#### Switch em C
```C
int switch_eg(int x, int n) {
	int result = x;
	switch (n){
	case 100:
		result *= 13;
		break
	case 102:
		result += 11; 
		break;
	case 104:
	case 106:
		result *= result;
		break;
	default:
		result = 0;
	}
	return result;
}
```
#### Switch em assembly
![[switch.png]]