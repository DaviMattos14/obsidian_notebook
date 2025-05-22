# Modelo Conceitual

Descreve a estrutura de um BD de uma forma mais próxima da percepção dos usuários
Independente de aspectos de implementação
	Representa a estrutura de um banco de dados sem considerar um SGBD específico
## Modelo Entidade-Relacionamento
### Três conceitos básicos
![[ER.png]]
#### Entidade
“Conjunto de objetos da realidade modelada sobre os quais deseja-se manter informações no banco de dados”
	Podendo ser:
		- Algo que existe fisicamente, que pode ser tocado
		- Algo que existe conceitualmente (Abstrato)
		- Podem ser eventos
##### Entidade Fraca
Existem entidades que apenas existem em função de outras
![[entidade_fraca.png]]
##### Entidade Associativa
![[entidade_associativa.png]]
#### Relacionamento
Conjunto de associações entre ocorrências/instâncias de entidades
Cada ocorrência da entidade que participa de um relacionamento desempenha um Papel
Úteis sobretudo nos auto-relacionamentos (relacionamento unário)
##### Grau de Relacionamento
Número de (instâncias de) entidades que participam do relacionamento
#### Cardinalidades
Expressar o número de ocorrências/instâncias às quais outra ocorrência/instância pode ser associada através de um conjunto de relacionamentos
- (1:1)
- (1:N)
- (N:N)
#### Atributo
![[atributo.png]]
Propriedades que descrevem uma entidade
Exemplo:
	– Entidade: Funcionário
	– Atributos: código, nome, data de nascimento
###### Atributo Composto
![[atributo composto.png]]
##### Atributo Multivalorado
Atributos multivalorados e compostos são atributos complexos
![[atributo_multivalorado.png]]
- Atributo de Relacionamento
![[atributo_relacionamento.png]]
### Generalização (Especialização)
É um relacionamento de classificação entre uma entidade mais geral e outra mais específica
A entidade mais geral é denominada entidade de nível superior (**superclasse**) e a mais específica de entidade de nível inferior (**subclasse**)
As propriedades da superclasse são herdadas pela subclasse → **Herança**
![[generalização.png]]
##### Especialização Total
Para cada ocorrência da entidade genérica existe **sempre** uma entidade especializada
![[especialização_total.png]]
##### Especialização Parcial
**Nem toda** ocorrência da entidade genérica possui uma ocorrência correspondente em uma entidade especializada
![[especialização+parcial.png]]
##### Especialização Exclusiva
**Exclusiva (x)**: ocorrência de uma entidade genérica em apenas uma entidade especializada
##### Especialização Compartilhada
**Compartilhada (c)**: Ocorrência de uma entidade genérica pode aparecer em **várias** entidades especializadas
![[Modelo_ER.png]]
### Construção do Modelo
#### Transformando Relacionamento N:N para Entidade
1. O relacionamento N:N é representado como uma entidade
2. A entidade criada é relacionada às entidades que originalmente participavam do relacionamento
3. A entidade criada tem como identificador:
	- Os relacionamentos com as entidades que originalmente participavam do relacionamento
	- Os atributos que eram identificadores do relacionamento original (caso o relacionamento original tivesse atributos identificadores)
4. A cardinalidade da entidade criada em cada relacionamento de que participa é (1,1)
5. As cardinalidades das entidades que eram originalmente associadas pelo relacionamento transformado em entidade são transcritas ao novo modelo conforme mostrado no exemplo inicial
#### Entidade vs. Atributo
Se objeto está vinculado a outros objetos:
- Deve ser modelado como entidade
Caso contrário:
- Pode ser modelado como atributo
Conjunto de valores de um determinado objeto é fixo (domínio fixo):
- Pode ser modelado como atributo
Existem transações no sistema que alteram o conjunto de valores do objeto (domínio variável):
- Não deve ser modelado como atributo
#### Atributo vs. Especialização/Generalização
Especialização deve ser usada quando:
As classes especializadas de entidades possuem propriedades particulares:
• Atributos
• Relacionamentos
• Generalizações/especializações
![[especializacao1.png]]
#### Conversão de relacionamentos não binários para a forma binária
![[n_ario_binario.png]]
# Modelo Relacional
O modelo relacional representa um banco de dados como um conjunto de relações
 **Relação $\leftrightarrow$ Tabela** (de valores)
 ![[modelo_relacional.png]]
## Relação R
$$
\text{R}\hspace{10px}(A_1,A_2,A_3,...,A_n)
$$
Onde:
- R é o nome da relação
- $A_1,A_2,...,A_n$ é uma lista de atributos
- N é o grau da relação
Exemplo:
```SQL
Professor (ID_Professor, Nome, CPF)
```

## Chave Primária (PK)
Seja $K \subset R$ 
	K é uma super chave de R se os valores de K são suficientes para identificar um única tupla de cada possível relação de $r(R)$
	Super-chave K é uma chave candidata se K é mínima
	Uma das chaves candidatas é selecionada para ser **chave primária**
	Chave(s) candidata(s) não selecionada(s) → chave(s) alternativa(s)
## Restrições de integridade de valores Null
Especifica se a um atributo é permitido ter valores Null
## Chave Estrangeira
$$
R_1[FK]\rightarrow R_2[PK]
$$
Onde:
	- PK é a chave primária
	- FK é a chave estrangeira
Então, para qualquer tupla $t_1$ de $R_1$:
	$t_1[FK] = t_2[PK]$, onde $t_2$ é uma tupla de $R_2$ ou $t_1[FK]$ é Null

![[fk.png]]
## Esquema Lógico
```SQL
Departamento (Nome_Depto, ID_Depto)
	PK(ID_Depto)

Professor (ID_Professor, Nome, CPF, ID_Depto)
	PK(ID_Professor)
	FK(ID_Depto) ref Departamento(ID_Depto)
```
# Mapeamento ER $\rightarrow$ Relacional
## Entidades Fortes
![[entidade_forte.png]]
1. Criar uma relação: `Aluno()`
2. Para todo Atributo Simples criar um atributo: `Aluno(Nome, CPF)`
3. Para atributos compostos, criar vários atributos simples: `Aluno(Nome, CPF, Rua, Numero)`
4. Criar uma chave primária 
```SQL
Aluno(Nome, CPF, Rua, Numero) 
	PK(CPF)
```
## Entidades Fracas

## Relacionamentos Binários 1:1
## Relacionamentos Binários 1:N
## Relacionamentos Binários N:N
## Atributos Multivalorados
## Relacionamentos N-ários, N>2