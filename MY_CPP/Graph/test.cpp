#include <iostream>
#include <vector>
#include <string>
#define isLower(x) (x >= 97 && x <= 122)
using namespace std;
int main()
{
   string str;
   cin >> str; // Key Word String
   for (int i = 0; i < str.length(); i++)
   {
      if (isLower(str[i]))
      {
         str[i] -= 32;
      }
   }
   int *freq = new int[26];
   for (int i = 0; i < 26; i++)
   {
      freq[i] = 0;
   }
   for (int i = 0; i < str.length(); i++)
   {
      freq[(str[i] - 'A')]++;
   }
   string newStr = "";
   for (int i = 0; i < str.length(); i++)
   {
      if (freq[(str[i] - 'A')] != -1)
      {
         newStr += str[i];
         freq[(str[i] - 'A')] = -1;
      }
   }
   str = newStr;
   vector<pair<int, int>> map(26, make_pair(0, 0));
   for (int i = 0; i < 26; i++)
   {
      freq[i] = -1;
   }
   for (int i = 0; i < str.length(); i++)
   {
      map[i] = make_pair(65 + i, int(str[i]));
      freq[str[i] - 'A']++;
   }
   int j = 0;
   for (int i = str.length(); i < 26; i++)
   {
      while (freq[j] != -1)
      {
         j++;
      }
      map[i] = make_pair(65 + i, 65 + j);
      j++;
   }
   string dec;
   getline(cin >> ws, dec);
   for (int i = 0; i < 26; i++)
   {
      freq[map[i].second - 65] = i;
   }
   for (int i = 0; i < dec.length(); i++)
   {
      cout << char(freq[dec[i] - 65] + 65);
   }
   return 0;
}