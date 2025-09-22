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

