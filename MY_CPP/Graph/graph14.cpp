// Rat in a Maze
// Given a boolean matrix
// find if rat can cross the maze
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool ratMaze(vector<vector<bool>> &maze, int r, int c);
int r, c;
pair<int, int> moveLeft(vector<vector<bool>> maze, pair<int, int> p);
pair<int, int> moveRight(vector<vector<bool>> maze, pair<int, int> p);
pair<int, int> moveUp(vector<vector<bool>> maze, pair<int, int> p);
pair<int, int> moveDown(vector<vector<bool>> maze, pair<int, int> p);
int main()
{
   cin >> r >> c;
   vector<vector<bool>> maze;
   for (int i = 0; i < r; i++)
   {
      vector<bool> temp;
      bool x;
      for (int j = 0; j < c; j++)
      {
         cin >> x;
         temp.push_back(x);
      }
      maze.push_back(temp);
   }
   if (ratMaze(maze, r, c))
   {
      cout << "\nRat can cross the maze";
   }
   else
   {
      cout << "\nRat cannot cross the maze";
   }
   return 0;
}
pair<int, int> moveDown(vector<vector<bool>> maze, pair<int, int> p)
{
   if (p.first == r - 1)
   {
      return p;
   }
   pair<int, int> res;
   res = {p.first + 1, p.second};
   return maze[res.first][res.second] == 0 ? res : p;
}
pair<int, int> moveUp(vector<vector<bool>> maze, pair<int, int> p)
{
   if (p.first == 0)
   {
      return p;
   }
   pair<int, int> res = {p.first - 1, p.second};
   return maze[res.first][res.second] == 0 ? res : p;
}
pair<int, int> moveLeft(vector<vector<bool>> maze, pair<int, int> p)
{
   if (p.second == 0)
   {
      return p;
   }
   pair<int, int> res = {p.first, p.second - 1};
   return maze[res.first][res.second] == 0 ? res : p;
}
pair<int, int> moveRight(vector<vector<bool>> maze, pair<int, int> p)
{
   if (p.second == c - 1)
   {
      return p;
   }
   pair<int, int> res = {p.first, p.second + 1};
   return maze[res.first][res.second] == 0 ? res : p;
}
bool ratMaze(vector<vector<bool>> &maze, int r, int c)
{
   if (r == 0 || c == 0)
   {
      return false;
   }
   queue<pair<int, int>> q;
   bool map[100][100];
   for (int i = 0; i < 100; i++)
   {
      for (int j = 0; j < 100; j++)
      {
         map[i][j] = false;
      }
   }
   map[0][0] = true;
   pair<int, int> p = {0, 0};
   pair<int, int> np;
   q.push(p);
   while (!q.empty())
   {
      p = q.front();
      q.pop();
      if (p.first == r - 1 && p.second == c - 1)
      {
         return true;
      }
      np = moveLeft(maze, p);
      if (map[np.first][np.second] == false)
      {
         map[np.first][np.second] = true;
         q.push(np);
      }
      np = moveRight(maze, p);
      if (map[np.first][np.second] == false)
      {
         map[np.first][np.second] = true;
         q.push(np);
      }
      np = moveUp(maze, p);
      if (map[np.first][np.second] == false)
      {
         map[np.first][np.second] = true;
         q.push(np);
      }
      np = moveDown(maze, p);
      if (map[np.first][np.second] == false)
      {
         map[np.first][np.second] = true;
         q.push(np);
      }
   }
   return false;
}