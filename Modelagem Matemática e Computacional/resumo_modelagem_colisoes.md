# 📘 Resumo da Apostila — até Colisões  

---

## 🔹 1. Noções de Cinemática

- **Posição** em função do tempo: `r(t)`  
- **Velocidade vetorial:**  
  ```math
  ec v(t)=rac{dec r}{dt}
  ```  
- **Aceleração vetorial:**  
  ```math
  ec a(t)=rac{dec v}{dt}=rac{d^2ec r}{dt^2}
  ```  

**Noções úteis:**  
- A componente **tangencial** da aceleração é ligada à variação da rapidez.  
- A componente **normal (centrípeta)** é ligada à mudança de direção:  
  ```math
  a_n = rac{v^2}{R}
  ```

---

## 🔹 2. Movimento Circular Uniforme

- Velocidade angular:  
  ```math
  \omega=rac{d	heta}{dt}
  ```
- Relação com velocidade escalar:  
  ```math
  v=\omega r
  ```
- Aceleração centrípeta:  
  ```math
  a_c=rac{v^2}{r}=\omega^2 r
  ```
- Período e frequência:  
  ```math
  T=rac{2\pi}{\omega}, \quad f=rac{1}{T}
  ```

---

## 🔹 3. Equações diferenciais simples

- Exemplo:  
  ```math
  rac{dr}{d	heta} = rrac{v-u\cos	heta}{u\sin	heta}
  ```

**Métodos recorrentes:**  
- **Separação de variáveis:** `dy/dx=g(x)h(y)`  
- **Integração:** `∫ dy/y = ln y`  
- **Identidades trigonométricas:**  
  `sin²θ=1-cos²θ`, `cotθ=cosθ/sinθ`

---

## 🔹 4. Movimento Harmônico Simples (MHS)

- EDO padrão:  
  ```math
  m\ddot x+kx=0
  ```
- Frequência angular:  
  ```math
  \omega=\sqrt{	frac{k}{m}}
  ```
- Solução geral:  
  ```math
  x(t)=A\cos(\omega t)+B\sin(\omega t)
  ```
- Período:  
  ```math
  T=rac{2\pi}{\omega}
  ```

**Extensão:** duas molas em paralelo: `k_eq=k1+k2`

---

## 🔹 5. Pêndulo Cônico

- Equilíbrio de forças:  
  ```math
  T\cos	heta=mg,\quad T\sin	heta=rac{mv^2}{r}
  ```
- Raio da trajetória: `r=ℓ sinθ`  
- Velocidade escalar:  
  ```math
  v=\sqrt{rac{g\ell\sin^2	heta}{\cos	heta}}
  ```
- Velocidade angular:  
  ```math
  \omega=\sqrt{rac{g}{\ell\cos	heta}}
  ```
- Período de rotação:  
  ```math
  T=2\pi\sqrt{rac{\ell\cos	heta}{g}}
  ```

---

## 🔹 6. Forças em Sistemas Rotacionais

Exemplo: conta deslizando numa curva girando com `ω`.

- Força centrífuga:  
  ```math
  F_{cf}=m\omega^2 x
  ```
- Projeções tangenciais:  
  ```math
  F_{cf,tang}=m\omega^2 x\cos	heta, \quad F_{peso,tang}=-mg\sin	heta
  ```
- Condição de equilíbrio:  
  ```math
  f'(x)=	an	heta=rac{\omega^2 x}{g}
  ```
- Curva resultante: parábola  
  ```math
  y=rac{\omega^2}{2g}x^2
  ```

---

## 🔹 7. Energia Mecânica

- **Cinética:**  
  ```math
  K=	frac12 mv^2
  ```
- **Potencial gravitacional:**  
  ```math
  U=mgh
  ```
- **Trabalho-energia:**  
  ```math
  W= \Delta K
  ```
- **Conservação (sem dissipação):**  
  ```math
  E=K+U=	ext{constante}
  ```

**Aplicações típicas:**  
- Velocidade em função da altura: `v=√(2g(h-h'))`  
- Condição para não perder contato (normal=0): `v²=gR`

---

## 🔹 8. Colisões

### (a) Choques elásticos
\`\`\`math
w_1 = rac{(m_1-m_2)v_1+2m_2v_2}{m_1+m_2}, \quad
w_2 = rac{(m_2-m_1)v_2+2m_1v_1}{m_1+m_2}
\`\`\`

Caso especial (m2 parado):  
\`\`\`math
w_2=rac{2m_1}{m_1+m_2}v_1
\`\`\`

### (b) Choques inelásticos
Velocidade comum:  
\`\`\`math
V=rac{m_1 v_1+m_2 v_2}{m_1+m_2}
\`\`\`

Energia perdida:  
\`\`\`math
\Delta K=rac{m_1m_2}{2(m_1+m_2)}(v_1-v_2)^2
\`\`\`

### (c) Coeficiente de restituição
\`\`\`math
e=rac{v_{rel,após}}{v_{rel,antes}}
\`\`\`

Exemplo: bola que quica  
\`\`\`math
h_n=e^{2n}h
\`\`\`

---

# ✅ Síntese — noções básicas recorrentes

- Conservação de energia  
- Conservação do momento linear  
- Separação de variáveis em EDOs  
- Identidades trigonométricas  
- Progressões geométricas  
- Indução matemática
