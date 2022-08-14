#include <iostream>
#include <string>
using namespace std;
struct item
{
   int data;
   int pr;
};
class PQueue
{
   item *arr;
   int size, l;

public:
   PQueue(int x)
   {
      {
         size = x;
         l = 0;
         arr = new item[size + 1];
      }
   }
   PQueue()
   {
      {
         size = 1000;
         l = 0;
         arr = new item[size + 1];
      }
   }
   void nq(item value)
   {
      if (l == 0)
      {
         arr[++l] = value;
      }
      else
      {
         arr[++l] = value;
         int i = l;
         while (i > 1 && arr[i].pr > arr[i / 2].pr)
         {
            swap(arr[i], arr[i / 2]);
            i /= 2;
         }
      }
   }
   void swap(item &x, item &y)
   {
      item temp = x;
      x = y;
      y = temp;
   }
   void check(int x)
   {
      for (int i = 1; i <= x; i++)
      {
         cout << arr[i].pr << " ";
      }
   }
};
int main()
{
   PQueue q(1100);
   for (int i = 0; i < 1000; i++)
   {
      item ii;
      ii.pr = 1000 - i;
      ii.data = i;
      q.nq(ii);
   }
   q.check(1000);
   return 0;
}
