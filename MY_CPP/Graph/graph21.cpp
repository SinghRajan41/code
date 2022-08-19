#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int, int>>> adj;
int v, e;
void inputGraph();
int main()
{
   inputGraph();
   return 0;
}
void inputGraph()
{
   cin >> v >> e;
   for (int i = 0; i <= v; i++)
   {
      vector<pair<int, int>> temp(v + 1, make_pair(-1, -1));
      adj.push_back(temp);
   }
   for (int i = 0; i < e; i++)
   {
      int x, y, xx, yy;
      cin >> x >> y >> xx >> yy;
      adj[x][y].first = xx;
      adj[x][y].second = yy;
      adj[xx][yy].first = x;
      adj[xx][yy].second = y;
   }
   for (int i = 1; i <= v; i++)
   {
      for (int j = 1; j < adj[i].size(); j++)
      {
         cout << adj[i][j].first << "," << adj[i][j].second << "\t";
      }
      cout << endl;
   }
}