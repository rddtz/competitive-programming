# https://cses.fi/problemset/task/1755
str = input()
letters = {}

for l in str:
    if l not in letters:
        letters[l] = 1
    else:
        letters[l] += 1
impares = 0
new_str = ""
m = 0
for k in letters.keys():
    if(letters[k] % 2):
        new_str = new_str[:m] + letters[k]*k + new_str[m:]
        m += 1
        impares += 1
    else:
        t = int(letters[k]/2)
        new_str = k*t + new_str + k*t
        m += t
if(impares > 1):
    print("NO SOLUTION")
else:
    print(new_str)
