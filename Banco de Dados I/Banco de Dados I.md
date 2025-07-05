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
### Junção Natural $\bowtie$
Junção forçando a igualdade naqueles atributos que são comuns a $R_1$ e $R_2$ (mesmo 
nome e domínio nas duas relações)
$$
R_{1}\bowtie R_2
$$
### Junção Theta $\bowtie_{\theta}$
Operação binária que combina o produto cartesiano e a seleção em uma única operação
$$
R_{1}\bowtie_{\theta}R_{2} = \sigma_{\theta}(R_{1}\times R_2)
$$
A condição de junção é geralmente da forma
$$
<cond_1> ∧ <cond_2> ∧ ... ∧ <cond_n>
	$$
	onde \<condi\> é uma expressão A θ B, sendo A um atributo de $R_1$ , B um atributo de $R2$ e θ um dos operadores de comparação {=,<, ≤,>, ≥, ≠}
### Renomeação $\rho$
![[renomeação.png]]![[renomeação2.png]]
### Atribuição $\leftarrow$ / $=$
![[atribuicao.png]]
## União $\cup$
$$
\sqcap_{\text{nome\_{coluna}}\hspace{0.2cm}(\text{Tabela 1})} \cup \sqcap_{\text{nome\_{coluna}}\hspace{0.2cm}(\text{Tabela 2})}
$$
## Diferença $-$
$$
\sqcap_{\text{nome\_{coluna}}\hspace{0.2cm}(\text{Tabela 1})} - \sqcap_{\text{nome\_{coluna}}\hspace{0.2cm}(\text{Tabela 2})}
$$
## Intersecção $\cap$
$$
\sqcap_{\text{nome\_{coluna}}\hspace{0.2cm}(\text{Tabela 1})} \cap \sqcap_{\text{nome\_{coluna}}\hspace{0.2cm}(\text{Tabela 2})}
$$
$$
\def\ojoin{%
  \rule[-.02ex]{.25em}{.4pt}\llap{\rule[.45em]{.25em}{.4pt}}}
\def\leftouterjoin{\mathbin{\ojoin\mkern-5.8mu\bowtie}}
\def\rightouterjoin{\mathbin{\bowtie\mkern-5.8mu\ojoin}}
\def\fullouterjoin{\mathbin{\ojoin\mkern-5.8mu\bowtie\mkern-5.8mu\ojoin}}
$$
## Junção Externa (Outer Join) 
Computa a junção e então adiciona tuplas extras formadas por uma relação que não casam com tuplas na outra relação no resultado da junção
- Usa valores `null`:
### Left Outer Join ⟕
$$
\text{Tabela 1} \leftouterjoin \text{ Tabela 2}
$$
### Right Outer Join ⟖
$$
\text{Tabela 1 ⟖ Tabela 2} 
$$
### Full Outer Join
$$
\text{Tabela 1 ⟗ Tabela 2}
$$
## Divisão $\div$ 
Dadas as relações $r(R)$ and $s(S)$ tais que $S\subset R$
-  R e S são os esquemas da relações r e s, respectivamente
$r\div s$ é a maior relação $t(R-S)$ tal que
$$t\times s \underline{\subset}r$$
$$
r\div s= \sqcap_{\text{R-S}}(\text{r})-\sqcap_{\text{R-S}}(((\sqcap_{\text{R-S}}(\text{r}))\times s)-r) 
$$
Onde R-S são as colunas únicas de $r$ (que não estão em $s$)
A operação divisão é apropriada para consultas que incluem a expressão "para todo"

_Exemplo_: listar os nomes de todos os clientes que têm conta em todas as agências de Niterói
$$
r\div s = \sqcap_{\text{nome\_cliente,cod\_{agencia}}}(\text{Cliente $\bowtie$ Conta}) \div \sqcap_{\text{cod\_agencia}}(\sigma_{\text{cidade='Niterói'}}(\text{Agencia}))
$$
## Agregação $\gamma$
Operação de álgebra relacional estendida, permite a utilização de funções agregadas sobre conjuntos de valores
$$
G_1,G_2,\dots\gamma F_1(A_{1),}F_2(A_2),\dots
$$
Onde:
- $G_n$ é uma lista de de atributos em cada grupo
- $F$ é uma função de agregação
	- avg
	- min
	- max
	- sum
	- count
	- count-distinct
