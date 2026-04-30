Sumário Executivo

Este documento sintetiza os princípios fundamentais dos bancos de dados NoSQL e a emergência das arquiteturas de persistência poliglota. Historicamente, os bancos de dados relacionais (SGBDR) dominaram o mercado por oferecerem persistência, controle de concorrência e um mecanismo de integração padrão via SQL. Entretanto, o surgimento de grandes volumes de dados e a necessidade de execução em clusters de hardware comum revelaram limitações críticas nos SGBDRs, que não foram projetados para escala horizontal eficiente.

O movimento NoSQL surge não para substituir o relacional, mas como uma alternativa para lidar com a "incompatibilidade de impedância" (diferença entre estruturas de memória e tabelas) e para suportar o processamento massivo de dados. Os modelos NoSQL são categorizados em: chave-valor, documentos, famílias de colunas (orientados a agregados) e grafos. A transição para bancos de dados de aplicativos, em vez de bancos de integração, permite o uso de tecnologias específicas para necessidades distintas, culminando no conceito de **Persistência Poliglota** e no modelo de **Polystores**, que integram múltiplos mecanismos de armazenamento sob uma federação de dados moderna.

--------------------------------------------------------------------------------

## Tópico 1: O Surgimento do NoSQL e a Crise do Modelo Relacional

### 1.1 O Valor e as Limitações do Modelo Relacional

Por décadas, os bancos de dados relacionais foram a escolha padrão devido à estabilidade e ao suporte a transações ACID. Suas principais funções incluem:

- **Persistência:** Armazenamento seguro em memória secundária.
- **Concorrência:** Controle via transações para evitar conflitos de acesso.
- **Integração:** Uso do banco de dados como ponto comum para múltiplos aplicativos (Bancos de Dados de Integração).

Entretanto, dois problemas principais impulsionaram a busca por alternativas:

1. **Incompatibilidade de Impedância:** A dificuldade de traduzir estruturas de dados ricas em memória (objetos, listas, registros aninhados) para o formato rígido de tabelas e linhas.
2. **O Ataque dos Clusters:** SGBDRs operam melhor em escala vertical (máquinas maiores), mas grandes propriedades web exigem escala horizontal (clusters de máquinas menores). SGBDRs em clusters enfrentam problemas de custo de licença e dificuldades técnicas de distribuição de dados.

### 1.2 Transição para Bancos de Dados de Aplicativos

A arquitetura de integração compartilhada, onde vários aplicativos acessam o mesmo banco, gera complexidade e rigidez. O movimento moderno preconiza **Bancos de Dados de Aplicativos**, onde cada serviço gerencia sua própria base e a integração ocorre via serviços web (HTTP/JSON). Isso libera os desenvolvedores para escolherem armazenamentos não relacionais que melhor se adaptem às necessidades de cada serviço.

### Questionário de Revisão 1

1. **Qual é a principal função de um mecanismo transacional em SGBDRs?**
2. **O que define a "incompatibilidade de impedância"?**
3. **Por que os bancos de dados relacionais enfrentam dificuldades em clusters?**
4. **Qual a diferença entre um banco de dados de integração e um de aplicativo?**
5. **Como o Google e a Amazon influenciaram o movimento NoSQL?**
6. **O que significa o termo "NoSQL" no contexto moderno?**
7. **Quais são os dois motivos principais para considerar o uso de NoSQL?**
8. **O que é escala vertical e escala horizontal?**
9. **Como a integração via serviços web difere da integração via SQL?**
10. **Por que o NoSQL é considerado um "neologismo acidental"?**

#### Gabarito 1

