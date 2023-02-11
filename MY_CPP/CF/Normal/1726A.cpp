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
      int Max = -1;
      int arr[n];
      for (int i = 0; i < n; i++)
      {
         cin >> arr[i];
      }
      for (int i = 0; i < n; i++)
      {
         int diff = (arr[(i + 1) % n] - arr[i]);
         Max = max(Max, -diff);
      }
      for (int i = 0; i < n; i++)
      {
         Max = max(Max, arr[n - 1] - arr[i]);
      }
      for (int i = 0; i < n; i++)
      {
         Max = max(Max, arr[i] - arr[0]);
      }
      cout << Max << endl;
   }
   return 0;
}