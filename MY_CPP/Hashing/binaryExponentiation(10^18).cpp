#include <iostream>
using namespace std;
// this method is suitable for a^b%m
// Where a,m <=10^18 && b<=10^9
int binExp(int a, int b, int m)
{
   int res = 1;
   while (b > 0)
   {
      if (b & 1)
      {
         res = (res * 1LL * a) % m;
      }
      a = (a * 1LL * a) % m;
      b = b >> 1;
   }
   return res;
}
int main()
{
   cout << binExp(5, 4, 1);
   return 0;
}