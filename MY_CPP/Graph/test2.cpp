#include <iostream>
#include <string>
using namespace std;
int main()
{
   int t;
   cin >> t;
   int x = 0;
   while (t--)
   {
      x++;
      int n, k;
      cin >> n >> k;
      string s;
      getline(cin >> ws, s);
      int good = 0;
      for (int i = 0; i < n / 2; i++)
      {
         if (s[i] != s[n - i - 1])
         {
            good++;
         }
      }
      cout << "Case #" << x << ": ";
      if (good == k)
      {
         cout << 0;
      }
      else if (good > k)
      {
         cout << good - k;
      }
      else
      {
         cout << k - good;
      }
      // cout << good << " " << k;
      cout << endl;
   }
}