- $A_i$ é um nome de atributo
_Exemplo_: Listar média dos salários dos professores por Departamento (ID_Depto)
$$
\text{ID\_Depto}\hspace{5px}\gamma_\text{avg(Salario)} (\text{Professor})
$$
# SQL - Consultas
## `Select`
```sql

select A1, A2, ...
from tabela
where P
```
- `distinct` - remove duplicatas
- `select *` - retorna todos atributos (colunas)
- Pode conter expressões aritméticas: $+, -, *, \text{ e } /$ operando em constantes ou atributos das tuplas
Equivalente ao $\sqcap_{\text{Nome}}(Professor)$ na álgebra relacional
## `From`
A cláusula `from` lista as relações envolvidas na consulta
Equivalente ao $\text{Tabela 1} \times \text{Tabela 2}$ na álgebra relacional
```sql
select *
from Professor, Departamento
```
Gera cada possível par professor – departamento, com todos atributos de ambas relações
## `Where`
A cláusula where especifica condições que o resultado deve satisfazer
	Resultados de comparação podem ser combinados usando conectivos lógicos: `and`, `or` e `not`
Corresponde ao predicado $\sigma_{\text{salario}>7000}(Professor)$da seleção de álgebra relacional
```sql
select *
from Professor
where salario > 7000
```
## `Natural Join`
```sql
select Nome
from Professor natural join Departamento
where Salario>9000 and Nome_Depto='Departamento de Informática'
```
## Renomeação - `AS`
SQL permite renomear relações e atributos usando a cláusula `AS`
```sql
old_name AS new_name
```
Para renomear pode-se omitir a palavra-chave `as`
```sql
old_name new_name
```
_Exemplo_:
```sql
select Nome, Salario*12 as Salario_Anual
from Professor
```
## Operações com strings - `LIKE`
Operador like para casamento de strings utilizando padrões descritos com o uso de
caracteres especiais:
%: casa com qualquer substring
 \_: casa com qualquer caracter
 
 _Exemplo_: Encontrar os nomes de todos os departamentos cujo nome inclui a substring “ica”
```sql
select Nome_Depto
from Departamento
where Nome_Depto like '%ica%'
```
**Obs**: Casar string “100 %”
`like '100 \%`  - Usar o caracter de escape '\\'
## `Order By`
Ordenar tuplas no resultado
 - `desc` - decrescente
 - `asc` - crescente (DEFAULT)
```sql
-- Listar o nome de todos os professores em ordem alfabética
select distinct Nome
from Professor
order by Nome
-- Ordenar por multiplos atributos
order by ID_Depto desc, Nome
```
## Predicados da Cláusula `Where`
### `Between`
```sql
-- Operador de comparação de intervalos:
select Nome
from Professor
where Salario between 7000 and 9000
```
### Comparação de tuplas
```sql
select Nome
from Professor as P, Departamento as D
where (P.ID_Depto, Nome_Depto) =
(D.ID_Depto, 'Departamento de Informática')
```
## Junções
### Outer Joins
```sql
select * 
from Professor P left outer join Departamento D 
on P.ID_Depto=D.ID_Depto

select * from Professor natural left outer join Departamento

select * from Professor left outer join
Departamento using (ID_Depto)
```

![[Pasted image 20250626190512.png]]![[Pasted image 20250626190803.png]]
## Operações sobre conjuntos
- União: `union`
```sql
(select Nome_Curso from Graduacao) union (select Nome_Curso from PosGrad)
```
- Diferença: `except`
```sql
(select ID_Area from Graduacao) except (select ID_Area from PosGrad)
```
- Intersecção: `intersect`
```sql
(select ID_Area from Graduacao) intersect (select ID_Area from PosGrad)
```
Cada uma das operações automaticamente elimina duplicatas
Para reter todas as duplicatas, usar versão multisets: `union all`, `intersect all` e `except all`

