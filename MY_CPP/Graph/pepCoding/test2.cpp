#include <bits/stdc++.h>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      int arr[n];
      for (int i = 0; i < n; i++)
      {
         cin >> arr[i];
      }
      int petrol = arr[0];
      int i = 1;
      while (i < n && petrol > 0)
      {
         petrol--;
         petrol += arr[i++];
      }
      if (petrol == 0)
      {
         cout << i - 1 << endl;
      }
      else
      {
         cout << i - 1 + petrol << endl;
      }
   }
   return 0;
}