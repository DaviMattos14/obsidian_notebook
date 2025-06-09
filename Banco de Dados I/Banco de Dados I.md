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
![[entidade_fraca1.png]]
1. Criar uma relação `Dependente()`
2. Para todo Atributo Simples criar um atributo: `Dependente(Nome, idade)`
3. Para atributos compostos, criar vários atributos simples
4. Criar uma FK apontando para PK da Entidade Forte
```SQL
Dependente(Nome, Idade, SocioCPF)
	FK(SocioCPF) ref Socio(CPF)
```
5. Criar uma PK composta pelo Atributo identificador e FK
```SQL
Dependente(Nome, Idade, SocioCPF)
	FK(SocioCPF) ref Socio(CPF)
	PK(Nome, SocioCPF)
```
## Relacionamentos Binários 1:1
![[rel11.png]]
1. Criar uma FK na relação com participação total (*Todo departamento tem funcionário*)
```
Funcionário (Nome, CPF)
	PK(CPF)
Departamento (Nome, Local, GerenteCPF)
	FK(GerenteCPF) ref Funcionário(CPF)
	PK(Nome)
```
## Relacionamentos Binários 1:N
![[rb1n.png]]
1. Criar uma FK na relação com cardinalidade N
```SQL
Funcionário (Nome, CPF, ProjetoNome)
	PK(CPF)
	FK(ProjetoNome) ref Projeto(Nome)
Projeto (Nome)
	PK(Nome)
```
2. Criar todos os atributos do relacionamento, se houver
```SQL
Funcionário (Nome, CPF, ProjetoNome, DataInicial)
	PK(CPF)
	FK(ProjetoNome) ref Projeto(Nome)
Projeto (Nome)
	PK(Nome)
```
## Relacionamentos Binários N:N
![[rbnn.png]]
1. Criar um novo Relacionamento
```SQL
Autor (Nome)
	PK(Nome)

Livro (ISBN, Título)
	PK(ISBN)

Escreve ()
```
2. Criar FK das duas relações
```SQL
Autor (Nome)
	PK(Nome)

Livro (ISBN, Título)
	PK(ISBN)

Escreve (AutorNome, LivroISBN)
	FK(AutorNome) ref Autor(Nome)
	FK(LivroISBN) ref Livro(ISBN)
```
3. Criar a PK (FK1 + FK2)
```SQL
Autor (Nome)
	PK(Nome)

Livro (ISBN, Título)
	PK(ISBN)

Escreve (AutorNome, LivroISBN)
	FK(AutorNome) ref Autor(Nome)
	FK(LivroISBN) ref Livro(ISBN)
	PK(AutorNome, LivroISBN)
```
## Atributos Multivalorados
![[am.png]]
1. Criar uma nova relação: `Telefone ()`
2. Criar Atributo(s) Simples: `Telefone (Telefone)` 
3. Cria FK para a relação original
```
Aluno(CPF, Nome, Endereço)
	PK(CPF)

Telefone(Telefone, AlunoCPF)
	FK(AlunoCPF) ref Aluno(CPK)
```
4. Criar PK (FK + Atributos)
```
Aluno(CPF, Nome, Endereço)
	PK(CPF)

Telefone(Telefone, AlunoCPF)
	FK(AlunoCPF) ref Aluno(CPF)
	PK(Telefone, AlunoCPF)
```
## Relacionamentos N-ários, N>2
![[rn.png]]
1. Criar uma nova relação `Trabalha ()`
2. Criar Atributo(s) simples 
3. Criar FK para todas as relações
```
Funcionário (CPF, Nome) 
	PK(CPF)

Cargo (Nome) 
	PK(Nome)

Projeto (Código, Descrição) 
	PK(Código)

Trabalha (FCPF, CNome, PCódigo)
	FK(FCPF) ref Funcionário(CPF)
	FK(CNome) ref Cargo(Nome)
	FK(PCódigo) ref Projeto(Código)
```
4. Criar PK com todas as relações que não sejam 1
```
Funcionário (CPF, Nome) 
	PK(CPF)

Cargo (Nome) 
	PK(Nome)

Projeto (Código, Descrição) 
	PK(Código)

Trabalha (FCPF, CNome, PCódigo)
	FK(FCPF) ref Funcionário(CPF)
	FK(CNome) ref Cargo(Nome)
	FK(PCódigo) ref Projeto(Código)
	PK(FCPF, PCódigo)
```
## Mapeamento de Heranças
![[mph.png]]
### Partição Única
```
Veículo (Placa, Combustível, Eixos, TipoVeículo*)
	PK(Placa)
```
### Particionamento Vertical
```
Veículo (Placa) 
	PK(Placa)

Carro (Combustível, VeículoPlaca)
	FK(VeículoPlaca) ref Veículo(Placa)
	PK(VeículoPlaca)

Caminhão (Eixos, VeículoPlaca)
	FK(VeículoPlaca) ref Veículo(Placa)
	PK(VeículoPlaca)
```
## Particionamento Horizontal
```
Carro (Combustível, Placa)
	PK(Placa)

Caminhão (Eixos, Placa)
	PK(Placa)
```
# Modelo Físico
## SQL - Struct Query Language
### Tipos de Dados
Numérico (principais):
	• integer/int, float, real, numeric(p,n)
