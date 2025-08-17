line1 = input()
line1 = line1.split(' ')

#print(line1)
n = int(line1[0])
p = int(line1[1])

c = input()
c = c.split(" ")
c = list(map(int, c))

#print(c)
c = sorted(c)
#print(c)

l = 0
h = n-1

g = 0
while l <= h:
        if c[h] == p:
                g += 1
                h -= 1
        elif c[h] + c[l] <= p:
                g += 1
                h -= 1
                l += 1
        else:
                g += 1
                h -= 1
        
print(g)
                            
