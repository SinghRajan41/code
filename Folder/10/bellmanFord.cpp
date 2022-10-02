#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct item
{
   int u;
   int v;
   int w;
};
class graph
{
   vector<pair<int, int>> *adj;
   int v, e;

public:
   void inputGraph();
   void bellManFord(int src);
};
int main()
{
   graph g;
   g.inputGraph();
   int src;
   cin >> src;
   g.bellManFord(src);
   return 0;
}
void graph::bellManFord(int src)
{
   vector<int> dist(v, INT32_MAX / 2);
   dist[src] = 0;
   vector<item> arr;
   for (int i = 0; i < v; i++)
   {
      for (int j = 0; j < adj[i].size(); j++)
      {
         item temp = {i, adj[i][j].first, adj[i][j].second};
         arr.push_back(temp);
      }
   }
   for (int i = 0; i < 1; i++)
   {
      for (int j = 0; j < arr.size(); j++)
      {
         if (arr[j].w + dist[arr[j].u] < dist[arr[j].v])
         {
            dist[arr[j].v] = arr[j].w + dist[arr[j].u];
         }
      }
   }

   for (auto i : dist)
   {
      cout << i << " ";
   }
   cout << endl;
}
void graph::inputGraph()
{
   cin >> v >> e;
   adj = new vector<pair<int, int>>[v];
   for (int i = 0; i < e; i++)
   {
      int x, y, w;
      cin >> x >> y >> w;
      adj[x].push_back(make_pair(y, w));
   }
}