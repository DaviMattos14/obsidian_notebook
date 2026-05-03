## 1. Big Data e a Evolução dos Bancos de Dados

O cenário tecnológico atual é marcado pelo "Data Deluge" (dilúvio de dados), onde a ciência evoluiu de modelos empíricos e teóricos para o "Quarto Paradigma", orientado a grandes volumes de dados (_in silico_). O **Big Data** é definido pelo seu alto volume, velocidade e variedade, exigindo formas inovadoras de processamento. Tradicionalmente classificado pelos "3 V's", o conceito expandiu-se para os **6 V's**:

- **Volume:** Terabytes, registros e arquivos distribuídos.
- **Velocidade:** Processamento em lote (batch), tempo real ou fluxos (streams).
- **Variedade:** Dados estruturados, não estruturados, probabilísticos e dinâmicos.
- **Veracidade:** Autenticidade, reputação da origem e disponibilidade.
- **Variabilidade:** Mudanças constantes nos dados e nos modelos.
- **Valor:** Correlações estatísticas e extração de _insights_ para tomada de decisão.

A evolução dos bancos de dados acompanhou o hardware e a arquitetura de sistemas. Saímos dos modelos de rede e hierárquicos (anos 60/70) para o "reinado relacional" (SQL), que dominou com transações ACID e o modelo OLTP. Contudo, a necessidade de escalabilidade horizontal e flexibilidade de esquema no século XXI impulsionou o surgimento do **NoSQL** ("Not Only SQL") e, mais recentemente, do **NewSQL**.

### Questionário de Revisão (Tópico 1)

1. **Como o Big Data é definido segundo a ótica da Ciência de Dados?** Big Data refere-se a ativos de informação de grande volume, alta velocidade e alta variedade. Esses ativos demandam formas inovadoras e econômicas de processamento para melhorar o _insight_ e a tomada de decisão.
2. **O que caracteriza o "Quarto Paradigma" da ciência mencionado no material?** O quarto paradigma representa a ciência orientada a grandes volumes de dados, utilizando computação distribuída e softwares sofisticados. Ele sucede os paradigmas empírico, teórico e de simulação computacional.
3. **Quais são os componentes do hardware que evoluíram para suportar o Big Data?** As máquinas evoluíram de memórias de 256KB para terabytes de DDR5 e de discos rígidos (HD) para SSDs. Além disso, os processadores avançaram de CPUs simples como o 386 para arquiteturas multinúcleo como o Core i9 e GPUs de alto desempenho.
4. **O que significa o termo "Data Deluge"?** O termo refere-se ao imenso volume de dados gerados atualmente por diversas fontes, como IoT, redes sociais e dispositivos móveis. Esse fenômeno desafia as capacidades tradicionais de armazenamento e gestão de dados.
5. **Por que o reinado dos SGBDr (Relacionais) começou a ser questionado?** Porque os SGBDr tradicionais enfrentam dificuldades para lidar com a complexidade, dispersão e as altas taxas de crescimento dos dados modernos. Além disso, problemas de Big Data muitas vezes exigem mais flexibilidade de esquema e melhor desempenho em larga escala do que o modelo relacional oferece.
6. **Quais são as duas razões principais que motivam a troca de um SGBDr por NoSQL segundo Michael Stonebraker?** As duas razões fundamentais são a necessidade de melhor desempenho e a necessidade de mais flexibilidade. Sistemas NoSQL são projetados para escalar horizontalmente em ambientes de clusters, superando limitações de performance dos modelos tradicionais.
7. **Explique o conceito de Variabilidade nos 6 V's do Big Data.** A variabilidade refere-se à natureza mutável dos dados, onde tanto o conteúdo quanto o modelo de ligação entre eles podem sofrer alterações frequentes. Isso exige sistemas que suportem esquemas dinâmicos.
8. **Como a arquitetura de sistemas evoluiu ao longo das décadas?** A arquitetura evoluiu de sistemas centralizados (mainframes) para sistemas distribuídos. Isso inclui modelos Cliente/Servidor, Peer-to-Peer (P2P), clusters, computação de alto desempenho (HPC) e, finalmente, a computação em nuvem (Cloud).
9. **Qual o papel da Proveniência (Provenance) no contexto do Big Data?** A proveniência ajuda a classificar e gerir os desafios de gestão de dados ao rastrear a origem e o histórico dos ativos de informação. Ela é essencial para garantir a confiabilidade e a veracidade dos dados processados.
10. **O que é o NewSQL no histórico evolutivo dos bancos de dados?** NewSQL é uma classe de bancos de dados modernos que busca combinar a escalabilidade horizontal dos sistemas NoSQL com as garantias ACID e a linguagem SQL dos sistemas relacionais tradicionais.

