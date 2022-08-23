#include <iostream>
#include <set>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n, m;
      cin >> n >> m;
      set<int> s;
      for (int i = 0; i < n; i++)
      {
         int x;
         cin >> x;
         s.insert(x);
      }
      if (s.size() < m)
      {
         cout << "Yes\n";
      }
      else
      {
         cout << "No\n";
      }
   }
}