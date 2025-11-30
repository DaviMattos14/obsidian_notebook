### 1. Dinâmica Newtoniana e Cinemática (O Básico)

**Foco:** Capítulos 2 e 3 da apostila. Questões de blocos, planos inclinados e movimento circular.

A Lógica de Resolução:

Sempre que o problema envolver forças, acelerações e movimento sem rotação complexa ou vínculos difíceis, use Newton.

**Passo a Passo Geral:**

1. **Desenhe o Diagrama de Corpo Livre:** Isole cada corpo e desenhe todas as forças (Peso, Normal, Tensão, Atrito).
    
2. **Defina os Eixos:** Escolha um sistema de coordenadas conveniente (ex: alinhado com o plano inclinado).
    
3. **Decomponha as Forças:** Se uma força não está nos eixos, decomponha em $F_x$ e $F_y$ usando seno e cosseno.
    
4. **Aplique a 2ª Lei:** $\vec{F}_{resultante} = m\vec{a}$ para cada eixo de cada corpo.
    
5. **Vínculos:** Se os corpos estão ligados (ex: corda), as acelerações se relacionam (ex: $a_1 = a_2$).
    

**Exemplo Chave (Prova 1 - Questão 1):** Bloco na mesa puxando outro pendurado.

- _Bloco na mesa:_ $T - F_{atrito} = ma$
    
- _Bloco pendurado:_ $Mg - T = Ma$
    
- _Resolução:_ Some as equações para eliminar $T$ e achar $a$.
    

---

### 2. Conservação de Energia e Momento Linear (O Atalho)

**Foco:** Capítulos 4 e 5. Questões de "antes e depois", colisões e alturas máximas.

A Lógica de Resolução:

Use quando o problema pede velocidades ou distâncias e não pede tempo ou aceleração, ou quando há choques.

**Técnica 1: Colisões (Prova 2 - Q2; Prova 3 - Q2)**

1. **Momento Linear ($\vec{p} = m\vec{v}$):** Sempre se conserva se não houver força externa horizontal.
    
    - $p_{antes} = p_{depois} \Rightarrow m_1v_{1i} + m_2v_{2i} = m_1v_{1f} + m_2v_{2f}$.
        
2. **Tipo de Colisão:**
    
    - _Inelástica (grudam):_ $v_{1f} = v_{2f}$. Energia **não** conserva.
        
    - _Elástica (batem e voltam):_ Energia Cinética se conserva ($K_i = K_f$).
        
    - _Dica de Ouro para Elástica:_ Use a relação de velocidade relativa: $v_{1i} - v_{2i} = -(v_{1f} - v_{2f})$.
        

**Técnica 2: Energia Mecânica ($E = T + V$)**

1. **Identifique:** $T = \frac{1}{2}mv^2$ (Cinética) e $V = mgh + \frac{1}{2}kx^2$ (Potencial Gravitacional + Elástica).
    
2. **Conserva?** Se não tem atrito, $E_{inicial} = E_{final}$.
    
3. **Aplicação:** Se um bloco desce uma rampa e comprime uma mola (Prova 1 - Q4), toda a $V_{grav}$ inicial vira $V_{elástica}$ final (com $T=0$ nos extremos).
    

---

### 3. Rotação e Momento Angular (O Avançado)

**Foco:** Capítulo 6 e 8. Ioiôs, barras girando, torque.

A Lógica de Resolução:

Agora os corpos têm dimensão. A massa não é um ponto. Eles giram.

**Passo a Passo:**

1. **Identifique o Eixo:** Onde o corpo está girando? (No centro de massa ou num pivô fixo?).
    
2. **Momento de Inércia ($I$):** É a "massa" da rotação.
    
    - _Barra pelo centro:_ $I = \frac{1}{12}ML^2$.
        
    - _Cilindro/Disco:_ $I = \frac{1}{2}MR^2$.
        
    - _Partícula a distância $R$:_ $I = mR^2$.
        
    - _Teorema dos Eixos Paralelos:_ Se girar fora do centro de massa: $I_{novo} = I_{CM} + Md^2$.
        
3. **Torque ($\tau$):** É a "força" da rotação. $\tau = \text{Força} \times \text{Braço de Alavanca}$.
    
4. **Leis de Newton para Rotação:**
    
    - $\tau_{res} = I\alpha$ (analoga a $F=ma$).
        
    - $\vec{L} = I\vec{\omega}$ (Momento Angular).
        
