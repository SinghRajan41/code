/*
1. You are given a string str of digits. (will never start with a 0)
2. You are required to encode the str as per following rules
    1 -> a
    2 -> b
    3 -> c
    ..
    25 -> y
    26 -> z
3. You are required to calculate and print the count of encodings for the string str.

     For 123 -> there are 3 encodings. abc, aw, lc
     For 993 -> there is 1 encoding. iic
     For 013 -> This is an invalid input. A string starting with 0 will not be passed.
     For 103 -> there is 1 encoding. jc
     For 303 -> there are 0 encodings. But such a string maybe passed. In this case
     print 0.
*/
#include <string>
#include <iostream>
using namespace std;
int countEncodings(string s);
int main()
{
   string s;
   cin >> s;
   cout << countEncodings(s);
   return 0;
}
int countEncodings(string str)
{
   int n = str.size();
   int dp[n + 1];
   char s[n + 1];
   for (register int i = 0; i < n; ++i)
   {
      s[i + 1] = str[i];
   }

   dp[0] = dp[1] = 1;
   for (register int i = 2; i <= n; ++i)
   {
      if (s[i] != '0' && s[i - 1] != '0')
      {
         dp[i] = dp[i - 1];
         string temp = "";
         temp += s[i - 1];
         temp += s[i];
         int x = stoi(temp);
         if (x >= 1 && x <= 26)
         {
            dp[i] += dp[i - 2];
         }
      }
      else if (s[i] == '0' && s[i - 1] != '0')
      {
         if (s[i - 1] == '1' || s[i - 1] == '2')
         {
            dp[i] = dp[i - 2];
         }
         else
         {
            dp[i] = 0;
         }
      }
      else if (s[i] != '0' && s[i - 1] == '0')
      {
         dp[i] = dp[i - 1];
      }
      else if (s[i] == '0' && s[i - 1] == '0')
      {
         dp[i] = 0;
      }
   }
   return dp[n];
}
/*
 For 123 -> there are 3 encodings. abc, aw, lc
     For 993 -> there is 1 encoding. iic
     For 013 -> This is an invalid input. A string starting with 0 will not be passed.
     For 103 -> there is 1 encoding. jc
     For 303 -> there are 0 encodings. But such a string maybe passed. In this case
     print 0.
*/