# https://cses.fi/problemset/task/1637
n = int(input())

p = 0
while(n != 0):
    s = max(map(int,list(str(n))))
    n -= s
    p += 1

print(p)
