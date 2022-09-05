#include <iostream>
#include <vector>
#include <queue>
// Given an NxN matrix of 0's and 1's
// Find the minimum manhattan distance of 0 for each element element in the matrix
using namespace std;
void printNearest0(vector<vector<int>> &arr, int n);
int bfs(vector<vector<int>> &arr, int x, int y, int n);
struct item
{
   int r;
   int c;
   int level;
};
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
   printNearest0(arr, n);
   return 0;
}
int bfs(vector<vector<int>> &arr, int x, int y, int n)
{
   // Creating a visited matrix with all entries as false
   bool visited[n][n];
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         visited[i][j] = false;
      }
   }
   queue<item> q;
   item i = {x, y, -1};
   q.push(i);
   while (!q.empty())
   {
      int r, c, level;
      r = q.front().r;
      c = q.front().c;
      level = q.front().level;
      q.pop();
      if (r >= 0 && r < n && c >= 0 && c < n)
      {
         if (arr[r][c] == 0)
         {
            return level + 1;
         }
         else
         {
            if (!visited[r][c])
            {
               visited[r][c] = true;
               item temp = {r - 1, c, level + 1};
               q.push(temp);
               item temp2 = {r + 1, c, level + 1};
               q.push(temp2);
               item temp3 = {r, c + 1, level + 1};
               q.push(temp3);
               item temp4 = {r, c - 1, level + 1};
               q.push(temp4);
            }
         }
      }
   }
   return -2;
}
void printNearest0(vector<vector<int>> &arr, int n)
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         cout << (arr[i][j] == 0 ? 0 : bfs(arr, i, j, n)) << " ";
      }
      cout << endl;
   }
}
