from math import ceil
n,d = map(int,input().split())
arr = sorted([int(x) for x in input().split()])
low = 0
high = n-1
count = 0
while low<=high:
   req = int(ceil(d+1)/arr[high]) +1
   print(req)
   if high - low + 1 >= req:
      low += (req - 1)
      high-=1
      count += 1
   else:
      low = high + 1
print(count)