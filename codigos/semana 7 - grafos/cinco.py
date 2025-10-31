import sys
from collections import deque

def edmonds_karp(n, adj, cap, s, t):
    flow = 0
    INF = 10**18
    while True:
        parent = [-1]*n
        parent[s] = s
        q = deque([s])
        # BFS en el grafo residual (como indica Edmonds–Karp)
        while q and parent[t] == -1:
            u = q.popleft()
            for v in adj[u]:
                if parent[v] == -1 and cap[u][v] > 0:
                    parent[v] = u
                    q.append(v)
                    if v == t:
                        break
        if parent[t] == -1:
            break  # no hay mas caminos aumentantes

        bottleneck = INF
        v = t
        while v != s:
            u = parent[v]
            bottleneck = min(bottleneck, cap[u][v])
            v = u

        # aumentar flujo y actualizar residuales
        v = t
        while v != s:
            u = parent[v]
            cap[u][v] -= bottleneck
            cap[v][u] += bottleneck
            v = u

        flow += bottleneck
    return flow


it = iter(sys.stdin.read().strip().split())
tc = int(next(it))
out = []
for _ in range(tc):
    n = int(next(it)); m = int(next(it))
    adj = [[] for _ in range(n)]
    cap = [[0]*n for _ in range(n)]
    for _ in range(m):
        u = int(next(it)); v = int(next(it)); c = int(next(it))
        # grafo residual: agregar arista y su inversa (capacidad 0)
        if cap[u][v] == 0 and cap[v][u] == 0:
            adj[u].append(v)
            adj[v].append(u)
        cap[u][v] += c  # por si repitieran

    maxflow = edmonds_karp(n, adj, cap, 0, n-1)
    out.append(str(maxflow))
print("\n".join(out))


