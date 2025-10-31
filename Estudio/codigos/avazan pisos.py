n = int(input())


valoresPisos = []
for _ in range(n-1):
    lista = list(map(int,input().strip().split()))
    valoresPisos.append(lista)

total = 0
i = 0
while(i < n-1):

    actual = valoresPisos[i]
    costo_base = actual[0]
    costo_atajo = actual[1]
    salto_atajo = actual[2]
    if (salto_atajo < i):
        total += costo_base
        i += 1
        continue
    costos_siguientes = 0
    for j in range(i,salto_atajo - 1):
        costos_siguientes += valoresPisos[j][0]

    if (costos_siguientes > costo_atajo):
        i  = salto_atajo - 1
        total += costo_atajo
    else:
        total += costo_base
        i += 1
        continue





print(total)
    


