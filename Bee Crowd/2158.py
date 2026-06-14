# relação de Euler para poliedros convexos:

# 𝑉 − 𝐸 + 𝐹 = 2

# neste caso:

# F = 5*FP + 6*FH (Faces Pentagonais e Hexagonais)

def calcular_molecula(fp, fh, caso):
    
    # Número de arestas
    E = (5 * fp + 6 * fh) // 2
    
    # Número de faces
    F = fp + fh
    
    # Número de vértices (átomos)
    V = E - F + 2
    
    print(f"Molecula #{caso}.:.")
    print(f"Possui {V} atomos e {E} ligacoes\n")

# Entrada dos valores
caso = 1
while True:
    try:
        fp, fh = map(int, input().split())
        calcular_molecula(fp, fh, caso)
        caso += 1
    except EOFError:
        break