--------------------------------------------------------------------------------

## 2. Conceitos Básicos e Arquitetura NoSQL

Os sistemas NoSQL rompem com a rigidez dos esquemas relacionais (_schemaless_) e focam na **orientação a agregados**. Um agregado é um conjunto de objetos relacionados tratados como uma unidade atômica de dados, facilitando a distribuição em clusters.

### O Teorema CAP e Propriedades BASE

Diferente dos SGBDr, que seguem o princípio ACID (Atomicidade, Consistência, Isolamento, Durabilidade), os sistemas NoSQL operam sob o **Teorema CAP**, que afirma que em um sistema distribuído só é possível garantir simultaneamente duas destas três propriedades:

- **Consistência (C):** Todos os nós veem os mesmos dados ao mesmo tempo.
- **Disponibilidade (A):** O sistema responde às requisições mesmo em caso de falhas parciais.
- **Tolerância a Partições (P):** O sistema continua operando apesar de falhas de comunicação que dividem o cluster.

Como alternativa ao ACID, surge o conceito **BASE**:

- **Basically Available:** Garante disponibilidade via replicação.
- **Soft State:** O estado do dado pode mudar ao longo do tempo devido à falta de consistência imediata.
- **Eventually Consistent (Consistência Eventual):** O sistema garante que, em algum momento, todos os nós estarão sincronizados.

### Distribuição de Dados

A escalabilidade horizontal é alcançada por duas estratégias:

1. **Fragmentação (Sharding):** Distribuição de dados diferentes em nós diferentes para equilibrar a carga.
2. **Replicação:** Cópias dos mesmos dados em múltiplos nós para resiliência. Pode ser **Mestre-Escravo** (um nó grava, outros leem) ou **Ponto a Ponto (P2P)** (todos os nós processam leituras e escritas).

### Questionário de Revisão (Tópico 2)

1. **O que define um "Agregado" em sistemas NoSQL?** Um agregado é um conjunto de objetos relacionados que precisam ser tratados como uma única unidade de dados. Ele facilita o gerenciamento da consistência e serve como unidade natural para replicação e particionamento em clusters.
2. **Explique a propriedade "Consistência Eventual" (Eventually Consistent).** Significa que o sistema não garante que um dado lido imediatamente após a escrita será o mais atual, pois a propagação leva tempo. Contudo, garante-se que todas as atualizações serão propagadas para todos os nós em algum momento futuro.
3. **Qual a diferença fundamental entre escalabilidade vertical e horizontal?** A escalabilidade vertical envolve aumentar o poder de processamento de uma única máquina (mais CPU ou RAM), enquanto a horizontal consiste em adicionar mais nós (máquinas) ao sistema para distribuir o armazenamento e o processamento.
4. **Por que a fragmentação (sharding) é importante para o desempenho?** O sharding distribui a carga de acesso aos registros entre vários nós do cluster, reduzindo a concorrência. Isso permite que operações de leitura e gravação sejam processadas simultaneamente em partes diferentes do dataset.
5. **Quais os riscos da replicação Ponto a Ponto (P2P)?** O principal risco é a inconsistência de dados quando duas pessoas tentam atualizar o mesmo item simultaneamente em nós diferentes. Sem um mestre central, conflitos de escrita podem ocorrer e precisam de estratégias de resolução.
6. **O que afirma o Teorema CAP de Brewer?** O Teorema CAP afirma que sistemas distribuídos que gerenciam dados em vários nós não podem oferecer simultaneamente Consistência, Disponibilidade e Tolerância a Partições; apenas duas dessas propriedades podem ser atendidas.
7. **Diferencie os conflitos escrita-escrita e leitura-escrita.** Escrita-escrita ocorre quando dois clientes tentam alterar o mesmo agregado simultaneamente. Leitura-escrita acontece quando um cliente lê um dado inconsistente enquanto outro nó ainda está processando a atualização desse mesmo dado.
8. **O que é o controle de concorrência otimista?** É uma abordagem para resolução de conflitos que permite que as operações ocorram livremente e detecta conflitos somente após o fato, tratando-os posteriormente. É o oposto do controle pessimista, que bloqueia os dados preventivamente.
9. **O que significa a "incompatibilidade de impedância"?** Refere-se à diferença entre a estrutura lógica dos dados em memória (objetos) e a estrutura em tabelas de um banco relacional. Agregados NoSQL reduzem esse problema por terem uma estrutura mais próxima dos objetos de programação.
10. **Quais são os benefícios da replicação Mestre-Escravo?** Essa estratégia ajuda a ampliar a escalabilidade de leitura, permitindo que os nós escravos atendam consultas, e oferece resiliência, pois um escravo pode substituir o mestre em caso de falha deste.

