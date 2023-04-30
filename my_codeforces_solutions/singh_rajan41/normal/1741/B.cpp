#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int check(int arr[], int n)
{
   for (int i = 1; i < n - 1; i++)
   {
      int cur = arr[i];
      int prev = arr[i - 1];
      int next = arr[i + 1];
      if (abs(prev - cur) != 1 && abs(next - cur) != 1)
         return false;
      if (cur == i + 1 || prev == i || next == i + 2)
         return false;
   }
   return true;
}
void solve(int n)
{
   if (n == 3)
   {
      cout << "-1\n";
      return;
   }
   for (int i = 3; i <= n; i++)
      cout << i << " ";
   cout << "2 1\n";
}
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      solve(n);
   }
   return 0;
}