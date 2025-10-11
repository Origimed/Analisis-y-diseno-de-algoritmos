import sys
import heapq
from dataclasses import dataclass
from typing import Optional, List, Tuple

@dataclass
class Node:
    freq: int
    tie_key: str           # clave para desempates
    ch: Optional[str]      # carácter si es hoja. None si es interno
    left: Optional['Node']
    right: Optional['Node']

def huffman(nodes: List[Node]) -> Node:
    heap: List[Tuple[int, str, Node]] = []
    for n in nodes:
        heapq.heappush(heap, (n.freq, n.tie_key, n))

    # Caso especial: solo un simbolo
    if len(heap) == 1:
        return heap[0][2]

    # unimos siempre los dos de menor frecuencia (desempate por tie_key)
    # repite N-1 veces como en en la clase
    while len(heap) > 1:
        f1, k1, x = heapq.heappop(heap)
        f2, k2, y = heapq.heappop(heap)

        # x sera el hijo izquierdo (el que salio primero), y el derecho
        merged = Node(
            freq=f1 + f2,
            tie_key=k1 + k2,   # concatenacion para que el desempate siga siendo determinista
            ch=None,
            left=x,
            right=y
        )
        heapq.heappush(heap, (merged.freq, merged.tie_key, merged))

    return heap[0][2]

def inorder(root: Node):
    result = []

    def dfs(node: Node, code: str):
        if node is None:
            return
        # En-orden: izquierda, nodo, derecha
        # Pero imprimimos unicamente si es hoja (node.ch no es None).
        # Para respetar orden, bajamos con el mismo patron,
        # pero acumulamos el codigo segun el camino (0 izquierda, 1 derecha).
        if node.left:
            dfs(node.left, code + "0")
        if node.ch is not None:  # hoja
            # si el arbol tiene un solo nodo, el code puede estar vacío: usar "0"
            result.append((node.ch, code if code != "" else "0"))
        if node.right:
            dfs(node.right, code + "1")

    dfs(root, "")
    return result

def parse_input():
    data = sys.stdin.read().splitlines()
    t = int(data[0].strip())
    idx = 1
    cases = []
    for _ in range(t):
        # N en una línea
        while data[idx].strip() == "":
            idx += 1
        N = int(data[idx].strip())
        idx += 1

        nodes = []
        for _ in range(N):
            line = data[idx].rstrip("\n")
            idx += 1

            ch = line[0]
            freq = int(line[2:].strip())  # despues del espacio
            nodes.append(Node(freq=freq, tie_key=ch, ch=ch, left=None, right=None))
        cases.append(nodes)
    return cases


cases = parse_input()
out_lines = []
for i, nodes in enumerate(cases, start=1):
    root = huffman(nodes)
    pairs = inorder(root)

    out_lines.append(f"caso {i}:")
    for ch, code in pairs:
        out_lines.append(f"{ch} {code}")
    out_lines.append("")  # linea en blanco entre casos

# imprimir resultado quitando el ultimo salto extra
print("\n".join(out_lines).rstrip() + "\n")

