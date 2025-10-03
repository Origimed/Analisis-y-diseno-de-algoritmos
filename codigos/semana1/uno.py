import math

C = int(input())
salida = ""
for _ in range(C):
    N = int(input())
    S = N * (N + 1) // 2   
    r = math.isqrt(S)      
    if r * r == S:
        salida += str(r) + "\n"
    else:
        salida += "NO\n"

print(salida, end="")
        
