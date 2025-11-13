# Regra do Produto
$$
\frac{d}{dx}[f(x)g(x)]=f(x)\frac{d}{dx}[g(x)] + g(x)\frac{d}{dx}[f(x)] \longleftrightarrow (f\cdot g)'=f'\cdot g+f\cdot g'
$$
Exemplo: $h(x)=xe^x$
$$
\begin{matrix}
h'(x)=\frac{d}{dx}(xe^{x)}\longrightarrow \begin{cases} f(x)=x && f'(x)= 1\\
g(x)=e^{x}&& g'(x)=e^x 
\end{cases} \\ 
h'(x) = x\frac{d}{dx}(e^x)+e^x\frac{d}{dx}(x) \\ 
h'(x)=xe^x+e^x\cdot 1=e^x(x+1) \\ 
h'(x)=(x+1)e^x
\end{matrix}
$$

# Regra da Cadeia
$$
\frac{d }{dx}[f(g(x))]=f'(g(x))\cdot g'(x)
$$
Exemplo: 
$$
\begin{matrix}
h(x)=\underbrace{\sin}_{f(x)}(\underbrace{x^{2}+2}_{g(x)})
\longrightarrow
\begin{cases}
\begin{array}{rcl}
f'(x)=\cos \\ g'(x)=2x  \end{array} 
\end{cases} \\
h'(x) = \underbrace{\cos}_{f'(x)}{(\underbrace{x^2+2}_{g(x)})}\cdot\underbrace{2x}_{g'(x)}
\end{matrix}
$$
# Equações Diferenciais Ordinárias (EDO)
$$
\frac{dy}{dx} = xy(x) \leftrightarrow f'(x)=xf(x) \leftrightarrow y'=xy
$$
## Equações Separáveis
$$
\frac{dy}{dx} = g(x)f(y), \text{  f(y)}\neq 0
$$
### Solução
$$\begin{matrix}
\frac{dy}{dx} = \frac{\overbrace{2x}^{g(x)}}{\underbrace{1+2y}_{f(y)}} \therefore (1+2y)\text{ dy} = 2x\text{ dx} \\ 
\int (1+2y)\text{ dy} = \int 2x\text{ dx} \\ 
y+y^{2}= x^{2}+ c
\end{matrix}
$$
## EDO (1ª Ordem)
$$
\frac{dy}{dx} + P(x)y = Q(x) \text{ , P e Q são funções ou constantes }
$$
### Solução
Exemplo: $x^2y'+xy=1$
1. Dividir ambos os lados pelo coeficiente de $y'$
	$$
	\frac{x^2y'}{x^2} + \frac{xy}{x^{2}} = \frac{1}{x^{2}} \therefore y' + \frac{1}{x}y=\frac{1}{x^2}
$$
2. Achar o fator integrante $P(x)$ e calcular $I(x)=e^{\int P(x) \text{ dx}}$ 
	$$
	\begin{matrix}
	 P(x) = \frac{1}{x}\rightarrow I(x)=e^{\int \frac{1}{x}}=e^{\ln x}=x
	\end{matrix}
$$
3. Multiplicar ambos os lados pelo fator integrante
	$$
	x \cdot y' + x\cdot \frac{1}{x}y=\frac{1}{x^{2}\cdot}x \therefore xy'+y=\frac{1}{x}
$$
4. Usar a regra do produto: $(f(x)\cdot g(x))'=f'(x)g(x)+f(x)g'(x)$
	$$
	xy'+1\cdot y = (xy)' \therefore (xy)'=\frac{1}{x}
$$
5. Integrar de ambos os lados
	$$
	\int (xy)'=\int \frac{1}{x} \therefore xy=\ln x + c
$$
6. Resolver o P.V.I. (Se houver)
## EDO (2ª Ordem)

$$
P(x)\frac{d^2y}{dx^2} + Q(x)\frac{dy}{dx} +R(x)y= G(x)
$$
Para $P(x),Q(x),R(x),Q(x)$ sendo funções ou constantes
### Caso Homogêneo - $G(x)=0$
$$
P(x)\frac{d^2y}{dx^2} + Q(x)\frac{dy}{dx} +R(x)y=0\therefore Ay''+By'+Cy=0
$$
#### Solução
1. Primeiro pegamos a equação auxiliar $Ay''+By'+Cy=0$
2. Achamos as suas raízes $\frac{-b\pm \sqrt{b^2-4ac}}{2a}$
3. Solucionamos caso a caso
	1. $\Delta >0$  : 	$y=C_1e^{r_1x}+C_2e^{r_2x}$
	2. $\Delta <0$  :	$y=e^{\alpha x}(C_1\cos{\beta x}+C_2\sin{\beta x})$
# Integral por partes
$$
\int u \hspace{0.2cm}dv = uv - \int v \hspace{0.2cm}du
$$
Exemplo:
$$
\begin{split}
\int \underbrace{x}_{u}\underbrace{e^{x}}_{\text{dv}}\, dx \longrightarrow
\begin{cases}
\begin{array}{rcl}
u=x && du=1 \\
v=e^{x}&& dv= e^x
\end{array} 
\end{cases} 
\\
= uv - \int v \text{ du} \longrightarrow 
\underbrace{x}_{\text{u}} \underbrace{e^{x}}_{\text{v}} 
- \int \underbrace{e^{x}}_{\text{v}}\cdot\underbrace{1}_{\text{du}}
\\ = xe^{x} - e^{x} + c
\end{split}
$$
# Integração por substituição
$$
\begin{matrix}
\int f(g(x))\cdot g'(x) \text{ dx} = F(g(x)) + C && && \int f(u)du=F(u)+C
\end{matrix}
$$
Exemplo:
$$
\begin{split}
\int(x-3)^{12} \text{ dx}
\longrightarrow
\int \overbrace{(\underbrace{x-3}_{u})^{12}}^{f} \underbrace{\text{ dx}}_{\text{ du}} 
\longrightarrow
\begin{cases}
\begin{array}{rcl}
u=x-3 \\ du=1  \end{array} 
\end{cases} 
\\
= \int u^{12}\text{ du} = \frac{u^{13}}{13} \cdot 1 +C =\frac{(x-3)^{13}}{13}+C 
\end{split}
$$

### 1. Cinemática e Cálculo
* **Posição, Velocidade e Aceleração**: A velocidade é a primeira derivada da posição, e a aceleração é a segunda.
    * Vetor Velocidade: $\vec{v}(t) = \dot{\vec{r}}(t) = \frac{d\vec{r}}{dt}$ 
    * Vetor Aceleração: $\vec{a}(t) = \ddot{\vec{r}}(t) = \frac{d\vec{v}}{dt}$ 
* **Regra da Cadeia**: Essencial para derivar funções compostas, como $\cos(kt)$.  2, 4]
    * $\frac{d}{dt}[f(g(t))] = f'(g(t)) \cdot g'(t)$
* **Derivação Implícita**: Usada quando `x` e `y` são funções do tempo e estão relacionados por uma equação de trajetória. Derivamos ambos os lados da equação em relação a `t`.
* **Norma de um Vetor**: Usada para encontrar a velocidade escalar a partir do vetor velocidade.
    * Para $\vec{v} = (v_x, v_y)$, a norma é $||\vec{v}||= \sqrt{v_x^2 + v_y^2}$ 217, 218].
