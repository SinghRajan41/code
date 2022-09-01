/*#include <iostream>
using namespace std;
class heap
{
   int arr[1001] = {-1}, i, size;

public:
   heap()
   {
      i = 0;
      arr[0] = 99999;
   }
   void insert(int value);
   void remove();
   void swap(int &x, int &y);
   void heapify(int arr[], int i, int n);
   void heap_sort();
   void display();
};
void heap::heap_sort()
{
   for (int j = 0; j < size; j++)
   {
      remove();
   }
}
void heap::insert(int value)
{
   arr[++i] = value;
   int j = i;
   size = i;
   while (value > arr[j / 2] && j / 2 >= 1)
   {
      arr[j] = arr[j / 2];
      j = j / 2;
   }
   if (i != j)
   {
      arr[j] = value;
   }
}
void heap::swap(int &x, int &y)
{
   int temp = x;
   x = y;
   y = temp;
}
void heap::remove()
{
   if (i <= 1)
   {
      return;
   }
   else
   {
      swap(arr[i], arr[1]);
      int x = arr[1];
      int j = 2;
      while (j < i - 1)
      {
         if (arr[j] < arr[j + 1])
         {
            j += 1;
         }
         if (arr[j / 2] < arr[j])
         {
            swap(arr[j / 2], arr[j]);
            j = j * 2;
         }
         else
         {
            break;
         }
      }
      i--;
   }
}
void heap::display()
{
   for (int j = 1; j <= size; j++)
   {
      cout << arr[j] << " ";
   }
}
int main()
{
   heap h;
   for (int i = 0; i < 15; i++)
   {
      h.insert(i);
   }
   h.heap_sort();

   h.display();
   return 0;
}*/

#include <iostream>
using namespace std;
class max_heap
{
   int arr[1001], i, size;

public:
   max_heap()
   {
      i = 0;
      arr[0] = 999999;
      size = 0;
   }
   void display();
   void insert(int value);
   void remove();
   void swap(int &x, int &y);
   void build_heap(int arr[], int n);
};
void max_heap::build_heap(int arr[], int n)
{
}
void max_heap::swap(int &x, int &y)
{
   int temp = x;
   x = y;
   y = temp;
}
void max_heap::insert(int value)
{
   arr[++i] = value;
   int j = i;
   size = i;
   while (value > arr[j / 2] && j / 2 >= 1)
   {
      arr[j] = arr[j / 2];
      j = j / 2;
   }
   if (i != j)
   {
      arr[j] = value;
   }
}
void max_heap::display()
{
   for (int j = 1; j <= size; j++)
   {
      cout << arr[j] << " ";
   }
}
void max_heap::remove()
{
   swap(arr[i], arr[1]);
   int x = arr[1];
   int j = 2;
   i--;
   while (j < i - 1)
   {
      if (arr[j] < arr[j + 1])
      {
         j += 1;
      }
      if (arr[j / 2] < arr[j])
      {
         swap(arr[j], arr[j / 2]);
         j = j * 2;
      }
      else
      {
         break;
      }
   }
}
int main()
{
   max_heap h;
   for (int i = 0; i < 15; i++)
   {
      h.insert(i + 1);
   }
   h.remove();
   h.remove();
   h.display();
   return 0;
}
