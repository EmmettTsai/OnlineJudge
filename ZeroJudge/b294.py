X = [x for x in range(1, int(input()) + 1)]
Y = [x for x in map(int, input().split())]
print(sum([a * b for (a, b) in zip(X, Y)]))
