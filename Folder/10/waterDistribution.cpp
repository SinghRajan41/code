#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define pb(x) push_back(x)
// Given a network of cities and the cost of connecting two cities with water pipeline
// Also given the cost of digging well in every city
// Find the minimum cost to connect all cities
using namespace std;
class graph
{
public:
   vector<int> well;
   vector<pair<int, int>> *adj;
   int v, e;
   void inputGraph();
   int distributeWater();
};
int main()
{
   graph g;
   g.inputGraph();
   cout << g.distributeWater();
   return 0;
}
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
   return a.second < b.second;
}
int graph::distributeWater()
{
   // Implementing kruskals algo
   vector<pair<pair<int, int>, int>> arr, res;
   for (int i = 0; i <= v; i++)
   {
      for (int j = 0; j < adj[i].size(); j++)
      {
         pair<pair<int, int>, int> p = {{i, adj[i][j].first}, adj[i][j].second};
         arr.pb(p);
      }
   }
   sort(arr.begin(), arr.end(), cmp);
   int i = 0, cost = 0;
   int k = v - 1;
   bool visited[v + 1];
   memset(visited, false, sizeof(visited));
   for (; k && i < arr.size();)
   {
      pair<pair<int, int>, int> p = arr[i];
      i += 2;
      if (!visited[p.first.first] || !visited[p.first.second])
      {
         visited[p.first.first] = visited[p.first.second] = true;
         k -= 1;
         res.pb(p);
         cost += p.second;
      }
   }
   for (auto i : res)
   {
      cout << i.first.first << " " << i.first.second << endl;
   }
   return cost;
}
void graph::inputGraph()
{
   cin >> v >> e;
   adj = new vector<pair<int, int>>[v + 1];
   for (int i = 0; i < e; i++)
   {
      int x, y, w;
      cin >> x >> y >> w;
      adj[x].push_back(make_pair(y, w));
      adj[y].push_back(make_pair(x, w));
   }
   well.push_back(0);
   for (int i = 1; i <= v; i++)
   {
      int x;
      cin >> x;
      well.push_back(x);
      adj[0].push_back(make_pair(i, x));
      adj[i].push_back(make_pair(0, x));
   }
   cout << "\nInput Done\n";
}