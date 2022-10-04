#include <string>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
string multiplyString(string l, int x);
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      string s;
      cin >> s;
      stack<int> n;
      stack<string> st;
      string l = "";
      for (int i = 0; i < s.length(); i++)
      {
         if (isdigit(s[i]))
         {
            n.push(s[i] - '0');
         }
         else if (isalpha(s[i]))
         {
            l += s[i];
         }
         else if (s[i] == '[')
         {
            st.push(l);
            l = "";
         }
         else if (s[i] == ']')
         {
            int x = n.top();
            n.pop();
            string temp = st.top();
            st.pop();
            l = multiplyString(l, x);
            l = temp + l;
         }
      }
      cout << l << endl;
   }

   return 0;
}
string multiplyString(string l, int x)
{
   string res = "";
   for (int i = 0; i < x; i++)
   {
      res += l;
   }
   return res;
}