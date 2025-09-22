# Equações Diferenciais Ordinárias (EDO)
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
\int(\underbrace{x-3}_{u})^{12} \underbrace{\text{ dx}}_{\text{ du}} 
\longrightarrow
\begin{cases}
\begin{array}{rcl}
u=x-3 \\ du=1  \end{array} 
\end{cases} 
\\
= \int u^{12}\text{ du} = \frac{u^{13}}{13} \cdot 1 +C =\frac{(x-3)^{13}}{13}+C 
\end{split}
$$


