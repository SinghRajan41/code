// Given a binary matrix
// for every element in binary matrix
// find the minimum manhattan distance of 0 from the element
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
struct item
{
   int x, y, level;
};
int BFS(vector<vector<int>> &arr, int r, int c, int n)
{
   // Making a visited matrix
   bool visited[n][n];
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         visited[i][j] = false;
      }
   }
   queue<item> q;
   visited[r][c] = true;
   item i = {r, c, 0};
   q.push(i);
   while (!q.empty())
   {
      i = q.front();
      int x = i.x;
      int y = i.y;
      int curLevel = i.level;
      if (arr[x][y] == 0)
      {
         return curLevel + 1;
      }
      else
      {
         arr[x][y] = true;
         // Move left
         if (y - 1 >= 0 && !visited[x][y - 1])
         {
            item ii = {x, y - 1, curLevel + 1};
            q.push(ii);
         }
         // Move Right
         if (y + 1 < n && !visited[x][y + 1])
         {
            item ii = {x, y + 1, curLevel + 1};
            q.push(ii);
         }
         // Move Up
         if (x - 1 >= 0 && !visited[x - 1][y])
         {
            item ii = {x - 1, y, curLevel + 1};
            q.push(ii);
         }
         // Move Down
         if (x + 1 < n && !visited[x + 1][y])
         {
            item ii = {x + 1, y, curLevel + 1};
            q.push(ii);
         }
      }
   }
}
void printNearestDist(vector<vector<int>> &arr, int n)
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         cout << (arr[i][j] == 0 ? 0 : BFS(arr, i, j, n)) << " ";
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
   printNearestDist(arr, n);
   return 0;
}