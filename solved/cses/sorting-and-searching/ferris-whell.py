# https://cses.fi/problemset/task/1090
line1 = input()
line1 = line1.split(' ')

n = int(line1[0])
p = int(line1[1])

c = input()
c = c.split(" ")
c = list(map(int, c))

c = sorted(c)

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
