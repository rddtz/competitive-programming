n = int(input())

size = pow(2, n)

str = "{:0" + str(n)  + "b}"

ini = 0
fim = 1
c = 0
l = []

while(fim <= size):

    l = l + [fim] + l
    
    for i in range(ini,fim):
        
        print(str.format(c))
 
        c = c^l[i]

    ini = fim
    fim = fim*2
