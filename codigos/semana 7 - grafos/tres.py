import sys, heapq

def dijkstra_grid(mat, n, m):
    INF = 10**18
    dist = [[INF]*m for _ in range(n)]
    # la celda (0,0); empezamos con costo 0
    dist[0][0] = 0
    pq = [(0, 0, 0)]  # (costo, x, y)

    DIRS = [(-1,0),(1,0),(0,-1),(0,1)]
    while pq:
        cost, x, y = heapq.heappop(pq)
        if cost != dist[x][y]:
            continue
        if (x, y) == (n-1, m-1):
            return cost
        for dx, dy in DIRS:
            nx, ny = x+dx, y+dy
            if 0 <= nx < n and 0 <= ny < m:
                # pagar al ENTRAR a (nx,ny)
                nc = cost + mat[nx][ny]
                if nc < dist[nx][ny]:
                    dist[nx][ny] = nc
                    heapq.heappush(pq, (nc, nx, ny))
    return dist[n-1][m-1]

def read_tokens():
    for line in sys.stdin:
        for tok in line.strip().split():
            yield tok

it = read_tokens()
t = int(next(it))
out_lines = []
for _ in range(t):
    n = int(next(it)); m = int(next(it))
    mat = [[int(next(it)) for _ in range(m)] for __ in range(n)]
    out_lines.append(str(dijkstra_grid(mat, n, m)))
sys.stdout.write("\n".join(out_lines))

