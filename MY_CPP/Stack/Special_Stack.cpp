// ###############################APPROACH 1 ####################################
//  SPECIAL STACK SUPPORTS GETMIN() IN O(1) TIME COMPLEXITY
// #include <iostream>
// using namespace std;
// class specialStack
// {
//    int *arr, *aux;
//    int top, top2;
//    int size;

// public:
//    specialStack()
//    {
//       size = 50;
//       arr = new int[size];
//       aux = new int[size];
//       top = -1;
//    }
//    specialStack(int x)
//    {
//       size = x;
//       arr = new int[size];
//       aux = new int[size];
//       top = top2 = -1;
//    }
//    void push(int value);
//    int pop();
//    int isEmpty();
//    int getMin();
// };
// int specialStack::getMin()
// {
//    if (top == -1)
//    {
//       return 2196752;
//    }
//    else
//    {
//       return aux[top];
//    }
// }
// int specialStack::isEmpty()
// {
//    return (top == -1) ? 1 : 0;
// }
// int specialStack::pop()
// {
//    if (top == -1)
//    {
//       cout << "\nStack UnderFlow";
//       return -1;
//    }
//    else
//    {
//       int x = arr[top];
//       top -= 1;
//       return x;
//    }
// }
// void specialStack::push(int value)
// {
//    if (top == size)
//    {
//       cout << "\nStackOverFlow";
//    }
//    else
//    {
//       arr[++top] = value;
//       if (top == 0)
//       {
//          aux[top] = value;
//       }
//       else
//       {
//          if (value < aux[top - 1])
//          {
//             aux[top] = value;
//          }
//          else
//          {
//             aux[top] = aux[top - 1];
//          }
//       }
//    }
// }
// int main()
// {
//    specialStack s;
//    for (int i = 0; i < 10; i++)
//    {
//       s.push(i);
//    }
//    for (int i = 0; i < 10; i++)
//    {
//       cout << s.pop() << " " << s.getMin() << endl;
//    }
//    return 0;
// }

#include <iostream>
using namespace std;
class specialStack
{
   int *arr, d, top, curMin, size;

public:
   specialStack(int x)
   {
      size = x;
      curMin = 2196752;
      top = -1;
      d = 97;
      arr = new int[size];
   }
   specialStack()
   {
      size = 100;
      curMin = 2196752;
      top = -1;
      d = 97;
      arr = new int[size];
   }
   void push(int value);
   int pop();
   bool isEmpty();
   int getMin();
   int peekTop();
};
int main()
{
   specialStack s;
   for (int i = 0; i < 10; i++)
   {
      s.push(i);
   }
   for (int i = 0; i < 10; i++)
   {
      cout << s.getMin() << " " << endl;
      s.pop();
   }
   return 0;
}
int specialStack::getMin()
{
   int x = arr[top] % d;
   return (top == -1) ? 2196752 : x;
}
int specialStack::peekTop()
{
   return (top == -1) ? -1 : arr[top] / d;
}
bool specialStack::isEmpty()
{
   return (top == -1) ? 1 : 0;
}
void specialStack::push(int value)
{
   curMin = (curMin < value) ? curMin : value;
   if (top == size)
   {
      cout << "\nStack OverFlow";
   }
   else
   {
      arr[++top] = (value * d + curMin);
   }
}
int specialStack::pop()
{
   if (top == -1)
   {
      return -1;
   }
   else
   {
      top -= 1;
      curMin = (arr[top] % d);
      return (arr[top + 1] / d);
   }
}