--------------------------------------------------------------------------------

## 3. Tipos de Sistemas NoSQL e Modelos de Dados

O ecossistema NoSQL é dividido em quatro categorias principais baseadas em seus modelos de dados:

### Família Chave-Valor

É o modelo mais simples, baseado em pares `<chave, valor>`. O valor é opaco para o banco (geralmente um BLOB), e o acesso ocorre estritamente pela chave. Oferece altíssimo desempenho e escalabilidade. Exemplos: **Redis, Riak, DynamoDB**.

### Orientado a Documentos

Armazena dados em documentos (JSON, BSON, XML) organizados em coleções. Diferente do chave-valor, a estrutura interna é visível, permitindo buscas por campos específicos e a criação de índices secundários. Exemplos: **MongoDB, CouchDB**.

### Família de Colunas (Tabular)

Utiliza pares `<chave, família de colunas>`. Os dados são armazenados em linhas com chaves, mas as colunas podem variar entre as linhas. É altamente eficiente para buscas em faixas de chaves e grandes volumes. Exemplos: **HBase, Google Bigtable, Cassandra**.

### Baseado em Grafos

Foca em entidades (vértices/nós) e seus relacionamentos (arestas/arcos). É o único modelo NoSQL que não é orientado a agregados, pois foca na conexão entre os dados. Suporta propriedades ACID e processamento transacional. Exemplos: **Neo4j, AllegroGraph**.

### Persistência Poliglota e MapReduce

A **Persistência Poliglota** defende o uso de diferentes tipos de bancos de dados para diferentes necessidades dentro de uma mesma aplicação. Para processar esses volumes massivos em clusters, utiliza-se o modelo **MapReduce**:

1. **Map:** Transforma fragmentos de entrada em pares chave-valor.
2. **Shuffle/Sort:** Agrupa e ordena os pares com chaves idênticas.
3. **Reduce:** Combina os valores agrupados para produzir o resultado final.

### Questionário de Revisão (Tópico 3)

1. **Por que o valor em um banco Chave-Valor é considerado "opaco"?** Porque o banco de dados não conhece a estrutura interna do que está armazenado no campo de valor, tratando-o apenas como um conjunto de bytes (BLOB). O acesso e a manipulação ocorrem apenas através da chave identificadora.
2. **Qual a vantagem dos bancos orientados a documentos sobre os de chave-valor?** Diferente dos sistemas chave-valor, os bancos de documentos permitem ver a estrutura interna dos dados. Isso possibilita realizar buscas por campos específicos dentro do documento e criar índices secundários para otimizar consultas.
3. **Como funciona a estrutura de uma "família de colunas"?** Uma família de colunas agrupa dados que geralmente são acessados juntos. Cada linha possui uma chave única e pode conter um número variável de colunas, que podem ser adicionadas de forma dinâmica sem afetar as outras linhas.
4. **Em que situações o modelo de grafos é superior aos outros modelos NoSQL?** O modelo de grafos é superior quando a relação entre os dados é tão ou mais importante que os próprios dados individuais. Ele brilha em dados massivos e altamente conectados, como redes sociais, detecção de fraude e logística.
5. **O que é "Persistência Poliglota"?** É o conceito de utilizar múltiplas tecnologias de armazenamento de dados em uma única arquitetura de sistema, escolhendo o banco de dados que melhor resolve cada problema específico (ex: SQL para transações e Grafos para recomendações).
6. **Descreva a função da etapa 'Shuffle' no MapReduce.** A etapa de Shuffle (e Sort) serve para agrupar e ordenar todos os pares chave-valor intermediários gerados pela função Map. Isso garante que todos os valores associados a uma mesma chave sejam enviados para o mesmo processo Reduce.
7. **Quais são os dois tipos principais de grafos mencionados?** Os grafos podem ser orientados a **Propriedades** (LPG), comuns em Data Science e análise de performance, ou orientados à **Semântica** (RDF), fundamentais para a Web Semântica e grafos do conhecimento.
8. **Como bancos de colunas como o Cassandra realizam a fragmentação?** A fragmentação ocorre tanto por linhas (através de faixas de valores da chave primária) quanto por famílias de colunas, permitindo dividir os dados entre diversos nós de um cluster para escala massiva.
9. **O que são "Wrappers" no contexto de integração de dados?** Wrappers são componentes usados em polystores para integrar diferentes fontes de dados (SQL, NoSQL, HDFS). Eles permitem o acesso integrado a dados em vários formatos e sistemas de armazenamento distintos.
10. **Dê um exemplo prático de aplicação do MapReduce.** Um exemplo clássico é a contagem de palavras em uma vasta coleção de documentos. O Map emite pares `<palavra, 1>` para cada ocorrência, e o Reduce soma esses valores para cada palavra única, gerando o total final.

