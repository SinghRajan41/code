#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long int
void generatePrimes(vector<ll> &primes, ll r);
void find_primes(vector<ll> &primes, ll l, ll r);
int main()
{
   ll i, j, x, l, h;
   // cout << "Enter lower and upper limit=";
   cin >> l >> h;
   vector<ll> primes;
   generatePrimes(primes, h);
   bool dummy[h - l + 1];
   for (i = 0; i < h - l + 1; i++)
   {
      dummy[i] = 1;
   }
   for (i = 0; i < primes.size(); i++)
   {
      // cout << primes[i] << " ";
   }
   find_primes(primes, l, h);

   return 0;
}
void find_primes(vector<ll> &primes, ll l, ll r)
{
   bool dummy[r - l + 1];
   for (ll i = 0; i < r - l + 1; i++)
   {
      dummy[i] = 1;
   }

   for (ll i = 0; i < primes.size(); i++)
   {
      ll ff = (l / primes[i]) * primes[i];
      if (ff < l)
      {
         ff += primes[i];
      }
      ff = ff > primes[i] * primes[i] ? ff : primes[i] * primes[i];
      for (ll j = ff; j <= r; j += primes[i])
      {
         dummy[j - l] = 0;
      }
   }
   for (ll i = l; i <= r; i++)
   {
      if (dummy[i - l] == 1)
      {
         cout << i << " ";
      }
   }
}
void generatePrimes(vector<ll> &primes, ll r)
{
   int x = sqrt(r);
   bool arr[x + 1];
   for (int i = 0; i <= x; i++)
   {
      arr[i] = 1;
   }
   for (int i = 2; i <= x; i++)
   {
      if (arr[i] == 1)
      {
         for (int j = i * i; j <= x; j += i)
         {
            arr[j] = 0;
         }
      }
   }
   for (int i = 2; i <= x; i++)
   {
      if (arr[i] == 1)
         primes.push_back(i);
   }
}
