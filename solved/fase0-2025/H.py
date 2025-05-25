n = int(input())

if(n % 2 == 0):
    n -= 1

s = bin(n)[2:]
t = len(s)

b = t//2 + 1

ns = ["0"]*t

final = ns
for i in range(b):

    aux = [i for i in final]
    aux[i] = "1"
    aux[t - i - 1] = "1"

    auxN = ''.join(aux)

    if(int(auxN,2) <= n):
        final = aux

print(int(''.join(final), 2))
