# Memórias

---

> É a parte do computador responsável por armazenar programas e dados, com duas operações principais: escrita e leitura.
> 

![memoria_visual.png](memoria_visual.png)

A memória de um computador, na realidade, é todo um subsistema de vários componentes, interligados e integrados, com o objetivo de armazenar e recuperar informações. 

### **Conceitos Importantes**

- Tempo de acesso (latência)
    - Medido em relação ao tempo de leitura.
    - Memórias eletrônicas → igual, independente da distância (acesso aleatório).
    - Dispositivos eletromecânicos → varia conforme a distância (acesso sequencial).
- Capacidade
    - Quantidade de informações que pode ser armazenada.
    - Unidade de medida: byte.
- Volatilidade
    - Volátil → perde a informação armazenada quando a máquina é desligada.
    - Não volátil → não perde a informação armazenada quando a máquina é desligada.
- Tecnologias de Fabricação
    - Memórias de semicondutores.
    - Memórias de meio magnético.
    - Memórias de meio óptico.
- Temporariedade
    - Tempo de permanência da informação.
    - Permanente → Discos, disquetes.
    - Transitório (temporário) →  Registradores, memória cache, memória principal.
- Custo
    - Bastante variado, dependendo da tecnologia de fabricação, do ciclo de memória, e da quantidade de bits.

# Tecnologias de Fabricação

---

- Memórias de Semicondutores
    - Rápidas e relativamente caras.
    - Exemplos: SSD, Memória Cache, Registradores, Memória Principal (RAM).
    
- Memórias de Meio Magnético
    - Armazenam as informações por meio de campos magnéticos.
    - Mais barato.
    - Grande quantidade de informações.
    - Acesso sequencial e mais lento.
    - Exemplos: disquetes, discos rígidos, e fitas magnéticas.
    
- Memórias de Meio Óptico
    - Feixe de luz “marca” o valor como 0 ou 1.
    - Exemplos: CD-ROM, e CD-RW.

As memórias de semicondutores serão melhor descritas na tabela a seguir: 

| **R/W Memory - Leitura e escrita** | **Read Only Memory (ROM) - Somente leitura** | CMOS | **Flash** |
| --- | --- | --- | --- |
| Acesso aleatório e volátil. | Acesso aleatório e não volátil.  | Memória volátil, mas alimentada via bateria. | Alta capacidade de armazenamento. |
| Estática (SRAM) ou Dinâmica (DRAM) | Usada para programas que não se deseja alterar, como a BIOS.  | Armazena data, hora e outras configurações de inicialização do sistema. | Conteúdo dessa memória pode ser apagado normalmente por escrita. |
| SRAM mantém as informações enquanto estiver energizado. | Mais lenta que a R/W e mais barata.  |  | Muito usada em pen-drives. |
| DRAM precisa de refresh (recarga dos capacitores). Por isso que memórias SRAM tendem a ser mais rápidas que as DRAM. |  |  |  |
| Outros sub-tipos: DDR/SDRAM-II, RDRAM, etc. | Outros sub-tipos: PROM, EPROM, EEPROM e Flash.  |  |  |

# Hierarquia de Memória

---

> Trata-se da relação custo/desempenho.
> 

![image.png](custo_capacidade.png)


| **Tipo de Memória**    | **Características**                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| ---------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Registradores**      | - Mais veloz e mais cara, mas com capacidade baixa.  <br>- Onde são armazenados os operandos para as diversas instruções.                                                                                                                                                                                                                                                                                                                                                                                              |
| **Cache**              | - Dividem-se em três níveis: L1, L2, e L3.  <br>L1 (primária): interna ao processador.  <br>L2 (secundária): no interior da pastilha do processador, mas separada dele.  <br>L3: localizada externamente ao processador.  <br>- Quanto mais próxima do processaodor, melhor o desempenho.  <br>- Volátil e do tipo SRAM.  <br>- Associada à memória principal para criar um sistema razoável, pois o processador procura primeiro na cache e depois na memória principal.  <br>- As palavras mais usadas são mantidas. |
| **Memória Principal**  | - Armazena os programas e seus dados na hora de sua execução (onde a CPU busca instrução por instrução).  <br>- Volátil e do tipo DRAM.  <br>- É organizada em várias células, onde cada célula abriga 1 byte e possui um endereço único.  <br>- Pode virar um “gargalo para a CPU”, por isso temos a Cache.                                                                                                                                                                                                           |
| **Memória Secundária** | - Memória mais barata, mais capacidade, menos velocidade.  <br>- Não volátil, com armazenamento de longo período.  <br>- Backup: operação que utiliza a MS diretamente.  <br>- Pode ser usada para emular memória principal:  <br>**memória virtual**.                                                                                                                                                                                                                                                                 |