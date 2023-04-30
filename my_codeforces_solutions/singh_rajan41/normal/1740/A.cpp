#include <iostream>
#include <queue>
using namespace std;
bool s[200001];
int main()
{
   int t;
   cin >> t;
   for (int i = 0; i < 200001; i++)
   {
      s[i] = true;
   }
   for (int i = 2; i < 200001; i++)
   {
      if (s[i])
      {
         for (int j = 2 * i; j < 200001; j += i)
         {
            s[j] = false;
         }
      }
   }

   while (t--)
   {
      int n;
      cin >> n;
      for (int i = 2; i <= 100000; i++)
      {
         if (!s[n + i] && s[i])
         {
            cout << i << "\n";
            break;
         }
      }
   }
   return 0;
}