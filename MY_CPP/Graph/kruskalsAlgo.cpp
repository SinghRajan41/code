#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define pb(x) push_back(x)
using namespace std;
class graph
{
   int v, e;
   vector<pair<int, int>> *adj;

public:
   void inputGraph();
   void kruskalsAlgo();
};
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
   return a.second < b.second;
}
int main()
{
   graph g;
   g.inputGraph();
   g.kruskalsAlgo();
   return 0;
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
      adj[y].push_back(make_pair(x, w));
   }
   cout << "\nInput Done\n";
}
void graph::kruskalsAlgo()
{
   vector<pair<pair<int, int>, int>> arr;
   for (int i = 0; i < v; i++)
   {
      for (auto j : adj[i])
      {
         pair<pair<int, int>, int> p = {{i, j.first}, j.second};
         arr.push_back(p);
      }
   }
   sort(arr.begin(), arr.end(), cmp);
   int i = 0;
   int k = v - 1;
   bool visited[v];
   memset(visited, false, sizeof(visited));
   vector<pair<int, int>> res;
   for (; k && i < arr.size();)
   {
      pair<pair<int, int>, int> cur = arr[i];
      i += 2;
      if (!visited[cur.first.first] || !visited[cur.first.second])
      {
         visited[cur.first.first] = visited[cur.first.second] = true;
         res.pb(cur.first);
         k -= 1;
      }
   }
   for (auto i : res)
   {
      cout << i.first << " " << i.second << endl;
   }
}