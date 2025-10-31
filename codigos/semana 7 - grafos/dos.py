import math
import heapq

def prim(points):
    n = len(points)
    visited = [False] * n
    min_dist = [float('inf')] * n
    min_dist[0] = 0
    total = 0.0
    pq = [(0.0, 0)]  # (distancia, indice)
    
    while pq:
        dist, u = heapq.heappop(pq)
        if visited[u]:
            continue
        visited[u] = True
        total += dist
        
        for v in range(n):
            if not visited[v]:
                dx = points[u][0] - points[v][0]
                dy = points[u][1] - points[v][1]
                d = math.hypot(dx, dy)
                if d < min_dist[v]:
                    min_dist[v] = d
                    heapq.heappush(pq, (d, v))
    
    return total



t = int(input())
for _ in range(t):
    n = int(input())
    points = [tuple(map(float, input().split())) for _ in range(n)]
    result = prim(points)
    print(f"{result:.1f}")

