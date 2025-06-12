> **Nome**: Davi dos Santos Mattos             **DRE**: 119133049

# Exercício 1
```
π Funcionario.Pnome, Funcionario.Minicial, Funcionario.Unome (σ Cpf_Supervisor = null (Funcionario))
∪
π Funcionario.Pnome, Funcionario.Minicial, Funcionario.Unome (
	σ Funcionario.Dnr ≠ Supervisor.Dnr (
		Funcionario 
			⨝ Funcionario.Cpf_Supervisor = Supervisor.Cpf 
		ρ Supervisor (Funcionario)
		)
)
```
# Exercício 2

```
projetos=   πProjeto.Projnome, Trabalha_em.Fcpf (
		Projeto ⨝ Projnumero = Pnr Trabalha_em)

nome_cpf = π Pnome, Minicial, Unome, Cpf (Funcionario)

Proj_Nome = πPnome,Minicial,Unome,Projnome(projetos ⨝ nome_cpf.Cpf = projetos.Fcpf nome_cpf)

prodX = πPnome,Minicial,Unome(σProjnome='ProdutoX'(Proj_Nome))
prodY = πPnome,Minicial,Unome(σProjnome='ProdutoY'(Proj_Nome))
prodZ = πPnome,Minicial,Unome(σProjnome='ProdutoZ'(Proj_Nome))
info = πPnome,Minicial,Unome(σProjnome='Informatizacao'(Proj_Nome))
reorg = πPnome,Minicial,Unome(σProjnome='Reorganizacao'(Proj_Nome))

((prodX ∩ prodY)-prodZ)∪(info-reorg)

```
# Exercício 3
```
-- Primeira Etapa: Achar o valor da média de salário do departamento 5
γ Dnr; avg(Salario)→Media (σ Dnr = 5 (Funcionario))


-- Segunda Etapa: 
media_salarios = γ Dnr; avg(Salario)→Media (Funcionario)

πDnome(σMedia > 33250 (
	media_salarios ⨝ Dnr = Dnumero Departamento
	)
)
```


