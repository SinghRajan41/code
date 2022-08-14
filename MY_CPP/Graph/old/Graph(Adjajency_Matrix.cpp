#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
template <class X>
class stack
{
   int size, top;
   X *arr;

public:
   stack()
   {
      cout << "Default Size of the Stack is 50\n";
      size = 50;
      top = -1;
      arr = new X[size];
   }
   stack(int n)
   {
      cout << "Size of the stack=" << n << endl;
      size = n;
      top = -1;
      arr = new X[size];
   }
   void destructor()
   {
      delete[] arr;
   }
   ~stack()
   {
      delete[] arr;
   }
   void push(X value);
   X pop();
   int isempty();
   X peektop();
};
template <class X>
void stack<X>::push(X value)
{
   if (top == size - 1)
   {
      cout << "StackOverFlow\nReturning from pop\n";
      return;
   }
   else
   {
      top += 1;
      arr[top] = value;
   }
}

template <class X>
X stack<X>::pop()
{
   X obj;
   if (top == -1)
   {
      cout << "\nStack is Empty\tReturning garbage value from pop\n";
      return obj;
   }
   else
   {
      obj = arr[top];
      top -= 1;
      return obj;
   }
}
template <class X>
int stack<X>::isempty()
{
   if (top <= -1)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
template <class X>
X stack<X>::peektop()
{
   return arr[top];
}
int main()
{
   stack<int> s;
   s.push(21);
   cout << s.pop();
   return 0;
}