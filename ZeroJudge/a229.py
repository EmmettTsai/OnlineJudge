import sys

n = None

def dfs(i, y, ans):
  for j in range(i, 2 * y + 1):
    if y == n:
      sys.stdout.buffer.write(ans[:j] + b'()' + ans[j:])
    else:
      dfs(j + 1, y + 1, ans[:j] + b'()' + ans[j:])

while True:
  try:
    try:
      n = int(input()) - 1
    except ValueError:
      continue
    dfs(0, 0, b'\n')
  except EOFError:
    break
