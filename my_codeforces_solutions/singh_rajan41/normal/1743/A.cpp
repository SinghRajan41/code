#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ncr(int n, int r)
{
   return (n * (n - 1)) / 2;
}
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      int arr[n];
      for (int i = 0; i < n; i++)
         cin >> arr[i];
      cout << ncr(10 - n, 2) * 6 << endl;
   }
   return 0;
}