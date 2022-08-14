#include <bits/stdc++.h>
#define ll long long int
#define PP 1000000007
const int N = 1000001;
using namespace std;
ll factorialNumInverse[N + 1];
ll naturalNumInverse[N + 1];
ll fact[N + 1];
void InverseofNumber(ll p)
{
   naturalNumInverse[0] = naturalNumInverse[1] = 1;
   for (int i = 2; i <= N; i++)
      naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(ll p)
{
   factorialNumInverse[0] = factorialNumInverse[1] = 1;
   for (int i = 2; i <= N; i++)
      factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
void factorial(ll p)
{
   fact[0] = 1;
   for (int i = 1; i <= N; i++)
   {
      fact[i] = (fact[i - 1] * i) % p;
   }
}
ll Binomial(ll N, ll R, ll p)
{
   ll ans = ((fact[N] * factorialNumInverse[R]) % p * factorialNumInverse[N - R]) % p;
   return ans;
}

int main()
{
   ll t, i, j, n, x, y, z, l, r;
   cin >> t;
   InverseofNumber(PP);
   InverseofFactorial(PP);
   factorial(PP);
   while (t--)
   {
      cin >> n >> l >> r;

      for (i = l; i <= r; i++)
      {
         if (n & 1)
         {
            if (i & 1)
            {

               cout << Binomial(n, (i + n) / 2, PP) << " ";
            }
            else
            {
               cout << 0 << " ";
            }
         }
         else
         {
            if (i & 1)
            {

               cout << 0 << " ";
            }
            else
            {
               cout << Binomial(n, (i + n) / 2, PP) << " ";
            }
         }
      }
      cout << endl;
   }
}
