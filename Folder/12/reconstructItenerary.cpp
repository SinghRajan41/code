#include <bits/stdc++.h>
using namespace std;
class cmp
{
public:
   bool operator()(string a, string b)
   {
      int n1 = a.length();
      int n2 = b.length();
      for (int i = 0; i < min(n1, n2); i++)
      {
         if (a[i] == b[i])
         {
            continue;
         }
         else
         {
            return a[i] > b[i];
         }
      }
      return n1 > n2;
   }
};

int main()
{
   std::priority_queue<string, vector<string>, cmp> pq;
   pq.push("rajan");
   pq.push("ashwin");
   pq.push("athish");
   pq.push("ayush");
   while (!pq.empty())
   {
      cout << pq.top() << " ";
      pq.pop();
   }
   return 0;
}
void dfs(string src, unordered_map<string, priority_queue<string, vector<string>, cmp>> &map, vector<string> &res)
{
   if (map[src].size())
   {
      cur = map[src].top();
      map[src].pop();
      dfs(cur, map, res);
      res.push_back(cur);
   }
}
vector<string> findItinerary(vector<vector<string>> &tickets)
{
   vector<string> res;
   unordered_map<string, priority_queue<string, vector<string>, cmp>> map;
   for (int i = 0; i < tickets.size(); i++)
   {
      map[tickets[i][0]].push(tickets[i][1]);
   }
   string src = "SRC";
   dfs(src, map, res);
   return res;
}