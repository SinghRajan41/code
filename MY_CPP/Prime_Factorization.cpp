#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
   int n;
   cin >> n;
   int c = 2;
   while (n > 1)
   {
      if (n % c == 0)
      {
         n /= c;
         cout << c << " ";
      }
      else
      {
         ++c;
      }
   }
   return 0;
}