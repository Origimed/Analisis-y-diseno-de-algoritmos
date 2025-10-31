import heapq
import sys

input = sys.stdin.readline
INF = float('inf')

def dijkstra(n, adj):
    dist = [INF] * (n + 1)
    dist[0] = 0
    pq = [(0, 0)]  # (distancia, nodo)
    
    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v, w in adj[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))
    return dist



N, M = map(int, input().split())
P = int(input())

adj = [[] for _ in range(N + 1)]
for _ in range(M):
    u, v, d = map(int, input().split())
    adj[u].append((v, d))
    adj[v].append((u, d))  # conexiones bidireccionales

destinos = [int(input()) for _ in range(P)]
dist = dijkstra(N, adj)

for k in destinos:
    if k <= N and dist[k] != INF:
        print(dist[k])
    else:
        print("ZOMBI")


