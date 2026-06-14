from math import gcd

def encontrar_probabilidade(t1, t2, N):
    # Cálculo do intervalo total em minutos
    intervalo_total = (t2 - t1) * 60
    
    # Cálculo da área onde há encontro
    if N >= intervalo_total:
        return "1/1"  # Sempre se encontram
    
    area_encontro = intervalo_total - N
    
    # Reduzindo a fração
    divisor = gcd(area_encontro, intervalo_total)
    
    return f"{area_encontro // divisor}/{intervalo_total // divisor}"

# Exemplo de uso:
print(encontrar_probabilidade(1, 2, 15))  # Saída: 7/16
print(encontrar_probabilidade(1, 2, 60))  # Saída: 1/1
