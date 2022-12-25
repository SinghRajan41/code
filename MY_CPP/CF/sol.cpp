import sys
 
def solve():
	inp = sys.stdin.readline
	n = int(inp())
	l, r = 1, 1
	i = 1
	ans = []
	for v in inp().strip():
		i += 1
		if v == '0':
			l = 1 
		else:
			r = i
			l += 1
		ans.append(str(r - l + 1))
	print(' '.join(ans))
	
 
def main():
	for i in range(int(sys.stdin.readline())):
		solve()
 
if __name__ == '__main__':
	main()