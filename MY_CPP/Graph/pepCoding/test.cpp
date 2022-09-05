#include <bits/stdc++.h>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n, m, x;
      cin >> n >> m >> x;
      priority_queue<int> pq;
      stack<int> s;
      int pos[10000];
      for (int i = 0; i < 10000; i++)
      {
         pos[i] = 0;
      }
      for (int i = 0; i < n; i++)
      {
         int temp;
         cin >> temp;
         pq.push(temp);
         pos[temp] = i + 1;
      }
      while ((!pq.empty() && pq.top() >= m) || s.size() < x)
      {
         s.push(pq.top());
         pq.pop();
      }
      cout << s.size() << " ";
      priority_queue<int, vector<int>, greater<int>> res;
      while (!s.empty())
      {
         res.push(pos[s.top()]);
         s.pop();
      }
      while (!res.empty())
      {
         cout << res.top() << " ";
         res.pop();
      }
      cout << endl;
   }
   return 0;
}