5. **Conservação do Momento Angular ($L$):** Se o Torque externo for zero, $L_{antes} = L_{depois}$.
    
    - _Exemplo (Prova 2 - Q1):_ Uma bala bate numa barra. $L_{bala} = L_{sistema}$.
        
    - $m v r = I_{total} \omega$.
        

---

### 4. Equações de Lagrange (A Ferramenta Suprema)

**Foco:** Capítulo 7. Resolve problemas complexos de forma elegante, sem vetores de força.

A Receita Infalível (Passo a Passo):

Esta técnica resolve quase todas as questões difíceis (Ioiô, conta no arame, bloco na cunha).

1. **Escolha as Coordenadas Generalizadas ($q$):** As variáveis mínimas para descrever o movimento (ex: $x$, $\theta$, $s$).
    
2. **Defina a Energia Cinética ($T$):**
    
    - $T = \frac{1}{2}mv^2 + \frac{1}{2}I\omega^2$ (Translação + Rotação).
        
    - _Atenção:_ Escreva $v$ e $\omega$ em função das coordenadas $q$ e suas derivadas $\dot{q}$. Use geometria se necessário (ex: $v^2 = \dot{x}^2 + \dot{y}^2$).
        
3. **Defina a Energia Potencial ($V$):**
    
    - Escolha o nível zero ($y=0$). Tudo acima é positivo, abaixo é negativo. $V = mgh$.
        
4. **Monte o Lagrangiano:** $\mathcal{L} = T - V$.
    
5. Aplique a Equação de Euler-Lagrange:
    
    $$\frac{d}{dt} \left( \frac{\partial \mathcal{L}}{\partial \dot{q}} \right) - \frac{\partial \mathcal{L}}{\partial q} = 0$$
    
    - Faça isso para cada coordenada $q$.
        

**Exemplo Prático (Prova 3 - Q3 - Ioiô):**

- $T = \frac{1}{2}m\dot{y}^2 + \frac{1}{2}I\dot{\theta}^2$.
    
- Vínculo: $y = R\theta \Rightarrow \dot{y} = R\dot{\theta}$. Substitua para ter só uma variável.
    
- $V = -mgy$ (se $y$ cresce para baixo).
    
- $\mathcal{L} = T - V$. Aplique a derivada.
    

---

### Resumo das Fórmulas Essenciais

| **Conceito**          | **Fórmula**                                                                                             | **Onde Usar**                |
| --------------------- | ------------------------------------------------------------------------------------------------------- | ---------------------------- |
| **2ª Lei de Newton**  | $\vec{F} = m\vec{a}$                                                                                    | Translação simples.          |
| **Energia Cinética**  | $K = \frac{1}{2}mv^2 + \frac{1}{2}I\omega^2$                                                            | Corpos em movimento/rotação. |
| **Energia Potencial** | $U = mgh + \frac{1}{2}kx^2$                                                                             | Altura e Molas.              |
| **Momento Linear**    | $\vec{p} = m\vec{v}$                                                                                    | Colisões.                    |
| **Momento Angular**   | $L = I\omega$ ou $\vec{r} \times \vec{p}$                                                               | Rotação, Colisão com barra.  |
| **Torque**            | $\tau = r F \sin\theta = I\alpha$                                                                       | Causar rotação.              |
| **Lagrangiano**       | $\mathcal{L} = T - V$                                                                                   | Sistemas complexos/vínculos. |
| **Eq. de Lagrange**   | $\frac{d}{dt}(\frac{\partial \mathcal{L}}{\partial \dot{q}}) = \frac{\partial \mathcal{L}}{\partial q}$ | Obter eq. do movimento.      |

---

### **Questão 1: Dinâmica com Força Variável no Tempo**

**Tópico:** Leis de Newton e Cinemática (Capítulo 3 da Apostila).

Esta questão testa se você sabe sair da aceleração para chegar na posição através da integração.

#### **A "Receita" para resolver qualquer problema desse tipo:**

1. Escreva a Equação Fundamental (Cap 3, Seção 4):
    
    A base é sempre $F = ma$ ou $F = m\ddot{x}$.
    
    - Se a força depende do tempo $F(t)$, a equação fica $m\ddot{x}(t) = F(t)$.
        