**Noções úteis:**
- A componente **tangencial** da aceleração é ligada à variação da rapidez.
- A componente **normal (centrípeta)** é ligada à mudança de direção:
    $$$a_n = \frac{v^2}{R}$$
### 2. Dinâmica (Forças)
* **Segunda Lei de Newton**: A base para encontrar a equação de um movimento a partir das forças.
    * $F_{resultante} = ma = m\ddot{r}$ 
* **Forças Comuns**:
    * **Peso**: $\vec{P} = mg$, aponta verticalmente para baixo.
    * **Força Normal (N)**: Perpendicular à superfície de contato, equilibra a componente perpendicular do peso.
    * **Força de Atrito ($F_a$)**: Oposta ao movimento, $F_a = \mu N$.  912]
    * **Força Centrípeta ($F_c$)**: Força resultante que aponta para o centro e mantém o corpo em movimento circular. Sua magnitude é $F_c = \frac{mv^2}{r} = m\omega^2r$. 

### 3. Leis de Conservação
* **Conservação de Energia Mecânica**: Usada quando não há atrito ou outras forças dissipativas. A energia total (cinética + potencial) permanece constante.
    * Energia Cinética: $K = \frac{1}{2}mv^2$ 
    * Energia Potencial Gravitacional: $U_g = mgh$ 
    * Princípio: $K_{inicial} + U_{inicial} = K_{final} + U_{final}$ 
