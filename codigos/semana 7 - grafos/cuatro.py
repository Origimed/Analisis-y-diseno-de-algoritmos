import sys

def find(x, parent):
    # DSU con compresion de caminos 
    while x != parent[x]:
        parent[x] = parent[parent[x]]
        x = parent[x]
    return x

def union(a, b, parent, size):
    ra, rb = find(a, parent), find(b, parent)
    if ra == rb:
        return False
    if size[ra] < size[rb]:
        ra, rb = rb, ra
    parent[rb] = ra
    size[ra] += size[rb]
    return True


data = sys.stdin.read().strip().split()
it = iter(data)
t = int(next(it))
out = []
for _ in range(t):
    n = int(next(it)); m = int(next(it)); A = int(next(it))

    # tomar solo carreteras que valen la pena (costo < A)
    edges = []
    for _ in range(m):
        u = int(next(it)) - 1
        v = int(next(it)) - 1
        w = int(next(it))
        if w < A:
            edges.append((w, u, v))

    edges.sort()  # kruskal

    parent = list(range(n))
    size   = [1]*n

    mst_cost = 0
    for w, u, v in edges:
        if union(u, v, parent, size):
            mst_cost += w

    # contar componentes ----  un aeropuerto por componente
    reps = {find(i, parent) for i in range(n)}
    airports = len(reps)
    total = mst_cost + airports * A

    out.append(f"{total} {airports}")

print("\n".join(out))

