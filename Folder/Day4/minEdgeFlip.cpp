// Given a directed graph
// Given a source node and destination node
// Find the minimum number of edge flips required to reach the destination from the source
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int minFlips(vector<pair<int, int>> &g, int src, int dest, int v);
bool cmp(pair<int, int> a, pair<int, int> b)
{
   return a.second < b.second;
}
int main()
{
   int v, e;
   cin >> v >> e;
   vector<pair<int, int>> g[v + 1];
   for (int i = 0; i < e; i++)
   {
      int x, y;
      cin >> x >> y;
      g[x].push_back(make_pair(y, 0));
   }
   int src, dest;
   cin >> src >> dest;
   cout << minFlips(g, src, dest);

   return 0;
}
int minFlips(vector<pair<int, int>> &g, int src, int dest, int v)
{
   if (src == dest)
   {
      return 0;
   }
   else
   {
      for (int i = 1; i <= v; i++)
      {
         for (int j = 0; j < g[i].size(); j++)
         {
            g[g[i].first].push_back(make_pair(i, 1000 - 1));
         }
      }
      bool visited[v + 1];
      memset(visited, false, sizeof(visited));
      std::priority_queue<pair<int, int>> pq;
      pq.push(make_pair < src, 1000 - 0);
      while (!pq.empty())
      {
         pair<int, int> cur = pq.front();
         pq.pop();
         if (cur.first == dest)
         {
            return cur.second;
         }
         else
         {
            if (!visited[cur.first])
            {
               visited[cur.first] = true;
               for (int i = 0; i < g[cur.first].size(); i++)
               {
                  int cost = cur.second;
                  int node = cur.first;
                  pair<int, int> p = {g[node].first, g[node].second + cost};
                  pq.push(p);
               }
            }
         }
      }
      return -1;
   }
}