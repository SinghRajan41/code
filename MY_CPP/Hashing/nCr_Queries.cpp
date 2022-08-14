#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
int fac[N];
int binExpRec(int a, int b, int m)
{
   if (b == 0)
   {
      return 1;
   }
   int t = binExpRec(a, b / 2, m);
   if (b & 1)
   {
      return (a * 1LL * t * t) % m;
   }
   else
   {
      return (t * 1LL * t) % m;
   }
}
int binExpIter(int a, int b, int m)
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

int gcd(int a, int b)
{
   if (a == 0)
      return b;
   return gcd(b % a, a);
}
void initialise();
int main()
{
   initialise();
   cout << binExpIter(N, M - 2, M) << " " << binExpRec(N, M - 2, M) << endl;
   return 0;
}
void initialise()
{
   fac[0] = 1;
   for (int i = 1; i < N; i++)
   {
      fac[i] = (fac[i - 1] * 1LL * i) % M;
   }
}