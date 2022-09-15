n,w,l = list(map(int,input().split(" ")))
H=list()
R=list()
def check(T):
   count = 0 
   for i in range(n):
      height = H[i]  + T*R[i]
      if(height >= l):
         count += height
   return count >= w
for i in range(n):
   x,y = list(map(int,input().split()))
   H.append(x)
   R.append(y)
low = 0
high = 1e18+1
res = high
while(low <= high):
   mid = (low + high) // 2
   if(check(mid)):
      if(mid < res):
         res = mid
      high = mid - 1
   else:
      low = mid + 1
print(int(res))
