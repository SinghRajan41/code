/*
There is a m*n rectangular matrix whose top-left(start) location is (1, 1) and bottom-right(end) location is (m*n).
There are k circles each with radius r. Find if there is any path from start to end without touching any circle.
The input contains values of m, n, k, r and two array of integers X and Y, each of length k.
(X[i], Y[i]) is the center of ith circle.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int r, c, k, rad;
vector<int> x;
vector<int> y;
bool ratInMaze(vector<vector<bool>> &maze);
pair<int, int> moveLeft(vector<vector<bool>> &maze, pair<int, int> p);
pair<int, int> moveRight(vector<vector<bool>> &maze, pair<int, int> p);
pair<int, int> moveDown(vector<vector<bool>> &maze, pair<int, int> p);
pair<int, int> moveUp(vector<vector<bool>> &maze, pair<int, int> p);
int main()
{
   cin >> r >> c >> k >> rad;
   for (int i = 0; i < k; i++)
   {
      int a, b;
      cin >> a >> b;
      x.push_back(a - 1);
      y.push_back(b - 1);
   }
   vector<vector<bool>> maze;
   for (int i = 0; i < r; i++)
   {
      vector<bool> temp(c, false);
      maze.push_back(temp);
   }
   for (int i = 0; i < r; i++)
   {
      for (int j = 0; j < c; j++)
      {
         for (int p = 0; p < k; p++)
         {
            if (sqrt((x[p] - i) * (x[p] - i) + (y[p] - j) * (y[p] - j)) <= rad)
            {
               maze[i][j] = true;
               break;
            }
         }
      }
   }
   for (int i = 0; i < maze.size(); i++)
   {
      for (auto j : maze[i])
      {
         cout << j << " ";
      }
      cout << endl;
   }
   if (ratInMaze(maze))
   {
      cout << "\nRat can cross the maze";
   }
   else
   {
      cout << "\nRat cannot cross the maze";
   }
   return 0;
}
pair<int, int> moveLeft(vector<vector<bool>> &maze, pair<int, int> p)
{
   if (p.second == 0)
   {
      return p;
   }
   pair<int, int> res = {p.first, p.second - 1};
   return maze[res.first][res.second] == 0 ? res : p;
}
pair<int, int> moveRight(vector<vector<bool>> &maze, pair<int, int> p)
{
   if (p.second == c - 1)
   {
      return p;
   }
   pair<int, int> res = {p.first, p.second + 1};
   return maze[res.first][res.second] == 0 ? res : p;
}
pair<int, int> moveDown(vector<vector<bool>> &maze, pair<int, int> p)
{
   if (p.first == r - 1)
   {
      return p;
   }
   pair<int, int> res = {p.first + 1, p.second};
   return maze[res.first][res.second] == 0 ? res : p;
}
pair<int, int> moveUp(vector<vector<bool>> &maze, pair<int, int> p)
{
   if (p.first == 0)
   {
      return p;
   }
   pair<int, int> res = {p.first - 1, p.second};
   return maze[p.first][p.second] == 0 ? res : p;
}
bool ratInMaze(vector<vector<bool>> &maze)
{
   if (maze[0][0] == 1)
   {
      return false;
   }
   pair<int, int> p, np;
   p = {0, 0};
   bool map[100][100];
   for (int i = 0; i < 100; i++)
   {
      for (int j = 0; j < 100; j++)
      {
         map[i][j] = 0;
      }
   }
   map[0][0] = 1;
   queue<pair<int, int>> q;
   q.push(p);
   while (!q.empty())
   {
      p = q.front();
      q.pop();
      if (p.first == r - 1 && p.second == c - 1)
      {
         cout << p.first << " " << p.second << endl;
         return true;
      }
      np = moveLeft(maze, p);
      if (map[np.first][np.second] == 0)
      {
         q.push(np);
         map[np.first][np.second] == 1;
      }
      np = moveRight(maze, p);
      if (map[np.first][np.second] == 0)
      {
         q.push(np);
         map[np.first][np.second] == 1;
      }
      np = moveUp(maze, p);
      if (map[np.first][np.second] == 0)
      {
         q.push(np);
         map[np.first][np.second] == 1;
      }
      np = moveDown(maze, p);
      if (map[np.first][np.second] == 0)
      {
         q.push(np);
         map[np.first][np.second] == 1;
      }
   }
   return false;
}
