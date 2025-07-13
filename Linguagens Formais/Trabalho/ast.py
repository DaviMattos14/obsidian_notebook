import sys

# ----- Árvore Sintática Abstrata -----

class Literal:
    def __init__(self, char):
        self.char = char
    def __repr__(self):
        return f"Literal({self.char})"

class Concat:
    def __init__(self, esq, dir):
        self.esq = esq
        self.dir = dir
    def __repr__(self):
        return f"Concat({self.esq}, {self.dir})"

class Uniao:
    def __init__(self, esq, dir):
        self.esq = esq
        self.dir = dir
    def __repr__(self):
        return f"Uniao({self.esq}, {self.dir})"

class Estrela:  # *
    def __init__(self, expr):
        self.expr = expr
    def __repr__(self):
        return f"Estrela({self.expr})"

class Interrogacao:  # ?
    def __init__(self, expr):
        self.expr = expr
    def __repr__(self):
        return f"Interrogacao({self.expr})"

# ----- Parser recursivo descendente -----

class Parser:
    def __init__(self, text):
        self.text = text
        self.pos = 0

    def parse(self):
        if not self.text:
            return None
        expr = self.parse_uniao()
        if self.pos < len(self.text):
            raise Exception("Erro de sintaxe")
        return expr

    def letra_atual(self):
        if self.pos < len(self.text):
            return self.text[self.pos]
        return None

    def parse_uniao(self):
        esq = self.parse_concat()
        if self.letra_atual() == '|':
            self.pos += 1
            dir = self.parse_uniao()
            return Uniao(esq, dir)
        return esq

    def parse_concat(self):
        if self.letra_atual() in (')', '|', None):
            return None  # epsilon
        esq = self.parse_postfix()
        if self.letra_atual() not in (')', '|', None):
            dir = self.parse_concat()
            if dir:
                return Concat(esq, dir)
        return esq

    def parse_postfix(self):
        expr = self.parse_atom()
        if self.letra_atual() == '*':
            self.pos += 1
            return Estrela(expr)
        if self.letra_atual() == '?':
            self.pos += 1
            return Interrogacao(expr)
        return expr

    def parse_atom(self):
        char = self.letra_atual()
        if char is None:
            raise Exception("Erro de sintaxe")
        if char.isalnum() or char in ' ':
            self.pos += 1
            return Literal(char)
        elif char == '(':
            self.pos += 1
            expr = self.parse_uniao()
            if self.letra_atual() != ')':
                raise Exception("Erro de sintaxe: esperava ')'")
            self.pos += 1
            return expr
        elif char == ')':
            return None
        else:
            raise Exception(f"Erro de sintaxe'{char}'")

# ----- Construção AFND -----

class NFA:
    def __init__(self, estado_inicio, estado_aceite):
        self.estados = set()
        self.transicoes = {}  # (estado, simbolo) -> set(estados)
        self.estado_inicio = estado_inicio
        self.estado_aceite = estado_aceite
        self.add_estado(estado_inicio)
        self.add_estado(estado_aceite)

    def add_estado(self, estado):
        self.estados.add(estado)

    def add_transicao(self, de_estado, simbolo, para_estado):
        self.add_estado(de_estado)
        self.add_estado(para_estado)
        if (de_estado, simbolo) not in self.transicoes:
            self.transicoes[(de_estado, simbolo)] = set()
        self.transicoes[(de_estado, simbolo)].add(para_estado)

_state_counter = 0
def novo_estado():
    global _state_counter
    _state_counter += 1
    return _state_counter

