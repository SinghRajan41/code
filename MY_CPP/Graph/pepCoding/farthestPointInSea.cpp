#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Given a matrix of 0's and 1's
// 1 represents land
// 0 represent water body
// find the farthest point in sea from any land area

int farthestPoint(vector<vector<int>> &arr, int n);
struct item
{
   int x;
   int y;
   int level;
};
bool isValid(item i, int n);
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
   cout << farthestPoint(arr, n);
   return 0;
}
bool isValid(item i, int n)
{
   return (i.x < n && i.y < n && i.y >= 0 && i.x >= 0);
}
int farthestPoint(vector<vector<int>> &arr, int n)
{
   queue<item> q;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (arr[i][j] == 1)
         {
            item temp = {i, j, 0};
            q.push(temp);
         }
      }
   }
   int ans = 0;
   int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
   while (!q.empty())
   {
      item cur = q.front();
      q.pop();
      for (int i = 0; i < 4; i++)
      {
         item a = {cur.x + dirs[i][0], cur.y + dirs[i][1], cur.level + 1};
         if (isValid(a, n) && arr[a.x][a.y] == 0)
         {
            arr[a.x][a.y] = 1;
            q.push(a);
            if (a.level > ans)
            {
               ans = a.level;
            }
         }
      }
   }
   return ans;
}