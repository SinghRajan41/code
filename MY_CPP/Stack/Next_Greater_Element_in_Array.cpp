#include <iostream>
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
void printNGE(int arr[], int n)
{
   //%%%%%%%%%%%%%%%%First Approach%%%%%%%%%%%%%%%%%%%%
   int res[n];
   stack<int> s(10000), idx(10000);
   s.push(arr[0]);
   idx.push(0);
   for (int i = 1; i < n; i++)
   {
      if (arr[i] > s.peektop())
      {
         while (arr[i] > s.peektop() && !s.isempty())
         {
            res[idx.pop()] = arr[i];
            s.pop();
         }
      }
      s.push(arr[i]);
      idx.push(i);
   }
   while (!s.isempty())
   {
      res[idx.pop()] = -1;
      s.pop();
   }
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << "->" << res[i] << endl;
   }
   //%%%%%%%%%%%%%seocnd approach%%%%%%%%%%%%%%%
   // int res[n];
   // stack<int> s;
   // for (int i = n - 1; i >= 0; i--)
   // {
   //    if (!s.isempty())
   //    {
   //       while (!s.isempty() && s.peektop() <= arr[i])
   //       {
   //          s.pop();
   //       }
   //    }
   //    res[i] = s.isempty() ? -1 : s.peektop();
   //    s.push(arr[i]);
   // }
   // for (int i = 0; i < n; i++)
   // {
   //    cout << arr[i] << " " << res[i] << endl;
   // }
}
int main()
{
   int arr[10] = {19, 12, 34, 21, 45, 65, 23, 55, 87, 95};
   printNGE(arr, 10);
   return 0;
}
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