def ast_to_nfa(ast):
    if ast is None:
        e = novo_estado()
        f = novo_estado()
        nfa = NFA(e, f)
        nfa.add_transicao(e, None, f)
        return nfa

    if isinstance(ast, Literal):
        e = novo_estado()
        f = novo_estado()
        nfa = NFA(e, f)
        nfa.add_transicao(e, ast.char, f)
        return nfa

    if isinstance(ast, Concat):
        nfa1 = ast_to_nfa(ast.esq)
        nfa2 = ast_to_nfa(ast.dir)
        nfa = NFA(nfa1.estado_inicio, nfa2.estado_aceite)
        nfa.estados = nfa1.estados.union(nfa2.estados)
        nfa.transicoes = {**nfa1.transicoes, **nfa2.transicoes}
        nfa.add_transicao(nfa1.estado_aceite, None, nfa2.estado_inicio)
        return nfa

    if isinstance(ast, Uniao):
        nfa1 = ast_to_nfa(ast.esq)
        nfa2 = ast_to_nfa(ast.dir)
        e = novo_estado()
        f = novo_estado()
        nfa = NFA(e, f)
        nfa.estados = nfa1.estados.union(nfa2.estados)
        nfa.transicoes = {**nfa1.transicoes, **nfa2.transicoes}
        nfa.add_transicao(e, None, nfa1.estado_inicio)
        nfa.add_transicao(e, None, nfa2.estado_inicio)
        nfa.add_transicao(nfa1.estado_aceite, None, f)
        nfa.add_transicao(nfa2.estado_aceite, None, f)
        return nfa

    if isinstance(ast, Estrela):
        nfa_expr = ast_to_nfa(ast.expr)
        e = novo_estado()
        f = novo_estado()
        nfa = NFA(e, f)
        nfa.estados = nfa_expr.estados
        nfa.transicoes = nfa_expr.transicoes
        nfa.add_transicao(e, None, nfa_expr.estado_inicio)
        nfa.add_transicao(e, None, f)
        nfa.add_transicao(nfa_expr.estado_aceite, None, nfa_expr.estado_inicio)
        nfa.add_transicao(nfa_expr.estado_aceite, None, f)
        return nfa

    if isinstance(ast, Interrogacao):
        nfa_expr = ast_to_nfa(ast.expr)
        e = novo_estado()
        f = novo_estado()
        nfa = NFA(e, f)
        nfa.estados = nfa_expr.estados
        nfa.transicoes = nfa_expr.transicoes
        nfa.add_transicao(e, None, nfa_expr.estado_inicio)
        nfa.add_transicao(nfa_expr.estado_aceite, None, f)
        nfa.add_transicao(e, None, f)
        return nfa

    raise Exception("desconhecido")

# ----- Simulador do AFND -----

class SimuladorAFND:
    def __init__(self, nfa):
        self.nfa = nfa

    def fecho_epsilon(self, estados):
        resultado = set(estados)
        pilha = list(estados)
        while pilha:
            estado = pilha.pop()
            proxs = self.nfa.transicoes.get((estado, None), set())
            for prox in proxs:
                if prox not in resultado:
                    resultado.add(prox)
                    pilha.append(prox)
        return resultado

    def mover(self, estados, simbolo):
        resultado = set()
        for estado in estados:
            trans = self.nfa.transicoes.get((estado, simbolo), set())
            resultado.update(trans)
        return resultado

    def casa(self, string):
        estados_atuais = self.fecho_epsilon({self.nfa.estado_inicio})
        for c in string:
            estados_atuais = self.fecho_epsilon(self.mover(estados_atuais, c))
            if not estados_atuais:
                return False
        return self.nfa.estado_aceite in estados_atuais


def main():
    if len(sys.argv) < 2:
        print(f"Uso: python {sys.argv[0]} '<expressao_regular>'")
        sys.exit(1)

    regex = sys.argv[1]

    try:
        parser = Parser(regex)
        ast = parser.parse()

        nfa = ast_to_nfa(ast)
        simulador = SimuladorAFND(nfa)

        for linha in sys.stdin:
            linha = linha.strip()
            if simulador.casa(linha):
                print("SIM")
            else:
                print("NÃO")

    except Exception as e:
        print(f"Erro: {e}", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()
