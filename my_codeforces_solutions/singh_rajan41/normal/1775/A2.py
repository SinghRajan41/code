def solve():
  s = input()
  n = len(s)
  for i in range(1, len(s)-1):
    if s[i] == 'a':
      print(s[0:i], s[i:i+1], s[i+1:])
      return;
  print(s[:1], s[1:n-1],s[n-1:])

t = int(input())
while t>0:
  solve()
  t -= 1