1. O mecanismo transacional coordena a interação de múltiplos usuários sobre o mesmo conjunto de dados, evitando conflitos de concorrência. Ele permite que alterações sejam desfeitas em caso de erro, garantindo a integridade dos dados.
2. É a frustração causada pela diferença entre o modelo relacional (tabelas e tuplas) e as estruturas de dados ricas na memória (objetos e listas). Essa divergência exige uma camada de tradução complexa para persistir os dados.
3. Eles não foram projetados para execução em clusters, dependendo frequentemente de subsistemas de disco compartilhado que representam pontos únicos de falha. Além disso, a fragmentação manual em SGBDRs é complexa e rompe controles de integridade e consistência.
4. Bancos de integração são acessados por múltiplos aplicativos, gerando esquemas complexos e coordenação difícil entre equipes. Bancos de aplicativo são acessados por apenas um serviço, facilitando a manutenção e a evolução do esquema.
5. Ambas desenvolveram soluções proprietárias (BigTable e Dynamo) para lidar com escalas massivas que SGBDRs não suportavam. Seus artigos técnicos inspiraram a criação de diversos projetos NoSQL de código aberto.
6. Refere-se a um conjunto mal definido de bancos de dados não relacionais, geralmente de código aberto e sem esquema, desenvolvidos no século XXI. Muitas vezes é interpretado como "Not Only SQL" (Não apenas SQL).
7. Os motivos são a melhoria na produtividade do desenvolvedor, ao reduzir a incompatibilidade de impedância, e a necessidade de processar grandes volumes de dados em clusters.
8. Escala vertical significa adquirir máquinas mais potentes com mais CPU e RAM. Escala horizontal significa adicionar mais máquinas menores e baratas trabalhando em conjunto em um cluster.
9. Na integração SQL, os dados devem seguir o modelo rígido de relações. Em serviços web, a comunicação pode usar estruturas mais ricas, como documentos JSON ou XML, reduzindo o número de chamadas remotas.
10. O termo foi usado pela primeira vez nos anos 90 para um banco relacional que não usava SQL. O significado atual surgiu por acaso em 2009 como uma hashtag para uma reunião sobre bancos distribuídos em São Francisco.

--------------------------------------------------------------------------------

## Tópico 2: Modelagem de Dados e Orientação a Agregados

### 2.1 O Conceito de Agregado

Diferente do modelo relacional que normaliza e divide os dados em tuplas simples, muitos bancos NoSQL são **orientados a agregados**. Um agregado é uma unidade de dados complexa que agrupa informações relacionadas para serem manipuladas como um todo (Ex: um Pedido com seus Itens e Endereço).

- **Vantagens:** Facilita a distribuição em clusters (o agregado é a unidade de fragmentação) e melhora a produtividade do programador.
- **Desvantagens:** Dificulta a análise de dados por diferentes perspectivas (os dados são otimizados para um acesso específico).

### 2.2 Categorias de Modelos NoSQL

|   |   |   |
|---|---|---|
|Modelo|Descrição|Exemplo|
|**Chave-Valor**|Armazena agregados acessíveis apenas via uma chave única.|Riak, Redis|
|**Documento**|Agregados são documentos (JSON/XML) que o banco pode "enxergar" e indexar.|MongoDB, CouchDB|
|**Família de Colunas**|Estrutura de agregados em dois níveis (linhas e colunas), otimizada para grandes volumes.|Cassandra, HBase|
|**Grafos**|Foca em relacionamentos complexos entre entidades, sem orientação a agregados.|Neo4j|

### Questionário de Revisão 2

1. **O que é um agregado no contexto de modelagem de dados?**
2. **Como os agregados auxiliam na operação de clusters?**
3. **Qual a principal limitação das tuplas relacionais frente aos agregados?**
4. **O que caracteriza um banco de dados sem esquema?**
5. **Diferencie bancos de dados de chave-valor de bancos de documentos.**
6. **Por que a desnormalização é comum em bancos NoSQL?**
7. **O que são visões materializadas?**
8. **Como os relacionamentos são tratados em modelos orientados a agregados?**
9. **Qual o papel do "marcador de composição" UML na modelagem agregada?**
10. **Por que o modelo de grafos não é considerado "orientado a agregados"?**

