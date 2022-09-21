// Given a number write an efficient program to print the largest prime factor
#include <iostream>
using namespace std;
long long int largestPrime(long long int n);
int main()
{
   long long int n;
   cin >> n;
   cout << largestPrime(n);
   return 0;
}
long long int largestPrime(long long int n)
{
   if (n == 1)
   {
      return 1ll;
   }
   else
   {
      long long int i = 2;
      int res = -1;
      while (n > 1)
      {
         while (n % i == 0)
         {
            n /= i;
            res = res > i ? res : i;
         }
         i++;
      }
      return res;
   }
}