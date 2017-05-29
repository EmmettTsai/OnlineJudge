import math

while True:
  try:
    n = int(input())
    print(str(int(math.log2(n) + 1)))
  except EOFError:
    break
