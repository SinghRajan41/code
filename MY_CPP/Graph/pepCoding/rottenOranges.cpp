#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int rottenOranges(vector<vector<int>> &arr, int n);
struct item
{
   int row;
   int col;
   int level;
};
item moveLeft(item i, int n);
item moveUp(item i, int n);
item moveDown(item i, int n);
item moveRight(item i, int n);
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
   cout << rottenOranges(arr, n);
   return 0;
}
item moveLeft(item i, int n)
{
   item r = {i.row, (i.col - 1 > -1 ? i.col - 1 : i.col), i.level + 1};
   return r;
}
item moveUp(item i, int n)
{
   item r = {i.row - 1 > -1 ? i.row - 1 : i.row, i.col, i.level + 1};
   return r;
}
item moveRight(item i, int n)
{
   item r = {i.row, i.col + 1 < n ? i.col + 1 : i.col, i.level + 1};
   return r;
}
item moveDown(item i, int n)
{
   item r = {i.row + 1 < n ? i.row + 1 : i.col, i.col, i.level + 1};
   return r;
}
int rottenOranges(vector<vector<int>> &arr, int n)
{
   int count = 0;
   int total = 0;
   queue<item> q;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (arr[i][j] == 2)
         {
            item it = {i, j, 0};
            q.push(it);
         }
         if (arr[i][j] == 1)
         {
            total++;
         }
      }
   }
   int maxLevel = -1;
   while (!q.empty())
   {
      item cur = q.front();
      q.pop();
      if (arr[cur.row][cur.col] == 2)
      {
         arr[cur.row][cur.col] == 0;
         item a, b, c, d;
         a = moveLeft(cur, n);
         b = moveUp(cur, n);
         c = moveRight(cur, n);
         d = moveDown(cur, n);
         if (arr[a.row][a.col] == 1)
         {
            arr[a.row][a.col] = 2;
            q.push(a);
            count++;
            maxLevel = maxLevel > a.level ? maxLevel : a.level;
         }
         if (arr[b.row][b.col] == 1)
         {
            arr[b.row][b.col] = 2;
            q.push(b);
            count++;
            maxLevel = maxLevel > b.level ? maxLevel : b.level;
         }
         if (arr[c.row][c.col] == 1)
         {
            arr[c.row][c.col] = 2;
            q.push(c);
            count++;
            maxLevel = maxLevel > c.level ? maxLevel : c.level;
         }
         if (arr[d.row][d.col] == 1)
         {
            arr[d.row][d.col] = 2;
            q.push(d);
            count++;
            maxLevel = maxLevel > d.level ? maxLevel : d.level;
         }
      }
   }
   return count == total ? maxLevel : -1;
}