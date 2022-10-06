#include <iostream>
using namespace std;
int fib(int n);
long long int fib2(long long int n);
long long int *arr;
long long int M = 1000000000000000009ll;
long long int fib3(long long int n);
int main()
{
   arr = new long long int[300000];
   fib3(300000ll);
   return 0;
}
long long int fib3(long long int n)
{
   arr[0] = 0;
   arr[1] = 1;
   for (int i = 2; i < 300000; i++)
   {
      arr[i] = (arr[i - 1] % M + arr[i - 2] % M) % M;
      cout << i << " -> " << arr[i] << endl;
   }
   return 1ll;
}
long long int fib2(long long int n)
{
   if (n == 0 || n == 1)
   {
      return n;
   }
   else
   {
      if (arr[n] != -1)
      {
         return arr[n];
      }
      else
      {
         arr[n] = (fib2(n - 1) % M + fib2(n - 2) % M) % M;
         return arr[n];
      }
   }
}
int fib(int n)
{
   if (n == 0 || n == 1)
   {
      return n;
   }
   else
   {
      return fib(n - 1) + fib(n - 2);
   }
}