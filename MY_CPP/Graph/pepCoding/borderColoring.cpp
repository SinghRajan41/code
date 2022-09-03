#include <iostream>
#include <vector>
// Given a binary matrix
// Convert all the 1's at the boundary of the matrix as 0
// Also convert those ones which are connected to boundary 1's
using namespace std;
int trapRat(vector<vector<short>> &arr, int n);
void eraseOne(vector<vector<short>> &arr, int r, int c, int n);
int main()
{
   int n;
   cin >> n;
   vector<vector<short>> arr;
   for (int i = 0; i < n; i++)
   {
      vector<short> temp(n, 0);
      arr.push_back(temp);
   }
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         cin >> arr[i][j];
      }
   }
   cout << trapRat(arr, n);
   return 0;
}
void eraseOne(vector<vector<short>> &arr, int r, int c, int n)
{
   if (r < 0 || c < 0 || r >= n || c >= n || arr[r][c] == 0)
   {
      return;
   }
   arr[r][c] = 0;
   eraseOne(arr, r - 1, c, n);
   eraseOne(arr, r + 1, c, n);
   eraseOne(arr, r, c + 1, n);
   eraseOne(arr, r, c - 1, n);
}
int trapRat(vector<vector<short>> &arr, int n)
{
   int count = 0;
   for (int i = 0; i < n; i++)
   {
      if (arr[0][i] == 1)
      {
         eraseOne(arr, 0, i, n);
      }
      if (arr[i][0] == 1)
      {
         eraseOne(arr, i, 0, n);
      }
      if (arr[n - 1][i] == 1)
      {
         eraseOne(arr, n - 1, i, n);
      }
      if (arr[i][n - 1] == 1)
      {
         eraseOne(arr, i, n - 1, n);
      }
   }
   for (int i = 1; i < n - 1; i++)
   {
      for (int j = 1; j < n - 1; j++)
      {
         count = arr[i][j] == 1 ? count + 1 : count;
      }
   }
   return count;
}