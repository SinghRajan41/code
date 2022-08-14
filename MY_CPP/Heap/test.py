import heapq
arr=list()
for i in range(2,1000000):
   arr.append(i)
heapq.heapify(arr)
print(arr[0])