#### Gabarito 2

1. Um agregado é uma coleção de objetos relacionados que tratamos como uma unidade para manipulação de dados e gerenciamento de consistência. Ele permite aninhar estruturas como listas e registros dentro de um único registro complexo.
2. Agregados fornecem uma unidade natural para replicação e fragmentação. Como os dados relacionados estão no mesmo agregado, o cluster pode movê-los entre nós sem perder a integridade daquela unidade de informação.
3. Tuplas relacionais são limitadas a valores simples e não permitem aninhamento de listas ou outros registros. Isso força a divisão de uma única entidade de negócio em múltiplas linhas em tabelas diferentes.
4. Bancos sem esquema permitem adicionar livremente campos aos registros sem definição prévia da estrutura. O esquema é implícito no código do aplicativo que lê os dados, oferecendo flexibilidade para dados não uniformes.
5. Em chave-valor, o banco vê o agregado como um bloco opaco de dados acessível apenas por chave. Em documentos, o banco entende a estrutura interna (JSON/XML), permitindo consultas e índices sobre campos específicos.
6. Ela é usada para minimizar o número de agregados acessados durante uma interação. Ao copiar dados necessários (como o nome de um produto em um item de pedido), reduz-se a necessidade de realizar "joins" custosos entre nós.
7. São formas de persistir resultados de consultas complexas ou agregadas para acesso rápido posterior. Elas são atualizadas quando o dado original muda, melhorando o desempenho de leitura.
8. Eles são geralmente tratados como relacionamentos entre agregados ou por meio de desnormalização. Crucialmente, o modelo deve ser projetado com base em como o aplicativo acessará os dados.
9. Ele é usado para mostrar como os dados são organizados fisicamente dentro da estrutura do agregado. Indica que determinados objetos pertencem e são salvos junto com a entidade principal.
10. Porque grafos focam nas conexões entre pequenas entidades (nós), permitindo percorrer relacionamentos complexos de forma eficiente. Diferente dos agregados, não há uma "unidade" única que englobe todos os dados relacionados.

--------------------------------------------------------------------------------

## Tópico 3: Distribuição, Consistência e Teorema CAP

### 3.1 Modelos de Distribuição

Para escalar, os bancos de dados NoSQL utilizam dois métodos principais:

- **Fragmentação (Sharding):** Divide os dados entre diferentes nós do cluster. Cada nó é responsável por uma parte distinta dos dados.
- **Replicação:** Copia os mesmos dados em vários nós.
    - _Mestre-Escravo:_ Um nó recebe gravações e replica para os escravos (foco em leitura).
    - _Ponto a Ponto (P2P):_ Todos os nós aceitam gravações e leituras, evitando pontos únicos de falha.

### 3.2 O Teorema CAP

Proposto para sistemas distribuídos, afirma que é impossível garantir simultaneamente:

1. **Consistência (Consistency):** Todos os nós veem os mesmos dados ao mesmo tempo.
2. **Disponibilidade (Availability):** Todas as solicitações recebem uma resposta (sucesso ou falha).
3. **Tolerância a Partições (Partition Tolerance):** O sistema continua operando apesar de falhas na rede entre nós. Em caso de partição de rede, o sistema deve escolher entre consistência ou disponibilidade.

### 3.3 Map-Reduce

É um padrão de programação para processar grandes volumes de dados de forma paralela em um cluster. O passo "Map" filtra e organiza os dados, enquanto o "Reduce" agrega os resultados.

### Questionário de Revisão 3

1. **O que é fragmentação (sharding) e qual seu objetivo?**
2. **Explique a diferença entre replicação mestre-escravo e ponto a ponto.**
3. **Quais são os três elementos do Teorema CAP?**
4. **Por que a tolerância a partições é obrigatória em sistemas distribuídos?**
5. **O que acontece em um sistema "CP" (Consistência e Partição) se a rede falhar?**
6. **O que é consistência eventual?**
7. **Qual a função dos quóruns em sistemas NoSQL?**
8. **Como as marcas de versões (version stamps) auxiliam na consistência?**
9. **O que é Map-Reduce?**
10. **Por que relaxar a durabilidade pode ser útil em alguns cenários?**

