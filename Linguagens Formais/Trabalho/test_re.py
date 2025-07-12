import sys

# ==============================================================================
# PARTE 1: DEFINIÇÃO DA ÁRVORE SINTÁTICA ABSTRATA (AST)
# Cada classe representa um tipo de operação na expressão regular.
# ==============================================================================

class Literal:
    def __init__(self, char):
        self.char = char
    def __repr__(self):
        return f"Literal({self.char})"

class Concat:
    def __init__(self, left, right):
        self.left = left
        self.right = right
    def __repr__(self):
        return f"Concat({self.left}, {self.right})"

class Union:
    def __init__(self, left, right):
        self.left = left
        self.right = right
    def __repr__(self):
        return f"Union({self.left}, {self.right})"

class Star: # Operador '*'
    def __init__(self, expr):
        self.expr = expr
    def __repr__(self):
        return f"Star({self.expr})"

class Question: # Operador '?'
    def __init__(self, expr):
        self.expr = expr
    def __repr__(self):
        return f"Question({self.expr})"

# ==============================================================================
# PARTE 2: O PARSER
# Transforma a string da expressão regular em uma AST.
# Este é um parser recursivo descendente que respeita a precedência.
# R -> C ('|' R)?
# C -> P+
# P -> A ('*' | '?')?
# A -> c | '(' R ')'
# ==============================================================================

class Parser:
    def __init__(self, text):
        self.text = text
        self.pos = 0

    def parse(self):
        # Uma expressão vazia é um caso especial.
        if not self.text:
            return None # Representa a concatenação vazia
        
        expr = self.parse_union()
        if self.pos < len(self.text):
            raise Exception("Erro de sintaxe: Caracteres inesperados no final da expressão.")
        return expr

    def current_char(self):
        if self.pos < len(self.text):
            return self.text[self.pos]
        return None

    # R -> C ('|' R)?
    def parse_union(self):
        left = self.parse_concat()
        if self.current_char() == '|':
            self.pos += 1
            right = self.parse_union()
            return Union(left, right)
        return left

    # C -> P+ (uma ou mais concatenações de P)
    def parse_concat(self):
        # A gramática do trabalho permite concatenação vazia, C -> ε
        # que complica um parser simples. Vamos ajustar para C -> P C | ε
        # e implementar com um loop.
        
        # Se o próximo token não pode iniciar uma expressão primária,
        # consideramos uma concatenação vazia (ε).
        if self.current_char() in (')', '|', None):
            return None # Representa epsilon, a string vazia

        left = self.parse_postfix()
        
        # Se houver uma expressão primária a seguir, é uma concatenação
        if self.current_char() not in (')', '|', None):
            right = self.parse_concat()
            # Se a parte direita não for vazia, cria a concatenação
            if right:
                return Concat(left, right)
        
        return left

    # P -> A ('*' | '?')?
    def parse_postfix(self):
        expr = self.parse_atom()
        if self.current_char() == '*':
            self.pos += 1
            return Star(expr)
        if self.current_char() == '?':
            self.pos += 1
            # R? é açúcar para (R|ε), que na nossa AST será Union(R, None)
            # Mas para a conversão para AFND, é mais fácil ter um nó específico.
            return Question(expr)
        return expr

    # A -> c | '(' R ')'
    def parse_atom(self):
        char = self.current_char()
        if char is None:
             raise Exception("Erro de sintaxe: Fim inesperado da expressão.")

        if char.isalnum() or char in ' ': # Adicione outros caracteres literais se necessário
            self.pos += 1
            return Literal(char)
        elif char == '(':
            self.pos += 1
            expr = self.parse_union()
            if self.current_char() != ')':
                raise Exception("Erro de sintaxe: Esperava ')' mas não encontrei.")
            self.pos += 1
            return expr
        # Caso de expressão vazia dentro de parênteses: ()
        elif char == ')':
            return None
        else:
            raise Exception(f"Erro de sintaxe: Caractere inesperado '{char}'.")


# ==============================================================================
# PARTE 3: CONVERSÃO AST -> AFND (NFA)
# Usa a Construção de Thompson para criar o autômato.
# ==============================================================================

class NFA:
    def __init__(self, start_state, accept_state):
        self.states = set()
        self.transitions = {} # Dicionário: (estado, simbolo) -> {conjunto de estados}
        self.start_state = start_state
        self.accept_state = accept_state
        self.add_state(start_state)
        self.add_state(accept_state)

    def add_state(self, state):
        self.states.add(state)

    def add_transition(self, from_state, symbol, to_state):
        self.add_state(from_state)
        self.add_state(to_state)
        if (from_state, symbol) not in self.transitions:
            self.transitions[(from_state, symbol)] = set()
        self.transitions[(from_state, symbol)].add(to_state)

# Variável global para garantir que os estados do AFND sejam únicos.
_state_counter = 0
def new_state():
    global _state_counter
    _state_counter += 1
    return _state_counter

