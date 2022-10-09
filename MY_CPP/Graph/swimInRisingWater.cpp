#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
class cmp
{
public:
   bool operator()()
   {
      return true;
   }
};
class priorityQueue
{
   pair<pair<int, int>, int> *harr;
   int size, n;

public:
   priorityQueue()
   {
      size = 5000;
      n = -1;
      harr = new pair<pair<int, int>, int>[size];
   }
   int length()
   {
      return n + 1;
   }
   void push(pair<pair<int, int>, int> p)
   {
      if (size == n - 1)
      {
         return;
      }
      else
      {
         harr[++n] = p;
         int i = n;
         while (i > 0)
         {
            if (harr[(i - 1) / 2].second > harr[i].second)
            {
               swap(harr[i], harr[(i - 1) / 2]);
            }
            i = (i - 1) / 2;
         }
      }
   }
   pair<pair<int, int>, int> front()
   {
      return harr[0];
   }
   bool empty()
   {
      return n == -1 ? true : false;
   }
   void pop()
   {
      if (n == -1)
      {
         return;
      }
      else if (n == 0)
      {
         n--;
      }
      else
      {
         swap(harr[0], harr[n]);
         n--;
         pushDown(0);
      }
   }
   void pushDown(int i)
   {
      int j = 2 * i + 1;
      if (j + 1 <= n && harr[j].second > harr[j + 1].second)
      {
         j += 1;
      }
      if (j <= n && harr[j].second < harr[(j - 1) / 2].second)
      {
         swap(harr[j], harr[(j - 1) / 2]);
         pushDown(j);
      }
   }
   void f()
   {
      for (int i = 0; i <= n; i++)
      {
         cout << harr[i].second << " ";
      }
   }
};
bool valid(int x, int y, int n)
{
   return (x >= 0 && y >= 0 && x < n && y < n);
}
int swimInWater(vector<vector<int>> &arr, int n)
{
   priorityQueue pq;
   pq.push(make_pair(make_pair(0, 0), arr[0][0]));
   int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
   bool visited[n][n];
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         visited[i][j] = false;
      }
   }
   while (!pq.empty())
   {
      pair<pair<int, int>, int> cur = pq.front();
      pq.pop();
      int x, y, w;
      x = cur.first.first;
      y = cur.first.second;
      w = cur.second;
      if (x == n - 1 && y == n - 1)
      {
         return max(w, arr[x][y]);
      }
      if (!visited[x][y])
      {
         visited[x][y] = true;
         // Generate all valid and unvisited neighbours and adding them to the priority queue
         for (int i = 0; i < 4; i++)
         {
            int r, c, newWt;
            r = x + dirs[i][0];
            c = y + dirs[i][1];
            if (valid(r, c, n) && !visited[r][c])
            {
               // Add it to the queuue
               pair<pair<int, int>, int> p = {{r, c}, max(w, arr[r][c])};
               pq.push(p);
            }
         }
      }
   }
   cout << "\nOut of While Loop\n";
   return -1;
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
   cout << swimInWater(arr, n);
   return 0;
}