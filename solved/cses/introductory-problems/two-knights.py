# https://cses.fi/problemset/task/1072
# The 4*(i-1)*(i-2) come from noticing that if two knights are attacking
# each other, they will create a 2x3 or 3x2, so we need to count the
# number of this sub-grids. for more information?
# https://math.stackexchange.com/questions/3266257/number-of-ways-two-knights-can-be-placed-such-that-they-dont-attack

for i in range(1, int(input()) + 1):
  c = int(((i*i)*(i*i - 1))/2)
  d = 4*(i-1)*(i-2)
  print(c - d)