# Aninhamento subconsultas
Uma subconsulta é uma consulta SQL aninhada dentro de outra consulta
- **Diferença**: Listar o identificador das áreas apenas com curso de graduação
```sql
select distinct ID_Area 
from Graduacao
where ID_Area not in (
	select distinct ID_Area from PosGrad
)
```
- **Intersecção**: Listar o identificador das áreas que possuem tanto cursos de graduação quanto de pós-graduação
```sql
select distinct ID_Area 
from Graduacao
where ID_Area in (
	select distinct ID_Area from PosGrad
)
```
# Funções de Agregração
- `avg`: média aritmética dos valores
```sql
select ID_Depto, avg(Salario)
from Professor
group by ID_Depto
```
- `min`: mínimo valor
- `max`: máximo valor
```sql
select max(Salario)
from Professor
```
- `sum`: soma de valores
- `count`: quantidade de valores
- `count (distinct ...)`: quantidade de valores distintos

## `Having`
Enquanto predicados na cláusula `where` são aplicados antes da formação dos grupos, predicados na cláusula `having` são aplicados depois da formação dos grupos
```sql
select ID_Depto, avg(Salario)
from Professor
group by ID_Depto
having avg(Salario) > 6000

-- OU

select ID_Depto, avg(Salario) as AvgSal
from Professor
group by ID_Depto
having AvgSal > 6000
```

# Comparação de Conjuntos
## `Some`
- $<$
- $<=$
- $>$
- $>=$
- $=$
- $<>$
Exemplo: Encontrar nomes dos professores com salário maior que algum (pelo menos um) professor do departamento com identificador igual a 21
```sql
select distinct T.Nome
from Professor as T, Professor as S
where T.Salario > S.Salario and S.ID_Depto=21

-- Mesma consulta usando cláusula > some
select distinct Nome
from Professor
where Salario > some (
	select Salario
	from Professor
	where ID_Depto=21
)
```

## All
-  `< all`
- `<= all`
- `> all`
- `>= all`
- `= all` (não é o mesmo que in)
- `<> all` (é idêntico a not in)
Exemplo: Encontrar nomes dos professores com salário maior que o salário de todos os professores do departamento com identificador igual a 17
```sql
select Nome
from Professor
where Salario > all (
	select Salario
	from Professor
	where ID_Depto=17
)
```

## Cardinalidade de conjunto:
O construtor `exists` retorna o valor `true` se a subconsulta argumento não é vazia
- `exists`
- `not exists`
Exemplo: Listar o identificador das áreas que possuem tanto cursos de graduação quanto de pós-graduação
```sql
select distinct ID_Area 
from Graduacao as G
where exists (
	select distinct ID_Area
	from PosGrad as P
	where P.ID_Area=G.ID_Area
)
```

# Subconsultas na cláusula `From`
Exemplo: Achar dentre todos os departamentos, o máximo do salário total (de algum dos departamentos)
```sql
select max(tot_salarios)
from (
	select ID_Depto, sum(Salario)
	as tot_salarios
	from Professor
	group by ID_Depto
) as total_deptos;
```

# `View`

```sql
create view v as <query expression>
```

Exemplo: Uma visão dos professores sem o seu salário
```sql
create view Cadastro_Prof as 
	select ID_Professor, Nome, CPF, ID_Depto
	from Professor
```
## Visões definidas usando outras visões
```sql
create view Prof_Depto (Prof, Depto) as
	select Nome, Nome_Depto
	from Professor natural join Departamento;

create view Prof_Depto_Letras (Nome) as
	select Prof
	from Prof_Depto
	where Depto='Departamento de Letras';
```
## Apagando visão
```sql
drop view v;
```
## Atualizando uma visão
Exemplo: Adicionar uma nova tupla na visão Cadastro_Prof definida anteriormente
```sql
insert into Cadastro_Prof values (6, 'Lopes','66666666666',21);
```

