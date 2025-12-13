# 🛡️ MAD: O Protocolo de Sobrevivência (Cheat Sheet)

## 1. Análise Operacional (O Jogo de Fluxo)

**Contexto:** Prova 1, Questão 5 (Balanceamento de Carga).

### O Ponto de Decisão: $N^*$

A primeira coisa a fazer é calcular o Ponto de Saturação. Ele define a tua estratégia.

$$N^* = \frac{D_{total} + Z}{D_{max}}$$

|**Cenário**|**Sintoma**|**O Inimigo**|**A Estratégia (Onde mexer no p)**|
|---|---|---|---|
|**Carga Pesada** ($N > N^*$)|Filas no gargalo.|**$D_{max}$** (Gargalo)|**Equilibrar Demandas:** Faça $D_2(p) = D_3(p)$. Reduza o teto máximo.|
|**Carga Leve** ($N < N^*$)|Sistema ocioso.|**$D_{total}$** (Soma)|**Minimizar Trabalho:** Encontre o $p$ que zera o caminho mais lento. Ignore o equilíbrio.|

**⚠️ Teu Ponto Cego:**

- Você hesitou na **Carga Leve**.
    
- **Correção:** Se não há fila, não importa se um servidor trabalha mais que o outro. Importa apenas a soma total do tempo de serviço. Se $D_{total} = 6p + 5$, o menor $p$ (0) ganha.
    

---

## 2. Cadeias de Markov (O Jogo de Estados)

**Contexto:** Prova 2, Questões 1, 2 e 4.

### DTMC (Discreta) vs. CTMC (Contínua)

A distinção onde você escorregou.

|**Conceito**|**DTMC (Passos)**|**CTMC (Tempo)**|
|---|---|---|
|**Tempo de Permanência**|1 passo (fixo).|$E[T] = 1/\theta_{saida}$ (Aleatório/Exponencial).|
|**Periodicidade**|Possível (ex: ping-pong 1-2-1).|**IMPOSSÍVEL**. O tempo é aleatório, não há "ritmo".|
|**Normalização**|$\sum \pi = 1$ (Sempre).|$\sum \pi = 1$ (Sempre).|

### Hierarquia da Estabilidade

1. **Irredutível:** Posso ir de qualquer lugar para qualquer lugar.
    
2. **Recorrente Positiva:** Se saio, volto em tempo finito.
    
3. **Aperiódica:** Não fico num ciclo previsível.
    
4. **Ergódica:** É o pacote completo (1 + 2 + 3).
    

**⚠️ Teus Pontos Cegos:**

- **Erro Crítico:** Achar que $\pi$ alto significa taxa $\theta$ alta.
    
    - **Verdade:** É o inverso. Se fico muito tempo ($\pi$ alto), é porque saio devagar ($\theta$ baixo).
        
- **Erro Crítico:** Confundir "Ter Limite" com "Ser Ergódica".
    
    - **Verdade:** Um estado absorvente tem limite (100%), mas não é ergódico (não volta).
        
- **Erro Crítico:** Achar que CTMC pode ser periódica. Não existe período em distribuição exponencial.
    

---

## 3. M/M/1 e Filas

**Contexto:** Prova 2, Questão 3.

### A Regra de Ouro da Simplificação

Não use a fórmula de $E[T_{fila}]$ a menos que seja obrigado. Ela é suja.

Use a relação aditiva:

$$Tempo_{Sistema} = Tempo_{Fila} + Tempo_{Serviço}$$

Se o enunciado pede $T_{fila} < 4$ e o serviço é $2$:

- Calcule para $T_{sistema} < 6$.
    
- Use a fórmula limpa: $E[T] = \frac{1}{\mu - \lambda}$.
    

---

## 4. Análise de Primeiro Passo & "Memoryless"

**Contexto:** Prova 2, Questão 4.

### O Sistema Linear ($E[T]$)

Para achar o tempo até a absorção:

$$E[T_{aqui}] = \text{Custo do Passo} + \sum (P_{vizinho} \times E[T_{vizinho}])$$

- Custo do passo em transições = 1.
    
- Custo do passo em tempo = $1/\Theta$.
    

### A Pegadinha do "Já passou 0,05s"

Se a distribuição é exponencial (Markoviana):

- **Passado:** Irrelevante.
    
- **Futuro:** A esperança reseta a cada instante.
    
- **Conclusão:** O tempo que _falta_ é sempre igual ao tempo médio original.
    

### A Pegadinha do Auto-Loop ($P_{ii} > 0$)

Se estou no estado 2, a taxa é 10, mas $P_{2,0}=0.5$ (sair) e $P_{2,2}=0.5$ (ficar).

- **Tempo por tentativa:** $0,1s$ (inverso da taxa 10).
    
- **Tentativas necessárias:** $1/p_{sucesso} = 1/0.5 = 2$.
    
- **Tempo Total para Sair:** $2 \times 0,1s = 0,2s$.
    

**⚠️ Teu Ponto Cego:**

- Você calculou intuitivamente certo ($1/5 = 0,2$), mas cuidado com a justificativa. O tempo físico do disparo do relógio (0,1s) não muda. O que muda é quantas vezes o relógio tem de disparar até você ter sorte de sair.
    

---

### Plano de Ação Final

1. **Revise as definições de V/F da Questão 1 (Prova 2).** Ali está a base teórica que derruba engenheiros que só sabem calcular.
    
2. **Treine o olho para $N^*$.** Antes de derivar ou otimizar qualquer sistema, pergunte: "Está cheio ou vazio?".
    
3. **Confie na propriedade Sem Memória.** Se o enunciado disser "dado que já esperou 100 anos", risque essa frase. Ela é ruído.
