#include <iostream>
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
   int v, e;
   vector<pair<int, int>> *adj;

public:
   void inputGraph()
   {
      cin >> v >> e;
      adj = new vector<pair<int, int>>[v];
      for (int i = 0; i < v; i++)
      {
         int x, y, w;
         cin >> x >> y >> w;
         adj[x].push_back(make_pair(y, w));
      }
   }
   bool detectNegCycle()
   {
      vector<item> arr;
      for (int i = 0; i < v; i++)
      {
         for (int j = 0; j < adj[i].size(); j++)
         {
            item p = {i, adj[i][j].first, adj[i][j].second};
            arr.push_back(p);
         }
      }
      vector<int> dist(v);
      for (int i = 0; i < v; i++)
      {
         dist[i] = INT32_MAX / 2;
      }
      dist[0] = 0; // Assuming 0 is the source
      for (int i = 0; i < v - 1; i++)
      {
         for (int j = 0; j < arr.size(); j++)
         {
            int u, v, w;
            u = arr[j].u;
            v = arr[j].v;
            w = arr[j].w;
            if (dist[u] + w < dist[v])
            {
               dist[v] = dist[u] + w;
            }
         }
      }
      for (int i = 0; i < arr.size(); i++)
      {
         int u, v, w;
         u = arr[i].u;
         v = arr[i].v;
         w = arr[i].w;
         if (dist[u] + w < dist[v])
         {
            return true;
         }
      }
      return false;
   }
};
int main()
{
   graph g;
   g.inputGraph();
   cout << (g.detectNegCycle() ? "Negative Cycle Detected" : "Negative Cycle Nweot detected");
   return 0;
}