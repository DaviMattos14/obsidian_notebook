# Apostila de Estudos: Bancos de Dados Modernos (NoSQL, NewSQL e In-Memory)

Esta apostila foi elaborada com foco principal no material didático (slides) da disciplina de Banco de Dados II da UFRJ, complementada por literatura técnica de referência (Elmasri & Navathe, Sadalage & Fowler, Kaufmann & Meier, e Valduriez).

---

## 1. Introdução ao Big Data e NoSQL

### 1.1 Conceitos e Motivação
O termo Big Data refere-se a conjuntos de dados tão grandes e complexos que os sistemas de processamento de dados tradicionais (SGBDr) não conseguem lidar de forma eficiente. O NoSQL surge como uma resposta a essa limitação, focando em escalabilidade horizontal e flexibilidade de esquema.

**Os 3 Vs do Big Data:**
* **Volume:** Quantidade massiva de dados gerados diariamente.
* **Velocidade:** Ritmo acelerado de criação e necessidade de processamento em tempo real.
* **Variedade:** Diferentes formatos de dados (estruturados, semiestruturados e não estruturados).

### 1.2 Modelos de Dados NoSQL
Diferente do modelo relacional, o NoSQL utiliza quatro arquiteturas principais:
1.  **Chave-Valor:** Armazenamento mais simples onde uma chave única aponta para um valor. Ex: Redis, Riak.
2.  **Documentos:** Armazena dados como documentos (JSON, BSON), permitindo esquemas flexíveis. Ex: MongoDB, CouchDB.
3.  **Família de Colunas:** Organiza dados em colunas em vez de linhas, otimizado para consultas em grandes volumes. Ex: Cassandra, HBase.
4.  **Grafos:** Foca nas relações entre entidades através de nós e arestas. Ex: Neo4j.

### 1.3 Teorema CAP e Propriedades BASE
O Teorema CAP afirma que um sistema distribuído deve escolher dois entre:
* **C (Consistência):** Todos veem os mesmos dados.
* **A (Disponibilidade):** Toda requisição recebe resposta.
* **P (Tolerância a Partições):** Sistema opera apesar de falhas na rede.

NoSQL geralmente adota o modelo **BASE**: **B**asically **A**vailable, **S**oft state, **E**ventual consistency.

---
### Questionário 1 (Resposta Curta)
1. **O que motivou o surgimento do NoSQL?**
   A necessidade de escalar bancos de dados para volumes massivos de dados e a demanda por esquemas flexíveis que o modelo relacional rígido não suportava eficientemente.

2. **Explique a diferença entre escalabilidade vertical e horizontal.**
   A vertical aumenta o poder do servidor existente (CPU/RAM), enquanto a horizontal adiciona novos servidores comuns ao cluster para distribuir a carga.

3. **O que define o modelo Chave-Valor?**
   É uma estrutura onde os dados são acessados exclusivamente por uma chave indexada, funcionando como um mapa de hash altamente performático.

4. **Qual a vantagem do modelo orientado a Documentos?**
   Ele permite o armazenamento de dados semiestruturados complexos em um único agregado, facilitando o desenvolvimento sem necessidade de JOINs constantes.

5. **Em que situações os bancos de dados de Grafos se destacam?**
   Eles são ideais quando a relação entre os dados é tão ou mais importante que os próprios dados, como em redes sociais.

6. **Defina Consistência Eventual.**
   É a garantia de que, se nenhuma nova atualização for feita, eventualmente todos os acessos retornarão o último valor atualizado.

7. **Como o Teorema CAP afeta sistemas distribuídos?**
   Ele força a decisão entre priorizar a disponibilidade ou a consistência imediata durante uma falha de comunicação na rede.

8. **O que significa dizer que o NoSQL é "Schema-less"?**
   Significa que o banco não exige definição prévia de tabelas, permitindo que cada registro tenha campos diferentes.

9. **O que é o conceito de Persistência Poliglota?**
   É a prática de utilizar diferentes tecnologias de banco de dados dentro de uma mesma aplicação, cada uma para sua melhor finalidade.

10. **Por que bancos de colunas são eficientes para análise de dados?**
    Porque permitem ler apenas as colunas específicas necessárias para um cálculo, economizando tempo de leitura de disco.

---

## 2. NewSQL e In-Memory Databases (IMDB)

### 2.1 O que é NewSQL?
NewSQL busca fornecer a escalabilidade horizontal do NoSQL para cargas transacionais (OLTP), mantendo as garantias ACID do SQL tradicional.