Cadeia de caracteres:
	• char(n), varchar(n), text
Dados binários:
	• blob
Data/tempo:
	• date, datetime, timestamp, time, year
Booleano:
	• bool, boolean, tinyint(1)
### Criando Banco de Dados
```SQL
create database nome_db
--ou
create schema nome_db
```
### Criando Tabela
```SQL
create table r (A1 D1, A2 D2, ..., An Dn,
(integrity-constraint1),
...,
(integrity-constraintk));
```
$r$ é o nome da relação
Cada $A_i$ é um nome de atributo no esquema da relação $r$
$D_i$ é o tipo de dados dos valores no domínio do atributo $A_i$
Exemplo:
```SQL
create table Departamento (Nome_Depto varchar(50), ID_Depto numeric(5,0) );
```
### Restrições de Integridade (RIs)

```SQL
-- Não Nulo
not null
-- Atributo(s) forma(m) uma chave candidata
unique(A1,...,An)
-- PK
primary key (A1, ..., An)
-- FK
foreign key (Am, ..., An) references r
```
Exemplo:
```SQL
create table Departamento (
	Nome_Depto varchar(50) not null,
	ID_Depto numeric(5,0),-------
	primary key (ID_Depto) ); -------

create table Professor (
	ID_Professor numeric(5,0),-------
	Nome varchar(50) not null,
	CPF char(11), -------
	Salario numeric(8,2),
	ID_Depto numeric(5,0),
	unique (CPF), -------
	primary key (ID_Professor), -------
	constraint fk_depto_prof foreign key (ID_Depto) references Departamento(ID_Depto) );
	-- foreign key (ID_Depto) references Departamento(ID_Depto) );
```

### Drop table
```SQL
drop table r
```

### Alterar Tabela
```SQL
alter table r add A D
-- Onde A é o nome do atributo a ser adicionado na relação r e D é o domínio de A
-- Todas as tuplas na relação são associados valores nulos como valor do novo atributo
alter table r drop A
-- Onde A é o nome do atributo da relação r a ser removido
-- Remoção de atributos não é suportado por muitos SGBDs
```
Exemplo
```SQL
create table Departamento (
	Nome_Depto varchar(50),
	ID_Depto numeric(5,0) );

alter table Departamento add Data_criacao date;

alter table Departamento add primary key (ID_Depto);

alter table Departamento drop primary key;
```

