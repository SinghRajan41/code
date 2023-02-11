#include <iostream>
#include <deque>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int s;
      cin >> s;
      int i = 9;
      std::deque<int> dq;
      while (s > 0 && i > 0)
      {
         if (s < i)
         {
            dq.push_front(s);
            s = 0;
         }
         else
         {
            s -= i;
            dq.push_front(i);
            i--;
         }
      }
      while (!dq.empty())
      {
         cout << dq.front();
         dq.pop_front();
      }
      cout << endl;
   }
}