* **Conservação de Momento Linear**: Chave para resolver **todas** as colisões em sistemas isolados.
    * Momento Linear: $p = mv$
    * Princípio: $P_{total, inicial} = P_{total, final}$ 

---

## Resumo dos Exercícios Resolvidos

### Capítulo 4 - Momento Linear

#### **Exercício 1 (p. 74): Colisão Elástica em Sequência**
* **Tópicos**: Colisão Elástica, Conservação de Momento.
* **Fórmulas**:
    * Inversão de velocidade (choque com parede): $v_f = -v_i$.
    * Velocidade final da partícula 2 (alvo parado): $\overline{w}_2 = \frac{2m_1\overline{v}_1}{m_1 + m_2}$.
* **Pontos de Atenção**: Manter a consistência dos sinais das velocidades e mapear corretamente as variáveis do problema para as da fórmula.

#### **Exercício 2 (p. 74): Bola Quicando**
* **Tópicos**: Conservação de Energia, Coeficiente de Restituição, Prova por Indução.
* **Fórmulas**: $mgh = \frac{1}{2}mv^2$, $w = ev$, $h_{n} = e^{2n}h$.
* **Pontos de Atenção**: O coeficiente de restituição `e` conecta a velocidade *antes* do choque (`v`) com a velocidade *depois* (`w`). A prova por indução foi uma forma rigorosa de confirmar o padrão físico.

### Capítulo 5 - Energia

#### **Exercício 2 (p. 86): Carrinho na Rampa com Loop**
* **Tópicos**: Conservação de Energia, Força Centrípeta, Movimento Circular.
* **Fórmulas**: $E_i = E_f$, $F_c = \frac{mv^2}{R}$, $v_{min} = \sqrt{gR}$.
* **Pontos de Atenção**: A condição para a velocidade mínima no topo do loop é quando a Força Normal ($N$) se torna zero 1291, 1293]. A solução exige a combinação da análise de forças (para a condição no topo) com a conservação de energia (para relacionar com a altura inicial).

#### **Exercício 3 (p. 86): Colisão Perfeitamente Inelástica**
* **Tópicos**: Colisão Inelástica, Conservação de Momento, Perda de Energia.
* **Fórmulas**: $P_{antes} = P_{depois}$, $K = \frac{1}{2}mv^2$.
* **Pontos de Atenção**: A característica principal é que os objetos se juntam e passam a ter uma única velocidade final. A energia cinética **não** é conservada. 

#### **Exercício 4 (p. 87): Cadeia de Colisões**
* **Tópicos**: Colisão Elástica, Padrões, Conservação de Energia.
* **Fórmulas**: $w_{j+1} = \frac{2m_j v_j}{m_j+m_{j+1}}$, $h_n = \frac{v_n^2}{2g}$.
* **Pontos de Atenção**: O segredo para resolver problemas em cadeia é resolver para o primeiro caso, depois para o segundo, e então **observar o padrão** para generalizar para o n-ésimo caso.

