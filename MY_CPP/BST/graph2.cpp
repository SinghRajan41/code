#include <iostream>
#include <vector>
using namespace std;
int main()
{
   int v, e;
   cin >> v >> e;
   vector<int> g[v + 1];
   for (int i = 0; i < e; i++)
   {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
   }
   for (int i = 1; i < v + 1; i++)
   {
      for (int j = 0; j < g[i].size(); j++)
      {
         cout << g[i][j] << " ";
      }
      cout << endl;
   }
   return 0;
}