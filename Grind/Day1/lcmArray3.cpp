#include <iostream>
using namespace std;
int maxPow[100005];
void f(int n);
int main()
{
   for (int i = 0; i < 100005; i++)
   {
      maxPow[i] = 0;
   }
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   for (int i = 0; i < n; i++)
   {
      f(arr[i]);
   }
   long long int ans = 1;
   for (int i = 0; i < 100005; i++)
   {
      int j = maxPow[i];
      while (j--)
      {
         ans *= i;
      }
   }
   cout << ans;
   return 0;
}
void f(int n)
{
   int i = 2;
   while (n > 1)
   {
      int count = 0;
      while (n % i == 0)
      {
         count++;
         n /= i;
      }
      maxPow[i] = (maxPow[i] > count) ? maxPow[i] : count;
      i++;
   }
}