```SQL
create table Professor (
		ID_Professor numeric(5,0),
		Nome varchar(50) not null,
		CPF char(11),
		Salario numeric(8,2),
		ID_Depto numeric(5,0),
		unique (CPF),
		primary key (ID_Professor));

alter table Professor add constraint fk_depto_prof foreign key (ID_Depto) references Departamento(ID_Depto);

alter table Professor drop foreign key fk_depto_prof; 
```
### Restrições de atributos e domínios
```SQL
not null
default <valor>
check <condição>
```
Exemplo
```SQL
ID_Depto int not null
check (ID_Depto>0 and ID_Depto<=99999)

semestre varchar(6) default 'Summer' check (semestre in ('Fall', 'Winter','Spring', 'Summer'));

create domain D_NUM as integer
check (D_NUM > 0 and D_NUM < 21);
ID_Depto D_NUM not null;
```
### Restrições de integridade referencial
```SQL
-- Remoção
on delete
cascade (propagação)
set null (substituição por nulos)
set default (substituição por um valor default)
-- Opção default: bloqueio (restrict)

-- As mesmas opções se aplicam à cláusula 
on update (alteração)
```
### Select
```SQL
select A1, A2, ..., An
from r1, r2, ..., rm
where P

-- Ai representa um atributo
-- ri representa uma relação
-- P é um predicado

select * from r
-- * denota todos os atributos 
-- r representa uma relação

```
### Modificações do banco de dados
```SQL
insert -- inserir

insert into Departamento 
values ('Departamento de Informática', 21);

insert into Professor (Nome, CPF, ID_Professor)
values ('Costa', 33333333333, 3);

--
update -- alterar

update Professor
set Salario=10000, ID_Depto=21
where ID_Professor=3;

update Professor
set Salario=Salario*1.1
where ID_Depto in (select ID_Depto from Departamento
where Nome_Depto='Departamento de Informática');

--
delete -- remover

delete from Professor;

delete from Professor where ID_Professor=3;

delete from Professor where ID_Depto in
(select ID_Depto from Departamento
where Nome_Depto='Departamento de Informática');
```

## Normalização

![[normalização.png]]
### 0FN ou ÑN
Uma relação está na 0FN se ela apresentar algum atributo não atômico
![[0FN.png]]
### 1FN
Uma relação está na 1FN se todos os seus atributos forem atômicos
![[1FN.png]]
### 2FN
Uma relação está na 2FN se ela estiver na 1FN e se ela **não** apresentar dependências funcionais (DFs) parciais da chave
	Parcial = "de uma parte"
![[2fn_1.png]]
![[2fn_2.png]]
### 3FN
Uma relação está na 3FN se ela estiver na 2FN e se ela **não** apresentar dependências funcionais (DFs) transitivas da chave
![[3fn.png]]![[3fn_2.png]]
### Resumo 
![[normalizar.png]]
# Álgebra Relacional

## Operações Básicas
### Seleção $\sigma$
Seleciona a partir da relação de entrada R, tuplas (linhas) que satisfazem a um determinado predicado:
$$
\sigma_{predicado}(R)
$$
Predicados permitem expressar comparações do tipo: ${=,<, ≤,>, ≥, ≠}$
Pode-se relacionar comparações com operadores lógicos (and, or, not): ${∧,∨, ¬}$
$$
\begin{matrix}
\sigma_{\text{ID\_Depto=17}}(Professor) \\ \sigma_{\text{ID\_Depto=21 ∧ Salario>9000}(Professor)}
\end{matrix}
$$
### Projeção $\Pi$
Copia as colunas das relações de entrada R
$$
\Pi_{\text{col1,col2,col3}}(Tabela)
$$
Exemplo:
$$
\Pi_\text{Nome, Salario}(Professor)
$$
### Produto Cartesiano $\times$
Concatena cada tupla de $R_1$ com todas as tuplas de $R_2$
$$
R_{1}\times R_2
$$
(Cada elemento de $R_1$ será associado a todos os elementos de $R_2$)
Exemplo:
![[produto_cartesiano.png]]
### Renomeação $\rho$
