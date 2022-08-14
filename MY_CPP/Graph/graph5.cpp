#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct graph
{
   int v;
   vector<int> *adj;
};
graph *createGraph(int x)
{
   graph *g = new graph;
   g->v = x;
   g->adj = new vector<int>[x + 1];
   return g;
}
void DFSUtil(bool visited[], int i, graph *g);
int findMother(graph *g);
void fillStack(int i, graph *g, bool visited[], stack<int> &s);
void DFSUtil(bool visited[], int i, graph *g);
void insertNode(struct graph *g, int x, int y)
{
   g->adj[x].push_back(y);
}
int findMother(graph *g)
{
   stack<int> s;
   bool visited[g->v] = {0};
   for (int i = 0; i < g->v; i++)
   {
      if (visited[i] == 0)
      {
         fillStack(i, g, visited, s);
      }
   }
   int mother = s.top();
   for (int i = 0; i < g->v; i++)
   {
      visited[i] = 0;
   }
   DFSUtil(visited, mother, g);
   for (int i = 0; i < g->v; i++)
   {
      if (visited[i] == 0)
      {
         return -1;
      }
   }
   return mother;
}
void fillStack(int i, graph *g, bool visited[], stack<int> &s)
{
   if (visited[i] == 0)
   {
      visited[i] = 1;
      for (int j = 0; j < g->adj[i].size(); j++)
      {
         if (visited[g->adj[i][j]] == 0)
         {
            fillStack(g->adj[i][j], g, visited, s);
         }
      }
   }
   s.push(i);
}
void DFSUtil(bool visited[], int i, graph *g)
{
   if (visited[i] == 0)
   {
      visited[i] = 1;
      for (int j = 0; j < g->adj[i].size(); j++)
      {
         if (visited[g->adj[i][j]] == 0)
         {
            DFSUtil(visited, g->adj[i][j], g);
         }
      }
   }
}
int main()
{
   int v;
   cin >> v;
   graph *g = createGraph(v);
   int e;
   cin >> e;
   for (int i = 0; i < e; i++)
   {
      int x, y;
      cin >> x >> y;
      insertNode(g, x, y);
   }

   cout << findMother(g);
   return 0;
}