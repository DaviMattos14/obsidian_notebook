O foco aqui é o **"Pareto" (80/20)**: os conceitos que resolvem a maioria das questões das listas que você enviou. Vamos dividir por capítulos conforme as listas.

---

### 🎯 Estratégia para 2 Dias

- **Dia 1:** Domine Lagrange (Cap 7) e Forças/Cinemática (Cap 2 e 3). Lagrange é uma ferramenta poderosa que muitas vezes resolve problemas dos capítulos anteriores mais facilmente.
    
- **Dia 2:** Foco total em Rotação/Momento Angular (Cap 6) e revisão de Colisões (Cap 4/5).
    

---

### 📝 Capítulo 2: Vetores e Cinemática (Lista 1)

**Foco:** Descrever o movimento sem se preocupar com as causas (forças).

#### 1. Conceitos e Fórmulas Chave

- **Vetor Posição, Velocidade e Aceleração:**
    
    - $\vec{r}(t)$: Posição.
        
    - $\vec{v}(t) = \dot{\vec{r}}(t)$: Derivada primeira (velocidade)1.
        
    - $\vec{a}(t) = \ddot{\vec{r}}(t)$: Derivada segunda (aceleração).
        
- **Coordenadas Polares (Crucial para movimentos circulares/curvos):**
    
    - Base móvel: $\vec{u}_r$ (radial) e $\vec{u}_\theta$ (tangencial).
        
    - Posição: $\vec{r} = r\vec{u}_r$.
        
    - **Velocidade:** $\vec{v} = \dot{r}\vec{u}_r + r\dot{\theta}\vec{u}_\theta$.
        
    - **Aceleração:** $\vec{a} = (\ddot{r} - r\dot{\theta}^2)\vec{u}_r + (2\dot{r}\dot{\theta} + r\ddot{\theta})\vec{u}_\theta$.
        
        - _Nota:_ O termo $-r\dot{\theta}^2$ é a aceleração centrípeta. O termo $2\dot{r}\dot{\theta}$ é a aceleração de Coriolis.
            

#### 2. Técnicas para a Prova

- **Derivar vetores:** Se o vetor muda de direção (como em movimento circular), você deve usar a regra da cadeia. Lembre-se que $\dot{\vec{u}}_r = \dot{\theta}\vec{u}_\theta$ e $\dot{\vec{u}}_\theta = -\dot{\theta}\vec{u}_r$.
    
- **Trajetórias:** Para achar a equação da trajetória (ex: $y(x)$), isole $t$ em $x(t)$ e substitua em $y(t)$.
    

---

### 🚀 Capítulo 3: Forças e Leis de Newton (Lista 2)

**Foco:** A causa do movimento ($F=ma$).

#### 1. Conceitos e Fórmulas Chave

- **Equação Fundamental:** $\vec{F}_{res} = m\ddot{\vec{r}}$.
    
- **Forças Comuns:**
    
    - Peso: $\vec{P} = m\vec{g}$.
        
    - Mola (Hooke): $\vec{F} = -k(x - l_0)$ (onde $l_0$ é o comprimento natural).
        
    - Atrito: $F_{at} = \mu N$ (opõe-se ao movimento)5.
        
- **Máquina de Atwood:** Um clássico para entender sistemas acoplados. A aceleração é $a = g \frac{m_2 - m_1}{m_1 + m_2}$ (para polia sem massa)6.
    

#### 2. Técnicas para a Prova

- **Diagrama de Corpo Livre:** Isole cada corpo e desenhe _todas_ as forças. Isso é vital para as questões 1, 2 e 5 da Lista 2.
    
- **Vínculos:** Se dois blocos estão ligados por um fio inextensível, a magnitude da aceleração é a mesma para ambos ( $|a_1| = |a_2|$ ).
    

---

### 💥 Capítulos 4 e 5: Momento Linear e Energia (Lista 3)

**Foco:** Leis de conservação (simplificam problemas complexos).

#### 1. Conceitos e Fórmulas Chave

- **Momento Linear ($\vec{p}$):** $\vec{p} = m\vec{v}$.
    
- **Conservação do Momento Linear:** Se a força externa resultante é zero ($\sum \vec{F}_{ext} = 0$), então $\vec{p}_{antes} = \vec{p}_{depois}$.
    
    - Útil para **colisões** e explosões.
        
- **Coeficiente de Restituição ($e$):** Mede a elasticidade da colisão. $e = \frac{|v_{rel, depois}|}{|v_{rel, antes}|}$.
    
    - $e=1$: Colisão elástica (Energia conserva).
        
    - $e=0$: Colisão inelástica (Corpos grudam, energia _não_ conserva).
        
- **Energia Mecânica ($E$):** $E = T + V$ (Cinética + Potencial). Conservada se apenas forças conservativas (gravidade, mola) atuam.
    
    - $T = \frac{1}{2}mv^2$.
        
    - $V_{grav} = mgh$.
        
    - $V_{mola} = \frac{1}{2}kx^2$.
        

#### 2. Técnicas para a Prova

