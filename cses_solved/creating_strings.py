from math import factorial

def combinations(static, rest):
    
    moiset.add(static + rest)
    
    if(rest == ""):
        return
    
    for l in range(len(rest)):
        combinations(static + rest[l], rest[:l] + rest[l+1:])


str = ''.join(sorted(input()))
moiset = {str}

letters = {}
s = factorial(len(str))
for l in str:
    if l not in letters:
        letters[l] = 1
    else:
        letters[l] += 1
    
for k in letters.keys():
    s = int(s/factorial(letters[k]))
    
print(s)
    
    
for l in range(len(str)):
    combinations(str[l], str[:l] + str[l+1:])

resposta = sorted(moiset)
for i in resposta:
    print(i)