#### Gabarito 3

1. Fragmentação é a distribuição de diferentes partes dos dados em múltiplos servidores. O objetivo é permitir que o banco de dados suporte cargas maiores de leitura e gravação do que um único servidor suportaria.
2. Na mestre-escravo, um único nó (mestre) é a fonte da verdade para gravações, enquanto os escravos replicam seus dados para leitura. Na ponto a ponto, todos os nós podem receber gravações e leituras, eliminando o mestre como ponto único de falha.
3. Consistência (todos os nós têm os mesmos dados), Disponibilidade (o sistema responde sempre) e Tolerância a Partições (o sistema sobrevive a falhas de comunicação entre nós).
4. Em clusters, falhas de rede (partições) são inevitáveis. Se um sistema não tolera partições, ele deixará de funcionar inteiramente ao primeiro sinal de erro de comunicação entre servidores.
5. Se ocorrer uma falha de rede que impeça a sincronização entre nós, o sistema sacrificará a disponibilidade e recusará solicitações para garantir que nenhum dado inconsistente seja lido ou gravado.
6. É um modelo onde, após uma atualização, os dados podem não estar imediatamente iguais em todos os nós, mas o sistema garante que, se não houver novas atualizações, todos os nós eventualmente convergirão para o mesmo estado.
7. Quóruns definem o número mínimo de nós que devem confirmar uma operação (leitura ou gravação) para que ela seja considerada bem-sucedida, permitindo equilibrar consistência e desempenho.
8. Elas servem para registrar alterações e detectar conflitos entre diferentes versões de um dado em múltiplos nós, permitindo ao sistema saber qual alteração é a mais recente ou se houve uma colisão.
9. É um modelo de computação paralela que divide uma tarefa em duas etapas: o Map extrai dados de agregados e o Reduce combina esses dados para gerar um resultado final consolidado.
10. Relaxar a durabilidade (ex: não esperar o dado ser gravado no disco) pode aumentar significativamente o desempenho de gravação para dados de baixa criticidade, como registros de log ou contadores temporários.

--------------------------------------------------------------------------------

## Tópico 4: Neo4j e Bancos de Dados de Grafos

### 4.1 Fundamentos do Neo4j

O Neo4j é um banco de dados de grafos nativo que utiliza a estrutura de **Nós**, **Relacionamentos** e **Propriedades**.

- **Nós:** Representam entidades (objetos).
- **Relacionamentos:** Conectam nós, possuem um tipo e uma direção.
- **Propriedades:** Pares chave-valor armazenados em nós ou relacionamentos.

### 4.2 Teoria de Grafos e Cypher

A "Lógica de Grafos" foca em como as entidades estão conectadas, sendo ideal para redes sociais, sistemas de recomendação e detecção de fraudes. A linguagem de consulta do Neo4j é o **Cypher**, projetada para ser intuitiva e focada em correspondência de padrões (Pattern Matching).

### Questionário de Revisão 4

1. **Quais são os elementos básicos de um banco de dados de propriedades?**
2. **O que diferencia o Neo4j dos bancos orientados a agregados?**
3. **O que é um nó no Neo4j?**
4. **Qual a importância da direção nos relacionamentos de grafos?**
5. **O que é Cypher?**
6. **Em quais casos o Neo4j é uma escolha melhor que um SGBDR?**
7. **O que significa "pensar em grafos"?**
8. **Como funciona a correspondência de padrões (Pattern Matching) no Cypher?**
9. **O que são propriedades em um grafo?**
10. **Quais ferramentas compõem o ecossistema Neo4j para exploração de dados?**