--------------------------------------------------------------------------------

## 4. Grafos e a Linguagem Cypher (Foco Neo4j)

A transição do SQL para grafos resolve o custo proibitivo das operações de **JOIN** em redes profundas. Enquanto no modelo relacional os relacionamentos são inferidos em tempo de execução via índices, no modelo de grafos os relacionamentos são objetos físicos e persistentes no disco (**Index-Free Adjacency**).

### Anatomia de um Labeled Property Graph (LPG)

- **Nós (Vértices):** Representam entidades (ex: Pessoa, Filme).
- **Arestas (Relacionamentos):** Conexões direcionadas com rótulos (ex: `:TRABALHA_EM`).
- **Propriedades:** Pares chave-valor armazenados em nós ou arestas.
- **Rótulos (Labels):** Utilizados para categorizar nós e filtrar pontos de entrada.

### Linguagem Cypher

Cypher é uma linguagem declarativa que utiliza uma sintaxe visual inspirada em "ASCII-Art":

- `()` representa um nó.
- `[]` representa um relacionamento.
- `->` representa a direção.
- `{}` contém as propriedades (chave-valor)
```Neo4j
					(p:Pessoa)-[:SEGUE]->(amigo:Pessoa)
```

**Cláusulas Principais:**

- **MATCH:** Procura padrões na topologia do grafo.
- **WHERE:** Filtragem avançada de propriedades.
- **RETURN:** Define a projeção final dos dados.
- **MERGE:** Funciona como "busque ou crie", garantindo a idempotência.
- **WITH:** Permite encadear subconsultas e realizar agregações intermediárias.

### Questionário de Revisão (Tópico 4)

