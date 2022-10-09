/*
Given a m x n grid filled with non-negative numbers,
find the a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
*/
#include <bits/stdc++.h>
using namespace std;
int n, m;
struct item
{
   int x;
   int y;
   int cost;
};
int minCost(vector<vector<int>> &grid);
class cmp
{
public:
   bool operator()(item a, item b)
   {
      return a.cost > b.cost;
   }
};
int main()
{
   cin >> n >> m;
   vector<vector<int>> grid(n, vector<int>(m, 0));
   for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
         cin >> grid[i][j];
   cout << minCost(grid);
   return 0;
}
int minCost(vector<vector<int>> &grid)
{
   priority_queue<item, vector<item>, cmp> pq;
   item i = {0, 0, grid[0][0]};
   pq.push(i);
   while (!pq.empty())
   {
      item cur = pq.top();
      pq.pop();
      if (cur.x == n - 1 && cur.y == m - 1)
      {
         return cur.cost;
      }
      else
      {
         if (cur.x + 1 < n && cur.y < m)
         {
            item temp = {cur.x + 1, cur.y, cur.cost + grid[cur.x + 1][cur.y]};
            pq.push(temp);
         }
         if (cur.y + 1 < m && cur.x < n)
         {
            item temp = {cur.x, cur.y + 1, cur.cost + grid[cur.x][cur.y + 1]};
            pq.push(temp);
         }
      }
   }
   return -1;
}