#include <iostream>
using namespace std;
long long int path1(long long int n);
long long int path2(long long int n);
long long int path3(long long int n);
long long *arr;
void init();
int main()
{
   init();
   cout << path3(100);
   return 0;
}
long long int path3(long long int n)
{
   long long int dp[n + 1];
   dp[0] = dp[1] = 1;
   dp[2] = 2;
   for (int i = 3; i <= n; i++)
   {
      dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]);
   }
   return dp[n];
}
void init()
{
   arr = new long long int[100001];
   for (int i = 0; i < 100001; i++)
   {
      arr[i] = -1;
   }
   arr[0] = arr[1] = 1;
   arr[2] = 2;
}
long long int path2(long long int n)
{
   if (n < 0)
   {
      return 0;
   }
   if (n == 0 || n == 1)
   {
      return 1;
   }
   if (arr[n] != -1)
   {
      return arr[n];
   }
   else
   {
      arr[n] = path2(n - 1) + path2(n - 2) + path2(n - 3);
      return arr[n];
   }
}
long long int path1(long long int n)
{
   if (n < 0)
   {
      return 0ll;
   }
   if (n == 0 || n == 1)
   {
      return 1ll;
   }
   return path1(n - 1) + path1(n - 2) + path1(n - 3);
}