// Given a disconnected graph
// Print all the connected compenents
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class graph
{
   int v, e;
   vector<vector<int>> adj;

public:
   void inputGraph();
   void printConnected();
   void findCompo(bool visited[], int cur, string &path);
};
int main()
{
   graph g;
   g.inputGraph();
   g.printConnected();
   return 0;
}
void graph::findCompo(bool visited[], int cur, string &path)
{
   if (!visited[cur])
   {
      visited[cur] = true;
      for (int i = 0; i < v; i++)
      {
         if (adj[cur][i] != -1)
         {
            if (!visited[i])
            {
               path = path + to_string(cur);
               findCompo(visited, i, path);
            }
         }
      }
   }
}
void graph::printConnected()
{
   bool visited[v + 1] = {0};
   for (int i = 0; i < v; i++)
   {
      if (!visited[i])
      {
         string path = "";
         findCompo(visited, i, path);
         cout << path << endl;
      }
   }
}
void graph::inputGraph()
{
   cin >> v >> e;
   for (int i = 0; i <= v; i++)
   {
      vector<int> temp(v + 1, -1);
      adj.push_back(temp);
   }
   for (int i = 0; i < e; i++)
   {
      int x, y, w;
      cin >> x >> y >> w;
      adj[x][y] = w;
      adj[y][x] = w;
   }
}