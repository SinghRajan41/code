#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;
long long int smallestPrime(ll i);
void generateSeive(int n);
bool *s = NULL;
void generateSeive(int n)
{
   // 10^5
   n += 2;
   s = new bool[n];
   for (int i = 0; i <= n; i++)
   {
      s[i] = 1;
   }
   for (int i = 2; i <= n; i++)
   {
      if (s[i] == 1)
      {
         for (long long int j = i * i; j <= n; j += i)
         {
            s[j] = 0;
         }
      }
   }
}
ll smallestPrime(ll i)
{
   if (i == 1)
   {
      return 1;
   }
   else if (i == 2)
   {
      return 2;
   }
   else if (i == 3)
   {
      return i;
   }
   else
   {
      // Write a code to find smallest prime factor of the number i
      for (int j = 2; j <= i; j++)
      {
         if (s[j] == 1 && i % j == 0)
         {
            return j;
         }
      }
      cout << "Smallest Prime number not found\nReturning -1";
      return -1;
   }
}
int main()
{
   long long int n;
   cin >> n;
   generateSeive(n);
   for (long long int i = 1; i <= n; i++)
   {
      cout << i << "->" << smallestPrime(i) << endl;
   }
   delete[] s;
   return 0;
}
bool s[n + 3];
for (int i = 0; i <= n + 2; i++)
{
   s[i] = 1;
}
for (int i = 2; i <= n + 2; i++)
{
   if (s[i] == 1)
   {
      for (int j = i * i; j <= n + 2; j += i)
      {
         s[j] = 0;
      }
   }
}

// Traverse from 1 to n find and push back the least prime numbers in the result vector
vector<int> res(n + 1, 0);
for (int i = 1; i <= n; i++)
{
   // Find the least prime for i
   if (i == 1)
   {
      res[i] = 1;
   }
   else if (i == 2)
   {
      res[i] = 2;
   }
   else
   {
      for (int j = 2; j <= i; j++)
      {
         if (i % j == 0 && s[j] == 1)
         {
            res[i] = j;
            break;
         }
      }
   }
}
