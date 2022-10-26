/*
In this problem you are given a number n.
All we need to print is the number of binary strings of length n with no consecutive 0's
*/
#include <iostream>
using namespace std;
int count(int n);
int main()
{
   int n;
   cin >> n;
   cout << count(n);
   return 0;
}
int count(int n)
{
   int dp0[n + 1];
   int dp1[n + 1];
   dp0[1] = dp1[1] = 1;
   for (int i = 2; i <= n; i++)
   {
      dp0[i] = dp1[i - 1];
      dp1[i] = dp0[i - 1] + dp1[i - 1];
   }
   return dp0[n] + dp1[n];
}