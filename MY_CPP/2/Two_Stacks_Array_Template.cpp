// #include <iostream>
// using namespace std;
// template <class X>
// class two_stack
// {
//    X *arr;
//    int i, j, n;

// public:
//    void initialise(int x)
//    {
//       n = x;
//       i = x - 1;
//       j = n;
//       arr = new X[2 * n];
//    }
//    void push1(X value);
//    void push2(X value);
//    X pop1();
//    X pop2();
// };
// int main()
// {
//    two_stack<int> s;
//    s.initialise(20);
//    for (int i = 0; i < 11; i++)
//    {
//       s.push1(i);
//       s.push2(i);
//    }
//    for (int i = 0; i <= 13; i++)
//    {
//       cout << s.pop1() << "   " << s.pop2() << endl;
//    }
// }
// template <class X>
// X two_stack<X>::pop1()
// {
//    if (i >= n)
//    {
//       return -1;
//    }
//    else
//    {
//       int x = arr[i + 1];
//       i += 1;
//       return x;
//    }
// }
// template <class X>
// X two_stack<X>::pop2()
// {
//    if (j < n)
//    {
//       return -1;
//    }
//    else
//    {
//       int x = arr[j - 1];
//       j -= 1;
//       return x;
//    }
// }
// template <class X>
// void two_stack<X>::push1(X value)
// {
//    if (i < 0)
//    {
//       cout << "\nStack OverFlow";
//    }
//    else
//    {
//       arr[i] = value;
//       i -= 1;
//    }
// }
// template <class X>
// void two_stack<X>::push2(X value)
// {
//    if (j >= 2 * n)
//    {
//       cout << "\nStack OverFlow";
//    }
//    else
//    {
//       arr[j] = value;
//       j += 1;
//    }
// }

//#################################SECOND STACK
#include <iostream>
using namespace std;
template <class X>
class stack
{
   X *arr;
   int i, j, n;

public:
   stack(int x)
   {
      n = x;
      i = 0;
      j = 2 * n - 1;
      arr = new X[2 * n];
   }
   void push1(X value);
   void push2(X value);
   X pop1();
   X pop2();
   bool isEmpty();
   X peektop1();
   X peektop2();
};
int main()
{
   stack<int> s(10);
   for (int i = 0; i < 7; i++)
   {
      s.push1(i);
      s.push2(i);
   }
   for (int i = 0; i < 21; i++)
   {
      cout << s.pop1() << "   " << s.pop2() << endl;
   }
   return 0;
}
template <class X>
void stack<X>::push1(X value)
{
   if (j - i > 1)
   {
      arr[i++] = value;
   }
   else
   {
      cout << "\nStack OverFlow";
   }
}
template <class X>
void stack<X>::push2(X value)
{
   if (j - i > 1)
   {
      arr[j--] = value;
   }
   else
   {
      cout << "\nStack OverFlow";
   }
}
template <class X>
X stack<X>::pop1()
{
   if (i == 0)
   {
      return -1;
   }
   else
   {
      X rvalue = arr[i - 1];
      i -= 1;
      return rvalue;
   }
}
template <class X>
X stack<X>::pop2()
{
   if (j == 2 * n - 1)
   {
      return -1;
   }
   else
   {
      X rvalue = arr[j + 1];
      j += 1;
      return rvalue;
   }
}