// Optimised approach for finding nearest zero to every one
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
pair<int, int> moveLeft(pair<int, int> p, int n)
{
   pair<int, int> r = {p.first, p.second - 1 >= 0 ? p.second - 1 : p.second};
   return r;
}
pair<int, int> moveRight(pair<int, int> p, int n)
{
   pair<int, int> r = {p.first, p.second + 1 < n ? p.second + 1 : p.second};
   return r;
}
pair<int, int> moveUp(pair<int, int> p, int n)
{
   pair<int, int> r = {p.first - 1 >= 0 ? p.first - 1 : p.first, p.second};
   return r;
}
pair<int, int> moveDown(pair<int, int> p, int n)
{
   pair<int, int> r = {p.first + 1 < n ? p.first + 1 : p.first, p.second};
   return r;
}
void printNearest(vector<vector<int>> &arr, int n)
{
   int dist[n][n];
   queue<pair<int, int>> q;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (arr[i][j] == 0)
         {
            dist[i][j] = 0;
            pair<int, int> p = {i, j};
            q.push(p);
         }
         else
         {
            dist[i][j] = -1;
         }
      }
   }
   while (!q.empty())
   {
      pair<int, int> cur = q.front();
      q.pop();
      // cout << cur.first << " " << cur.second << endl;
      pair<int, int> a, b, c, d;
      a = moveLeft(cur, n);
      b = moveRight(cur, n);
      c = moveUp(cur, n);
      d = moveDown(cur, n);
      if (dist[a.first][a.second] == -1)
      {
         dist[a.first][a.second] = dist[cur.first][cur.second] + 1;
         q.push(a);
      }
      if (dist[b.first][b.second] == -1)
      {
         dist[b.first][b.second] = dist[cur.first][cur.second] + 1;
         q.push(b);
      }
      if (dist[c.first][c.second] == -1)
      {
         dist[c.first][c.second] = dist[cur.first][cur.second] + 1;
         q.push(c);
      }
      if (dist[d.first][d.second] == -1)
      {
         dist[d.first][d.second] = dist[cur.first][cur.second] + 1;
         q.push(d);
      }
   }
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         cout << dist[i][j] << " ";
      }
      cout << endl;
   }
}
int main()
{
   int n;
   cin >> n;
   vector<vector<int>> arr;
   for (int i = 0; i < n; i++)
   {
      vector<int> temp(n, 0);
      arr.push_back(temp);
   }
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         cin >> arr[i][j];
      }
   }
   printNearest(arr, n);
   return 0;
}