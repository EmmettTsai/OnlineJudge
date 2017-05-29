while True:
  try:
    a, b, c = map(int, input().split())
    if a == 0:
      print('Two same roots x=' + str(int(-c / b)))
    else:
      d = b * b - 4 * a * c
      if d == 0:
        print('Two same roots x=' + str(int(-b / 2 / a)))
      elif d > 0:
        e = d ** 0.5
        print('Two different roots x1=%d , x2=%d' % ((-b + e) / 2 / a, (-b - e) / 2 / a))
      else:
        print('No real root')
      
  except EOFError:
    break
