// Given a matrix of 0's and 1's
// 1 represents land
// 0 represents
// there will be two land body and one water body
// find the length of shortest bridge connecting two land bodies
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct item
{
   int row;
   int col;
   int level;
};
void inputArray(vector<vector<int>> &arr, int n);
int shortestBridge(vector<vector<int>> &arr, int n);
void dfs(vector<vector<int>> &arr, int row, int col, int n, queue<item> &q, vector<vector<bool>> &visited);
int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main()
{
   int n;
   cin >> n;
   vector<vector<int>> arr;
   inputArray(arr, n);
   cout << shortestBridge(arr, n);
   return 0;
}
int shortestBridge(vector<vector<int>> &arr, int n)
{
   queue<item> q;
   bool flag = false;
   vector<vector<bool>> visited;
   for (int i = 0; i < n; i++)
   {
      vector<bool> temp(n, false);
      visited.push_back(temp);
   }
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (arr[i][j] == 1)
         {
            dfs(arr, i, j, n, q, visited);
            flag = true;
         }
      }
      if (flag)
      {
         break;
      }
   }
   while (!q.empty())
   {
      item cur = q.front();
      q.pop();
      if (!visited[cur.row][cur.col] && arr[cur.row][cur.col] == 1)
      {
         return cur.level;
      }
      else
      {
         for (int i = 0; i < 4; i++)
         {
            if (!visited[cur.row][cur.col] && arr[cur.row][cur.col] == 0)
            {
               visited[cur.row][cur.col] = true;
            }
            item temp = {cur.row + dirs[i][0], cur.col + dirs[i][1], cur.level + 1};
            if (temp.row >= 0 && temp.col >= 0 && temp.row < n && temp.col < n && !visited[temp.row][temp.col])
            {
               q.push(temp);
            }
         }
      }
   }

   return -1;
}
void dfs(vector<vector<int>> &arr, int row, int col, int n, queue<item> &q, vector<vector<bool>> &visited)
{
   if (row >= 0 && col >= 0 && row < n && col < n)
   {
      if (!visited[row][col] && arr[row][col] == 1)
      {
         visited[row][col] = true;
         item temp = {row, col, 0};
         q.push(temp);
         for (int i = 0; i < 4; i++)
         {
            dfs(arr, row + dirs[i][0], col + dirs[i][1], n, q, visited);
         }
      }
   }
}
void inputArray(vector<vector<int>> &arr, int n)
{
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
}