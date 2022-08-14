#include <iostream>
#include <stack>
using namespace std;
void stackSort(int cur);
void sortedInsert(int key);
stack<int> s;
void stackSort(int cur)
{
   int x = s.top();
   s.pop();
   if (!s.empty())
   {
      stackSort(x);
   }
   else
   {
      s.push(x);
   }

   sortedInsert(cur);
}
void sortedInsert(int key)
{

   int x = -1;

   if (key < s.top() && !s.empty())
   {

      x = s.top();
      s.pop();

      sortedInsert(key);
   }
   else
   {

      s.push(key);
   }
   if (x != -1)
   {
      s.push(x);
   }
}

int main()
{

   s.push(21);
   s.push(11);
   s.push(91);
   s.push(311);
   s.push(41);
   s.push(71);
   s.push(811);
   s.push(21);
   int x = s.top();
   stackSort(x);
   cout << "x";

   return 0;
}