#include <iostream>
#include <string>
using namespace std;
int main()
{
   string word;
   getline(cin >> ws, word);
   bool hash[word.length()];
   int n = word.length();
   int d = 0;
   for (int i = 0; i <= n / 2; i++)
   {
      if (word[i] == word[n - i - 1])
      {
         hash[i] = hash[n - i - 1] = 0;
      }
      else
      {
         hash[i] = hash[n - i - 1] = 1;
         d += 2;
      }
   }
   int q;
   cin >> q;
   while (q--)
   {
      int i, j, ch;
      cin >> i >> j >> ch;
      word[i] = word[j] = ch;
      // Checking for i
      if (word[i] == word[n - i - 1])
      {
         // Reduce d by checking for ones
         if (hash[i] == 1)
         {
            hash[i] = 0;
            d--;
         }
         if (hash[n - i - 1] == 1)
         {
            hash[n - i - 1] = 0;
            d--;
         }
      }
      else
      {
         // Increase d by checking for 0
         if (hash[i] == 0)
         {
            hash[i] = 1;
            d++;
         }
         if (hash[n - i - 1] == 0)
         {
            hash[n - i - 1] = 1;
            d++;
         }
      }
      i = j;
      if (word[i] == word[n - i - 1])
      {
         // position is balanced now reduce d by checking for 1
         if (hash[i] == 1)
         {
            d--;
            hash[i] = 0;
         }
         if (hash[n - i - 1] == 1)
         {
            d--;
            hash[n - i - 1] = 0;
         }
      }
      else
      {
         // Increasing D
         if (hash[i] == 0)
         {
            d++;
            hash[i] = 1;
         }
         if (hash[n - i - 1] == 0)
         {
            d++;
            hash[n - i - 1] = 1;
         }
      }
      cout << d << " ";
      if (d == 0)
      {
         cout << "YES\n";
      }
      else
      {
         cout << "NO\n";
      }
   }

   return 0;
}