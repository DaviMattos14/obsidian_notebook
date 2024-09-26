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