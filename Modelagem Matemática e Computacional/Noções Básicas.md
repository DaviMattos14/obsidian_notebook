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
* **Regra da Cadeia**: Essencial para derivar funções compostas, como $\cos(kt)$. [cite: 2, 4]
    * $\frac{d}{dt}[f(g(t))] = f'(g(t)) \cdot g'(t)$
* **Derivação Implícita**: Usada quando `x` e `y` são funções do tempo e estão relacionados por uma equação de trajetória. Derivamos ambos os lados da equação em relação a `t`.
* **Norma de um Vetor**: Usada para encontrar a velocidade escalar a partir do vetor velocidade.
    * Para $\vec{v} = (v_x, v_y)$, a norma é $||\vec{v}||= \sqrt{v_x^2 + v_y^2}$[cite: 217, 218].
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
    * **Força de Atrito ($F_a$)**: Oposta ao movimento, $F_a = \mu N$. [cite: 912]
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
* **Pontos de Atenção**: A condição para a velocidade mínima no topo do loop é quando a Força Normal ($N$) se torna zero[cite: 1291, 1293]. A solução exige a combinação da análise de forças (para a condição no topo) com a conservação de energia (para relacionar com a altura inicial).

#### **Exercício 3 (p. 86): Colisão Perfeitamente Inelástica**
* **Tópicos**: Colisão Inelástica, Conservação de Momento, Perda de Energia.
* **Fórmulas**: $P_{antes} = P_{depois}$, $K = \frac{1}{2}mv^2$.
* **Pontos de Atenção**: A característica principal é que os objetos se juntam e passam a ter uma única velocidade final. A energia cinética **não** é conservada. 

#### **Exercício 4 (p. 87): Cadeia de Colisões**
* **Tópicos**: Colisão Elástica, Padrões, Conservação de Energia.
* **Fórmulas**: $w_{j+1} = \frac{2m_j v_j}{m_j+m_{j+1}}$, $h_n = \frac{v_n^2}{2g}$.
* **Pontos de Atenção**: O segredo para resolver problemas em cadeia é resolver para o primeiro caso, depois para o segundo, e então **observar o padrão** para generalizar para o n-ésimo caso.