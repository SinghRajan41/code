#include <iostream>
using namespace std;
class two_stack
{
   int *arr;
   int i, j, n;

public:
   two_stack(int x)
   {
      n = x;
      i = x - 1;
      j = n;
      arr = new int[2 * n];
   }
   void push1(int value);
   void push2(int value);
   int pop1();
   int pop2();
};
int main()
{
   two_stack s(12);
   for (int i = 0; i < 11; i++)
   {
      s.push1(i);
      s.push2(i);
   }
   for (int i = 0; i <= 13; i++)
   {
      cout << s.pop1() << "   " << s.pop2() << endl;
   }
}
int two_stack::pop1()
{
   if (i >= n)
   {
      return -1;
   }
   else
   {
      int x = arr[i + 1];
      i += 1;
      return x;
   }
}
int two_stack::pop2()
{
   if (j < n)
   {
      return -1;
   }
   else
   {
      int x = arr[j - 1];
      j -= 1;
      return x;
   }
}
void two_stack::push1(int value)
{
   if (i < 0)
   {
      cout << "\nStack OverFlow";
   }
   else
   {
      arr[i] = value;
      i -= 1;
   }
}
void two_stack::push2(int value)
{
   if (j >= 2 * n)
   {
      cout << "\nStack OverFlow";
   }
   else
   {
      arr[j] = value;
      j += 1;
   }
}