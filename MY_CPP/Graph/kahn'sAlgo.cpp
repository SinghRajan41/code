#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
class graph
{
   int e, v;
   vector<int> *adj;

public:
   void inputGraph()
   {
      cin >> v >> e;
      adj = new vector<int>[v];
      for (int i = 0; i < e; i++)
      {
         int x, y;
         cin >> x >> y;
         adj[x].push_back(y);
      }
   }
   void printTopo();
};
void graph::printTopo()
{
   queue<int> res, q;
   int hash[v];
   for (int i = 0; i < v; i++)
   {
      hash[i] = 0;
   }
   for (int i = 0; i < v; i++)
   {
      for (int j = 0; j < adj[i].size(); j++)
      {
         hash[adj[i][j]]++;
      }
   }
   int count = 0;
   for (int i = 0; i < v; i++)
   {
      if (hash[i] == 0)
      {
         q.push(i);
      }
   }
   while (!q.empty())
   {
      int cur = q.front();
      q.pop();
      count++;
      res.push(cur);
      for (int i = 0; i < adj[cur].size(); i++)
      {
         hash[adj[cur][i]]--;
         if (hash[adj[cur][i]] == 0)
         {
            q.push(adj[cur][i]);
         }
      }
   }
   if (count == v)
   {
      while (!res.empty())
      {
         cout << res.front() << " ";
         res.pop();
      }
   }
   else
   {
      cout << -1;
   }
}
int main()
{
   graph g;
   g.inputGraph();
   g.printTopo();
   return 0;
}
// 6 6
// 0 1
// 0 5
// 3 4
// 2 3
// 5 2
// 5 1