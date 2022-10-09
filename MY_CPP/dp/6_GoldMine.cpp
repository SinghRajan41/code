/*
1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a, which represents a gold mine.
4. You are standing in front of left wall and are supposed to dig to the right wall. You can start from
     any row in the left wall.
5. You are allowed to move 1 cell right-up (d1), 1 cell right (d2) or 1 cell right-down(d3).
*/
#include <iostream>
#include <vector>
using namespace std;
int n, m;
#define valid(r, c) (r >= 0 && c >= 0 && r < n && c < m)
int maxGold(vector<vector<int>> &grid);
int main()
{
   cin >> n >> m;
   vector<vector<int>> grid(n, vector<int>(m, 0));
   for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
         cin >> grid[i][j];
   cout << maxGold(grid);
   return 0;
}
int maxGold(vector<vector<int>> &grid)
{
   int dp[n][m];
   for (int i = 0; i < n; i++)
   {
      dp[i][m - 1] = grid[i][m - 1];
   }
   for (int j = m - 2; j >= 0; j--)
   {
      for (int i = 0; i < n; i++)
      {
         int Max = INT32_MIN;
         if (valid(i, j + 1))
         {
            Max = max(Max, dp[i][j + 1]);
         }
         if (valid(i - 1, j + 1))
         {
            Max = max(Max, dp[i - 1][j + 1]);
         }
         if (valid(i + 1, j + 1))
         {
            Max = max(Max, dp[i + 1][j + 1]);
         }
         dp[i][j] = grid[i][j] + Max;
      }
   }
   int M = INT32_MIN;
   for (int i = 0; i < n; i++)
   {
      M = max(M, dp[i][0]);
   }
   return M;
}