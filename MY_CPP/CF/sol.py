class Solution:
    def VeryEasyTask(n,x,y):
        # Base case
        if n == 1:
            return min(x,y)
        ans = 0
        left = 0
        right = max(x,y) * n

        def isGood(mid, n , x , y):
            # We need to check whether mid time is enough to make n - 1 copies( remember we have ORIG)
            # C1 -> x seconds
            # C2 -> y seconds

            # no of copies C1 copier can make in mid seconds
            # (mid / x)

            # no of copies C2 copier can make in mid seconds
            # (mid / y)

            return (mid // x) + ( mid // y) >= n-1

        # Now the main code to do BinarySearch
        while left <= right:
            mid = (left+right) // 2

            if isGood(mid, n, x, y):
                # thats a possible answer,but we want a better answer, so LEFT
                ans = mid
                right = mid-1
            else:
                left = mid + 1
        return ans + min(x,y)  # why min(x,y) to consider the original copy being used
    
s = input()
n,x,y = map(int,s.split())
print(Solution.VeryEasyTask(n,x,y))