#include <iostream>
using namespace std;
bool isPrime(int n);
bool isPrime2(int n);
const int n = 1e4 + 5 * 1e3;
int hp[n] = {0};
int lp[n] = {0};
void inithp();
void initlp();
void primeFactors(int n);
int main()
{
   inithp();
   initlp();
   primeFactors(240);
   return 0;
}
void primeFactors(int n)
{
   while (n > 1)
   {
      int prime = hp[n];
      while (n % prime == 0)
      {
         cout << prime << " ";
         n = n / prime;
      }
   }
}
void inithp()
{
   for (int i = 2; i < n; i++)
   {
      if (hp[i] == 0)
      {
         hp[i] = i;
         for (int j = 2 * i; j < n; j += i)
         {
            hp[j] = i;
         }
      }
   }
}
void initlp()
{
   for (int i = 2; i < n; i++)
   {
      if (lp[i] == 0)
      {
         lp[i] = i;
         for (int j = i * i; j < n; j += i)
         {
            if (lp[j] == 0)
            {
               lp[j] = i;
            }
         }
      }
   }
}
bool isPrime2(int n)
{
   for (int i = 2; i * i <= n; i++)
   {
      if (n % i == 0)
      {
         return false;
      }
   }
   return true;
}
bool isPrime(int n)
{
   for (int i = 2; i < n; i++)
   {
      if (n % i == 0)
      {
         return false;
      }
   }
   return true;
}