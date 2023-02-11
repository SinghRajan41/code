#include <iostream>
#include <algorithm>
using namespace std;
bool check(int arr[], int n, int k);
int solve(int arr[], int n);
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      int questions = 0;
      for (int i = 0; i < n; i++)
      {
         char ch;
         cin >> ch;
         if (ch == 'Q')
         {
            questions++;
         }
         else
         {
            questions--;
            if (questions < 0)
            {
               questions = 0;
            }
         }
      }
      if (questions == 0)
      {
         cout << "Yes\n";
      }
      else
      {
         cout << "No\n";
      }
   }
   return 0;
}