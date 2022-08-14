#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> *adj;
int v, e;
int countAtK(int k)
{
   queue<int> q1, q2;
   q1.push(0);
   q2.push(0);
   int count = 0;
   while (!q1.empty())
   {
      int cur = q1.front();
      q1.pop();
      int curLevel = q2.front();
      q2.pop();
      if (curLevel == k)
      {
         count++;
      }
      for (int i = 0; i < adj[cur].size(); i++)
      {
         q1.push(adj[cur][i]);
         q2.push(curLevel + 1);
      }
   }
   return count;
}
struct info
{
   int data;
   int level;
};
int countAtK2(int k)
{
   int count = 0;
   info temp;
   temp.data = 0;
   temp.level = 0;
   queue<info> q;
   q.push(temp);
   while (!q.empty())
   {
      temp = q.front();
      q.pop();
      if (temp.level == k)
      {
         count++;
      }
      for (int i = 0; i < adj[temp.data].size(); i++)
      {
         info x = {adj[temp.data][i], temp.level + 1};
         q.push(x);
      }
   }
   return count;
}
int main()
{
   cin >> v;
   adj = new vector<int>[v + 1];
   for (int i = 0; i < v - 1; i++)
   {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
   }
   int k;
   cin >> k;
   cout << countAtK2(k);
   return 0;
}