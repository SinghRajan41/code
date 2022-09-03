#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class graph
{
public:
   int v, e;
   vector<int> *adj;
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
   void fillStack(stack<int> &s, int cur, bool visited[])
   {
      if (!visited[cur])
      {
         visited[cur] = true;
         for (int i = 0; i < adj[cur].size(); i++)
         {
            if (!visited[adj[cur][i]])
            {
               fillStack(s, adj[cur][i], visited);
            }
         }
         s.push(cur);
      }
   }
   void topoSort()
   {
      bool visited[v];
      for (int i = 0; i < v; i++)
      {
         visited[i] = false;
      }
      stack<int> s;
      for (int i = 0; i < v; i++)
      {
         if (!visited[i])
         {
            fillStack(s, i, visited);
         }
      }
      while (!s.empty())
      {
         cout << s.top() << " ";
         s.pop();
      }
   }
};
int main()
{
   graph g;
   g.inputGraph();
   cout << "Input Done\n";
   g.topoSort();
   return 0;
}