#include <iostream>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n, m;
      cin >> n >> m;
      int count = 0;
      for (int a = 1; a <= n; a++)
      {
         for (int b = a + 1; b <= n; b++)
         {
            if ((m % a) % b == (m % b) % a)
            {
               cout << a << " " << b << "\t\t";
               count += 1;
            }
         }
      }
      // cout << count << endl;
   }
   return 0;
}