# Momento Angular, Torque e Coordenadas em Rotação

## Tensor de Inércia

$$
\mathbb{I} = \sum\limits_{k} m_{k}((r_{k}^{T}r_{k})I-r_{k}r_{k}^{T})
$$$$\mathbb{I} = \begin{bmatrix} \sum m_i(y_i^2 + z_i^2) & -\sum m_i x_i y_i & -\sum m_i x_i z_i \\ -\sum m_i y_i x_i & \sum m_i(x_i^2 + z_i^2) & -\sum m_i y_i z_i \\ -\sum m_i z_i x_i & -\sum m_i z_i y_i & \sum m_i(x_i^2 + y_i^2) \end{bmatrix}
$$
# Resumo de Estudo: Capítulos 6 e 7 (Modelagem Matemática)

## Capítulo 6: Momento Angular e Dinâmica de Rotação

Este capítulo expande a mecânica de Newton para incluir movimentos de rotação. A ideia principal é que, assim como a *Força* causa variação no *Momento Linear*, o **Torque** ($\tau$) causa variação no **Momento Angular** ($\vec{L}$).

### Conceitos Fundamentais e Fórmulas Recorrentes

**1. Momento de Inércia ($I$): A "Massa Rotacional"**

O conceito mais importante do capítulo. É a medida da resistência de um objeto à aceleração angular.

* **Para Corpos Rígidos (Discos, Hastes, etc.):**
    * A forma mais fácil de encontrar o $I$ é consultando a **Tabela 1 (página 107)**  .
    * **Cilindro Sólido/Disco** (usado nos Ex 6, 15): $I = \frac{1}{2}mr^2$  .
    * **Casca Cilíndrica/Anel** (usado no Ex 9): $I = ma^2$ .
    * **Barra (pelo centro)** (usado no Ex 14): $I = \frac{1}{12}M\ell^2$.
        * *Ponto de Atenção (Ex 14):* A haste tinha comprimento $2L$, então $I_{haste} = \frac{1}{12}M(2L)^2 = \frac{1}{3}ML^2$  .

* **Para Sistemas de Partículas (Ex 2): O Tensor de Inércia**
    * Para sistemas 3D discretos, $I$ é uma matriz 3x3 .
    * **Elementos Diagonais** (Momentos de Inércia): $I_{1,1} = \sum m_i(y_i^2 + z_i^2)$ .
    * **Elementos Fora da Diagonal** (Produtos de Inércia): $I_{1,2} = -\sum m_i x_i y_i$ .

* **Teorema dos Eixos Perpendiculares (Ex 8):**
    * Provamos que para um conjunto de massas no plano $z=0$, $I_z = I_x + I_y$ .
    * Isso foi feito mostrando que $I_x = \sum m_i y_i^2$, $I_y = \sum m_i x_i^2$ e $I_z = \sum m_i (x_i^2 + y_i^2)$  .

**2. Energia Cinética de Rotação ($T$ ou $K_{rot}$)**

* **Fórmula Base (Ex 6, 9, 15):** $T_{rot} = \frac{1}{2}I\omega^2$   .
* **Ponto de Atenção: "Rolar sem Deslizar" (Ex 9, 10, 15):**
    * Esta condição é crucial e conecta o movimento linear (translação) com o angular (rotação).
    * A fórmula de conexão é **$v = \omega r$** 366
    * **Energia Cinética Total** é a soma da translação e da rotação  :
        $K_{Total} = K_{Transla\c{c}\tilde{a}o} + K_{Rota\c{c}\tilde{a}o} = \frac{1}{2}mv^2 + \frac{1}{2}I\omega^2$
    * No Ex 9 (casca cilíndrica, $I=ma^2$), isso resultou em $K_{Total} = \frac{1}{2}mv^2 + \frac{1}{2}(ma^2)(\frac{v}{a})^2 = mv^2$ .
    * No Ex 15 (cilindro sólido, $I=\frac{1}{2}mr^2$), o sistema era $K_{Total} = K_{bloco} + K_{cilindro} = \frac{1}{2}Mv^2 + \frac{1}{4}mv^2$ .