1. **O que é "Index-Free Adjacency" e por que ela é importante?** É a capacidade de um nó armazenar ponteiros físicos diretos para seus vizinhos. Isso torna a travessia do grafo extremamente rápida (tempo constante por salto), pois o custo depende apenas dos dados explorados e não do tamanho total do disco.
2. **Qual o problema do excesso de JOINs no modelo relacional?** Em dados altamente conectados e massivos, cada JOIN exige uma pesquisa de índice complexa. Em redes profundas, a latência aumenta exponencialmente, levando ao colapso da performance do sistema.
3. **Como Cypher representa um relacionamento entre duas pessoas em sua sintaxe?** A sintaxe utiliza ASCII-Art: `(p:Pessoa)-[:SEGUE]->(amigo:Pessoa)`. Onde os parênteses são nós, os colchetes são o tipo do relacionamento e a seta indica a direção da conexão.
4. **Diferencie o uso de MATCH e MERGE.** O MATCH é usado para procurar padrões existentes no grafo. O MERGE é usado para garantir que um padrão exista; ele tenta encontrar o padrão e, se não existir, ele o cria, evitando duplicatas (idempotência).
5. **Para que serve a cláusula WITH no Neo4j?** A cláusula WITH funciona como uma barreira de processamento ou "pipe" que permite encadear subconsultas, realizar agregações intermediárias (como contagens) e preparar listas para operações subsequentes.
6. **O que acontece ao tentar usar DELETE em um nó com relacionamentos ativos?** A operação DELETE falha se o nó possuir relações ativas para proteger a integridade do grafo. É necessário usar `DETACH DELETE` para remover o nó e todas as suas conexões simultaneamente de forma segura.
7. **Explique o conceito de "Caminhos de Profundidade Variável".** É a capacidade de encontrar conexões diretas ou indiretas até um determinado nível de distância com uma única linha de código, como em `MATCH (p)-[:COLABORA_SEM *1..3]-(colaborador)`.
8. **Quais as principais diferenças entre os paradigmas LPG e RDF?** LPG foca em performance, análise e travessia rápida com propriedades ricas. RDF foca em interoperabilidade, semântica e padrões web, utilizando uma estrutura de triplas (Sujeito-Predicado-Objeto) e a linguagem SPARQL.
9. **Como o Neo4j garante a confiabilidade dos dados?** Diferente de muitos bancos NoSQL, o Neo4j é totalmente compatível com as propriedades ACID (Atomicidade, Consistência, Isolamento e Durabilidade), garantindo transações seguras.
10. **Mencione três casos de uso práticos para bancos de dados de grafos.** São utilizados em Humanidades Digitais (redes de influência histórica), Agricultura Digital (rastreabilidade produtiva) e Segurança (detecção de ciclos de lavagem de dinheiro).

--------------------------------------------------------------------------------

## Sugestões de Questões Dissertativas

- _Não forneça as respostas para estas questões; use-as para testar o nível de profundidade do seu estudo._

1. Analise o Teorema CAP e discuta as implicações de se escolher um sistema do tipo AP (Disponibilidade e Tolerância a Partições) em detrimento da Consistência imediata para uma aplicação financeira global.
2. Compare e contraste as garantias ACID dos SGBDr com as propriedades BASE dos sistemas NoSQL. Em que cenários cada uma é indispensável?
3. Explique como o modelo de agregados do NoSQL influencia o design de aplicações web modernas e como ele resolve o problema da "incompatibilidade de impedância".
4. Discorra sobre a evolução da ciência rumo ao Quarto Paradigma e como as características de Volume, Variedade e Velocidade do Big Data moldaram as novas tecnologias de banco de dados.
5. Avalie a importância da "Index-Free Adjacency" para a análise de redes sociais de larga escala em comparação com o uso de tabelas de junção em bancos de dados relacionais.

--------------------------------------------------------------------------------

## Gabarito (Respostas Curtas)

### Tópico 1

1. Dados de grande volume, velocidade e variedade que exigem novas técnicas de processamento.
2. Ciência orientada a dados com computação distribuída e softwares avançados.
3. RAM DDR5 (terabytes), SSDs e GPUs de alto desempenho (Nvidia).
4. Volume massivo de dados gerados por IoT, redes sociais e web.
5. Dificuldade em lidar com a escala, flexibilidade e crescimento acelerado dos dados.
6. Necessidade de melhor desempenho e maior flexibilidade.
7. Natureza mutável dos dados e modelos, exigindo esquemas dinâmicos.
8. De mainframes centralizados para clusters e nuvens distribuídas.
9. Rastrear a origem e histórico para garantir veracidade.
10. Bancos que unem escalabilidade NoSQL com garantias ACID e SQL.

### Tópico 2

1. Conjunto de objetos tratados como unidade para consistência e distribuição.
2. Garantia de que todos os nós sincronizarão os dados em algum momento.
3. Vertical aumenta poder da máquina; horizontal adiciona mais máquinas ao cluster.
4. Distribui a carga de acesso entre nós, reduzindo concorrência e latência.
5. Inconsistência por atualizações simultâneas em nós diferentes.
6. Apenas duas entre Consistência, Disponibilidade e Tolerância a Partições podem ser atendidas.
7. Escrita-escrita: dois alteram o mesmo dado. Leitura-escrita: lê dado em atualização.
8. Permite operações e resolve conflitos apenas após sua detecção.
9. Diferença estrutural entre objetos em memória e tabelas relacionais.
10. Escala leituras via escravos e provê resiliência se o mestre falhar.

### Tópico 3

