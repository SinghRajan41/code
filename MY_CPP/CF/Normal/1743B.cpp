#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check(int arr[], string &s, int n);
bool cmp(int a, int b)
{
   return a > b;
}
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
         arr[i] = i + 1;
      swap(arr[1], arr[n - 1]);
      for (int i = 0; i < n; i++)
         cout << arr[i] << " ";
      cout << "\n";
   }
   return 0;
}
bool check(int arr[], string &s, int n)
{
   vector<int> a, b;
   int i, j;
   if (n != s.length())
      return false;
   int t[51];
   for (int i = 0; i < 51; i++)
      t[i] = 0;
   for (int i = 0; i < n; i++)
      t[arr[i]]++;
   sort(t, t + 51, cmp);
   for (int i = 0; i < 51; i++)
      if (t[i] != 0)
      {
         b.push_back(t[i]);
      }
   for (int i = 0; i < 51; i++)
      t[i] = 0;
   for (int i = 0; i < s.length(); i++)
      t[s[i] - 'a'] += 1;
   sort(t, t + 26, cmp);
   for (int i = 0; i < 26; i++)
      if (t[i] != 0)
         a.push_back(t[i]);
   int p = a.size();
   int q = b.size();
   i = j = 0;
   /*for (auto i : a)
   {
      cout << i << " ";
   }
   cout << endl;
   for (auto j : b)
   {
      cout << j << " ";
   }
   cout << endl;
   cout << p << endl;*/
   while (i < p && j < q)
   {
      a[i] -= b[j];
      if (a[i] < 0)
         return false;
      if (a[i] == 0)
         i++;
      j++;
   }

   if (a[p - 1] == 0)
      return true;
   else
      return false;
}