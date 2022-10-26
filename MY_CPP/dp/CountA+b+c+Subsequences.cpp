/*
1. You are given a string str.
2. You are required to calculate and print the count of subsequences of the nature a+b+c+.
For abbc -> there are 3 subsequences. abc, abc, abbc
For abcabc -> there are 7 subsequences. abc, abc, abbc, aabc, abcc, abc, abc.

*/
#include <iostream>
#include <string>
using namespace std;
int count(string s);
int main()
{
   string s;
   cin >> s;
   cout << count(s);
   return 0;
}
int count(string s)
{
   int n = s.length();
   int i = 0;
   int a[n], b[n], c[n];
   while (s[i] != 'a')
      ++i;
   a[i] = 1;
   b[i] = c[i] = 0;
   if (i >= n)
      return 0;

   for (i = i + 1; i < n; i++)
   {
      if (s[i] == 'a')
      {
         a[i] = 2 * a[i - 1] + 1;
         b[i] = b[i - 1];
         c[i] = c[i - 1];
      }
      else if (s[i] == 'b')
      {
         a[i] = a[i - 1];
         b[i] = 2 * b[i - 1] + a[i - 1];
         c[i] = c[i - 1];
      }
      else
      {
         a[i] = a[i - 1];
         b[i] = b[i - 1];
         c[i] = 2 * c[i - 1] + b[i - 1];
      }
   }
   return c[n - 1];
}