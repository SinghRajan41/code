#include <iostream>
using namespace std;
// this method is suitable for a^b%m
// Where a,m <=10^18 && b<=10^9
int count = 0;
long long int binMulti(long long int a, long long int b, long long int m);
long long int binExp(long long int a, long long int b, long long int m)
{
   long long int res = 1;
   while (b > 0)
   {
      if (b & 1)
      {
         res = /* (res * 1LL * a) % m;*/ binMulti(res, a, m);
      }
      a = /*(a * 1LL * a) % m;*/ binMulti(a, a, m);
      b = b >> 1;
      count++;
   }
   return res;
}
long long int binMulti(long long int a, long long int b, long long int m)
{
   long long int res = 0;
   while (b > 0)
   {
      if (b & 1)
      {
         res = (res + a) % m;
      }
      b = b >> 1;
      a = (a + a) % m;
      count++;
   }
   return res;
}
int main()
{
   cout << binExp(1e16 + 7, 1e9 - 2, 1e16 + 2) << endl;
   cout << count;
   return 0;
}