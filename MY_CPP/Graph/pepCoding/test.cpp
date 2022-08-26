#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> findPos(int x, int y)
{
   vector<pair<int, int>> res;
   if (y + 2 <= 8 && x - 1 >= 1)
   {
      res.push_back(make_pair(x - 1, y + 2));
   }
   if (y - 2 >= 1 && x - 1 >= 1)
   {
      res.push_back(make_pair(x - 1, y - 2));
   }
   if (y + 2 <= 8 && x + 1 <= 8)
   {
      res.push_back(make_pair(x + 1, y + 2));
   }
   if (y - 2 >= 1 && x + 1 <= 8)
   {
      res.push_back(make_pair(x + 1, y - 2));
   }
   if (y + 1 <= 8 && x - 2 >= 1)
   {
      res.push_back(make_pair(x - 2, y + 1));
   }
   if (y + 1 <= 8 && x + 2 <= 8)
   {
      res.push_back(make_pair(x + 2, y + 1));
   }
   if (x - 2 >= 1 && y - 1 >= 1)
   {
      res.push_back(make_pair(x - 2, y - 1));
   }
   if (y - 1 >= 1 && x + 2 <= 8)
   {
      res.push_back(make_pair(x + 2, y - 1));
   }
   return res;
}
bool validSubSet(vector<pair<int, int>> subSet, int x, int y)
{
   bool arr[9][9] = {0};
   for (int i = 0; i < subSet.size(); i++)
   {
      int r, c;
      r = subSet[i].first;
      c = subSet[i].second;
      for (int x = 1; x <= 8; x++)
      {
         arr[x][c] = 1;
         arr[r][x] = 1;
      }
      int a, b;
      a = r;
      b = c;
      while (a <= 8 && b <= 8)
      {
         arr[a][b] = 1;
         a++;
         b++;
      }
      a = r;
      b = c;
      while (a >= 1 && b >= 1)
      {
         arr[a][b] = 1;
         a--;
         b--;
      }
      a = r;
      b = c;
      while (a >= 1 && b <= 8)
      {
         arr[a][b] = 1;
         a--;
         b++;
      }
      a = r;
      b = c;
      while (b >= 1 && a <= 8)
      {
         arr[a][b] = 1;
         b--;
         a++;
      }
   }
   if (arr[x][y] == 0)
   {
      if (x + 1 <= 8 && y + 1 <= 8 && arr[x + 1][y + 1] == 0)
      {
         return false;
      }
      if (x - 1 >= 1 && y + 1 <= 8 && arr[x - 1][y + 1] == 0)
      {
         return false;
      }
      if (x - 1 >= 1 && y - 1 >= 1 && arr[x - 1][y - 1] == 0)
      {
         return false;
      }
      if (x + 1 <= 8 && y - 1 >= 8 && arr[x + 1][y - 1] == 0)
      {
         return false;
      }
      if (y + 1 <= 8 && arr[x][y + 1] == 0)
      {
         return false;
      }
      if (y - 1 >= 1 && arr[x][y - 1] == 0)
      {
         return false;
      }
      if (x + 1 <= 8 && arr[x + 1][y] == 0)
      {
         return false;
      }
      if (x - 1 >= 1 && arr[x - 1][y] == 0)
      {
         return false;
      }
      return true;
   }
   else
   {
      return false;
   }
}
void printRes(vector<pair<int, int>> subSet, int x, int y)
{
   int arr[9][9];
   for (int i = 1; i <= 8; i++)
   {
      for (int j = 1; j <= 8; j++)
      {
         arr[i][j] = 0;
      }
   }
   for (int i = 0; i < subSet.size(); i++)
   {
      int r, c;
      r = subSet[i].first;
      c = subSet[i].second;
      arr[r][c] = 2;
   }
   arr[x][y] = 1;
   for (int i = 1; i <= 8; i++)
   {
      for (int j = 1; j <= 8; j++)
      {
         cout << arr[i][j] << " ";
      }
      cout << endl;
   }
}
void f1(int x, int y)
{
   vector<pair<int, int>> pos = findPos(x, y);
   int n = pos.size();
   vector<pair<int, int>> res;
   int minSize = 100;
   for (int i = 0; i < (1 << n); i++)
   {
      vector<pair<int, int>> subSet;
      for (int j = 0; j < 11; j++)
      {
         if (i & (1 << j))
         {
            subSet.push_back(pos[j]);
         }
      }
      if (validSubSet(subSet, x, y) && subSet.size() != 0 && subSet.size() < minSize)
      {
         minSize = subSet.size();
         res = subSet;
      }
   }
   printRes(res, x, y);
}
void print(int kx, int ky, int q1x, int q1y, int q2x, int q2y, int q3x, int q3y)
{
   for (int i = 1; i <= 8; i++)
   {
      for (int j = 1; j <= 8; j++)
      {
         if (i == kx && j == ky)
            cout << 1 << " ";
         else if ((i == q1x && j == q1y) && q1x != 0 && q1y != 0)
            cout << 2 << " ";
         else if ((i == q2x && j == q2y) && q2x != 0 && q2y != 0)
            cout << 2 << " ";
         else if ((i == q3x && j == q3y) && q3x != 0 && q3y != 0)
            cout << 2 << " ";
         else
            cout << 0 << " ";
      }
      cout << endl;
   }
}
void sub(int a, int c, int *e)
{
   if ((a - c) <= 0)
      *e = a + c;
   else
      *e = a - c;
}
void add(int a, int c, int *e)
{
   if (a + c > 8)
      *e = a - c;
   else
      *e = a + c;
}
void f2(int a, int b)
{
   if ((a == 8 && b == 8) || (a == 8 && b == 1) || (a == 1 && b == 8) || (a == 1 && b == 1))
   {
      int e, f;
      sub(a, 2, &e);
      sub(b, 1, &f);
      print(a, b, e, f, 0, 0, 0, 0);
   }
   else if (a == 8 || a == 1 || b == 1 || b == 8)
   {
      int p, q, r, s;
      if (b == 1 || b == 8)
      {
         sub(a, 1, &p);
         sub(b, 2, &q);
         add(a, 1, &r);
         sub(b, 2, &s);
      }
      else
      {
         sub(a, 2, &p);
         sub(b, 1, &q);
         sub(a, 2, &r);
         add(b, 1, &s);
      }
      print(a, b, p, q, r, s, 0, 0);
   }
   else if ((a == 2 && b == 2) || (a == 2 && b == 7) || (a == 7 && b == 2) || (a == 7 && b == 7))
   {
      int p, q, r, s, e, f;
      if ((a == 2 && b == 2))
      {
         add(a, 2, &p);
         sub(b, 1, &q);
         sub(a, 1, &r);
         add(b, 3, &s);
      }
      else if ((a == 2 && b == 7))
      {
         sub(a, 1, &r);
         sub(b, 3, &s);
         add(a, 2, &p);
         add(b, 1, &q);
      }
      else if ((a == 7 && b == 7))
      {
         add(a, 1, &p);
         sub(b, 2, &q);
         sub(a, 3, &r);
         add(b, 1, &s);
      }
      else if ((a == 7 && b == 2))
      {
         sub(a, 2, &p);
         sub(b, 1, &q);
         add(a, 1, &r);
         add(b, 3, &s);
      }
      print(a, b, p, q, r, s, 0, 0);
   }
   else if (a == 2 || a == 7 || b == 2 || b == 7)
   {
      int p, q, r, s, e, f;
      /*if(a==2)
      {
          sub(a,2,&p);
          sub(b,1,&q);
          add(a,2,&e);
          add(b,1,&f);
          add(a,1,&r);
          add(b,2,&s);
      }
      else if(a==7)
      {
          sub(a,2,&p);
          sub(b,1,&q);
          add(a,2,&e);
          add(b,1,&f);
          sub(a,1,&r);
          sub(b,2,&s);
      }
      else if(b==7)
      {
          sub(a,1,&p);
          sub(b,2,&q);
          add(a,1,&e);
          sub(b,2,&f);
          sub(a,2,&r);
          sub(b,1,&s);
      }
      else if(b==2)
      {
          sub(a,2,&p);
          sub(b,1,&q);
          add(a,2,&e);
          add(b,1,&f);
      }*/
      if (b == 2 || b == 7)
      {
         sub(a, 2, &p);
         sub(b, 1, &q);
         add(a, 2, &e);
         add(b, 1, &f);
      }
      else
      {
         sub(a, 1, &p);
         sub(b, 2, &q);
         add(a, 1, &e);
         add(b, 2, &f);
      }
      print(a, b, p, q, 0, 0, e, f);
   }
   else
   {
      int p, q, r, s, e, f;
      sub(a, 2, &p);
      sub(b, 1, &q);
      add(a, 2, &e);
      add(b, 1, &f);
      print(a, b, p, q, 0, 0, e, f);
   }
}

int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int x, y;
      cin >> x >> y;
      f1(x, y);
      cout << endl
           << endl;
      // f2(x, y);
   }
   return 0;
}