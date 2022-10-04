// Given n cities
// Alice and bob want to visit every city
// Given three types of edges connecting the cities
// Type 3 can be accessed by both alice and bob
// Type 2 can be accessed by only bob
// Type 1 can be accessed by only alice
// Find the maximum number of edges that can be removed and still keep bob and alice coonected to all n cities
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class dsu
{
   int n, groups;
   int *parent, *size;

public:
   dsu(int x)
   {
      n = groups = x;
      parent = new int[n + 1];
      size = new int[n + 1];
      for (int i = 0; i <= n; i++)
      {
         parent[i] = i;
         size[i] = 1;
      }
   }
   int find(int x)
   {
      if (parent[x] == x)
      {
         return x;
      }
      else
      {
         int temp = find(parent[x]);
         parent[x] = temp;
         return temp;
      }
   }
   bool Union(int a, int b)
   {
      int pa = find(a);
      int pb = find(b);
      if (pa != pb)
      {
         if (size[pa] > size[pb])
         {
            swap(pa, pb);
         }
         parent[pa] = pb;
         size[pb] += size[pa];
         groups--;
         return true;
      }
      return false;
   }
};
int removeMaxEdge(vector<pair<int, pair<int, int>>> edges, int n);
int main()
{
   int n, e;
   cin >> n >> e;
   vector<pair<int, pair<int, int>>> edges;
   for (int i = 0; i < e; i++)
   {
      int type, u, v;
      cin >> type >> u >> v;
      edges.push_back(make_pair(type, make_pair(u, v)));
   }
   cout << "Input Done\n";
   cout << removeMaxEdge(edges, n);
   return 0;
}
int removeMaxEdge(vector<pair<int, pair<int, int>>> edges, int n)
{
   dsu alice(n), bob(n);
   int removed = 0;
   for (int i = 0; i < edges.size(); i++)
   {
      if (edges[i].first == 3)
      {
         bool temp = (!alice.Union(edges[i].second.first, edges[i].second.second)) && (!bob.Union(edges[i].second.first, edges[i].second.second));
         if (temp)
         {
            removed++;
            cout << edges[i].second.first << " " << edges[i].second.second << endl;
         }
      }
   }
   for (int i = 0; i < edges.size(); i++)
   {
      if (edges[i].first == 1)
      {
         if (alice.Union(edges[i].second.first, edges[i].second.second))
         {
            removed++;
            cout << edges[i].second.first << " " << edges[i].second.second << endl;
         }
      }
      else if (edges[i].first == 2)
      {
         if (bob.Union(edges[i].second.first, edges[i].second.second))
         {
            removed++;
            cout << edges[i].second.first << " " << edges[i].second.second << endl;
         }
      }
   }
   return removed;
}