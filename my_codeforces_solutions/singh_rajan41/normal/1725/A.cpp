#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
   int t = 1;
   while (t--)
   {
      long long int a, b;
      cin >> a >> b;
      if (b == 1)
      {
         cout << a - 1 << endl;
      }
      else
      {
         cout << a * (b - 1) << endl;
      }
   }
   return 0;
}