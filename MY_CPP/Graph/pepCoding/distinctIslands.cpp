#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
void generatePath(vector<vector<int>> &arr, int r, int c, int n, string &path, char lastMove);
int distinctIslands(vector<vector<int>> &arr, int n)
{
   unordered_map<string, int> map;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (arr[i][j] == 1)
         {
            string path = "";
            generatePath(arr, i, j, n, path, 'x');
            map[path]++;
         }
      }
   }
   return map.size();
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
   cout << distinctIslands(arr, n);
   return 0;
}
void generatePath(vector<vector<int>> &arr, int r, int c, int n, string &path, char lastMove)
{
   if (r < 0 || c < 0 || r >= n || c >= n || arr[r][c] == 0)
   {
      return;
   }
   else
   {
      arr[r][c] = 0;
      path += lastMove;
      generatePath(arr, r - 1, c, n, path, 'u');
      generatePath(arr, r, c + 1, n, path, 'r');
      generatePath(arr, r + 1, c, n, path, 'd');
      generatePath(arr, r, c - 1, n, path, 'l');
   }
}