#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
int searchZero(string board);
struct item
{
   string board;
   int level;
};
int minSlides(string board);
int main()
{
   string board;
   cin >> board;
   cout << minSlides(board);
   return 0;
}
int searchZero(string board)
{
   for (int i = 0; i < 6; i++)
   {
      if (board[i] == '0')
      {
         return i;
      }
   }
}
int minSlides(string board)
{
   string ans = "012345";
   vector<int> moves[6] = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
   queue<item> q;
   q.push({board, 0});
   unordered_map<string, bool> map;
   while (!q.empty())
   {
      item cur = q.front();
      q.pop();
      if (cur.board == ans)
      {
         return cur.level;
      }
      else
      {
         int pos = searchZero(cur.board);
         for (int i = 0; i < moves[pos].size(); i++)
         {
            string newBoard = cur.board;
            swap(newBoard[pos], newBoard[moves[pos][i]]);
            if (map[newBoard] == true)
            {
               continue;
            }
            else
            {
               map[newBoard] = true;
               q.push({newBoard, cur.level + 1});
            }
         }
      }
   }
   return -1;
}