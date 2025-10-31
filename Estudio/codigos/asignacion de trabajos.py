from itertools import permutations

# Leer 6x6
valores = []
for _ in range(6):
    fila = list(map(int, input().strip().split()))
    valores.append(fila)

mejor_total = 0

perm = permutations(valores)

for i in perm:
    total = 0
    for j in range(0,6):
        total += i[j][j]
    
    if (total > mejor_total):
        mejor_total = total

print(mejor_total)
