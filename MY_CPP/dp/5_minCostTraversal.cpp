/*
Given a m x n grid filled with non-negative numbers,
find the cost of a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
*/
#include <iostream>
#include <vector>
using namespace std;
int minCost(vector<vector<int>> &grid, int n, int m);
int _minCost(vector<vector<int>> &grid, int mem[101][101], int r, int c, int n, int m);
int inf = INT32_MAX / 2;
int n, m;
int main()
{
   cin >> n >> m;
   vector<vector<int>> grid;
   for (int i = 0; i < n; i++)
   {
      vector<int> temp(m, 0);
      grid.push_back(temp);
   }
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         cin >> grid[i][j];
      }
   }
   cout << minCost(grid, n, m) + grid[n - 1][m - 1];
   return 0;
}
int _minCost(vector<vector<int>> &grid, int mem[101][101], int r, int c, int n, int m)
{
   if (r == n - 1 && c == m - 1)
      return 0;
   if (r >= n || c >= m)
      return inf;
   if (mem[r][c] == -1)
   {

      int a = _minCost(grid, mem, r + 1, c, n, m);
      int b = _minCost(grid, mem, r, c + 1, n, m);
      mem[r][c] = min(a, b) + grid[r][c];
   }
   return mem[r][c];
}
int minCost(vector<vector<int>> &grid, int n, int m)
{
   int mem[101][101];
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         mem[i][j] = -1;
      }
   }
   return _minCost(grid, mem, 0, 0, n, m);
}