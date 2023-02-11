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
      if (n > m)
      {
         cout << "No\n";
      }
      else
      {
         if (n & 1)
         {
            cout << "Yes\n";
            for (int i = 0; i < n - 1; i++)
            {
               cout << 1 << " ";
            }
            cout << m - n + 1 << endl;
         }
         else
         {
            if (m % 2 == 0)
            {
               cout << "Yes\n";
               for (int i = 0; i < n - 2; i++)
               {
                  cout << 1 << " ";
               }
               cout << ((m - n + 2) / 2) << " " << ((m - n + 2) / 2) << endl;
            }
            else
            {
               cout << "No\n";
            }
         }
      }
   }
}