2. Integre para achar a Velocidade ($\dot{x}$):
    
    A aceleração $\ddot{x}$ é a derivada da velocidade. Para voltar, integre:
    
    $$\dot{x}(t) = \int \frac{F(t)}{m} dt + v_0$$
    
    (Não esqueça da constante de integração $v_0$, que é a velocidade inicial).
    
3. Integre para achar a Posição ($x$):
    
    A velocidade $\dot{x}$ é a derivada da posição. Integre novamente:
    
    $$x(t) = \int \dot{x}(t) dt + x_0$$
    
4. Condições de Parada (Cinemática):
    
    Se o problema envolve parar em uma rampa (como no item c), use a conservação de energia ou a dinâmica com força constante (peso). Na rampa, a força que "freia" é a componente do peso: $F_{res} = -mg \sin(\theta)$.
    

**No contexto da Prova:**

- A força era $F=6t$. Integrando $\rightarrow$ Aceleração $\propto t$ $\rightarrow$ Velocidade $\propto t^2$ $\rightarrow$ Posição $\propto t^3$.
    

---

### **Questão 2: Colisões e Conservação**

**Tópico:** Momento Linear e Colisões (Capítulo 4, Seção 4, e Capítulo 5, Seção 4).

Aqui você precisa distinguir quando a energia se conserva e quando apenas o momento se conserva.

#### **A "Receita" para Colisões:**

1. **Identifique o Tipo de Colisão:**
    
    - **Inelástica (Plástica):** Os corpos grudam ou deformam. **A Energia Cinética NÃO se conserva**.
        
    - **Elástica:** Os corpos batem e voltam sem deformação permanente. **A Energia Cinética SE conserva**.
        
2. Aplique a Conservação do Momento Linear (Sempre Válida):
    
    (A menos que haja forças externas horizontais).
    
    $$P_{antes} = P_{depois} \implies m_1 v_{1i} + m_2 v_{2i} = m_1 v_{1f} + m_2 v_{2f}$$
    
    - _Dica da apostila (pág. 63):_ $F = dp/dt$. Se $F=0$, $p$ é constante.
        
3. Se a colisão for Elástica (item b da prova):
    
    Você ganha uma segunda equação: a Conservação da Energia Cinética.
    
    $$\frac{1}{2}m_1 v_{1i}^2 + \frac{1}{2}m_2 v_{2i}^2 = \frac{1}{2}m_1 v_{1f}^2 + \frac{1}{2}m_2 v_{2f}^2$$
    
    - _Truque Matemático:_ Em colisões elásticas unidimensionais, a velocidade relativa se inverte: $(v_{1i} - v_{2i}) = -(v_{1f} - v_{2f})$. Isso simplifica muito a álgebra (ver pág. 85 da apostila).
        

---

### **Questão 3: Dinâmica de Rotação (O Ioiô)**

**Tópico:** Momento Angular e Torque (Capítulo 6).

Este problema combina o movimento de queda (translação) com o movimento de giro (rotação).

#### **A "Receita" para Corpos Rígidos (Translação + Rotação):**

1. **Separe os Movimentos:**
    
    - **Translação (Centro de Massa):** Use Newton padrão. $\sum F = m\ddot{y}$.
        
        - Forças típicas: Peso ($P=mg$) e Tensão ($T$).
            
    - **Rotação (Em torno do Eixo):** Use a versão rotacional de Newton. $\sum \tau = I\ddot{\theta}$.
        
        - $\tau$ (Torque) = Força $\times$ Braço de Alavanca (pág. 93 da apostila).
            
        - $I$ (Momento de Inércia): Consulte a tabela na pág. 107. Para cilindro, $I = \frac{1}{2}mR^2$.
            
2. Identifique o Vínculo (O "Pulo do Gato"):
    
    Se o fio não desliza, existe uma relação fixa entre o quanto o objeto desce ($y$) e o quanto ele gira ($\theta$).
    
    $$y = R\theta \implies \dot{y} = R\dot{\theta} \implies \ddot{y} = R\ddot{\theta}$$
    
    (Isso está explicado na pág. 105 da apostila, Teorema 4.1).
    
3. Resolva o Sistema:
    
    Você terá um sistema de 3 equações:
    
    1. $mg - T = m\ddot{y}$ (Translação)
        
    2. $T \cdot R = I \ddot{\theta}$ (Rotação - note que o peso não gera torque no centro)
        
    3. $\ddot{y} = R\ddot{\theta}$ (Vínculo)
        

