import sys

ans = bytearray()
n = None

def dfs(i, y):
  for j in range(i, 2 * y + 1):
    if y == n:
      sys.stdout.buffer.write(ans[:j] + b'()' + ans[j:])
    else:
      ans[j:j] = b'()'
      dfs(j + 1, y + 1)
      ans[j:j + 2] = []

while True:
  try:
    try:
      n = int(input()) - 1
    except ValueError:
      continue
    ans[:] = b'\n'
    dfs(0, 0)
  except EOFError:
    break
