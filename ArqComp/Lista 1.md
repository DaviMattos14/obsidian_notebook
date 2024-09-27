1) Descreva as funções de uma UCP.
- Executar os programas armazenados na memória principal, buscando suas instruções, examinando as, e então executando uma após a outra.
- Busca de instruções e dados na memória.
- Programa a transferência de dados entre a memória e os dispositivos de entrada/saída.
- Decodifica as instruções.
- Realiza as operações lógica e aritméticas.
- Responde a sinais enviados por dispositivos de entrada/saída como RESET ou interrupções.

2) Indique os dois atributos da memória e quais são as operações que a UCP pode solicitar.
- Mémória: Primária e Secundária, Volátil e não volátil
- Operações da UCP: Aritmética e Lógica

3) Para que servem os dispositivos de entrada e saída de um computador? Cite alguns exemplos.
- Os dispositivos de entrada e saída (E/S) permitem a comunicação entre o usuário e o computador, bem como entre o computador e outros dispositivos. Exemplos de dispositivos de entrada incluem teclado e mouse, enquanto dispositivos de saída incluem monitores e impressoras. Dispositivos como discos rígidos e pen drives podem funcionar como entrada e saída.

4) Formalize o conceito de bit, byte e palavra.
- **Bit**: A menor unidade de informação em um computador, que pode representar dois estados (0 ou 1).
- **Byte**: Conjunto de 8 bits. É a unidade básica de armazenamento usada para representar um caractere, como uma letra ou número.
- **Palavra**: Conjunto de bits que o processador manipula como uma unidade única. O tamanho da palavra varia conforme a arquitetura do sistema, podendo ser, por exemplo, 16, 32 ou 64 bits.

5) Qual é a diferença entre linguagem de alto nível e linguagem de máquina?:
- **Linguagem de Alto Nível**: Linguagens como Python, C ou Java, que são mais fáceis para humanos entenderem, utilizando sintaxes semelhantes a palavras e frases do cotidiano.
- **Linguagem de Máquina**: Conjunto de instruções em formato binário que o processador entende diretamente. Estas instruções são mais difíceis para os humanos escreverem e interpretarem, mas são necessárias para a execução direta no hardware.
 
6) Considere um sistema de computador que possua u processador capaz de endereçar, no máximo, 32 M endereços de memória principal. Qual deverá ser o tamanho, em bits, do barramento de endereços?

$\text{Número de endereços} = 2^{n}$
Onde:
- $n$ é o número de bits do barramento de endereços;
- O número de endereços é 32M, que significa \( $32 \times 10^6$ \) endereços.
Primeiro, transformamos \( $32M$ \) em potência de 2:
$$32M = 32 \times 2^{20} = 2^5 \times 2^{20} = 2^{25}$$
Agora, igualamos:
$$2^{n} = 2^{25}$$
Logo:
$$n = 25
$$
Portanto, o tamanho do barramento de endereços deverá ser **25 bits**.

7) Um computador, cuja memória RAM (MP) tem uma capacidade máxima de armazenamento de 2K palavras de 16 bits cada, possui um REM e um RDM. Qual é o tamanho desses registradores? Qual é o valor do maior endereço dessa MP e qual é a quantidade total de bits que nela podem ser armazenados?
**Tamanho do REM (Registrador de Endereços de Memória): O REM** armazena o endereço de uma palavra na memória. A memória tem 2K palavras, onde $K=1024$, então:
$$2K = 2 \times 1024 = 2048 \text{ palavras}$$
Para endereçar 2048 palavras, o número de bits necessários no REM é dado por $2^n = 2048$, onde $n$ é o número de bits:

$$2^{11} = 2048$$
Logo, o **REM deve ter 11 bits** para endereçar todas as palavras da memória.
**Tamanho do RDM (Registrador de Dados de Memória)**: O **RDM** armazena os dados de uma palavra. Cada palavra na memória tem 16 bits, então o **RDM deve ter 16 bits**, já que ele precisa ser capaz de armazenar uma palavra inteira.
**Valor do maior endereço da MP**: O maior endereço possível é o último endereço da memória, que é o endereço 204720472047 (em decimal), pois os endereços começam do 0. Portanto, o valor do maior endereço é **2047**.    
**Quantidade total de bits que podem ser armazenados na memória**: A memória tem 2048 palavras, e cada palavra tem 16 bits. Assim, a quantidade total de bits que podem ser armazenados é:
$$2048 \times 16 = 32768 \text{ bits} = 32K \text{ bits}$$
8) Um processador possui RDM com capacidade de armazenar 32 bits e um REM com capacidade de armazenar 24 bits. Sabendo-se que em cada acesso são lidas duas células da memória RAM (MP) e que o barramento de dados em tamanho igual ao da palavra, pergunta-se:
- a) Qual é a capacidade máxima de endereçamento do microcomputador em questão?
A capacidade máxima de endereçamento depende do número de bits do **REM** (Registrador de Endereços de Memória). O REM tem 24 bits, então o número total de endereços que o microcomputador pode acessar é:
$$2^{24} = 16.777.216 \text{ endereços}$$
Portanto, o microcomputador pode endereçar **16.777.216 (ou 16M) endereços**.
- b) Qual é o total máximo de bits que podem ser armazenados na memória RAM?
Sabemos que em cada acesso à memória são lidas **duas células**. Como o **RDM** (Registrador de Dados de Memória) tem 32 bits, cada palavra tem 32 bits. Isso significa que cada célula armazena metade de uma palavra, ou seja, **16 bits** por célula.

Assim, a memória tem $2^{24}$ endereços, e cada endereço (ou célula) armazena 16 bits. O total de bits que podem ser armazenados na memória RAM é:
$$16 \times 2^{24} = 16 \times 16.777.216 = 268.435.456 \text{ bits}$$
Portanto, o total máximo de bits que podem ser armazenados na memória RAM é **268.435.456 bits** ou **256 Megabits (Mb)**.
- c) Qual é o tamanho da palavra e de cada célula da máquina?
O tamanho da **palavra** é igual à capacidade do **RDM**, ou seja, **32 bits**.
O tamanho de cada **célula** é metade de uma palavra, já que o enunciado menciona que em cada acesso são lidas duas células. Portanto, o tamanho de cada célula é **16 bits**.

9) Um processador possui um barramento de endereços com capacidade de permitir a transferência de 33 bits de cada vez. Sabe-se que o barramento de dados permite a transferência de 4 palavras em cada acesso e que cada célula da memória RAM armazena 1/8 de cada palavra. Considerando que a memória RAM pode armazenar um máximo de 64 Gbits, pergunta-se:
a) Qual é a quantidade máxima de células que podem ser armazenadas na memória RAM?
**Tamanho total da memória (em bits):** 64 Gbits = $64 \times 10^9$ bits.
**Tamanho de cada célula (em bits):** Cada célula armazena 1/8 de uma palavra, ou seja, o tamanho de uma palavra é 8 vezes o tamanho de uma célula.

Se $\text{memória total} = 64 \times 10^9$ , e uma célula armazena $\frac{1}{8}$ de uma palavra, a quantidade máxima de $\text{Q}_{\text{células}}$  é simplesmente o número de bits que podem ser armazenados (64 bilhões de bits), já que estamos falando de bits individuais:

$$\text{Q}_{\text{células}} = 64 \times 10^9 \, \text{bits}
$$
Então, **a quantidade máxima de células é 64 bilhões de células**.

b) Qual é o tamanho do REM e do barramento de dados existentes neste computador?
Com um barramento de 33 bits, o número máximo de endereços que podem ser representados é: 
$$2^{33} = 8.589.934.592 \, \text{endereços}.$$

No entanto, como a memória só tem 64 bilhões de células (ou $6,4 \times 10^{10}$ bits), o número de bits no REM corresponde ao que pode ser endereçado pelo barramento de 33 bits.