1. O banco não conhece ou processa o conteúdo interno do valor (BLOB).
2. Permitem ver a estrutura interna e criar índices em campos específicos.
3. Agrupa colunas acessadas juntas; cada linha pode ter colunas diferentes.
4. Quando a conexão entre entidades é o foco principal (ex: redes sociais).
5. Uso de diferentes bancos (SQL, NoSQL) para diferentes partes de um sistema.
6. Agrupar e ordenar chaves idênticas para processamento no Reduce.
7. Grafos de Propriedades (LPG) e Grafos Semânticos (RDF).
8. Divide linhas por faixas de chaves e colunas por famílias entre nós.
9. Componentes que traduzem consultas para integrar fontes de dados distintas.
10. Contagem de palavras em grandes volumes de texto distribuídos.

### Tópico 4

1. Nós guardam ponteiros diretos para vizinhos, agilizando travessias em tempo constante.
2. Alto custo computacional em índices, gerando latência exponencial em redes profundas.
3. Através de ASCII-Art: `(p:Pessoa)-[:SEGUE]->(amigo:Pessoa)`.
4. MATCH busca dados existentes; MERGE busca e cria se necessário (idempotente).
5. Permite encadear subconsultas e realizar agregações ou transformações intermediárias.
6. O DELETE puro falha; deve-se usar DETACH DELETE para remover as relações.
7. Busca conexões diretas ou indiretas em múltiplos níveis com um comando.
8. LPG foca em performance/travessia; RDF foca em semântica/triplas/padrões web.
9. Implementa as propriedades ACID para garantir transações transacionais seguras.
10. Redes de influência, rastreabilidade agrícola e detecção de fraudes financeiras.

--------------------------------------------------------------------------------

## Glossário Completo

- **ACID:** Conjunto de propriedades (Atomicidade, Consistência, Isolamento, Durabilidade) que garantem transações confiáveis em bancos relacionais.
- **Agregado:** Unidade atômica de dados no NoSQL que agrupa objetos relacionados para facilitar o particionamento.
- **Aresta (Edge):** Conexão ou relacionamento entre dois nós em um grafo.
- **BASE:** Modelo de consistência (Basically Available, Soft State, Eventually Consistent) focado em disponibilidade e escala.
- **BLOB (Binary Large Object):** Grande bloco de dados binários tratados de forma opaca pelo banco de dados.
- **Cipher:** Linguagem de consulta declarativa utilizada pelo Neo4j.
- **Cluster:** Conjunto de computadores (nós) que trabalham juntos como um único sistema.
- **Consistência Eventual:** Propriedade onde os dados em nós distribuídos podem divergir temporariamente, mas se tornarão iguais no futuro.
- **DFS (Distributed File System):** Sistema de arquivos que armazena dados em múltiplos nós de rede.
- **Grafo de Propriedades (LPG):** Modelo de grafo onde nós e arestas podem conter rótulos e propriedades em chave-valor.
- **Idempotência:** Propriedade de uma operação que pode ser aplicada múltiplas vezes sem alterar o resultado além da aplicação inicial (ex: MERGE).
- **Index-Free Adjacency:** Técnica onde cada nó em um grafo aponta fisicamente para seus vizinhos, dispensando índices globais para travessia.
- **MapReduce:** Modelo de programação para processar grandes datasets em paralelo através das funções Map e Reduce.
- **Nó (Node/Vertex):** Representação de uma entidade em um banco de dados de grafos.
- **OLTP (Online Transaction Processing):** Sistemas focados em transações rápidas e frequentes.
- **OLAP (Online Analytical Processing):** Sistemas focados em análises complexas de grandes volumes de dados.
- **Persistência Poliglota:** Prática de usar diferentes tipos de bancos de dados em uma mesma arquitetura para otimizar soluções.
- **RDF (Resource Description Framework):** Padrão do W3C para modelagem de metadados em triplas (Sujeito-Predicado-Objeto).
- **Replicação:** Processo de copiar dados entre múltiplos nós para garantir disponibilidade e resiliência.
- **Sharding (Fragmentação):** Técnica de particionamento horizontal que divide os dados entre diferentes servidores.
- **Teorema CAP:** Princípio que limita sistemas distribuídos a escolher duas entre Consistência, Disponibilidade e Tolerância a Partições.
- **Wrappers:** Camadas de software que adaptam ou integram diferentes fontes de dados em um sistema unificado.