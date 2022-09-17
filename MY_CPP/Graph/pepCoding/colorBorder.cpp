#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void printMatrix(vector<vector<int>> &arr, int n);
void colorBorder(vector<vector<int>> &arr, int n, int r, int c);
bool boundaryNode(vector<vector<int>> &arr, int r, int c, int n, int key);
void dfs(vector<vector<int>> &arr, int n, int r, int c, int key, vector<vector<bool>> &visited, queue<pair<int, int>> &q);
bool isValid(int r, int c, int n);
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
   int r, c;
   cin >> r >> c;
   colorBorder(arr, n, r, c);
   return 0;
}
bool boundaryNode(vector<vector<int>> &arr, int r, int c, int n, int key)
{
   int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
   for (int i = 0; i < 4; i++)
   {
      if (isValid(r + dirs[i][0], c + dirs[i][1], n))
      {
         if (arr[r + dirs[i][0]][c + dirs[i][1]] != key)
         {
            return true;
         }
      }
   }
   return false;
}
bool isValid(int r, int c, int n)
{
   return (r >= 0 && c >= 0 && r < n && c < n);
}
void dfs(vector<vector<int>> &arr, int n, int r, int c, int key, vector<vector<bool>> &visited, queue<pair<int, int>> &q)
{
   if (isValid(r, c, n))
   {
      if (!visited[r][c])
      {
         visited[r][c] = true;
         if (arr[r][c] == key)
         {
            if (boundaryNode(arr, r, c, n, key))
            {
               q.push(make_pair(r, c));
               // Call the function in all four directions
               int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
               for (int i = 0; i < 4; i++)
               {
                  dfs(arr, n, r + dirs[i][0], c + dirs[i][1], key, visited, q);
               }
            }
         }
      }
   }
}
void colorBorder(vector<vector<int>> &arr, int n, int r, int c)
{
   queue<pair<int, int>> q;
   vector<vector<bool>> visited;
   int key = arr[r][c];
   for (int i = 0; i < n; i++)
   {
      vector<bool> temp(n, 0);
      visited.push_back(temp);
   }
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         visited[i][j] = ((arr[i][j] == key) ? false : true);
      }
   }
   dfs(arr, n, r, c, key, visited, q);
   while (!q.empty())
   {
      pair<int, int> cur = q.front();
      q.pop();
      arr[cur.first][cur.second] = -1;
   }
   printMatrix(arr, n);
}
void printMatrix(vector<vector<int>> &arr, int n)
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         cout << arr[i][j] << " ";
      }
      cout << endl;
   }
}