#### Gabarito 4

1. Os elementos básicos são Nós (entidades), Relacionamentos (conexões entre entidades) e Propriedades (atributos de nós e relacionamentos).
2. Enquanto bancos orientados a agregados tentam manter dados relacionados juntos em uma unidade, o Neo4j foca na eficiência de percorrer relacionamentos complexos entre entidades independentes.
3. Um nó é o equivalente a um objeto ou uma entidade no grafo. Ele pode ter rótulos (labels) para categorização e propriedades para armazenar dados.
4. A direção ajuda a definir semanticamente o relacionamento (ex: "Martin SEGUE Neo4j"). Embora o Neo4j permita percorrer relacionamentos em qualquer direção sem perda de desempenho, a direção ajuda na clareza do modelo.
5. Cypher é a linguagem de consulta declarativa do Neo4j. Ela utiliza uma sintaxe visual baseada em ASCII para descrever padrões de nós e relacionamentos no grafo.
6. Quando os dados possuem relacionamentos complexos e profundos ("muitos-para-muitos") ou quando o desempenho das consultas depende mais das conexões entre dados do que dos dados em si.
7. É o processo de modelar o domínio focando não apenas nas entidades, mas principalmente em como elas se conectam e quais são as regras que governam essas conexões.
8. É a capacidade de expressar consultas descrevendo a forma do grafo que você deseja encontrar (ex: "encontrar amigos de amigos que gostam do mesmo produto").
9. São pares chave-valor que armazenam informações detalhadas sobre as entidades (nós) ou sobre os próprios relacionamentos (ex: a data em que uma amizade começou).
10. O ecossistema inclui ferramentas como o Neo4j Browser para consultas interativas e o Neo4j Bloom para visualização e exploração de grafos em larga escala.

--------------------------------------------------------------------------------

## Tópico 5: Persistência Poliglota e Polystores

### 5.1 O Futuro: Persistência Poliglota

O termo **Persistência Poliglota** descreve o uso de diferentes tecnologias de armazenamento para diferentes necessidades dentro de uma mesma organização ou aplicativo.

- Exemplo: Um SGBDR para transações financeiras, um Grafo para recomendações e um Chave-Valor para sessões de usuário.

### 5.2 O Modelo Polystore (BigDAWG)

Michael Stonebraker defende que "um tamanho não serve para todos". As **Polystores** são sistemas de federação de dados que obedecem a dois princípios:

1. **Não há uma linguagem de consulta universal:** Usuários devem usar a linguagem que melhor se adapta aos dados (SQL para estruturados, linguagens de array para séries temporais, etc.).
2. **Funcionalidade completa dos bancos subjacentes:** O sistema não deve limitar o poder do banco local em prol da federação.

### Questionário de Revisão 5

1. **O que é persistência poliglota?**
2. **Por que Michael Stonebraker afirma que "um tamanho não serve para todos"?**
3. **O que é um DBMS Federado?**
4. **Qual a diferença entre um DBMS paralelo e um sistema polystore?**
5. **O que define o conceito de "Ilha de Informação" em polystores?**
6. **O que são shims em uma arquitetura polystore?**
7. **Quais são os problemas da curadoria de dados (ETL) tradicional?**
8. **O que é transparência de localização?**
9. **Quais são os desafios de pesquisa em sistemas polystores?**
10. **Como o projeto BigDAWG implementa o conceito de polystore?**

#### Gabarito 5