- **Colisões:** Sempre comece conservando o Momento Linear. Só conserve a Energia se o problema disser "elástico".
    
- **Centro de Massa:** O sistema se move como se toda a massa estivesse concentrada no CM: $\vec{R} = \frac{\sum m_i \vec{r}_i}{\sum m_i}$.
    

---

### 🌀 Capítulo 6: Momento Angular e Rotação (Lista 4)

**Foco:** A parte mais densa. Rotação de corpos rígidos e sistemas de partículas.

#### 1. Conceitos e Fórmulas Chave

- **Momento Angular ($\vec{L}$):** $\vec{L} = \vec{r} \times \vec{p}$.
    
- **Torque ($\vec{\tau}$):** $\vec{\tau} = \vec{r} \times \vec{F}$. A lei fundamental é $\vec{\tau} = \frac{d\vec{L}}{dt}$.
    
- **Momento de Inércia ($I$):** A "resistência" à rotação.
    
    - Discreto: $I = \sum m_i r_i^2$.
        
    - Contínuo (Tabela): Disco ($1/2 mR^2$), Anel ($mR^2$), Esfera ($2/5 mR^2$)12.
        
- **Teorema dos Eixos Paralelos (Steiner):** $I = I_{CM} + Md^2$.
    
- **Rotação em Eixo Fixo:** $L = I\omega$ e $K_{rot} = \frac{1}{2}I\omega^2$.
    
- **Rolamento sem Deslizamento:** A condição chave é $v = \omega R$.
    
    - Energia Total = Translação ($\frac{1}{2}mv^2$) + Rotação ($\frac{1}{2}I\omega^2$).
        

#### 2. Técnicas para a Prova

- **Tensor de Inércia (Matriz):** Para as questões 2 e 5 da lista 4. Lembre-se que os termos da diagonal são as somas de distâncias quadradas ($y^2+z^2$, etc) e os fora da diagonal são os produtos negativos ($-xy$, etc).
    
- **Forças Fictícias:** Em referenciais giratórios (Ex: conta no canudo giratório), adicione a **Força Centrífuga** ($m\omega^2 r$) e a **Força de Coriolis** ($-2m\vec{\Omega} \times \vec{v}$).
    
- **Equações de Euler:** Para rotações 3D complexas (pião).
    

---

### ⚙️ Capítulo 7: Equações de Lagrange (Lista 5)

**Foco:** O método mais poderoso para resolver problemas mecânicos complexos. É puramente escalar (energia), evitando vetores de força.

#### 1. A "Receita" de Lagrange (Use isso em todas as questões da Lista 5)

1. **Defina as Coordenadas Generalizadas ($q_i$):** As variáveis mínimas necessárias para descrever o sistema (ex: $x$, $\theta$, $l$).
    
2. **Calcule a Energia Cinética ($T$):** Em termos de $q$ e $\dot{q}$.
    
    - Dica: Use $v^2 = \dot{x}^2 + \dot{y}^2$. Se tiver vínculo (ex: $y=f(x)$), substitua $\dot{y}$ usando a regra da cadeia.
        
3. **Calcule a Energia Potencial ($V$):** Em termos de $q$. Geralmente $mgh$ ou $\frac{1}{2}kx^2$.
    
4. **Monte o Lagrangiano ($L$):** $\mathcal{L} = T - V$.
    
5. Aplique a Equação de Euler-Lagrange:
    
    $$\frac{d}{dt} \left( \frac{\partial \mathcal{L}}{\partial \dot{q}_i} \right) - \frac{\partial \mathcal{L}}{\partial q_i} = 0$$
    
    17
    

#### 2. Técnicas para a Prova

- **Velocidade ao Quadrado:** O passo mais difícil geralmente é escrever $v^2$.
    
    - Em coordenadas polares: $v^2 = \dot{r}^2 + (r\dot{\theta})^2$.
        
    - Em coordenadas cartesianas: $v^2 = \dot{x}^2 + \dot{y}^2$.
        
- **Vínculos:** Se um objeto está preso a uma curva (ex: conta na parábola ou ciclóide), use a equação da curva para eliminar uma variável. Ex: Se $y=ax^2$, então $\dot{y} = 2ax\dot{x}$. Substitua isso na energia cinética.
    
- **Coordenadas Cíclicas:** Se a Lagrangiana não depende explicitamente de uma coordenada $q$ (apenas de $\dot{q}$), então o momento conjugado $\frac{\partial \mathcal{L}}{\partial \dot{q}}$ é conservado. Isso é uma resposta rápida para questões conceituais.
    

### Resumo das Prioridades

1. **Decore a "Receita de Lagrange".** Ela resolve quase tudo da Lista 5 e é muito cobrada.
    
2. **Entenda "Rolar sem Deslizar".** A relação $v = \omega R$ conecta os capítulos de energia com os de rotação.
    
3. **Revise Coordenadas Polares.** Saber escrever $\vec{v}$ e $\vec{a}$ em polares é essencial para questões de força central e vínculos circulares.