#include <iostream>
using namespace std;
int arr[10000] = {0};
int longestSubSeq(int prev, int l, int h)
{
   if (l > h)
   {
      return 0;
   }
   int x, y;
   x = longestSubSeq(l, l + 1, h);
   y = longestSubSeq(prev, l + 1, h);
   if (prev != -1 && arr[l] - arr[prev] == 1)
   {
      return 1 + max(x, y);
   }
   else
   {
      return max(x, y);
   }
}
int main()
{
   int n;
   cin >> n;
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   cout << longestSubSeq(-1, 0, n - 1);
   return 0;
}