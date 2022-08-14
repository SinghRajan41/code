#include <iostream>
using namespace std;
int power(int a, int b)
{
   if (b == 0)
   {
      return 1;
   }
   if (b % 2 == 0)
   {
      int t = power(a, b / 2);
      return (t * t);
   }
   else
   {
      int t = power(a, (b - 1) / 2);
      return (a * t * t);
   }
}
int main()
{
   cout << power(5, 8);
   return 0;
}