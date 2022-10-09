#include <iostream>
using namespace std;
int path(int arr[], int src, int dest);
int _path2(int arr[], int mem[], int src, int dest);
int path2(int arr[], int src, int dest);
int path3(int arr[], int src, int dest);
int main()
{
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   cout << path3(arr, 0, n);
   return 0;
}
int path(int arr[], int src, int dest)
{
   if (src > dest)
      return INT32_MAX / 2;
   if (src == dest)
      return 1;
   int Min = INT32_MAX / 2;
   for (int i = 1; i <= arr[src]; i++)
   {
      Min = min(Min, path(arr, src + i, dest));
   }
   return Min + 1;
}
int _path2(int arr[], int mem[], int src, int dest)
{
   if (src > dest)
      return INT32_MAX / 2;
   if (src == dest)
      return 0;
   if (mem[src] == -1)
   {
      int Min = INT32_MAX;
      for (int i = 1; i <= arr[src]; i++)
         Min = min(Min, _path2(arr, mem, src + i, dest));
      mem[src] = Min + 1;
   }
   return mem[src] + 1;
}
int path2(int arr[], int src, int dest)
{
   int mem[dest + 1];
   for (int i = 0; i < dest + 1; i++)
   {
      mem[i] = -1;
   }
   return _path2(arr, mem, src, dest);
}
int path3(int arr[], int src, int dest)
{
   int dp[dest + 1];
   for (int i = 0; i < dest + 1; i++)
   {
      dp[i] = INT32_MAX / 2;
   }
   dp[dest] = 1;
   for (int i = dest - 1; i >= 0; i--)
   {
      int Min = INT32_MAX / 2;
      for (int j = 1; j <= arr[i]; j++)
      {
         Min = min(Min, (j + i > dest) ? INT32_MAX / 2 : dp[i + j]);
      }
      dp[i] = Min + 1;
   }
   return dp[0];
}