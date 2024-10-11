# Introdução aos Sistemas Operacionais

**Definição:**  Um sistema operacional é um programa de computador (software) que atua como intermediário entre o usuário e o hardware. Ele fornece um ambiente onde o usuário possa executar seus programas.

![Figura 1. Componente de um sistema de computação.](visual_SO.png)

Figura 1. Componente de um sistema de computação.

![Figura 2. Visão simplificada de um sistema operacional.](componente_so%201.png)

Figura 2. Visão simplificada de um sistema operacional.

Os usuários e programas utilizam os recursos do computador de maneira concorrente. Dessa forma, o sistema operacional precisa gerenciar esse compartilhamento.

## Classificações

- Monotarefa vs Multitarefa
    
    
    - **Sistema Monotarefa**: sistemas que admitem e gerenciam apenas uma tarefa em execução por vez.
        - Vantagem: Fácil implementação.
        - Desvantagem: Baixa eficiência pois a CPU fica em vários momentos ociosa (por exemplo, em momentos de leitura e gravação de dados);
    - **Sistema Multitarefa**: sistemas que admitem e gerenciam várias tarefas em concorrência.
        - Vantagem: Maior eficiência na utilização dos recursos da máquina;
        - Desvantagem: Implementação mais complexa e possível sobrecarga.

- Monousuário vs Multiusuário
    - **Sistema Monousuário**: sistemas que admitem e gerenciam apenas um usuário (não pode ter mais de um usuário logado simultaneamente).
    - **Sistema Multiusuário**: sistemas que admirem e gerenciam vários usuários (podem estar logados simultaneamente).
    

- Monoprocessado vs Multiprocessado
    - **Sistemas Monoprocessados**: admitem uma única CPU e podem ser mono ou multitarefas (a CPU alterna rapidamente entre elas para simular uma execução simultânea).
    - **Sistemas Multiprocessados**: admitem mais de uma CPU e ocorre execução simultânea de tarefas.

Existem 3 tipos de sistema multitarefa: Batch, Time Sharing e Tempo Real.

- Batch
    - Os programas em sistemas batch são processados em lote, um de cada vez, sem interação com o usuário.

- Time Sharing
    - Os usuários compartilham o tempo de uso do computador.

- Tempo Real
    - Sistemas que possuem forte vínculo com o tempo e o resultado coreto deve ser dado no tempo previsto.

- Embarcado
    - Sistemas inseridos em produtos com funções específicas.