Sabemos que o barramento de dados transfere 4 palavras em cada acesso. Se considerarmos que cada palavra tem 8 bits, isso significa que o barramento de dados tem que ser capaz de transferir 32 bits por vez (4 palavras × 8 bits por palavra = 32 bits).

c) Qual é o tamanho de cada célula e da palavra desta máquina?
Tamanho da célula: **1 bit**, tamanho da palavra: **8 bits**.

10) Um computador possui um RDM com 16 bits de tamanho e um REM com capacidade para armazenar números com 2º bits. Sabe-se que a célula deste computador armazena dados com 8 bits de tamanho e que ele possui uma quantidade N de células, igual à sua capacidade máxima de armazenamento. Pergunta-se:
a) Qual é o tamanho do barramento de endereços?
Um barramento de endereços com 20 bits pode endereçar 2^{20} posições de memória, pois o número de endereços possíveis é dado por $2^n$, onde $n$ é o número de bits no barramento de endereços.

$$2^{20} = 1.048.576 \, \text{células}.$$

b) Quantas células de memória são lidas em uma única operação de leitura?
Como o RDM é o registrador responsável por conter os dados transferidos do barramento de dados, ele precisa ser capaz de armazenar os dados de uma operação de leitura. Se o RDM tem 16 bits e cada célula tem 8 bits, então em uma única operação de leitura, o RDM consegue ler:

$$\frac{16 \, \text{bits (RDM)}}{8 \, \text{bits por célula}} = 2 \, \text{células}.$$

c) Quantos bits tem a MP?
Para calcular o número total de bits da memória principal (MP), basta multiplicar a quantidade total de células pelo número de bits armazenados em cada célula:

$$\text{MP} = 2^{20} \, \text{células} \times 2^{3} \, \text{bits por célula} = 2^{23} \, \text{bits}.$$
11) Um microcomputador possui uma capacidade máxima de MP com 32 K células, cada uma capaz de armazenar uma palavra de 8 bits. Pergunta-se:
a) Qual é o maior endereço, em decimal , desta memória?
Sabemos que a memória principal (MP) possui **32 K células**. O número "K" representa **1024** ou $2^{10}$, logo o número total de células é:
$$32 \times 1024 = 2^5 \times 2^{10} = 2^{15} =32.768 \, \text{células}.$$
O **maior endereço** de uma memória é sempre igual ao número total de células menos 1 (porque o endereçamento começa do zero). Portanto, o maior endereço, em decimal, é:
$$32.768 - 1 = 32.767.$$
Portanto, **o maior endereço desta memória, em decimal, é 32.767**.

b) Qual é o tamanho do barramento de endereços deste sistema?
O barramento de endereços precisa ser capaz de endereçar todas as **32.768 células** de memória. O tamanho do barramento de endereços em bits é determinado pelo número de endereços que ele pode gerar, que é dado por $2^n$, onde n é o número de bits no barramento.
Sabemos que:
$$2^{15} = 32.768.$$
Portanto, o **barramento de endereços tem 15 bits**
c) Quantos bits podem ser armazenados no RDM e no REM?
**RDM (Registrador de Dados de Memória):** O RDM armazena uma **palavra** de dados. Como cada célula da memória armazena uma palavra de **8 bits**, o RDM deve ser capaz de armazenar **8 bits**.

d) Qual é o total máximo de bits que pode existir nesta memória?
Para determinar o total máximo de bits que a memória pode armazenar, basta multiplicar o número total de células pela quantidade de bits que cada célula pode armazenar.

Sabemos que a memória tem **32.768 células**, e cada célula armazena **8 bits**. Logo, o total máximo de bits é:

$$32.768 \, \text{células} \times 8 \, \text{bits por célula} = 2^{15}\times 2^3 = 2^{17} = 262.144 \, \text{bits}.$$
Como $\text{Kbits} = 2^{10}$, logo, $2^7$ Kbits = 256 Kbits 