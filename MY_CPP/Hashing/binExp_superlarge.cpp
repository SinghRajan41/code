#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int phi(int);
// int phi(int n)
// {
//    if (n < 1)
//    {
//       return -1;
//    }
//    int count = 0;
//    for (int i = 1; i < n; i++)
//    {
//       if (__gcd(n, i) == 1)
//       {
//          count++;
//       }
//    }
//    return count;
// }
int binExp(int a, int b, int m)
{
   int res = 1;
   while (b > 0)
   {
      if (b & 1)
      {
         res = (res * 1LL * a) % m;
      }
      b = b >> 1;
      a = (a * 1LL * a) % m;
   }
   return res;
}
int largeExpo(int a, string b, int m)
{
   // a,m <= 10^9  b has 1=^5 digits
   int ans = 0;
   int n = b.length();
   int x = m;
   m = phi(m);
   for (int i = n - 1; i > -1; i--)
   {
      ans = (ans + (b[i] - '0') * 1LL * binExp(10, n - i - 1, m) % m) % m;
   }
   return binExp(a, ans, x);
}
int bModM(vector<int> b, int m)
{
   int ans = 0;
   int n = b.size();
   for (int i = b.size() - 1; i > -1; i--)
   {
      ans = (ans + ((b[i] % m * binExp(10, n - i - 1, m) % m)) % m) % m;
   }
   return ans;
}
int phi(int n)
{
   int count = 0;
   for (int i = 1; i < n; i++)
   {
      if (__gcd(i, n) == 1)
      {
         count++;
      }
   }
   return count;
}
int main()
{
   // int a, m;
   // string b;
   // // cout << "\nenter a=";
   // cin >> a;
   // // cout << "\nenter b=";
   // getline(cin >> ws, b);
   // // cout << "\nenter m=";
   // cin >> m;
   // cout << largeExpo(a, b, m);
   // int a = 2;
   // int arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
   // vector<int> b(arr, arr + 18);
   // int m = 54;
   // cout << bModM(b, m);
   cout << phi(1337);
   return 0;
}