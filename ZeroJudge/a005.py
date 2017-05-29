N = int(input())
for i in range(N):
  a, b, c, d = map(int, input().split())
  if b - a == d - c:
    e = d + b - a
  else:
    e = d * b / a
  print("{} {} {} {} {}".format(a, b, c, d, int(e)))
