import sys

class Literal:
    def __init__(self, caractere):
        self.caractere = caractere
    def __repr__(self):
        return f"Literal('{self.caractere}')"

class Concatenacao:
    def __init__(self, esquerda, direita):
        self.esquerda = esquerda
        self.direita = direita
    def __repr__(self):
        return f"Concatenacao({self.esquerda}, {self.direita})"

class Uniao:
    def __init__(self, esquerda, direita):
        self.esquerda = esquerda
        self.direita = direita
    def __repr__(self):
        return f"Uniao({self.esquerda}, {self.direita})"

class Estrela:
    def __init__(self, expressao):
        self.expressao = expressao
    def __repr__(self):
        return f"Estrela({self.expressao})"

class Opcional:
    def __init__(self, expressao):
        self.expressao = expressao
    def __repr__(self):
        return f"Opcional({self.expressao})"


class Parser:
    def __init__(self, expressao):
        self.expressao = expressao
        self.pos = 0

    def ver(self):
        return self.expressao[self.pos] if self.pos < len(self.expressao) else None

    def consumir(self):
        if self.pos < len(self.expressao):
            caractere = self.expressao[self.pos]
            self.pos += 1
            return caractere
        return None

    def analisar(self):
        if not self.expressao:
             return Literal('') # expressão vazia
        arvore = self._expressao()
        if self.ver() is not None:
            raise Exception(f"Erro: Caractere inesperado ")
        return arvore

    def _expressao(self):
        esquerda = self._concatenacao()
        # união com associatividade à esquerda
        while self.ver() == '|':
            self.consumir()
            direita = self._concatenacao()
            esquerda = Uniao(esquerda, direita)
        return esquerda

    def _concatenacao(self):
        if self.ver() is None or self.ver() in '|)':
            return Literal('') 

        esquerda = self._atomo()
        
        while self.ver() is not None and self.ver() not in '|)':
            direita = self._atomo()
            esquerda = Concatenacao(esquerda, direita)
            
        return esquerda

    def _atomo(self):
        simbolo = self.ver()
        base = None
        if simbolo == '(':
            self.consumir() # consome '('
            base = self._expressao()
            if self.consumir() != ')': # consome ')'
                raise Exception("Erro: Esperava ')'")
        elif simbolo == ')':
            base = Literal('')
        elif simbolo is None or simbolo in '|':
             raise Exception("Expressão incompleta.")
        else:
            base = Literal(self.consumir())

        while self.ver() is not None and self.ver() in '*?':
            op = self.consumir()
            if op == '*':
                base = Estrela(base)
            elif op == '?':
                base = Opcional(base)
        return base

class AFND:
    def __init__(self):
        self.transicoes = {}
        self.estado_inicial = None
        self.estados_finais = set()
        self._contador_estado = 0

    def novo_estado(self):
        estado = f"q{self._contador_estado}"
        self._contador_estado += 1
        self.transicoes[estado] = {}
        return estado

    def adicionar_transicao(self, origem, simbolo, destino):
        if simbolo not in self.transicoes[origem]:
            self.transicoes[origem][simbolo] = set()
        self.transicoes[origem][simbolo].add(destino)

    def epsilon_clausura(self, estados):
        pilha = list(estados)
        clausura = set(estados)
        while pilha:
            estado = pilha.pop()
            for destino in self.transicoes.get(estado, {}).get('', []):
                if destino not in clausura:
                    clausura.add(destino)
                    pilha.append(destino)
        return clausura

class AFD:
    def __init__(self):
        self.transicoes = {}
        self.estado_inicial = None
        self.estados_finais = set()

