#include <iostream>
#include <vector>
using namespace std;
char map[26];
int main()
{
   int t;
   cin >> t;
   for (int i = 0; i < 26; i++)
   {
      map[i] = 'a' + i;
   }
   while (t--)
   {
      int a, b, c;
      cin >> a >> b >> c;
      int cost1 = a - 1;
      int cost2 = abs(b - c) + abs(c - 1);
      if (cost1 == cost2)
         cout << "3\n";
      else if (cost1 < cost2)
         cout << "1\n";
      else
         cout << "2\n";
   }

   return 0;
}