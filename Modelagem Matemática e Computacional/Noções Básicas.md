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
f(x)
$$
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
