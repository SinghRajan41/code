#include <bits/stdc++.h>
using namespace std;
int main()
{
   long long int t;
   cin >> t;
   while (t--)
   {
      long long int n;
      cin >> n;
      long long int arr[n];
      for (long long int i = 0; i < n; i++)
      {
         cin >> arr[i];
      }
      sort(arr, arr + n);
      long long int start = 0;
      long long int count = 1;
      for (long long int i = 1; i <= n; i++)
      {
         if (arr[i] < i + 1 - start)
         {
            count++;
            start = i;
         }
      }
      sort(arr, arr + n, greater<int>());
      start = 0;
      long long int count1 = 1;
      for (long long int i = 1; i <= n; i++)
      {
         if (arr[i] < i + 1 - start)
         {
            count1++;
            start = i;
         }
      }

      cout << (count < count1 ? count : count1) << endl;
   }
   return 0;
}