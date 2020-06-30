import sys

def dfs(n, i, y, ans):
  if y == n:
    for j in range(i, y):
      sys.stdout.buffer.write(ans[:j] + b'()' + ans[j:])
  else:
    for j in range(i, y):
      dfs(n, j + 1, y + 2, ans[:j] + b'()' + ans[j:])

while True:
  try:
    try:
      n = 2 * int(input()) - 1
    except ValueError:
      continue
    dfs(n, 0, 1, b'\n')
  except EOFError:
    break
