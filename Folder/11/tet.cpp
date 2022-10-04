
#include <iostream>
using namespace std;
long long int gcd(long long int a, long long int b)
{
   if (a == 0)
   {
      return b;
   }
   else
   {
      return gcd(a % b, a);
   }
}
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int x, y, z;
      cin >> x >> y >> z;
      cout << gcd(x, gcd(y, z)) << endl;
   }
   return 0;
}