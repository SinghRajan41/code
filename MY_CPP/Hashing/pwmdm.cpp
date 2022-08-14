#include <iostream>
using namespace std;
const int m = 51;
int pwmdm(int a, int b)
{
   if (b == 0)
   {
      return 1;
   }
   if (b % 2 == 0)
   {
      int t = pwmdm(a, b / 2);
      return (1LL * t * t) % m;
   }
   else
   {
      int t = pwmdm(a, (b - 1) / 2);
      return (a * 1LL * t * t) % m;
   }
}
int power(int a, int b)
{
   int res = 1;
   while (b--)
   {
      res *= a;
   }
   return res;
}
int main()
{
   int a, b;
   cin >> a >> b;
   cout << power(a, b) % m << endl;
   cout << pwmdm(a, b);
   return 0;
}