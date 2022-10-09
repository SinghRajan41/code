#include <iostream>
using namespace std;
int n;
int *arr = NULL;
int path1(int src, int dest);
int path2(int arr[], int src, int dest);
int path3(int arr[], int src, int dest);
int _path2(int arr[], int mem[], int src, int dest);
int main()
{
   cin >> n;
   arr = new int[n + 1];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   cout << path1(0, n) << endl;
   cout << path2(arr, 0, n) << endl;
   cout << path3(arr, 0, n) << endl;
   return 0;
}
int path1(int src, int dest)
{
   if (src == dest)
   {
      return 1;
   }
   if (src > dest || !arr[src])
   {
      return 0;
   }
   int ways = 0;
   for (int i = 1; i <= arr[src]; i++)
   {
      ways += path1(src + i, dest);
   }
   return ways;
}
int _path2(int arr[], int mem[], int src, int dest)
{
   if (src > dest || !arr[src])
      return 0;
   if (src == dest)
      return 1;
   if (mem[src] == -1)
   {
      int ways = 0;
      for (int i = 1; i <= arr[src]; i++)
         ways += _path2(arr, mem, src + i, dest);
      mem[src] = ways;
   }
   return mem[src];
}
int path2(int arr[], int src, int dest)
{
   int mem[n + 1];
   for (int i = 0; i <= n; i++)
   {
      mem[i] = -1;
   }
   return _path2(arr, mem, src, dest);
}
int path3(int arr[], int src, int dest)
{
   int dp[n + 1];
   for (int i = 0; i <= n; i++)
   {
      dp[i] = 0;
   }
   dp[dest] = 1;
   for (int i = dest - 1; i >= 0; i--)
   {
      int ways = 0;
      for (int j = 1; j <= arr[i]; j++)
      {
         ways += (j + i > dest ? 0 : dp[j + i]);
      }
      dp[i] = ways;
   }
   return dp[0];
}