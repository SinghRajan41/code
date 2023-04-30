#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dirs[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
bool valid(int r, int c, int n, int m)
{
   return (r >= 1 && r <= n && c >= 1 && c <= m);
}
bool solve(int n, int m)
{
   int x, y;
   x = y = -1;
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= m; j++)
      {
         bool canMove = false;
         for (int x = 0; x < 8; x++)
         {
            if (valid(i + dirs[x][0], j + dirs[x][1], n, m))
            {
               canMove = true;
            }
         }
         if (canMove == false)
         {
            x = i;
            y = j;
         }
      }
   }
   if (x == -1 && y == -1)
   {
      cout << 1 << " " << 1 << endl;
   }
   else
   {
      cout << x << " " << y << endl;
   }
   return false;
}

int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n, m;
      cin >> n >> m;
      if (solve(n, m))
      {
         cout << 1 << " " << 1 << endl;
      }
   }
   return 0;
}