**3. Conservação do Momento Angular (Ex 14)**

* **Princípio:** Se não há torques externos ($\tau_{ext} = 0$), o momento angular total ($L$) do sistema é conservado 21* **Fórmula:** $L = I\omega$.
* **Aplicação (Ex 14):** As bolas deslizaram para fora, mudando o Momento de Inércia do sistema. Para $L$ se manter constante, a velocidade angular $\omega$ teve que mudar.
    * $L_{antes} = L_{depois} \implies I_{antes}\omega_1 = I_{depois}\omega_2$  .
    * Isso nos deu a nova velocidade angular: $\omega_2 = \omega_1 \left( \frac{I_{antes}}{I_{depois}} \right)$ .

**4. Equações de Euler (Dinâmica 3D Avançada)**

* Estas são as equações de movimento para um corpo rígido em 3D, vistas do referencial do próprio corpo. Elas são usadas quando a rotação *não* é simples .
    1.  $I_1 \dot{\Omega}_1 = (I_2 - I_3)\Omega_2 \Omega_3 + \tau'_1$
    2.  $I_2 \dot{\Omega}_2 = (I_3 - I_1)\Omega_1 \Omega_3 + \tau'_2$
    3.  $I_3 \dot{\Omega}_3 = (I_1 - I_2)\Omega_1 \Omega_2 + \tau'_3$

