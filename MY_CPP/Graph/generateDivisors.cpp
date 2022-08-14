#include <iostream>
using namespace std;
void generateDivisors(int n)
{
   for (int i = 1; i <= 24; i++)
   {
      if (n % i == 0)
      {
         cout << i << " ";
      }
   }
}
void generateDivisors2(int n)
{
   // O(sqrt(n))
   for (int i = 1; i * i <= n; i++)
   {
      if (n % i == 0)
      {
         cout << i << " ";
         if (n / i != i)
         {
            cout << n / i << " ";
         }
      }
   }
}
int main()
{
   generateDivisors2(36);
   return 0;
}