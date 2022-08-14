#include <iostream>
#include <vector>
// Given a directed graph
// Find the transpose of the graph
// ie reverse the pointers
using namespace std;
vector<int> *adj;
int v, e;
void insertNode(int x, int y);
vector<int> *transpose(vector<int> *ADJ);
int main()
{
   cin >> v >> e;
   adj = new vector<int>[v + 1];
   for (int i = 0; i < e; i++)
   {
      int x, y;
      cin >> x >> y;
      insertNode(x, y);
   }
   for (int i = 0; i < v; i++)
   {
      cout << i << " -> ";
      for (int j = 0; j < adj[i].size(); j++)
      {
         cout << adj[i][j] << " ";
      }
      cout << endl;
   }
   adj = transpose(adj);
   cout << endl
        << endl;
   for (int i = 0; i < v; i++)
   {
      cout << i << " -> ";
      for (int j = 0; j < adj[i].size(); j++)
      {
         cout << adj[i][j] << " ";
      }
      cout << endl;
   }
   return 0;
}
vector<int> *transpose(vector<int> *ADJ)
{
   vector<int> *res = new vector<int>[v + 1];
   for (int i = 0; i < v; i++)
   {
      if (ADJ[i].size() > 0)
      {
         for (int j = 0; j < ADJ[i].size(); j++)
         {
            res[ADJ[i][j]].push_back(i);
         }
      }
   }
   return res;
}
void insertNode(int x, int y)
{
   adj[x].push_back(y);
}