#include <iostream>
#include <vector>
using namespace std;
class graph
{
   vector<int> *g;
   int v, e;

public:
   graph();
   void showGraph();
   void dfs(int i);
   void dfsUtil(int i, bool visited[]);
   void printMother();
};
int main()
{
   graph g;
   g.printMother();
   return 0;
}
void graph::printMother()
{
   for (int i = 1; i <= v; i++)
   {
      bool visited[v + 1] = {0};
      dfsUtil(i, visited);
      bool isMother = true;
      for (int j = 1; j <= v; j++)
      {
         if (visited[j] == 0)
         {
            isMother = false;
            break;
         }
      }
      if (isMother)
      {
         cout << i << " ";
      }
   }
}
void graph::dfsUtil(int i, bool visited[])
{
   if (visited[i] == 0)
   {
      // cout << i << " ";
      visited[i] = 1;
      for (int j = 0; j < g[i].size(); j++)
      {
         if (visited[g[i][j]] == 0)
         {
            dfsUtil(g[i][j], visited);
         }
      }
   }
}
void graph::dfs(int i)
{
   bool visited[v + 1] = {0};
   dfsUtil(i, visited);
}
void graph::showGraph()
{
   for (int i = 1; i <= v; i++)
   {
      cout << i << " -> ";
      for (int j = 0; j < g[i].size(); j++)
      {
         cout << g[i][j] << " ";
      }
      cout << endl;
   }
}
graph::graph()
{
   cin >> v >> e;
   g = new vector<int>[v + 1];
   for (int i = 0; i < e; i++)
   {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
   }
}
