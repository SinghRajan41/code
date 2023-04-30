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
      int n, c;
      cin >> n;
      string s;
      cin >> s;
      string res = "";
      s.push_back('$');
      s.push_back('$');
      s.push_back('$');
      for (int i = 0; i < n;)
      {
         if (s[i + 2] == '0' && s[i + 3] != '0')
         {
            int num = stoi(s.substr(i, 2));
            res.push_back(map[num - 1]);
            i += 3;
         }
         else
         {
            res.push_back(map[s[i] - '1']);
            i += 1;
         }
      }
      cout << res << endl;
   }
   return 0;
}