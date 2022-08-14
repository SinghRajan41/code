#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
int x, y;
pair<int, int> eu(pair<int, int> p)
{
   pair<int, int> res;
   res.first = 0;
   res.second = p.second;
   return res;
}
pair<int, int> ue(pair<int, int> p)
{
   pair<int, int> res;
   res.first = p.first;
   res.second = 0;
   return res;
}
pair<int, int> lr(pair<int, int> p)
{
   int req, avail;
   pair<int, int> res;
   avail = p.first;
   req = y - p.second;
   if (req > avail)
   {
      res.first = 0;
      res.second = p.second + avail;
   }
   else if (req == avail)
   {
      res.first = 0;
      res.second = p.second + avail;
   }
   else
   {
      // req < avail
      res.first = p.first - req;
      res.second = y;
   }
   return res;
}
pair<int, int> rl(pair<int, int> p)
{
   pair<int, int> res;
   int avail, req;
   avail = p.second;
   req = y - p.first;
   if (req > avail)
   {
      res.first = p.first + avail;
      res.second = 0;
   }
   else if (req == avail)
   {
      res.first = x;
      res.second = 0;
   }
   else
   {
      // req < avail
      res.first = x;
      res.second = p.second - req;
   }
   return res;
}
pair<int, int> cu(pair<int, int> p)
{
   pair<int, int> res;
   res.first = x;
   res.second = p.second;
   return res;
}
pair<int, int> uc(pair<int, int> p)
{
   pair<int, int> res;
   res.first = p.first;
   res.second = y;
   return res;
}
int minSteps(int a, int b, int target)
{
   queue<pair<int, int>> q;
   x = a;
   y = b;
   queue<int> level;
   level.push(0);
   q.push(make_pair(0, 0));
   pair<int, int> p;
   bool map[100][100];
   for (int i = 0; i < 100; i++)
   {
      for (int j = 0; j < 100; j++)
      {
         map[i][j] = false;
      }
   }
   while (!q.empty())
   {
      p = q.front();
      q.pop();
      int curLevel = level.front();
      level.pop();
      if (p.first == a && p.second == b)
      {
         continue;
      }
      if (p.first == target || p.second == target)
      {
         return curLevel + 1;
      }
      pair<int, int> np;
      np = eu(p);
      if (map[np.first][np.second] == false)
      {
         map[np.first][np.second] = true;
         q.push(np);
         level.push(curLevel + 1);
      }
      np = ue(p);
      if (map[np.first][np.second] == false)
      {
         map[np.first][np.second] = true;
         q.push(np);
         level.push(curLevel + 1);
      }
      np = lr(p);
      if (map[np.first][np.second] == false)
      {
         map[np.first][np.second] = true;
         q.push(np);
         level.push(curLevel + 1);
      }
      np = rl(p);
      if (map[np.first][np.second] == false)
      {
         map[np.first][np.second] = true;
         q.push(np);
         level.push(curLevel + 1);
      }
      np = cu(p);
      if (map[np.first][np.second] == false)
      {
         map[np.first][np.second] = true;
         q.push(np);
         level.push(curLevel + 1);
      }
      np = uc(p);
      if (map[np.first][np.second] == false)
      {
         map[np.first][np.second] = true;
         q.push(np);
         level.push(curLevel + 1);
      }
   }
   return -1;
}
int main()
{
   int a, b;
   cin >> a >> b;
   int target;
   cin >> target;
   cout << minSteps(a, b, target);
   return 0;
}