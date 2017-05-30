while True:
  try:
    n, m = map(int, input().split())
    if n == 0 or m == 0:
      print('Go Kevin!!')
      continue
    D = (m + 2) ** 2 + 8 * m * (n - 1)
    N = int((D ** 0.5 - m - 2) * 0.5 / m)
    if 2 * n == (N + 1) * (2 + m * N):
      print('Go Kevin!!')
    else:
      print('No Stop!!')
  except EOFError:
    break
