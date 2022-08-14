#include <iostream>
#include <unordered_set>
using namespace std;
const int M = 7;
int binExp(int a, int b, int m)
{
   if (b == 0)
   {
      return 1;
   }
   int t = binExp(a, b / 2, m);
   if (b & 1)
   {
      return (a * 1LL * t * t) % m;
   }
   else
   {
      return (t * 1LL * t) % m;
   }
}
int main()
{
   int a, b, m;
   cin >> a >> b >> m;
   a = a % m;
   b = binExp(b % m, m - 2, m);
   cout << a * b % m;
   return 0;
}