## Resumo
• Tabela virtual definida através de uma consulta
• Definição fica armazenada no catálogo
• Pode ser usada em um select
• Insert, update e delete com restrições
• Aninhamento permitido (visão sobre visão)
• Visões temporárias apenas para uso imediato em consultas, sem salvamento no catálogo

# Criando usuários em MySQL
```sql
create user 'novousuario'@'<host>' identified by 'password';
```
Exemplo:
```sql
create user 'joao'@'localhost' identified by '123456';

create user 'maria'@'localhost'identified by '654321';
```
# Removendo usuários
```sql
drop user 'maria'@'localhost';
```
# Especificação de autorizações em SQL
```sql
-- A declaração grant é usada para conferir autorização
grant <privilege list>
on <relation name* or view name>
to <user list>

-- *'nome da base de dados'.'nome da tabela'
```
## Privilégios
• `select`: permite acesso de leitura para uma relação, ou a habilidade de consultar usando a visão
• `insert`: a habilidade de inserir tuplas
• `update`: a habilidade de alterar usando a declaração update em SQL
• `delete`: a habilidade de remover tuplas
• `all privileges`: usada como uma forma abreviada para conceder todos os privilégios
```sql
show privileges;

grant select
on Departamento
to 'joao'@'localhost', 'maria'@'localhost';
```

A declaração `revoke` é usada para revogar autorização
```sql
revoke select
on Departamento
from 'joao'@'localhost', 'maria'@'localhost'
```
# Triggers
São ações especificadas pelos usuários, e que são executadas automaticamente quando ocorrer alguma operação que cause a modificação dos dados de uma tabela
```sql
CREATE
	[DEFINER = { user | CURRENT_USER }]
	TRIGGER trigger_name
	trigger_time trigger_event
	ON tbl_name FOR EACH ROW
	[trigger_order]
	trigger_body
	
-- trigger_time: { BEFORE | AFTER }
-- trigger_event: { INSERT | UPDATE | DELETE }
-- trigger_order: { FOLLOWS | PRECEDES } other_trigger_name
```
## Removendo gatilho
```sql
DROP TRIGGER trigger_name;
```
## Mostrando os gatilhos definidos:
```sql
SHOW TRIGGERS;
```
## Por Linha (`FOR EACH ROW`)
O código do Gatilho é executado a cada alteração em determinada linha
Variáveis especiais são criadas, dentre estas estão:
	`NEW`: refere-se aos valores associados a uma nova linha a ser inserida (`insert`) ou aos novos valores de uma linha já existente (`update`)
		Não aplicável em delete
	`OLD`: refere-se aos valores associados a uma linha que acabou de ser removida (`delete`) ou aos antigos valores de uma linha já existente (`update`)
		Não aplicável em `insert`
Exemplos: 
```sql
DELIMITER $$
CREATE TRIGGER Tgr_Venda_Insert
AFTER INSERT ON Venda
FOR EACH ROW
BEGIN
	UPDATE Produto SET Quant_Estoque = Quant_Estoque - NEW.Quant
	WHERE ID_Produto = NEW.ID_Produto;

CREATE TRIGGER Tgr_Venda_Delete
AFTER DELETE ON Venda
FOR EACH ROW
BEGIN
	UPDATE Produto SET Quant_Estoque = Quant_Estoque + OLD.Quant
	WHERE ID_Produto = OLD.ID_Produto;
END$$

CREATE TRIGGER Tgr_Controle_Estoque
BEFORE UPDATE ON Produto
FOR EACH ROW
BEGIN
	if NEW.Quant_Estoque < 0 then
		signal sqlstate '45000' set message_text = 'Nao ha produto suficiente em estoque para atender o pedido, venda nao pode ser realizada.';
	end if;

CREATE TRIGGER Tgr_Controle_Estoque
AFTER UPDATE ON Produto
FOR EACH ROW
BEGIN
	DECLARE qtd integer;
	select Quant_Estoque into qtd
	from Produto
	where ID_Produto=OLD.ID_Produto;
		if qtd < 0 then
			signal sqlstate '45000' set message_text = 'Nao ha produto suficiente em estoque para atender o pedido, venda nao pode ser realizada.';
		end if;
END$$


DELIMITER ;
```