* **Aplicação 1: Rotação Estável (Ex 12, $\tau'=0$)**
    * Usamos as equações para provar que uma rotação com $\Omega_3 = \text{constante}$ e $I_1 \neq I_2 \neq I_3$ só pode existir se $\Omega_1 = 0$ e $\Omega_2 = 0$ .
    * *Passo Chave:* $\Omega_3 = \text{constante} \implies \dot{\Omega}_3 = 0$. Substituindo na Eq. 3, $0 = (I_1 - I_2)\Omega_1 \Omega_2$. Como $I_1 \neq I_2$, concluímos que $\Omega_1\Omega_2 = 0$ .

* **Aplicação 2: Encontrar Torque (Ex 13)**
    * Usamos as equações para encontrar o torque $\tau'$ necessário para manter um movimento.
    * A rotação $\vec{\omega}$ era constante, mas inclinada em um ângulo $\theta$.
    * *Passo Chave 1:* Decompomos $\vec{\omega}$ nos eixos principais: $\Omega = (0, \omega \sin\theta, \omega \cos\theta)$ .
    * *Passo Chave 2:* Como $\Omega$ é constante, todas as derivadas $\dot{\Omega}_1, \dot{\Omega}_2, \dot{\Omega}_3$ são zero.
    * *Passo Chave 3:* Substituímos isso nas Equações de Euler e isolamos as componentes do torque $\tau'$, descobrindo que $\tau'_1 \neq 0$ .

**5. Forças Fictícias (Ex 4)**

* Em um referencial giratório, objetos sentem "forças fictícias".
* **Força Centrífuga:** $F_c = m\omega^2 r$. Esta é a força que empurra a partícula para fora do canudo giratório .
* A equação de movimento radial se tornou $m\ddot{r} = F_c$, o que levou à EDO $\ddot{r} = \omega^2 r$ .
* A solução $r(t) = a \cosh(\omega t)$ foi encontrada   e a velocidade final foi determinada usando a identidade $\cosh^2(x) - \sinh^2(x) = 1$ para eliminar o tempo .

---

## Capítulo 7: Equações de Lagrange

Este capítulo apresenta um método alternativo e mais poderoso para encontrar as equações de movimento. Em vez de vetores (Forças e Torques), ele usa escalares (Energia).

### A "Receita" Lagrangiana

Para encontrar a equação de movimento de um sistema, seguimos 5 passos:

**Passo 1: Escolher Coordenadas Generalizadas ($q_i$)**
* Escolhemos o número mínimo de variáveis independentes que descrevem o sistema.
    * (Ex 1) Queda Livre: $q_1 = z$
    * (Ex 2) Conta na Parábola: $q_1 = x$.
    * (Ex 8) Pêndulo-Haste: $q_1 = \theta$ .
    * (Ex 3) Bloco e Cunha: $q_1 = x$ (posição da cunha), $q_2 = y$ (posição do bloco na rampa) .

**Passo 2: Calcular a Energia Cinética ($T$)**
* Escrevemos $T$ *apenas* em termos das coordenadas $q_i$ e suas derivadas $\dot{q}_i$.
* **Ponto de Atenção (Regra da Cadeia):** Este é o passo mais crucial.
    * (Ex 2, $y=ax^2$): Precisávamos de $v^2 = \dot{x}^2 + \dot{y}^2$. Usamos a Regra da Cadeia: $\dot{y} = \frac{dy}{dt} = (\frac{dy}{dx})(\frac{dx}{dt}) = (2ax)\dot{x}$ .
    * (Ex 3, Bloco e Cunha): Precisávamos da velocidade absoluta do bloco $m$. Isso foi a soma vetorial da velocidade da cunha ($\dot{x}$) e da velocidade do bloco na rampa ($\dot{y}$).
        * $v_x = \dot{x} + \dot{y}\cos\alpha$  
        * $v_y = -\dot{y}\sin\alpha$  
        * $T_m = \frac{1}{2}m(v_x^2 + v_y^2) = \frac{1}{2}m(\dot{x}^2 + 2\dot{x}\dot{y}\cos\alpha + \dot{y}^2)$  .
    * (Ex 8, Pêndulo-Haste): Para rotação pura, $T = \frac{1}{2}I\omega^2 = \frac{1}{2}I\dot{\theta}^2$. Usamos $I = \frac{m\ell^2}{3}$ (momento de inércia pela extremidade)   .

**Passo 3: Calcular a Energia Potencial ($V$)**
* Escrevemos $V$ *apenas* em termos das coordenadas $q_i$.
* (Ex 1, Queda Livre): $V = mgz$  .
* (Ex 2, Parábola): $V = mgy = mg(ax^2)$  .
* (Ex 3, Bloco e Cunha): $V = V_M + V_m = 0 - mgy\sin\alpha$ (definindo $V=0$ no topo da rampa)  .
* (Ex 8, Pêndulo-Haste): $V$ depende da altura do centro de massa. $h_{cm} = \frac{\ell}{2}\cos\theta$. Definindo $V=0$ no pivô, $V = -mg(\frac{\ell}{2}\cos\theta)$ .

**Passo 4: Montar o Lagrangiano ($L$)**
* A definição é simplesmente $L = T - V$  .

**Passo 5: Aplicar a Equação de Lagrange**
* Para *cada* coordenada generalizada $q_i$, aplicamos a fórmula:
    **$\frac{d}{dt}\left(\frac{\partial L}{\partial \dot{q}_i}\right) - \frac{\partial L}{\partial q_i} = 0$**  .
* **Ponto de Atenção (Coordenadas Cíclicas):**
    * No Ex 3, o Lagrangiano dependia de $\dot{x}$, mas **não** de $x$.
    * Isso significa que $\frac{\partial L}{\partial x} = 0$.
    * A equação de Lagrange para $x$ tornou-se $\frac{d}{dt}(\frac{\partial L}{\partial \dot{x}}) = 0$.
    * Isso implica que a quantidade $\frac{\partial L}{\partial \dot{x}}$ (o "momento generalizado" para $x$) é **conservada** durante todo o movimento.