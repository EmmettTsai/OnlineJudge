X, Y = map(int, input().split())
X += 2
if Y >= 30:
  X += 1
  Y -= 30
else:
  Y += 30
X %= 24
print('%02d:%02d' % (X, Y))
