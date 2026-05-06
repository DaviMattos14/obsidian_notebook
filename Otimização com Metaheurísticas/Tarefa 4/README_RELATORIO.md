# Relatório: Algoritmo Evolutivo (Differential Evolution)

## Descrição

Este relatório em formato LNCS (Lecture Notes in Computer Science) documenta um estudo comparativo de diferentes estratégias de Differential Evolution para otimização contínua, aplicadas à função de Rosenbrock 2D.

## Conteúdo

- **relatorio_algoritmo_evolutivo.tex**: Documento principal em LaTeX
- **relatorio_algoritmo_evolutivo.bib**: Arquivo de referências BibTeX
- **llncs.cls**: Classe LaTeX para documentos LNCS
- **splncs04.bst**: Arquivo de estilo BibTeX para LNCS

## Compilação

### Pré-requisitos

- TeX Live ou MiKTeX (distribuição LaTeX completa)
- pdflatex e bibtex

### Instruções de Compilação

No Windows (PowerShell):

```powershell
# Navegue até o diretório
cd "c:\Users\Pichau\Documents\REPOSITÓRIOS\obsidian_notebook\Otimização com Metaheurísticas\Tarefa 4"

# Execute a compilação em ciclo
pdflatex -interaction=nonstopmode relatorio_algoritmo_evolutivo.tex
bibtex relatorio_algoritmo_evolutivo
pdflatex -interaction=nonstopmode relatorio_algoritmo_evolutivo.tex
pdflatex -interaction=nonstopmode relatorio_algoritmo_evolutivo.tex
```

### Resultado

O arquivo PDF será gerado como: `relatorio_algoritmo_evolutivo.pdf`

## Conteúdo do Relatório

### Seções Principais

1. **Introdução**: Contexto e motivação da otimização evolutiva
2. **Algoritmo Evolutivo**: Descrição de todas as 5 estratégias de DE
3. **Implementação**: Detalhes técnicos e pseudocódigo
4. **Experimentos e Resultados**: Configuração, tabelas e análise
5. **Comparação com PyMoo**: Validação contra biblioteca otimizada
6. **Análise e Conclusões**: Hierarquia de desempenho e recomendações

### Estratégias Analisadas

- DE/Rand/1/bin (Baseline aleatória)
- DE/Rand/2/bin (Dual randômica)
- DE/Best/1/bin (Melhor com uma diferença)
- DE/Best/2/bin (Melhor com duas diferenças)
- DE/Current-to-Best/1/bin (Híbrida)

### Resultados Principais

| Estratégia | Fitness Final (log10) | Ranking |
|---|---|---|
| DE/Best/1/bin | -19.2 | **1º (Melhor)** |
| DE/Rand/1/bin | -16.5 | 2º |
| DE/Current-to-Best/1/bin | -3.8 | 3º |
| DE/Best/2/bin | -3.2 | 4º |
| DE/Rand/2/bin | -1.8 | 5º (Pior) |

## Referências

O relatório contém referências bibliográficas completas em formato LNCS, incluindo trabalhos seminais de:
- Goldberg (Algoritmos Genéticos)
- Storn & Price (Differential Evolution original)
- Rosenbrock (Função benchmark)
- Das & Suganthan (Survey de DE)
- Price, Storn & Lampinen (Handbook de DE)

## Notebooks Relacionados

- `Algoritmo_Evolutivo.ipynb`: Implementação e experimentos em Python

## Autor

Davi S. Mattos
DRE: 119133049
Universidade Federal do Rio de Janeiro

## Notas

- O documento segue rigorosamente o formato LNCS de Springer
- Inclui algoritmos em pseudocódigo formatados corretamente
- Contém tabelas de resultados com estatísticas completas
- Análise crítica comparativa das estratégias
- Recomendações práticas de uso
