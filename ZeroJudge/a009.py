import sys

key = ord('1') - ord('*')
lines = sys.stdin.readlines()
for string in lines:
  print(''.join([chr(ord(c) - key) for c in string]))
