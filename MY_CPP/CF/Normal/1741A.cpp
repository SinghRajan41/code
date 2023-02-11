#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int check(int arr[], int n)
{
   for (int i = 1; i < n - 1; i++)
   {
      int cur = arr[i];
      int prev = arr[i - 1];
      int next = arr[i + 1];
      if (abs(prev - cur) != 1 && abs(next - cur) != 1)
         return false;
      if (cur == i + 1 || prev == i || next == i + 2)
         return false;
   }
   return true;
}
void solve(string a, string b)
{
   if (a[a.length() - 1] != b[b.length() - 1])
   {
      // Ending characters are not same
      if (a[a.length() - 1] < b[b.length() - 1])
      {
         cout << ">\n";
      }
      else
      {
         cout << "<\n";
      }
   }
   else
   {
      // Ending characters are same
      if (a.length() == b.length())
      {
         cout << "=\n";
      }
      else
      {
         // Unequal length
         if (a[a.length() - 1] == 'S')
         {
            if (a.length() > b.length())
            {
               cout << "<\n";
            }
            else
            {
               cout << ">\n";
            }
         }
         else
         {
            if (a.length() < b.length())
            {
               cout << "<\n";
            }
            else
            {
               cout << ">\n";
            }
         }
      }
   }
}
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      string a, b;
      cin >> a >> b;
      solve(a, b);
   }
   return 0;
}