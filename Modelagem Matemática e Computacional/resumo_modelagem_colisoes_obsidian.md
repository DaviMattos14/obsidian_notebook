# 📘 Resumo da Apostila — até Colisões  

---

## 🔹 1. Noções de Cinemática

- **Posição** em função do tempo: \(r(t)\)  
- **Velocidade vetorial:**  
$$
ec v(t)=rac{dec r}{dt}
$$  
- **Aceleração vetorial:**  
$$
ec a(t)=rac{dec v}{dt}=rac{d^2ec r}{dt^2}
$$  

**Noções úteis:**  
- A componente **tangencial** da aceleração é ligada à variação da rapidez.  
- A componente **normal (centrípeta)** é ligada à mudança de direção:  
$$
a_n = rac{v^2}{R}
$$

---

## 🔹 2. Movimento Circular Uniforme

- Velocidade angular:  
$$
\omega=rac{d	heta}{dt}
$$
- Relação com velocidade escalar:  
$$
v=\omega r
$$
- Aceleração centrípeta:  
$$
a_c=rac{v^2}{r}=\omega^2 r
$$
- Período e frequência:  
$$
T=rac{2\pi}{\omega}, \quad f=rac{1}{T}
$$

---

## 🔹 3. Equações diferenciais simples

- Exemplo:  
$$
rac{dr}{d	heta} = rrac{v-u\cos	heta}{u\sin	heta}
$$

**Métodos recorrentes:**  
- **Separação de variáveis:** \(rac{dy}{dx}=g(x)h(y)\)  
- **Integração:** \(\int rac{dy}{y} = \ln y\)  
- **Identidades trigonométricas:**  
  \(\sin^2	heta=1-\cos^2	heta,\quad \cot	heta=rac{\cos	heta}{\sin	heta}\)

---

## 🔹 4. Movimento Harmônico Simples (MHS)

- EDO padrão:  
$$
m\ddot x+kx=0
$$
- Frequência angular:  
$$
\omega=\sqrt{	frac{k}{m}}
$$
- Solução geral:  
$$
x(t)=A\cos(\omega t)+B\sin(\omega t)
$$
- Período:  
$$
T=rac{2\pi}{\omega}
$$

**Extensão:** duas molas em paralelo: \(k_{eq}=k_1+k_2\)

---

## 🔹 5. Pêndulo Cônico

- Equilíbrio de forças:  
$$
T\cos	heta=mg,\quad T\sin	heta=rac{mv^2}{r}
$$
- Raio da trajetória: \(r=\ell \sin	heta\)  
- Velocidade escalar:  
$$
v=\sqrt{rac{g\ell\sin^2	heta}{\cos	heta}}
$$
- Velocidade angular:  
$$
\omega=\sqrt{rac{g}{\ell\cos	heta}}
$$
- Período de rotação:  
$$
T=2\pi\sqrt{rac{\ell\cos	heta}{g}}
$$

---

## 🔹 6. Forças em Sistemas Rotacionais

Exemplo: conta deslizando numa curva girando com \(\omega\).

- Força centrífuga:  
$$
F_{cf}=m\omega^2 x
$$
- Projeções tangenciais:  
$$
F_{cf,tang}=m\omega^2 x\cos	heta, \quad F_{peso,tang}=-mg\sin	heta
$$
- Condição de equilíbrio:  
$$
f'(x)=	an	heta=rac{\omega^2 x}{g}
$$
- Curva resultante: parábola  
$$
y=rac{\omega^2}{2g}x^2
$$

---

## 🔹 7. Energia Mecânica

- **Cinética:**  
$$
K=	frac12 mv^2
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
E=K+U=	ext{constante}
$$

**Aplicações típicas:**  
- Velocidade em função da altura: \(v=\sqrt{2g(h-h')}\)  
- Condição para não perder contato (normal=0): \(v^2=gR\)

---

## 🔹 8. Colisões

### (a) Choques elásticos
$$
w_1 = rac{(m_1-m_2)v_1+2m_2v_2}{m_1+m_2}, \quad
w_2 = rac{(m_2-m_1)v_2+2m_1v_1}{m_1+m_2}
$$

Caso especial (\(m_2\) parado):  
$$
w_2=rac{2m_1}{m_1+m_2}v_1
$$

### (b) Choques inelásticos
Velocidade comum:  
$$
V=rac{m_1 v_1+m_2 v_2}{m_1+m_2}
$$

Energia perdida:  
$$
\Delta K=rac{m_1m_2}{2(m_1+m_2)}(v_1-v_2)^2
$$

### (c) Coeficiente de restituição
$$
e=rac{v_{rel,após}}{v_{rel,antes}}
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
