for t in range(int(input())):
	n = int(input())
	h = [0]+list(map(int, input().split()))+[0]
	
	L = [0]*(n+2)
	for i in range(1, n+1):
		L[i] = min(L[i-1]+1, h[i])
	R = [0]*(n+2)
	for i in range(n, 0, -1):
		R[i] = min(R[i+1]+1, h[i])
	print(L,R,sep="\n",end="\n\n")