def ast_to_nfa(ast):
    if ast is None: # Expressão vazia (ε)
        start = new_state()
        accept = new_state()
        nfa = NFA(start, accept)
        nfa.add_transition(start, None, accept) # None representa a transição ε
        return nfa

    if isinstance(ast, Literal):
        start = new_state()
        accept = new_state()
        nfa = NFA(start, accept)
        nfa.add_transition(start, ast.char, accept)
        return nfa

    if isinstance(ast, Concat):
        nfa1 = ast_to_nfa(ast.left)
        nfa2 = ast_to_nfa(ast.right)
        
        # Combina os dois NFAs
        nfa = NFA(nfa1.start_state, nfa2.accept_state)
        nfa.states = nfa1.states.union(nfa2.states)
        nfa.transitions = {**nfa1.transitions, **nfa2.transitions}
        
        # Conecta o estado de aceitação do primeiro ao estado inicial do segundo
        nfa.add_transition(nfa1.accept_state, None, nfa2.start_state)
        return nfa

    if isinstance(ast, Union):
        nfa1 = ast_to_nfa(ast.left)
        nfa2 = ast_to_nfa(ast.right)
        
        start = new_state()
        accept = new_state()
        
        nfa = NFA(start, accept)
        nfa.states = nfa1.states.union(nfa2.states)
        nfa.transitions = {**nfa1.transitions, **nfa2.transitions}
        
        # Transições ε do novo início para os inícios dos sub-autômatos
        nfa.add_transition(start, None, nfa1.start_state)
        nfa.add_transition(start, None, nfa2.start_state)
        
        # Transições ε dos fins dos sub-autômatos para o novo fim
        nfa.add_transition(nfa1.accept_state, None, accept)
        nfa.add_transition(nfa2.accept_state, None, accept)
        return nfa

    if isinstance(ast, Star):
        nfa_expr = ast_to_nfa(ast.expr)
        start = new_state()
        accept = new_state()

        nfa = NFA(start, accept)
        nfa.states = nfa_expr.states
        nfa.transitions = nfa_expr.transitions

        # Transições ε para o loop e para pular o loop
        nfa.add_transition(start, None, nfa_expr.start_state)
        nfa.add_transition(start, None, accept) # Pula (0 ocorrências)
        nfa.add_transition(nfa_expr.accept_state, None, nfa_expr.start_state) # Loop
        nfa.add_transition(nfa_expr.accept_state, None, accept)
        return nfa

    if isinstance(ast, Question):
        nfa_expr = ast_to_nfa(ast.expr)
        start = new_state()
        accept = new_state()

        nfa = NFA(start, accept)
        nfa.states = nfa_expr.states
        nfa.transitions = nfa_expr.transitions
        
        # Conecta o início e o fim do sub-autômato
        nfa.add_transition(start, None, nfa_expr.start_state)
        nfa.add_transition(nfa_expr.accept_state, None, accept)
        
        # Adiciona o caminho que "pula" a expressão (0 ocorrências)
        nfa.add_transition(start, None, accept)
        return nfa


# ==============================================================================
# PARTE 4: SIMULADOR DE AFND
# ==============================================================================

class Simulator:
    def __init__(self, nfa):
        self.nfa = nfa

    def epsilon_closure(self, states):
        """Calcula o fecho-ε de um conjunto de estados."""
        closure = set(states)
        stack = list(states)
        while stack:
            state = stack.pop()
            # Procura por transições ε a partir do estado atual
            next_states = self.nfa.transitions.get((state, None), set())
            for s_next in next_states:
                if s_next not in closure:
                    closure.add(s_next)
                    stack.append(s_next)
        return closure

    def move(self, states, char):
        """Calcula os estados alcançáveis a partir de um conjunto de estados com um caractere."""
        reachable_states = set()
        for state in states:
            next_states = self.nfa.transitions.get((state, char), set())
            reachable_states.update(next_states)
        return reachable_states

    def match(self, string):
        """Simula o AFND para verificar se a string é aceita."""
        current_states = self.epsilon_closure({self.nfa.start_state})
        
        for char in string:
            next_states = self.move(current_states, char)
            current_states = self.epsilon_closure(next_states)
            
            if not current_states:
                return False # Não há mais estados possíveis

        # Após consumir a string, verifica se algum dos estados atuais é de aceitação
        return self.nfa.accept_state in current_states

# ==============================================================================
# FUNÇÃO PRINCIPAL
# ==============================================================================

def main():
    if len(sys.argv) < 2:
        print(f"Uso: python {sys.argv[0]} '<expressao_regular>'")
        sys.exit(1)

    regex_string = sys.argv[1]

    try:
        # 1. Parsear a expressão regular para criar a AST
        parser = Parser(regex_string)
        ast = parser.parse()
        
        # 2. Converter a AST em um AFND
        nfa = ast_to_nfa(ast)
        
        # 3. Criar o simulador com o AFND
        simulator = Simulator(nfa)

        # 4. Ler as strings da entrada padrão e testar cada uma
        for line in sys.stdin:
            string_to_test = line.strip()
            if simulator.match(string_to_test):
                print("SIM")
            else:
                print("NÃO")

    except Exception as e:
        print(f"Erro: {e}", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()