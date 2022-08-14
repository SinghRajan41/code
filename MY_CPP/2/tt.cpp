#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'coinOnTheTable' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER m
 *  2. INTEGER k
 *  3. STRING_ARRAY board
 */
int xi, yi;
int count(vector<string> board, int i, int j, int r, int c)
{
   if (board[i][j] == '*' || i >= r || j >= c)
   {
      return 0;
   }
   else
   {
      int w, x, y, z;
      w = x = y = z = 0;
      if (board[i][j] != 'D')
      {
         w = 1 + count(board, i + 1, j, r, c);
      }
      else
      {
         x = count(board, i + 1, j, r, c);
      }
      if (board[i][j] != 'R')
      {
         y = 1 + count(board, i, j + 1, r, c);
      }
      else
      {
         z = count(board, i, j + 1, r, c);
      }
      int arr[4] = {w, x, y, z};
      sort(arr, arr + 4);
      return arr[0];
   }
}
int coinOnTheTable(int m, int k, vector<string> board)
{
   int r, c, i, j;
   r = m;
   c = board[0].length();
   for (i = 0; i < m; i++)
   {
      for (j = 0; j < board[i].length(); j++)
      {
         if (board[i][j] == '*')
         {
            xi = i;
            yi = j;
            break;
         }
      }
   }
   cout << count(board, 0, 0, r, c);
}

int main()
{
   ofstream fout(getenv("OUTPUT_PATH"));

   string first_multiple_input_temp;
   getline(cin, first_multiple_input_temp);

   vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

   int n = stoi(first_multiple_input[0]);

   int m = stoi(first_multiple_input[1]);

   int k = stoi(first_multiple_input[2]);

   vector<string> board(n);

   for (int i = 0; i < n; i++)
   {
      string board_item;
      getline(cin, board_item);

      board[i] = board_item;
   }

   int result = coinOnTheTable(m, k, board);

   fout << result << "\n";

   fout.close();

   return 0;
}

string ltrim(const string &str)
{
   string s(str);

   s.erase(
       s.begin(),
       find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

   return s;
}

string rtrim(const string &str)
{
   string s(str);

   s.erase(
       find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
       s.end());

   return s;
}

vector<string> split(const string &str)
{
   vector<string> tokens;

   string::size_type start = 0;
   string::size_type end = 0;

   while ((end = str.find(" ", start)) != string::npos)
   {
      tokens.push_back(str.substr(start, end - start));

      start = end + 1;
   }

   tokens.push_back(str.substr(start));

   return tokens;
}
