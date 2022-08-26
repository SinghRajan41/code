#include <iostream>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n, p, x, y;
      cin >> n >> p >> x >> y;
      short int arr[n];
      for (int i = 0; i < n; i++)
      {
         cin >> arr[i];
      }
      long long int sum = 0;
      for (int i = 0; i < p; i++)
      {
         sum += (arr[i] == 1) ? y : x;
      }
      cout << sum << endl;
   }
}