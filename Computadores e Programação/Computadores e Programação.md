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

