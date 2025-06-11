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
# Exercício 3