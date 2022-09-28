#include <iostream>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      string s;
      cin >> s;
      bool a[n + 1];
      for (int i = 0; i < n; i++)
         a[i + 1] = (s[i] == '1');
      int cost[n + 1];
      for (int i = n; i >= 1; i--)
      {
         for (int j = i; j <= n; j += i)
         {
            if (a[j])
               break;
            cost[j] = i;
         }
      }
      long long int tot = 0;
      for (int i = 1; i <= n; i++)
      {
         if (!a[i])
         {
            tot += cost[i];
         }
      }
      cout << tot << endl;
   }
   return 0;
}