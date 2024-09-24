1. Construa uma matriz que produza uma rotação de 90° no sentido anti-horário.
     Resposta: $\begin{bmatrix}\cos{\frac{\pi}{2}} & \sin{\frac{\pi}{2}}\\ -\sin{\frac{\pi}{2}} & \cos{\frac{\pi}{2}}\end{bmatrix}$
2. Determine a matriz que transformou o espaço de acordo com a imagem abaixo: 
	![[Pasted image 20240923095633.png]]

	Resposta: $\begin{bmatrix}1 & -1\\ 0 & 1\end{bmatrix}$

3. Insira a matriz $\begin{bmatrix}0 & 1\\ 1 & 0\end{bmatrix}$ no programa e descreva em palavras o que esta transformação faz.
     
     Resposta: Uma rotação de 180º no sentido anti-horário na origem
     
4. Ainda utilizando a matriz do item anterior, observe atentamente a animação e tente determinar vetores ou conjuntos de vetores que não mudam de direção (podem ser esticados ou encolhidos, mas não saem da reta original). Chamamos estes vetores "especiais" de autovetores ( [Dica](https://www.google.com/url?q=https%3A%2F%2Fen.wikipedia.org%2Fwiki%2FEigenvalues_and_eigenvectors%23%2Fmedia%2FFile%3AEigenvectors.gif))
    
	O vetor que não mudam de direção é o eixo de $Ax$
    
1. Ache os vetores ou conjuntos de vetores que não mudam de direção (podem ser esticados ou encolhidos, mas não saem da reta original (autovetores) da matriz $\begin{bmatrix}-1 & 0\\ 0 & 1\end{bmatrix}$.
    
6. Ache os vetores ou conjuntos de vetores que não mudam de direção (podem ser esticados ou encolhidos, mas não saem da reta original (autovetores) da matriz $\begin{bmatrix}-2 & 0\\ 2 & 2\end{bmatrix}$.
    
7. Observe o que acontece com o espaço quando inserimos a matriz $\begin{bmatrix}2 & 4\\ 1 & 2\end{bmatrix}$ e tente explicar com suas palavras o porquê disto acontecer.
    
8. Invente uma matriz de transformação linear que estique o espaço 2,5 unidades na direção y e 2 unidades na direção x.
    
9. Utilizando a matriz criada no exercício anterior, invente uma outra matriz que execute a mesma transformação, mas que, em seguida, rotacione o espaço em 45° no sentido anti-horário.
    
10. Explique como a matriz M transforma o espaço, sendo: M=$\begin{bmatrix}0 & 1\\ -1 & 0\end{bmatrix}$$\begin{bmatrix}1 & 0\\ 0 & 0\end{bmatrix}$ (Dica: o módulo do numpy define o operador @ para multiplicação entre matrizes.)
    
11. Se uma letra, como na aula de ontem, for transformada pela matriz $\begin{bmatrix}1 & 3\\ 0 & 2\end{bmatrix}$. A letra vai aumentar ou diminuir de tamanho? Quanto vai mudar?
    
12. Se uma letra, como na aula de ontem, for transformada pela matriz $\begin{bmatrix}1 & 3\\ 3 & 2\end{bmatrix}$. A letra vai aumentar ou diminuir de tamanho? Quanto vai mudar?
    
13. Se uma letra, como na aula de ontem, for transformada pela matriz $\begin{bmatrix}0.5 & 0\\ 1 & 4\end{bmatrix}$. A letra vai aumentar ou diminuir de tamanho? Quanto vai mudar? Definimos esse valor com o Determinante da transformação.
    
14. Se uma letra, como na aula de ontem, for transformada pela matriz $\begin{bmatrix}a & 1\\ c & 1\end{bmatrix}$. A letra vai aumentar ou diminuir de tamanho? Quanto vai mudar?
    
15. Uma rotação de 45 graus (anti-horária) e depois uma reflexão sobre o eixo x é equivalente à um reflexão sobre o eixo x e depois uma rotação de 45 graus (anti-horária)?
    
16. Seja M uma matriz de rotação de 90 graus (anti-horário). Explique o que a M2, M3, e M4 fazem.
    
17. Faça uma composição de 2 matrizes (pode escolher) que vimos ontem em aula e descreva o que acontece.
    
18. No exercício 5, determine todos os vetores que foram transformados no vetor nulo pela transformação.
    
19. Determine todos os vetores que foram transformados no vetor nulo pela matriz [−361−2]. Esse conjunto de vetores é chamado de núcleo da matriz.
    
20. Determine todos os vetores que foram transformados no vetor nulo pela transformação [−321−2].
    
21. Determine todos os vetores que estão no contra-domínio (imagem) da transformação [−361−2].
    
22. Determine todos os vetores que estão no contra-domínio da transformação [−321−2].
    
23. Baseado nos exercícios 16, 17, 18 e 19, faça alguma observação ou conjectura sobre o núcleo e a imagem de uma transformação e verifique a sua afirmação com outros exemplos.
    
24. Escolha 5 matrizes e descreva o determinante, o vetores no núcleo, imagem, autovetores das 5 matrizes.
    
25. Use as matrizes de rotação e reflexão para determinar uma matriz que faz uma reflexão sobre uma reta com inclinação de 20 graus. Verifique usando o código que a sua resposta está correta.
    
26. Qual é o determinante de uma matriz A com a inversa de A?
    
27. Qual é a relação dos autovalores de A com o determinante de A?