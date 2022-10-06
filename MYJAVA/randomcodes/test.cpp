#include <iostream>
#include <string>
using namespace std;
int main()
{
   string s;
   cin >> s;
   int a, b;
   a = b = 0;
   for (int i = 0; i < s.length(); i += 2)
   {
      a += s[i] - '0';
   }
   for (int i = s.length() - 1; i >= 0; i -= 2)
   {
      b += (s[i] - '0');
   }
   cout << abs(a - b) << endl;
   return 0;
}