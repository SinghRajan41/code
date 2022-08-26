#include <iostream>
#include <vector>
using namespace std;
int countIslands(vector<vector<int>> &arr, int n);
int main()
{
   int n;
   cin >> n;
   vector<vector<int>> arr;
   for (int i = 0; i <= n; i++)
   {
      vector<int> temp(n + 1, 0);
      arr.push_back(temp);
   }
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= n; j++)
      {
         cin >> arr[i][j];
      }
   }
   cout << countIslands(arr, n);
   return 0;
}
void dfs(vector<vector<int>> &arr, int n, int i, int j)
{
   if (i < 1 || i > n || j < 1 || j > n || arr[i][j] == 1)
   {
      return;
   }
   arr[i][j] = 1;
   dfs(arr, n, i + 1, j);
   dfs(arr, n, i - 1, j);
   dfs(arr, n, i, j + 1);
   dfs(arr, n, i, j - 1);
}
int countIslands(vector<vector<int>> &arr, int n)
{
   int count = 0;
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= n; j++)
      {
         if (!arr[i][j])
         {
            dfs(arr, n, i, j);
            count++;
         }
      }
   }
   return count;
}