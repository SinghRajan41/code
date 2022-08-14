#include <iostream>
using namespace std;
class hazz
{
   int *arr, keys, size;

public:
   hazz(int n)
   {
      keys = n;
      size = 2 * keys;
      arr = new int[2 * keys];
      for (int i = 0; i < size; i++)
      {
         arr[i] = -1;
      }
   }
   void hazzInsert(int value);
   void hazzDelete(int value);
   int hazzSearch(int value);
   void hazzDisplay();
};
int main()
{
   hazz h(10);
   h.hazzInsert(21);
   h.hazzInsert(33);
   h.hazzInsert(51);
   h.hazzInsert(69);
   h.hazzInsert(84);
   h.hazzInsert(17);
   h.hazzInsert(81);
   h.hazzInsert(19);
   h.hazzInsert(15);
   h.hazzInsert(27);
   if (h.hazzSearch(27))
   {
      cout << "Found";
   }
   return 0;
}
int hazz::hazzSearch(int value)
{
   for (int i = 0; i < size; i++)
   {
      if (arr[value % size + i] == value)
      {
         return 1;
      }
   }
   return 0;
}
void hazz::hazzDelete(int value)
{
   bool found = false;
   for (int i = 0; i < size; i++)
   {
      if (arr[value % size + i] == value)
      {
         found = true;
         arr[value % size + i] == -1;
         break;
      }
      if (arr[value % size + i] == -1)
      {
         break;
      }
   }
   if (found)
   {
      // Writing code for rehashing
      cout << "I'm here mofo";
      int temp[size], k = 0;
      for (int i = 0; i < size; i++)
      {
         if (arr[i] != -1 && arr[i] != value)
         {
            temp[k++] = arr[i];
         }
      }
      for (int i = 0; i < size; i++)
      {
         arr[i] = -1;
      }
      for (int i = 0; i < k; i++)
      {
         hazzInsert(temp[i]);
      }
   }
}
void hazz::hazzDisplay()
{
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << endl;
   }
}
void hazz::hazzInsert(int value)
{
   int idx = -1;
   for (int i = 0; i < size; i++)
   {
      if (arr[value % size + i] == -1)
      {
         idx = value % size + i;
         break;
      }
   }
   if (idx == -1)
   {
      cout << "\nhazzTable Full";
      return;
   }
   else
   {
      arr[idx] = value;
   }
}