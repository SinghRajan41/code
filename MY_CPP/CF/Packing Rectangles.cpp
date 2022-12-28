s = input()
a,b,n = map(int,s.split())
ans = -1
low = 1
high = int(1e14 + 1)
while low<=high:
	mid  = (low + high)//2
	x = mid 
	num = (x//a)*(x//b)
	if num>=n:
		ans = mid
		high = mid - 1
	else:
		low = mid + 1
print(ans)