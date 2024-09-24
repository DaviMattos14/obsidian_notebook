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