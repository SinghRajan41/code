// Rat in a Maze
#include <iostream>
#include <vector>
using namespace std;
int main()
{
   int r, c;
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
   return 0;
}