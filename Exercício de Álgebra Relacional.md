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

πProjeto.Projnome, Projeto.Dnum, Trabalha_em.Fcpf (
		Projeto ⨝ Projnumero = Pnr Trabalha_em)

nome_cpf = π Pnome, Minicial, Unome, Cpf (Funcionario)

proj_cpf = π Projeto.Projnome, Trabalha_em.Fcpf (
		Projeto ⨝ Projnumero = Pnr Trabalha_em
)

prodX = πFcpf(σProjnome='ProdutoX'(proj_cpf))
prodY = πFcpf(σProjnome='ProdutoY'(proj_cpf))
prodZ = πFcpf(σProjnome='ProdutoZ'(proj_cpf))

# Exercício 3