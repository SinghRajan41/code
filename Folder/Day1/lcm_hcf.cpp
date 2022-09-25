#include <iostream>
using namespace std;
long long int gcd(long long int a, long long int b)
{
   if (a == 0)
   {
      return b;
   }
   return gcd(b % a, a);
}

int main()
{
   int a, b;
   cin >> a >> b;
   cout << "HCF=" << gcd((int)a, (int)b) << endl;
   cout << "LCM=" << (a * b) / gcd((int)a, (int)b) << endl;
   return 0;
}