---

### **Questão 4: Mecânica Lagrangiana (Corrente na Mesa)**

**Tópico:** Equações de Lagrange (Capítulo 7).

A Lagrangiana é perfeita para sistemas onde a geometria muda (como uma corrente escorregando), pois evita lidar com forças vetoriais complicadas.

#### **A "Receita" de Lagrange (Passo a Passo):**

1. Defina a Coordenada Generalizada ($q$):
    
    Escolha uma variável que define todo o sistema. Na prova, foi $y$ (o comprimento da corrente pendurada).
    
2. Encontre a Energia Cinética ($T$):
    
    Geralmente é $\frac{1}{2}M v^2$.
    
    - _Atenção:_ Mesmo que a corrente dobre a esquina, a corrente **inteira** se move com a mesma velocidade escalar $\dot{y}$. Logo, $T = \frac{1}{2} (\text{massa total}) \dot{y}^2$.
        
3. Encontre a Energia Potencial ($V$):
    
    Aqui está a pegadinha. Você deve somar a energia potencial de cada parte.
    
    - Parte na mesa: Se a mesa for o nível zero ($h=0$), então $V=0$.
        
    - Parte pendurada: Tem comprimento $y$ e massa proporcional ($\frac{y}{L}M$). Onde está o centro de massa dessa parte pendurada? No meio dela ($y/2$ abaixo da mesa).
        
    - Logo, $V = (\text{massa pendurada}) \cdot g \cdot (-y/2)$.
        
4. Monte a Lagrangiana ($\mathcal{L}$):
    
    $$\mathcal{L} = T - V$$
    
    (Capítulo 7, Seção 1).
    
5. Aplique a Equação de Euler-Lagrange:
    
    $$\frac{d}{dt} \left( \frac{\partial \mathcal{L}}{\partial \dot{y}} \right) - \frac{\partial \mathcal{L}}{\partial y} = 0$$
    
    Isso resultará na equação diferencial do movimento.
    

### **Resumo para Estudo Rápido:**

- **Forças:** Desenhe o diagrama de corpo livre. Se $F$ depende do tempo, integre.
    
- **Colisões:** Conservação de Momento ($P$) é lei. Energia ($K$) só se for elástica.
    
- **Rotação:** $F=ma$ para mover o centro, $\tau = I\alpha$ para girar em torno do centro. Use $a = R\alpha$ para conectar os dois.
    
- **Lagrange:** Energia Cinética ($T$) - Energia Potencial ($V$). Derive em relação à velocidade e à posição.
# ✅ **1. Como resolver qualquer exercício com Equação Fundamental da Dinâmica**

**(Capítulo 3 da apostila, especialmente Seções 1, 4 e 5)**

### **Passo 1 — Identifique todas as forças reais que atuam no corpo**

Só entram forças reais:

- peso ( mg )
    
- normal
    
- tensão
    
- mola: ( $-kx$ )
    
- empurrões externos
    
- atrito ( $-\mu N$ ) (quando não ignorado)
    

👉 _Nunca esqueça_: se o problema for 1D, basta usar o sinal correto (positivo ou negativo) conforme a direção.

---

### **Passo 2 — Projete as forças na direção do movimento**

Exemplos:

- Objeto na rampa → use seno e cosseno
    
- Movimento vertical → peso é negativo
    

---

### **Passo 3 — Use a equação fundamental**

  
$$
mx'' = \sum F  
$$

E isso **gera uma equação diferencial**, que quase sempre é um dos tipos abaixo:

### **a) Movimento acelerado**

$$
mx'' = A \quad \Longrightarrow \quad x(t)=x_0+v_0 t + \frac{A}{2m} t^2  
$$

### **b) Força variável**

Ex.: ( $6t$ ), ( $e^t$ ), ( $x^2$ ), etc.  
👉 **Integre uma vez** para achar velocidade  
👉 **Integre outra vez** para achar posição

### **c) Movimento harmônico**

$$
mx'' = -kx \quad\Longrightarrow\quad x(t)=c_1\cos(\omega t)+c_2\sin(\omega t)  $$
  
$$
\omega = \sqrt{\frac{k}{m}}  
$$

### **Como achar constantes?**

Use condições iniciais:

