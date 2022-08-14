#include <iostream>
using namespace std;
template <class X>
class PQueue
{
   X *arr;
   int size, l;

public:
   PQueue(int x)
   {
      size = x;
      arr = new X[size + 1];
      l = 0;
   }
   void swap(X &x, X &y)
   {
      X temp = x;
      x = y;
      y = temp;
   }
   PQueue()
   {
      size = 1000;
      arr = new X[size + 1];
      l = 0;
   }
   void nq(X value)
   {
      if (l == 0)
      {
         arr[++l] = value;
      }
      else
      {
         arr[++l] = value;
         int i = l;
         while (i > 1 && arr[i] > arr[i / 2])
         {
            swap(arr[i], arr[i / 2]);
            i /= 2;
         }
      }
   }
   void dq()
   {
      if (l == 0)
      {
         cout << "\nQueue is Empty";
         return;
      }
      else if (l == 1)
      {
         l -= 1;
      }
      else
      {
         swap(arr[1], arr[l]);
         l -= 1;
         pushDown(1);
      }
   }
   void pushDown(int i)
   {
      int j = 2 * i;
      if ((j + 1 <= l) && arr[j + 1] > arr[j])
      {
         j += 1;
      }
      if (arr[j / 2] < arr[j] && j <= l)
      {
         swap(arr[j], arr[j / 2]);
         pushDown(j);
      }
   }
   void check(int x)
   {
      for (int i = 1; i <= x; i++)
      {
         cout << arr[i] << " ";
      }
   }
};
int main()
{
   PQueue<int> q;
   for (int i = 0; i < 500; i++)
   {
      q.nq(i + 1);
   }
   q.dq();
   q.dq();
   q.dq();
   q.check(500);
   return 0;
}