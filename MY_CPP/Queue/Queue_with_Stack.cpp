#include <iostream>
#include <stack>
using namespace std;
class queue
{
   stack<int> s1, s2;

public:
   void nq(int value);
   void dq();
   int peekfront();
   inline bool isEmpty();
};
inline bool queue::isEmpty()
{
   return (s1.empty()) ? true : false;
}
int queue::peekfront()
{
   if (s1.empty())
   {
      return -1;
   }
   while (!s1.empty())
   {
      s2.push(s1.top());
      s1.pop();
   }
   int x = s2.top();
   s2.pop();
   while (!s2.empty())
   {
      s1.push(s2.top());
      s2.pop();
   }
}
void queue::nq(int value)
{
   s1.push(value);
}
void queue::dq()
{
   if (s1.empty())
   {
      cout << "\nQueue is Empty";
   }
   else
   {
      while (!s1.empty())
      {
         s2.push(s1.top());
         s1.pop();
      }
      s2.pop();
      while (!s2.empty())
      {
         s1.push(s2.top());
         s2.pop();
      }
   }
}
int main()
{
   queue q;
   for (int i = 0; i < 21; i++)
   {
      q.nq(i + 1);
   }
   for (int i = 0; i < 21; i++)
   {
      cout << q.peekfront() << " ";
      q.dq();
   }
   if (q.isEmpty())
   {
      cout << "\nI'm All Empty Now";
   }
   else
   {
      cout << "\nI'm Not at all Empty";
   }
   return 0;
}
