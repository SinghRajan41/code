#include <iostream>
using namespace std;
int power(int a, int b)
{
   if (b == 0)
   {
      return 1;
   }
   else
   {
      int res = 1;
      for (int i = 0; i < b; i++)
      {
         res += a;
      }
      return res;
   }
}
int main()
{
   // Input a number n
   //  Add one to the number without using + operator
   int n = 21;
   cout << -(~n);
   return 0;
}