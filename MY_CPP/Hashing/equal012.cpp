// Given a string consiting of 0s 1s and 2s
// Count the numbers of substrings having equal number of 0s 1s and 2s
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int countSubstring(string str)
{

   long long int count = 0;
   unordered_map<pair<int, int>, int> map;
   int oc, zc, tc;
   oc = tc = zc = 0;
   int n = str.length();
   for (int i = 0; i < n; i++)
   {
      if (str[i] == '0')
         zc++;
      else if (str[i] == '1')
         oc++;
      else
         tc++;
      pair<int, int> temp;
      temp.first = zc - oc;
      temp.second = zc - tc;
      count += map[temp];
      map[temp]++;
   }
   return count;
}
int main()
{
   string s;
   getline(cin >> ws, s);
   cout << countSubstring(s);
   return 0;
}