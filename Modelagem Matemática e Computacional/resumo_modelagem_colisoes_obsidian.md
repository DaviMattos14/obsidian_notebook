# 📘 Resumo da Apostila — até Colisões  

---

## 🔹 1. Noções de Cinemática

- **Posição** em função do tempo: \(r(t)\)  
- **Velocidade vetorial:**  
$$v(t)=\frac{\text{d } \overrightarrow{r}}{dt}
$$  
- **Aceleração vetorial:**  
$$a(t)=\frac{d\vec{v}}{dt}=\frac{\text{d}^2\vec{r}}{dt^2}
$$  

**Noções úteis:**  
- A componente **tangencial** da aceleração é ligada à variação da rapidez.  
- A componente **normal (centrípeta)** é ligada à mudança de direção:  
$$
a_n = \frac{v^2}{R}
$$

---

## 🔹 2. Movimento Circular Uniforme

- Velocidade angular:  
$$
\omega=\frac{d\theta}{dt}
$$
- Relação com velocidade escalar:  
$$
v=\omega r
$$
- Aceleração centrípeta:  
$$
a_c=\frac{v^2}{r}=\omega^2 r
$$
- Período e frequência:  
$$
T=\frac{2\pi}{\omega}, \quad f=\frac{1}{T}
$$

---

## 🔹 3. Equações diferenciais simples

- Exemplo:  
$$
\frac{dr}{d\theta} = r\frac{v-u\cos\theta}{u\sin\theta}
$$

**Métodos recorrentes:**  
- **Separação de variáveis:** $(\frac{dy}{dx}=g(x)h(y))$
- **Integração:** $(\int\frac{dy}{y} = \ln y)$  
- **Identidades trigonométricas:**  
  $(\sin^2	\theta=1-\cos^2	\theta,\quad \cot	\theta=\frac{\cos	\theta}{\sin	\theta})$

---

## 🔹 4. Movimento Harmônico Simples (MHS)

- EDO padrão:  
$$
m\ddot x+kx=0
$$
- Frequência angular:  
$$
\omega=\sqrt{	\frac{k}{m}}
$$
- Solução geral:  
$$
x(t)=A\cos(\omega t)+B\sin(\omega t)
$$
- Período:  
$$
T=\frac{2\pi}{ \Omega}
$$

**Extensão:** duas molas em paralelo: $(k_{eq}=k_1+k_2)$

---

## 🔹 5. Pêndulo Cônico

- Equilíbrio de forças:  
$$
T\cos	\theta=mg,\quad T\sin	\theta=\frac{mv^2}{r}
$$
- Raio da trajetória: $(r=\ell \sin	\theta)$  
- Velocidade escalar:  
$$
v=\sqrt{\frac{g\ell\sin^2	\theta}{\cos	\theta}}
$$
- Velocidade angular:  
$$
\omega=\sqrt{\frac{g}{\ell\cos	\theta}}
$$
- Período de rotação:  
$$
T=2\pi\sqrt{\frac{\ell\cos	\theta}{g}}
$$

---

## 🔹 6. Forças em Sistemas Rotacionais

Exemplo: conta deslizando numa curva girando com \($\omega$\).

- Força centrífuga:  
$$
F_{cf}=m\omega^2 x
$$
- Projeções tangenciais:  
$$
F_{cf,tang}=m\omega^2 x\cos	\theta, \quad F_{peso,tang}=-mg\sin	\theta
$$
- Condição de equilíbrio:  
$$
f'(x)=tan\theta=\frac{\omega^2 x}{g}
$$
- Curva resultante: parábola  
$$
y=\frac{\omega^2}{2g}x^2
$$

---

## 🔹 7. Energia Mecânica

- **Cinética:**  
$$
K=	\frac12 mv^2
$$
- **Potencial gravitacional:**  
$$
U=mgh
$$
- **Trabalho-energia:**  
$$
W= \Delta K
$$
- **Conservação (sem dissipação):**  
$$
E=K+U=	\text{constante}
$$

**Aplicações típicas:**  
- Velocidade em função da altura: $(v=\sqrt{2g(h-h')})$  
- Condição para não perder contato (normal=0): $(v^2=gR)$

---

## 🔹 8. Colisões

### (a) Choques elásticos
$$
w_1 =\frac{(m_1-m_2)v_1+2m_2v_2}{m_1+m_2}, \quad
w_2 =\frac{(m_2-m_1)v_2+2m_1v_1}{m_1+m_2}
$$

Caso especial (\(m_2\) parado):  
$$
w_2=\frac{2m_1}{m_1+m_2}v_1
$$

### (b) Choques inelásticos
Velocidade comum:  
$$
V=\frac{m_1 v_1+m_2 v_2}{m_1+m_2}
$$

Energia perdida:  
$$
\Delta K=\frac{m_1m_2}{2(m_1+m_2)}(v_1-v_2)^2
$$

### (c) Coeficiente de restituição
$$
e=\frac{v_{rel,após}}{v_{rel,antes}}
$$

Exemplo: bola que quica  
$$
h_n=e^{2n}h
$$

---

# ✅ Síntese — noções básicas recorrentes

- Conservação de energia  
- Conservação do momento linear  
- Separação de variáveis em EDOs  
- Identidades trigonométricas  
- Progressões geométricas  
- Indução matemática
- **Conservação de energia** (potencial ↔ cinética).
- **Conservação do momento linear** em colisões.
- **Separação de variáveis** em EDOs simples.
- **Identidades trigonométricas** (sin²+cos²=1, tan=sin/cos).
- **Progressões geométricas** (para somas de saltos, tempos, alturas).
-  **Indução matemática** (para generalizar fórmulas como $(h_n=e^{2n}h)$.