- $(x(0))$
    
- $(x'(0))$
    

---

# ✅ **2. Como resolver qualquer exercício com Energia**

**(Capítulo 5: energia cinética, potencial e colisões)**

### **Energia cinética**

- Corpo translacional:  
$$  
    T = \frac12 mv^2  
$$
    
- Disco/cilindro/roldana:  
    $$ 
    T = \frac12 I\omega^2  
$$  
    com ( $I = \frac12 mR^2$ ) para disco.
    

---

### **Energia potencial**

- Gravidade:  

    $$V = mgy  $$

    
- Mola:  
   
    $$V = \frac12 kx^2$$  

    

---

### **Conservação da Energia**

Se não há forças dissipativas:  
 
$$T_i + V_i = T_f + V_f$$  
Usado para:

- pêndulo
    
- objetos na rampa
    
- molas
    
- ioiô
    
- corrente que desliza
    

---

# ✔️ Aplicação fundamental: **colisões**

- **Comum 1**: conservação do momento  
    
    $$m_1v_1+m_2v_2 = \text{constante}  $$
    
- **Comum 2 (elástica)**: também conserva energia cinética
    

---

# ✅ **3. Como resolver exercícios de Momento Linear**

**(Capítulo 4)**

O momento linear é:  

$$p = mv $$ 
E a lei fundamental:  

$$F = \dot p  $$

Útil quando:

- massa muda com o tempo (foguete)
    
- há colisões
    
- há dois corpos ligados por fio, roldana, etc.
    

---

# ✅ **4. Como resolver exercícios que envolvem Momento Angular / Torque**

**(Capítulo 6)**

### **Momento angular**:


$$L = I\omega  $$


### **Torque**:

$$\tau = I\alpha  $$

### **Relação entre movimento linear e angular**

Quando a corda não desliza:  
$$v = R\omega,\qquad a = R\alpha  $$


Toda vez que aparece:

- ioiô
    
- roldana
    
- cilindro
    
- corpo rolando sem deslizar
    

Você sempre usa:  
  
$$
\begin{cases}  
my'' = \text{forças} \\  
I\alpha = \tau \\  
\alpha = \frac{y''}{R}  
\end{cases}  
$$

---

# ✅ **5. Como resolver QUALQUER questão com Lagrange**

**(Capítulo 7)**

### **Passo 1 — escolha uma coordenada generalizada ( q )**

Pode ser:

- distância percorrida ( x )
    
- ângulo ( \theta )
    
- comprimento pendente ( y )
    

---

### **Passo 2 — escreva a energia cinética (T(q, \dot q))**

Se há rotação:  
[  
$$T = \frac12 mv^2 + \frac12 I\omega^2$$  
]

Se há fio:  
[  
$$v = \dot q,\quad \omega = \frac{\dot q}{R}  $$
]

---

### **Passo 3 — escreva a energia potencial (V(q))**

Use centro de massa sempre.

---

### **Passo 4 — lagrangiano**

[  
$$L = T - V$$  
]

---

### **Passo 5 — equação de Lagrange**

[
$$\frac{d}{dt}\Big(\frac{\partial L}{\partial \dot q}\Big)  
= \frac{\partial L}{\partial q}  $$


Isso gera uma equação diferencial.

---

### **Passo 6 — resolva a equação**

Quase sempre vira um destes:

#### **a) Acelerado linear**

[  
$$\ddot q = \text{constante}$$  
]

#### **b) Harmônico**

[  
$$\ddot q + \omega^2 q = 0$$  
]

#### **c) Exponencial**

[  
$$\ddot q = C q  
\Rightarrow q(t)=c_1 e^{\lambda t}+c_2 e^{-\lambda t}$$  
]

---

# ▶️ **6. Quando usar cada método**

|Situação|Método certo|
|---|---|
|forças explícitas|Equação fundamental|
|não há atrito e há alturas/molhas|Energia|
|objetos com rotação (roldana/yo-yo)|Torque + (a = R\alpha)|
|movimentos complicados / vários corpos|Lagrange|
|colisões|Momento linear|
|choque elástico|+ conservação de energia|

---

# 🎯 **7. Quer que eu te mostre como aplicar isso em um exercício específico?**

Posso te guiar _passo a passo_ usando **dicas e direções**, como você prefere.

Basta me enviar a questão que deseja entender.