1. É a prática de utilizar múltiplos tipos de tecnologias de banco de dados (relacional, grafos, documentos, etc.) para lidar com diferentes problemas de armazenamento de dados em um mesmo ecossistema de software.
2. Porque nenhum banco de dados individual oferece alto desempenho para todos os tipos de dados (texto, JSON, séries temporais, relacionais). Cada arquitetura tem pontos fortes específicos que devem ser aproveitados.
3. É um middleware que roda sobre vários DBMS locais, apresentando uma interface única para sistemas distintos com esquemas independentes.
4. DBMSs paralelos são um único banco de dados com tabelas particionadas sob um único esquema. Polystores integram múltiplos bancos de dados distintos com modelos de dados e linguagens de consulta diferentes.
5. Uma ilha de informação consiste em um modelo de dados, uma linguagem de consulta específica e mecanismos para traduzir essas consultas para os sistemas de armazenamento locais daquela ilha.
6. São camadas de software que traduzem as instruções da linguagem da "ilha" para o dialeto local suportado por cada mecanismo de armazenamento específico dentro do sistema.
7. O ETL é caro e complexo. Frequentemente, os dados curados são transformados de tal forma que se tornam incompatíveis com as fontes originais, dificultando consultas cruzadas em tempo real.
8. É a capacidade do sistema de fornecer a mesma resposta a uma consulta, independentemente de onde os dados residam fisicamente entre os diversos motores de armazenamento.
9. Os desafios incluem otimização de consultas em "caixa preta", construção automática de shims, transações distribuídas entre motores diferentes e balanceamento de carga automático.
10. O BigDAWG é um sistema de polystore que permite aos usuários navegar entre diferentes ilhas de informação, utilizando a melhor ferramenta para cada tipo de análise sem perder o acesso global aos dados.

--------------------------------------------------------------------------------

## Questões Dissertativas (Para Estudo Independente)

1. Analise as consequências da transição de "Bancos de Dados de Integração" para "Bancos de Dados de Aplicativo" na agilidade de desenvolvimento de uma empresa.
2. Discuta como o Teorema CAP limita o design de sistemas globais e como a escolha entre Consistência e Disponibilidade impacta a experiência do usuário final.
3. Explique a relação entre a orientação a agregados e o desempenho de sistemas distribuídos em larga escala.
4. Compare e contraste as linguagens SQL e Cypher, focando em como cada uma aborda a recuperação de dados altamente conectados.
5. Avalie os custos operacionais de manter uma arquitetura de Persistência Poliglota em comparação com a simplicidade de um SGBDR centralizado único.

--------------------------------------------------------------------------------

## Glossário

- **ACID:** Conjunto de propriedades (Atomicidade, Consistência, Isolamento, Durabilidade) que garantem que as transações de banco de dados sejam processadas de forma confiável.
- **Agregado:** Uma unidade de dados que combina informações relacionadas (ex: pedido e itens) para facilitar o acesso e a distribuição.
- **Cypher:** Linguagem de consulta declarativa baseada em padrões de grafos, utilizada pelo Neo4j.
- **Desnormalização:** Processo de adicionar dados redundantes em um modelo para otimizar o desempenho de leitura.
- **ETL (Extract, Transform, Load):** Processo de extração de dados de fontes, transformação para limpeza/ajuste e carregamento em um destino (como um Data Warehouse).
- **Fragmentação (Sharding):** Técnica de particionamento horizontal de dados entre múltiplos servidores em um cluster.
- **Incompatibilidade de Impedância:** O conflito entre o modelo relacional de tabelas e as estruturas de dados ricas usadas em linguagens de programação.
- **NoSQL:** Termo para bancos de dados não relacionais, geralmente distribuídos e sem esquema fixo.
- **Persistência Poliglota:** Abordagem arquitetural que utiliza diferentes bancos de dados para atender diferentes requisitos de dados em uma aplicação.
- **Polystore:** Sistema de gerenciamento de dados que integra múltiplos motores de armazenamento (relacional, grafo, etc.) e permite consultas via múltiplas linguagens.
- **Quórum:** Número mínimo de votos de nós em um sistema distribuído para que uma operação de leitura ou escrita seja validada.
- **SGBDR (Sistema Gerenciador de Banco de Dados Relacional):** Software que gerencia bancos de dados baseados no modelo relacional (ex: Oracle, MySQL).