#include <bits/stdc++.h>
using namespace std;
int main()
{
   int t;
   cin >> t;
   char arr[8][8];
   while (t--)
   {
      for (int i = 0; i < 8; i++)
      {
         for (int j = 0; j < 8; j++)
         {
            cin >> arr[i][j];
         }
      }
      bool red = false;
      bool blue = false;
      for (int i = 0; i < 8; i++)
      {
         int count = 0;
         for (int j = 0; j < 8; j++)
         {
            if (arr[i][j] == 'R')
            {
               count++;
            }
         }
         if (count == 8)
         {
            red = true;
         }
      }
      for (int j = 0; j < 8; j++)
      {
         int count = 0;
         for (int i = 0; i < 8; i++)
         {
            if (arr[i][j] == 'B')
            {
               count++;
            }
         }
         if (count == 8)
         {
            blue = true;
         }
      }
      if (red)
      {
         cout << "R\n";
      }
      if (blue)
      {
         cout << "B\n";
      }
   }
   return 0;
}