**Principais Características:**
* SQL como linguagem principal e suporte total a ACID.
* Arquitetura de controle de concorrência não bloqueante.
* Projetado para clusters de servidores comuns.

### 2.2 In-Memory Databases (IMDB)
Sistemas como o **VoltDB** eliminam o gargalo do disco armazenando dados na RAM.
* **VoltDB:** Utiliza processamento single-thread por partição para evitar overhead de travas (locking).
* **Tolerância a Falhas:** Utiliza replicação síncrona (K-safety) e snapshots em disco.

### 2.3 Processamento HTAP
HTAP (*Hybrid Transactional/Analytical Processing*) permite transações e análises complexas simultaneamente sobre os mesmos dados, sem processos ETL demorados.

---
### Questionário 2 (Resposta Curta)
1. **Qual o principal diferencial do NewSQL em relação ao NoSQL?**
   O NewSQL mantém as garantias ACID e o uso da linguagem SQL, enquanto busca a mesma escalabilidade distribuída que o NoSQL oferece.

2. **Como o VoltDB elimina o overhead de Locking?**
   Ao particionar os dados e executar transações de forma serializada em cada partição, eliminando a necessidade de travas complexas.

3. **O que é o mecanismo K-safety?**
   É um parâmetro que define quantas cópias extras de cada partição existem no cluster para garantir disponibilidade em caso de falha.

4. **Explique o conceito de HTAP.**
   É a capacidade de um banco de dados realizar processamento transacional e analítico no mesmo motor de dados em tempo real.

5. **Por que a RAM tornou-se viável para bancos de dados?**
   Devido à queda no preço por GB e ao aumento das capacidades de endereçamento dos processadores modernos.

6. **O que é particionamento de dados no NewSQL?**
   É a técnica de distribuir as linhas de uma tabela entre diferentes nós do cluster baseando-se em uma chave de partição.

7. **Qual o papel dos "Stored Procedures" no VoltDB?**
   Encapsular a lógica da transação para executá-la localmente aos dados, reduzindo tráfego de rede.

8. **Como o NewSQL resolve o problema da escalabilidade vertical?**
   Permite que o banco cresça horizontalmente adicionando nós baratos, em vez de investir em um único servidor caro.

9. **O que acontece com os dados em um IMDB em caso de queda de energia?**
   São protegidos por replicação em outros nós e pela persistência periódica (snapshots) em disco.

10. **Por que o SQL ainda é a interface preferida no NewSQL?**
    Pela sua maturidade, ecossistema de ferramentas e ampla base de profissionais capacitados.

---

## Questões Dissertativas (Sem Resposta)
1. Analise como a arquitetura do VoltDB desafia o design tradicional de SGBDs relacionais que dependem de ARIES para recuperação de falhas.
2. Explique como o Teorema CAP se aplica na prática para a escolha entre Google Spanner e Cassandra.
3. Discorra sobre os desafios de implementar JOINs em sistemas NoSQL orientados a documentos.
4. Avalie as vantagens e desvantagens de utilizar bancos de dados In-Memory para volumes de dados históricos (cold data).
5. Como o HTAP impacta a arquitetura de sistemas que dependiam de um Data Warehouse separado?

---

## Glossário de Termos
* **ACID:** Propriedades (Atomicidade, Consistência, Isolamento, Durabilidade) de transações confiáveis.
* **BASE:** Modelo de consistência flexível (Basically Available, Soft state, Eventual consistency).
* **CAP:** Teorema sobre Consistência, Disponibilidade e Tolerância a Partição.
* **HTAP:** Processamento híbrido (Transacional + Analítico).
* **In-Memory:** Armazenamento principal na memória RAM.
* **NewSQL:** Bancos relacionais com escala de NoSQL.
* **Sharding:** Particionamento horizontal de dados.

---
### Gabarito dos Questionários
**Q1:** 1. Escala e flexibilidade. 2. CPU da máquina vs Número de máquinas. 3. Mapa de Hash. 4. Dados complexos sem JOINs. 5. Redes sociais. 6. Sincronia após tempo. 7. Troca C por A em falhas. 8. Sem tabelas rígidas. 9. Vários bancos em um app. 10. Leitura seletiva.
**Q2:** 1. ACID+SQL. 2. Serialização por partição. 3. Redundância de dados. 4. OLTP+OLAP juntos. 5. Baixo custo da RAM. 6. Distribuição por chave. 7. Lógica local ao dado. 8. Cluster de nós comuns. 9. Réplicas e Snapshots. 10. Padrão de mercado.
