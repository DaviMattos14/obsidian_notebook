### Operações Elementares
1. $L_i \rightarrow k \cdot L_i$ (Multiplicar uma linha por um escalar $K$, ex: $2, \frac{1}{2}$)
2. $L_i \leftrightarrow L_j$ (Inverter linhas)
3. $L_i \rightarrow L_i + k \cdot L_j$ (Somar duas linhas)

### Semântica $\rightarrow$ Sintática
$$
\text{Usuário}
\begin{cases}
3x_1+2x_2+5x_3=y_1 \\
4x_1+5x_2+10x_3=y_2 \\
4x_1+10x_2+10x_3=y_3 \\
\end{cases}
\rightarrow
\text{Programador}
\begin{bmatrix}
&X_1 & X_2 & X_3 & y_1 & y_2 & y_3\\  
(\text{Eq. }1)&3 & 2 & 5 & 1 & 0 & 0\\ 
(\text{Eq. }2)&4 & 5 & 10 & 0 & 1 & 0\\ 
(\text{Eq. }3)&4 & 10 & 10 & 0 & 0 & 1\\
\end{bmatrix}
$$
Resolvemos na **sintaxe** e verificamos no modo **semântico**
###### Matriz:
$$
\Huge\Downarrow
$$
$$
\begin{align}
A_{(1,1)}x_1 + A_{(1,2)}x_2 + A_{(1,3)}x_3 = y_1 \\
A_{(2,1)}x_1 + A_{(2,2)}x_2 + A_{(2,3)}x_3 = y_2 \\
A_{(3,1)}x_1 + A_{(3,2)}x_2 + A_{(3,3)}x_3 = y_3 \\
\end{align}
\rightarrow
\begin{bmatrix}
a_{(1,1)} & a_{(1,2)}& a_{(1,3)} \\
a_{(2,1)} & a_{(2,2)}& a_{(2,3)} \\
a_{(3,1)} & a_{(3,2)}& a_{(3,3)} \\
\end{bmatrix}
\cdot
\begin{bmatrix}
x_1\\x_2\\x_3
\end{bmatrix}
=
\begin{bmatrix}
y_1\\y_2\\y_3
\end{bmatrix}
$$
### Composição de Função
$$
\begin{gather}
f:R^2\rightarrow R^2 & g:R^2\rightarrow R^2\\
f\bigg(\begin{bmatrix}x_1\\x_2\end{bmatrix}\bigg) = \begin{bmatrix}3x_1+2x_2\\5x_1+4x_2\end{bmatrix} &
g\bigg(\begin{bmatrix}x_1\\x_2\end{bmatrix}\bigg) = \begin{bmatrix}10x_1+11x_2\\14x_1+5x_2\end{bmatrix}
\end{gather}
$$
Exemplo: $g(f(x))$
$$
f\bigg(\begin{bmatrix}3x_1+2x_2\\5x_1+4x_2\end{bmatrix}\bigg) = \begin{bmatrix}10(3x_1+2x_2)+11(5x_1+4x_2)\\14(3x_1+2x_2)+5(5x_1+4x_2)\end{bmatrix}=
\begin{bmatrix}85x_1+62x_2\\67x_1+48x_2\end{bmatrix}
$$
$$
\begin{gather}
f\bigg(\begin{bmatrix}x_1\\x_2\end{bmatrix}\bigg) = \begin{bmatrix}3&2\\5&4\end{bmatrix}\cdot \begin{bmatrix}x_1\\x_2\end{bmatrix}&
g\bigg(\begin{bmatrix}x_1\\x_2\end{bmatrix}\bigg) = \begin{bmatrix}10&11\\14&5\end{bmatrix} \cdot
\begin{bmatrix}x_1\\x_2\end{bmatrix}
\end{gather}
$$
$$
g \circ{f} \bigg(\begin{bmatrix}x_1\\x_2\end{bmatrix}\bigg) = 
\begin{bmatrix}10&11\\14&5\end{bmatrix}^A\cdot\begin{bmatrix}3&2\\5&4\end{bmatrix}^B \cdot\begin{bmatrix}x_1\\x_2\end{bmatrix} = 
\begin{bmatrix}85&62\\67&48\end{bmatrix}^C
\cdot \begin{bmatrix}x_1\\x_2\end{bmatrix}
$$
Onde $A\cdot B = C$, é o mesmo que $A_(\text{Linha i}) \cdot B(\text{Coluna j}) = C_{(i,j)}$ 
Exemplo: $\begin{bmatrix}10&11\\14&5\end{bmatrix}^A\cdot\begin{bmatrix}3&2\\5&4\end{bmatrix}^B = \begin{bmatrix}((A_{(1,1)}\cdot B_{(1,1)})+(A_{(1,2)}\cdot B_{(2,1)}) )&((A_{(1,1)}\cdot B_{(2,1)})+(A_{(1,2)}\cdot B_{(2,2)}) )\\((A_{(2,1)}\cdot B_{(1,1)})+(A_{(2,2)}\cdot B_{(2,1)}) )&((A_{(2,1)}\cdot B_{(1,2)})+(A_{(2,2)}\cdot B_{(2,2)}) )\end{bmatrix}$
### Função Inversa
$f(x)=y \leftrightarrow x = g(y)$ 
$$
\begin{cases}
x_1+3x_2 = y_1\\
x_1+4x_2 = y_2
\end{cases}
\hspace{6px}
\underrightarrow{\text{Gauss-Jordan}\hspace{6px}}
\hspace{6px}
\begin{cases}
x_1=y_1-3(y_2-y_1)\\
x_2=y_2-y_1
\end{cases}
\rightarrow
\begin{cases}
x_1=4y_2-3y_2\\
x_2=y_2-y_1
\end{cases} \rightarrow x=g(y)
$$
$$
g\bigg(\begin{bmatrix}y_1\\y_2\end{bmatrix}\bigg) = \begin{bmatrix}4y_2-3y_2\\
y_2-y_1
\end{bmatrix}
$$
##### Teorema: $f(g(y)) = y \leftrightarrow g(f(x))=x$
##### Vetores Linearmente Independentes
$$
\begin{bmatrix}
&x_1&x_2&x_3&x_4&x_5\\
\text{(Eq 1)}& 1 & 0& 0& 0& 0\\
\text{(Eq 2)}& 0& 0 & 1& 0& 0\\
\text{(Eq 3)}& 0& 0& 0& 1& 0\\
\end{bmatrix}
$$
Onde, $x_2\text{ , } x_5$ são **variáveis dependentes** e $x_1\text{ , }x_3\text{ , }x_4$ são **variáveis independentes**, ou seja, $x_2 \text{ e } x_5$ podem ser escritos como combinação linear de $x_1\text{ , }x_3\text{ , }x_4$.
