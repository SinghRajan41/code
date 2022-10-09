/*
Given a m x n grid filled with non-negative numbers,
find the a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct item
{
   int cost;
   string path;
};
int minCost(vector<vector<int>> &grid, int n, int m);
int _minCost(vector<vector<int>> &grid, int mem[101][101], int r, int c, int n, int m);
int inf = INT32_MAX / 2;
void printMinCostPath(vector<vector<int>> &grid, int n, int m);
item f(vector<vector<int>> &grid, int r, int c, int n, int m);
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
   printMinCostPath(grid, n, m);
   return 0;
}
item f(vector<vector<int>> &grid, int r, int c, int n, int m)
{
   if (r == n - 1 && c == m - 1)
   {
      item i = {grid[r][c], to_string(grid[r][c])};
      return i;
   }
   if (r >= n || c >= m)
   {
      item i = {inf, ""};
      return i;
   }
   item a = f(grid, r + 1, c, n, m);
   item b = f(grid, r, c + 1, n, m);
   if (a.cost < b.cost)
   {
      a.path = to_string(grid[r][c]) + a.path;
      a.cost += grid[r][c];
      return a;
   }
   else
   {
      b.path = to_string(grid[r][c]) + b.path;
      b.cost += grid[r][c];
      return b;
   }
}
void printMinCostPath(vector<vector<int>> &grid, int n, int m)
{
   item res = f(grid, 0, 0, grid.size(), grid[0].size());
   cout << endl
        << res.cost << endl
        << res.path;
}
// int _minCost(vector<vector<int>> &grid, int mem[101][101], int r, int c, int n, int m)
// {
//    if (r == n - 1 && c == m - 1)
//       return 0;
//    if (r >= n || c >= m)
//       return inf;
//    if (mem[r][c] == -1)
//    {

//       int a = _minCost(grid, mem, r + 1, c, n, m);
//       int b = _minCost(grid, mem, r, c + 1, n, m);
//       mem[r][c] = min(a, b) + grid[r][c];
//    }
//    return mem[r][c];
// }
// int minCost(vector<vector<int>> &grid, int n, int m)
// {
//    int mem[101][101];
//    for (int i = 0; i < n; i++)
//    {
//       for (int j = 0; j < m; j++)
//       {
//          mem[i][j] = -1;
//       }
//    }
//    return _minCost(grid, mem, 0, 0, n, m);
// }