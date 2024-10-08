# Estrutura do Sistema Operacional

![Figura 1: Partes do sistema operacional.](Estrutura_SO.jpg)

Figura 1: Partes do sistema operacional.

**Definição**: Kernel é o núcleo (parte central) do sistema operacional. Tem como responsabilidades: 

- Escalonamento de Processos;
- Tratamento de interrupções (chamadas ao sistema);
- Gerência de Memória;

- Gerência de Processador;
- Gerência de Arquivos;
- Gerência de E/S.

## Tipos de Arquitetura

### Monolítica

O sistema operacional é executado como se fosse um único módulo no Nível Kernel.

![monolitica.png](monolitica.png)

### Em camadas

O sistema operacional é dividido em níveis (como se fosse uma cebola) e cada nível oferece funções que só podem ser utilizadas pelas camadas mais externas.

![WhatsApp Image 2024-09-30 at 16.08.25_ee72e92f.jpg](camadas.jpg)

### Microkernel

Nós separamos o kernel em dois: a parte principal fica no microkernel (em nível kernel) que faz a comunicação direta com o hardware e entre os módulos. E os outros módulos do kernel ficam separados em servidores no nível usuário.

![WhatsApp Image 2024-09-30 at 16.06.07_a330a16e.jpg](microkernel.jpg)

### Máquina Virtual

Uma máquina real abriga internamente diferentes ambientes virtuais, onde cada um simula uma máquina distinta com seus próprios recursos. Assim, cada usuário parece ter uma própria máquina.

![WhatsApp Image 2024-09-30 at 16.07.19_e760ebc2.jpg](maquina%20virtual.jpg)

## System Call

![WhatsApp Image 2024-09-30 at 17.13.42_8a75c36f.jpg](system%20call.jpg)

## Interrupções

São sinais enviados por software ou hardware ao processador para que interrompa temporariamente a tarefa atual e lide com outro evento.

- A execução do programa corrente é suspensa.
- O endereço da Rotina de Serviço é localizado na tabela de interrupções (Tratador de Interrupções).
- O status do programa corrente é salvo (PC, PSW, etc).
- O controle do processador passa para a rotina de serviço.

![WhatsApp Image 2024-09-30 at 19.26.57_a25eb27f.jpg](tipos%20de%20interrupcoes.jpg)

### Múltiplas Interrupções

![Modelo Sequencial: Só podemos atender outra interrupção quando terminarmos a atual. Se a rotina X demorar a ser tratada, podemos perder dados da rotina Y.](multiplas%20interrupcoes.jpg)

Modelo Sequencial: Só podemos atender outra interrupção quando terminarmos a atual. Se a rotina X demorar a ser tratada, podemos perder dados da rotina Y.

![WhatsApp Image 2024-09-30 at 19.28.58_fb420323.jpg](interrupcao%20sequencial.jpg)

![Modelo Cascata: As interrupções possuem prioridade. Isto é, as mais importantes podem interromper outras de menor prioridade.](interrupcao%20em%20cascata.jpg)

Modelo Cascata: As interrupções possuem prioridade. Isto é, as mais importantes podem interromper outras de menor prioridade.