#include <iostream>
using namespace std;
template <class X>
class stack
{
   X *arr;
   int size, top;
   X temp;

public:
   stack()
   {
      arr = new X[50];
      top = -1;
      size = 50;
   }
   stack(int x)
   {
      arr = new X[x];
      size = x;
      top = -1;
   }
   void push(X value);
   X pop();
   bool isEmpty();
   X peektop();
};
template <class X>
void stack<X>::push(X value)
{
   if (top == size)
   {
      return;
   }
   else
   {
      arr[++top] = value;
   }
}
template <class X>
bool stack<X>::isEmpty()
{
   if (top == -1)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
template <class X>
X stack<X>::pop()
{
   if (top > -1)
   {
      temp = arr[top];
      top -= 1;
   }
   return temp;
}
template <class X>
X stack<X>::peektop()
{
   if (top > -1)
   {
      return arr[top];
   }
   else
   {
      cout << "\nStack UnderFlow Returning Junk\n";
      return temp;
   }
}
void printNGFE(int arr[], int n)
{
   stack<int> s, idx;
   short int freq[10000] = {0};
   int res[n];
   for (int i = 0; i < n; i++)
   {
      freq[arr[i]]++;
   }
   s.push(arr[0]);
   idx.push(0);
   for (int i = 1; i < n; i++)
   {
      if (freq[arr[i]] > freq[s.peektop()])
      {
         while (freq[arr[i]] > freq[s.peektop()] && !s.isEmpty())
         {
            res[idx.pop()] = arr[i];
            s.pop();
         }
      }
      s.push(arr[i]);
      idx.push(i);
   }
   while (!s.isEmpty())
   {
      res[idx.pop()] = -1;
      s.pop();
   }
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << "  ->  " << res[i] << endl;
   }
}
int main()
{
   int arr[10] = {1, 1, 1, 2, 2, 2, 2, 11, 3, 3};
   printNGFE(arr, 10);
   return 0;
}