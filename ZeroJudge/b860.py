c, w = map(int, input().split())

n = 0
while c + w > 12:
  if c < 12:
    w = c + w - 13
    c = 2
    n += 1
    continue
 
  a, b = divmod(c, 12)
  if a >= w:
    n += w
    break
  n += a
  w -= a
  c = b + 2 * a

print(n)
