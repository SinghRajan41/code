// Implement K Stacks in a single array
//#################approach 1###################33
#include <iostream>
using namespace std;
class KStack
{
   int *arr, size, k;
   int *top;

public:
   KStack(int x, int y)
   {
      size = x;
      k = y;
      arr = new int[x * y];
      top = new int[k];
      for (int i = 0; i < k; i++)
      {
         top[i] = i * size - 1;
      }
   }
   void push(int i, int value);
   int pop(int i);
   bool isEmpty(int i);
};
bool KStack::isEmpty(int i)
{
   if (top[i] == i * size - 1)
   {
      return true;
   }
   else
   {
      return false;
   }
}
void KStack::push(int i, int value)
{
   if (top[i] == size * (i + 1))
   {
      cout << "\nStack OverlFlow";
   }
   else
   {
      arr[++top[i]] = value;
   }
}
int KStack::pop(int i)
{
   if (top[i] == (i * size - 1))
   {
      cout << "\nStack Underflow";
      return -1;
   }
   else
   {
      int x = arr[top[i]];
      top[i] -= 1;
      return x;
   }
}
int main()
{
   int size, k;
   cout << "\nEnter the size of each stack=";
   cin >> size;
   cout << "\nEnter the number of stacks=";
   cin >> k;
   KStack s(size, k);
   for (int i = 0; i < size; i++)
   {
      s.push(0, i + 1);
   }
   for (int i = 0; i < size; i++)
   {
      cout << s.pop(0) << " ";
      ;
   }
   return 0;
}