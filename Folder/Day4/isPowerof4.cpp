#include <iostream>
using namespace std;
bool power4(long long int n);
int main()
{
   long long int num;
   cin >> num;
   for (int i = 1; i <= 100; i++)
   {
      cout << i << " -> " << (power4(i) ? "Yes\n" : "No\n");
   }
   return 0;
}
bool power4(long long int n)
{
   while (n > 1)
   {
      if (n % 4)
      {
         return false;
      }
      n >>= 2;
   }
   return true;
}