def converter_para_afnd(arvore):
    afnd = AFND()

    def construir(node):
        if isinstance(node, Literal):
            ini = afnd.novo_estado()
            fim = afnd.novo_estado()
            afnd.adicionar_transicao(ini, node.caractere, fim)
            return ini, fim
        elif isinstance(node, Concatenacao):
            ini1, fim1 = construir(node.esquerda)
            ini2, fim2 = construir(node.direita)
            afnd.adicionar_transicao(fim1, '', ini2)
            return ini1, fim2
        elif isinstance(node, Uniao):
            ini = afnd.novo_estado()
            fim = afnd.novo_estado()
            ini1, fim1 = construir(node.esquerda)
            ini2, fim2 = construir(node.direita)
            afnd.adicionar_transicao(ini, '', ini1)
            afnd.adicionar_transicao(ini, '', ini2)
            afnd.adicionar_transicao(fim1, '', fim)
            afnd.adicionar_transicao(fim2, '', fim)
            return ini, fim
        elif isinstance(node, Estrela):
            ini = afnd.novo_estado()
            fim = afnd.novo_estado()
            sub_ini, sub_fim = construir(node.expressao)
            afnd.adicionar_transicao(ini, '', sub_ini)
            afnd.adicionar_transicao(sub_fim, '', sub_ini)
            afnd.adicionar_transicao(sub_fim, '', fim)
            afnd.adicionar_transicao(ini, '', fim) 
            return ini, fim
        elif isinstance(node, Opcional):
            ini, fim = construir(node.expressao)
            afnd.adicionar_transicao(ini, '', fim)
            return ini, fim

    afnd.estado_inicial, final = construir(arvore)
    afnd.estados_finais.add(final)
    return afnd

def converter_afnd_para_afd(afnd):
    afd = AFD()
    if not afnd.estado_inicial: return afd

    mapeamento_estados = {} 
    fila = []
    
    estado_inicial_afnd = afnd.epsilon_clausura({afnd.estado_inicial})
    conjunto_inicial_frozen = frozenset(estado_inicial_afnd)
    
    nome_estado_inicial = "A"
    mapeamento_estados[conjunto_inicial_frozen] = nome_estado_inicial
    afd.estado_inicial = nome_estado_inicial
    fila.append(conjunto_inicial_frozen)
    
    contador_nomes = 1

    while fila:
        conjunto_atual_frozen = fila.pop(0)
        nome_atual = mapeamento_estados[conjunto_atual_frozen]
        afd.transicoes[nome_atual] = {}

        simbolos = set()
        for estado_afnd in conjunto_atual_frozen:
            simbolos.update(s for s in afnd.transicoes.get(estado_afnd, {}) if s != '')

        for simbolo in simbolos:
            proximo_conjunto = set()
            for estado_afnd in conjunto_atual_frozen:
                destinos_simbolo = afnd.transicoes.get(estado_afnd, {}).get(simbolo, set())
                proximo_conjunto.update(afnd.epsilon_clausura(destinos_simbolo))
            
            proximo_conjunto_frozen = frozenset(proximo_conjunto)
            if not proximo_conjunto_frozen: continue

            if proximo_conjunto_frozen not in mapeamento_estados:
                novo_nome = chr(ord('A') + contador_nomes)
                contador_nomes += 1
                mapeamento_estados[proximo_conjunto_frozen] = novo_nome
                fila.append(proximo_conjunto_frozen)
            
            afd.transicoes[nome_atual][simbolo] = mapeamento_estados[proximo_conjunto_frozen]

    for conjunto, nome in mapeamento_estados.items():
        if any(e in afnd.estados_finais for e in conjunto):
            afd.estados_finais.add(nome)

    return afd

def simular_afd(afd, entrada):
    if not afd.estado_inicial:
        return "SIM" if entrada == "" else "NÃO"
        
    estado = afd.estado_inicial
    for simbolo in entrada:
        estado = afd.transicoes.get(estado, {}).get(simbolo)
        if estado is None:
            return "NÃO" 
            
    return "SIM" if estado in afd.estados_finais else "NÃO"

def main():
    if len(sys.argv) < 2:
        print(f"Uso: python {sys.argv[0]} '<expressao>'")
        return
    
    try:
        expressao = sys.argv[1]
        parser = Parser(expressao)
        arvore = parser.analisar()
        afnd = converter_para_afnd(arvore)
        afd = converter_afnd_para_afd(afnd)
        
        for linha in sys.stdin:
            linha = linha.strip()
            print(simular_afd(afd, linha))
    except Exception as e:
        print(f"Erro: {e}", file=sys.stderr)

if __name__ == "__main__":
    main()