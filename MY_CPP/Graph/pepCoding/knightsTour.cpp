// Given the position of knight in a NxN chess board
// Find a path covering all blocks of chess board without visiting the same block twice
// Print all such paths if possible
#include <iostream>
#include <vector>
using namespace std;
void printBoard(vector<vector<int>> &board, int n)
{
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= n; j++)
      {
         cout << board[i][j] << " ";
      }
      cout << endl;
   }
   cout << endl
        << endl;
}
void printKnightsTour(vector<vector<int>> &board, int r, int c, int n, int move)
{
   if (r < 1 || c < 1 || r > n || c > n || board[r][c] != 0)
   {
      return;
   }
   if (move == n * n)
   {
      board[r][c] = move;
      printBoard(board, n);
      board[r][c] = 0;
      return;
   }
   board[r][c] = move;
   printKnightsTour(board, r - 2, c + 1, n, move + 1);
   printKnightsTour(board, r - 1, c + 2, n, move + 1);
   printKnightsTour(board, r + 1, c + 2, n, move + 1);
   printKnightsTour(board, r + 2, c + 1, n, move + 1);
   printKnightsTour(board, r + 2, c - 1, n, move + 1);
   printKnightsTour(board, r + 1, c - 2, n, move + 1);
   printKnightsTour(board, r - 1, c - 2, n, move + 1);
   printKnightsTour(board, r - 2, c - 1, n, move + 1);
   board[r][c] = 0;
}
int main()
{
   int n;
   cin >> n;
   int r, c;
   cin >> r >> c;
   vector<vector<int>> board;
   for (int i = 0; i <= n; i++)
   {
      vector<int> temp(n + 1, 0);
      board.push_back(temp);
   }
   printKnightsTour(board, r, c, n, 1);
   return 0;
}